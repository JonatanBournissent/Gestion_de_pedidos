//---------------------------------------------------------------------------

#ifndef uEmitirComprobanteElectronicoH
#define uEmitirComprobanteElectronicoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include "frxExportPDF.hpp"
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ComCtrls.hpp>
#include "frxBarcode.hpp"
#include "frxBarcode2D.hpp"
#include "frxDBSet.hpp"
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include "frxExportBaseDialog.hpp"
//---------------------------------------------------------------------------
class TfEmitirComprobanteElectronico : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TEdit *Edit17;
	TButton *Button10;
	TMonthCalendar *MC;
	TCheckBox *chbFactA4;
	TEdit *Edit2;
	TButton *Button1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TfrxReport *frxReport2;
	TfrxPDFExport *frxPDFExport1;
	TfrxReport *frxReport3;
	TfrxDBDataset *frxDBDataset3;
	TSQLQuery *Query3;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *CDS3;
	TWideStringField *CDS3domicilio;
	TWideStringField *CDS3razonSocial;
	TWideStringField *CDS3condFrenteIVA;
	TWideStringField *CDS3cuit;
	TDataSource *DataSource3;
	TSQLQuery *QueryAux;
	TfrxReport *frxReport1;
	TLabel *lbSubtotal;
	TLabel *lbIVA21;
	TLabel *lbTotal;
	TEdit *Edit1;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit21;
	TLabel *Label6;
	TShape *Shape1;
	TShape *Shape2;
	TCheckBox *CheckBox1;
	TSaveDialog *SD1;
	TButton *Button2;
	TShape *Shape3;
	TfrxBarCodeObject *frxBarCodeObject1;
	TButton *Button3;
	TEdit *Edit22;
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit9KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit12KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit15KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit5KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit8KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit11KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit14KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit17KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall Edit8Change(TObject *Sender);
	void __fastcall Edit11Change(TObject *Sender);
	void __fastcall Edit14Change(TObject *Sender);
	void __fastcall chbFactA4Click(TObject *Sender);
	void __fastcall Edit3Exit(TObject *Sender);
	void __fastcall Edit6Exit(TObject *Sender);
	void __fastcall Edit9Exit(TObject *Sender);
	void __fastcall Edit12Exit(TObject *Sender);
	void __fastcall Edit15Exit(TObject *Sender);
	void __fastcall Edit5Exit(TObject *Sender);
	void __fastcall Edit8Exit(TObject *Sender);
	void __fastcall Edit11Exit(TObject *Sender);
	void __fastcall Edit14Exit(TObject *Sender);
	void __fastcall Edit17Exit(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall Edit9Change(TObject *Sender);
	void __fastcall Edit12Change(TObject *Sender);
	void __fastcall Edit15Change(TObject *Sender);
	void __fastcall Edit17Change(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button3Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfEmitirComprobanteElectronico(TComponent* Owner);

	int refCondicionFrenteIVA;
	bool CanPrint;
	int idCliente;
	float valorUnidad;
	float calcular(void);
	void mostrarCliente(int refCliente);
};
//---------------------------------------------------------------------------
extern PACKAGE TfEmitirComprobanteElectronico *fEmitirComprobanteElectronico;
//---------------------------------------------------------------------------
#endif
