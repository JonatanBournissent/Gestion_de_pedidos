//---------------------------------------------------------------------------

#ifndef uComidasExcluidasH
#define uComidasExcluidasH
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
//---------------------------------------------------------------------------
class TfComidasExcluidas : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TSQLConnection *SQLConnection1;
	TDBGrid *DBGrid1;
	TWideStringField *CDS1nombre;
	TWideStringField *CDS1codigo;
	TWideStringField *CDS1categoria;
	TIntegerField *CDS1refComida;
	TButton *Button1;
	TButton *Button2;
	TSQLQuery *QueryAux;
	TPopupMenu *PopupMenu1;
	TMenuItem *N1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall N1Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfComidasExcluidas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfComidasExcluidas *fComidasExcluidas;
//---------------------------------------------------------------------------
#endif
