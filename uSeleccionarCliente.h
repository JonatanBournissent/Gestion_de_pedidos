//---------------------------------------------------------------------------

#ifndef uSeleccionarClienteH
#define uSeleccionarClienteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uFrame2.h"
//---------------------------------------------------------------------------
class TfSeleccionarCliente : public TForm
{
__published:	// IDE-managed Components
	TFrame2 *Frame21;
	TButton *Button1;
	void __fastcall Frame21DBGrid1DblClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Frame21Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Frame21DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TfSeleccionarCliente(TComponent* Owner);

	int idSeleccionado;
	int llamador;
	bool precargar;
	String filtro;
};
//---------------------------------------------------------------------------
extern PACKAGE TfSeleccionarCliente *fSeleccionarCliente;
//---------------------------------------------------------------------------
#endif
