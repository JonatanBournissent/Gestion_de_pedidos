//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uGestionDeGastos.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfGestionDeGastos *fGestionDeGastos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfGestionDeGastos::TfGestionDeGastos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit3Change(TObject *Sender)
{
   if(Edit3->Text != "")
   {
	  CDS2->Active = false;
	  Query2->Close();
	  Query2->SQL->Clear();
	  Query2->SQL->Add("SELECT idItemGasto, descripcion FROM itemsgastos WHERE UPPER(descripcion) LIKE :n LIMIT 20");
	  Query2->ParamByName("n")->AsString = "%" + Edit3->Text.UpperCase() + "%";
	  Query2->Open();
	  if(!Query2->IsEmpty())
		 CDS2->Active = true;
   }
   else
   {
	  CDS2->Close();
	  Query2->Close();
   }

   ShowScrollBar(DBGrid2->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Button1Click(TObject *Sender)
{
   if(!CDS2->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("INSERT INTO gastos (fecha, refItem, cantidad, total, comentario) VALUES (:fecha, :refItem, :cantidad, :total, :comentario)");
   QueryUpdate->ParamByName("fecha")->AsDate = MC->Date;
   QueryUpdate->ParamByName("refItem")->AsInteger = CDS2->FieldByName("idItemGasto")->AsInteger;
   QueryUpdate->ParamByName("cantidad")->AsFloat = StrToFloat(Edit1->Text);
   QueryUpdate->ParamByName("total")->AsFloat = StrToFloat(Edit2->Text.Delete(1,2));
   QueryUpdate->ParamByName("comentario")->AsString = Edit4->Text;
   QueryUpdate->ExecSQL();

   Edit1->Text = "1,00";
   Edit2->Text = "$ 0,00";
   Edit3->Text = "";
   Edit4->Text = "";

   MCClick(MC);
   Edit3->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Eliminarestetem1Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("DELETE FROM gastos WHERE idGasto = :idGasto LIMIT 1");
   QueryUpdate->ParamByName("idGasto")->AsInteger = CDS1->FieldByName("idGasto")->AsInteger;
   QueryUpdate->ExecSQL();

   CDS1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit2Enter(TObject *Sender)
{
   String txt = dynamic_cast<TEdit *>(Sender)->Text;
   if(txt.Pos("$ ") > 0)
	  dynamic_cast<TEdit *>(Sender)->Text = txt.Delete(1,2);
   dynamic_cast<TEdit *>(Sender)->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit2Exit(TObject *Sender)
{
   String txt = dynamic_cast<TEdit *>(Sender)->Text;
   if(txt.Length() == 0)
      txt = "0,00";
   if(txt.Pos("$ ") == 0)
	  dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("$ 0.00", StrToFloat(txt));
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit2KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Edit1KeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
	  Key = ',';
   if((Key < '0' || Key > '9') && Key != '\b' && Key != ',')
	  Key = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::FormShow(TObject *Sender)
{
   Panel1->Visible = false;
   Panel2->Visible = false;
   Edit1->Text = "1,00";
   Edit2->Text = "$ 0,00";
   Edit3->Text = "";
   Edit4->Text = "";
   MC->Date = Now();
   MCClick(MC);
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit1Click(TObject *Sender)
{
   dynamic_cast<TEdit *>(Sender)->SelectAll();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Edit2Click(TObject *Sender)
{
   dynamic_cast<TEdit *>(Sender)->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Edit1Exit(TObject *Sender)
{
   String txt = dynamic_cast<TEdit *>(Sender)->Text;
   if(txt.Length() == 0)
	  txt = "0,00";

   try
   {
	  StrToFloat(txt);
   }
   catch(...)
   {
	  txt = "0,00";
	  ShowMessage("El n�mero ingresado no es v�lido!");
   }
   dynamic_cast<TEdit *>(Sender)->Text = FormatFloat("0.00", StrToFloat(txt));
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::MCClick(TObject *Sender)
{
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT idGasto, cantidad, total, comentario, refItem, "
					"(SELECT descripcion FROM itemsgastos WHERE idItemGasto = refItem LIMIT 1) AS item "
					"FROM gastos WHERE fecha = :fecha");
   Query1->ParamByName("fecha")->AsDate = MC->Date;
   Query1->Open();
   if(!Query1->IsEmpty())
	  CDS1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TfGestionDeGastos::Button2Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT descripcion FROM categoriasgastos ORDER BY descripcion");
   QueryAux->Open();
   ComboBox1->Clear();
   QueryAux->First();

   while(!QueryAux->Eof)
   {
	  ComboBox1->Items->Add(QueryAux->FieldByName("descripcion")->AsString);

	  QueryAux->Next();
   }
   QueryAux->Close();
   ComboBox1->ItemIndex = -1;

   Edit5->Text = Edit3->Text;

   Shape1->Visible = false;
   Panel1->Visible = true;
   Edit5->SetFocus();
   Edit5->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Button4Click(TObject *Sender)
{
   if(ComboBox1->ItemIndex < 0)
   {
	  Shape1->Visible = true;
	  return;
   }
   if(Application->MessageBox(L"Desea agregar este �tem?",L"Agregar un nuevo �tem de gasto?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO itemsgastos (descripcion, refCategoria) VALUES (:descripcion, (SELECT idCategoriaGasto FROM categoriasgastos WHERE descripcion = :descCat LIMIT 1))");
   QueryAux->ParamByName("descripcion")->AsString = Edit5->Text;
   QueryAux->ParamByName("descCat")->AsString = ComboBox1->Items->Strings[ComboBox1->ItemIndex];
   QueryAux->ExecSQL();

   Panel1->Visible = false;

   Edit3->Text = Edit5->Text;
   Edit3Change(Edit3);
   Edit1->SetFocus();
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Button3Click(TObject *Sender)
{
   Edit6->Text = "";

   Panel2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Button5Click(TObject *Sender)
{
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::ComboBox1Change(TObject *Sender)
{
   if(ComboBox1->ItemIndex >= 0)
   {
	  Shape1->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Button6Click(TObject *Sender)
{
   if(Edit6->Text == "")
   {
	  return;
   }
   if(Application->MessageBox(L"Desea agregar esta categor�a?",L"Agregar una nueva categor�a de gasto?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("INSERT INTO categoriasgastos (descripcion) VALUES (:descripcion)");
   QueryAux->ParamByName("descripcion")->AsString = Edit6->Text;
   QueryAux->ExecSQL();

   Panel2->Visible = false;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT descripcion FROM categoriasgastos ORDER BY descripcion");
   QueryAux->Open();
   ComboBox1->Clear();
   QueryAux->First();

   while(!QueryAux->Eof)
   {
	  ComboBox1->Items->Add(QueryAux->FieldByName("descripcion")->AsString);

	  QueryAux->Next();
   }
   QueryAux->Close();
   ComboBox1->ItemIndex = -1;

   ComboBox1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfGestionDeGastos::Button7Click(TObject *Sender)
{
   Panel2->Visible = false;
}
//---------------------------------------------------------------------------

