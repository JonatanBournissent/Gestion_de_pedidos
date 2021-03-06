//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#include <Clipbrd.hpp>
#pragma hdrstop

#include "uCuentas.h"
#include "uImprimirCuentas.h"
#include "uSeleccionarCliente.h"
#include "uModificarCliente.h"
#include "VariablesGlobales.h"
#include "uEmitirComprobanteElectronico.h"
#include "uVerHistorialPedidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfCuentas *fCuentas;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfCuentas::TfCuentas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TfCuentas::calcular(bool parcial)
{
   String q;

   q = "SELECT SUM(unidades) AS suma, ";
   q = q + "(SELECT SUM(saldoParcial) FROM cuentas WHERE refCliente = :rc) AS deudaTotal, ";
   q = q + "(SELECT SUM(saldoParcial) FROM cuentas WHERE refCliente = :rc AND fecha <= :ff) AS deudaParcial ";
   q = q + "FROM cuentas WHERE refCliente = :rc AND fecha >= :fi AND fecha <= :ff";

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("rc")->AsInteger = idCliente;
   QueryAux->ParamByName("fi")->AsDate = MC->Date;
   QueryAux->ParamByName("ff")->AsDate = MC->EndDate;

   QueryAux->Open();
   float unidTotales = QueryAux->FieldByName("suma")->AsFloat;
   float deudaTotal = QueryAux->FieldByName("deudaTotal")->AsFloat;
   float deudaParcial = QueryAux->FieldByName("deudaParcial")->AsFloat;
   QueryAux->Close();

   if(deudaTotal > 0)
   {
	  Label1->Font->Color = clRed;
	  Label1->Caption = FormatFloat("Deuda total acumulada: $ 0.00", deudaTotal);
   }
   else if(deudaTotal < 0)
   {
	  Label1->Font->Color = clBlue;
	  Label1->Caption = FormatFloat("Saldo total a favor: $ 0.00", -1.0 * deudaTotal);
   }
   else
   {
	  Label1->Font->Color = clGreen;
	  Label1->Caption = "No presenta deudas ni saldos a favor";
   }


   if(deudaParcial > 0)
   {
	  Label3->Font->Color = clRed;
	  Label3->Caption = FormatFloat("Deuda parcial acumulada: $ 0.00", deudaParcial) + " (Hasta el d?a " + DateToStr(MC->EndDate) + " inclu?do)";
   }
   else if(deudaParcial < 0)
   {
	  Label3->Font->Color = clBlue;
	  Label3->Caption = FormatFloat("Saldo parcial a favor: $ 0.00", -1.0 * deudaParcial) + " (Hasta el d?a " + DateToStr(MC->EndDate) + " inclu?do)";
   }
   else
   {
	  Label3->Font->Color = clGreen;
	  Label3->Caption = "No presenta deudas hasta el d?a " + DateToStr(MC->EndDate) + " inclu?do";
   }

   Label2->Caption = FormatFloat("Se entregaron: 0.## vianda(s) en el per?odo analizado", unidTotales);


   if(CheckBox1->Checked)
   {
	  q = "SELECT idCuenta, fecha, unidades, pagoRealizado, valorUnidad, "
		  "(SELECT descripcion FROM obsCuentas WHERE cuentas.idCuenta = obscuentas.refCuenta LIMIT 1) AS obs, "
		  "(SELECT nombreCorto FROM repartidores WHERE cuentas.refRepartidor = repartidores.idRepartidor LIMIT 1) AS rep "
		  "FROM cuentas WHERE refCliente = :rc AND fecha >= :fi AND fecha <= :ff ORDER by fecha";
   }
   else
   {
	  q = "SELECT idCuenta, fecha, unidades, pagoRealizado, valorUnidad, "
		  "(SELECT descripcion FROM obsCuentas WHERE cuentas.idCuenta = obscuentas.refCuenta LIMIT 1) AS obs, "
		  "(SELECT nombreCorto FROM repartidores WHERE cuentas.refRepartidor = repartidores.idRepartidor LIMIT 1) AS rep "
		  "FROM cuentas WHERE refCliente = :rc AND fecha >= :fi AND fecha <= :ff  AND (unidades <> 0.0 OR pagoRealizado <> 0.0) ORDER by fecha";
   }

   if(parcial)
   {
	  int rec = CDS->RecNo;
	  CDS->Active = false;
	  CDS->Active = true;
	  if(CDS->IsEmpty())
	  {
		 CDS->Active = false;
		 Button2->SetFocus();
		 return;
	  }
	  CDS->RecNo = rec;
	  return;
   }

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);
   Query1->ParamByName("rc")->AsInteger = idCliente;
   Query1->ParamByName("fi")->AsDate = MC->Date;
   Query1->ParamByName("ff")->AsDate = MC->EndDate;
   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}

