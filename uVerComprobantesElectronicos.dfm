object fVerComprobantesElectronicos: TfVerComprobantesElectronicos
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Ver comprobantes electronicos emitidos'
  ClientHeight = 702
  ClientWidth = 1015
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 529
    Height = 202
    Brush.Style = bsClear
  end
  object Label1: TLabel
    Left = 40
    Top = 14
    Width = 146
    Height = 14
    Alignment = taCenter
    AutoSize = False
    Caption = 'Filtrar por N'#176' de Comp.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 238
    Top = 14
    Width = 251
    Height = 14
    Alignment = taCenter
    AutoSize = False
    Caption = 'Filtrar por fecha informada'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 216
    Width = 1000
    Height = 451
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
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
        Alignment = taCenter
        Expanded = False
        FieldName = 'nroComp'
        Title.Alignment = taCenter
        Title.Caption = 'Recibo N'#176
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 109
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'tipoComp'
        Title.Alignment = taCenter
        Title.Caption = 'Tipo Comp.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 80
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'fecha'
        Title.Alignment = taCenter
        Title.Caption = 'Fecha'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 85
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
        Width = 168
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cuitCliente'
        Title.Alignment = taCenter
        Title.Caption = 'CUIT/DNI'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 90
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cfIVA'
        Title.Alignment = taCenter
        Title.Caption = 'Cond. Frente IVA'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'netoGravado'
        Title.Alignment = taCenter
        Title.Caption = 'Neto Gravado'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'iva21'
        Title.Alignment = taCenter
        Title.Caption = 'IVA al 21%'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'total'
        Title.Alignment = taCenter
        Title.Caption = 'TOTAL'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 100
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 40
    Top = 33
    Width = 146
    Height = 27
    Alignment = taCenter
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object MC1: TMonthCalendar
    Left = 238
    Top = 33
    Width = 251
    Height = 160
    Date = 44056.901485115740000000
    TabOrder = 2
    OnClick = MC1Click
  end
  object Button1: TButton
    Left = 40
    Top = 92
    Width = 146
    Height = 25
    Caption = 'Filtrar por cliente'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 40
    Top = 152
    Width = 146
    Height = 25
    Caption = 'Restablecer'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 407
    Top = 673
    Width = 201
    Height = 25
    Caption = 'Salir'
    TabOrder = 5
    OnClick = Button3Click
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
    Left = 312
    Top = 386
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 376
    Top = 384
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 440
    Top = 384
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    ReadOnly = True
    Left = 488
    Top = 384
    object CDS1idComprobanteElectronico: TIntegerField
      FieldName = 'idComprobanteElectronico'
    end
    object CDS1cliente: TWideStringField
      FieldName = 'cliente'
      Size = 40
    end
    object CDS1cuitCliente: TWideStringField
      FieldName = 'cuitCliente'
      Size = 13
    end
    object CDS1cfIVA: TWideStringField
      FieldName = 'cfIVA'
    end
    object CDS1fecha: TDateField
      FieldName = 'fecha'
    end
    object CDS1tipoComp: TWideStringField
      FieldName = 'tipoComp'
      Size = 15
    end
    object CDS1nroComp: TWideStringField
      FieldName = 'nroComp'
      Size = 15
    end
    object CDS1netoGravado: TFMTBCDField
      FieldName = 'netoGravado'
      DisplayFormat = '$ 0.00'
      Size = 12
    end
    object CDS1iva21: TFMTBCDField
      FieldName = 'iva21'
      DisplayFormat = '$ 0.00'
      Size = 12
    end
    object CDS1total: TFMTBCDField
      FieldName = 'total'
      DisplayFormat = '$ 0.00'
      Size = 12
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 528
    Top = 384
  end
end
