//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAgregarComida.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame3"
#pragma resource "*.dfm"
TfAgregarComida *fAgregarComida;
//---------------------------------------------------------------------------
__fastcall TfAgregarComida::TfAgregarComida(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAgregarComida::FormShow(TObject *Sender)
{
   Frame31->llamador = 1;
   Frame31->restablecerFrame();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarComida::FormClose(TObject *Sender, TCloseAction &Action)

{
   if((Frame31->DBEdNombre->Text == "") || Application->MessageBox(L"Realmente desea descartar los cambios no guardados y salir?",
   																   L"Salir?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  Frame31->cancelar();
	  Frame31->cerrarFrame();
   }
   else
	  Action = caNone;
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarComida::Button1Click(TObject *Sender)
{
   if(Frame31->guardar())
   {
	  Frame31->cerrarFrame();
	  Frame31->llamador = 1;
	  Frame31->restablecerFrame();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarComida::Button2Click(TObject *Sender)
{
   if(Application->MessageBox(L"Realmente desea descartar los camios sin guardar?" ,
   							  L"Descartar cambios",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  return;

   Frame31->cancelar();
   Frame31->restablecerFrame();
}
//---------------------------------------------------------------------------

void __fastcall TfAgregarComida::Button3Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

