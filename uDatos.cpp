//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VariablesGlobales.h"
#include "uChartPedidosPorHora.h"
#include "uChartPedidosPorDia.h"
#include "uChartCobrosPorDia.h"
#include "uChartComidasMasVendidas.h"
#include "uDatos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfDatos *fDatos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;

//---------------------------------------------------------------------------
__fastcall TfDatos::TfDatos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfDatos::Button1Click(TObject *Sender)
{
   CDS1->Active = false;

   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT (SELECT descripcion FROM repartidores WHERE idRepartidor = refRepartidor) AS repartidor, "
	   "SUM(unidades) AS cantViandas, SUM(pagoRealizado) AS cobro, "
	   "(SELECT COUNT(idCantidad) FROM cantidades WHERE cantidades.refRepartidor = cuentas.refRepartidor AND fecha >= :fi AND fecha <= :ff) AS cantDomicilios, "
	   "SUM(unidades * valorUnidad) AS montoVentas "
	   "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff GROUP BY refRepartidor";

   Query1->SQL->Add(q);
   Query1->ParamByName("fi")->AsDate = MC->Date;
   Query1->ParamByName("ff")->AsDate = MC->EndDate;
   Query1->Open();
   CDS1->Active = true;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   q = "SELECT SUM(unidades) AS totalViandas, SUM(pagoRealizado) AS totalCobros, "
	   "SUM(unidades * valorUnidad) AS totalVentas, "
	   "(SELECT COUNT(*) AS totalPedidos FROM pedidos WHERE DATE(momento) >= :fi AND DATE(momento) <= :ff) AS totalPedidos, "
	   "(SELECT COUNT(*) AS oficina FROM pedidos WHERE refComida4 = 1 AND DATE(momento) >= :fi AND DATE(momento) <= :ff) AS oficina, "
	   "(SELECT SUM(acumuladoGlobal) as deudaClientes FROM clientes WHERE clientes.acumuladoGlobal > 0.0) AS deudaClientes, "
	   "(SELECT (-1 * SUM(acumuladoGlobal)) as deudaNuestra FROM clientes WHERE clientes.acumuladoGlobal < 0.0) AS deudaNuestra "
	   "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("fi")->AsDate = MC->Date;
   QueryAux->ParamByName("ff")->AsDate = MC->EndDate;
   QueryAux->Open();

   Label1->Caption = "Equivalencia en viandas totales entregadas en el per?odo: " + FormatFloat("0.00",QueryAux->FieldByName("totalViandas")->AsFloat);
   Label3->Caption = "Cobro total en el per?odo: $ " + FormatFloat("#,##0.00",QueryAux->FieldByName("totalCobros")->AsFloat);
   Label2->Caption = "Monto total de ventas en el per?odo: $ " + FormatFloat("#,##0.00",QueryAux->FieldByName("totalVentas")->AsFloat);
   Label4->Caption = "Total de pedidos entregados en el per?odo: " + QueryAux->FieldByName("totalPedidos")->AsString;
   Label5->Caption = "Total de pedidos sin complemento en el per?odo: " + QueryAux->FieldByName("oficina")->AsString;
   Label6->Caption = "Total $ en viandas a?n no cobradas: $ " + FormatFloat("#,##0.00",QueryAux->FieldByName("deudaClientes")->AsFloat);
   Label7->Caption = "Total $ en viandas a?n no entregadas: $ " + FormatFloat("#,##0.00",QueryAux->FieldByName("deudaNuestra")->AsFloat);
   QueryAux->Close();

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfDatos::FormClose(TObject *Sender, TCloseAction &Action)
{
   QueryAux->Close();
   CDS1->Active = false;
   Query1->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfDatos::FormShow(TObject *Sender)
{
   MC->MultiSelect = false;
   MC->Date = Now();
   MC->EndDate = MC->Date;
   MC->MultiSelect = true;

   Label1->Caption = "";
   Label3->Caption = "";
   Label2->Caption = "";
   Label4->Caption = "";
   Label5->Caption = "";
   Label6->Caption = "";
   Label7->Caption = "";

   Panel1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfDatos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;

   Panel1->Top = (fDatos->Height - Panel1->Height) / 2;
   Panel1->Left = (fDatos->Width - Panel1->Width) / 2;
}
//---------------------------------------------------------------------------



void __fastcall TfDatos::Button2Click(TObject *Sender)
{
   fChartPedidosPorDia->CDS2->Active = false;

   fChartPedidosPorDia->Query2->Close();
   fChartPedidosPorDia->Query2->SQL->Clear();
   String q;
   q = "SELECT SUM(unidades) AS cantViandas, DAYOFMONTH(fecha) AS diaDelMes "
	   "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff GROUP BY fecha";

   fChartPedidosPorDia->Query2->SQL->Add(q);
   fChartPedidosPorDia->Query2->ParamByName("fi")->AsDate = MC->Date;
   fChartPedidosPorDia->Query2->ParamByName("ff")->AsDate = MC->EndDate;
   fChartPedidosPorDia->Query2->Open();
   fChartPedidosPorDia->CDS2->Active = true;

   fChartPedidosPorDia->DBChart1->UndoZoom();
   fChartPedidosPorDia->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfDatos::Button3Click(TObject *Sender)
{
   fChartPedidosPorHora->CDS2->Active = false;

   fChartPedidosPorHora->Query2->Close();
   fChartPedidosPorHora->Query2->SQL->Clear();
   String q;
   q = "SELECT COUNT(*) AS cantPedidos, HOUR(momento) AS horaDelDia "
	   "FROM pedidos WHERE DATE(momento) >= :fi AND DATE(momento) <= :ff GROUP BY HOUR(momento)";

   fChartPedidosPorHora->Query2->SQL->Add(q);
   fChartPedidosPorHora->Query2->ParamByName("fi")->AsDate = MC->Date;
   fChartPedidosPorHora->Query2->ParamByName("ff")->AsDate = MC->EndDate;
   fChartPedidosPorHora->Query2->Open();
   fChartPedidosPorHora->CDS2->Active = true;

   fChartPedidosPorHora->DBChart1->UndoZoom();
   fChartPedidosPorHora->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfDatos::Button4Click(TObject *Sender)
{
   fChartCobrosPorDia->CDS2->Active = false;

   fChartCobrosPorDia->Query2->Close();
   fChartCobrosPorDia->Query2->SQL->Clear();
   String q;
   q = "SELECT SUM(pagoRealizado) AS pagoRecibido, DAYOFMONTH(fecha) AS diaDelMes "
	   "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff GROUP BY fecha";

   fChartCobrosPorDia->Query2->SQL->Add(q);
   fChartCobrosPorDia->Query2->ParamByName("fi")->AsDate = MC->Date;
   fChartCobrosPorDia->Query2->ParamByName("ff")->AsDate = MC->EndDate;
   fChartCobrosPorDia->Query2->Open();
   fChartCobrosPorDia->CDS2->Active = true;

   fChartCobrosPorDia->DBChart1->UndoZoom();
   fChartCobrosPorDia->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfDatos::Button5Click(TObject *Sender)
{
   fChartComidasMasVendidas->CDS2->Active = false;

   fChartComidasMasVendidas->Query2->Close();
   fChartComidasMasVendidas->Query2->SQL->Clear();
   String q;
   q = "SELECT * FROM (SELECT refComida, COUNT(*) AS nroRepe, "
	   "(SELECT codigo FROM comidas WHERE comidas.idComida = refComida) AS nombre "
	   "FROM "
	   "("
		   "SELECT refComida1 AS refComida FROM pedidos WHERE refComida1 > 1 AND DATE(momento) >= :fi AND DATE(momento) <= :ff "
		   "UNION ALL "
		   "(SELECT refComida2 AS refComida FROM pedidos WHERE refComida2 > 1 AND DATE(momento) >= :fi AND DATE(momento) <= :ff) "
		   "UNION ALL "
		   "(SELECT refComida3 AS refComida FROM pedidos WHERE refComida3 > 1 AND DATE(momento) >= :fi AND DATE(momento) <= :ff) "
		   "UNION ALL "
		   "(SELECT refComida4 AS refComida FROM pedidos WHERE refComida4 > 1 AND DATE(momento) >= :fi AND DATE(momento) <= :ff) "
	   ") aux "
	   "GROUP BY refComida) aux2 WHERE nroRepe > 10 ORDER BY nroRepe DESC LIMIT ";

   q = q + IntToStr(SpinEdit1->Value);

   fChartComidasMasVendidas->Query2->SQL->Add(q);
   fChartComidasMasVendidas->Query2->ParamByName("fi")->AsDate = MC->Date;
   fChartComidasMasVendidas->Query2->ParamByName("ff")->AsDate = MC->EndDate;
   fChartComidasMasVendidas->Query2->Open();
   fChartComidasMasVendidas->CDS2->Active = true;

   fChartComidasMasVendidas->DBChart1->UndoZoom();
   fChartComidasMasVendidas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfDatos::Button7Click(TObject *Sender)
{
   CDS2->Active = false;

   Query2->Close();
   Query2->SQL->Clear();
   String q;
   q = "SELECT * FROM (SELECT SUM(unidades) AS cantViandas, refCliente, (SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE idCliente = refCliente LIMIT 1) AS cliente "
	   "FROM cuentas WHERE fecha >= :fi AND fecha <= :ff GROUP BY refCliente) aux ORDER BY cantViandas DESC LIMIT ";

   q = q + IntToStr(SpinEdit1->Value);

   Query2->SQL->Add(q);
   Query2->ParamByName("fi")->AsDate = MC->Date;
   Query2->ParamByName("ff")->AsDate = MC->EndDate;
   Query2->Open();
   CDS2->Active = true;

   Panel1->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfDatos::Button6Click(TObject *Sender)
{
   CDS2->Active = false;
   Query2->Close();
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------

