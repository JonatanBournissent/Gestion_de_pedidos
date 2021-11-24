object fChartComidasMasVendidas: TfChartComidasMasVendidas
  Left = 0
  Top = 0
  Caption = 'Comidas mas Vendidas'
  ClientHeight = 398
  ClientWidth = 756
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
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
      'COMIDAS MAS VENDIDAS EN EL PER'#205'ODO SELECCIONADO')
    BottomAxis.LabelsAngle = 90
    BottomAxis.Title.Caption = 'C'#211'DIGO DE COMIDA'
    LeftAxis.Title.Caption = 'CANTIDAD DE PORCIONES VENDIDAS'
    Panning.MouseWheel = pmwNone
    Zoom.MouseWheel = pmwNormal
    BevelOuter = bvNone
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      24
      15
      24)
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      Legend.Visible = False
      Selected.Hover.Visible = False
      Marks.Frame.Visible = False
      Marks.Transparent = True
      Marks.Style = smsValue
      Marks.Angle = 90
      Marks.AutoPosition = False
      DataSource = CDS2
      ShowInLegend = False
      XLabelsSource = 'nombre'
      XValues.Name = 'X'
      XValues.Order = loDescending
      XValues.ValueSource = 'nroRepe'
      YValues.Name = 'Bar'
      YValues.Order = loNone
      YValues.ValueSource = 'nroRepe'
    end
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    ReadOnly = True
    Left = 274
    Top = 352
    object CDS2refComida: TIntegerField
      FieldName = 'refComida'
    end
    object CDS2nombre: TWideStringField
      FieldName = 'nombre'
      Size = 15
    end
    object CDS2nroRepe: TLargeintField
      FieldName = 'nroRepe'
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
