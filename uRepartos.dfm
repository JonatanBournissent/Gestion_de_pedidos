object fRepartos: TfRepartos
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Organizador de repartos'
  ClientHeight = 664
  ClientWidth = 561
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
    Top = 9
    Width = 345
    Height = 647
    DataSource = DataSource1
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'calle'
        Title.Alignment = taCenter
        Title.Caption = 'Calle'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 223
        Visible = True
      end
      item
        Alignment = taRightJustify
        Expanded = False
        FieldName = 'numero'
        Title.Alignment = taCenter
        Title.Caption = 'N'#250'mero'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 88
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 384
    Top = 185
    Width = 169
    Height = 25
    Caption = 'Agregar registro'
    TabOrder = 1
    OnClick = Button1Click
  end
  object RG1: TRadioGroup
    Left = 384
    Top = 9
    Width = 169
    Height = 81
    ItemIndex = 0
    Items.Strings = (
      'Lunes a viernes'
      'Sabados')
    TabOrder = 2
    OnClick = RG1Click
  end
  object ComboBox1: TComboBox
    Left = 384
    Top = 96
    Width = 169
    Height = 22
    Style = csOwnerDrawFixed
    DropDownCount = 15
    TabOrder = 3
    OnChange = ComboBox1Change
  end
  object Button6: TButton
    Left = 384
    Top = 216
    Width = 169
    Height = 25
    Caption = 'Agregar espacio'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 383
    Top = 145
    Width = 170
    Height = 25
    Caption = 'Previsualizar planilla impresa'
    TabOrder = 5
    OnClick = Button7Click
  end
  object GroupBox1: TGroupBox
    Left = 367
    Top = 272
    Width = 202
    Height = 313
    Caption = 'Opciones de domicilio seleccionado:'
    TabOrder = 6
    object Button2: TButton
      Left = 16
      Top = 82
      Width = 169
      Height = 25
      Caption = 'Desplazar hacia arriba'
      DoubleBuffered = False
      ParentDoubleBuffered = False
      TabOrder = 0
      OnMouseDown = Button2MouseDown
      OnMouseUp = Button2MouseUp
    end
    object Button3: TButton
      Left = 16
      Top = 113
      Width = 169
      Height = 25
      Caption = 'Desplazar hacia abajo'
      TabOrder = 1
      OnMouseDown = Button3MouseDown
      OnMouseUp = Button3MouseUp
    end
    object ComboBox2: TComboBox
      Left = 16
      Top = 189
      Width = 169
      Height = 22
      Style = csOwnerDrawFixed
      DropDownCount = 15
      TabOrder = 2
    end
    object Button4: TButton
      Left = 16
      Top = 227
      Width = 169
      Height = 25
      Caption = 'Transferir a planilla seleccionada'
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 16
      Top = 31
      Width = 169
      Height = 25
      Caption = 'Quitar de la planilla'
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button8: TButton
      Left = 16
      Top = 274
      Width = 169
      Height = 25
      Caption = 'Transferir todas las direcciones'
      TabOrder = 5
      OnClick = Button8Click
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
    Left = 661
    Top = 96
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 789
    Top = 96
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 853
    Top = 96
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 901
    Top = 96
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 720
    Top = 96
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 696
    Top = 208
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 180
    OnTimer = Timer1Timer
    Left = 696
    Top = 304
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 180
    OnTimer = Timer2Timer
    Left = 696
    Top = 352
  end
  object PopupMenu1: TPopupMenu
    Left = 72
    Top = 224
    object Quitardeestaplanilla1: TMenuItem
      Caption = 'Quitar de esta planilla'
      OnClick = Quitardeestaplanilla1Click
    end
    object ransferira1: TMenuItem
      Caption = 'Transferir a...'
      object Item11: TMenuItem
        Caption = 'Item1'
        OnClick = Item11Click
      end
      object Item21: TMenuItem
        Caption = 'Item2'
        OnClick = Item21Click
      end
      object Item31: TMenuItem
        Caption = 'Item3'
        OnClick = Item31Click
      end
      object Item41: TMenuItem
        Caption = 'Item4'
        OnClick = Item41Click
      end
      object Item51: TMenuItem
        Caption = 'Item5'
        OnClick = Item51Click
      end
      object Item61: TMenuItem
        Caption = 'Item6'
        OnClick = Item61Click
      end
      object Item71: TMenuItem
        Caption = 'Item7'
        OnClick = Item71Click
      end
      object Item81: TMenuItem
        Caption = 'Item8'
        OnClick = Item81Click
      end
      object Item91: TMenuItem
        Caption = 'Item9'
        OnClick = Item91Click
      end
      object Item101: TMenuItem
        Caption = 'Item10'
        OnClick = Item101Click
      end
      object Item111: TMenuItem
        Caption = 'Item11'
        OnClick = Item111Click
      end
      object Item121: TMenuItem
        Caption = 'Item12'
        OnClick = Item121Click
      end
      object Item131: TMenuItem
        Caption = 'Item13'
        OnClick = Item131Click
      end
      object Item141: TMenuItem
        Caption = 'Item14'
        OnClick = Item141Click
      end
      object Item151: TMenuItem
        Caption = 'Item15'
        OnClick = Item151Click
      end
    end
    object Verestadodecuentacorriente1: TMenuItem
      Caption = 'Ver estado de cuenta corriente'
      OnClick = Verestadodecuentacorriente1Click
    end
    object Desplazarhaciaarriba1: TMenuItem
      Caption = 'Desplazar hacia arriba'
      OnClick = Desplazarhaciaarriba1Click
    end
    object Desplazarhaciaabajo1: TMenuItem
      Caption = 'Desplazar hacia abajo'
      OnClick = Desplazarhaciaabajo1Click
    end
  end
end
