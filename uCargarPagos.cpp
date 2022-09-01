//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uCargarPagos.h"
#include "uCuentas.h"
#include "uSeleccionarCliente.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfCargarPagos *fCargarPagos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfCargarPagos::TfCargarPagos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

String TfCargarPagos::comaToDot(String str)
{
   if(str.Pos(",") == 0)
	  return str;
   if(str.Pos(".") > 0)
	  return "0";

   int p = str.Pos(",");
   str = str.Delete(p,1);
   return str.Insert(".",p);
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button1Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT COUNT(idCuenta) as existe FROM cuentas WHERE (fecha = :f) LIMIT 1");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->Open();
   bool existe;

   if(QueryAux->FieldByName("existe")->AsInteger > 0)
	  existe = true;
   else
      existe = false;
   QueryAux->Close();

   String q;

   if(!existe)
   {

	  q = "INSERT INTO cuentas (refCliente, fecha, refRepartidor, valorUnidad) SELECT refCliente, :f, refRepartidor, "
		  "((SELECT valor FROM listasPrecio WHERE (SELECT refListaPrecio FROM clientes WHERE "
				"idCliente = refCliente LIMIT 1) = idListaPrecio LIMIT 1) * (SELECT ((100.0 - bonificacion) / 100.0) "
				"FROM clientes WHERE idCliente = refCliente LIMIT 1)) "
		  "FROM repartos WHERE (refCliente > 2 AND esSabado = :sab)";

	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add(q);
	  QueryAux->ParamByName("sab")->AsInteger = esSabado;
	  QueryAux->ParamByName("f")->AsDate = DTP->Date;
	  QueryAux->ExecSQL();
   }

   q = "SELECT idCuenta, refCliente, refRepartidor, valorUnidad, unidades, pagoRealizado, "
	   "(SELECT calle FROM clientes WHERE refCliente = clientes.idCliente LIMIT 1) AS calle, "
	   "(SELECT numero FROM clientes WHERE refCliente = clientes.idCliente LIMIT 1) AS numero, "
	   "(SELECT refFrecuenciaPago FROM clientes WHERE refCliente = clientes.idCliente LIMIT 1) AS refFrecuenciaPago, "
	   "(SELECT posicion FROM repartos WHERE (repartos.refCliente = cuentas.refCliente AND "
	   		"repartos.refRepartidor = cuentas.refRepartidor AND repartos.esSabado = :sab) LIMIT 1) AS posicion "
       "FROM cuentas WHERE (refRepartidor = :rep AND fecha = :f) ORDER BY posicion";

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   Query1->ParamByName("rep")->AsInteger = idRepartidor;
   Query1->ParamByName("sab")->AsInteger = esSabado;
   Query1->ParamByName("f")->AsDate = DTP->Date;
   Query1->Open();
   CDS->Active = true;

   DBGrid1->Enabled = true;

   DTP->Enabled = false;
   ComboBox1->Enabled = false;
   Button1->Enabled = false;
   Button2->Enabled = true;
   Button3->Enabled = true;
   Button6->Enabled = true;
   Button7->Enabled = true;

   DBGrid1->SelectedIndex = 2;
   CDS->First();

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);

   DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::FormShow(TObject *Sender)
{
   Panel2->Visible = false;

   if(DayOfTheWeek(Now()) == DaySunday)
	  DTP->Date = IncDay(Now(), -1);
   else
      DTP->Date = Now();

   DTPChange(fCargarPagos);

   DTP->Enabled = true;
   ComboBox1->Enabled = false;
   Button1->Enabled = false;
   Button2->Enabled = false;
   Button3->Enabled = false;
   Button6->Enabled = false;
   Button7->Enabled = false;
   mostrado = false;

   DTP->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfCargarPagos::ComboBox1Change(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRepartidor FROM repartidores WHERE descripcion = :des LIMIT 1");
   QueryAux->ParamByName("des")->AsString = ComboBox1->Text;
   QueryAux->Open();
   idRepartidor = QueryAux->FieldByName("idRepartidor")->AsInteger;
   QueryAux->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
   else if(Key == '+')
   {
	  Key = NULL;
	  Button6Click(Button6);
   }

}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::DBGrid1KeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
   {
	  if(DBGrid1->SelectedIndex == 2)
		 DBGrid1->SelectedIndex = 3;
	  else if(DBGrid1->SelectedIndex == 3)
	  {
		 DBGrid1->SelectedIndex = 2;
		 CDS->Next();
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::CDSpagoRealizadoChange(TField *Sender)
{
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, "
						 ":pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DTP->Date;
   QueryUpdate->ParamByName("refCliente")->AsInteger = CDS->FieldByName("refCliente")->AsInteger;
   QueryUpdate->ParamByName("unidades")->AsFloat = CDS->FieldByName("unidades")->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = CDS->FieldByName("valorUnidad")->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();

   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE cuentas SET fechaIngresoPago = :fp, medioDePago = 'A' WHERE idCuenta = :idC LIMIT 1");
   QueryUpdate->ParamByName("fp")->AsDate = DateOf(DTP->DateTime);
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}

//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::CDSunidadesChange(TField *Sender)
{

   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, "
   						 ":pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DTP->Date;
   QueryUpdate->ParamByName("refCliente")->AsInteger = CDS->FieldByName("refCliente")->AsInteger;
   QueryUpdate->ParamByName("unidades")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = CDS->FieldByName("pagoRealizado")->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = CDS->FieldByName("valorUnidad")->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::CDSvalorUnidadChange(TField *Sender)
{
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, "
   						 ":pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DTP->Date;
   QueryUpdate->ParamByName("refCliente")->AsInteger = CDS->FieldByName("refCliente")->AsInteger;
   QueryUpdate->ParamByName("unidades")->AsFloat = CDS->FieldByName("unidades")->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = CDS->FieldByName("pagoRealizado")->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button2Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();

   QueryAux->SQL->Add("SELECT SUM(unidades) AS cantUnid, SUM(pagoRealizado) AS cobro FROM cuentas WHERE "
   					  "refRepartidor = :rep AND fecha = :f");

   QueryAux->ParamByName("rep")->AsInteger = idRepartidor;
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->Open();

   String str = L"Viandas entregadas: " + FormatFloat("0.00", QueryAux->FieldByName("cantUnid")->AsFloat);
   str = str + '\n' + '\n' + L"Dinero cobrado: $ " + FormatFloat("0.00", QueryAux->FieldByName("cobro")->AsFloat);


   Application->MessageBox(str.w_str() ,L"Informaci�n.",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   DTP->Enabled = true;
   ComboBox1->Enabled = true;
   Button1->Enabled = true;
   Button2->Enabled = false;
   Button3->Enabled = false;
   Button6->Enabled = false;
   Button7->Enabled = false;

   Query1->Close();
   CDS->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::CDSNewRecord(TDataSet *DataSet)
{
   CDS->Cancel();
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(CDS->Active)
   {
	  Application->MessageBox(L"Debe terminar con la carga antes de cerrar esta ventana" ,
	  						  L"Finalizar la carga antes de salir.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  Action = caNone;
	  return;
   }

   if(!mostrado && Application->MessageBox(L"Desea realizar una comprobaci�n de estas planillas con respecto a los pedidos?",
   										   L"Realizar comprobaci�n?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
   {
       Button9Click(Button9);

	   if(Application->MessageBox(L"Desea salir de la ventana para carga de pagos?",L"Salir?",
	   							    MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDNO)
	   {
		  Action = caNone;
		  return;
	   }
   }

   CDS->Active = false;
   Query1->Close();
   QueryAux->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfCargarPagos::Button3Click(TObject *Sender)
{
   if(CDS->RecordCount < 1)
      return;

   Memo1->Clear();
   Panel1->Visible = true;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT *, COUNT(*) AS existe FROM obscuentas WHERE refCuenta = :idCuenta LIMIT 1");
   QueryAux->ParamByName("idCuenta")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryAux->Open();
   existeObs = QueryAux->FieldByName("existe")->AsInteger;

   if(existeObs > 0)
   {
	  idObsCuenta =  QueryAux->FieldByName("idObsCuenta")->AsInteger;
	  Memo1->Lines->Add(QueryAux->FieldByName("descripcion")->AsString);
   }
   else
	  idObsCuenta = 0;

   QueryAux->Close();

   Memo1->SetFocus();

}
//---------------------------------------------------------------------------


void __fastcall TfCargarPagos::Button4Click(TObject *Sender)
{
   if(existeObs > 0)
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("UPDATE obscuentas SET descripcion = :text WHERE idObsCuenta = :id");
	  QueryAux->ParamByName("id")->AsInteger = idObsCuenta;
	  QueryAux->ParamByName("text")->AsString = Memo1->Text;
	  QueryAux->ExecSQL();
   }
   else
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("INSERT INTO obscuentas (refCuenta, descripcion) VALUES (:id, :text)");
	  QueryAux->ParamByName("id")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
	  QueryAux->ParamByName("text")->AsString = Memo1->Text;
	  QueryAux->ExecSQL();
   }

   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button5Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button6Click(TObject *Sender)
{
   fSeleccionarCliente->ShowModal();
   int id = fSeleccionarCliente->idSeleccionado;

   if(id == 0)
	  return;

   bool ok = false;

   if(CDS->State == dsEdit)
      CDS->ApplyUpdates(0);

   CDS->Active = false;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT *, COUNT(*) AS existe FROM cuentas WHERE fecha = :f AND refCliente = :rc LIMIT 1");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = id;
   QueryAux->Open();
   bool existe = QueryAux->FieldByName("existe")->AsInteger;
   int refRepartidor = QueryAux->FieldByName("refRepartidor")->AsInteger;
   int idCuenta = QueryAux->FieldByName("idCuenta")->AsInteger;
   QueryAux->Close();

   String q;

   if(!existe)
   {
	  q = "INSERT INTO cuentas (refCliente, fecha, refRepartidor, valorUnidad) VALUES(:rc, :f, :rep, "
		  "((SELECT valor FROM listasPrecio WHERE "
		  "(SELECT refListaPrecio FROM clientes WHERE clientes.idCliente = :rc LIMIT 1) "
		  "= listasPrecio.idListaPrecio LIMIT 1) * (SELECT ((100.0 - bonificacion) / 100.0) "
		  "FROM clientes WHERE idCliente = :rc LIMIT 1))) ";

	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add(q);
	  QueryAux->ParamByName("rep")->AsInteger = idRepartidor;
	  QueryAux->ParamByName("rc")->AsInteger = id;
	  QueryAux->ParamByName("f")->AsDate = DTP->Date;
	  QueryAux->ExecSQL();
	  ok = true;
   }
   else
   {
	  if(refRepartidor != idRepartidor)
	  {
		 String msg = "Este cliente ya se encuentra agregado en otra planilla, desea cambiarlo a esta planilla por este d�a?";

		 if(Application->MessageBox(msg.w_str(), L"Transferir temporalmente este cliente?",
		 							MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
		 {
			QueryUpdate->Close();
			QueryUpdate->SQL->Clear();
			QueryUpdate->SQL->Add("UPDATE cuentas SET refRepartidor = :rr WHERE idCuenta = :id");
			QueryUpdate->ParamByName("id")->AsInteger = idCuenta;
			QueryUpdate->ParamByName("rr")->AsString = idRepartidor;
			QueryUpdate->ExecSQL();
			ok = true;
		 }
	  }
	  else
	  {
		 String msg = "Este cliente ya se encuentra agregado en esta planilla";
		 String title = "No se agreg� el cliente.";
		 Application->MessageBox(msg.w_str(), title.w_str(), MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
         ok = true;
	  }
   }

   CDS->Active = true;

   if(ok)
   {
	  CDS->First();
	  while(!CDS->Eof)
	  {
		 if(CDS->FieldByName("refCliente")->AsInteger == id)
			break;

		 CDS->Next();
	  }
	  DBGrid1->SelectedIndex = 2;
	  DBGrid1->SetFocus();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button7Click(TObject *Sender)
{
   if(Application->MessageBox(L"Se van a poner en cero todos las unidades y los pagos. Realmente desea continaur?",
   							  L"ATENCION!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  CDS->First();
	  while(!CDS->Eof)
	  {
		 CDS->Edit();
		 CDS->FieldByName("pagoRealizado")->AsFloat = 0.0;
		 CDS->FieldByName("unidades")->AsFloat = 0.0;
		 CDS->Post();
		 CDS->Next();
	  }
   }
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::DTPChange(TObject *Sender)
{
  if(CompareDate(DateOf(Now()), DTP->Date) == LessThanValue)
  {
	 Application->MessageBox(L"No es posible configurar una fecha posterior a este d�a." ,L"Error.",
								MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	 DTP->Date = DateOf(Now());
	 return;
  }
  if(DayOfTheWeek(DTP->Date) == DaySunday)
  {
	 Application->MessageBox(L"Al menos por ahora no trabajamos los domingos... :D" ,L"Error.",
	                           MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	 return;
  }
  if(DayOfTheWeek(DTP->Date) == DaySaturday)
	  esSabado = 1;
   else
	  esSabado = 0;


   QueryAux->Close();
   QueryAux->SQL->Clear();

   if(esSabado)
	  QueryAux->SQL->Add("SELECT descripcion FROM repartidores WHERE reparteSabados = 1 ORDER BY descripcion");
   else
	  QueryAux->SQL->Add("SELECT descripcion FROM repartidores ORDER BY descripcion");

   QueryAux->Open();

   ComboBox1->Clear();
   QueryAux->First();

   while(!QueryAux->Eof)
   {
	  ComboBox1->Items->Add(QueryAux->FieldByName("descripcion")->AsString);

	  QueryAux->Next();
   }
   QueryAux->Close();
   ComboBox1->ItemIndex = 0;
   ComboBox1->Enabled = true;

   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idRepartidor FROM repartidores WHERE descripcion = :des LIMIT 1");
   QueryAux->ParamByName("des")->AsString = ComboBox1->Text;
   QueryAux->Open();
   idRepartidor = QueryAux->FieldByName("idRepartidor")->AsInteger;
   QueryAux->Close();

   Button1->Enabled = true;
   Button2->Enabled = false;
   mostrado = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button8Click(TObject *Sender)
{
   Memo2->Clear();
   Panel2->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Button9Click(TObject *Sender)
{
   String q;
   QueryAux->Close();
   QueryAux->SQL->Clear();

   q = "SELECT * FROM (SELECT idCliente, CONCAT(calle, ' ', numero) AS cliente, "
	   "(IFNULL((SELECT nroUnidades FROM cantidades WHERE "
			"fecha = :fecha AND cantidades.refCliente = clientes.idCliente LIMIT 1), 0)) AS unidPedidos, "
	   "(IFNULL((SELECT unidades FROM cuentas WHERE "
	   		"fecha = :fecha AND cuentas.refCliente = clientes.idCliente LIMIT 1), 0)) AS unidPlanillas "
	   " FROM clientes) t WHERE t.unidPedidos <> t.unidPlanillas ";


   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
   QueryAux->Open();
   Memo2->Clear();
   QueryAux->First();
   Memo2->Lines->Add("LISTA DE IRREGULARIDADES:");
   Memo2->Lines->Add("");
   Memo2->Lines->Add("");
   Memo2->Lines->Add("CLIENTE                       CANT PEDIDA     CANT ENTREGADA");
   Memo2->Lines->Add("____________________________________________________________");
   Memo2->Lines->Add("");
   String a,b;
   while (!QueryAux->Eof)
   {
	  a = QueryAux->FieldByName("cliente")->AsString;
	  while(a.Length() < 35)
		 a = a + " ";
	  b = QueryAux->FieldByName("unidPedidos")->AsString;

	  while(b.Length() < 17)
		 b = b + " ";

	  Memo2->Lines->Add(a + b + QueryAux->FieldByName("unidPlanillas")->AsString);
	  QueryAux->Next();
   }
   Memo2->Lines->Add("____________________________________________________________");
   QueryAux->Close();

   Panel2->Visible = true;
   mostrado = true;
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Aadiruncomentario1Click(TObject *Sender)
{
   Button3Click(Button3);
}
//---------------------------------------------------------------------------

void __fastcall TfCargarPagos::Verestadodecuentadelcliente1Click(TObject *Sender)

{
   if(CDS->FieldByName("refCliente")->AsInteger > 2)
   {
	  fCuentas->idCliente = CDS->FieldByName("refCliente")->AsInteger;
	  fCuentas->ShowModal();
   }
}
//---------------------------------------------------------------------------

