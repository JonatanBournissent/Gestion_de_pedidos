//---------------------------------------------------------------------------

#ifndef uRepartidoresH
#define uRepartidoresH
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
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfRepartidores : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDataSource *DataSource1;
	TClientDataSet *CDS;
	TDataSetProvider *DataSetProvider1;
	TSQLQuery *Query1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryUpdate;
	TIntegerField *CDSidRepartidor;
	TWideStringField *CDSdescripcion;
	TWideStringField *CDSnombreCorto;
	TSQLTimeStampField *CDShorario1;
	TSQLTimeStampField *CDShorario2;
	TButton *Button1;
	TPanel *Panel1;
	TButton *Button2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button3;
	TButton *Button4;
	TDBCheckBox *CB;
	TByteField *CDSreparteSabados;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall CDSdescripcionChange(TField *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall CDSnombreCortoChange(TField *Sender);
	void __fastcall CDShorario1Change(TField *Sender);
	void __fastcall CDShorario2Change(TField *Sender);
	void __fastcall CDSNewRecord(TDataSet *DataSet);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall DBGrid1ColExit(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall CDSreparteSabadosChange(TField *Sender);
	void __fastcall CBClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfRepartidores(TComponent* Owner);


	TRect *DrawRect;
};
//---------------------------------------------------------------------------
extern PACKAGE TfRepartidores *fRepartidores;
//---------------------------------------------------------------------------
#endif
