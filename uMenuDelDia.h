//---------------------------------------------------------------------------

#ifndef uMenuDelDiaH
#define uMenuDelDiaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfMenuDelDia : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *ClientDataSet1;
	TDataSource *DataSource1;
	TSQLTable *SQLTable1;
	TDataSetProvider *DataSetProvider2;
	TClientDataSet *ClientDataSet2;
	TDataSource *DataSource2;
	TDBLookupComboBox *Comida1;
	TDBLookupComboBox *Comida2;
	TDBLookupComboBox *Comida3;
	TDBLookupComboBox *Comida4;
	TDBLookupComboBox *Comida5;
	TDBLookupComboBox *Comida6;
	TDBLookupComboBox *Comida7;
	TDBLookupComboBox *Comida8;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TSQLQuery *QueryAux;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TLabel *Label1;
	TLabel *Label2;
	TBevel *Bevel3;
	TIntegerField *ClientDataSet1refComida1;
	TIntegerField *ClientDataSet1refComida2;
	TIntegerField *ClientDataSet1refComida3;
	TIntegerField *ClientDataSet1refComida4;
	TIntegerField *ClientDataSet1refComida5;
	TIntegerField *ClientDataSet1refComida6;
	TIntegerField *ClientDataSet1refComida7;
	TIntegerField *ClientDataSet1refComida8;
	TIntegerField *ClientDataSet1idMenuDelDia;
	TPanel *Panel1;
	TListBox *ListBox1;
	TLabel *Label3;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Comida1Click(TObject *Sender);
	void __fastcall Comida2Click(TObject *Sender);
	void __fastcall Comida3Click(TObject *Sender);
	void __fastcall Comida4Click(TObject *Sender);
	void __fastcall Comida5Click(TObject *Sender);
	void __fastcall Comida6Click(TObject *Sender);
	void __fastcall Comida7Click(TObject *Sender);
	void __fastcall Comida8Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfMenuDelDia(TComponent* Owner);

	TDate fecha;
	int id;
	int arrid[8];
	bool revisarAntecedentes(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMenuDelDia *fMenuDelDia;
//---------------------------------------------------------------------------
#endif
