//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("uModificarCliente.cpp", fModificarCliente);
USEFORM("uMenuSemanal.cpp", fMenuSemanal);
USEFORM("uMenuDelDia.cpp", fMenuDelDia);
USEFORM("uPedidos.cpp", fPedidos);
USEFORM("uMostrarPedidos.cpp", fMostrarPedidos);
USEFORM("uModificarComida.cpp", fModificarComida);
USEFORM("uMain.cpp", fMain);
USEFORM("uImprimirResumenManual.cpp", fImprimirResumenManual);
USEFORM("uImprimirPlanillas.cpp", fImprimirPlanillas);
USEFORM("uImprimirCuentas.cpp", fImprimirCuentas);
USEFORM("uIngredientes.cpp", fIngredientes);
USEFORM("uInformacionNutricional.cpp", fInformacionNutricional);
USEFORM("uInfoCliente.cpp", fInfoCliente);
USEFORM("uPrecios.cpp", fPrecios);
USEFORM("uVerComprobantesElectronicos.cpp", fVerComprobantesElectronicos);
USEFORM("uVerCargaManual.cpp", fVerCargaManual);
USEFORM("uValorNutricional.cpp", fValorNutricional);
USEFORM("uVerHistorialPedidos.cpp", fVerHistorialPedidos);
USEFORM("uSeleccionarComida.cpp", fSeleccionarComida);
USEFORM("uRecetas.cpp", fRecetas);
USEFORM("uRastrearPagos.cpp", fRastrearPagos);
USEFORM("uProductos.cpp", fProductos);
USEFORM("uSeleccionarCliente.cpp", fSeleccionarCliente);
USEFORM("uRepartos.cpp", fRepartos);
USEFORM("uRepartidores.cpp", fRepartidores);
USEFORM("uGestionDeGastos.cpp", fGestionDeGastos);
USEFORM("uChartPedidosPorHora.cpp", fChartPedidosPorHora);
USEFORM("uChartPedidosPorDia.cpp", fChartPedidosPorDia);
USEFORM("uChartComidasMasVendidas.cpp", fChartComidasMasVendidas);
USEFORM("uComprobantesX.cpp", fComprobantesX);
USEFORM("uComidasExcluidas.cpp", fComidasExcluidas);
USEFORM("uClientesHabituales.cpp", fClientesHabituales);
USEFORM("uChartCobrosPorDia.cpp", fChartCobrosPorDia);
USEFORM("uAgregarCliente.cpp", fAgregarCliente);
USEFORM("uCargarPagos.cpp", fCargarPagos);
USEFORM("uAlarma.cpp", fAlarma);
USEFORM("uAgregarComida.cpp", fAgregarComida);
USEFORM("uConfiguraciones.cpp", fConfiguraciones);
USEFORM("uFrame3.cpp", Frame3); /* TFrame: File Type */
USEFORM("uFrame2.cpp", Frame2); /* TFrame: File Type */
USEFORM("uFrame1.cpp", Frame1); /* TFrame: File Type */
USEFORM("uGestionarAlarmas.cpp", fGestionarAlarmas);
USEFORM("uFrecuenciaComidas.cpp", fFrecuenciaComidas);
USEFORM("uFrame4.cpp", Frame4); /* TFrame: File Type */
USEFORM("uFormulaComidas.cpp", fFormulaComidas);
USEFORM("uDatos.cpp", fDatos);
USEFORM("uCuentas.cpp", fCuentas);
USEFORM("uConfigurarAlarma.cpp", fConfigurarAlarma);
USEFORM("uFacturacionMensual.cpp", fFacturacionMensual);
USEFORM("uEmitirComprobanteElectronico.cpp", fEmitirComprobanteElectronico);
USEFORM("uEmitirCompElectMonotributo.cpp", fEmitirCompElectMonotributo);
USEFORM("uPausa.cpp", fPausa);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfMain), &fMain);
		Application->CreateForm(__classid(TfAgregarCliente), &fAgregarCliente);
		Application->CreateForm(__classid(TfModificarCliente), &fModificarCliente);
		Application->CreateForm(__classid(TfRepartidores), &fRepartidores);
		Application->CreateForm(__classid(TfRepartos), &fRepartos);
		Application->CreateForm(__classid(TfSeleccionarCliente), &fSeleccionarCliente);
		Application->CreateForm(__classid(TfPedidos), &fPedidos);
		Application->CreateForm(__classid(TfRecetas), &fRecetas);
		Application->CreateForm(__classid(TfAgregarComida), &fAgregarComida);
		Application->CreateForm(__classid(TfModificarComida), &fModificarComida);
		Application->CreateForm(__classid(TfSeleccionarComida), &fSeleccionarComida);
		Application->CreateForm(__classid(TfMenuSemanal), &fMenuSemanal);
		Application->CreateForm(__classid(TfMenuDelDia), &fMenuDelDia);
		Application->CreateForm(__classid(TfProductos), &fProductos);
		Application->CreateForm(__classid(TfCargarPagos), &fCargarPagos);
		Application->CreateForm(__classid(TfImprimirPlanillas), &fImprimirPlanillas);
		Application->CreateForm(__classid(TfConfiguraciones), &fConfiguraciones);
		Application->CreateForm(__classid(TfCuentas), &fCuentas);
		Application->CreateForm(__classid(TfImprimirCuentas), &fImprimirCuentas);
		Application->CreateForm(__classid(TfImprimirResumenManual), &fImprimirResumenManual);
		Application->CreateForm(__classid(TfComidasExcluidas), &fComidasExcluidas);
		Application->CreateForm(__classid(TfVerCargaManual), &fVerCargaManual);
		Application->CreateForm(__classid(TfDatos), &fDatos);
		Application->CreateForm(__classid(TfAlarma), &fAlarma);
		Application->CreateForm(__classid(TfConfigurarAlarma), &fConfigurarAlarma);
		Application->CreateForm(__classid(TfGestionarAlarmas), &fGestionarAlarmas);
		Application->CreateForm(__classid(TfVerHistorialPedidos), &fVerHistorialPedidos);
		Application->CreateForm(__classid(TfMostrarPedidos), &fMostrarPedidos);
		Application->CreateForm(__classid(TfComprobantesX), &fComprobantesX);
		Application->CreateForm(__classid(TfEmitirComprobanteElectronico), &fEmitirComprobanteElectronico);
		Application->CreateForm(__classid(TfVerComprobantesElectronicos), &fVerComprobantesElectronicos);
		Application->CreateForm(__classid(TfPrecios), &fPrecios);
		Application->CreateForm(__classid(TfFacturacionMensual), &fFacturacionMensual);
		Application->CreateForm(__classid(TfClientesHabituales), &fClientesHabituales);
		Application->CreateForm(__classid(TfRastrearPagos), &fRastrearPagos);
		Application->CreateForm(__classid(TfChartPedidosPorHora), &fChartPedidosPorHora);
		Application->CreateForm(__classid(TfChartPedidosPorDia), &fChartPedidosPorDia);
		Application->CreateForm(__classid(TfChartCobrosPorDia), &fChartCobrosPorDia);
		Application->CreateForm(__classid(TfChartComidasMasVendidas), &fChartComidasMasVendidas);
		Application->CreateForm(__classid(TfGestionDeGastos), &fGestionDeGastos);
		Application->CreateForm(__classid(TfValorNutricional), &fValorNutricional);
		Application->CreateForm(__classid(TfIngredientes), &fIngredientes);
		Application->CreateForm(__classid(TfFormulaComidas), &fFormulaComidas);
		Application->CreateForm(__classid(TfInformacionNutricional), &fInformacionNutricional);
		Application->CreateForm(__classid(TfEmitirCompElectMonotributo), &fEmitirCompElectMonotributo);
		Application->CreateForm(__classid(TfFrecuenciaComidas), &fFrecuenciaComidas);
		Application->CreateForm(__classid(TfInfoCliente), &fInfoCliente);
		Application->CreateForm(__classid(TfPausa), &fPausa);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
