//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uProductos.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfProductos *fProductos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfProductos::TfProductos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfProductos::FormShow(TObject *Sender)
{
   Table1->Active = true;
   ClientDataSet1->Active = true;
   DBNavigator1->ShowHint = true;
}
//---------------------------------------------------------------------------
void __fastcall TfProductos::DBNavigator1Click(TObject *Sender, TNavigateBtn Button)

{
   if(Button == nbInsert)
   {
	  if(Application->MessageBox(L"Se va a agregar un nuevo producto. Desea continuar?",L"Agregar nuevo producto?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  {
		 ClientDataSet1->Cancel();
	  }
	  else
	  {
		 DBGrid1->Options = TDBGridOptions(DBGrid1->Options) << dgEditing;
		 ClientDataSet1->FieldByName("idProducto")->AsInteger = 0;
		 return;
	  }
   }
   else if(Button == nbEdit)
   {
	  DBGrid1->Options = TDBGridOptions(DBGrid1->Options) << dgEditing;
	  return;
   }
   else if(Button == nbPost)
   {
	  ClientDataSet1->ApplyUpdates(0);
   }
   DBGrid1->Options = TDBGridOptions(DBGrid1->Options) >> dgEditing;
}
//---------------------------------------------------------------------------
void __fastcall TfProductos::DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_DOWN || Key == VK_UP || Key == VK_TAB)
      Key = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TfProductos::FormClose(TObject *Sender, TCloseAction &Action)
{
   ClientDataSet1->Cancel();
   ClientDataSet1->Active = false;
   Table1->Active = false;
   DBNavigator1->ShowHint = false;

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfProductos::FormCreate(TObject *Sender)
{
//   TIniFile *Configuraciones;
//   String Dir = GetCurrentDir()+"//Config.ini";
//   Configuraciones = new TIniFile(Dir);
//
//   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
//   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
//   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";
//
//   delete Configuraciones;

   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

