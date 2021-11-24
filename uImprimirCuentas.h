//---------------------------------------------------------------------------

#ifndef uImprimirCuentasH
#define uImprimirCuentasH
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxExportPDF.hpp"
#include "frxExportBaseDialog.hpp"
//---------------------------------------------------------------------------
class TfImprimirCuentas : public TForm
{
__published:	// IDE-managed Components
	TDataSource *DataSource1;
	TClientDataSet *CDS;
	TDataSetProvider *DataSetProvider1;
	TSQLQuery *Query1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryAux;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TMonthCalendar *MC;
	TRadioGroup *RG1;
	TIntegerField *CDSidCliente;
	TWideStringField *CDScalle;
	TWideStringField *CDSnumero;
	TFMTBCDField *CDSunidadesPeriodo;
	TFMTBCDField *CDSdeudaTotal;
	TDBCheckBox *CB;
	TButton *Button4;
	TFMTBCDField *CDSsubtotal;
	TFMTBCDField *CDSsaldoAnterior;
	TfrxReport *frxReport1;
	TWideStringField *CDSnombre;
	TWideStringField *CDSapellido;
	TFMTBCDField *CDSprecio;
	TButton *Button5;
	TLargeintField *CDSimprimir;
	TButton *Button6;
	TFMTBCDField *CDSagregado;
	TButton *Button7;
	TRadioGroup *RG2;
	TButton *Button8;
	TButton *Button9;
	TfrxDBDataset *frxDBDataset2;
	TSQLQuery *Query2;
	TDataSetProvider *DataSetProvider2;
	TClientDataSet *CDS2;
	TDataSource *DataSource2;
	TfrxReport *frxReport2;
	TFMTBCDField *CDS2valorUnidad;
	TfrxDBDataset *frxDBDataset3;
	TSQLQuery *Query3;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *CDS3;
	TDataSource *DataSource3;
	TWideStringField *CDS3cliente;
	TWideStringField *CDS3domicilio;
	TWideStringField *CDS2detalle;
	TFloatField *CDS2subtotal;
	TFloatField *CDS3total;
	TDateField *CDS3dfechaDetalle;
	TDateField *CDS3mfechaDetalle;
	TDateField *CDS3yfechaDetalle;
	TfrxReport *frxReport3;
	TDateField *CDS3fechaDetalleMensual;
	TFloatField *CDS2unidades;
	TButton *Button2;
	TCheckBox *chbTicket;
	TfrxReport *frxReport5;
	TfrxReport *frxReport4;
	TfrxPDFExport *frxPDFExport1;
	TLargeintField *CDSrep;
	TCheckBox *CheckBox1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid1ColExit(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall RG1Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall MCClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DBGrid1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall chbTicketClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfImprimirCuentas(TComponent* Owner);

	TRect *DrawRect;
	bool CanPrint;
	bool usarSaldos;

	bool usarClienteIndicado;
	int refClienteIndicado;
};
//---------------------------------------------------------------------------
extern PACKAGE TfImprimirCuentas *fImprimirCuentas;
//---------------------------------------------------------------------------
#endif
