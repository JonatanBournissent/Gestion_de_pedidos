//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.NetEncoding.hpp>
#pragma hdrstop

#include "uEmitirComprobanteElectronico.h"
#include "uSeleccionarCliente.h"
#include "VariablesGlobales.h"
#include "FEAFIPLib_TLB.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxExportPDF"
#pragma link "frxBarcode"
#pragma link "frxBarcode2D"
#pragma link "frxDBSet"
#pragma link "frxExportBaseDialog"
#pragma resource "*.dfm"
TfEmitirComprobanteElectronico *fEmitirComprobanteElectronico;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfEmitirComprobanteElectronico::TfEmitirComprobanteElectronico(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TfEmitirComprobanteElectronico::mostrarCliente(int refCliente)
{
   idCliente = refCliente;

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT razonSocial AS cliente, acumuladoGlobal AS deuda, refListaPrecio, refCondicionFrenteIVA, "
					"(SELECT valor FROM listasPrecio WHERE clientes.refListaPrecio = listasPrecio.idListaPrecio LIMIT 1) AS valorUnidad "
					" FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   Query1->ParamByName("idCliente")->AsInteger = refCliente;
   Query1->Open();
   Edit2->Text = Query1->FieldByName("cliente")->AsString;
   if(Edit2->Text.Length() < 2) //Uno o menos caracteres... quizas un espacio o un guion o nada.
	  Edit2->Text = "Consumidor Final";
   refCondicionFrenteIVA = Query1->FieldByName("refCondicionFrenteIVA")->AsInteger;

   Label1->Caption = "";

   if(Query1->FieldByName("deuda")->AsFloat > 0.0)
   {
	  Label1->Caption = "Atenci?n! Este cliente presenta una deuda a la fecha: " + FormatDateTime("dd/mm/yyy", Now()) + " de " + FormatFloat("$ 0.00", Query1->FieldByName("deuda")->AsFloat);
	  Label1->Font->Color = clRed;
   }
   else if(Query1->FieldByName("deuda")->AsFloat < 0.0)
   {
	  Label1->Caption = "Atenci?n! Este cliente presenta un saldo a favor a la fecha: " + FormatDateTime("dd/mm/yyy", Now()) + " de " + FormatFloat("$ 0.00", -1.0 * Query1->FieldByName("deuda")->AsFloat);
      Label1->Font->Color = clBlue;
   }

   valorUnidad = Query1->FieldByName("valorUnidad")->AsFloat;

   CDS3->Active = false;
   Query1->Close();

   String q;

	  q = "SELECT idCliente, razonSocial, domicilioFiscal AS domicilio, REPLACE(cuit,'-','') AS cuit, "
		  "(SELECT descripcion FROM condicionesFrenteIVA WHERE condicionesFrenteIVA.idCondicionFrenteIVA = clientes.refCondicionFrenteIVA LIMIT 1) AS condFrenteIVA "
		  "FROM clientes WHERE idCliente = :refCliente LIMIT 1";

   Query3->Close();
   Query3->SQL->Clear();
   Query3->SQL->Add(q);
   Query3->ParamByName("refCliente")->AsInteger = refCliente;

   Query3->Open();
   CDS3->Active = true;

   if(refCondicionFrenteIVA == 2)
   {
	  lbTotal->Top = 550;
	  lbIVA21->Visible = true;
   }
   else
   {
	  lbTotal->Top = 510;
	  lbIVA21->Visible = false;
   }
   calcular();
   Button10->Enabled = true;
   Edit3->SetFocus();
}
//---------------------------------------------------------------------------

float TfEmitirComprobanteElectronico::calcular(void)
{
   float tot = StrToFloat(Edit1->Text.Delete(1,2)) +
				StrToFloat(Edit18->Text.Delete(1,2)) +
				StrToFloat(Edit19->Text.Delete(1,2)) +
				StrToFloat(Edit20->Text.Delete(1,2)) +
				StrToFloat(Edit21->Text.Delete(1,2));
   float subt = tot / 1.21;
   float totalIva21 = subt * 0.21;

   if(refCondicionFrenteIVA != 2)
	  lbSubtotal->Caption = FormatFloat("Subtotal: $ 0.00", tot);
   else
	  lbSubtotal->Caption = FormatFloat("Subtotal: $ 0.00", subt);

   lbIVA21->Caption = FormatFloat("IVA 21%: $ 0.00", totalIva21);
   lbTotal->Caption = FormatFloat("TOTAL: $ 0.00", tot);
   return tot;
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Button10Click(TObject *Sender)
{
   if(!CDS3->Active)
	  return;

   if(calcular() < 0.0)
   {
	  Application->MessageBox(L"No es posible generar un comprobante electr?nico con valor negativo." ,L"Error.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }
   else if(calcular() == 0.0)
   {
	  if(Application->MessageBox(L"Esta por generar un comprobante por un valor de $ 0,00. Realmente desea continuar?" ,L"ATENCI?N!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  {
		 return;
	  }
   }

   Button10->Enabled = false;

   CanPrint = false;
   String imp_actual;
   String DirFacturas;

   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   if(CheckBox1->Checked)
      imp_actual = Configuraciones->ReadString("Impresion","ImpresoraPDF","NO_CONFIGURADA");
   else if(chbFactA4->Checked)
	  imp_actual = Configuraciones->ReadString("Impresion","ImpresoraPlanillas","NO_CONFIGURADA");
   else
	  imp_actual = Configuraciones->ReadString("Impresion","ImpresoraPresupuestos","NO_CONFIGURADA");

   DirFacturas = Configuraciones->ReadString("Directorios","Facturas","NO_CONFIGURADA");

   if(DirFacturas == "NO_CONFIGURADA")
   {
	   delete Configuraciones;
	   Application->MessageBox(L"Antes de continuar debe configurar un directorio para guardar las copias de respaldo" ,L"Configurar directorio.",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
       CDS3->Active = false;
	   Query3->Close();
	   return;
   }

   if(imp_actual != "NO_CONFIGURADA")
   {
	  CanPrint = true;

	  int imp_index;

	  if(CanPrint)
	  {
		 TPrinter *printer;
		 printer = new TPrinter;
		 for(imp_index=0; imp_index<printer->Printers->Count; imp_index++)
		 {
			if(printer->Printers->Strings[imp_index] == imp_actual)
			   break;
		 }
		 if(imp_index < printer->Printers->Count)
			CanPrint = true;
		 else
		 {
			CanPrint = false;
			if(CheckBox1->Checked)
			   Configuraciones->WriteString("Impresion","ImpresoraPDF","NO CONFIGURADA");
			else if(chbFactA4->Checked)
			   Configuraciones->WriteString("Impresion","ImpresoraPlanillas","NO CONFIGURADA");
			else
			   Configuraciones->WriteString("Impresion","ImpresoraPresupuestos","NO CONFIGURADA");
		 }
	  }
	  delete Configuraciones;

	  if(CanPrint)
	  {
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("fechaComp"))->Text = FormatDateTime("dd/mm/yyy", MC->Date);
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("fechaComp"))->Text = FormatDateTime("dd/mm/yyy", MC->Date);
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("fechaComp"))->Text = FormatDateTime("dd/mm/yyy", MC->Date);


		 float total = 0.0;

		 if(Edit3->Enabled && Edit3->Text != "" && Edit3->Text != "0")
		 {
			total = total + (StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades1"))->Text = FormatFloat("0.00", StrToFloat(Edit3->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio1"))->Text = Edit4->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades1"))->Text = FormatFloat("0.00", StrToFloat(Edit3->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio1"))->Text = Edit4->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades1"))->Text = FormatFloat("0.00", StrToFloat(Edit3->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio1"))->Text = Edit4->Text;

			if(refCondicionFrenteIVA == 2)
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text) / 1.21);

			}
			else
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit5->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal1"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));
			}
		 }
		 else
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal1"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal1"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio1"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal1"))->Text = "";

			return;
		 }
		 if(Edit6->Enabled && Edit6->Text != "" && Edit6->Text != "0")
		 {
			total = total + (StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades2"))->Text = FormatFloat("0.00", StrToFloat(Edit6->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio2"))->Text = Edit7->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades2"))->Text = FormatFloat("0.00", StrToFloat(Edit6->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio2"))->Text = Edit7->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades2"))->Text = FormatFloat("0.00", StrToFloat(Edit6->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio2"))->Text = Edit7->Text;

			if(refCondicionFrenteIVA == 2)
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text) / 1.21);
			}
			else
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit8->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal2"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));
			}
		 }
		 else
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal2"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal2"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio2"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal2"))->Text = "";
		 }
		 if(Edit9->Enabled && Edit9->Text != "" && Edit9->Text != "0")
		 {
			total = total + (StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades3"))->Text = FormatFloat("0.00", StrToFloat(Edit9->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio3"))->Text = Edit10->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades3"))->Text = FormatFloat("0.00", StrToFloat(Edit9->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio3"))->Text = Edit10->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades3"))->Text = FormatFloat("0.00", StrToFloat(Edit9->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio3"))->Text = Edit10->Text;

			if(refCondicionFrenteIVA == 2)
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text) / 1.21);
			}
			else
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit11->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal3"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));
			}
		 }
		 else
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal3"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal3"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio3"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal3"))->Text = "";
		 }
		 if(Edit12->Enabled && Edit12->Text != "" && Edit12->Text != "0")
		 {
			total = total + (StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades4"))->Text = FormatFloat("0.00", StrToFloat(Edit12->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio4"))->Text = Edit13->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades4"))->Text = FormatFloat("0.00", StrToFloat(Edit12->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio4"))->Text = Edit13->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades4"))->Text = FormatFloat("0.00", StrToFloat(Edit12->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio4"))->Text = Edit13->Text;

			if(refCondicionFrenteIVA == 2)
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text) / 1.21);
			}
			else
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit14->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal4"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));
			}
		 }
		 else
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal4"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal4"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio4"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal4"))->Text = "";
		 }
		 if(Edit15->Enabled && Edit15->Text != "" && Edit15->Text != "0")
		 {
			total = total + (StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades5"))->Text = FormatFloat("0.00", StrToFloat(Edit15->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio5"))->Text = Edit16->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades5"))->Text = FormatFloat("0.00", StrToFloat(Edit15->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio5"))->Text = Edit16->Text;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades5"))->Text = FormatFloat("0.00", StrToFloat(Edit15->Text));
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio5"))->Text = Edit16->Text;

			if(refCondicionFrenteIVA == 2)
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text) / 1.21);
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text) / 1.21);
			}
			else
			{
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit17->Text));
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal5"))->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));
			}
		 }
		 else
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mUnidades5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mDomicilio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mPrecio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal5"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mUnidades5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mDomicilio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mPrecio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal5"))->Text = "";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mUnidades5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mDomicilio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mPrecio5"))->Text = "";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal5"))->Text = "";
		 }


	   float subtotalSIVA = total / 1.21;
	   float totalIVA21 = total * 0.1735537190082645;


	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("SELECT montoMaximoFacturableSinDatos FROM registros WHERE idRegistro = 1 LIMIT 1");
	   QueryAux->Open();
	   float maximoFactSD = QueryAux->FieldByName("montoMaximoFacturableSinDatos")->AsFloat;
	   QueryAux->Close();

	   if(
			 (CDS3->FieldByName("cuit")->AsString == "00000000"
		  || CDS3->FieldByName("cuit")->AsString == "00000000000"
		  || CDS3->FieldByName("domicilio")->AsString == "-"
		  || CDS3->FieldByName("domicilio")->AsString == ""
		  || CDS3->FieldByName("razonSocial")->AsString == "-"
		  || CDS3->FieldByName("razonSocial")->AsString == "")
		  && (total > maximoFactSD)
		 )
	   {
		  String msg = "Error: para emitir facturas con monto mayor a: " + FormatFloat("$ 0.00", maximoFactSD);
		  msg = msg + " debe completar todos los datos del cliente\nCuit/DNI, Domicilio Fiscal y Raz?n Social o Nombre y Apellido";
		  Application->MessageBox(msg.w_str() ,L"ERROR!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
          CDS3->Active = false;
	  	  Query3->Close();
		  return;
	   }


	   if(
		  (refCondicionFrenteIVA == 2) &&
			 (CDS3->FieldByName("cuit")->AsString == "00000000"
		  || CDS3->FieldByName("cuit")->AsString == "00000000000"
		  || CDS3->FieldByName("domicilio")->AsString == "-"
		  || CDS3->FieldByName("domicilio")->AsString == ""
		  || CDS3->FieldByName("razonSocial")->AsString == "-"
		  || CDS3->FieldByName("razonSocial")->AsString == "")
		 )
	   {
		  String msg = "Error: para emitir facturas A debe completar todos los datos del cliente\nCuit, Domicilio Fiscal y Raz?n Social o Nombre y Apellido";
		  Application->MessageBox(msg.w_str() ,L"ERROR!",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
          CDS3->Active = false;
		  Query3->Close();
		  return;
	   }

		 bool conDNI, sinID;

		 conDNI = false;
		 sinID = false;

		 if(CDS3->FieldByName("cuit")->AsString == "00000000" || CDS3->FieldByName("cuit")->AsString == "00000000000")
			 sinID = true;
		 else if(CDS3->FieldByName("cuit")->AsString.Length() == 8)
			conDNI = true;



		 int selModelo = 0;

		 if(refCondicionFrenteIVA == 2 && chbFactA4->Checked)
			selModelo = 1; //factura A A4
		 else if(refCondicionFrenteIVA == 2 && !chbFactA4->Checked)
			selModelo = 2; //TIQUE A
		 else if(refCondicionFrenteIVA != 2 && chbFactA4->Checked && sinID)
			selModelo = 3; //factura B A4 sin datos de cliente
		 else if(refCondicionFrenteIVA != 2 && chbFactA4->Checked)
			selModelo = 4; //factura B A4
		 else if(refCondicionFrenteIVA != 2 && !chbFactA4->Checked && sinID)
			selModelo = 5; //TIQUE B sin datos de cliente
		 else
			selModelo = 6; //TIQUE B con datos de cliente


         String s;

		 if(selModelo == 1)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo18"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo19"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo21"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoComp"))->Text = "A";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("codigoComp"))->Text = "COD. 01";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoDocumento"))->Text = "FACTURA";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", subtotalSIVA);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Visible = true;
            dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "CUIT:";

			s = "FACTURA A - ";
		 }
		 else if(selModelo == 2)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("Memo19"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("tipoComp"))->Text = "FACTURA A. COD. 01";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", subtotalSIVA);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotalIVA21"))->Visible = true;

            if(conDNI)
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "DNI:";
			else
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "CUIT:";

			s = "FACTURA A - ";
		 }
		 else if(selModelo == 3)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo18"))->Visible = false;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo19"))->Visible = false;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo21"))->Visible = false;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoComp"))->Text = "B";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("codigoComp"))->Text = "COD. 06";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoDocumento"))->Text = "FACTURA";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", total);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Visible = false;

			if(conDNI)
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "DNI:";
			else
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "CUIT:";

			s = "FACTURA B - ";
		 }
		 else if(selModelo == 4)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo18"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo19"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo21"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoComp"))->Text = "B";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("codigoComp"))->Text = "COD. 06";
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("tipoDocumento"))->Text = "FACTURA";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", total);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("mTotalIVA21"))->Visible = false;

            if(conDNI)
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "DNI:";
			else
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "CUIT:";

			s = "FACTURA B - ";
		 }

		 else if(selModelo == 5)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("Memo19"))->Visible = false;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("tipoComp"))->Text = "FACTURA B. COD. 06";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", total);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("mTotalIVA21"))->Visible = false;

			s = "FACTURA B - ";
		 }
		 else if(selModelo == 6)
		 {
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("Memo19"))->Visible = true;
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("tipoComp"))->Text = "FACTURA B. COD. 06";

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mSubtotal"))->Text = FormatFloat("Subtotal: $ 0.00", total);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotalIVA21"))->Text = FormatFloat("IVA 21%: $ 0.00", totalIVA21);
			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotal"))->Text = FormatFloat("Total: $ 0.00", total);

			dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("mTotalIVA21"))->Visible = false;

            if(conDNI)
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "DNI:";
			else
			   dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo27"))->Text = "CUIT:";

			s = "FACTURA B - ";
		 }


