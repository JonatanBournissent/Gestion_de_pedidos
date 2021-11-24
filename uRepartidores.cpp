//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uRepartidores.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRepartidores *fRepartidores;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfRepartidores::TfRepartidores(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::FormShow(TObject *Sender)
{
   Panel1->Visible = false;

   CDS->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT * FROM repartidores ORDER BY descripcion");
   Query1->Open();
   CDS->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CDSdescripcionChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE repartidores SET descripcion = :descripcion WHERE idRepartidor = :idRepartidor LIMIT 1");
   QueryUpdate->ParamByName("descripcion")->AsString = Sender->AsString;
   QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::FormClose(TObject *Sender, TCloseAction &Action)
{
   CDS->Active = false;
   Query1->Close();
   QueryUpdate->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN && CDS->Active && CDS->State == dsEdit)
      CDS->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::Button1Click(TObject *Sender)
{
//   Panel1->Left = (fRepartidores->Width - Panel1->Width) / 2;
//   Panel1->Top = (fRepartidores->Height - Panel1->Height) / 2;
   Edit1->Text = "";
   Edit2->Text = "";
   Panel1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::Button2Click(TObject *Sender)
{
   if(Edit1->Text == "" || Edit2->Text == "")
   {
	  Application->MessageBox(L"Se deben completar ambos datos antes de continuar",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(Application->MessageBox(L"Los repartidoes no se pueden eliminar. Realmente desea continuar?",L"Confirma que desea continuar?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("INSERT INTO repartidores (descripcion, nombreCorto, horario1, horario2, reparteSabados) "
						 "VALUES (:descripcion, :nombreCorto, '2020-06-20 00:00:00', '2020-06-20 00:00:00', 1)");
   QueryUpdate->ParamByName("descripcion")->AsString = Edit1->Text;
   QueryUpdate->ParamByName("nombreCorto")->AsString = Edit2->Text;
   QueryUpdate->ExecSQL();

   Panel1->Visible = false;
   CDS->Refresh();

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::Button3Click(TObject *Sender)
{
   CDS->Cancel();
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CDSnombreCortoChange(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE repartidores SET nombreCorto = :nombreCorto WHERE idRepartidor = :idRepartidor LIMIT 1");
   QueryUpdate->ParamByName("nombreCorto")->AsString = Sender->AsString;
   QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CDShorario1Change(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE repartidores SET horario1 = :horario1 WHERE idRepartidor = :idRepartidor LIMIT 1");
   QueryUpdate->ParamByName("horario1")->AsDateTime = Sender->AsDateTime;
   QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CDShorario2Change(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE repartidores SET horario2 = :horario2 WHERE idRepartidor = :idRepartidor LIMIT 1");
   QueryUpdate->ParamByName("horario2")->AsDateTime = Sender->AsDateTime;
   QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CDSNewRecord(TDataSet *DataSet)
{
   DataSet->Cancel();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::Button4Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::DBGrid1ColExit(TObject *Sender)
{
   if(DBGrid1->SelectedField == CB->Field)
	  CB->Visible = false;

   if(CDS->Active && CDS->State == dsEdit)
	  CDS->Post();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   int DrawState;
   if(State.Contains(gdFocused))
   {
	  if(Column->Field == CB->Field)
      {
		 CB->Left = Rect.Left + DBGrid1->Left + 2;
		 CB->Top = Rect.Top + DBGrid1->Top + 2;
		 CB->Width = Rect.Right - Rect.Left;
		 CB->Height = Rect.Bottom - Rect.Top;

		 CB->Visible = true;
	  }
   }
   else if(Column->Field == CB->Field)
   {
      DrawRect = new TRect(Rect);
	  InflateRect(DrawRect,-1,-1);

	  if(Column->Field->AsInteger == 0)
         DrawState = DFCS_BUTTONCHECK;
	  else
         DrawState = DFCS_BUTTONCHECK | DFCS_CHECKED;

	  DBGrid1->Canvas->FillRect(Rect);
	  DrawFrameControl(DBGrid1->Canvas->Handle , DrawRect, DFC_BUTTON, DrawState);
      delete DrawRect;
   }
}
//---------------------------------------------------------------------------


void __fastcall TfRepartidores::CDSreparteSabadosChange(TField *Sender)
{
//   QueryUpdate->Close();
//   QueryUpdate->SQL->Clear();
//   QueryUpdate->SQL->Add("UPDATE repartidores SET reparteSabados = :reparteSabados WHERE idRepartidor = :idRepartidor LIMIT 1");
//   QueryUpdate->ParamByName("reparteSabados")->AsInteger = Sender->AsInteger;
//   QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
//   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::CBClick(TObject *Sender)
{
   if(CB->Checked)
   {
	  QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE repartidores SET reparteSabados = 1 WHERE idRepartidor = :idRepartidor LIMIT 1");
	  QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
	  QueryUpdate->ExecSQL();
   }
   else
   {
      QueryUpdate->Close();
	  QueryUpdate->SQL->Clear();
	  QueryUpdate->SQL->Add("UPDATE repartidores SET reparteSabados = 0 WHERE idRepartidor = :idRepartidor LIMIT 1");
	  QueryUpdate->ParamByName("idRepartidor")->AsInteger = CDS->FieldByName("idRepartidor")->AsInteger;
	  QueryUpdate->ExecSQL();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfRepartidores::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

