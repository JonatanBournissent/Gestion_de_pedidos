object fChartPedidosPorHora: TfChartPedidosPorHora
  Left = 0
  Top = 0
  Caption = 'Cantidad de pedidos por hora del d'#237'a'
  ClientHeight = 446
  ClientWidth = 731
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object DBChart1: TDBChart
    Left = 0
    Top = 0
    Width = 721
    Height = 425
    Title.Text.Strings = (
      'CANTIDAD DE PEDIDOS DISCRIMINADOS POR HORARIO DEL D'#205'A')
    BottomAxis.Title.Caption = 'HORARIO DEL D'#205'A'
    LeftAxis.Title.Caption = 'CANTIDAD DE PEDIDOS INGRESADOS'
    Legend.Visible = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      24
      15
      24)
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      Marks.Transparent = True
      Marks.Style = smsValue
      DataSource = CDS2
      XLabelsSource = 'horaDelDia'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'horaDelDia'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'cantPedidos'
    end
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    ReadOnly = True
    Left = 332
    Top = 384
    object CDS2cantPedidos: TLargeintField
      FieldName = 'cantPedidos'
    end
    object CDS2horaDelDia: TIntegerField
      FieldName = 'horaDelDia'
    end
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query2
    Left = 280
    Top = 384
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 224
    Top = 384
  end
  object SQLConnection1: TSQLConnection
    ConnectionName = 'MySQLConnection'
    DriverName = 'MySQL'
    KeepConnection = False
    LoginPrompt = False
    Params.Strings = (
      'DriverName=MySQL'
      'HostName=localhost'
      'Database=dbes'
      'User_Name=root'
      'Password=CBR900rr'
      'ServerCharSet=utf8'
      'BlobSize=-1'
      'ErrorResourceFile='
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'ConnectTimeout=60')
    Left = 160
    Top = 386
  end
end
