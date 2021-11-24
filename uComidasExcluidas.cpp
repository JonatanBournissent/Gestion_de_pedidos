//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uComidasExcluidas.h"
#include "uSeleccionarComida.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfComidasExcluidas *fComidasExcluidas;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfComidasExcluidas::TfComidasExcluidas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfComidasExcluidas::FormShow(TObject *Sender)
{
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT refComida, "
					"(SELECT nombre FROM comidas WHERE comidasnocontroladas.refComida = comidas.idComida LIMIT 1) AS nombre, "
					"(SELECT codigo FROM comidas WHERE comidasnocontroladas.refComida = comidas.idComida LIMIT 1) AS codigo, "
					"(SELECT descripcion FROM categoriacomidas WHERE (SELECT refCategoriaComida FROM comidas WHERE comidasnocontroladas.refComida = comidas.idComida LIMIT 1) = idCategoriaComida LIMIT 1) AS categoria "
					"FROM comidasnocontroladas");
   Query1->Open();
   CDS1->Active = true;
   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfComidasExcluidas::Button1Click(TObject *Sender)
{
   fSeleccionarComida->idSeleccionado = 0;
   fSeleccionarComida->ShowModal();
   int idSel = fSeleccionarComida->idSeleccionado;
   if(idSel > 1)
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT COUNT(*) AS existe FROM comidasnocontroladas WHERE refComida = :idComida");
	  QueryAux->ParamByName("idComida")->AsInteger = idSel;
	  QueryAux->Open();

	  if(QueryAux->FieldByName("existe")->AsInteger > 0)
	  {
		 QueryAux->Close();
		 Application->MessageBox(L"Esta comida ya se encuentra agregada a la lista.",L"No se realizaron cambios!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		 return;
	  }

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("INSERT INTO comidasnocontroladas (refComida) VALUES (:idComida)");
	  QueryAux->ParamByName("idComida")->AsInteger = idSel;
	  QueryAux->ExecSQL();
	  CDS1->Refresh();
   }
}
//---------------------------------------------------------------------------
void __fastcall TfComidasExcluidas::Button2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfComidasExcluidas::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->Active = false;
   Query1->Close();
   QueryAux->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfComidasExcluidas::N1Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM comidasnocontroladas WHERE refComida = :idComida");
   QueryAux->ParamByName("idComida")->AsInteger = CDS1->FieldByName("refComida")->AsInteger;
   QueryAux->ExecSQL();
   CDS1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfComidasExcluidas::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfComidasExcluidas::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

