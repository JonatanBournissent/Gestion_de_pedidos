//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uImprimirResumenManual.h"
#include "VariablesGlobales.h"
#include "uPedidos.h"
#include "uImprimirCuentas.h"
#include "uSeleccionarComida.h"
#include "uVerHistorialPedidos.h"
#include "uSeleccionarCliente.h"
#include "uVerCargaManual.h"
#include "uCuentas.h"
#include "uImprimirPlanillas.h"
#include "uConfigurarAlarma.h"
#include "uModificarCliente.h"
#include "uModificarComida.h"
#include "uGestionarAlarmas.h"
#include "uRepartos.h"
#include "uMenuSemanal.h"
#include "uMostrarPedidos.h"
#include "uComprobantesX.h"
#include "uEmitirComprobanteElectronico.h"
#include "uInformacionNutricional.h"
#include "uInfoCliente.h"
#include "uPausa.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uFrame2"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"


TfPedidos *fPedidos;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;

//---------------------------------------------------------------------------
__fastcall TfPedidos::TfPedidos(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

bool TfPedidos::esOpcionEspecial(int idComida)
{
   if (idComida == 1) {
	   return false;
   }

   for (int i = 0; i < RG1->Items->Count - 1; i++) {

	  if(arrIdComida[i] == idComida)
	     return false;
   }

   return true;
}

//---------------------------------------------------------------------------
void TfPedidos::completarEtiquetaPedido(String c1, String c2, String c3, String c4,
						   String cliente, String repartidor, String nroReparto,
						   String comentario, bool izq, bool c1Esp, bool c2Esp,
						   bool c3Esp, bool comentarioEsp, bool blanca = false)
{
   TfrxMemoView * num;
   TfrxMemoView * rep;
   TfrxMemoView * pp1;
   TfrxMemoView * pp2;
   TfrxMemoView * pp3;
   TfrxMemoView * comp;
   TfrxMemoView * coment;
   TfrxMemoView * pos;

   TfrxBrushFill * rellPos;
   TfrxBrushFill * rellRep;
   TfrxBrushFill * rellPP1;
   TfrxBrushFill * rellPP2;
   TfrxBrushFill * rellPP3;


   if (izq) {

	  num = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("num1"));
	  rep = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("rep1"));
	  pp1 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp11"));
	  pp2 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp12"));
	  pp3 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp13"));
	  comp = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("comp1"));
	  coment = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("coment1"));
	  pos = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pos1"));
   }
   else {

	  num = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("num2"));
	  rep = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("rep2"));
	  pp1 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp21"));
	  pp2 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp22"));
	  pp3 = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pp23"));
	  comp = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("comp2"));
	  coment = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("coment2"));
	  pos = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport1->FindObject("pos2"));
   }


   rellPos = dynamic_cast <TfrxBrushFill *> (pos->Fill);
   rellPos->BackColor = Vcl::Graphics::clNone;
   rellRep = dynamic_cast <TfrxBrushFill *> (rep->Fill);
   rellRep->BackColor = Vcl::Graphics::clNone;
   rellPP1 = dynamic_cast <TfrxBrushFill *> (pp1->Fill);
   rellPP1->BackColor = Vcl::Graphics::clNone;
   rellPP2 = dynamic_cast <TfrxBrushFill *> (pp2->Fill);
   rellPP2->BackColor = Vcl::Graphics::clNone;
   rellPP3 = dynamic_cast <TfrxBrushFill *> (pp3->Fill);
   rellPP3->BackColor = Vcl::Graphics::clNone;

   pos->Font->Color = clBlack;
   rep->Font->Color = clBlack;
   pp1->Font->Color = clBlack;
   pp2->Font->Color = clBlack;
   pp3->Font->Color = clBlack;


   if (blanca) {

	  pp1->Text = "";
	  pp2->Text = "";
	  pp3->Text = "";
	  comp->Text = "";
	  coment->Text = "";
	  num->Text = "";
	  rep->Text = "";
	  pos->Text = "";

	  return;
   }

   pp1->Text = c1;
   pp2->Text = c2;
   pp3->Text = c3;
   comp->Text = c4;
   coment->Text = comentario;
   num->Text = cliente;
   rep->Text = repartidor;
   pos->Text = nroReparto;

   rellPos = dynamic_cast <TfrxBrushFill *> (pos->Fill);
   rellPos->BackColor = clBlack;
   pos->Font->Color = clWhite;


   if (c1Esp || c2Esp || c3Esp || comentarioEsp) {

	  rellRep = dynamic_cast <TfrxBrushFill *> (rep->Fill);
	  rellRep->BackColor = clBlack;
	  rep->Font->Color = clWhite;
   }

   if (c1Esp) {

	  rellPP1 = dynamic_cast <TfrxBrushFill *> (pp1->Fill);
	  rellPP1->BackColor = clBlack;
	  pp1->Font->Color = clWhite;
   }

   if (c2Esp) {

	  rellPP2 = dynamic_cast <TfrxBrushFill *> (pp2->Fill);
	  rellPP2->BackColor = clBlack;
	  pp2->Font->Color = clWhite;
   }

   if (c3Esp) {

	  rellPP3 = dynamic_cast <TfrxBrushFill *> (pp3->Fill);
	  rellPP3->BackColor = clBlack;
	  pp3->Font->Color = clWhite;
   }
}

//---------------------------------------------------------------------------
void TfPedidos::completarEtiquetaComplemento(String c4, String cliente,
										String repartidor, String nroReparto,
										String comentario, bool izq,
										bool blanca)
{
	TfrxMemoView * num;
	TfrxMemoView * rep;
	TfrxMemoView * comp;
	TfrxMemoView * coment;
	TfrxMemoView * pos;
	TfrxMemoView * ident;

	if (izq) {

		num = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("num1"));
		rep = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("rep1"));
		comp = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("comp1"));
		coment = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("coment1"));
		pos = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("pos1"));
		ident = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("ident1"));
	}
	else {

		num = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("num2"));
		rep = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("rep2"));
		comp = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("comp2"));
		coment = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("coment2"));
		pos = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("pos2"));
		ident = dynamic_cast <TfrxMemoView *> (fPedidos->frxReport2->FindObject("ident2"));
	}

	comp->Visible = true;
	coment->Visible = true;
	num->Visible = true;
	rep->Visible = true;
	pos->Visible = true;
	ident->Visible = true;


	if (blanca) {
		comp->Visible = false;
		coment->Visible = false;
		num->Visible = false;
		rep->Visible = false;
		pos->Visible = false;
		ident->Visible = false;

		return;
	}

	comp->Text = c4;
	coment->Text = comentario;
	num->Text = cliente;
	rep->Text = repartidor;
	pos->Text = nroReparto;
}
//--------------------------------------------------------------------------

