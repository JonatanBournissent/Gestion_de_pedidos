//---------------------------------------------------------------------------

#ifndef uClientesHabitualesH
#define uClientesHabitualesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfClientesHabituales : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TWideStringField *CDS1cliente;
	TDataSource *DataSource1;
	TSQLQuery *QueryAux;
	TPopupMenu *PopupMenu1;
	TMenuItem *Agregaruncliente1;
	TMenuItem *Quitaresteclientedelalista1;
	TButton *Button1;
	TIntegerField *CDS1refCliente;
	TIntegerField *CDS1idClienteHabitual;
	TDBCheckBox *CB1;
	TIntegerField *CDS1Lunes;
	TIntegerField *CDS1Martes;
	TIntegerField *CDS1Miercoles;
	TIntegerField *CDS1Jueves;
	TIntegerField *CDS1Viernes;
	TIntegerField *CDS1Sabado;
	TDBCheckBox *CB2;
	TDBCheckBox *CB3;
	TDBCheckBox *CB4;
	TDBCheckBox *CB5;
	TDBCheckBox *CB6;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Agregaruncliente1Click(TObject *Sender);
	void __fastcall Quitaresteclientedelalista1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1ColExit(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall CDS1LunesChange(TField *Sender);
	void __fastcall CDS1MartesChange(TField *Sender);
	void __fastcall CDS1MiercolesChange(TField *Sender);
	void __fastcall CDS1JuevesChange(TField *Sender);
	void __fastcall CDS1ViernesChange(TField *Sender);
	void __fastcall CDS1SabadoChange(TField *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfClientesHabituales(TComponent* Owner);


	TRect *DrawRect;
};
//---------------------------------------------------------------------------
extern PACKAGE TfClientesHabituales *fClientesHabituales;
//---------------------------------------------------------------------------
#endif
