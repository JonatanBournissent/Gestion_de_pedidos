//---------------------------------------------------------------------------

#ifndef uFormulaComidasH
#define uFormulaComidasH
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
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfFormulaComidas : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TSQLQuery *QueryAux;
	TWideStringField *CDS1ingrediente;
	TIntegerField *CDS1idFormulaComida;
	TIntegerField *CDS1refIngrediente;
	TPopupMenu *PopupMenu1;
	TMenuItem *Agregaringrediente1;
	TMenuItem *Eliminaresteingrediente1;
	TPanel *Panel1;
	TComboBox *ComboBox1;
	TEdit *Edit1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;
	TFMTBCDField *CDS1cantidadCada100g;
	TShape *Shape1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Agregaringrediente1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Eliminaresteingrediente1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfFormulaComidas(TComponent* Owner);
	int idComida;
};
//---------------------------------------------------------------------------
extern PACKAGE TfFormulaComidas *fFormulaComidas;
//---------------------------------------------------------------------------
#endif
