//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAgregarCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame1"
#pragma resource "*.dfm"
TfAgregarCliente *fAgregarCliente;
//---------------------------------------------------------------------------
__fastcall TfAgregarCliente::TfAgregarCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::FormShow(TObject *Sender)
{
   Frame11->llamador = 1;
   Frame11->restablecerFrame();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::FormClose(TObject *Sender, TCloseAction &Action)
{
   if((Frame11->DBEdCalle->Text == "") || Application->MessageBox(L"Realmente desea descartar los cambios no guardados y salir?",
   																  L"Salir?", MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  Frame11->cancelar();
	  Frame11->cerrarFrame();
   }
   else
      Action = caNone;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Button1Click(TObject *Sender)
{
   if(Frame11->guardar())
   {
      Frame11->cerrarFrame();
	  Frame11->llamador = 1;
	  Frame11->restablecerFrame();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Button2Click(TObject *Sender)
{
   if(Application->MessageBox(L"Se van a descartar los cambios realizados. Desea continuar?",L"Cancelar cambios?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  Frame11->cancelar();
	  Frame11->restablecerFrame();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarCliente::Button3Click(TObject *Sender)
{
	  Close();
}
//---------------------------------------------------------------------------

