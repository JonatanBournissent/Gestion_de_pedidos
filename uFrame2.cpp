//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrame2.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame2 *Frame2;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TFrame2::TFrame2(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void TFrame2::restablecerFrame(void)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;

   idSeleccionado = 0;
   ClientDataSet1->Active = false;
   llamador = 1;     //solo utilizo el llamador en el caso de cargar un pedido a un cliente no habitual.
   Edit1->Clear();


   Query1->Close();
   Query1->SQL->Clear();
   if(llamador == 1) // todos los clientes
	  Query1->SQL->Add("SELECT idCliente, calle, numero, nombre, apellido FROM clientes WHERE idCliente > 2 ORDER BY numero");
   else if(llamador == 2)  //solo los que no figuran en planillas
	  Query1->SQL->Add("SELECT idCliente, calle, numero, nombre, apellido FROM clientes WHERE idCliente > 2 AND esVisible = 0 ORDER BY numero");

   Query1->Open();

   ClientDataSet1->Active = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void TFrame2::cerrarFrame(void)
{
   ClientDataSet1->Active = false;
   Query1->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFrame2::Edit1Change(TObject *Sender)
{
   ClientDataSet1->Active = false;
   if((Edit1->Text != "" && Edit1->Text.Length() >= 2) || Sender == Label1)
   {
	  Query1->Close();
	  Query1->SQL->Clear();
	  if(llamador == 1)
		 Query1->SQL->Add("SELECT idCliente, calle, numero, nombre, apellido FROM clientes "
						  "WHERE((UPPER(numero) LIKE :v OR UPPER(calle) LIKE :v OR UPPER(nombre) LIKE :v OR UPPER(apellido) LIKE :v) "
						  "AND idCliente > 2) ORDER BY esVisible DESC, numero ASC LIMIT 50");
	  if(llamador == 2)
		 Query1->SQL->Add("SELECT idCliente, calle, numero, nombre, apellido FROM clientes "
						  "WHERE((UPPER(numero) LIKE :v OR UPPER(calle) LIKE :v OR UPPER(nombre) LIKE :v OR UPPER(apellido) LIKE :v) "
						  "AND idCliente > 2 AND esVisible = 0) ORDER BY esVisible DESC, numero ASC LIMIT 50");
	  Query1->ParamByName("v")->AsString = "%" + Edit1->Text.UpperCase() + "%";
	  Query1->Open();
      ClientDataSet1->Active = true;
   }

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TFrame2::DBGrid1DblClick(TObject *Sender)
{
   if(!ClientDataSet1->IsEmpty())
	  idSeleccionado = ClientDataSet1->FieldByName("idCliente")->AsInteger;
   else
      idSeleccionado = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFrame2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
   if(ClientDataSet1->Active && ClientDataSet1->RecordCount == 1)
      DBGrid1DblClick(DBGrid1);
}
//---------------------------------------------------------------------------

void __fastcall TFrame2::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
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

void __fastcall TFrame2::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
	  Edit1Change(Label1);  //cualquier sender
   else if(Key == VK_DOWN)
      DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------


