object fChartPedidosPorDia: TfChartPedidosPorDia
  Left = 0
  Top = 0
  Caption = 'Pedidos recibidos por d'#237'a del mes'
  ClientHeight = 403
  ClientWidth = 770
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
    Left = 1
    Top = 0
    Width = 744
    Height = 385
    Title.Text.Strings = (
      'CANTIDAD DE VIANDAS EFECTIVAMENTE ENTREGADAS EN CADA D'#205'A DEL MES')
    BottomAxis.Title.Caption = 'D'#205'A DEL MES'
    LeftAxis.Title.Caption = 'CANTIDAD DE VIANDAS ENTREGADAS'
    View3D = False
    View3DOptions.Orthogonal = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      Legend.Visible = False
      Selected.Hover.Visible = False
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Angle = 90
      DataSource = CDS2
      ShowInLegend = False
      XLabelsSource = 'diaDelMes'
      XValues.Name = 'X'
      XValues.Order = loAscending
      XValues.ValueSource = 'diaDelMes'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'cantViandas'
    end
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    ReadOnly = True
    Left = 274
    Top = 352
    object CDS2cantViandas: TFMTBCDField
      FieldName = 'cantViandas'
      Size = 10
    end
    object CDS2diaDelMes: TLargeintField
      FieldName = 'diaDelMes'
    end
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query2
    Left = 256
    Top = 352
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 192
    Top = 352
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
    Left = 152
    Top = 354
  end
end
