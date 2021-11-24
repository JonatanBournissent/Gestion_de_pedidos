//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uRecetas.h"
#include "uSeleccionarComida.h"
#include "VariablesGlobales.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfRecetas *fRecetas;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfRecetas::TfRecetas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfRecetas::Button1Click(TObject *Sender)
{
   fSeleccionarComida->ShowModal();

   if(fSeleccionarComida->idSeleccionado <= 1)
	  return;

   idComida = fSeleccionarComida->idSeleccionado;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT nombre FROM comidas WHERE idComida = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = idComida;
   QueryAux->Open();
   Label1->Caption = "Receta de: " + QueryAux->FieldByName("nombre")->AsString;
   QueryAux->Close();

   QueryReceta->Close();
   QueryReceta->SQL->Clear();
   QueryReceta->SQL->Add("SELECT idReceta, descripcion FROM recetas WHERE refComida = :id LIMIT 1");
   QueryReceta->ParamByName("id")->AsInteger = idComida;
   QueryReceta->Open();
   if(QueryReceta->IsEmpty())
   {
	  QueryReceta->Close();
	  QueryReceta->SQL->Clear();
	  QueryReceta->SQL->Add("INSERT INTO recetas (refComida, descripcion)  VALUES (:refComida, NULL)");
	  QueryReceta->ParamByName("refComida")->AsInteger = idComida;
	  QueryReceta->ExecSQL();
	  QueryReceta->Close();
	  QueryReceta->SQL->Clear();
	  QueryReceta->SQL->Add("SELECT idReceta, descripcion FROM recetas WHERE refComida = :id LIMIT 1");
	  QueryReceta->ParamByName("id")->AsInteger = idComida;
	  QueryReceta->Open();
   }
   idReceta = QueryReceta->FieldByName("idReceta")->AsInteger;
   TStringStream *Stream;
   Stream = new TStringStream(QueryReceta->FieldByName("descripcion")->AsString);
   REMemo->Lines->LoadFromStream(Stream);
   QueryReceta->Close();

   delete Stream;
   guardado = true;

   REMemo->Enabled = true;
   Button4->Enabled = true;
   Button8->Enabled = true;
   ComboBox1->Enabled = true;
   Panel1->Enabled = true;
   Panel2->Enabled = true;
   Panel3->Enabled = true;
   Panel4->Enabled = true;
   Panel5->Enabled = true;
   Panel6->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::FormShow(TObject *Sender)
{
   idComida = 0;
   idReceta = 0;
   Label1->Caption = "Seleccione una comida...";
   REMemo->Clear();

   REMemo->Enabled = false;
   Button4->Enabled = false;
   Button8->Enabled = false;
   ComboBox1->Enabled = false;
   Panel1->Enabled = false;
   Panel2->Enabled = false;
   Panel3->Enabled = false;
   Panel4->Enabled = false;
   Panel5->Enabled = false;
   Panel6->Enabled = false;

   Panel4->Color = TColor(0x00DDDDDD);
   Panel5->Color = TColor(0x00DDDDDD);
   Panel6->Color = TColor(0x00DDDDDD);

   guardado = true;

   ComboBox1->Clear();
   ComboBox1->Items->Assign(Screen->Fonts);
   ComboBox1->ItemIndex = ComboBox1->Items->IndexOf("Calibri");

   Panel1->Font->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Button3Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(!guardado)
   {
	  int rta = Application->MessageBox(L"Desea guardar los cambios antes de salir?",L"Guardar cambios?",MB_YESNOCANCEL | MB_ICONQUESTION | MB_DEFBUTTON3);
	  if(rta == IDYES)
		 Button2Click(Button2);
	  else if(rta == IDCANCEL)
	  {
		 Action = caNone;
		 return;
	  }
   }

   QueryReceta->Close();
   QueryAux->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Button2Click(TObject *Sender)
{
   TStringStream *Stream;
   Stream = new TStringStream();
   REMemo->Lines->SaveToStream(Stream);


   QueryReceta->Close();
   QueryReceta->SQL->Clear();
   QueryReceta->SQL->Add("UPDATE recetas SET descripcion = :descripcion WHERE idReceta = :id LIMIT 1");
   QueryReceta->ParamByName("id")->AsInteger = idReceta;
   QueryReceta->ParamByName("descripcion")->AsString = Stream->DataString;
   QueryReceta->ExecSQL();

   delete Stream;

   guardado = true;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Button4Click(TObject *Sender)
{
   if(ColorDialog1->Execute())
   {
	  Panel1->Font->Color = ColorDialog1->Color;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel1Click(TObject *Sender)
{
   REMemo->SelAttributes->Color = Panel1->Font->Color;
}
//---------------------------------------------------------------------------


void __fastcall TfRecetas::Button8Click(TObject *Sender)
{
   REMemo->SelAttributes->Style = TFontStyles() >> fsUnderline >> fsItalic >> fsBold;
   REMemo->SelAttributes->Color = clBlack;
   REMemo->SelAttributes->Size = 11;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel2Click(TObject *Sender)
{
   if(REMemo->SelAttributes->Size < 128)
      REMemo->SelAttributes->Size = REMemo->SelAttributes->Size + 2;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel3Click(TObject *Sender)
{
   if(REMemo->SelAttributes->Size > 6)
	  REMemo->SelAttributes->Size = REMemo->SelAttributes->Size - 2;
}
//---------------------------------------------------------------------------
void __fastcall TfRecetas::REMemoSelectionChange(TObject *Sender)
{
   if(REMemo->SelAttributes->Style.Contains(fsBold))
   {
	  Panel4->BevelOuter = bvLowered;
	  Panel4->Color = TColor(0x009D9DFF);
   }
   else
   {
	  Panel4->BevelOuter = bvRaised;
	  Panel4->Color = TColor(0x00DDDDDD);
   }

   if(REMemo->SelAttributes->Style.Contains(fsItalic))
   {
	  Panel5->BevelOuter = bvLowered;
	  Panel5->Color = TColor(0x009D9DFF);
   }
   else
   {
	  Panel5->BevelOuter = bvRaised;
	  Panel5->Color = TColor(0x00DDDDDD);
   }

   if(REMemo->SelAttributes->Style.Contains(fsUnderline))
   {
	  Panel6->BevelOuter = bvLowered;
	  Panel6->Color = TColor(0x009D9DFF);
   }
   else
   {
	  Panel6->BevelOuter = bvRaised;
	  Panel6->Color = TColor(0x00DDDDDD);
   }

   ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(REMemo->SelAttributes->Name);
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel3MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel3->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel3MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel3->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel2MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel2->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel2MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel2->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel1->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   Panel1->BevelOuter = bvRaised;
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel4Click(TObject *Sender)
{
   if(Panel4->BevelOuter == bvRaised)
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style + (TFontStyles() << fsBold);
	  Panel4->BevelOuter = bvLowered;
	  Panel4->Color = TColor(0x009D9DFF);
   }
   else
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style - (TFontStyles() << fsBold);
	  Panel4->BevelOuter = bvRaised;
	  Panel4->Color = TColor(0x00DDDDDD);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel5Click(TObject *Sender)
{
   if(Panel5->BevelOuter == bvRaised)
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style + (TFontStyles() << fsItalic);
	  Panel5->BevelOuter = bvLowered;
	  Panel5->Color = TColor(0x009D9DFF);
   }
   else
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style - (TFontStyles() << fsItalic);
	  Panel5->BevelOuter = bvRaised;
	  Panel5->Color = TColor(0x00DDDDDD);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel6Click(TObject *Sender)
{
   if(Panel6->BevelOuter == bvRaised)
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style + (TFontStyles() << fsUnderline);
	  Panel6->BevelOuter = bvLowered;
	  Panel6->Color = TColor(0x009D9DFF);
   }
   else
   {
	  REMemo->SelAttributes->Style = REMemo->SelAttributes->Style - (TFontStyles() << fsUnderline);
	  Panel6->BevelOuter = bvRaised;
	  Panel5->Color = TColor(0x00DDDDDD);
   }
}
//---------------------------------------------------------------------------


void __fastcall TfRecetas::Panel4MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel5MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Panel6MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::Button8MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TfRecetas::REMemoChange(TObject *Sender)
{
   guardado = false;
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::ComboBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{
   dynamic_cast <TComboBox *>(Control)->Canvas->Font->Name = dynamic_cast <TComboBox *>(Control)->Items->Strings[Index];
   dynamic_cast <TComboBox *>(Control)->Canvas->Font->Size = 12;
   dynamic_cast <TComboBox *>(Control)->Canvas->FillRect(Rect);
   int t = dynamic_cast <TComboBox *>(Control)->Canvas->TextHeight(dynamic_cast <TComboBox *>(Control)->Items->Strings[Index]);
   t = Rect.Height() - t;
   t = t / 2;
   dynamic_cast <TComboBox *>(Control)->Canvas->TextOutW(Rect.Left + 5, Rect.Top + t, dynamic_cast <TComboBox *>(Control)->Items->Strings[Index]);
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::ComboBox1MeasureItem(TWinControl *Control, int Index, int &Height)

{
   if(Index != -1)
   {
	  dynamic_cast <TComboBox *>(Control)->Canvas->Font->Name = dynamic_cast <TComboBox *>(Control)->Items->Strings[Index];
	  dynamic_cast <TComboBox *>(Control)->Canvas->Font->Size = 12;
	  Height = dynamic_cast <TComboBox *>(Control)->Canvas->TextHeight(dynamic_cast <TComboBox *>(Control)->Items->Strings[Index]);
	  if(Height < 25)
		 Height = 25;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfRecetas::ComboBox1Change(TObject *Sender)
{
   REMemo->SelAttributes->Name = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
}
//---------------------------------------------------------------------------

