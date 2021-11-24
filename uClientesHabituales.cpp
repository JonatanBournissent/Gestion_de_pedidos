//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uClientesHabituales.h"
#include "VariablesGlobales.h"
#include "uSeleccionarCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfClientesHabituales *fClientesHabituales;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfClientesHabituales::TfClientesHabituales(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::FormShow(TObject *Sender)
{
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT *, (SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE "
   	   "clientesHabituales.refCliente = clientes.idCliente LIMIT 1) AS cliente FROM clienteshabituales ORDER BY cliente";
   Query1->SQL->Add(q);
   Query1->Open();
   CDS1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::Agregaruncliente1Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   fSeleccionarCliente->llamador = 1;
   fSeleccionarCliente->ShowModal();
   if(fSeleccionarCliente->idSeleccionado <= 2)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q;
   q = "SELECT refCliente FROM clienteshabituales WHERE refCliente = :idCliente LIMIT 1";
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idCliente")->AsInteger = fSeleccionarCliente->idSeleccionado;
   QueryAux->Open();
   if(!QueryAux->IsEmpty())
   {
	  QueryAux->Close();
	  Application->MessageBox(L"Este cliente ya se encuentra agregado" ,L"No se realizaron cambios",
								MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   q = "INSERT INTO clienteshabituales (refCliente, Lunes, Martes, Miercoles, Jueves, Viernes, Sabado) "
       "VALUES(:idCliente, 1, 1, 1, 1, 1, 0)";
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idCliente")->AsInteger = fSeleccionarCliente->idSeleccionado;
   QueryAux->ExecSQL();


   if(CDS1->Active && CDS1->State == dsEdit)
	  CDS1->Post();
   CDS1->ApplyUpdates(0);
   CDS1->Active = false;
   CDS1->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::Quitaresteclientedelalista1Click(TObject *Sender)

{
   if(!CDS1->Active)
	  return;

   if(Application->MessageBox(L"Se va a quitar este cliente de la lista. Desea continuar?" ,
   							  L"Quitar cliente de la lista?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q = "DELETE FROM clienteshabituales WHERE idClienteHabitual = :idClienteHabitual LIMIT 1";
   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
   CDS1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::Button1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::DBGrid1ColExit(TObject *Sender)
{
   if(DBGrid1->SelectedField == CB1->Field)
	  CB1->Visible = false;
   else if(DBGrid1->SelectedField == CB2->Field)
	  CB2->Visible = false;
   else if(DBGrid1->SelectedField == CB3->Field)
	  CB3->Visible = false;
   else if(DBGrid1->SelectedField == CB4->Field)
	  CB4->Visible = false;
   else if(DBGrid1->SelectedField == CB5->Field)
	  CB5->Visible = false;
   else if(DBGrid1->SelectedField == CB6->Field)
	  CB6->Visible = false;

   if(CDS1->Active && CDS1->State == dsEdit)
	  CDS1->Post();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   int DrawState;
   if(State.Contains(gdFocused))
   {
	  if(Column->Field == CB1->Field)
	  {
		 CB1->Left = Rect.Left + DBGrid1->Left + 2;
		 CB1->Top = Rect.Top + DBGrid1->Top + 2;
		 CB1->Width = Rect.Right - Rect.Left;
		 CB1->Height = Rect.Bottom - Rect.Top;

		 CB1->Visible = true;
	  }
	  else if(Column->Field == CB2->Field)
	  {
		 CB2->Left = Rect.Left + DBGrid1->Left + 2;
		 CB2->Top = Rect.Top + DBGrid1->Top + 2;
		 CB2->Width = Rect.Right - Rect.Left;
		 CB2->Height = Rect.Bottom - Rect.Top;

		 CB2->Visible = true;
	  }
	  else if(Column->Field == CB3->Field)
	  {
		 CB3->Left = Rect.Left + DBGrid1->Left + 2;
		 CB3->Top = Rect.Top + DBGrid1->Top + 2;
		 CB3->Width = Rect.Right - Rect.Left;
		 CB3->Height = Rect.Bottom - Rect.Top;

		 CB3->Visible = true;
	  }
	  else if(Column->Field == CB4->Field)
	  {
		 CB4->Left = Rect.Left + DBGrid1->Left + 2;
		 CB4->Top = Rect.Top + DBGrid1->Top + 2;
		 CB4->Width = Rect.Right - Rect.Left;
		 CB4->Height = Rect.Bottom - Rect.Top;

		 CB4->Visible = true;
	  }
	  else if(Column->Field == CB5->Field)
	  {
		 CB5->Left = Rect.Left + DBGrid1->Left + 2;
		 CB5->Top = Rect.Top + DBGrid1->Top + 2;
		 CB5->Width = Rect.Right - Rect.Left;
		 CB5->Height = Rect.Bottom - Rect.Top;

		 CB5->Visible = true;
	  }
	  else if(Column->Field == CB6->Field)
	  {
		 CB6->Left = Rect.Left + DBGrid1->Left + 2;
		 CB6->Top = Rect.Top + DBGrid1->Top + 2;
		 CB6->Width = Rect.Right - Rect.Left;
		 CB6->Height = Rect.Bottom - Rect.Top;

		 CB6->Visible = true;
	  }
   }
   else if(Column->Field == CB1->Field || Column->Field == CB2->Field || Column->Field == CB3->Field ||
   		   Column->Field == CB4->Field || Column->Field == CB5->Field || Column->Field == CB6->Field)
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
void __fastcall TfClientesHabituales::CDS1LunesChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Lunes = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::CDS1MartesChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Martes = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::CDS1MiercolesChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Miercoles = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::CDS1JuevesChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Jueves = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::CDS1ViernesChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Viernes = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::CDS1SabadoChange(TField *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE clientesHabituales SET Sabado = :var WHERE idClienteHabitual = :idClienteHabitual LIMIT 1");
   QueryAux->ParamByName("var")->AsInteger = Sender->AsInteger;
   QueryAux->ParamByName("idClienteHabitual")->AsInteger = CDS1->FieldByName("idClienteHabitual")->AsInteger;
   QueryAux->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfClientesHabituales::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->ApplyUpdates(0);
   CDS1->Active = false;
   Query1->Close();
   QueryAux->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfClientesHabituales::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------

