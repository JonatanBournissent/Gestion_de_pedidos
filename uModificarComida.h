//---------------------------------------------------------------------------

#ifndef uModificarComidaH
#define uModificarComidaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uFrame4.h"
#include "uFrame3.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfModificarComida : public TForm
{
__published:	// IDE-managed Components
	TFrame4 *Frame41;
	TFrame3 *Frame31;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TShape *Shape1;
	TShape *Shape2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Frame41DBGrid1DblClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Frame41Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfModificarComida(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfModificarComida *fModificarComida;
//---------------------------------------------------------------------------
#endif
