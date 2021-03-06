//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uSeleccionarComida.h"
#include "uAgregarComida.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame4"
#pragma resource "*.dfm"
TfSeleccionarComida *fSeleccionarComida;
//---------------------------------------------------------------------------
__fastcall TfSeleccionarComida::TfSeleccionarComida(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarComida::FormShow(TObject *Sender)
{
   idSeleccionado = 0;
   FormResize(fSeleccionarComida);
   Frame41->restablecerFrame();
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarComida::Frame41DBGrid1DblClick(TObject *Sender)
{
  Frame41->DBGrid1DblClick(fSeleccionarComida);
  idSeleccionado = Frame41->idSeleccionado;
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarComida::FormClose(TObject *Sender, TCloseAction &Action)

{
   Frame41->cerrarFrame();
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarComida::FormResize(TObject *Sender)
{
   Frame41->Width = fSeleccionarComida->Width;
   Frame41->Height = fSeleccionarComida->Height;
   Frame41->DBGrid1->Width = fSeleccionarComida->Width - 10;
   Frame41->DBGrid1->Height = fSeleccionarComida->Height - 60;
}
//---------------------------------------------------------------------------
void __fastcall TfSeleccionarComida::Button1Click(TObject *Sender)
{
   fAgregarComida->ShowModal();
   if(Frame41->ClientDataSet1->Active)
      Frame41->ClientDataSet1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarComida::Frame41DBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
   if(Key == VK_RETURN)
   {
      Frame41->DBGrid1DblClick(fSeleccionarComida);
	  idSeleccionado = Frame41->idSeleccionado;
	  Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfSeleccionarComida::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_ESCAPE)
   {
      Close();
   }
}
//---------------------------------------------------------------------------

