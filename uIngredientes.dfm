object fIngredientes: TfIngredientes
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Lista de ingredientes'
  ClientHeight = 399
  ClientWidth = 325
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClick = FormClick
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 15
    Width = 28
    Height = 13
    Caption = 'Filtro:'
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 39
    Width = 308
    Height = 313
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'nombre'
        Title.Alignment = taCenter
        Title.Caption = 'Igrediente'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 42
    Top = 12
    Width = 274
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
  end
  object Button1: TButton
    Left = 21
    Top = 358
    Width = 129
    Height = 25
    Caption = 'Agregar ingrediente'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 173
    Top = 358
    Width = 129
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 42
    Top = 15
    Width = 241
    Height = 92
    Caption = 'Panel1'
    Color = 11579647
    ParentBackground = False
    ShowCaption = False
    TabOrder = 4
    object Label2: TLabel
      Left = 10
      Top = 8
      Width = 41
      Height = 13
      Caption = 'Nombre:'
    end
    object Button3: TButton
      Left = 14
      Top = 56
      Width = 92
      Height = 25
      Caption = 'Agregar'
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 136
      Top = 56
      Width = 92
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 1
      OnClick = Button4Click
    end
    object Edit2: TEdit
      Left = 8
      Top = 27
      Width = 225
      Height = 21
      TabOrder = 2
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
    Left = 64
    Top = 186
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 120
    Top = 186
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 176
    Top = 186
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    ReadOnly = True
    Left = 215
    Top = 90
    object CDS1nombre: TWideStringField
      FieldName = 'nombre'
      Size = 45
    end
    object CDS1idIngrediente: TIntegerField
      FieldName = 'idIngrediente'
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 263
    Top = 90
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 96
    Top = 266
  end
end