//**************** CODIGOS SEGUN TABLA DE CODIGOS DE AFIP ************
//	001		FACTURA A                                                *
//	002		NOTA DE DEBITO A                                         *
//	003		NOTA DE CREDITO A                                        *
//                                                                   *
//	006		FACTURA B                                                *
//	007		NOTA DE DEBITO B                                         *
//	008		NOTA DE CREDIT B                                         *
//                                                                   *
//	011		FACTURA C                                                *
//	012		NOTA DE DEBITO C                                         *
//	013		NOTA DE CREDITO C                                        *
//                                                                   *
//**************** FIN CODIGOS SEGUN TABLA DE CODIGOS DE AFIP ********



//   URLs de autenticacion y negocio. Cambiarlas por las de producci?n al implementarlas en el cliente(abajo)
//   String URLWSAA = "https://wsaahomo.afip.gov.ar/ws/services/LoginCms"; //homologacion
//   String URLWSW = "https://wswhomo.afip.gov.ar/wsfev1/service.asmx";     //homologacion

   String URLWSAA = "https://wsaa.afip.gov.ar/ws/services/LoginCms";       //Produccion
   String URLWSW =  "https://servicios1.afip.gov.ar/wsfev1/service.asmx";   //Produccion

   WideString CAE = "";
   WideString Resultado = "";
   WideString Reproceso = "";
   WideString Vencimiento = "";
   WideString CUIT = "20149650939";     //CUIT EMISOR DE FACTURA
   double totalComp = StrToFloat(FormatFloat("0.00",total));
   double netoGravado = StrToFloat(FormatFloat("0.00",subtotalSIVA));
   double IVA21 = StrToFloat(FormatFloat("0.00",totalIVA21));

   bool error = false;

   double nro = 0;
   int PtoVta = 6;   //Punto de venta dado de alta en AFIP para Web Service

   int TipoComp;     //Codigo de Tipo de comprobante segun tabla de AFIP (resumen arriba)

   if(selModelo == 1)
	  TipoComp = 1;
   else if(selModelo == 2)
	  TipoComp = 1;
   else if(selModelo == 3)
	  TipoComp = 6;
   else if(selModelo == 4)
	  TipoComp = 6;
   else if(selModelo == 5)
	  TipoComp = 6;
   else if(selModelo == 6)
	  TipoComp = 6;
   else
   {
	  Application->MessageBox(L"Por algun motivo no se puede definir el tipo de comprobante.", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      CDS3->Active = false;
	  Query3->Close();
	  return;	//hay algun error
   }

   String FechaComp = FormatDateTime("yyyyMMdd", MC->Date);

   try
   {
	  StrToInt64(CDS3cuit->AsString);
   }
   catch(...)
   {
	  Application->MessageBox(L"Error al intentar converir el numero de CUIT del cliente a un valor entero", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      CDS3->Active = false;
	  Query3->Close();
	  return;
   }




   String tipoComp;

   if(TipoComp == 1)
	  tipoComp = "A";
   else if(TipoComp == 6)
	  tipoComp = "B";
   else
      return;

   String mensaje = "Se va a emitir una factura " + tipoComp + " a nombre de: \n\n";

   mensaje  = mensaje + "Fecha: " + FormatDateTime("dd/mm/yyyy", MC->Date);

   if(CDS3razonSocial->AsString == "")
	  mensaje  = mensaje + "\nRaz?n Social: NO ESPECIFICADA";
   else
	  mensaje  = mensaje + "\nRaz?n Social: " + CDS3razonSocial->AsString;

   if(conDNI)
	  mensaje  = mensaje + "\nDNI: " + CDS3cuit->AsString;
   else
	  mensaje  = mensaje + "\nCUIT: " + CDS3cuit->AsString;

   mensaje  = mensaje + "\nCondici?n frente al IVA: " + CDS3condFrenteIVA->AsString;
   mensaje = mensaje + "\nNeto Gravado: " + FormatFloat("$ 0.00", netoGravado);
   mensaje = mensaje + "\nIVA 21%: " + FormatFloat("$ 0.00", IVA21);
   mensaje = mensaje + "\nImporte TOTAL: " + FormatFloat("$ 0.00", totalComp);
   mensaje  = mensaje  + "\n\nRealmente desea continuar?";


   if(Application->MessageBox(L"Esta operaci?n no puede cancelarse. Desea continuar?" ,L"ATENCI?N!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  Button10->Enabled = true;
	  return;
   }

   if(Application->MessageBox(mensaje.w_str() ,L"ATENCI?N!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
   {
	  Button10->Enabled = true;
	  return;
   }


   bool comprobanteAutorizado = false;


   Twsfev1 *lwsfev1;
   lwsfev1 = new Twsfev1(Owner);
   lwsfev1->CUIT = StrToInt64(CUIT);
   lwsfev1->URL = URLWSW;

	if (lwsfev1->login("certificado.crt", "clave.key", URLWSAA))   //certificados y claves generados para el contribuyente emisor de la factura
	{
		if (lwsfev1->SFRecuperaLastCMP(PtoVta, TipoComp) == false)
		{
		   String msg = lwsfev1->ErrorDesc;
		   Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		   Application->MessageBox(L"Error al intentar recuperar desde AFIP el n?mero del ?ltimo comprobante emitido", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		   error = true;
		}
		else
		{
			nro = lwsfev1->SFLastCMP + 1;
			lwsfev1->Reset();

			if(sinID)
			   lwsfev1->AgregaFactura(1, 99, __int64(0)					   , nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);
			else if(conDNI)
			   lwsfev1->AgregaFactura(1, 96, StrToInt64(CDS3cuit->AsString), nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);
			else
			   lwsfev1->AgregaFactura(1, 80, StrToInt64(CDS3cuit->AsString), nro, nro, FechaComp, totalComp, 0, netoGravado, 0, "", "", "", "PES", 1);

			lwsfev1->AgregaIVA(5, netoGravado, IVA21); //ir a http://www.bitingenieria.com.ar/codigos.html

			if (lwsfev1->Autorizar(PtoVta, TipoComp))
			{
				lwsfev1->AutorizarRespuesta(0, CAE, Vencimiento, Resultado, Reproceso);
				if (Resultado == "A")
				{
					//ShowMessage("Felicitaciones! Si ve este mensaje instalo correctamente FEAFIP. CAE y Vencimiento :" + CAE + " " + Vencimiento);
					comprobanteAutorizado = true;
				}
				else
				{
					String msg = lwsfev1->AutorizarRespuestaObs(0);
					Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
					Application->MessageBox(L"Hubo un error al intentar autorizar el comprobante", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
					error = true;
				}
			}
			else
			{
				String msg = lwsfev1->ErrorDesc;
				Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
				error = true;
			}
		}
	}
	else
	{
		String msg = lwsfev1->ErrorDesc;
		Application->MessageBox(msg.w_str(), L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		Application->MessageBox(L"Arror al intentar conectarse al Web Service de AFIP con las credenciales disponibles", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		error = true;
	}


   if(error)
   {
	  delete lwsfev1;
	  CDS3->Active = false;
	  Query3->Close();
	  return;
   }







//ATENCION!!!!      SIMULACION***********************************************************

//   CAE = "71099320294706";
//   MC->Date = StrToDate("27/02/2021");
//   PtoVta = 3;
//   nro = 6;
//   CUIT = "23323762589";
//   TipoComp = 1;
//   total = 7872.03;
//   conDNI = false;
//   sinID = false;


//*********************************************************************




   String ptoDeVenta = IntToStr(PtoVta);
   while(ptoDeVenta.Length() < 5)
	  ptoDeVenta.Insert("0",1);

   String nroComp = IntToStr(__int64(nro));
   while(nroComp.Length() < 8)
	  nroComp.Insert("0",1);

   String tipoComprobante = IntToStr(TipoComp);

   while(tipoComprobante.Length() < 3)
	  tipoComprobante.Insert("0",1);

   String codigoBarra = CUIT + tipoComprobante + ptoDeVenta + CAE + Vencimiento; //cuit vendedor
   String fechaVencimiento = Vencimiento.SubString(7,2) + "/" + Vencimiento.SubString(5,2) + "/" + Vencimiento.SubString(1,4);







//ATENCION!!!! SIMULACION**************************************************
//   comprobanteAutorizado = true;      //para poder probar sin enviar a AFIP
//   fechaVencimiento = "01/01/2020";
//*************************************************************







   frxPDFExport1->FileName = DirFacturas + "\\" + s + ptoDeVenta + "-" + nroComp + ".pdf";

   if(comprobanteAutorizado)
   {
	 String importe = FormatFloat("0.00",total);
	 importe = importe.Delete(importe.Length() - 2, 1);
	 importe = importe.Insert(".", importe.Length() - 1);

	 if(importe.Pos(".00") > 0)
		importe = importe.SubString(1,importe.Pos(".00") - 1);

	 String json = "{\"ver\":1,\"fecha\":\"" + FormatDateTime("yyyy-mm-dd", MC->Date);
	 json = json + "\",\"cuit\":" + CUIT + ",\"ptoVta\":" + IntToStr(PtoVta);
	 json = json + ",\"tipoCmp\":" + IntToStr(TipoComp) + ",\"nroCmp\":" + IntToStr(__int64(nro));
	 json = json + ",\"importe\":";
	 json = json + importe;
	 json = json + ",\"moneda\":\"PES\",\"ctz\":1";

	 if(sinID)
		json = json + "";
	 else if(conDNI)
		json = json + ",\"tipoDocRec\":96";
	 else
		json = json + ",\"tipoDocRec\":80";

	 String nDoc = CDS3cuit->AsString;
//		 nDoc = "20295355442";

	 if(conDNI && nDoc.Length() > 0)
	 {
		while(nDoc.Pos("0") == 1)
		   nDoc = nDoc.Delete(1,1);
	 }

	 if(!sinID)
		json = json + ",\"nroDocRec\":" + nDoc;


	 json = json + ",\"tipoCodAut\":\"E\",\"codAut\":";
	 json = json + CAE + "}";

	 String encJSON = "https://www.afip.gob.ar/fe/qr/?p=" + TNetEncoding::Base64->Encode(json);

	 while(encJSON.Pos('\r'))
		encJSON = encJSON.Delete(encJSON.Pos('\r'), 1);
	 while(encJSON.Pos('\n'))
		encJSON = encJSON.Delete(encJSON.Pos('\n'), 1);



	  if(selModelo == 1 || selModelo == 3 || selModelo == 4)
	  {
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo33"))->Text = "ORIGINAL";
		 dynamic_cast <TfrxBarCodeView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("BarCode1"))->Text = codigoBarra;
		 dynamic_cast <TfrxBarcode2DView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Barcode2D1"))->Text = encJSON;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("caeComp"))->Text = "N? de CAE: " + CAE;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("nroComp"))->Text = ptoDeVenta + " - " + nroComp;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("vencComp"))->Text = "Vto. de CAE: " + fechaVencimiento;
		 frxReport3->PrintOptions->Printer = imp_actual;
		 frxReport3->PrepareReport(true);
//		 frxReport3->ShowReport(true);
		 frxReport3->Print();
         dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport3->FindObject("Memo33"))->Text = "DUPLICADO";
		 frxReport3->PrepareReport(true);

		 if(!frxReport3->Export(frxPDFExport1))
		 {
			Application->MessageBox(L"Especifique manualmente una ubicaci?n (y nombre de archivo) donde guardar una copia del comprobante.", L"ATENCI?N",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport1->FileName = SD1->FileName;
			frxReport3->Export(frxPDFExport1);
		 }

	  }
	  else if(selModelo == 2 || selModelo == 6)
	  {
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("caeComp"))->Text = "N? de CAE: " + CAE;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("nroComp"))->Text = ptoDeVenta + " - " + nroComp;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("vencComp"))->Text = "Vto. de CAE: " + fechaVencimiento;
		 dynamic_cast <TfrxBarcode2DView *> (fEmitirComprobanteElectronico->frxReport2->FindObject("Barcode2D1"))->Text = encJSON;
		 frxReport2->PrintOptions->Printer = imp_actual;
		 frxReport2->PrepareReport(true);
		 frxReport2->Print();
//		 frxReport2->ShowReport(true);

		 if(!frxReport2->Export(frxPDFExport1))
		 {
			Application->MessageBox(L"Especifique manualmente una ubicaci?n donde guardar una copia del comprobante.", L"ATENCI?N",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport1->FileName = SD1->FileName;
			frxReport2->Export(frxPDFExport1);
		 }

	  }
	  else
	  {
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("caeComp"))->Text = "N? de CAE: " + CAE;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("nroComp"))->Text = ptoDeVenta + " - " + nroComp;
		 dynamic_cast <TfrxMemoView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("vencComp"))->Text = "Vto. de CAE: " + fechaVencimiento;
		 dynamic_cast <TfrxBarcode2DView *> (fEmitirComprobanteElectronico->frxReport1->FindObject("Barcode2D1"))->Text = encJSON;
		 frxReport1->PrintOptions->Printer = imp_actual;
		 frxReport1->PrepareReport(true);
		 frxReport1->Print();
//		 frxReport1->ShowReport(true);

		 if(!frxReport1->Export(frxPDFExport1))
		 {
			Application->MessageBox(L"Especifique manualmente una ubicaci?n donde guardar una copia del comprobante.", L"ATENCI?N",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
			if(SD1->Execute())
			   frxPDFExport1->FileName = SD1->FileName;
			frxReport1->Export(frxPDFExport1);
		 }
	  }



		QueryAux->Close();
		QueryAux->SQL->Clear();
		String qy;

		qy = "INSERT INTO comprobanteselectronicos ("
			 "refCliente, cuitCliente, refCondicionFrenteIVA, fecha, refTipoComp, "
			 "ptoVenta, nroComprobante, netoGravado, iva21, total, CAE, vencimientoCAE) "
			 "VALUES ("
			 ":refCliente, :cuitCliente, :refCondicionFrenteIVA, :fecha, :refTipoComp, "
			 ":ptoVenta, :nroComprobante, :netoGravado, :iva21, :total, :CAE, :vencimientoCAE) ";


		QueryAux->SQL->Add(qy);
		QueryAux->ParamByName("refCliente")->AsInteger = idCliente;
		QueryAux->ParamByName("cuitCliente")->AsString = CDS3->FieldByName("cuit")->AsString;
		QueryAux->ParamByName("refCondicionFrenteIVA")->AsInteger = refCondicionFrenteIVA;
		QueryAux->ParamByName("fecha")->AsDate = MC->Date;
		QueryAux->ParamByName("refTipoComp")->AsInteger = TipoComp; //Segun tablas de AFIP
		QueryAux->ParamByName("ptoVenta")->AsInteger = PtoVta;
		QueryAux->ParamByName("nroComprobante")->AsInteger = StrToInt(nroComp);
		QueryAux->ParamByName("netoGravado")->AsFloat = netoGravado;
		QueryAux->ParamByName("iva21")->AsFloat = IVA21;
		QueryAux->ParamByName("total")->AsFloat = totalComp;
		QueryAux->ParamByName("CAE")->AsString = CAE;
		QueryAux->ParamByName("vencimientoCAE")->AsDate = StrToDate(fechaVencimiento);
		QueryAux->ExecSQL();

   }
   else
   {
	  Application->MessageBox(L"El comprobante no fue autorizado", L"ERROR",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  CDS3->Active = false;
	  Query3->Close();
   }

   delete lwsfev1;


	  }
	  else
	  {
		 String str;
		 str = "Se produjo un error al intentar localizar la impresora seleccionada.";
		 str = str + '\n';
		 str = str + "La reconfiguraracion de la impresora podria solucionar el problema.";

		 Application->MessageBox(str.w_str() ,L"Error", MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  }
   }
   else
   {
	  delete Configuraciones;
	  Application->MessageBox(L"Debe configurar una impresora antes de imprimir." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }

//   Query1->Close();
//   CDS3->Active = false;
//   Query3->Close();
//   QueryAux->Close();
   Button10->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::FormShow(TObject *Sender)
{
      Edit2->Enabled = false;
      Edit3->Enabled = false;
      Edit4->Enabled = false;
      Edit5->Enabled = false;
      Edit6->Enabled = false;
      Edit7->Enabled = false;
      Edit8->Enabled = false;
      Edit9->Enabled = false;
      Edit10->Enabled = false;
      Edit11->Enabled = false;
      Edit12->Enabled = false;
      Edit13->Enabled = false;
      Edit14->Enabled = false;
      Edit15->Enabled = false;
      Edit16->Enabled = false;
      Edit17->Enabled = false;
      Edit2->Text = "";
      Edit3->Text = "0";
      Edit4->Text = "Vianda(s)";
      Edit5->Text = "0";
      Edit6->Text = "0";
      Edit7->Text = "Vianda(s)";
      Edit8->Text = "0";
      Edit9->Text = "0";
      Edit10->Text = "Vianda(s)";
      Edit11->Text = "0";
      Edit12->Text = "0";
      Edit13->Text = "Vianda(s)";
      Edit14->Text = "0";
      Edit15->Text = "0";
      Edit16->Text = "Vianda(s)";
	  Edit17->Text = "0";

	  Label1->Caption = "";

	  Edit2->Enabled = true;
	  Edit3->Enabled = true;
	  Edit4->Enabled = true;
	  Edit5->Enabled = true;
	  Button10->Enabled = false;
	  Button1->SetFocus();

	  CheckBox1->Checked = false;
	  chbFactA4->Checked = false;

	  lbTotal->Top = 510;
	  lbIVA21->Visible = false;
	  refCondicionFrenteIVA = 0;

	  //Button10->Enabled = true;

	  MC->Date = Now();
}
//---------------------------------------------------------------------------


void __fastcall TfEmitirComprobanteElectronico::Button1Click(TObject *Sender)
{
   Query1->Close();
   CDS3->Active = false;
   Query3->Close();
   QueryAux->Close();
   Button10->Enabled = false;

   fSeleccionarCliente->llamador = 1;
   fSeleccionarCliente->ShowModal();

   if(fSeleccionarCliente->idSeleccionado < 2)
	  return;

   mostrarCliente(fSeleccionarCliente->idSeleccionado);
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit3KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit6KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit9KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit12KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit15KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit5KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit8KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit11KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit14KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit17KeyPress(TObject *Sender, System::WideChar &Key)

{
   if((Key < '0' || Key > '9') && Key != '\b' && Key != '.')
	  Key = NULL;
   if(Key == '.')
	  Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit5Change(TObject *Sender)
{
   if(Edit3->Text != "0" && Edit4->Text != "" && Edit5->Text != "0")
   {
      Edit6->Enabled = true;
      Edit7->Enabled = true;
      Edit8->Enabled = true;
   }
   if(Edit5->Text.Length() > 0)
	  Edit1->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));

   calcular();
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit8Change(TObject *Sender)
{
   if(Edit6->Text != "0" && Edit7->Text != "" && Edit8->Text != "0")
   {
      Edit9->Enabled = true;
      Edit10->Enabled = true;
      Edit11->Enabled = true;
   }

   if(Edit8->Text.Length() > 0)
	  Edit18->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));

   calcular();
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit11Change(TObject *Sender)
{
   if(Edit9->Text != "0" && Edit10->Text != "" && Edit11->Text != "0")
   {
      Edit12->Enabled = true;
      Edit13->Enabled = true;
      Edit14->Enabled = true;
   }

   if(Edit11->Text.Length() > 0)
	  Edit19->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));

   calcular();
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::Edit14Change(TObject *Sender)
{
   if(Edit12->Text != "0" && Edit13->Text != "" && Edit14->Text != "0")
   {
      Edit15->Enabled = true;
      Edit16->Enabled = true;
      Edit17->Enabled = true;
   }

   if(Edit14->Text.Length() > 0)
	  Edit20->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));

   calcular();
}
//---------------------------------------------------------------------------
void __fastcall TfEmitirComprobanteElectronico::chbFactA4Click(TObject *Sender)
{
   if(chbFactA4->Checked)
   {
	  Edit4->MaxLength = 40;
	  Edit7->MaxLength = 40;
	  Edit10->MaxLength = 40;
	  Edit13->MaxLength = 40;
	  Edit16->MaxLength = 40;
   }
   else
   {
	  bool largo = false;

	  if(Edit4->Text.Length() > 17)
		 largo = true;
	  else if(Edit7->Text.Length() > 17)
		 largo = true;
	  else if(Edit10->Text.Length() > 17)
		 largo = true;
	  else if(Edit13->Text.Length() > 17)
		 largo = true;
	  else if(Edit16->Text.Length() > 17)
		 largo = true;

	  Edit4->Text = Edit4->Text.SubString(1,17);
	  Edit7->Text = Edit7->Text.SubString(1,17);
	  Edit10->Text = Edit10->Text.SubString(1,17);
	  Edit13->Text = Edit13->Text.SubString(1,17);
	  Edit16->Text = Edit16->Text.SubString(1,17);

	  Edit4->MaxLength = 17;
	  Edit7->MaxLength = 17;
	  Edit10->MaxLength = 17;
	  Edit13->MaxLength = 17;
	  Edit16->MaxLength = 17;

	  if(largo)
	     Application->MessageBox(L"En formato tique, las descripciones pueden tener un m?ximo de 17 caracteres de longitud" ,L"Antenci?n",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit3Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
      dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit6Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit9Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit12Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit15Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit5Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit8Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit11Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit14Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit17Exit(TObject *Sender)
{
   if(dynamic_cast <TEdit *>(Sender)->Text == "")
	  dynamic_cast <TEdit *>(Sender)->Text = "0";
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit3Change(TObject *Sender)
{
   if(Edit3->Text.Length() > 0)
	  Edit1->Text = FormatFloat("$ 0.00", StrToFloat(Edit3->Text) * StrToFloat(Edit5->Text));

   calcular();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit6Change(TObject *Sender)
{
   if(Edit6->Text.Length() > 0)
	  Edit18->Text = FormatFloat("$ 0.00", StrToFloat(Edit6->Text) * StrToFloat(Edit8->Text));

   calcular();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit9Change(TObject *Sender)
{
   if(Edit9->Text.Length() > 0)
	  Edit19->Text = FormatFloat("$ 0.00", StrToFloat(Edit9->Text) * StrToFloat(Edit11->Text));

   calcular();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit12Change(TObject *Sender)
{
   if(Edit12->Text.Length() > 0)
	  Edit20->Text = FormatFloat("$ 0.00", StrToFloat(Edit12->Text) * StrToFloat(Edit14->Text));

   calcular();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit15Change(TObject *Sender)
{
   if(Edit15->Text.Length() > 0)
	  Edit21->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));

   calcular();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Edit17Change(TObject *Sender)
{
   if(Edit17->Text.Length() > 0)
	  Edit21->Text = FormatFloat("$ 0.00", StrToFloat(Edit15->Text) * StrToFloat(Edit17->Text));

   calcular();
}
//---------------------------------------------------------------------------


void __fastcall TfEmitirComprobanteElectronico::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
      chbFactA4->Checked = true;
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::Button2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfEmitirComprobanteElectronico::FormClose(TObject *Sender, TCloseAction &Action)

{
   Query1->Close();
   CDS3->Active = false;
   Query3->Close();
   QueryAux->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfEmitirComprobanteElectronico::Button3Click(TObject *Sender)
{
   Edit22->Text = TNetEncoding::Base64->Decode("eyJ2ZXIiOjEsImZlY2hhIjoiMjAyMS0wMy0xMCIsImN1aXQiOjIwMTQ5NjUwOTM5LCJwdG9WdGEiOjYsInRpcG9DbXAiOjEsIm5yb0NtcCI6MTgxLCJpbXBvcnRlIjo4MTAsIm1vbmVkYSI6IlBFUyIsImN0eiI6MSwidGlwb0RvY1JlYyI6ODAsIm5yb0RvY1JlYyI6MzA3MTEyMjczNjUsInRpcG9Db2RBdXQiOiJFIiwiY29kQXV0Ijo3MTEwOTk0MzkzOTk5MH0=");
}
//---------------------------------------------------------------------------

