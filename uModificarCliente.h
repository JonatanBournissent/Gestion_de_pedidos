//---------------------------------------------------------------------------

#ifndef uModificarClienteH
#define uModificarClienteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uFrame1.h"
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "uFrame2.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfModificarCliente : public TForm
{
__published:	// IDE-managed Components
	TFrame1 *Frame11;
	TFrame2 *Frame21;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TShape *Shape1;
	TShape *Shape2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Frame21DBGrid1DblClick(TObject *Sender);
	void __fastcall Frame21Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfModificarCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfModificarCliente *fModificarCliente;
//---------------------------------------------------------------------------
#endif
