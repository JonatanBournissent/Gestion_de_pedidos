//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uModificarCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame1"
#pragma link "uFrame2"
#pragma resource "*.dfm"
TfModificarCliente *fModificarCliente;
//---------------------------------------------------------------------------
__fastcall TfModificarCliente::TfModificarCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfModificarCliente::FormShow(TObject *Sender)
{
   Frame11->Enabled = false;
   Frame21->llamador = 1;
   Frame21->Enabled = true;
   Frame21->restablecerFrame();

   Button1->Enabled = false;
   Button2->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfModificarCliente::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(!Frame11->Enabled || Frame11->DBEdCalle->Text == "" || Application->MessageBox(L"Se van a descartar los cambios realizados. Desea continuar?",L"Cancelar cambios?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  Frame11->cancelar();
	  Frame21->cerrarFrame();
	  Frame11->cerrarFrame();
   }
   else
      Action = caNone;
}
//---------------------------------------------------------------------------

void __fastcall TfModificarCliente::Frame21DBGrid1DblClick(TObject *Sender)
{
   Frame21->DBGrid1DblClick(fModificarCliente);
   if(Frame21->idSeleccionado > 2)
   {
	  Frame11->id = Frame21->idSeleccionado;
	  Frame21->Enabled = false;
	  Frame11->llamador = 2;
	  Frame11->Enabled = true;
	  Frame11->restablecerFrame();

	  Button1->Enabled = true;
	  Button2->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfModificarCliente::Frame21Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
   if(Key == VK_RETURN)
   {
      if(Frame21->ClientDataSet1->RecordCount != 1)
		return;

	  Frame21DBGrid1DblClick(Frame21);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfModificarCliente::Button1Click(TObject *Sender)
{
   if(Frame11->guardar())
   {
	  Frame11->cerrarFrame();
	  Frame11->Enabled = false;
	  Frame21->Enabled = true;
	  Frame21->restablecerFrame();
	  Button1->Enabled = false;
	  Button2->Enabled = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfModificarCliente::Button2Click(TObject *Sender)
{
   if(Application->MessageBox(L"Realmente desea cancelar todos los cambios?",L"Cancelar cambios?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  Frame11->cerrarFrame();
	  Frame11->Enabled = false;
	  Frame21->Enabled = true;
	  Frame21->restablecerFrame();
	  Button1->Enabled = false;
	  Button2->Enabled = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfModificarCliente::Button3Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------



