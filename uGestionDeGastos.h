//---------------------------------------------------------------------------

#ifndef uGestionDeGastosH
#define uGestionDeGastosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DBXMySQL.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfGestionDeGastos : public TForm
{
__published:	// IDE-managed Components
	TMonthCalendar *MC;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid2;
	TSQLConnection *SQLConnection1;
	TWideStringField *CDS1item;
	TFMTBCDField *CDS1cantidad;
	TEdit *Edit1;
	TIntegerField *CDS1idGasto;
	TEdit *Edit2;
	TSQLQuery *Query2;
	TDataSetProvider *DataSetProvider2;
	TClientDataSet *CDS2;
	TDataSource *DataSource2;
	TDBGrid *DBGrid1;
	TWideStringField *CDS2descripcion;
	TEdit *Edit3;
	TButton *Button1;
	TLabel *Label1;
	TSQLQuery *QueryUpdate;
	TEdit *Edit4;
	TIntegerField *CDS2idItemGasto;
	TPopupMenu *PopupMenu1;
	TMenuItem *Eliminarestetem1;
	TWideStringField *CDS1comentario;
	TFMTBCDField *CDS1total;
	TButton *Button2;
	TPanel *Panel1;
	TEdit *Edit5;
	TLabel *Label2;
	TComboBox *ComboBox1;
	TLabel *Label3;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TSQLQuery *QueryAux;
	TLabel *Label4;
	TShape *Shape1;
	TPanel *Panel2;
	TButton *Button6;
	TButton *Button7;
	TEdit *Edit6;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Eliminarestetem1Click(TObject *Sender);
	void __fastcall Edit2Enter(TObject *Sender);
	void __fastcall Edit2Exit(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Edit2Click(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
	void __fastcall MCClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfGestionDeGastos(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TfGestionDeGastos *fGestionDeGastos;
//---------------------------------------------------------------------------
#endif
