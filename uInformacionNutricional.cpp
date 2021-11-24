//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uInformacionNutricional.h"
#include "VariablesGlobales.h"
#include "uSeleccionarComida.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfInformacionNutricional *fInformacionNutricional;

extern String servidor;
extern String dbName;
extern String userName;
extern String pass;
//---------------------------------------------------------------------------
__fastcall TfInformacionNutricional::TfInformacionNutricional(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfInformacionNutricional::FormCreate(TObject *Sender)
{
   SQLConnection1->Params->Values["HostName"] = servidor;
   SQLConnection1->Params->Values["Database"] = dbName;
   SQLConnection1->Params->Values["User_Name"] = userName;
   SQLConnection1->Params->Values["Password"] = pass;

   preseleccion = false;
}
//---------------------------------------------------------------------------
void __fastcall TfInformacionNutricional::FormShow(TObject *Sender)
{
   if(!preseleccion)
   {
	   fSeleccionarComida->ShowModal();
	   if(fSeleccionarComida->idSeleccionado < 2)
	   {
		  ShowMessage("Sebe seleccionar una comida. Cierre y vuelva a abrir esta ventana");
		  return;
	   }

	   idComida = fSeleccionarComida->idSeleccionado;
   }
//   idComida = 2388; //papas al horno;

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT nombre FROM comidas WHERE idComida = :idComida LIMIT 1");
   Query1->ParamByName("idComida")->AsInteger = idComida;
   Query1->Open();
   Label19->Caption = Query1->FieldByName("nombre")->AsString;

   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT SUM(valorEnergetico) AS valorEnergeticoTotal, "
	   "SUM(carbohidratos) AS carbohidratosTotal, "
	   "SUM(proteinas) AS proteinasTotal, "
	   "SUM(grasasTotales) AS grasasTotalesTotal, "
	   "SUM(grasasSaturadas) AS grasasSaturadasTotal, "
	   "SUM(grasasTrans) AS grasasTransTotal, "
	   "SUM(fibraAlimentaria) AS fibraAlimentariaTotal, "
	   "SUM(sodio) AS sodioTotal FROM "
	   "(SELECT idIngrediente, (valorEnergetico * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS valorEnergetico, "
	   "(carbohidratos * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS carbohidratos, "
	   "(proteinas * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS proteinas, "
	   "(grasasTotales * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS grasasTotales, "
	   "(grasasSaturadas * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS grasasSaturadas, "
	   "(grasasTrans * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS grasasTrans, "
	   "(fibraAlimentaria * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS fibraAlimentaria, "
	   "(sodio * (SELECT cantidadCada100g FROM formulacomidas WHERE refComida = :idComida AND refIngrediente = idIngrediente LIMIT 1) / 100.0) AS sodio "
	   "FROM ingredientes WHERE idIngrediente IN (SELECT refIngrediente FROM formulacomidas WHERE refComida = :idComida)) tabla ";


   Query1->SQL->Add(q);
   Query1->ParamByName("idComida")->AsInteger = idComida;
   Query1->Open();

   Label20->Caption = FormatFloat("0.00", Query1->FieldByName("valorEnergeticoTotal")->AsFloat);
   Label21->Caption = FormatFloat("0.00", Query1->FieldByName("carbohidratosTotal")->AsFloat);
   Label22->Caption = FormatFloat("0.00", Query1->FieldByName("proteinasTotal")->AsFloat);
   Label23->Caption = FormatFloat("0.00", Query1->FieldByName("grasasTotalesTotal")->AsFloat);
   Label24->Caption = FormatFloat("0.00", Query1->FieldByName("grasasSaturadasTotal")->AsFloat);
   Label25->Caption = FormatFloat("0.00", Query1->FieldByName("grasasTransTotal")->AsFloat);
   Label26->Caption = FormatFloat("0.00", Query1->FieldByName("fibraAlimentariaTotal")->AsFloat);
   Label27->Caption = FormatFloat("0.00", Query1->FieldByName("sodioTotal")->AsFloat);
   Query1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfInformacionNutricional::FormClose(TObject *Sender, TCloseAction &Action)

{
   Query1->Close();
   SQLConnection1->Close();
   preseleccion = false;
}
//---------------------------------------------------------------------------

void __fastcall TfInformacionNutricional::Button2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

