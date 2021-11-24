object fClientesHabituales: TfClientesHabituales
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Lista de clientes que consumen vianda todos los d'#237'as'
  ClientHeight = 514
  ClientWidth = 377
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
    Left = 7
    Top = 8
    Width = 362
    Height = 466
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = [fsBold]
    OnColExit = DBGrid1ColExit
    OnDrawColumnCell = DBGrid1DrawColumnCell
    Columns = <
      item
        Expanded = False
        FieldName = 'cliente'
        Title.Alignment = taCenter
        Title.Caption = 'Cliente'
        Width = 213
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Lunes'
        Title.Alignment = taCenter
        Title.Caption = 'L'
        Width = 18
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Martes'
        Title.Alignment = taCenter
        Title.Caption = 'M'
        Width = 18
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Miercoles'
        Title.Alignment = taCenter
        Title.Caption = 'M'
        Width = 18
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Jueves'
        Title.Alignment = taCenter
        Title.Caption = 'J'
        Width = 18
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Viernes'
        Title.Alignment = taCenter
        Title.Caption = 'V'
        Width = 18
        Visible = True
      end
      item
        Alignment = taLeftJustify
        Expanded = False
        FieldName = 'Sabado'
        Title.Alignment = taCenter
        Title.Caption = 'S'
        Width = 18
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 53
    Top = 480
    Width = 269
    Height = 25
    Caption = 'Salir'
    TabOrder = 1
    OnClick = Button1Click
  end
  object CB2: TDBCheckBox
    Left = 256
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Martes'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 3
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object CB3: TDBCheckBox
    Left = 275
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Miercoles'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 4
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object CB4: TDBCheckBox
    Left = 294
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Jueves'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 5
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object CB5: TDBCheckBox
    Left = 313
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Viernes'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 6
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object CB6: TDBCheckBox
    Left = 333
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Sabado'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 7
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object CB1: TDBCheckBox
    Left = 237
    Top = 29
    Width = 14
    Height = 17
    Color = clBtnFace
    DataField = 'Lunes'
    DataSource = DataSource1
    ParentColor = False
    TabOrder = 2
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
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
    Left = 216
    Top = 226
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 272
    Top = 224
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 184
    Top = 168
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 232
    Top = 168
    object CDS1cliente: TWideStringField
      FieldName = 'cliente'
      Size = 40
    end
    object CDS1refCliente: TIntegerField
      FieldName = 'refCliente'
    end
    object CDS1idClienteHabitual: TIntegerField
      FieldName = 'idClienteHabitual'
    end
    object CDS1Lunes: TIntegerField
      FieldName = 'Lunes'
      OnChange = CDS1LunesChange
    end
    object CDS1Martes: TIntegerField
      FieldName = 'Martes'
      OnChange = CDS1MartesChange
    end
    object CDS1Miercoles: TIntegerField
      FieldName = 'Miercoles'
      OnChange = CDS1MiercolesChange
    end
    object CDS1Jueves: TIntegerField
      FieldName = 'Jueves'
      OnChange = CDS1JuevesChange
    end
    object CDS1Viernes: TIntegerField
      FieldName = 'Viernes'
      OnChange = CDS1ViernesChange
    end
    object CDS1Sabado: TIntegerField
      FieldName = 'Sabado'
      OnChange = CDS1SabadoChange
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 272
    Top = 168
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 176
    Top = 224
  end
  object PopupMenu1: TPopupMenu
    Left = 32
    Top = 96
    object Agregaruncliente1: TMenuItem
      Caption = 'Agregar un cliente a la lista'
      OnClick = Agregaruncliente1Click
    end
    object Quitaresteclientedelalista1: TMenuItem
      Caption = 'Quitar este cliente de la lista'
      OnClick = Quitaresteclientedelalista1Click
    end
  end
end
