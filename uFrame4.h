//---------------------------------------------------------------------------

#ifndef uFrame4H
#define uFrame4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFrame4 : public TFrame
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TDataSource *DataSource1;
	TClientDataSet *ClientDataSet1;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TFrame4(TComponent* Owner);

	void restablecerFrame(void);
	void cerrarFrame(void);
	int idSeleccionado;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame4 *Frame4;
//---------------------------------------------------------------------------
#endif
