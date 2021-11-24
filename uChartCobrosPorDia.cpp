//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uChartCobrosPorDia.h"
#include "VariablesGlobales.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfChartCobrosPorDia *fChartCobrosPorDia;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfChartCobrosPorDia::TfChartCobrosPorDia(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfChartCobrosPorDia::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;
}
//---------------------------------------------------------------------------
void __fastcall TfChartCobrosPorDia::FormResize(TObject *Sender)
{
   DBChart1->Width = fChartCobrosPorDia->Width;
   DBChart1->Height = fChartCobrosPorDia->Height - 35;
}
//---------------------------------------------------------------------------
void __fastcall TfChartCobrosPorDia::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS2->Active = false;
   Query2->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