String TfPedidos::getImpresoraEtiquetas(void)
{
    TIniFile *Configuraciones;
	String Dir = GetCurrentDir()+"//Config.ini";
	Configuraciones = new TIniFile(Dir);
	String impActual = Configuraciones->ReadString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");

	if (impActual == "NO_CONFIGURADA") {

	  String msg;
	  msg = "Falta configurar una impresora para esta funci?n.";
	  Application->MessageBox(msg.w_str() ,L"ERROR", MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  delete Configuraciones;
	  return impActual;
	}


	int impIndex;

	TPrinter *printer;
	printer = new TPrinter;

	for (impIndex = 0; impIndex < printer->Printers->Count; impIndex++) {

	  if (printer->Printers->Strings[impIndex] == impActual)
		 break;
	}

	if (impIndex >= printer->Printers->Count) {
	  Configuraciones->WriteString("Impresion","ImpresoraEtiquetas","NO_CONFIGURADA");
	  String msg;
	  msg = "No se encontr? la impresora configurada para esta funci?n.";
	  Application->MessageBox(msg.w_str() ,L"ERROR", MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  delete Configuraciones;
	  return "NO_CONFIGURADA";
	}

	return impActual;
}

//--------------------------------------------------------------------------

void TfPedidos::procesoImpresionEtiquetasPedidos(int reparto)
{

	int refComida1, refComida2, refComida3, nroApaAnt;
	String c1, c2, c3, c4, comentario, cliente, repartidor, nroReparto;
	bool c1Esp, c2Esp, c3Esp;
	bool comentarioEsp;

	bool etiquetaIzq = true;

	while (!CDSEtiquetas->Eof) {

	   c1 = CDSEtiquetas->FieldByName("c1")->AsString;
	   c2 = CDSEtiquetas->FieldByName("c2")->AsString;
	   c3 = CDSEtiquetas->FieldByName("c3")->AsString;
	   c4 = CDSEtiquetas->FieldByName("c4")->AsString;
	   comentario = CDSEtiquetas->FieldByName("comentario")->AsString;
	   cliente = CDSEtiquetas->FieldByName("Numero")->AsString;
	   repartidor = CDSEtiquetas->FieldByName("Repartidor")->AsString;
	   nroReparto = CDSEtiquetas->FieldByName("salidaRep")->AsString;

	   refComida1 = CDSEtiquetas->FieldByName("refComida1")->AsInteger;
	   refComida2 = CDSEtiquetas->FieldByName("refComida2")->AsInteger;
	   refComida3 = CDSEtiquetas->FieldByName("refComida3")->AsInteger;
	   nroApaAnt = CDSEtiquetas->FieldByName("nroApa")->AsInteger;

	   c1Esp = esOpcionEspecial(refComida1);
	   c2Esp = esOpcionEspecial(refComida2);
	   c3Esp = esOpcionEspecial(refComida3);

	   comentarioEsp = false;
	   if(CDSEtiquetas->FieldByName("comentarioParaCocina")->AsInteger != 0)
		  comentarioEsp = true;


	   completarEtiquetaPedido(c1, c2, c3, c4, cliente, repartidor, nroReparto,
								  comentario, etiquetaIzq, c1Esp, c2Esp, c3Esp,
								  comentarioEsp, false);

	   etiquetaIzq = !etiquetaIzq;

	   CDSEtiquetas->Next();

	   if (!CDSEtiquetas->Eof) {

		   bool huboCambio = false;

		   if (CDSEtiquetas->FieldByName("refComida1")->AsInteger != refComida1 ||
			   CDSEtiquetas->FieldByName("refComida2")->AsInteger != refComida2 ||
			   CDSEtiquetas->FieldByName("refComida3")->AsInteger != refComida3) {

			   huboCambio = true;
		   }

		   if (!etiquetaIzq && nroApaAnt > 1 && huboCambio) {

			   completarEtiquetaPedido("", "", "", "", "", "", "",
									   "", false, false, false, false,
									   false, true);

			   etiquetaIzq = !etiquetaIzq;
			   CDSEtiquetas->Prior();
		   }
		   else	{

			   c1 = CDSEtiquetas->FieldByName("c1")->AsString;
			   c2 = CDSEtiquetas->FieldByName("c2")->AsString;
			   c3 = CDSEtiquetas->FieldByName("c3")->AsString;
			   c4 = CDSEtiquetas->FieldByName("c4")->AsString;
			   comentario = CDSEtiquetas->FieldByName("comentario")->AsString;
			   cliente = CDSEtiquetas->FieldByName("Numero")->AsString;
			   repartidor = CDSEtiquetas->FieldByName("Repartidor")->AsString;
			   nroReparto = CDSEtiquetas->FieldByName("salidaRep")->AsString;

			   refComida1 = CDSEtiquetas->FieldByName("refComida1")->AsInteger;
			   refComida2 = CDSEtiquetas->FieldByName("refComida2")->AsInteger;
			   refComida3 = CDSEtiquetas->FieldByName("refComida3")->AsInteger;
			   nroApaAnt = CDSEtiquetas->FieldByName("nroApa")->AsInteger;

			   c1Esp = esOpcionEspecial(refComida1);
			   c2Esp = esOpcionEspecial(refComida2);
			   c3Esp = esOpcionEspecial(refComida3);

			   comentarioEsp = false;
			   if(CDSEtiquetas->FieldByName("comentarioParaCocina")->AsInteger != 0)
				  comentarioEsp = true;


			   completarEtiquetaPedido(c1, c2, c3, c4, cliente, repartidor, nroReparto,
										  comentario, etiquetaIzq, c1Esp, c2Esp, c3Esp,
										  comentarioEsp, false);

			   etiquetaIzq = !etiquetaIzq;
		   }
	   }
	   else	if (!etiquetaIzq) {

		   completarEtiquetaPedido("", "", "", "", "", "", "",
									   "", false, false, false, false,
									   false, true);
	   }

	   frxReport1->PrepareReport(true);
	   frxReport1->Print();

	   contLineasImpresas++;

	   if(contLineasImpresas >= cantLineas)
	   {
		   fPausa->ShowModal();
	   }



	   CDSEtiquetas->Next();
	}



	if(Application->MessageBox(L"Las etiqueteas se imprimieron correctamente?" ,L"Impresi?n correcta?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
	{
	   QueryEtiquetas->Close();
	   CDSEtiquetas->Active = false;

	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("UPDATE pedidos SET etiquetaImpresa = 1 WHERE (DATE(momento) = :f "
						  "AND (SELECT sectorReparto FROM cantidades WHERE (pedidos.refCantidad = cantidades.idCantidad) LIMIT 1) = :sr)");
	   QueryAux->ParamByName("f")->AsDate = DTP->Date;
	   QueryAux->ParamByName("sr")->AsInteger = reparto;
	   QueryAux->ExecSQL();

	   Edit2->Text = "10000";
	   CheckBox1->Checked = false;
	}
	else
	{
	   Panel10->Left = (fPedidos->Width - Panel10->Width) / 2;
	   Panel10->Top = (fPedidos->Height - Panel10->Height) / 2;
	   Panel10->Visible = true;

	   llamadorAux = reparto;

	   Application->MessageBox(L"Seleccionar pr?xima etiqueta a imprimir y presionar el bot?n." ,L"Seleccione punto de partida",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);

	   CDSEtiquetas->First();
	}

}
//--------------------------------------------------------------------------

void TfPedidos::procesoImpresionEtiquetasComplementos()
{
	String c4, comentario, cliente, repartidor, nroReparto;

	bool etiquetaIzq = true;

	while (!CDSEtiquetasComp->Eof) {

	   c4 = CDSEtiquetasComp->FieldByName("c4")->AsString;
	   comentario = CDSEtiquetasComp->FieldByName("comentario")->AsString;
	   cliente = CDSEtiquetasComp->FieldByName("Numero")->AsString;
	   repartidor = CDSEtiquetasComp->FieldByName("Repartidor")->AsString;
	   nroReparto = CDSEtiquetasComp->FieldByName("salidaRep")->AsString;

	   completarEtiquetaComplemento(c4, cliente, repartidor, nroReparto,
							   comentario, etiquetaIzq, false);

	   etiquetaIzq = !etiquetaIzq;

	   CDSEtiquetasComp->Next();

	   if (!CDSEtiquetasComp->Eof) {

		   c4 = CDSEtiquetasComp->FieldByName("c4")->AsString;
		   comentario = CDSEtiquetasComp->FieldByName("comentario")->AsString;
		   cliente = CDSEtiquetasComp->FieldByName("Numero")->AsString;
		   repartidor = CDSEtiquetasComp->FieldByName("Repartidor")->AsString;
		   nroReparto = CDSEtiquetasComp->FieldByName("salidaRep")->AsString;

		   completarEtiquetaComplemento(c4, cliente, repartidor, nroReparto,
										comentario, etiquetaIzq, false);

		   etiquetaIzq = !etiquetaIzq;
	   }
	   else	if (!etiquetaIzq) {

		   completarEtiquetaComplemento("", "", "", "", "", false, true);
	   }

	   frxReport2->PrepareReport(true);
	   frxReport2->Print();

	   contLineasImpresas++;

	   if(contLineasImpresas >= cantLineas)
	   {
		   fPausa->ShowModal();
	   }

	   CDSEtiquetasComp->Next();
	}


	if(Application->MessageBox(L"Las etiqueteas se imprimieron correctamente?" ,L"Impresi?n correcta?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) == IDYES)
	{
	   CDSEtiquetasComp->Active = false;
	   QueryEtiquetasComp->Close();

	   QueryAux->Close();
	   QueryAux->SQL->Clear();
	   QueryAux->SQL->Add("UPDATE pedidos SET complementoImpreso = 1 "
						  "WHERE DATE(momento) = :f AND complementoImpreso = 0 AND refComida4 NOT IN(:c1,:c2) ");
	   QueryAux->ParamByName("f")->AsDate = DTP->Date;
	   QueryAux->ParamByName("c1")->AsInteger = arrIdComida[RGTexto->Items->Count - 3];
	   QueryAux->ParamByName("c2")->AsInteger = arrIdComida[RGTexto->Items->Count - 2];
	   QueryAux->ExecSQL();

	   Edit2->Text = "10000";
	   CheckBox1->Checked = false;
	}
	else
	{
	   Panel17->Left = (fPedidos->Width - Panel17->Width) / 2;
	   Panel17->Top = (fPedidos->Height - Panel17->Height) / 2;
	   Panel17->Visible = true;

	   Application->MessageBox(L"Seleccionar pr?xima etiqueta a imprimir y presionar el bot?n." ,L"Seleccione punto de partida",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	}
}
//--------------------------------------------------------------------------

void TfPedidos::imprimirEtiquetas(int llamador)
{
	if (getImpresoraEtiquetas() != "NO_CONFIGURADA") {
		frxReport1->PrintOptions->Printer = getImpresoraEtiquetas();
	}
	else return;


	QueryAux->Close();
	QueryAux->SQL->Clear();

	QueryAux->SQL->Add("SELECT COUNT(*) AS cantidadPedidos FROM pedidos WHERE DATE(momento) = :f AND omitirEtiqueta = 0 AND etiquetaImpresa = 0 AND "
					   "refCliente IN (SELECT refCliente FROM cantidades WHERE sectorReparto = :sr AND fecha = :f)");

	QueryAux->ParamByName("f")->AsDate = DTP->Date;
	QueryAux->ParamByName("sr")->AsInteger = llamador;
	QueryAux->Open();
	cantidadPedidos = QueryAux->FieldByName("cantidadPedidos")->AsInteger;
	QueryAux->Close();


	if (cantidadPedidos == 0) {

	  Application->MessageBox(L"No hay pedidos para imprimir :(" ,L"No hay nada para imprimir",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
	}

	String msg;
	if (cantidadPedidos > 150)
	  msg = "Se van a imprimir " + IntToStr(cantidadPedidos) + " pedidos :D . Desea continuar?";
	else
	  msg = "Se van a imprimir " + IntToStr(cantidadPedidos) + " pedidos . Desea continuar?";

	if (Application->MessageBox(msg.w_str() ,L"Imprimir etiquetas?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  return;


	String q;

	q = "SELECT p.refCliente, p.comentario, p.refComida1, p.refComida2, p.refComida3, g.nroApa, p.comentarioParaCocina, "

	"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (p.refComida1 = comidas.idComida) LIMIT 1) AS c1, "
	"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (p.refComida2 = comidas.idComida) LIMIT 1) AS c2, "
	"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (p.refComida3 = comidas.idComida) LIMIT 1) AS c3, "
	"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (p.refComida4 = comidas.idComida) LIMIT 1) AS c4, "

	"(SELECT refRepartidor FROM cantidades WHERE (p.refCantidad = cantidades.idCantidad) LIMIT 1) AS refRep, "
	"(SELECT sectorReparto + 1 FROM cantidades WHERE (p.refCantidad = cantidades.idCantidad) LIMIT 1) AS salidaRep, "

	"(SELECT UPPER(SUBSTRING(descripcion, 1, 4)) FROM repartidores WHERE (repartidores.idRepartidor = refRep) LIMIT 1) AS Repartidor, "

	"(SELECT numero FROM clientes WHERE (p.refCliente = clientes.idCliente) LIMIT 1) AS Numero "

	"FROM pedidos p "

	"INNER JOIN( "

	"SELECT refComida1, refComida2, refComida3, refCliente, comentarioParaCocina, COUNT(*) AS nroApa FROM pedidos "
	"WHERE DATE(momento) = :f "
	"AND refCliente IN (SELECT refCliente FROM cantidades WHERE fecha = :f AND sectorReparto = :sr) "
	"AND etiquetaImpresa = 0 "
	"AND omitirEtiqueta = 0 "
	"GROUP BY refComida1, refComida2, refComida3, comentarioParaCocina "//ORDER BY nroApa DESC, refComida1, refComida2 "

	") g ON "

	"p.refCliente IN (SELECT refCliente FROM cantidades WHERE fecha = :f AND sectorReparto = :sr) "
	"AND p.refComida1 = g.refComida1 "
	"AND p.refComida2 = g.refComida2 "
	"AND p.refComida3 = g.refComida3 "
	"AND p.comentarioParaCocina = g.comentarioParaCocina "
	"AND DATE(p.momento) = :f "
	"AND p.etiquetaImpresa = 0 "
	"AND p.omitirEtiqueta = 0 "
	"ORDER BY comentarioParaCocina, nroApa DESC, refComida1, refComida2";


	CDSEtiquetas->Active = false;
	QueryEtiquetas->Close();
	QueryEtiquetas->SQL->Clear();
	QueryEtiquetas->SQL->Add(q);
	QueryEtiquetas->ParamByName("f")->AsDate = DTP->Date;
	QueryEtiquetas->ParamByName("sr")->AsInteger = llamador;
	QueryEtiquetas->ParamByName("una")->AsString = una;
	QueryEtiquetas->ParamByName("ens")->AsString = ens;
	QueryEtiquetas->Open();
	CDSEtiquetas->Active = true;


	CDSEtiquetas->First();

	procesoImpresionEtiquetasPedidos(llamador);

}
//--------------------------------------------------------------------------

void TfPedidos::imprimirComplementos(void)
{
	if (getImpresoraEtiquetas() != "NO_CONFIGURADA") {
		frxReport2->PrintOptions->Printer = getImpresoraEtiquetas();
	}
	else return;


   QueryAux->Close();
   QueryAux->SQL->Clear();

   QueryAux->SQL->Add("SELECT COUNT(*) AS cantidadPedidos FROM pedidos WHERE DATE(momento) = :f "
					  "AND complementoImpreso = 0 AND refComida4 > 1 AND refComida4 NOT IN(:c1,:c2) "
					  "ORDER BY refComida4");

   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("c1")->AsInteger = arrIdComida[RGTexto->Items->Count - 3];
   QueryAux->ParamByName("c2")->AsInteger = arrIdComida[RGTexto->Items->Count - 2];
   QueryAux->Open();

   int cantidadComplementos = QueryAux->FieldByName("cantidadPedidos")->AsInteger;
   QueryAux->Close();

   if(cantidadComplementos == 0)
   {
	  Application->MessageBox(L"No hay complementos especiales para imprimir :)" ,L"No hay nada para imprimir",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
	  return;
   }

   String msg = "Se van a imprimir " + IntToStr(cantidadComplementos) + " complementos especiales. Desea continuar?";
   if(Application->MessageBox(msg.w_str(), L"Imprimir complementos?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	  return;


	String q;

	q = "SELECT comentario, refComida4, "

	"(SELECT codigo FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS c4, "

	"(SELECT refRepartidor FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS refRep, "
	"(SELECT sectorReparto + 1 FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS salidaRep, "

	"(SELECT UPPER(SUBSTRING(descripcion, 1, 4)) FROM repartidores WHERE (repartidores.idRepartidor = refRep) LIMIT 1) AS Repartidor, "

	"(SELECT numero FROM clientes WHERE (refCliente = clientes.idCliente) LIMIT 1) AS Numero "

	"FROM pedidos WHERE DATE(momento) = :f AND complementoImpreso = 0 AND refComida4 > 1 AND refComida4 NOT IN(:c1,:c2) "

	"ORDER BY refComida4";

	CDSEtiquetasComp->Active = false;
	QueryEtiquetasComp->Close();
	QueryEtiquetasComp->SQL->Clear();
	QueryEtiquetasComp->SQL->Add(q);
	QueryEtiquetasComp->ParamByName("f")->AsDate = DTP->Date;
	QueryEtiquetasComp->ParamByName("c1")->AsInteger = arrIdComida[RGTexto->Items->Count - 3];
	QueryEtiquetasComp->ParamByName("c2")->AsInteger = arrIdComida[RGTexto->Items->Count - 2];
	QueryEtiquetasComp->Open();
	CDSEtiquetasComp->Active = true;


	CDSEtiquetasComp->First();

	procesoImpresionEtiquetasComplementos();
}
//---------------------------------------------------------------------------

String TfPedidos::comaToDot(String str)
{
   if(str.Pos(",") == 0)
	  return str;
   if(str.Pos(".") > 0)
	  return "0";

   int p = str.Pos(",");
   str = str.Delete(p,1);
   return str.Insert(".",p);
}
//---------------------------------------------------------------------------

String TfPedidos::generarCadComp(void)
{
	  String strComp = "";
	  ClientDataSet2->First();
	  int cont_1, cont_ens;
	  cont_1 = 0;
	  cont_ens = 0;

	  String cod;
	  while(!ClientDataSet2->Eof)
	  {
		 cod = ClientDataSet2->FieldByName("com4")->AsString;
		 if(cod != "")
		 {
			if(cod == "1")
			   cont_1++;
			else if(cod == "ENS")
			   cont_ens++;
			else
			   strComp = cod + "+" + strComp;
		 }
		 ClientDataSet2->Next();
	  }

	  if(strComp.SubString(strComp.Length(),1) == "+")   //para borrar el ultimo "+" en caso de que exista
		 strComp = strComp.Delete(strComp.Length(),1);


	  String aux = "";
	  String nuevo = "";

	  if(strComp.Pos("+") == 1)
		 strComp = strComp.Delete(1,1);

	  if(strComp.Pos("+") > 0)    //revisa si al menos hay al menos mas de un complemento en strComp
	  {
		 while(strComp.Pos("+") > 0)
		 {
			aux = strComp.SubString(1,strComp.Pos("+")-1);

			int cAux = 0;
			while(strComp.Pos(aux) > 0)
			{
			   cAux++;
			   strComp = strComp.Delete(strComp.Pos(aux),aux.Length());
			}

			if(cAux > 1)
			   nuevo = nuevo + aux + "x" + IntToStr(cAux) + "+";
			else
			   nuevo = nuevo + aux + "+";

			while(strComp.Pos("++"))
			{
			   strComp = strComp.Delete(strComp.Pos("++"),1);
			}
			if(strComp.Pos("+") == 1)
			   strComp = strComp.Delete(1,1);
			if(strComp.Pos("+") == 0)
			   if(strComp != "")
				  strComp = strComp + "+";
		 }

		 while(nuevo.SubString(nuevo.Length(),1) == "+")
			nuevo = nuevo.Delete(nuevo.Length(),1);

		 strComp = nuevo;
	  }

	  if(cont_ens > 0)
	  {
		 if(cont_ens == 1)
			strComp = "ENS+" + strComp;
		 else
			strComp = "ENSx" + IntToStr(cont_ens) + "+" + strComp;
	  }

	  if(cont_1 > 0)
		 strComp = IntToStr(cont_1) + "+" + strComp;

	  if(strComp.SubString(strComp.Length(),1) == "+")
			strComp = strComp.Delete(strComp.Length(),1);

	  return strComp;

	  /******FINALIZA RUTINA PARA GENERAR CADENA DE TEXTO DE COMPLEMENTOS******/

}
//---------------------------------------------------------------------------

void TfPedidos::CargarOpciones(void)
{
   cargandoOpciones = true;

   RG1->Enabled = false;
   RG2->Enabled = false;
   RG3->Enabled = false;
   RG4->Enabled = false;

   edComentario->Enabled = false;
   CBParaCocina->Enabled = false;
   CBOmitirEtiqueta->Enabled = false;
   cbRefMedioContacto->Enabled = false;
   cbRefProducto->Enabled = false;
   Label9->Enabled = false;
   Label17->Enabled = false;
   Label8->Enabled = false;

   RG1->Items->Clear();
   RG2->Items->Clear();
   RG3->Items->Clear();
   RG4->Items->Clear();
   RGTexto->Items->Clear();

   Query1->Close();
   Query1->SQL->Clear();
   String q = "SELECT *, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida1) AS c1, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida2) AS c2, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida3) AS c3, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida4) AS c4, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida5) AS c5, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida6) AS c6, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida7) AS c7, "
			  "(SELECT nombre FROM comidas WHERE idComida = refComida8) AS c8, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida7) AS una, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida8) AS ens "
			  "FROM menudeldia WHERE (fecha = :f) LIMIT 1";
   Query1->SQL->Add(q);
   Query1->ParamByName("f")->AsDate = DTP->Date;
   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  Panel2->Visible = false;
	  Panel3->Visible = false;
	  Panel4->Visible = false;
	  Panel5->Visible = false;
	  Panel6->Visible = false;
	  Panel7->Visible = false;
	  Panel8->Visible = false;
	  Panel9->Visible = false;
	  return;
   }
   else
   {

	  for(int i = 0; i < 9; i++)
		 arrIdComida[i] = 1;

	  int iID = 0;
	  RGTexto->Items->Add(Query1->FieldByName("c1")->AsString);
	  opciones[iID] = Query1->FieldByName("c1")->AsString;
	  arrIdComida[iID] = Query1->FieldByName("refComida1")->AsInteger;
	  iID++;


	  if(Query1->FieldByName("refComida2")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c2")->AsString);
		 opciones[iID] = Query1->FieldByName("c2")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida2")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida3")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c3")->AsString);
		 opciones[iID] = Query1->FieldByName("c3")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida3")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida4")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c4")->AsString);
		 opciones[iID] = Query1->FieldByName("c4")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida4")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida5")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c5")->AsString);
		 opciones[iID] = Query1->FieldByName("c5")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida5")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida6")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c6")->AsString);
		 opciones[iID] = Query1->FieldByName("c6")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida6")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida7")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c7")->AsString);
		 opciones[iID] = Query1->FieldByName("c7")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida7")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida8")->AsInteger != 1)
	  {
		 RGTexto->Items->Add(Query1->FieldByName("c8")->AsString);
		 opciones[iID] = Query1->FieldByName("c8")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida8")->AsInteger;
		 iID++;
	  }
	  RGTexto->Items->Add("Ninguna");
	  arrIdComida[iID] = 1;


	  una = Query1->FieldByName("una")->AsString;
	  ens = Query1->FieldByName("ens")->AsString;

	  Query1->Close();

	  for(int j = 0 ; j < RGTexto->Items->Count ; j++)
	  {
		 RG1->Items->Add("");
	  }
	  RG2->Items = RG1->Items;
	  RG3->Items = RG1->Items;
	  RG4->Items = RG1->Items;

	  int ni = RG1->Items->Count - 1;
	  RG1->ItemIndex = ni;
	  RG2->ItemIndex = ni;
	  RG3->ItemIndex = ni;
	  RG4->ItemIndex = ni;
	  RGTexto->ItemIndex = ni;



	  Panel2->Visible = false;
	  Panel3->Visible = false;
	  Panel4->Visible = false;
	  Panel5->Visible = false;
	  Panel6->Visible = false;
	  Panel7->Visible = false;
	  Panel8->Visible = false;
	  Panel9->Visible = false;

	  if(RG1->Items->Count > 1)
		 Panel2->Visible = true;
	  if(RG1->Items->Count > 2)
		 Panel3->Visible = true;
	  if(RG1->Items->Count > 3)
		 Panel4->Visible = true;
	  if(RG1->Items->Count > 4)
		 Panel5->Visible = true;
	  if(RG1->Items->Count > 5)
		 Panel6->Visible = true;
	  if(RG1->Items->Count > 6)
		 Panel7->Visible = true;
	  if(RG1->Items->Count > 7)
		 Panel8->Visible = true;
	  if(RG1->Items->Count > 8)
		 Panel9->Visible = true;

	  if(RG1->Items->Count == 2)
	  {
		 Panel2->Top = RG1->Top + 16 + 111 * 1;
	  }
	  else if(RG1->Items->Count == 3)
	  {
		 Panel2->Top = RG1->Top + 16 + 74 * 1;
		 Panel3->Top = RG1->Top + 16 + 74 * 2;
	  }
	  else if(RG1->Items->Count == 4)
	  {
		 Panel2->Top = RG1->Top + 16 + 55 * 1;
		 Panel3->Top = RG1->Top + 16 + 55 * 2;
		 Panel4->Top = RG1->Top + 16 + 55 * 3;
	  }
	  else if(RG1->Items->Count == 5)
	  {
		 Panel2->Top = RG1->Top + 16 + 44 * 1;
		 Panel3->Top = RG1->Top + 16 + 44 * 2;
		 Panel4->Top = RG1->Top + 16 + 44 * 3;
		 Panel5->Top = RG1->Top + 16 + 44 * 4;
	  }
	  else if(RG1->Items->Count == 6)
	  {
		 Panel2->Top = RG1->Top + 16 + 37 * 1;
		 Panel3->Top = RG1->Top + 16 + 37 * 2;
		 Panel4->Top = RG1->Top + 16 + 37 * 3;
		 Panel5->Top = RG1->Top + 16 + 37 * 4;
		 Panel6->Top = RG1->Top + 16 + 37 * 5;
	  }
	  else if(RG1->Items->Count == 7)
	  {
		 Panel2->Top = RG1->Top + 16 + 31 * 1;
		 Panel3->Top = RG1->Top + 16 + 31 * 2;
		 Panel4->Top = RG1->Top + 16 + 31 * 3;
		 Panel5->Top = RG1->Top + 16 + 31 * 4;
		 Panel6->Top = RG1->Top + 16 + 31 * 5;
		 Panel7->Top = RG1->Top + 16 + 31 * 6;
	  }
	  else if(RG1->Items->Count == 8)
	  {
		 Panel2->Top = RG1->Top + 16 + 27 * 1;
		 Panel3->Top = RG1->Top + 16 + 27 * 2;
		 Panel4->Top = RG1->Top + 16 + 27 * 3;
		 Panel5->Top = RG1->Top + 16 + 27 * 4;
		 Panel6->Top = RG1->Top + 16 + 27 * 5;
		 Panel7->Top = RG1->Top + 16 + 27 * 6;
		 Panel8->Top = RG1->Top + 16 + 27 * 7;
	  }
	  else if(RG1->Items->Count == 9)
	  {
		 Panel2->Top = RG1->Top + 16 + 24 * 1;
		 Panel3->Top = RG1->Top + 16 + 24 * 2;
		 Panel4->Top = RG1->Top + 16 + 24 * 3;
		 Panel5->Top = RG1->Top + 16 + 24 * 4;
		 Panel6->Top = RG1->Top + 16 + 24 * 5;
		 Panel7->Top = RG1->Top + 16 + 24 * 6;
		 Panel8->Top = RG1->Top + 16 + 24 * 7;
		 Panel9->Top = RG1->Top + 16 + 24 * 8;
	  }
   }
   Edit1->Enabled = true;
   Button9->Enabled = true;
   cargandoOpciones = false;
   cargandoPedido = false;
   Button27->Enabled = false;
}
//---------------------------------------------------------------------------

void TfPedidos::RestablecerFormulario(void)
{
   DBGrid2->Enabled = false;
   DBGrid1->Enabled = false;

   Panel16->Visible = false;

   ClientDataSet2->Active = false;
   ClientDataSet3->Active = false;
   Query1->Close();
   QueryPedidos->Close();
   QueryAux->Close();
   QueryCliente->Close();
   QueryComida->Close();
   QueryEtiquetas->Close();
   QueryGenCad->Close();
   QueryInfo->Close();



   Button7->Enabled = false;
   Button2->Enabled = false;

   idCliSel = 0;
   modificandoPedido = false;
   cargandoOpciones = false;
   cargandoPedido = false;
   Button27->Enabled = false;
   puedeSalir = true;


   idMod = 0;

   cbRefProducto->ItemIndex = 0;
   cbRefMedioContacto->ItemIndex = 0;
   CBOmitirEtiqueta->Checked = false;
   edComentario->Text = "";

   RG1->Enabled = false;
   RG2->Enabled = false;
   RG3->Enabled = false;
   RG4->Enabled = false;

   edComentario->Enabled = false;
   CBParaCocina->Enabled = false;
   CBOmitirEtiqueta->Enabled = false;
   cbRefMedioContacto->Enabled = false;
   cbRefProducto->Enabled = false;
   Label9->Enabled = false;
   Label17->Enabled = false;
   Label8->Enabled = false;

   RG1->ItemIndex = RG1->Items->Count - 1;
   RG2->ItemIndex = RG1->Items->Count - 1;
   RG3->ItemIndex = RG1->Items->Count - 1;
   RG4->ItemIndex = RG1->Items->Count - 1;

   Label4->Caption = "";
   Label5->Caption = "";
   Label6->Caption = "";
   Label7->Caption = "";
   idOpEsp1 = 0;
   idOpEsp2 = 0;
   idOpEsp3 = 0;
   idOpEsp4 = 0;

   Label12->Caption = "";

   edUnidades->Text = "1,00";
   edBandGrand->Text = "1";
   rgUbicacion->ItemIndex = -1;
   cbRepartidor->ItemIndex = -1;
   lbComplementos->Caption = "";
   RGSeleccionado = 0;
   Label18->Caption = "";

   Edit1->Clear();
   Edit1->Enabled = true;
   Button9->Enabled = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

String TfPedidos::GetCodigo(int idComida)
{
   if(idComida == arrIdComida[RG1->Items->Count - 3])
	  return "1";

   if(idComida == arrIdComida[RG1->Items->Count - 2])
	  return "ENS";

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE(idComida = :id) LIMIT 1");
   QueryAux->ParamByName("id")->AsString = idComida;
   QueryAux->Open();
   String codigo = QueryAux->FieldByName("codigo")->AsString;
   QueryAux->Close();
   return codigo;
}
//---------------------------------------------------------------------------

void TfPedidos::verClienteSeleccionado(int idCliente)
{
	 QueryAux->Close();
	 QueryAux->SQL->Clear();
	 QueryAux->SQL->Add("SELECT nroUnidades, nroBandejas, sectorReparto, txtComplemento, "
						"(SELECT descripcion FROM repartidores WHERE refRepartidor = idRepartidor LIMIT 1) AS Repartidor "
						"FROM cantidades WHERE(fecha = :d AND refCliente = :rc)");
	 QueryAux->ParamByName("d")->AsDate = DTP->Date;
	 QueryAux->ParamByName("rc")->AsInteger = idCliente;
	 QueryAux->Open();
	 if(!QueryAux->IsEmpty())  //SI YA EXISTIA UN PEDIDO, ENTONCES CARGA LOS DATOS
	 {
		edUnidades->Text = FormatFloat("0.00", QueryAux->FieldByName("nroUnidades")->AsFloat);
		edBandGrand->Text = QueryAux->FieldByName("nroBandejas")->AsString;
		rgUbicacion->ItemIndex = QueryAux->FieldByName("sectorReparto")->AsInteger;
		lbComplementos->Caption = QueryAux->FieldByName("txtComplemento")->AsString;

		cbRepartidor->ItemIndex = 0;
		while(1)
		{
		   if(cbRepartidor->Text == QueryAux->FieldByName("Repartidor")->AsString)
			  break;
		   else
		   {
			  if(cbRepartidor->ItemIndex == cbRepartidor->Items->Count - 1)
				 break;

			  cbRepartidor->ItemIndex++;
		   }
		}
	 }
	 else
	 {
		edUnidades->Text = "1,00";
		edBandGrand->Text = "1";
		lbComplementos->Caption = "";
	 }

	 QueryAux->Close();

	 String q1;
	 q1 = "SELECT idPedido, TIME(momento) AS hora, comentario, refCantidad, "
		  "(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', IF(codigo = 'NO', '', codigo))) FROM comidas WHERE refComida1 = idComida LIMIT 1) AS com1, "
		  "(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', IF(codigo = 'NO', '', codigo))) FROM comidas WHERE refComida2 = idComida LIMIT 1) AS com2, "
		  "(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', IF(codigo = 'NO', '', codigo))) FROM comidas WHERE refComida3 = idComida LIMIT 1) AS com3, "
		  "(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', IF(codigo = 'NO', '', codigo))) FROM comidas WHERE refComida4 = idComida LIMIT 1) AS com4 "
		  "FROM pedidos WHERE (refCliente = :rc AND DATE(momento) = :d) ORDER BY momento";

	 ClientDataSet2->Active = false;
	 QueryPedidos->Close();
	 QueryPedidos->SQL->Clear();
	 QueryPedidos->SQL->Add(q1);
	 QueryPedidos->ParamByName("d")->AsDate = DTP->Date;
	 QueryPedidos->ParamByName("rc")->AsInteger = idCliSel;
	 QueryPedidos->ParamByName("una")->AsString = una;
	 QueryPedidos->ParamByName("ens")->AsString = ens;
	 QueryPedidos->Open();
	 ClientDataSet2->Active = true;

	 Button7->Enabled = true;
	 Button2->Enabled = true;

	 RG1->Enabled = true;
	 RG2->Enabled = true;
	 RG3->Enabled = true;
	 RG4->Enabled = true;
	 DBGrid1->Enabled = true;

	 edComentario->Enabled = true;
	 CBParaCocina->Enabled = true;
	 CBOmitirEtiqueta->Enabled = true;
	 cbRefMedioContacto->Enabled = true;
	 cbRefProducto->Enabled = true;
	 Label9->Enabled = true;
	 Label17->Enabled = true;
	 Label8->Enabled = true;

	 ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------

void TfPedidos::actualizarInfoVentas(void)
{
   String q = "SELECT todas AS idComida, COUNT(*) AS cantidad, (SELECT nombre FROM comidas WHERE t.todas = comidas.idComida) AS nComida "
			  "FROM ((SELECT refComida1 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida1 > 1) "
			  "UNION ALL (SELECT refComida2 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida2 > 1) "
			  "UNION ALL (SELECT refComida3 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida3 > 1) "
			  "UNION ALL (SELECT refComida4 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida4 > 1)) t GROUP BY todas ";



   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add(q);
   QueryInfo->ParamByName("f")->AsDate = DTP->Date;
   QueryInfo->Open();


   ListBox1->Clear();
   int id;
   int i;
   bool esNormal;
   while(!QueryInfo->Eof)
   {
	  id = QueryInfo->FieldByName("idComida")->AsInteger;

	  esNormal = false;

	  for(i = 0; i< RGTexto->Items->Count; i++)
	  {
		 if(id == arrIdComida[i])
		 {
			RGTexto->Items->Strings[i] = opciones[i] + " (" + QueryInfo->FieldByName("cantidad")->AsString + ")";
			i = 100; //si o si sale del for
			esNormal = true;
		 }
	  }
	  if(!esNormal)
	  {
		 ListBox1->Items->Add(QueryInfo->FieldByName("nComida")->AsString + " x " + QueryInfo->FieldByName("cantidad")->AsString);
	  }

	  QueryInfo->Next();
   }

   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add("SELECT SUM(nroUnidades) AS cantidadViandas FROM cantidades WHERE fecha = :f");
   QueryInfo->ParamByName("f")->AsDate = DTP->Date;
   QueryInfo->Open();

   Label12->Caption = "Cantidad de viandas: " + QueryInfo->FieldByName("cantidadViandas")->AsString;

   QueryInfo->Close();

   QueryRep->Close();
   QueryRep->SQL->Clear();
   QueryRep->SQL->Add("SELECT refRepartidor, (sectorReparto + 1) AS reparto, RPAD(SUM(nroUnidades),5 , ' ') AS cantViandas, RPAD(COUNT(*), 2, ' ') AS cantDirecciones, "
					  "(SELECT RPAD(nombreCorto, 5, ' ') FROM repartidores WHERE refRepartidor = idRepartidor LIMIT 1) AS nombreRep "
					  "FROM cantidades WHERE fecha = :fecha "
					  "GROUP BY refRepartidor, sectorReparto ORDER BY nombreRep, reparto");
   QueryRep->ParamByName("fecha")->AsDate = DTP->Date;
   QueryRep->Open();
   ListBox3->Clear();
   QueryRep->First();
   while(!QueryRep->Eof)
   {
	  ListBox3->Items->Add(QueryRep->FieldByName("nombreRep")->AsString + " " + QueryRep->FieldByName("reparto")->AsString + "?- " + QueryRep->FieldByName("cantViandas")->AsString + " - " + QueryRep->FieldByName("cantDirecciones")->AsString);
	  QueryRep->Next();
   }
   QueryRep->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::FormShow(TObject *Sender)
{
   DTP->DateTime = Now();
   CargarOpciones();
   Edit2->Text = "1000";
   Edit2->Enabled = false;
   CheckBox1->Checked = false;

   cbRefMedioContacto->Clear();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT * FROM medioscontacto ORDER BY idMedioContacto");
   QueryAux->Open();
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  cbRefMedioContacto->Items->Add(QueryAux->FieldByName("descripcion")->AsString);
	  QueryAux->Next();
   }
   QueryAux->Close();
   cbRefMedioContacto->ItemIndex = 4;

   cbRefProducto->Clear();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT * FROM productos ORDER BY idProducto");
   QueryAux->Open();
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  cbRefProducto->Items->Add(QueryAux->FieldByName("descripcion")->AsString);
	  QueryAux->Next();
   }
   QueryAux->Close();
   cbRefProducto->ItemIndex = 0;


   QueryAux->Close();
   QueryAux->SQL->Clear();

   if(DayOfTheWeek(DTP->Date) == DaySaturday)
	  QueryAux->SQL->Add("SELECT descripcion FROM repartidores WHERE reparteSabados = 1 ORDER BY descripcion");
   else
      QueryAux->SQL->Add("SELECT descripcion FROM repartidores ORDER BY descripcion");
   QueryAux->Open();

   cbRepartidor->Clear();
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  cbRepartidor->Items->Add(QueryAux->FieldByName("descripcion")->AsString);
	  QueryAux->Next();
   }
   QueryAux->Close();

   RestablecerFormulario();

   actualizarInfoVentas();
   Panel18->Visible = false;
   Panel19->Visible = false;
   Panel20->Visible = false;
   blockRGTexto = false;
//   actualizarInfoRepartos = 0;

   Edit1->SetFocus();

   Timer3->Enabled = true;

   if(DayOfTheWeek(DTP->Date) == DayThursday)
	  CopiarcombinacionesJUEVES1->Visible = true;
   else
      CopiarcombinacionesJUEVES1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DTPChange(TObject *Sender)
{
   if(cargandoPedido)
   {
	  return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();

   if(DayOfTheWeek(DTP->Date) == DaySaturday)
	  QueryAux->SQL->Add("SELECT descripcion FROM repartidores WHERE reparteSabados = 1 ORDER BY descripcion");
   else
      QueryAux->SQL->Add("SELECT descripcion FROM repartidores ORDER BY descripcion");
   QueryAux->Open();

   if(DayOfTheWeek(DTP->Date) == DayThursday)
	  CopiarcombinacionesJUEVES1->Visible = true;
   else
      CopiarcombinacionesJUEVES1->Visible = false;

   cbRepartidor->Clear();
   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  cbRepartidor->Items->Add(QueryAux->FieldByName("descripcion")->AsString);
	  QueryAux->Next();
   }
   QueryAux->Close();

   CargarOpciones();
   actualizarInfoVentas();
   if(Edit1->Text != "")
	  Edit1Change(DTP);
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button2Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE cantidades SET nroUnidades = :cant, nroBandejas = :nb WHERE(fecha = :d AND refCliente = :rc)");
   QueryAux->ParamByName("d")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idCliSel;
   QueryAux->ParamByName("cant")->AsString = comaToDot(edUnidades->Text);
   QueryAux->ParamByName("nb")->AsString = edBandGrand->Text;
   QueryAux->ExecSQL();

   actualizarInfoVentas();

   Beep();
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Modificarestepedido1Click(TObject *Sender)
{
   RG1->Enabled = false;
   RG2->Enabled = false;
   RG3->Enabled = false;
   RG4->Enabled = false;

   RG1->ItemIndex = RG1->Items->Count - 1;
   RG2->ItemIndex = RG2->Items->Count - 1;
   RG3->ItemIndex = RG3->Items->Count - 1;
   RG4->ItemIndex = RG4->Items->Count - 1;


   idMod = ClientDataSet2->FieldByName("idPedido")->AsInteger;
   int rp, rc1, rc2, rc3, rc4, rmc, oe, cpc;
   String coment;
   modificandoPedido = true;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT * FROM pedidos WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = idMod;
   QueryAux->Open();
   rc1 = QueryAux->FieldByName("refComida1")->AsInteger;
   rc2 = QueryAux->FieldByName("refComida2")->AsInteger;
   rc3 = QueryAux->FieldByName("refComida3")->AsInteger;
   rc4 = QueryAux->FieldByName("refComida4")->AsInteger;
   rp = QueryAux->FieldByName("refProducto")->AsInteger;
   rmc = QueryAux->FieldByName("refMedioContacto")->AsInteger;
   oe = QueryAux->FieldByName("omitirEtiqueta")->AsInteger;
   cpc = QueryAux->FieldByName("comentarioParaCocina")->AsInteger;
   coment = QueryAux->FieldByName("comentario")->AsString;
   QueryAux->Close();

   for(int i=0; i < RG1->Items->Count; i++)
   {
	  if(arrIdComida[i] == rc1)
		 RG1->ItemIndex = i;
	  if(arrIdComida[i] == rc2)
		 RG2->ItemIndex = i;
	  if(arrIdComida[i] == rc3)
		 RG3->ItemIndex = i;
	  if(arrIdComida[i] == rc4)
		 RG4->ItemIndex = i;
   }

   cbRefProducto->ItemIndex = rp - 1;
   cbRefMedioContacto->ItemIndex = rmc - 1;

   if(oe == 0)
	  CBOmitirEtiqueta->Checked = false;
   else
	  CBOmitirEtiqueta->Checked = true;

   if(cpc == 0)
	  CBParaCocina->Checked = false;
   else
	  CBParaCocina->Checked = true;

   edComentario->Text = coment;


   if((rc1 != 1) && (RG1->ItemIndex == RG1->Items->Count - 1))
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = rc1;
	  QueryAux->Open();
	  Label4->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();

	  idOpEsp1 = rc1;
   }
   if((rc2 != 1) && (RG2->ItemIndex == RG2->Items->Count - 1))
   {
      QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = rc2;
	  QueryAux->Open();
	  Label5->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();

	  idOpEsp2 = rc2;
   }
   if((rc3 != 1) && (RG3->ItemIndex == RG3->Items->Count - 1))
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = rc3;
	  QueryAux->Open();
	  Label6->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();

	  idOpEsp3 = rc3;
   }
   if((rc4 != 1) && (RG4->ItemIndex == RG4->Items->Count - 1))
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = rc4;
	  QueryAux->Open();
	  Label7->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();

	  idOpEsp4 = rc4;
   }

   idOpEsp1Old = idOpEsp1;
   idOpEsp2Old = idOpEsp2;
   idOpEsp3Old = idOpEsp3;
   idOpEsp4Old = idOpEsp4;

   //actualizarInfoVentas();

   RG1->Enabled = true;
   RG2->Enabled = true;
   RG3->Enabled = true;
   RG4->Enabled = true;

   edComentario->Enabled = true;
   CBParaCocina->Enabled = true;
   CBOmitirEtiqueta->Enabled = true;
   cbRefMedioContacto->Enabled = true;
   cbRefProducto->Enabled = true;
   Label9->Enabled = true;
   Label17->Enabled = true;
   Label8->Enabled = true;

   vTimer1 = 0;
   Panel18->Visible = true;
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Eliminarestepedido1Click(TObject *Sender)
{
   if(Application->MessageBox(L"Realmente desea eliminar el registro seleccionado?",L"Eliminar registro?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   int id = ClientDataSet2->FieldByName("idPedido")->AsInteger;


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido = :id");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM pedidos WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();

   ClientDataSet2->Refresh();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refCantidad, COUNT(*) AS existe FROM pedidos WHERE (DATE(momento) = :f AND refCliente = :rc)");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idCliSel;
   QueryAux->Open();

   if(QueryAux->FieldByName("existe")->AsInteger == 0)
   {
	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("DELETE FROM cantidades WHERE (fecha = :f AND refCliente = :rc) LIMIT 1");
	  QueryAux->ParamByName("f")->AsDate = DTP->Date;
	  QueryAux->ParamByName("rc")->AsInteger = idCliSel;
	  QueryAux->ExecSQL();
   }
   else
   {
	  int idCantidad = QueryAux->FieldByName("refCantidad")->AsInteger;
	  QueryAux->Close();
	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("UPDATE cantidades SET nroUnidades = :cant, nroBandejas = :nb, txtComplemento = :txComp "
					   "WHERE idCantidad = :refCantidad");
	  Query1->ParamByName("refCantidad")->AsInteger = idCantidad;
	  Query1->ParamByName("cant")->AsString = comaToDot(edUnidades->Text);
	  Query1->ParamByName("nb")->AsString = edBandGrand->Text;
	  Query1->ParamByName("txComp")->AsString = generarCadComp();
	  Query1->ExecSQL();
   }

   actualizarInfoVentas();

   vTimer1 = 0;
   Panel18->Visible = true;
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button7Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   if(Application->MessageBox(L"Realmente desea eliminar TODOS LOS PEDIDOS de este cliente?",L"Eliminar pedido?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido IN (SELECT idPedido FROM pedidos WHERE (refCliente = :id AND DATE(momento) = :f))");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("id")->AsInteger = idCliSel;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM pedidos WHERE (refCliente = :id AND DATE(momento) = :f)");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("id")->AsInteger = idCliSel;
   QueryAux->ExecSQL();

   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("DELETE FROM cantidades WHERE (refCliente = :id AND fecha = :f) LIMIT 1");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("id")->AsInteger = idCliSel;
   QueryAux->ExecSQL();

   QueryPedidos->Close();
   ClientDataSet2->Active = false;

   actualizarInfoVentas();
   RestablecerFormulario();
   Beep();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::edUnidadesKeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
      Key = ',';
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::edBandGrandKeyPress(TObject *Sender, System::WideChar &Key)

{
   if(Key == '.')
   {
	  Key = NULL;
	  Beep();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button8Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   int ni = RG1->Items->Count - 1;


   if(cbRepartidor->ItemIndex == -1 || rgUbicacion->ItemIndex == -1)
   {
	  Application->MessageBox(L"Se debe indicar repartidor y/o sector de reparto.",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   if(RG1->ItemIndex == ni && RG2->ItemIndex == ni && RG3->ItemIndex == ni && RG4->ItemIndex == ni && idOpEsp1 < 2 && idOpEsp2 < 2 && idOpEsp3 < 2 && idOpEsp4 < 2)
   {
	  Application->MessageBox(L"No se puede agregar un pedido vac?o.",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  return;
   }

   bool sinComp = false;
   if(RG4->ItemIndex == ni && idOpEsp4 == 0 && edUnidades->Text.Pos(",00") > 0 && (StrToFloat(edUnidades->Text) == StrToFloat(edBandGrand->Text)))
   {
	  if(Application->MessageBox(L"Este pedido no tiene complemento, es correcto?",L"Verificar pedido",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
		 return;
	  sinComp = true;
   }

   if(!sinComp && edUnidades->Text.Pos(",00") > 0 && (StrToFloat(edUnidades->Text) == StrToFloat(edBandGrand->Text)))
   {
	  int j = 0;
	  if(RG1->ItemIndex == ni && idOpEsp1 == 0)
		 j++;
	  if(RG2->ItemIndex == ni && idOpEsp2 == 0)
		 j++;
	  if(RG3->ItemIndex == ni && idOpEsp3 == 0)
		 j++;
	  if(RG4->ItemIndex == ni && idOpEsp4 == 0)
		 j++;

	  if(j > 1)
		 if(Application->MessageBox(L"Este pedido tiene menos de las opciones habituales es correcto?",L"Verificar pedido",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			return;
   }



   DTP->Time = Now();
   int idCantidad = 0;


   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT idCantidad, COUNT(*) AS existe FROM cantidades WHERE (fecha = :d AND refCliente = :rc) LIMIT 1");
   Query1->ParamByName("d")->AsDate = DTP->Date;
   Query1->ParamByName("rc")->AsInteger = idCliSel;
   Query1->Open();

   bool existeCantidad;
   if(Query1->FieldByName("existe")->AsInteger == 0)
	  existeCantidad = false;
   else
   {
	  existeCantidad = true;
	  idCantidad = Query1->FieldByName("idCantidad")->AsInteger;
   }

   Query1->Close();
   Query1->SQL->Clear();

   if(!existeCantidad)
   {
	  Query1->SQL->Add("INSERT INTO cantidades VALUES (NULL, :d, :rc, :cant, :nb, :txComp, "
					   "(SELECT idRepartidor FROM repartidores WHERE descripcion = :rep LIMIT 1), :ubi, :cm)");
	  Query1->ParamByName("d")->AsDate = DTP->Date;
	  Query1->ParamByName("rc")->AsInteger = idCliSel;
	  Query1->ParamByName("cant")->AsString = comaToDot(edUnidades->Text);
	  Query1->ParamByName("nb")->AsString = edBandGrand->Text;
	  if(RG4->ItemIndex != RG4->Items->Count - 1)
		 Query1->ParamByName("txComp")->AsString = GetCodigo(arrIdComida[RG4->ItemIndex]);
	  else
		 Query1->ParamByName("txComp")->AsString = Label7->Caption;

	  Query1->ParamByName("rep")->AsString = cbRepartidor->Text;
	  Query1->ParamByName("ubi")->AsInteger = rgUbicacion->ItemIndex;

	  if(rgUbicacion->ItemIndex == oriRgUbiID && cbRepartidor->ItemIndex == oriCbRepID)
		 Query1->ParamByName("cm")->AsInteger = 0;
	  else
		 Query1->ParamByName("cm")->AsInteger = 1;

	  Query1->ExecSQL();

	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("SELECT MAX(idCantidad) FROM cantidades");
	  Query1->Open();
	  idCantidad = Query1->Fields->Fields[0]->AsInteger;
      Query1->Close();
   }

   int nroRec;
   bool modificado = false;
   if(modificandoPedido)
   {
      modificado = true;
      nroRec = ClientDataSet2->RecNo;
	  if(idOpEsp1Old != 0 && idOpEsp1Old != idOpEsp1)
	  {
		 Query1->Close();
		 Query1->SQL->Clear();
		 Query1->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido = :rp AND refComida = :refComida");
		 Query1->ParamByName("rp")->AsInteger = idMod;
		 Query1->ParamByName("refComida")->AsInteger = idOpEsp1Old;
		 Query1->ExecSQL();
	  }
	  if(idOpEsp2Old != 0 && idOpEsp1Old != idOpEsp2)
	  {
		 Query1->Close();
		 Query1->SQL->Clear();
		 Query1->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido = :rp AND refComida = :refComida");
		 Query1->ParamByName("rp")->AsInteger = idMod;
		 Query1->ParamByName("refComida")->AsInteger = idOpEsp2Old;
		 Query1->ExecSQL();
	  }
	  if(idOpEsp3Old != 0 && idOpEsp1Old != idOpEsp3)
	  {
		 Query1->Close();
		 Query1->SQL->Clear();
		 Query1->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido = :rp AND refComida = :refComida");
		 Query1->ParamByName("rp")->AsInteger = idMod;
		 Query1->ParamByName("refComida")->AsInteger = idOpEsp3Old;
		 Query1->ExecSQL();
	  }
	  if(idOpEsp4Old != 0 && idOpEsp1Old != idOpEsp4)
	  {
		 Query1->Close();
		 Query1->SQL->Clear();
		 Query1->SQL->Add("DELETE FROM comidasespeciales WHERE refPedido = :rp AND refComida = :refComida");
		 Query1->ParamByName("rp")->AsInteger = idMod;
		 Query1->ParamByName("refComida")->AsInteger = idOpEsp4Old;
		 Query1->ExecSQL();
	  }

	  bool pedidoEspecial = false;

	  Query1->Close();
	  Query1->SQL->Clear();                //momento = :dt,
	  Query1->SQL->Add("UPDATE pedidos SET refProducto = :rp, refComida1 = :rc1, refComida2 = :rc2, refComida3 = :rc3, "
					   "refComida4 = :rc4, refMedioContacto = :rmc, comentario =  :com, omitirEtiqueta = :oe, "
					   "etiquetaImpresa = 0, complementoImpreso = 0, comentarioParaCocina = :cpc WHERE(idPedido = :idP) LIMIT 1");

	  Query1->ParamByName("rp")->AsInteger = cbRefProducto->ItemIndex + 1;

	  if(RG1->ItemIndex == ni && idOpEsp1 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc1")->AsInteger = idOpEsp1;
	  }
	  else
		 Query1->ParamByName("rc1")->AsInteger = arrIdComida[RG1->ItemIndex];

	  if(RG2->ItemIndex == ni && idOpEsp2 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc2")->AsInteger = idOpEsp2;
	  }
	  else
		 Query1->ParamByName("rc2")->AsInteger = arrIdComida[RG2->ItemIndex];

	  if(RG3->ItemIndex == ni && idOpEsp3 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc3")->AsInteger = idOpEsp3;
	  }
	  else
		 Query1->ParamByName("rc3")->AsInteger = arrIdComida[RG3->ItemIndex];

	  if(RG4->ItemIndex == ni && idOpEsp4 > 1)
	  {
	     pedidoEspecial = true;
		 Query1->ParamByName("rc4")->AsInteger = idOpEsp4;
	  }
	  else
		 Query1->ParamByName("rc4")->AsInteger = arrIdComida[RG4->ItemIndex];

	  Query1->ParamByName("rmc")->AsInteger = cbRefMedioContacto->ItemIndex + 1;
	  Query1->ParamByName("com")->AsString = edComentario->Text;
	  Query1->ParamByName("idP")->AsInteger = idMod;
	  if(CBOmitirEtiqueta->Checked)
		 Query1->ParamByName("oe")->AsInteger = 1;
	  else
		 Query1->ParamByName("oe")->AsInteger = 0;

	  if(CBParaCocina->Checked)
		 Query1->ParamByName("cpc")->AsInteger = 1;
	  else
		 Query1->ParamByName("cpc")->AsInteger = 0;

	  Query1->ExecSQL();

	  if(pedidoEspecial)
	  {
		 if(RG1->ItemIndex == ni && idOpEsp1 > 1 && idOpEsp1 != idOpEsp1Old)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp1;
			Query1->ParamByName("rp")->AsInteger = idMod;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG2->ItemIndex == ni && idOpEsp2 > 1 && idOpEsp2 != idOpEsp2Old)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp2;
			Query1->ParamByName("rp")->AsInteger = idMod;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG3->ItemIndex == ni && idOpEsp3 > 1 && idOpEsp3 != idOpEsp3Old)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp3;
			Query1->ParamByName("rp")->AsInteger = idMod;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG4->ItemIndex == ni && idOpEsp4 > 1 && idOpEsp4 != idOpEsp4Old)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp4;
			Query1->ParamByName("rp")->AsInteger = idMod;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
	     }
	  }

	  modificandoPedido = false;
   }
   else
   {
	  bool pedidoEspecial = false;

	  Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("INSERT INTO pedidos VALUES (NULL, :dt, :rc, :rp, :rc1, :rc2, :rc3, :rc4, :rmc, 1, :com, :oe, 0, :refCantidad, 0, :cpc)");
	  Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
	  Query1->ParamByName("rc")->AsInteger = idCliSel;
	  Query1->ParamByName("rp")->AsInteger = cbRefProducto->ItemIndex + 1;
      Query1->ParamByName("refCantidad")->AsInteger = idCantidad;

	  if(RG1->ItemIndex == ni && idOpEsp1 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc1")->AsInteger = idOpEsp1;
	  }
	  else
		 Query1->ParamByName("rc1")->AsInteger = arrIdComida[RG1->ItemIndex];

	  if(RG2->ItemIndex == ni && idOpEsp2 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc2")->AsInteger = idOpEsp2;
	  }
	  else
		 Query1->ParamByName("rc2")->AsInteger = arrIdComida[RG2->ItemIndex];

	  if(RG3->ItemIndex == ni && idOpEsp3 > 1)
	  {
		 pedidoEspecial = true;
		 Query1->ParamByName("rc3")->AsInteger = idOpEsp3;
	  }
	  else
		 Query1->ParamByName("rc3")->AsInteger = arrIdComida[RG3->ItemIndex];

	  if(RG4->ItemIndex == ni && idOpEsp4 > 1)
	  {
	     pedidoEspecial = true;
		 Query1->ParamByName("rc4")->AsInteger = idOpEsp4;
	  }
	  else
		 Query1->ParamByName("rc4")->AsInteger = arrIdComida[RG4->ItemIndex];

	  Query1->ParamByName("rmc")->AsInteger = cbRefMedioContacto->ItemIndex + 1;
	  Query1->ParamByName("com")->AsString = edComentario->Text;
	  if(CBOmitirEtiqueta->Checked)
		 Query1->ParamByName("oe")->AsInteger = 1;
	  else
		 Query1->ParamByName("oe")->AsInteger = 0;

	  if(CBParaCocina->Checked)
		 Query1->ParamByName("cpc")->AsInteger = 1;
	  else
		 Query1->ParamByName("cpc")->AsInteger = 0;

	  Query1->ExecSQL();

	  if(pedidoEspecial)
	  {
		 Query1->Close();
		 Query1->SQL->Clear();
		 Query1->SQL->Add("SELECT MAX(idPedido) FROM pedidos");
		 Query1->Open();
		 int id = Query1->Fields->Fields[0]->AsInteger;
		 Query1->Close();

		 if(RG1->ItemIndex == ni && idOpEsp1 > 1)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp1;
			Query1->ParamByName("rp")->AsInteger = id;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG2->ItemIndex == ni && idOpEsp2 > 1)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp2;
			Query1->ParamByName("rp")->AsInteger = id;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG3->ItemIndex == ni && idOpEsp3 > 1)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp3;
			Query1->ParamByName("rp")->AsInteger = id;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
		 }

		 if(RG4->ItemIndex == ni && idOpEsp4 > 1)
		 {
			Query1->Close();
			Query1->SQL->Clear();
			Query1->SQL->Add("INSERT INTO comidasespeciales (refPedido, refComida, refEstadoPedido, ordenReparto, marcaTiempo) "
							 "VALUES (:rp, :idComEsp, 1, :or, :dt)");
			Query1->ParamByName("dt")->AsDateTime = DTP->DateTime;
			Query1->ParamByName("idComEsp")->AsInteger = idOpEsp4;
			Query1->ParamByName("rp")->AsInteger = id;
            Query1->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
			Query1->ExecSQL();
	     }
	  }

   }

   ClientDataSet2->Refresh();

   if(existeCantidad)
   {
      Query1->Close();
	  Query1->SQL->Clear();
	  Query1->SQL->Add("UPDATE cantidades SET nroUnidades = :cant, nroBandejas = :nb, txtComplemento = :txComp "
					   "WHERE (idCantidad = :id) LIMIT 1");
	  Query1->ParamByName("id")->AsInteger = idCantidad;
	  Query1->ParamByName("cant")->AsString = comaToDot(edUnidades->Text);
	  Query1->ParamByName("nb")->AsString = edBandGrand->Text;
	  Query1->ParamByName("txComp")->AsString = generarCadComp();
	  Query1->ExecSQL();
   }

   lbComplementos->Caption = generarCadComp();


   RG1->ItemIndex = RG1->Items->Count - 1;
   RG2->ItemIndex = RG1->Items->Count - 1;
   RG3->ItemIndex = RG1->Items->Count - 1;
   RG4->ItemIndex = RG1->Items->Count - 1;

   idOpEsp1 = 0;
   idOpEsp2 = 0;
   idOpEsp3 = 0;
   idOpEsp4 = 0;

   Label4->Caption = "";
   Label5->Caption = "";
   Label6->Caption = "";
   Label7->Caption = "";

   modificandoPedido = false;
   idMod = 0;
   cargandoOpciones = false;
   CBOmitirEtiqueta->Checked = false;
   CBParaCocina->Checked = false;
   edComentario->Text = "";
   cbRefProducto->ItemIndex = 0;
   cbRefMedioContacto->ItemIndex = 0;

   if(Sender != Button1)
   {
	  edUnidades->Text = FormatFloat("0.00", StrToFloat(edUnidades->Text) + 1.0);
	  edBandGrand->Text = IntToStr(StrToInt(edBandGrand->Text) + 1);
   }

   if(modificado)
	  ClientDataSet2->RecNo = nroRec;

   Button27->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button1Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   Button8Click(Button1);



   cargandoPedido = false;
   Button27->Enabled = false;

   actualizarInfoVentas();

   DBGrid1->Enabled = true;
   DBGrid1->Repaint();

   Edit1->Enabled = true;
   Button9->Enabled = true;
   Edit1->SetFocus();
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
	if(Button == btNext)
	{
	   float aux;
	   aux = StrToFloat(edUnidades->Text);
	   aux = aux + 0.25;
	   edUnidades->Text = FormatFloat("0.00",aux);


	   if(edUnidades->Text.Pos(",00") > 0)
		  edBandGrand->Text = edUnidades->Text.SubString(1,edUnidades->Text.Pos(",")-1);
	   else if(edUnidades->Text == "1,50" || edUnidades->Text == "1,75")
		  edBandGrand->Text = "2";
	   else if(edUnidades->Text == "2,25")
		  edBandGrand->Text = "3";
	}
	else
	{
	   float aux;
	   aux = StrToFloat(edUnidades->Text);
	   if(aux > 0.2)
	   {
		  aux = aux - 0.25;
		  edUnidades->Text = FormatFloat("0.00",aux);
	   }

	   if(edUnidades->Text.Pos(",00") > 0)
		  edBandGrand->Text = edUnidades->Text.SubString(1,edUnidades->Text.Pos(",")-1);
	   else if(edUnidades->Text == "1,50" || edUnidades->Text == "1,75")
		  edBandGrand->Text = "2";
	   else if(edUnidades->Text == "2,25")
		  edBandGrand->Text = "3";
	}
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
   if(Button == btNext)
	{
	   int aux;
	   aux = StrToInt(edBandGrand->Text);
	   aux = aux + 1;
       edBandGrand->Text = IntToStr(aux);
	}
	else
	{
	   int aux;
	   aux = StrToInt(edBandGrand->Text);
	   if(aux > 0)
	   {
		  aux = aux - 1;
		  edBandGrand->Text = IntToStr(aux);
       }
	}
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::FormClose(TObject *Sender, TCloseAction &Action)
{
   if(!puedeSalir)
   {
      Action = caNone;
	  return;
   }

   if(cargandoPedido)
   {
	  Application->MessageBox(L"Antes de salir debe finalizar o cancelar el pedido en curso" ,L"No se puede salir..",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  Action = caNone;
	  return;
   }
   Timer1->Enabled = false;
   Timer3->Enabled = false;

   ClientDataSet3->Active = false;
   CDSEtiquetas->Active = false;
   CDSEtiquetasComp->Active = false;
   ClientDataSet2->Active = false;

   Query1->Close();
   QueryAux->Close();
   QueryCliente->Close();
   QueryComida->Close();
   QueryEtiquetas->Close();
   QueryEtiquetasComp->Close();
   QueryGenCad->Close();
   QueryInfo->Close();
   QueryPedidos->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Image1Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   if(RG1->ItemIndex == RG1->Items->Count - 1)
   {
	  fSeleccionarComida->ShowModal();

	  if(fSeleccionarComida->idSeleccionado <= 1)
		 return;

	  idOpEsp1 = fSeleccionarComida->idSeleccionado;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = fSeleccionarComida->idSeleccionado;
	  QueryAux->Open();
	  Label4->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Image2Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   if(RG2->ItemIndex == RG2->Items->Count - 1)
   {
	  fSeleccionarComida->ShowModal();

	  if(fSeleccionarComida->idSeleccionado <= 1)
		 return;

	  idOpEsp2 = fSeleccionarComida->idSeleccionado;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = fSeleccionarComida->idSeleccionado;
	  QueryAux->Open();
	  Label5->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Image3Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   if(RG3->ItemIndex == RG3->Items->Count - 1)
   {
	  fSeleccionarComida->ShowModal();
	  if(fSeleccionarComida->idSeleccionado <= 1)
		 return;

	  idOpEsp3 = fSeleccionarComida->idSeleccionado;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = fSeleccionarComida->idSeleccionado;
	  QueryAux->Open();
	  Label6->Caption = QueryAux->FieldByName("codigo")->AsString;
	  QueryAux->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Image4Click(TObject *Sender)
{
   if(idCliSel < 3)
	  return;

   if(RG4->ItemIndex == RG4->Items->Count - 1)
   {
	  fSeleccionarComida->ShowModal();

	  if(fSeleccionarComida->idSeleccionado <= 1)
		 return;

	  idOpEsp4 = fSeleccionarComida->idSeleccionado;

	  QueryAux->Close();
	  QueryAux->SQL->Clear();
	  QueryAux->SQL->Add("SELECT codigo FROM comidas WHERE idComida = :id LIMIT 1");
	  QueryAux->ParamByName("id")->AsInteger = fSeleccionarComida->idSeleccionado;
	  QueryAux->Open();
	  Label7->Caption = QueryAux->FieldByName("codigo")->AsString;
      QueryAux->Close();
   }
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Edit1Change(TObject *Sender)
{
   ClientDataSet3->Active = false;

   if(Edit1->Text.Length() >= 3 || Sender == Button20)
   {
      String q;

	  q = "SELECT idCliente, calle, numero, acumuladoGlobal, (acumuladoGlobal - acumuladoParcial) AS deuda, "
		  "(SELECT descripcion FROM repartidores WHERE repartidores.idRepartidor = (SELECT refRepartidor FROM repartos WHERE (repartos.esSabado = :esSab AND repartos.refCliente = clientes.idCliente) LIMIT 1) LIMIT 1) AS Repartidor, "
		  "(SELECT posicion FROM repartos WHERE (repartos.refCliente = clientes.idCliente AND esSabado = :esSab) LIMIT 1) AS pos, "
		  "(SELECT posicion FROM repartos WHERE (repartos.refRepartidor = (SELECT refRepartidor FROM repartos WHERE (repartos.refCliente = clientes.idCliente AND esSabado = :esSab) LIMIT 1) AND refCliente = 1 AND esSabado = :esSab) LIMIT 1) AS division "
		  "FROM clientes WHERE(UPPER(numero) LIKE :v AND idCliente > 2 AND esVisible = 1 AND (SELECT COUNT(*) FROM repartos WHERE (repartos.refCliente = clientes.idCliente AND repartos.esSabado = :esSab) LIMIT 1) > 0) ORDER BY numero LIMIT 7"; //selecciona 7 por vez

	  QueryCliente->Close();
	  QueryCliente->SQL->Clear();
	  QueryCliente->SQL->Add(q);
	  QueryCliente->ParamByName("v")->AsString = "%" + Edit1->Text.UpperCase() + "%";

	  if(DayOfTheWeek(DTP->Date) == 6)
		 QueryCliente->ParamByName("esSab")->AsInteger = 1;
	  else
	     QueryCliente->ParamByName("esSab")->AsInteger = 0;

	  QueryCliente->Open();
	  ClientDataSet3->Active = true;
      ShowScrollBar(DBGrid2->Handle, SB_VERT, true);

	  if(ClientDataSet3->RecordCount == 1)
	  {
		 //--------------------------CARGA PLANILLA Y UBICACION POR DEFECTO
		 cbRepartidor->ItemIndex = 0;
		 while(1)
		 {
			if(cbRepartidor->Text == ClientDataSet3->FieldByName("Repartidor")->AsString)
			   break;
			else
			{
			   if(cbRepartidor->ItemIndex == cbRepartidor->Items->Count - 1)
				  break;

			   cbRepartidor->ItemIndex++;
			}
		 }

		 if(ClientDataSet3->FieldByName("pos")->AsInteger < ClientDataSet3->FieldByName("division")->AsInteger)
			rgUbicacion->ItemIndex = 0;
		 else
			rgUbicacion->ItemIndex = 1;


		 oriRgUbiID = rgUbicacion->ItemIndex;   //GUARDA UBICACIONES ORIGINALES
		 oriCbRepID = cbRepartidor->ItemIndex;

		 //-----------------------------------------------------------------

		 idCliSel = ClientDataSet3->FieldByName("idCliente")->AsInteger;
		 verClienteSeleccionado(idCliSel);

		 if(ClientDataSet3->FieldByName("deuda")->AsFloat == 0 || ClientDataSet3->FieldByName("acumuladoGlobal")->AsFloat == 0)
		 {
			Label18->Caption = "No presenta deudas";
			Label18->Font->Color = clGreen;
		 }
		 else if(ClientDataSet3->FieldByName("deuda")->AsFloat > 0)
		 {
			Label18->Caption = FormatFloat("Deuda: $ 0.00", ClientDataSet3->FieldByName("deuda")->AsFloat);
			Label18->Font->Color = clRed;
		 }
		 else
		 {
			Label18->Caption = FormatFloat("Saldo a favor: $ 0.00", -1.0 * ClientDataSet3->FieldByName("deuda")->AsFloat);
			Label18->Font->Color = clBlue;
		 }

		 rgUbicacion->Enabled = true;
         cbRepartidor->Enabled = true;
	  }
	  else
	  {
	     Label18->Caption = "";
		 idCliSel = 0;
		 rgUbicacion->ItemIndex = -1;
		 cbRepartidor->ItemIndex = -1;
		 rgUbicacion->Enabled = false;
		 cbRepartidor->Enabled = false;
         lbComplementos->Caption = "";
		 ClientDataSet2->Active = false;
		 QueryPedidos->Close();

		 RG1->Enabled = false;
		 RG2->Enabled = false;
		 RG3->Enabled = false;
		 RG4->Enabled = false;

		 edComentario->Enabled = false;
		 CBParaCocina->Enabled = false;
		 CBOmitirEtiqueta->Enabled = false;
		 cbRefMedioContacto->Enabled = false;
		 cbRefProducto->Enabled = false;
		 Label9->Enabled = false;
		 Label17->Enabled = false;
		 Label8->Enabled = false;

		 RG1->ItemIndex = RG1->Items->Count - 1;
		 RG2->ItemIndex = RG1->Items->Count - 1;
		 RG3->ItemIndex = RG1->Items->Count - 1;
		 RG4->ItemIndex = RG1->Items->Count - 1;


		 DBGrid2->Enabled = true;
		 DBGrid1->Enabled = false;
	  }

   }
   else
   {
	  ClientDataSet3->Active = false;
	  QueryCliente->Close();
	  ClientDataSet2->Active = false;
	  QueryPedidos->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid2DblClick(TObject *Sender)
{
   //--------------------------CARGA PLANILLA Y UBICACION POR DEFECTO
   cbRepartidor->ItemIndex = 0;
   while(1)
   {
	  if(cbRepartidor->Text == ClientDataSet3->FieldByName("Repartidor")->AsString)
		 break;
	  else
	  {
		 if(cbRepartidor->ItemIndex == cbRepartidor->Items->Count - 1)
			break;

		 cbRepartidor->ItemIndex++;
	  }
   }

   if(ClientDataSet3->FieldByName("pos")->AsInteger < ClientDataSet3->FieldByName("division")->AsInteger)
	  rgUbicacion->ItemIndex = 0;
   else
	  rgUbicacion->ItemIndex = 1;

   rgUbicacion->Enabled = true;
   cbRepartidor->Enabled = true;

   oriRgUbiID = rgUbicacion->ItemIndex;   //GUARDA UBICACIONES ORIGINALES
   oriCbRepID = cbRepartidor->ItemIndex;

   //-----------------------------------------------------------------


   idCliSel = ClientDataSet3->FieldByName("idCliente")->AsInteger;
   verClienteSeleccionado(idCliSel);

     if(ClientDataSet3->FieldByName("deuda")->AsFloat == 0)
	 {
		Label18->Caption = "No presenta deudas";
		Label18->Font->Color = clGreen;
	 }
	 else if(ClientDataSet3->FieldByName("deuda")->AsFloat > 0)
	 {
		Label18->Caption = FormatFloat("Deuda: $ 0.00", ClientDataSet3->FieldByName("deuda")->AsFloat);
		Label18->Font->Color = clRed;
	 }
	 else
	 {
		Label18->Caption = FormatFloat("Saldo a favor: $ 0.00", -1.0 * ClientDataSet3->FieldByName("deuda")->AsFloat);
		Label18->Font->Color = clBlue;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button10Click(TObject *Sender)
{
   if(idCliSel < 3)
      return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE cantidades SET refRepartidor = (SELECT idRepartidor FROM repartidores WHERE descripcion = :rep LIMIT 1), "
					  "sectorReparto = :sr, cargaManual = :cm WHERE(fecha = :d AND refCliente = :rc) LIMIT 1");
   QueryAux->ParamByName("d")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idCliSel;
   QueryAux->ParamByName("rep")->AsString = cbRepartidor->Text;
   QueryAux->ParamByName("sr")->AsInteger = rgUbicacion->ItemIndex;

   if(cbRepartidor->ItemIndex != oriCbRepID || rgUbicacion->ItemIndex != oriRgUbiID)
	  QueryAux->ParamByName("cm")->AsInteger = 1;  //si alguno de los parametros no son los originales, entonces
   else                                            //debera cargarse en la planilla de forma manual
	  QueryAux->ParamByName("cm")->AsInteger = 0;

   QueryAux->ExecSQL();


   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE comidasespeciales SET ordenReparto = :or WHERE refPedido IN (SELECT idPedido FROM pedidos WHERE (refCliente = :id AND DATE(momento) = :f))");
   QueryAux->ParamByName("f")->AsDate = DTP->Date;
   QueryAux->ParamByName("id")->AsInteger = idCliSel;
   QueryAux->ParamByName("or")->AsInteger = rgUbicacion->ItemIndex;
   QueryAux->ExecSQL();


   Beep();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button9Click(TObject *Sender)
{
   String filtro = Edit1->Text;
   Edit1->Clear();
   cbRepartidor->ItemIndex = -1;
   rgUbicacion->ItemIndex = -1;
   lbComplementos->Caption = "";
   Label18->Caption = "";


   fSeleccionarCliente->llamador = 1;
   if(filtro.Length() > 2)
   {
	  fSeleccionarCliente->precargar = true;
	  fSeleccionarCliente->filtro = filtro;
   }
   else
	  fSeleccionarCliente->precargar = false;

   fSeleccionarCliente->ShowModal();

   if(fSeleccionarCliente->idSeleccionado > 2)
   {
	  idCliSel = fSeleccionarCliente->idSeleccionado;
	  ClientDataSet3->Active = false;
	  QueryCliente->Close();
	  QueryCliente->SQL->Clear();
	  QueryCliente->SQL->Add("SELECT calle, numero, acumuladoGlobal, (acumuladoGlobal - acumuladoParcial) as deuda FROM clientes WHERE idCliente = :idc LIMIT 1");
	  QueryCliente->ParamByName("idc")->AsInteger = idCliSel;
	  QueryCliente->Open();
	  ClientDataSet3->Active = true;

	  oriRgUbiID = -1;   //estos serian los valores originales que nunca van a coincidir con los que se seleccionan despues
	  oriCbRepID = -1;   //de esta forma el campo "cargaManual" siempre se va a marcar como verdadero en los clientes no habituales

	  verClienteSeleccionado(idCliSel);

	  if(ClientDataSet3->FieldByName("deuda")->AsFloat == 0 || ClientDataSet3->FieldByName("acumuladoGlobal")->AsFloat == 0)
	  {
		 Label18->Caption = "No presenta deudas";
		 Label18->Font->Color = clGreen;
	  }
	  else if(ClientDataSet3->FieldByName("deuda")->AsFloat > 0)
	  {
		 Label18->Caption = FormatFloat("Deuda: $ 0.00", ClientDataSet3->FieldByName("deuda")->AsFloat);
		 Label18->Font->Color = clRed;
	  }
	  else
	  {
		 Label18->Caption = FormatFloat("Saldo a favor: $ 0.00", -1.0 * ClientDataSet3->FieldByName("deuda")->AsFloat);
		 Label18->Font->Color = clBlue;
	  }

	  if(cbRepartidor->ItemIndex == -1 || rgUbicacion->ItemIndex == -1)
	  {
		 vTimer2 = 0;
		 rgUbicacion->ParentBackground = false;
		 Panel19->Visible = true;
		 Timer2->Enabled = true;
	  }

	  rgUbicacion->Enabled = true;
      cbRepartidor->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button3Click(TObject *Sender)
{
   Button3->Enabled = false;
   Button4->Enabled = false;
   Button17->Enabled = false;
   puedeSalir = false;

   contLineasImpresas = 0;
   cantLineas = StrToInt(Edit2->Text);
   imprimirEtiquetas(0);

   Button3->Enabled = true;
   Button4->Enabled = true;
   Button17->Enabled = true;
   puedeSalir = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit1Click(TObject *Sender)
{
   Edit1->SelectAll();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button5Click(TObject *Sender)
{
   Panel10->Visible = false;

   procesoImpresionEtiquetasPedidos(llamadorAux);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button6Click(TObject *Sender)
{
   Panel10->Visible = false;
   CDSEtiquetas->Active = false;
   QueryEtiquetas->Close();
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button4Click(TObject *Sender)
{
   Button3->Enabled = false;
   Button4->Enabled = false;
   Button17->Enabled = false;
   puedeSalir = false;

   contLineasImpresas = 0;
   cantLineas = StrToInt(Edit2->Text);
   imprimirEtiquetas(1);

   Button3->Enabled = true;
   Button4->Enabled = true;
   Button17->Enabled = true;
   puedeSalir = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
	  Edit2->Enabled = true;
   else
      Edit2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Agregaracoladeimpresin1Click(TObject *Sender)
{
   int id = ClientDataSet2->FieldByName("idPedido")->AsInteger;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET etiquetaImpresa = 0 WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();
   ClientDataSet2->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Marcarcomoimpresa1Click(TObject *Sender)
{
   int id = ClientDataSet2->FieldByName("idPedido")->AsInteger;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET etiquetaImpresa = 1 WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();
   ClientDataSet2->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Mandaraimprimirestaetiqueta1Click(TObject *Sender)
{
	if (getImpresoraEtiquetas() != "NO_CONFIGURADA") {
		frxReport1->PrintOptions->Printer = getImpresoraEtiquetas();
	}
	else return;


	String q;

	q = "SELECT comentario, refComida1, refComida2, refComida3, comentarioParaCocina, "

		"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (refComida1 = comidas.idComida) LIMIT 1) AS c1, "
		"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (refComida2 = comidas.idComida) LIMIT 1) AS c2, "
		"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (refComida3 = comidas.idComida) LIMIT 1) AS c3, "
		"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS c4, "

		"(SELECT refRepartidor FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS refRep, "
		"(SELECT sectorReparto + 1 FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS salidaRep, "

		"(SELECT UPPER(SUBSTRING(descripcion, 1, 4)) FROM repartidores WHERE (repartidores.idRepartidor = refRep) LIMIT 1) AS Repartidor, "

		"(SELECT numero FROM clientes WHERE (refCliente = clientes.idCliente) LIMIT 1) AS Numero "

		"FROM pedidos WHERE idPedido = :idP";


	QueryAux->Close();
	QueryAux->SQL->Clear();
	QueryAux->SQL->Add(q);
	QueryAux->ParamByName("idP")->AsInteger = ClientDataSet2->FieldByName("idPedido")->AsInteger;
	QueryAux->ParamByName("una")->AsString = una;
	QueryAux->ParamByName("ens")->AsString = ens;
	QueryAux->Open();


	int refComida1, refComida2, refComida3, nroApaAnt;
	String c1, c2, c3, c4, comentario, cliente, repartidor, nroReparto;
	bool c1Esp, c2Esp, c3Esp;
	bool comentarioEsp;


	c1 = QueryAux->FieldByName("c1")->AsString;
	c2 = QueryAux->FieldByName("c2")->AsString;
	c3 = QueryAux->FieldByName("c3")->AsString;
	c4 = QueryAux->FieldByName("c4")->AsString;
	comentario = QueryAux->FieldByName("comentario")->AsString;
	cliente = QueryAux->FieldByName("Numero")->AsString;
	repartidor = QueryAux->FieldByName("Repartidor")->AsString;
	nroReparto = QueryAux->FieldByName("salidaRep")->AsString;

	refComida1 = QueryAux->FieldByName("refComida1")->AsInteger;
	refComida2 = QueryAux->FieldByName("refComida2")->AsInteger;
	refComida3 = QueryAux->FieldByName("refComida3")->AsInteger;

	c1Esp = esOpcionEspecial(refComida1);
	c2Esp = esOpcionEspecial(refComida2);
	c3Esp = esOpcionEspecial(refComida3);

	comentarioEsp = false;
	if(QueryAux->FieldByName("comentarioParaCocina")->AsInteger != 0)
	  comentarioEsp = true;


	completarEtiquetaPedido(c1, c2, c3, c4, cliente, repartidor, nroReparto,
							  comentario, true, c1Esp, c2Esp, c3Esp,
							  comentarioEsp, false);

	completarEtiquetaPedido("", "", "", "", "", "", "",
							"", false, false, false, false,
							false, true);


	frxReport1->PrepareReport(true);
	frxReport1->Print();

	QueryAux->Close();

}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button11Click(TObject *Sender)
{
   if(idCliSel > 2)
   {
	  fCuentas->idCliente = idCliSel;
	  fCuentas->ShowModal();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verdescripcion1Click(TObject *Sender)
{
   if(RGTexto->ItemIndex == RGTexto->Items->Count - 1)
	  return;

   QueryComida->Close();
   QueryComida->SQL->Clear();
   QueryComida->SQL->Add("SELECT descripcion FROM comidas WHERE idComida = :idComida");
   QueryComida->ParamByName("idComida")->AsInteger = arrIdComida[RGTexto->ItemIndex];
   QueryComida->Open();


   Memo1->Clear();
   Memo1->Lines->Add("*" + opciones[RGTexto->ItemIndex] + ":*");
   Memo1->Lines->Add(QueryComida->FieldByName("descripcion")->AsString);

   Panel11->Left = (fPedidos->Width - Panel11->Width) / 2;
   Panel11->Top = (fPedidos->Height - Panel11->Height) / 2;
   Panel11->Visible = true;

   blockRGTexto = true;
   RGTexto->ItemIndex =  RGTexto->Items->Count - 1;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RGTextoClick(TObject *Sender)
{
   if(blockRGTexto)
   {
	  blockRGTexto = false;
	  return;
   }

   if(!cargandoOpciones)
   {
	  TPoint *Puntero;
	  Puntero = new TPoint();
	  GetCursorPos(Puntero);
	  PopupMenu2->Popup(Puntero->X, Puntero->Y);
      delete Puntero;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button12Click(TObject *Sender)
{
   Panel11->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button13Click(TObject *Sender)
{
   Memo1->SelectAll();
   Memo1->CopyToClipboard();
   Panel11->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG1Click(TObject *Sender)
{
   if(!cargandoOpciones)
   {
	  Edit1->Enabled = false;
	  Button9->Enabled = false;
	  DBGrid2->Enabled = false;
	  DBGrid1->Enabled = false;
	  cargandoPedido = true;
	  if(!ClientDataSet2->IsEmpty())
		 Button27->Enabled = true;
   }

   if(RG1->ItemIndex != RG1->Items->Count - 1)
      Label4->Caption = "";
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG2Click(TObject *Sender)
{
   if(!cargandoOpciones)
   {
	  Edit1->Enabled = false;
	  Button9->Enabled = false;
	  DBGrid2->Enabled = false;
	  DBGrid1->Enabled = false;
	  cargandoPedido = true;
	  if(!ClientDataSet2->IsEmpty())
		 Button27->Enabled = true;

	  if(RG2->ItemIndex != RG2->Items->Count - 1)
		 Label5->Caption = "";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG3Click(TObject *Sender)
{
   if(!cargandoOpciones)
   {
	  Edit1->Enabled = false;
	  Button9->Enabled = false;
	  DBGrid2->Enabled = false;
	  DBGrid1->Enabled = false;
	  cargandoPedido = true;
	  if(!ClientDataSet2->IsEmpty())
		 Button27->Enabled = true;

	  if(RG3->ItemIndex != RG3->Items->Count - 1)
		 Label6->Caption = "";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG4Click(TObject *Sender)
{
   if(!cargandoOpciones)
   {
	  Edit1->Enabled = false;
	  Button9->Enabled = false;
	  DBGrid2->Enabled = false;
	  DBGrid1->Enabled = false;
	  cargandoPedido = true;
	  if(!ClientDataSet2->IsEmpty())
		 Button27->Enabled = true;

	  if(RG4->ItemIndex != RG4->Items->Count - 1)
		 Label7->Caption = "";
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button15Click(TObject *Sender)
{
   if(Application->MessageBox(L"Se va a cancelar el pedido actual, desea continuar?" ,L"Cancelar este peddido?",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) == IDYES)
   {
	  modificandoPedido = false;
	  cargandoOpciones = false;
	  cargandoPedido = false;
	  Button27->Enabled = false;
	  puedeSalir = true;

	  idMod = 0;

	  cbRefProducto->ItemIndex = 0;
	  cbRefMedioContacto->ItemIndex = 0;
	  CBOmitirEtiqueta->Checked = false;
	  edComentario->Text = "";

	  idOpEsp1 = 0;
	  idOpEsp2 = 0;
	  idOpEsp3 = 0;
	  idOpEsp4 = 0;
	  Label4->Caption = "";
	  Label5->Caption = "";
	  Label6->Caption = "";
	  Label7->Caption = "";

	  actualizarInfoVentas();

	  RG1->ItemIndex = RG1->Items->Count - 1;
	  RG2->ItemIndex = RG1->Items->Count - 1;
	  RG3->ItemIndex = RG1->Items->Count - 1;
      RG4->ItemIndex = RG1->Items->Count - 1;

	  DBGrid1->Enabled = true;
	  DBGrid1->Repaint();

	  Edit1->Enabled = true;
	  Button9->Enabled = true;
	  Edit1->SetFocus();
	  Edit1->SelectAll();

   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DTPEnter(TObject *Sender)
{
   fechaPrevia = DTP->DateTime;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DTPExit(TObject *Sender)
{
   if(cargandoPedido)
	  DTP->DateTime = fechaPrevia;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button14Click(TObject *Sender)
{
   fVerCargaManual->MC->Date = DTP->Date;
   fVerCargaManual->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::ListBox1DblClick(TObject *Sender)
{
   if(ListBox1->Items->Count < 1)
	  return;
   if(ListBox1->ItemIndex < 0)
      return;

   String n = ListBox1->Items->Strings[ListBox1->ItemIndex];
   n = n.SubString(1,n.Pos(" x "));

   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add("SELECT CONCAT(calle, ' ',numero) AS cliente FROM clientes WHERE idCliente IN (SELECT refCliente FROM pedidos WHERE DATE(momento) = :f AND("
					   "refComida1 = (SELECT idComida FROM comidas WHERE nombre = :n LIMIT 1) "
					   "OR refComida2 = (SELECT idComida FROM comidas WHERE nombre = :n LIMIT 1) "
					   "OR refComida3 = (SELECT idComida FROM comidas WHERE nombre = :n LIMIT 1) "
					   "OR refComida4 = (SELECT idComida FROM comidas WHERE nombre = :n LIMIT 1)))");
   QueryInfo->ParamByName("f")->AsDate = DTP->Date;
   QueryInfo->ParamByName("n")->AsString = n;
   QueryInfo->Open();

   ListBox2->Clear();
   QueryInfo->First();
   while(!QueryInfo->Eof)
   {
      ListBox2->Items->Add(QueryInfo->FieldByName("cliente")->AsString);
	  QueryInfo->Next();
   }
   QueryInfo->Close();

   Panel16->Visible = true;;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button16Click(TObject *Sender)
{
   Panel16->Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Configurarunaalarma1Click(TObject *Sender)
{
   fConfigurarAlarma->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::FormCanResize(TObject *Sender, int &NewWidth, int &NewHeight,
          bool &Resize)
{
   Resize = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Imprimirplanillasderepartos1Click(TObject *Sender)
{
   fImprimirPlanillas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Modificardatosdeuncliente1Click(TObject *Sender)
{
   if(idCliSel <= 2)
	  return;

   fModificarCliente->Show();

   fModificarCliente->Frame11->id = idCliSel;
   fModificarCliente->Frame21->cerrarFrame();
   fModificarCliente->Frame21->Enabled = false;
   fModificarCliente->Frame11->llamador = 2;
   fModificarCliente->Frame11->Enabled = true;
   fModificarCliente->Frame11->restablecerFrame();
   fModificarCliente->Button1->Enabled = true;
   fModificarCliente->Button2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Modificardatosdeunacomida1Click(TObject *Sender)
{
   fModificarComida->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Imprimircuentas1Click(TObject *Sender)
{
   fImprimirCuentas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Gestionaralarmas1Click(TObject *Sender)
{
   fGestionarAlarmas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verplanillasdereparto1Click(TObject *Sender)
{
   fRepartos->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Vermenusemanal1Click(TObject *Sender)
{
   fMenuSemanal->ShowModal();
   Application->MessageBox(L"Si realiz? modificaciones sobre el men? de este mismo d?a, deber? cerrar y volver a abrir esta pantalla." ,L"ATENCI?N!",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Marcarcomplementocomoimpreso1Click(TObject *Sender)
{
   int id = ClientDataSet2->FieldByName("idPedido")->AsInteger;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET complementoImpreso = 1 WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();
   ClientDataSet2->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Marcarparavolveraimprimircomplemento1Click(TObject *Sender)

{
   int id = ClientDataSet2->FieldByName("idPedido")->AsInteger;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET complementoImpreso = 0 WHERE idPedido = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = id;
   QueryAux->ExecSQL();
   ClientDataSet2->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button17Click(TObject *Sender)
{
   Button3->Enabled = false;
   Button4->Enabled = false;
   Button17->Enabled = false;
   puedeSalir = false;

   contLineasImpresas = 0;
   cantLineas = StrToInt(Edit2->Text);
   imprimirComplementos();

   Button3->Enabled = true;
   Button4->Enabled = true;
   Button17->Enabled = true;
   puedeSalir = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button19Click(TObject *Sender)
{
   Panel17->Visible = false;
   CDSEtiquetasComp->Active = false;
   QueryEtiquetasComp->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button18Click(TObject *Sender)
{
	Panel17->Visible = false;

	procesoImpresionEtiquetasComplementos();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verhistorialdepedidosdelcliente1Click(TObject *Sender)

{
   if(idCliSel > 2)
   {
	  fVerHistorialPedidos->idCliente = idCliSel;
	  fVerHistorialPedidos->ShowModal();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Copiarmenparawhatsapp1Click(TObject *Sender)
{
   Memo2->Clear();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q;
   q = "SELECT *, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS c1, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida1 LIMIT 1) AS cat1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS c2, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida2 LIMIT 1) AS cat2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS c3, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida3 LIMIT 1) AS cat3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS c4, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida4 LIMIT 1) AS cat4, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida5 LIMIT 1) AS c5, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida5 LIMIT 1) AS cat5, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida6 LIMIT 1) AS c6, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida6 LIMIT 1) AS cat6, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida7 LIMIT 1) AS c7, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida7 LIMIT 1) AS cat7, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida8 LIMIT 1) AS c8, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida8 LIMIT 1) AS cat8 "
	   "FROM menudeldia WHERE fecha = :fecha LIMIT 1";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
   QueryAux->Open();

   if(QueryAux->IsEmpty() || QueryAux->FieldByName("refComida1")->AsInteger <= 1 || QueryAux->FieldByName("refComida7")->AsInteger <= 1)
   {
	  QueryAux->Close();
	  return;
   }

   int catV, catN;
   String rc, cc, c;
   catV = 1;

   Memo2->Lines->Add("*Men? del d?a " + FormatDateTime("dddd dd/mm/yyyy", QueryAux->FieldByName("fecha")->AsDateTime) + "*");
   Memo2->Lines->Add("");
   Memo2->Lines->Add("*Plato principal:*");
   Memo2->Lines->Add("  1 - " + QueryAux->FieldByName("c1")->AsString);

   int i = 2;
   int p = 2;
   while(i < 7)
   {
	  rc = "refComida" + IntToStr(i);
	  cc = "cat" + IntToStr(i);
	  c = "c" + IntToStr(i);
	  catN = QueryAux->FieldByName(cc)->AsInteger;

	  if(QueryAux->FieldByName(rc)->AsInteger != 2431  && QueryAux->FieldByName(rc)->AsInteger != 2434  && QueryAux->FieldByName(rc)->AsInteger != 2664)   //bolognesa o estofado
	  {
		 if(QueryAux->FieldByName(rc)->AsInteger > 1)
		 {
			if(catN > catV)
			{
			   if(DayOfTheWeek(DTP->Date) != DayThursday)
			   {
				  Memo2->Lines->Add("");
				  Memo2->Lines->Add("*Guarnici?n:*");
               }
			   catV = catN;
			}
			Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);
			p++;
		 }
		 else
		 {
			i = 10;    //sale del while
		 }
	  }
	  i++;
   }

   Memo2->Lines->Add("");
   Memo2->Lines->Add("*Complemento:*");

   i = 7;
   c = "c" + IntToStr(i);
   Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);
   p++;
   i = 8;
   c = "c" + IntToStr(i);
   Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);


   Memo2->Lines->Add("");
   Memo2->Lines->Add("_Si no desea recibir estos mensajes av?senos y ser? quitado inmediatamente de esta lista._");
   Memo2->Lines->Add("_El Sembrador - Viandas saludables_");

   QueryAux->Close();
   Memo2->SelectAll();
   Memo2->CopyToClipboard();

//   if(DayOfTheWeek(DTP->Date) == 4)
//	  Application->MessageBox(L"Por ser jueves es posible que el men? copiado deba ser editado antes de enviarse",L"ATENCI?N!",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);

   blockRGTexto = true;
   RGTexto->ItemIndex =  RGTexto->Items->Count - 1;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::CopiarmenparaMailFBIG1Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q;
   q = "SELECT *, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS c1, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida1 LIMIT 1) AS cat1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS c2, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida2 LIMIT 1) AS cat2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS c3, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida3 LIMIT 1) AS cat3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS c4, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida4 LIMIT 1) AS cat4, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida5 LIMIT 1) AS c5, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida5 LIMIT 1) AS cat5, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida6 LIMIT 1) AS c6, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida6 LIMIT 1) AS cat6, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida7 LIMIT 1) AS c7, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida7 LIMIT 1) AS cat7, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida8 LIMIT 1) AS c8, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida8 LIMIT 1) AS cat8 "
	   "FROM menudeldia WHERE fecha = :fecha LIMIT 1";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
   QueryAux->Open();


      if(QueryAux->IsEmpty() || QueryAux->FieldByName("refComida1")->AsInteger <= 1 || QueryAux->FieldByName("refComida7")->AsInteger <= 1)
   {
	  QueryAux->Close();
	  return;
   }

   int catV, catN;
   String rc, cc, c;
   catV = 1;

   Memo2->Lines->Add("Men? del d?a " + FormatDateTime("dddd dd/mm/yyyy", QueryAux->FieldByName("fecha")->AsDateTime));
   Memo2->Lines->Add("");
   Memo2->Lines->Add("Plato principal:");
   Memo2->Lines->Add("  1 - " + QueryAux->FieldByName("c1")->AsString);

   int i = 2;
   int p = 2;
   while(i < 7)
   {
	  rc = "refComida" + IntToStr(i);
	  cc = "cat" + IntToStr(i);
	  c = "c" + IntToStr(i);
	  catN = QueryAux->FieldByName(cc)->AsInteger;

	  if(QueryAux->FieldByName(rc)->AsInteger != 2431  && QueryAux->FieldByName(rc)->AsInteger != 2434)   //bolognesa o estofado
	  {
		 if(QueryAux->FieldByName(rc)->AsInteger > 1)
		 {
			if(catN > catV)
			{
			   Memo2->Lines->Add("");
			   Memo2->Lines->Add("Guarnici?n:");
			   catV = catN;
			}
			Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);
			p++;
		 }
		 else
		 {
			i = 10;    //sale del while
		 }
	  }
	  i++;
   }

   Memo2->Lines->Add("");
   Memo2->Lines->Add("Complemento:");

   i = 7;
   c = "c" + IntToStr(i);
   Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);
   p++;
   i = 8;
   c = "c" + IntToStr(i);
   Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryAux->FieldByName(c)->AsString);



   QueryAux->Close();
   Memo2->SelectAll();
   Memo2->CopyToClipboard();

   if(DayOfTheWeek(DTP->Date) == 4)
	  Application->MessageBox(L"Por ser jueves es posible que el men? copiado deba ser editado antes de enviarse",L"ATENCI?N!",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);

   blockRGTexto = true;
   RGTexto->ItemIndex =  RGTexto->Items->Count - 1;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Agregarunpedidoigual1Click(TObject *Sender)
{
   if(!ClientDataSet2->Active)
	  return;

   Modificarestepedido1Click(PopupMenu1);
   idMod = 0;
   modificandoPedido = false;	//anula lo de modificar para que se cargue como un nuevo pedido

   if(Sender == Button27)
      Button8Click(PopupMenu1);
   else
      Button1Click(PopupMenu1);

   vTimer1 = 0;
   Panel18->Visible = true;
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Timer1Timer(TObject *Sender)
{
   if(vTimer1 < 10)
   {
	  if(Panel18->Color == TColor(0x00DFDFDF))
	  {
		 Panel18->Color = TColor(0x009595FF);
	  }
	  else
	  {
		 Panel18->Color = TColor(0x00DFDFDF);
	  }
	  vTimer1++;
   }
   else
   {
	  Timer1->Enabled = false;
	  Panel18->Color = TColor(0x00DFDFDF);
	  Panel18->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Mandaraimprimirestecomplemento1Click(TObject *Sender)
{
	if (getImpresoraEtiquetas() != "NO_CONFIGURADA") {
		frxReport2->PrintOptions->Printer = getImpresoraEtiquetas();
	}
	else return;

	String q;

	q = "SELECT comentario, refComida4, "

	"(SELECT IF(codigo = :una, '1', IF(codigo = :ens, 'ENS', codigo)) FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS c4, "

	"(SELECT refRepartidor FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS refRep, "
	"(SELECT sectorReparto + 1 FROM cantidades WHERE (refCantidad = cantidades.idCantidad) LIMIT 1) AS salidaRep, "

	"(SELECT UPPER(SUBSTRING(descripcion, 1, 4)) FROM repartidores WHERE (repartidores.idRepartidor = refRep) LIMIT 1) AS Repartidor, "

	"(SELECT numero FROM clientes WHERE (refCliente = clientes.idCliente) LIMIT 1) AS Numero "

	"FROM pedidos WHERE idPedido = :idPedido";


	QueryAux->Close();
	QueryAux->SQL->Clear();
	QueryAux->SQL->Add(q);
	QueryAux->ParamByName("idPedido")->AsInteger = ClientDataSet2->FieldByName("idPedido")->AsInteger;
	QueryAux->ParamByName("una")->AsString = una;
	QueryAux->ParamByName("ens")->AsString = ens;
	QueryAux->Open();


	String c4 = QueryAux->FieldByName("c4")->AsString;
	String comentario = QueryAux->FieldByName("comentario")->AsString;
	String cliente = QueryAux->FieldByName("Numero")->AsString;
	String repartidor = QueryAux->FieldByName("Repartidor")->AsString;
	String nroReparto = QueryAux->FieldByName("salidaRep")->AsString;

	QueryAux->Close();


	completarEtiquetaComplemento(c4, cliente, repartidor, nroReparto,
								comentario, true, false);

	completarEtiquetaComplemento("", "", "", "", "", false, true);

	frxReport2->PrepareReport(true);
	frxReport2->Print();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verpedidosdehoy1Click(TObject *Sender)
{
   fMostrarPedidos->DTP->Date = DTP->Date;
   fMostrarPedidos->una = una;
   fMostrarPedidos->ens = ens;
   fMostrarPedidos->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button20Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refCliente, idCantidad FROM cantidades WHERE fecha = :fecha");
   QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
   QueryAux->Open();

   QueryAux->First();
   while(!QueryAux->Eof)
   {
	  QueryGenCad->Close();
   QueryGenCad->SQL->Clear();
   QueryGenCad->SQL->Add("SELECT codigo FROM comidas WHERE idComida IN (SELECT refComida4 FROM pedidos WHERE refCliente = :refCliente AND DATE(momento) = :fecha)");
   QueryGenCad->ParamByName("fecha")->AsDate = DTP->Date;
   QueryGenCad->ParamByName("refCliente")->AsInteger = QueryAux->FieldByName("refCliente")->AsInteger;
   QueryGenCad->Open();

      String strComp = "";
	  QueryGenCad->First();
	  int cont_1, cont_ens;
	  cont_1 = 0;
	  cont_ens = 0;

	  String cod;
	  while(!QueryGenCad->Eof)
	  {
		 cod = QueryGenCad->FieldByName("codigo")->AsString;
		 if(cod == "1")
			cont_1++;
		 else if(cod == "ENS")
			cont_ens++;
		 else if(cod != "NO")
			strComp = cod + "+" + strComp;

		 QueryGenCad->Next();
	  }
      QueryGenCad->Close();


	  if(strComp.SubString(strComp.Length(),1) == "+")   //para borrar el ultimo "+" en caso de que exista
		 strComp = strComp.Delete(strComp.Length(),1);


	  String aux = "";
	  String nuevo = "";

	  if(strComp.Pos("+") == 1)
		 strComp = strComp.Delete(1,1);

	  if(strComp.Pos("+") > 0)    //revisa si al menos hay al menos mas de un complemento en strComp
	  {
		 while(strComp.Pos("+") > 0)
		 {
			aux = strComp.SubString(1,strComp.Pos("+")-1);

			int cAux = 0;
			while(strComp.Pos(aux) > 0)
			{
			   cAux++;
			   strComp = strComp.Delete(strComp.Pos(aux),aux.Length());
			}

			if(cAux > 1)
			   nuevo = nuevo + aux + "x" + IntToStr(cAux) + "+";
			else
			   nuevo = nuevo + aux + "+";

			while(strComp.Pos("++"))
			{
			   strComp = strComp.Delete(strComp.Pos("++"),1);
			}
			if(strComp.Pos("+") == 1)
			   strComp = strComp.Delete(1,1);
			if(strComp.Pos("+") == 0)
			   if(strComp != "")
				  strComp = strComp + "+";
		 }

		 while(nuevo.SubString(nuevo.Length(),1) == "+")
			nuevo = nuevo.Delete(nuevo.Length(),1);

		 strComp = nuevo;
	  }

	  if(cont_ens > 0)
	  {
		 if(cont_ens == 1)
			strComp = "ENS+" + strComp;
		 else
			strComp = "ENSx" + IntToStr(cont_ens) + "+" + strComp;
	  }

	  if(cont_1 > 0)
		 strComp = IntToStr(cont_1) + "+" + strComp;

	  if(strComp.SubString(strComp.Length(),1) == "+")
			strComp = strComp.Delete(strComp.Length(),1);

   QueryGenCad->SQL->Clear();
   QueryGenCad->SQL->Add("UPDATE cantidades SET txtComplemento = :comp WHERE idCantidad = :idCantidad");
   QueryGenCad->ParamByName("comp")->AsString = strComp;
   QueryGenCad->ParamByName("idCantidad")->AsInteger = QueryAux->FieldByName("idCantidad")->AsInteger;
   QueryGenCad->ExecSQL();

	  QueryAux->Next();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::ListBox1DrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{
   if(State.Contains(odSelected))
   {
	  dynamic_cast <TListBox *>(Control)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(Index % 2 == 0)
		 dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x00D9D9D9);
	  else
		 dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x00F2F2F2);
   }


   String s = dynamic_cast <TListBox *>(Control)->Items->Strings[Index];
   int l = Rect.Left  + 5;//+ (Rect.Width() - dynamic_cast <TListBox *>(Control)->Canvas->TextWidth(s)) / 2;

   dynamic_cast <TListBox *>(Control)->Canvas->FillRect(Rect);
   dynamic_cast <TListBox *>(Control)->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);
       else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);
       else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
	  Edit1Change(Button20);
   else if(Key == VK_DOWN && !ClientDataSet3->IsEmpty())
	  DBGrid2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Timer2Timer(TObject *Sender)
{
   if(vTimer2 < 10)
   {
	  if(Panel19->Color == TColor(0x00DFDFDF))
	  {
		 Panel19->Color = TColor(0x009595FF);
	  }
	  else
	  {
		 Panel19->Color = TColor(0x00DFDFDF);
	  }
	  vTimer2++;
   }
   else
   {
	  Timer2->Enabled = false;
	  Panel19->Color = TColor(0x00DFDFDF);
	  Panel19->Visible = false;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button21Click(TObject *Sender)
{
   if(idCliSel <= 2)
	  return;

   fImprimirCuentas->refClienteIndicado = idCliSel;
   fImprimirCuentas->usarClienteIndicado = true;
   fImprimirCuentas->Show();
   //fImprimirCuentas->RG1->ItemIndex = 2;
   fImprimirCuentas->Button8Click(fImprimirCuentas->RG1); // cualquier sender

}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
   if(RGSeleccionado == 0 || idCliSel <= 2)
	  return;

   if(Key == 'j' || Key == 'J')
   {
	  if(RGSeleccionado == 1 && RG1->ItemIndex == RG1->Items->Count - 1)
	  {
		 idOpEsp1 = 2496; //idComida del jamon y queso generico
		 Label4->Caption = "JQ";
	  }
	  else if(RGSeleccionado == 2 && RG2->ItemIndex == RG2->Items->Count - 1)
	  {
		 idOpEsp2 = 2496; //idComida del jamon y queso generico
		 Label5->Caption = "JQ";
	  }
	  else if(RGSeleccionado == 3 && RG3->ItemIndex == RG3->Items->Count - 1)
	  {
		 idOpEsp3 = 2496; //idComida del jamon y queso generico
		 Label6->Caption = "JQ";
	  }
	  else if(RGSeleccionado == 4 && RG4->ItemIndex == RG4->Items->Count - 1)
	  {
		 idOpEsp4 = 2496; //idComida del jamon y queso generico
		 Label7->Caption = "JQ";
      }
   }
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::RG1Enter(TObject *Sender)
{
   RGSeleccionado = 1;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG1Exit(TObject *Sender)
{
   RGSeleccionado = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG2Enter(TObject *Sender)
{
   RGSeleccionado = 2;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG2Exit(TObject *Sender)
{
   RGSeleccionado = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG3Exit(TObject *Sender)
{
   RGSeleccionado = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG3Enter(TObject *Sender)
{
   RGSeleccionado = 3;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG4Enter(TObject *Sender)
{
   RGSeleccionado = 4;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::RG4Exit(TObject *Sender)
{
   RGSeleccionado = 0;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Panel18Click(TObject *Sender)
{
	Button2Click(Panel18);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Panel19Click(TObject *Sender)
{
	Button10Click(Panel19);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Mem(TObject *Sender)
{
	String q;

	q = "SELECT refComida4, "
	"(SELECT nombre FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS c4, "
	"(SELECT refCategoriaComida FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS cat, "
	" COUNT(*) AS repe "

	"FROM pedidos WHERE DATE(momento) = :f AND complementoImpreso = 0 AND refComida4 > 1 "
	" AND refComida4 NOT IN(:c1,:c2) "

	"GROUP BY refComida4 "
	"ORDER BY c4 ";
//
	q = "SELECT refComida, c4, cat, COUNT(*) AS repe FROM (SELECT refComida4 AS refComida, "
	"(SELECT nombre FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS c4, "
	"(SELECT refCategoriaComida FROM comidas WHERE (refComida4 = comidas.idComida) LIMIT 1) AS cat "
	"FROM pedidos WHERE DATE(momento) = :f AND etiquetaImpresa = 0 AND refComida4 > 1 "
	" AND refComida4 NOT IN(:c1,:c2) "

	"UNION ALL "
	"(SELECT refComida3 AS refComida, "
	"(SELECT nombre FROM comidas WHERE (refComida3 = comidas.idComida) LIMIT 1) AS c4, "
	"(SELECT refCategoriaComida FROM comidas WHERE (refComida3 = comidas.idComida) LIMIT 1) AS cat "
	"FROM pedidos WHERE DATE(momento) = :f AND etiquetaImpresa = 0 AND refComida3 > 1 "
	" AND refComida3 NOT IN(:c1,:c2)) "

	"UNION ALL "
	"(SELECT refComida2 AS refComida, "
	"(SELECT nombre FROM comidas WHERE (refComida2 = comidas.idComida) LIMIT 1) AS c4, "
	"(SELECT refCategoriaComida FROM comidas WHERE (refComida2 = comidas.idComida) LIMIT 1) AS cat "
	"FROM pedidos WHERE DATE(momento) = :f AND etiquetaImpresa = 0 AND refComida2 > 1 "
	" AND refComida2 NOT IN(:c1,:c2)) "

	"UNION ALL "
	"(SELECT refComida1 AS refComida, "
	"(SELECT nombre FROM comidas WHERE (refComida1 = comidas.idComida) LIMIT 1) AS c4, "
	"(SELECT refCategoriaComida FROM comidas WHERE (refComida1 = comidas.idComida) LIMIT 1) AS cat "
	"FROM pedidos WHERE DATE(momento) = :f AND etiquetaImpresa = 0 AND refComida1 > 1 "
	" AND refComida1 NOT IN(:c1,:c2)))t "
	"WHERE cat IN (3,4) "
	"GROUP BY refComida "
	"ORDER BY c4 ";


	CDSEtiquetasComp->Active = false;
	QueryEtiquetasComp->Close();
	QueryEtiquetasComp->SQL->Clear();
	QueryEtiquetasComp->SQL->Add(q);
	QueryEtiquetasComp->ParamByName("f")->AsDate = DTP->Date;
	QueryEtiquetasComp->ParamByName("c1")->AsInteger = arrIdComida[RGTexto->Items->Count - 3];
	QueryEtiquetasComp->ParamByName("c2")->AsInteger = arrIdComida[RGTexto->Items->Count - 2];
	QueryEtiquetasComp->Open();

	Memo3->Clear();
	QueryEtiquetasComp->First();

	while (!QueryEtiquetasComp->Eof)
	{
	   Memo3->Lines->Add(QueryEtiquetasComp->FieldByName("c4")->AsString + " x " + QueryEtiquetasComp->FieldByName("repe")->AsString);
	   QueryEtiquetasComp->Next();
	}
	QueryEtiquetasComp->Close();
	Memo3->SelectAll();
	Memo3->CopyToClipboard();

}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;

   Panel20->Left = (fPedidos->Width - Panel20->Width) / 2;
   Panel20->Top = (fPedidos->Height - Panel20->Height) / 2;
   mostroMsg1 = false;
   mostroMsg2 = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::VercomprobantesX1Click(TObject *Sender)
{
   fComprobantesX->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button23Click(TObject *Sender)
{
   if(idCliSel <= 2)
	  return;

   fImprimirResumenManual->Show();
   fImprimirResumenManual->mostrarCliente(idCliSel);
   fImprimirResumenManual->Edit3->Text = edBandGrand->Text;
   fImprimirResumenManual->Edit5->Text = FormatFloat("0.00", fImprimirResumenManual->valorUnidad);
   fImprimirResumenManual->Edit5->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Emitiruncomprobanteelectronico1Click(TObject *Sender)
{
   fEmitirComprobanteElectronico->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button24Click(TObject *Sender)
{
   if(idCliSel <= 2)
	  return;

   if(Application->MessageBox(L"Se va a acceder al formulario para la emisi?n de comprobantes homologados por AFIP. Desea continuar?" ,L"ATENCI?N!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;

   fEmitirComprobanteElectronico->Show();
   fEmitirComprobanteElectronico->mostrarCliente(idCliSel);
   fEmitirComprobanteElectronico->Edit3->Text = edBandGrand->Text;
   fEmitirComprobanteElectronico->Edit5->Text = FormatFloat("0.00", fEmitirComprobanteElectronico->valorUnidad);
   fEmitirComprobanteElectronico->Edit5->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      DBGrid2DblClick(DBGrid2);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
   if(Key == '+')
   {
      Key = NULL;
	  Button9Click(Edit1);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button25Click(TObject *Sender)
{
   String q;
   q = "SELECT cliente FROM (SELECT refCliente, "
					 "(IFNULL((SELECT nroUnidades FROM cantidades WHERE cantidades.fecha = :fecha AND cantidades.refCliente = clientesHabituales.refCliente LIMIT 1), 0)) AS pedido, "
					 "(SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE clientesHabituales.refCliente = clientes.idCliente LIMIT 1) AS cliente ";
   if(DayOfTheWeek(DTP->Date) == 1)
	  q = q + "FROM clientesHabituales WHERE Lunes = 1) t WHERE pedido = 0";
   else if(DayOfTheWeek(DTP->Date) == 2)
	  q = q + "FROM clientesHabituales WHERE Martes = 1) t WHERE pedido = 0";
   else if(DayOfTheWeek(DTP->Date) == 3)
	  q = q + "FROM clientesHabituales WHERE Miercoles = 1) t WHERE pedido = 0";
   else if(DayOfTheWeek(DTP->Date) == 4)
	  q = q + "FROM clientesHabituales WHERE Jueves = 1) t WHERE pedido = 0";
   else if(DayOfTheWeek(DTP->Date) == 5)
	  q = q + "FROM clientesHabituales WHERE Viernes = 1) t WHERE pedido = 0";
   else if(DayOfTheWeek(DTP->Date) == 6)
	  q = q + "FROM clientesHabituales WHERE Sabado = 1) t WHERE pedido = 0";

   Querych->Close();
   Querych->SQL->Clear();
   Querych->SQL->Add(q);
   Querych->ParamByName("fecha")->AsDate = DTP->Date;
   Querych->Open();
   CDSch->Active = true;

   if(CDSch->IsEmpty())
   {
	  Querych->Close();
	  CDSch->Active = false;
	  Timer3->Enabled = false;
	  return;
   }

   Panel20->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::Button26Click(TObject *Sender)
{
   CDSch->Active = false;
   Querych->Close();
   Panel20->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Timer3Timer(TObject *Sender)
{
   if(!mostroMsg1 && (CompareDateTime(Now(), StrToDateTime(DateToStr(Now()) + " 10:45:00")) == GreaterThanValue))
   {
	  mostroMsg1 = true;
	  if(CompareDateTime(Now(), StrToDateTime(DateToStr(Now()) + " 11:45:00")) == LessThanValue)
	     Button25Click(Timer3);
   }
   else if(!mostroMsg2 && (CompareDateTime(Now(), StrToDateTime(DateToStr(Now()) + " 11:45:00")) == GreaterThanValue))
   {
	  mostroMsg2 = true;
	  if(CompareDateTime(Now(), StrToDateTime(DateToStr(Now()) + " 13:45:00")) == LessThanValue)
	     Button25Click(Timer3);
   }

   if(mostroMsg1 && mostroMsg2)
	  Timer3->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::ransferiraotrocliente1Click(TObject *Sender)
{
   fSeleccionarCliente->llamador = 1;
   fSeleccionarCliente->precargar = false;
   fSeleccionarCliente->ShowModal();

   if(fSeleccionarCliente->idSeleccionado <= 2)
	  return;

   int idClienteDestino = fSeleccionarCliente->idSeleccionado;
   int idClienteOrigen = idCliSel;
   int idCant;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT CONCAT(calle, ' ', numero) AS cliente FROM clientes WHERE idCliente = :idCliente LIMIT 1");
   QueryAux->ParamByName("idCliente")->AsInteger = idClienteDestino;
   QueryAux->Open();
   String cliente = QueryAux->FieldByName("cliente")->AsString;
   QueryAux->Close();
   String msg = "Se va a transferir todo este pedido hacia el cliente:\n" + cliente + "\nDesea continuar?";

   if(Application->MessageBox(msg.w_str(),L"?ATENCI?N!",MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2) != IDYES)
	  return;


   QueryPedidos->Close();
   ClientDataSet2->Active = false;

   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT COUNT(*) AS existe FROM cantidades WHERE (fecha = :d AND refCliente = :rc) LIMIT 1");
   QueryAux->ParamByName("d")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idClienteDestino;
   QueryAux->Open();
   bool existeCantidad;
   if(QueryAux->FieldByName("existe")->AsInteger == 0)
	  existeCantidad = false;
   else
   {
	  existeCantidad = true;
   }

   QueryAux->Close();

   if(existeCantidad)
   {
	  Application->MessageBox(L"El cliente destino no puede contener un pedido anterior.",L"No se realizaron cambios",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      return;
   }

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT idCantidad FROM cantidades WHERE (fecha = :d AND refCliente = :rc) LIMIT 1");
   QueryAux->ParamByName("d")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idClienteOrigen;
   QueryAux->Open();
   idCant = QueryAux->FieldByName("idCantidad")->AsInteger;

   QueryAux->Close();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE cantidades SET refCliente = :refCliente "
					   "WHERE idCantidad = :refCantidad LIMIT 1");
   QueryAux->ParamByName("refCantidad")->AsInteger = idCant;
   QueryAux->ParamByName("refCliente")->AsInteger = idClienteDestino;
   QueryAux->ExecSQL();

   QueryAux->Close();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("UPDATE pedidos SET refCliente = :refCliente "
					   "WHERE refCantidad = :refCantidad");
   QueryAux->ParamByName("refCantidad")->AsInteger = idCant;
   QueryAux->ParamByName("refCliente")->AsInteger = idClienteDestino;
   QueryAux->ExecSQL();

   RestablecerFormulario();
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::DBGrid1DblClick(TObject *Sender)
{
   Modificarestepedido1Click(PopupMenu1);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Informacinnutricional1Click(TObject *Sender)
{
   fInformacionNutricional->preseleccion = true;
   fInformacionNutricional->idComida =  arrIdComida[RGTexto->ItemIndex];
   fInformacionNutricional->ShowModal();
   RGTexto->ItemIndex = RGTexto->Items->Count - 1;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CopiarmenusemanalparaWhatsapp1Click(TObject *Sender)
{
   Memo2->Clear();
   for(int w = 0; w < 6; w++)
   {
		QueryComida->Close();
		QueryComida->SQL->Clear();
		String q;
		q = "SELECT *, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS c1, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida1 LIMIT 1) AS cat1, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS c2, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida2 LIMIT 1) AS cat2, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS c3, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida3 LIMIT 1) AS cat3, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS c4, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida4 LIMIT 1) AS cat4, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida5 LIMIT 1) AS c5, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida5 LIMIT 1) AS cat5, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida6 LIMIT 1) AS c6, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida6 LIMIT 1) AS cat6, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida7 LIMIT 1) AS c7, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida7 LIMIT 1) AS cat7, "
		   "(SELECT nombre FROM comidas WHERE idComida = refComida8 LIMIT 1) AS c8, "
		   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida8 LIMIT 1) AS cat8 "
		   "FROM menudeldia WHERE fecha = :fecha LIMIT 1";

		QueryComida->SQL->Add(q);
		QueryComida->ParamByName("fecha")->AsDate = IncDay(StartOfTheWeek(DTP->Date), w);
		QueryComida->Open();


		if(QueryComida->IsEmpty() || QueryComida->FieldByName("refComida1")->AsInteger <= 1 || QueryComida->FieldByName("refComida7")->AsInteger <= 1)
		{
		  Memo2->Lines->Add("*Men? del d?a " + FormatDateTime("dddd dd/mm/yyyy", QueryComida->FieldByName("fecha")->AsDateTime) + "*");
		  Memo2->Lines->Add("");
		  Memo2->Lines->Add("	CERRADO");
		}
		else
		{
			int catV, catN;
			String rc, cc, c;
			catV = 1;
			catN = 1;

			Memo2->Lines->Add("*Men? del d?a " + FormatDateTime("dddd dd/mm/yyyy", QueryComida->FieldByName("fecha")->AsDateTime) + "*");
			Memo2->Lines->Add("");
			Memo2->Lines->Add("*Plato principal:*");
			Memo2->Lines->Add("  1 - " + QueryComida->FieldByName("c1")->AsString);

			int i = 2;
			int p = 2;
			while(i < 7)
			{
			  rc = "refComida" + IntToStr(i);
			  cc = "cat" + IntToStr(i);
			  c = "c" + IntToStr(i);
			  catN = QueryComida->FieldByName(cc)->AsInteger;

			  if(QueryComida->FieldByName(rc)->AsInteger != 2431  && QueryComida->FieldByName(rc)->AsInteger != 2434  && QueryComida->FieldByName(rc)->AsInteger != 2664)   //bolognesa o estofado
			  {
				 if(QueryComida->FieldByName(rc)->AsInteger > 1)
				 {
					if(catN > catV)
					{
					   if(w != 3)
					   {
						  Memo2->Lines->Add("");
						  Memo2->Lines->Add("*Guarnici?n:*");
					   }
					   catV = catN;
					}
					Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryComida->FieldByName(c)->AsString);
					p++;
				 }
				 else
				 {
					i = 10;    //sale del while
				 }
			  }
			  i++;
			}

			Memo2->Lines->Add("");
			Memo2->Lines->Add("*Complemento:*");

			i = 7;
			c = "c" + IntToStr(i);
			Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryComida->FieldByName(c)->AsString);
			p++;
			i = 8;
			c = "c" + IntToStr(i);
			Memo2->Lines->Add("  " + IntToStr(p) + " - " + QueryComida->FieldByName(c)->AsString);
		}
		Memo2->Lines->Add("");
		Memo2->Lines->Add("");
		Memo2->Lines->Add("");
   }

   Memo2->Lines->Add("_Si no desea recibir estos mensajes av?senos y ser? quitado inmediatamente de esta lista._");
   Memo2->Lines->Add("_El Sembrador - Viandas saludables_");

   QueryComida->Close();

   Memo2->SelectAll();
   Memo2->CopyToClipboard();
   Application->MessageBox(L"El men? fue copiado correctamente al portapapeles. Puede pegarlo donde prefiera",L"Men? copiado",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Button27Click(TObject *Sender)
{
   Agregarunpedidoigual1Click(Button27);
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::CopiarcombinacionesJUEVES1Click(TObject *Sender)
{
   if(DayOfTheWeek(DTP->Date) != DayThursday)
   {
      return;
   }

   Memo2->Clear();
   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q;
   q = "SELECT *, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS c1, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida1 LIMIT 1) AS cat1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS c2, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida2 LIMIT 1) AS cat2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS c3, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida3 LIMIT 1) AS cat3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS c4, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida4 LIMIT 1) AS cat4, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida5 LIMIT 1) AS c5, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida5 LIMIT 1) AS cat5, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida6 LIMIT 1) AS c6, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida6 LIMIT 1) AS cat6, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida7 LIMIT 1) AS c7, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida7 LIMIT 1) AS cat7, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida8 LIMIT 1) AS c8, "
	   "(SELECT refCategoriaComida FROM comidas WHERE idComida = refComida8 LIMIT 1) AS cat8 "
	   "FROM menudeldia WHERE fecha = :fecha LIMIT 1";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("fecha")->AsDate = DTP->Date;
   QueryAux->Open();

   if(QueryAux->IsEmpty() || QueryAux->FieldByName("refComida1")->AsInteger <= 1 || QueryAux->FieldByName("refComida7")->AsInteger <= 1)
   {
	  QueryAux->Close();
	  return;
   }

   TStringList *Lista;
   Lista = new TStringList();
   Lista->Add(QueryAux->FieldByName("c1")->AsString);  //[0]
   Lista->Add(QueryAux->FieldByName("c3")->AsString);  //[1]
   Lista->Add(QueryAux->FieldByName("c5")->AsString);  //[2]
   Lista->Add(QueryAux->FieldByName("c6")->AsString);  //[3]

   Lista->Add(QueryAux->FieldByName("c7")->AsString);  //[4]
   Lista->Add(QueryAux->FieldByName("c8")->AsString);  //[5]

   Lista->Add(QueryAux->FieldByName("c1")->AsString);  //[6]
   Lista->Strings[6] = Lista->Strings[6].SubString(1, Lista->Strings[6].Pos("salsa") + 4);
   Lista->Add(QueryAux->FieldByName("c3")->AsString);  //[7]
   Lista->Strings[7] = Lista->Strings[7].SubString(1, Lista->Strings[7].Pos("salsa") + 4);

   QueryAux->Close();


   Memo2->Lines->Add("*1)-* " + Lista->Strings[0] + " (Doble porci?n) + " + Lista->Strings[4]);
   Memo2->Lines->Add("*2)-* " + Lista->Strings[0] + " (Doble porci?n) + " + Lista->Strings[5]);
   Memo2->Lines->Add("*3)-* " + Lista->Strings[1] + " (Doble porci?n) + " + Lista->Strings[4]);
   Memo2->Lines->Add("*4)-* " + Lista->Strings[1] + " (Doble porci?n) + " + Lista->Strings[5]);
   Memo2->Lines->Add("*5)-* " + Lista->Strings[2] + " + " + Lista->Strings[3] + " + " + Lista->Strings[4]);
   Memo2->Lines->Add("*6)-* " + Lista->Strings[2] + " + " + Lista->Strings[3] + " + " + Lista->Strings[5]);
   Memo2->Lines->Add("*7)-* " + Lista->Strings[6] + " + " + Lista->Strings[2] + " + " + Lista->Strings[4]);
   Memo2->Lines->Add("*8)-* " + Lista->Strings[6] + " + " + Lista->Strings[2] + " + " + Lista->Strings[5]);
   Memo2->Lines->Add("*9)-* " + Lista->Strings[7] + " + " + Lista->Strings[2] + " + " + Lista->Strings[4]);
   Memo2->Lines->Add("*10)-* " + Lista->Strings[7] + " + " + Lista->Strings[2] + " + " + Lista->Strings[5]);
   Memo2->Lines->Add("*11)-* " + Lista->Strings[0] + " + " + Lista->Strings[3] + " + " + Lista->Strings[4]);
   Memo2->Lines->Add("*12)-* " + Lista->Strings[0] + " + " + Lista->Strings[3] + " + " + Lista->Strings[5]);
   Memo2->Lines->Add("*13)-* " + Lista->Strings[1] + " + " + Lista->Strings[3] + " + " + Lista->Strings[4]);
   Memo2->Lines->Add("*14)-* " + Lista->Strings[1] + " + " + Lista->Strings[3] + " + " + Lista->Strings[5]);

   Memo2->SelectAll();
   Memo2->CopyToClipboard();

   delete Lista;
   blockRGTexto = true;
   RGTexto->ItemIndex =  RGTexto->Items->Count - 1;
}
//---------------------------------------------------------------------------

void __fastcall TfPedidos::Verinformacindelcliente1Click(TObject *Sender)
{
   if(idCliSel > 2)
   {
	  fInfoCliente->idCliente = idCliSel;
	  fInfoCliente->ShowModal();
   }
}
//---------------------------------------------------------------------------


void __fastcall TfPedidos::CopiarpedidoparaWhatsApp1Click(TObject *Sender)
{
   if(!ClientDataSet2->Active)
	  return;

   Memo2->Clear();


   String q1;
   q1 = "SELECT refComida1, refComida2, refComida3, refComida4, comentario, "
		  "(SELECT nombre FROM comidas WHERE refComida1 = idComida LIMIT 1) AS com1, "
		  "(SELECT nombre FROM comidas WHERE refComida2 = idComida LIMIT 1) AS com2, "
		  "(SELECT nombre FROM comidas WHERE refComida3 = idComida LIMIT 1) AS com3, "
		  "(SELECT nombre FROM comidas WHERE refComida4 = idComida LIMIT 1) AS com4 "
		  "FROM pedidos WHERE (refCliente = :rc AND DATE(momento) = :d) ORDER BY momento";

   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add(q1);
   QueryAux->ParamByName("d")->AsDate = DTP->Date;
   QueryAux->ParamByName("rc")->AsInteger = idCliSel;
   QueryAux->Open();


   String pedido;

   Memo2->Lines->Add("*Pedido(s) para este d?a:*");

   int idx = 1;
   while(!QueryAux->Eof)
   {
      Memo2->Lines->Add("");
	  Memo2->Lines->Add("_*Pedido " + IntToStr(idx) + ":*_");
	  idx++;

	  if(QueryAux->FieldByName("refComida1")->AsInteger != 1)
	  {
		 pedido = QueryAux->FieldByName("com1")->AsString;

		 if(QueryAux->FieldByName("refComida1")->AsInteger == QueryAux->FieldByName("refComida2")->AsInteger)
			pedido = pedido + " (Doble porci?n)";
		 else if(QueryAux->FieldByName("refComida2")->AsInteger != 1)
			pedido = pedido + " + " + QueryAux->FieldByName("com2")->AsString;
		 if(QueryAux->FieldByName("refComida3")->AsInteger != 1)
			pedido = pedido + " + " + QueryAux->FieldByName("com3")->AsString;
		 if(QueryAux->FieldByName("refComida4")->AsInteger != 1)
			pedido = pedido + " + " + QueryAux->FieldByName("com4")->AsString;
	  }
	  else
		 pedido = QueryAux->FieldByName("com4")->AsString;

	  if(QueryAux->FieldByName("comentario")->AsString != "")
		 pedido = pedido + " (*" + QueryAux->FieldByName("comentario")->AsString + "*)";

	  Memo2->Lines->Add(pedido);
	  QueryAux->Next();
   }
   QueryAux->Close();
   Memo2->SelectAll();
   Memo2->CopyToClipboard();
}
//---------------------------------------------------------------------------



void __fastcall TfPedidos::Configuraralarmadeentrega1Click(TObject *Sender)
{
   if(idCliSel > 2)
   {
	  fConfigurarAlarma->Show();
	  fConfigurarAlarma->Memo1->Text = "Entregar pedido a " +
										ClientDataSet3->FieldByName("calle")->AsString + " " +
                                        ClientDataSet3->FieldByName("Numero")->AsString;
   }
}
//---------------------------------------------------------------------------




