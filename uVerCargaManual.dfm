object fVerCargaManual: TfVerCargaManual
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Clientes que se deben anotar manualmente'
  ClientHeight = 656
  ClientWidth = 978
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 8
    Top = 8
    Width = 962
    Height = 611
    DataSource = DataSource3
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'repartidor'
        Title.Alignment = taCenter
        Title.Caption = 'Repartidor'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 138
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'reparto'
        Title.Alignment = taCenter
        Title.Caption = 'Reparto'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 66
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cliente'
        Title.Alignment = taCenter
        Title.Caption = 'Cliente'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 248
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'bandGrand'
        Title.Alignment = taCenter
        Title.Caption = 'Nro bandejas'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 94
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cantViandas'
        Title.Alignment = taCenter
        Title.Caption = 'Nro Viandas'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 99
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'complemento'
        Title.Alignment = taCenter
        Title.Caption = 'Complementos'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 277
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 376
    Top = 625
    Width = 225
    Height = 25
    Caption = 'Cerrar esta ventana'
    TabOrder = 1
    OnClick = Button1Click
  end
  object MC: TMonthCalendar
    Left = 623
    Top = 543
    Width = 191
    Height = 160
    Date = 43981.875778171300000000
    TabOrder = 2
    Visible = False
  end
  object DataSource3: TDataSource
    DataSet = ClientDataSet3
    Left = 52
    Top = 427
  end
  object QueryCantidad: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 52
    Top = 363
  end
  object DataSetProvider3: TDataSetProvider
    DataSet = QueryCantidad
    Left = 60
    Top = 275
  end
  object ClientDataSet3: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider3'
    ReadOnly = True
    Left = 60
    Top = 203
    object ClientDataSet3idCantidad: TIntegerField
      FieldName = 'idCantidad'
    end
    object ClientDataSet3repartidor: TWideStringField
      FieldName = 'repartidor'
    end
    object ClientDataSet3cliente: TWideStringField
      FieldName = 'cliente'
    end
    object ClientDataSet3bandGrand: TIntegerField
      FieldName = 'bandGrand'
    end
    object ClientDataSet3cantViandas: TFMTBCDField
      FieldName = 'cantViandas'
      DisplayFormat = '0.00'
    end
    object ClientDataSet3complemento: TWideStringField
      FieldName = 'complemento'
    end
    object ClientDataSet3refCliente: TIntegerField
      FieldName = 'refCliente'
    end
    object ClientDataSet3reparto: TIntegerField
      FieldName = 'reparto'
    end
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
    Left = 60
    Top = 115
  end
end
