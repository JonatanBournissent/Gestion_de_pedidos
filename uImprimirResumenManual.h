//---------------------------------------------------------------------------

#ifndef uImprimirResumenManualH
#define uImprimirResumenManualH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "frxClass.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include "frxExportPDF.hpp"
#include "frxExportBaseDialog.hpp"
//---------------------------------------------------------------------------
class TfImprimirResumenManual : public TForm
{
__published:	// IDE-managed Components
	TButton *Button10;
	TfrxReport *frxReport1;
	TMonthCalendar *MC;
	TCheckBox *chbTicket;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TfrxReport *frxReport2;
	TButton *Button1;
	TfrxPDFExport *frxPDFExport1;
	TLabel *Label1;
	TShape *Shape1;
	TShape *Shape2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label2;
	TLabel *lbTotal;
	TLabel *Label6;
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
	TEdit *Edit2;
	TEdit *Edit1;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit21;
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall Edit8Change(TObject *Sender);
	void __fastcall Edit11Change(TObject *Sender);
	void __fastcall Edit14Change(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
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
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall Edit9Change(TObject *Sender);
	void __fastcall Edit12Change(TObject *Sender);
	void __fastcall Edit15Change(TObject *Sender);
	void __fastcall Edit17Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfImprimirResumenManual(TComponent* Owner);

	bool CanPrint;
	int idCliente;
	float valorUnidad;
	float calcular(void);
	void mostrarCliente(int refCliente);
};
//---------------------------------------------------------------------------
extern PACKAGE TfImprimirResumenManual *fImprimirResumenManual;
//---------------------------------------------------------------------------
#endif
