//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <FileCtrl.hpp>

#pragma hdrstop

#include "uConfiguraciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfConfiguraciones *fConfiguraciones;

//---------------------------------------------------------------------------
__fastcall TfConfiguraciones::TfConfiguraciones(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TfConfiguraciones::FormShow(TObject *Sender)
{
	  TIniFile *Configuraciones;
	  String Dir = GetCurrentDir()+"//Config.ini";
      Configuraciones = new TIniFile(Dir);

      if(printer->Printers->Count != 0)
      {
         cboPrinterPlanillas->Items->Assign(printer->Printers);
         cboPrinterPlanillas->ItemIndex = printer->PrinterIndex;
		 cboPrinterEtiquetas->Items->Assign(printer->Printers);
		 cboPrinterEtiquetas->ItemIndex = printer->PrinterIndex;
		 cboPrinterPresupuestos->Items->Assign(printer->Printers);
		 cboPrinterPresupuestos->ItemIndex = printer->PrinterIndex;
		 cboPrinterPDF->Items->Assign(printer->Printers);
		 cboPrinterPDF->ItemIndex = printer->PrinterIndex;
      }
      else
      {
		 Application->MessageBox(L"No hay impresoras instaladas en el sistema." ,L"Error",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);

         cboPrinterPlanillas->Text = "SIN IMPRESORAS";
		 cboPrinterEtiquetas->Text = "SIN IMPRESORAS";
		 cboPrinterPresupuestos->Text = "SIN IMPRESORAS";
		 cboPrinterPDF->Text = "SIN IMPRESORAS";
		 Configuraciones->WriteString("Impresion","ImpresoraPlanillas","NO CONFIGURADA");
		 Configuraciones->WriteString("Impresion","ImpresoraEtiquetas","NO CONFIGURADA");
		 Configuraciones->WriteString("Impresion","ImpresoraPresupuestos","NO CONFIGURADA");
		 Configuraciones->WriteString("Impresion","ImpresoraPDF","NO CONFIGURADA");
	  }

      Label2->Caption = Configuraciones->ReadString("Impresion","ImpresoraPlanillas","NO_CONFIGURADA");
	  Label4->Caption = Configuraciones->ReadString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");
	  Label6->Caption = Configuraciones->ReadString("Impresion","ImpresoraPresupuestos","NO_CONFIGURADA");
	  Label18->Caption = Configuraciones->ReadString("Impresion","ImpresoraPDF","NO_CONFIGURADA");

      cboPrinterPlanillas->Text = Label2->Caption;
	  cboPrinterEtiquetas->Text = Label4->Caption;
	  cboPrinterPresupuestos->Text = Label6->Caption;
	  cboPrinterPDF->Text = Label18->Caption;

	  DirMenuMail = Configuraciones->ReadString("Directorios","DirMenuMail", "NO_CONFIGURADA");
	  DirMenuVenta = Configuraciones->ReadString("Directorios","DirMenuVenta", "NO_CONFIGURADA");
	  DirPlanillaVenta = Configuraciones->ReadString("Directorios","DirPlanillaVenta", "NO_CONFIGURADA");
	  DirPlanillaFijos = Configuraciones->ReadString("Directorios","DirPlanillaFijos", "NO_CONFIGURADA");
	  DirPlanillaInstrucciones = Configuraciones->ReadString("Directorios","DirPlanillaInstrucciones", "NO_CONFIGURADA");
	  DirComprobantesX = Configuraciones->ReadString("Directorios","ComprobantesX", "NO_CONFIGURADA");
	  DirFacturas = Configuraciones->ReadString("Directorios","Facturas", "NO_CONFIGURADA");

	  Label7->Caption = "Actual: " + DirMenuMail;
	  Label8->Caption = "Actual: " + DirMenuVenta;
	  Label9->Caption = "Actual: " + DirPlanillaVenta;
	  Label10->Caption = "Actual: " + DirPlanillaFijos;
	  Label11->Caption = "Actual: " + DirPlanillaInstrucciones;
	  Label19->Caption = "Actual: " + DirComprobantesX;
	  Label20->Caption = "Actual: " + DirFacturas;


	  Edit1->Text = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");


	  //BUPrincipal = Configuraciones->ReadString("DirectoriosBackUp","DirectorioPrincipal", SD->InitialDir);
	  //BUSecundario = Configuraciones->ReadString("DirectoriosBackUp","DirectorioSecundario", SD->InitialDir);

	  delete Configuraciones;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button2Click(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Configuraciones->WriteString("Impresion","ImpresoraPlanillas",cboPrinterPlanillas->Text);
   Configuraciones->WriteString("Impresion","ImpresoraEtiquetas",cboPrinterEtiquetas->Text);
   Configuraciones->WriteString("Impresion","ImpresoraPresupuestos",cboPrinterPresupuestos->Text);
   Configuraciones->WriteString("Impresion","ImpresoraPDF",cboPrinterPDF->Text);

   Label2->Caption = cboPrinterPlanillas->Text;
   Label4->Caption = cboPrinterEtiquetas->Text;
   Label6->Caption = cboPrinterPresupuestos->Text;
   Label18->Caption = cboPrinterPDF->Text;

   Configuraciones->WriteString("Directorios","DirMenuMail",DirMenuMail);
   Configuraciones->WriteString("Directorios","DirMenuVenta",DirMenuVenta);
   Configuraciones->WriteString("Directorios","DirPlanillaVenta",DirPlanillaVenta);
   Configuraciones->WriteString("Directorios","DirPlanillaFijos",DirPlanillaFijos);
   Configuraciones->WriteString("Directorios","DirPlanillaInstrucciones",DirPlanillaInstrucciones);
   Configuraciones->WriteString("Directorios","ComprobantesX",DirComprobantesX);
   Configuraciones->WriteString("Directorios","Facturas",DirFacturas);

   Configuraciones->WriteString("MySQLServer","Servidor",Edit1->Text);

//
//   Configuraciones->WriteString("DirectoriosBackUp","DirectorioPrincipal",BUPrincipal);
//   Configuraciones->WriteString("DirectoriosBackUp","DirectorioSecundario",BUSecundario);

   delete Configuraciones;

   Application->MessageBox(L"Si realiz� alg�n cambio en el nombre del servidor de base de datos deber� cerrar el programa y volver a iniciarlo." ,L"ATENCI�N!",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormDestroy(TObject *Sender)
{
   delete printer;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormCreate(TObject *Sender)
{
   printer = new TPrinter;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button1Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Men� para e-mail","",dir) == true)
   {
	  Label7->Caption = "Actual: " + dir;
	  DirMenuMail = dir;
   }
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button3Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Men� para ventas","",dir) == true)
   {
	  Label8->Caption = "Actual: " + dir;
	  DirMenuVenta = dir;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfConfiguraciones::Button4Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Planilla para ventas","",dir) == true)
   {
	  Label9->Caption = "Actual: " + dir;
	  DirPlanillaVenta = dir;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfConfiguraciones::Button5Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Planilla para clientes fijos","",dir) == true)
   {
	  Label10->Caption = "Actual: " + dir;
	  DirPlanillaFijos = dir;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfConfiguraciones::Button6Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Planilla para instrucciones","",dir) == true)
   {
	  Label11->Caption = "Actual: " + dir;
	  DirPlanillaInstrucciones = dir;
   }
}
//---------------------------------------------------------------------------


void __fastcall TfConfiguraciones::Button7Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Comprobantes X","",dir) == true)
   {
	  Label19->Caption = "Actual: " + dir;
	  DirComprobantesX = dir;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfConfiguraciones::Button8Click(TObject *Sender)
{
   String dir;

   if(SelectDirectory("Facturas","",dir) == true)
   {
	  Label20->Caption = "Actual: " + dir;
	  DirFacturas = dir;
   }
}
//---------------------------------------------------------------------------

