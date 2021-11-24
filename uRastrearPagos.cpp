//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uRastrearPagos.h"
#include "VariablesGlobales.h"
#include "uSeleccionarCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRastrearPagos *fRastrearPagos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfRastrearPagos::TfRastrearPagos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfRastrearPagos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------
void __fastcall TfRastrearPagos::FormShow(TObject *Sender)
{
   MC->MultiSelect = false;
   MC->Date = Now();
   MC->MultiSelect = true;
   MC->EndDate = Now();
   Edit1->Text = "$ 0,00";
   Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TfRastrearPagos::Button2Click(TObject *Sender)
{
   String q;

   q = "SELECT idCuenta, fecha, unidades, pagoRealizado, valorUnidad, refCliente, "
		  "(SELECT descripcion FROM obsCuentas WHERE cuentas.idCuenta = obscuentas.refCuenta LIMIT 1) AS obs, "
		  "(SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE cuentas.refCliente = clientes.idCliente LIMIT 1) AS cliente, "
		  "(SELECT nombreCorto FROM repartidores WHERE cuentas.refRepartidor = repartidores.idRepartidor LIMIT 1) AS rep "
		  "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff ";

   if(Edit1->Text != "$ 0,00")
	  q = q + " AND pagoRealizado = :pagoRealizado ";

   if(Edit2->Text != "")
	  q = q + " AND idCuenta IN (SELECT refCuenta FROM obsCuentas WHERE UPPER(obsCuentas.descripcion) LIKE :d) ";

   q = q + " ORDER by fecha DESC";

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add(q);

   if(Edit1->Text != "$ 0,00")
	  Query1->ParamByName("pagoRealizado")->AsFloat = StrToFloat(Edit1->Text.Delete(1,2));

   if(Edit2->Text != "")
	  Query1->ParamByName("d")->AsString = "%" + Edit2->Text.UpperCase() + "%";

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
void __fastcall TfRastrearPagos::Edit1Enter(TObject *Sender)
{
   if(dynamic_cast<TEdit *>(Sender)->Text.Pos("$ ") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = dynamic_cast<TEdit *>(Sender)->Text.Delete(1,2);

   dynamic_cast<TEdit *>(Sender)->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfRastrearPagos::Edit1Exit(TObject *Sender)
{
   String s = Edit1->Text;

   try
   {
	  if(s.Pos("$") > 0)
		 s = s.Delete(1,2);

	  StrToFloat(s);
   }
   catch(...)
   {
	  s = "0,00";
   }

   Edit1->Text = FormatFloat("$ 0.00", StrToFloat(s));
}
//---------------------------------------------------------------------------
void __fastcall TfRastrearPagos::Edit1Click(TObject *Sender)
{
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfRastrearPagos::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
