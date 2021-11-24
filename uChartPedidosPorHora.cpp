//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uChartPedidosPorHora.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfChartPedidosPorHora *fChartPedidosPorHora;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfChartPedidosPorHora::TfChartPedidosPorHora(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfChartPedidosPorHora::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------
void __fastcall TfChartPedidosPorHora::FormResize(TObject *Sender)
{
   DBChart1->Width = fChartPedidosPorHora->Width;
   DBChart1->Height = fChartPedidosPorHora->Height - 35;
}
//---------------------------------------------------------------------------
void __fastcall TfChartPedidosPorHora::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS2->Active = false;
   Query2->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
