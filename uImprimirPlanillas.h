//---------------------------------------------------------------------------

#ifndef uImprimirPlanillasH
#define uImprimirPlanillasH
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
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfImprimirPlanillas : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS;
	TDataSource *DataSource1;
	TSQLQuery *QueryAux;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDataset1;
	TButton *Button1;
	TWideStringField *CDScalle;
	TWideStringField *CDSnumero;
	TComboBox *ComboBox1;
	TWideStringField *CDScomp;
	TIntegerField *CDSbandGrand;
	TFMTBCDField *CDSunid;
	TMonthCalendar *MC;
	TBevel *Bevel1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall MCClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfImprimirPlanillas(TComponent* Owner);

	int idRepartidor;
	bool CanPrint;

	int esSabado;

};
//---------------------------------------------------------------------------
extern PACKAGE TfImprimirPlanillas *fImprimirPlanillas;
//---------------------------------------------------------------------------
#endif