//---------------------------------------------------------------------------
void __fastcall TfCuentas::Button2Click(TObject *Sender)
{
   if(frecPago == 3)
   {
	  MC->Date = StartOfTheMonth(IncDay(StartOfTheMonth(MC->Date), -1));
	  MC->EndDate = EndOfTheMonth(MC->Date);
   }
   else
   {
	  MC->Date = StartOfTheWeek(IncDay(StartOfTheWeek(MC->Date), -1));
	  MC->EndDate = IncDay(EndOfTheWeek(MC->Date), -1);
   }

   calcular(false);
}
//---------------------------------------------------------------------------
void __fastcall TfCuentas::Button3Click(TObject *Sender)
{
   if(frecPago == 3)
   {
	  MC->Date = IncDay(EndOfTheMonth(MC->Date), 1);
	  MC->EndDate = EndOfTheMonth(MC->Date);
   }
   else
   {
	  MC->Date = IncDay(EndOfTheWeek(MC->Date), 1);
	  MC->EndDate = IncDay(EndOfTheWeek(MC->Date), -1);
   }

   calcular(false);
}
//---------------------------------------------------------------------------
void __fastcall TfCuentas::MCClick(TObject *Sender)
{
   calcular(false);
}
//---------------------------------------------------------------------------
void __fastcall TfCuentas::FormShow(TObject *Sender)
{
   CheckBox1->Checked = false;
   Panel1->Hide();
   Edit1->Clear();
   CDS2->Active = false;
   Query2->Close();

   if(idCliente == 0)
   {
      fSeleccionarCliente->llamador = 1;
	  fSeleccionarCliente->ShowModal();

	  if(fSeleccionarCliente->idSeleccionado < 3)
	  {
		 idCliente = 0;
		 Timer1->Enabled = true;
	  }

	  idCliente = fSeleccionarCliente->idSeleccionado;
      //FormShow(fCuentas);
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT calle, numero, refFrecuenciaPago FROM clientes WHERE idCliente = :idC LIMIT 1");
   QueryAux->ParamByName("idC")->AsInteger = idCliente;
   QueryAux->Open();
   frecPago = QueryAux->FieldByName("refFrecuenciaPago")->AsInteger;
   Label4->Caption =  "Cliente seleccionado: " + QueryAux->FieldByName("calle")->AsString + " " + QueryAux->FieldByName("numero")->AsString;;

   QueryAux->Close();

   MC->MultiSelect = false;
   MC->Date = Now();
   MC->MultiSelect = true;

   if(frecPago == 3)
   {
	  MC->Date = StartOfTheMonth(Now());
	  MC->EndDate = EndOfTheMonth(Now());
	  Label4->Caption = Label4->Caption + " (Pago mensual)";
   }
   else if(frecPago == 2)
   {
	  MC->Date = StartOfTheWeek(Now());
	  MC->EndDate = IncDay(EndOfTheWeek(Now()), -1);
	  Label4->Caption = Label4->Caption + " (Pago semanal)";
   }
   else if(frecPago == 1)
   {
	  MC->Date = StartOfTheWeek(Now());
	  MC->EndDate = IncDay(EndOfTheWeek(Now()), -1);
	  Label4->Caption = Label4->Caption + " (Pago diario)";
   }

   Button5->Visible = false;

   calcular(false);
}
//---------------------------------------------------------------------------
void __fastcall TfCuentas::Button1Click(TObject *Sender)
{
   fSeleccionarCliente->llamador = 1;
   fSeleccionarCliente->ShowModal();

   if(fSeleccionarCliente->idSeleccionado < 3)
	  return;

   idCliente = fSeleccionarCliente->idSeleccionado;
   FormShow(Label1);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormCreate(TObject *Sender)
{
   idCliente = 0;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(fVerHistorialPedidos->Showing)
	  fVerHistorialPedidos->Close();

   idCliente = 0;
   CDS->Active = false;
   Query1->Close();
   QueryAux->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSunidadesChange(TField *Sender)
{
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, :pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DateOf(CDS->FieldByName("fecha")->AsDateTime);
   QueryUpdate->ParamByName("refCliente")->AsInteger = idCliente;
   QueryUpdate->ParamByName("unidades")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = CDS->FieldByName("pagoRealizado")->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = CDS->FieldByName("valorUnidad")->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;;
   QueryUpdate->ExecSQL();

   calcular(true);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSpagoRealizadoChange(TField *Sender)
{

   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, :pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DateOf(CDS->FieldByName("fecha")->AsDateTime);
   QueryUpdate->ParamByName("refCliente")->AsInteger = idCliente;
   QueryUpdate->ParamByName("unidades")->AsFloat = CDS->FieldByName("unidades")->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = CDS->FieldByName("valorUnidad")->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();

   calcular(true);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSvalorUnidadChange(TField *Sender)
{

   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL actualizarCuenta(:fSemanal, :fMensual, :fechaActualizada , :unidades, :pago, :valor ,:refCliente, :idC)");
   QueryUpdate->ParamByName("fSemanal")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("fMensual")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fechaActualizada")->AsDate = DateOf(CDS->FieldByName("fecha")->AsDateTime);
   QueryUpdate->ParamByName("refCliente")->AsInteger = idCliente;
   QueryUpdate->ParamByName("unidades")->AsFloat = CDS->FieldByName("unidades")->AsFloat;
   QueryUpdate->ParamByName("pago")->AsFloat = CDS->FieldByName("pagoRealizado")->AsFloat;
   QueryUpdate->ParamByName("valor")->AsFloat = Sender->AsFloat;
   QueryUpdate->ParamByName("idC")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->ExecSQL();

   calcular(true);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CDSobsChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("SELECT idObsCuenta FROM obscuentas WHERE refCuenta = :id LIMIT 1");
   QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
   QueryUpdate->Open();

   if(!QueryUpdate->IsEmpty())
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE obsCuentas SET descripcion = :descripcion WHERE refCuenta = :id LIMIT 1");
	  QueryUpdate->ParamByName("descripcion")->AsString = Sender->AsString;
	  QueryUpdate->ParamByName("id")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
	  QueryUpdate->ExecSQL();
   }
   else
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("INSERT INTO obsCuentas (refCuenta, descripcion)  VALUES (:refCuenta, :descripcion)");
	  QueryUpdate->ParamByName("descripcion")->AsString = Sender->AsString;
	  QueryUpdate->ParamByName("refCuenta")->AsInteger = CDS->FieldByName("idCuenta")->AsInteger;
	  QueryUpdate->ExecSQL();
   }
}
//---------------------------------------------------------------------------


void __fastcall TfCuentas::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN && CDS->Active && CDS->State == dsEdit)
	  CDS->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::DBGrid1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  if(DBGrid1->SelectedIndex != 5)
		 Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Mostrarestasemana1Click(TObject *Sender)
{
   MC->MultiSelect = false;
   MC->Date = Now();
   MC->MultiSelect = true;

   if(frecPago == 3)
   {
	  MC->Date = StartOfTheMonth(Now());
	  MC->EndDate = EndOfTheMonth(Now());
   }
   else if(frecPago == 2)
   {
	  MC->Date = StartOfTheWeek(Now());
	  MC->EndDate = IncDay(EndOfTheWeek(Now()), -1);
   }
   else if(frecPago == 1)
   {
	  MC->Date = StartOfTheWeek(Now());
	  MC->EndDate = IncDay(EndOfTheWeek(Now()), -1);
   }

   calcular(false);
}
//---------------------------------------------------------------------------


void __fastcall TfCuentas::Button4Click(TObject *Sender)
{
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("CALL calcularSaldoCliente(:f1, :f2, :fref , :refCliente)");
   QueryUpdate->ParamByName("f1")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
   QueryUpdate->ParamByName("f2")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
   QueryUpdate->ParamByName("fref")->AsDate = DateOf(IncYear(Now(), -10));
   QueryUpdate->ParamByName("refCliente")->AsInteger = idCliente;
   QueryUpdate->ExecSQL();

   calcular(true);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button5Click(TObject *Sender)
{
   CDS->Active = false;
   Query1->Close();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idCliente FROM clientes");
   QueryAux->Open();

   QueryAux->First();

   while(!QueryAux->Eof)
   {
	  Button5->Caption = "Id cli: " + IntToStr(QueryAux->FieldByName("idCliente")->AsInteger);

	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("CALL calcularSaldoCliente(:f1, :f2, :fref , :refCliente)");
	  QueryUpdate->ParamByName("f1")->AsDate = DateOf(IncDay(StartOfTheWeek(Now()),-1));
	  QueryUpdate->ParamByName("f2")->AsDate = DateOf(IncDay(StartOfTheMonth(Now()),-1));
	  QueryUpdate->ParamByName("fref")->AsDate = DateOf(IncYear(Now(), -10));
	  QueryUpdate->ParamByName("refCliente")->AsInteger = QueryAux->FieldByName("idCliente")->AsInteger;
	  QueryUpdate->ExecSQL();

	  QueryAux->Next();
   }
   QueryAux->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_F11)
	  Button5->Visible = true;
   else if (Shift.Contains(ssCtrl) && Key == VK_F1) {

	  Edit1->Clear();
	  Panel1->Show();
	  Edit1->SetFocus();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button6Click(TObject *Sender)
{
   if(idCliente <= 2)
	  return;

   fModificarCliente->Show();

   fModificarCliente->Frame11->id = idCliente;
   fModificarCliente->Frame21->cerrarFrame();
   fModificarCliente->Frame21->Enabled = false;
   fModificarCliente->Frame11->llamador = 2;
   fModificarCliente->Frame11->Enabled = true;
   fModificarCliente->Frame11->restablecerFrame();
   fModificarCliente->Button1->Enabled = true;
   fModificarCliente->Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button7Click(TObject *Sender)
{
   fImprimirCuentas->Show();
   if (idCliente > 2) {
	   fImprimirCuentas->MC->Date = MC->EndDate;
	   fImprimirCuentas->usarClienteIndicado = true;
	   fImprimirCuentas->refClienteIndicado = idCliente;
	   if (frecPago == 1) {
		  fImprimirCuentas->RG1->ItemIndex = 2;
	   }
	   else if(frecPago == 2)
		  fImprimirCuentas->RG1->ItemIndex = 0;
	   else
		  fImprimirCuentas->RG1->ItemIndex = 1;

	   fImprimirCuentas->Button8Click(fImprimirCuentas->RG1); // el Sender es para completar nada mas
	   fImprimirCuentas->Button7Click(fImprimirCuentas->RG1); // el Sender es para completar nada mas
   }
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button8Click(TObject *Sender)
{

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT SUM(unidades) AS cantidad, valorUnidad FROM cuentas WHERE fecha >= :fi AND fecha <= :ff AND refCliente = :refCliente GROUP BY valorUnidad ORDER BY valorUnidad");
   QueryAux->ParamByName("refCliente")->AsInteger = idCliente;
   QueryAux->ParamByName("fi")->AsDate = MC->Date;
   QueryAux->ParamByName("ff")->AsDate = MC->EndDate;
   QueryAux->Open();

   QueryAux->First();
   fEmitirComprobanteElectronico->Show();
   fEmitirComprobanteElectronico->mostrarCliente(idCliente);

   int i = 0;
   bool error = false;
   while(!QueryAux->Eof)
   {
	  if(i == 0)
	  {
		 fEmitirComprobanteElectronico->Edit3->Text = QueryAux->FieldByName("cantidad")->AsString;
		 fEmitirComprobanteElectronico->Edit5->Text = QueryAux->FieldByName("valorUnidad")->AsString;
	  }
	  else if(i == 1)
	  {
		 fEmitirComprobanteElectronico->Edit6->Text = QueryAux->FieldByName("cantidad")->AsString;
		 fEmitirComprobanteElectronico->Edit8->Text = QueryAux->FieldByName("valorUnidad")->AsString;
	  }
	  else if(i == 2)
	  {
		 fEmitirComprobanteElectronico->Edit9->Text = QueryAux->FieldByName("cantidad")->AsString;
		 fEmitirComprobanteElectronico->Edit11->Text = QueryAux->FieldByName("valorUnidad")->AsString;
	  }
	  else if(i == 3)
	  {
		 fEmitirComprobanteElectronico->Edit12->Text = QueryAux->FieldByName("cantidad")->AsString;
		 fEmitirComprobanteElectronico->Edit14->Text = QueryAux->FieldByName("valorUnidad")->AsString;
	  }
	  else if(i == 4)
	  {
		 fEmitirComprobanteElectronico->Edit15->Text = QueryAux->FieldByName("cantidad")->AsString;
		 fEmitirComprobanteElectronico->Edit17->Text = QueryAux->FieldByName("valorUnidad")->AsString;
	  }
	  else
	  {
		 error = true;
		 break;
	  }
	  QueryAux->Next();
	  i++;
   }
   QueryAux->Close();

   if(error)
      ShowMessage("ERROR: Hay mas datos para incluir en la factura pero no hay mas renglones disponibles. Deber? solucionar el inconveniente realizando la misma de forma manual");
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Verpedidosdeesteda1Click(TObject *Sender)
{
   if(!CDS->Active || CDS->IsEmpty())
	  return;

   fVerHistorialPedidos->idCliente = idCliente;
   fVerHistorialPedidos->Show();
   fVerHistorialPedidos->mostrar(idCliente, DateOf(CDS->FieldByName("fecha")->AsDateTime), DateOf(CDS->FieldByName("fecha")->AsDateTime));
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Timer1Timer(TObject *Sender)
{
   Timer1->Enabled = false;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button10Click(TObject *Sender)
{
   String q;

   q = "SELECT (SELECT SUM(saldoParcial) FROM cuentas WHERE refCliente = :rc AND fecha < :fi) AS deudaAnterior, "
	   "(SELECT SUM(saldoParcial) FROM cuentas WHERE refCliente = :rc AND fecha <= :ff) AS deudaParcial";

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("rc")->AsInteger = idCliente;
   QueryAux->ParamByName("fi")->AsDate = MC->Date;
   QueryAux->ParamByName("ff")->AsDate = MC->EndDate;

   QueryAux->Open();
   float deudaAnterior = QueryAux->FieldByName("deudaAnterior")->AsFloat;
   float deudaParcial = QueryAux->FieldByName("deudaParcial")->AsFloat;
   QueryAux->Close();



   TStringList * Lista;
   Lista = new TStringList();
   Lista->Clear();
   String cliente = Label4->Caption.SubString(23, Label4->Caption.Pos("(") - 24);

   Lista->Add("*RESUMEN DE CUENTA*");
   Lista->Add("");
   Lista->Add("*Cliente:* " + cliente);
   Lista->Add("");

   if(deudaAnterior > 0.0)
   {
	  Lista->Add("*DEUDA ANTERIOR:* " + FormatFloat("$0.00", deudaAnterior));
	  Lista->Add("");
   }

   CDS->First();
   while(!CDS->Eof)
   {
	  Lista->Add("*" + FormatDateTime("dd/mm", CDS->FieldByName("fecha")->AsDateTime) + "* - " + FormatFloat("0.00", CDS->FieldByName("unidades")->AsFloat) + "v = " + FormatFloat("$0.00", CDS->FieldByName("unidades")->AsFloat * CDS->FieldByName("valorUnidad")->AsFloat));
	  if(CDS->FieldByName("pagoRealizado")->AsFloat > 0.0)
	  {
		 Lista->Add("   *Pago " + FormatDateTime("dd/mm", CDS->FieldByName("fecha")->AsDateTime) + "* " + FormatFloat("$0.00", CDS->FieldByName("pagoRealizado")->AsFloat));
         Lista->Add("");
	  }
	  CDS->Next();
   }
   Lista->Add("");

   if(CompareDateTime(MC->EndDate, Now()) == GreaterThanValue)
	  Lista->Add("*Saldo al " + FormatDateTime("dd/mm/yyyy", Now()) + ":* " + FormatFloat("$0.00", deudaParcial));
   else
	  Lista->Add("*Saldo al " + FormatDateTime("dd/mm/yyyy", MC->EndDate) + ":* " + FormatFloat("$0.00", deudaParcial));

   TClipboard *cb;
   cb = new TClipboard();
   cb->AsText = Lista->Text;
   delete cb;
   delete Lista;

   Application->MessageBox(L"Resumen copiado al portapapeles.\nPuede pegarlo en WhatsApp",L"Resumen copiado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::CheckBox1Click(TObject *Sender)
{
   calcular(false);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Edit1Change(TObject *Sender)
{
   if (Edit1->Text.Length() < 3) {

	   CDS2->Active = false;
	   Query2->Close();
       return;
   }

   CDS2->Active = false;

   String q;

   q = "SELECT DISTINCT refCliente, "
		  "(SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE cuentas.refCliente = clientes.idCliente LIMIT 1) AS cliente "
		  "FROM cuentas WHERE fecha > (NOW() - INTERVAL 12 MONTH) "
   	      "AND idCuenta IN (SELECT refCuenta FROM obsCuentas WHERE UPPER(obsCuentas.descripcion) LIKE :d) ";

   Query2->Close();
   Query2->SQL->Clear();
   Query2->SQL->Add(q);
   Query2->ParamByName("d")->AsString = "%" + Edit1->Text.UpperCase() + "%";
   Query2->Open();

   if (Query2->IsEmpty()) {
	   Query2->Close();
	   return;
   }
   CDS2->Active = true;

   Query2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::Button9Click(TObject *Sender)
{
   Panel1->Hide();
   CDS2->Active = false;
   Query2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   if(Column->Field->Index == 3 && Column->Field->AsFloat > 0)
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clGreen;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Style = TFontStyles() << fsBold;
   }
   else if(Column->Field->Index == 3)
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clBlack;

   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);
       else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfCuentas::DBGrid2DblClick(TObject *Sender)
{
   idCliente = CDS2->FieldByName("refCliente")->AsInteger;
   FormShow(Label1);
}
//---------------------------------------------------------------------------

