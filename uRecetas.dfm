object fRecetas: TfRecetas
  Left = 0
  Top = 0
  Caption = 'Gestion de recetario'
  ClientHeight = 701
  ClientWidth = 1064
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
  object Label1: TLabel
    Left = 89
    Top = 11
    Width = 54
    Height = 19
    Caption = 'Label1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Shape1: TShape
    Left = 8
    Top = 43
    Width = 809
    Height = 41
    Brush.Style = bsClear
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Seleccionar'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 271
    Top = 668
    Width = 150
    Height = 25
    Caption = 'Guardar cambios'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 642
    Top = 668
    Width = 150
    Height = 25
    Caption = 'Salir'
    TabOrder = 2
    OnClick = Button3Click
  end
  object REMemo: TRichEdit
    Left = 8
    Top = 88
    Width = 1048
    Height = 574
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = []
    Lines.Strings = (
      'REMemo')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 3
    WantTabs = True
    Zoom = 100
    OnChange = REMemoChange
    OnSelectionChange = REMemoSelectionChange
  end
  object Button4: TButton
    Left = 13
    Top = 48
    Width = 113
    Height = 31
    Caption = 'Color de fuente'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Panel1: TPanel
    Left = 132
    Top = 48
    Width = 28
    Height = 31
    Caption = 'A'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 5
    OnClick = Panel1Click
    OnMouseDown = Panel1MouseDown
    OnMouseUp = Panel1MouseUp
  end
  object Button8: TButton
    Left = 642
    Top = 48
    Width = 97
    Height = 31
    Caption = 'Eliminar formato'
    TabOrder = 6
    OnClick = Button8Click
    OnMouseUp = Button8MouseUp
  end
  object Panel2: TPanel
    Left = 747
    Top = 48
    Width = 30
    Height = 31
    Caption = 'A'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = Panel2Click
    OnMouseDown = Panel2MouseDown
    OnMouseUp = Panel2MouseUp
  end
  object Panel3: TPanel
    Left = 779
    Top = 48
    Width = 29
    Height = 31
    Caption = 'A'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 8
    OnClick = Panel3Click
    OnMouseDown = Panel3MouseDown
    OnMouseUp = Panel3MouseUp
  end
  object Panel4: TPanel
    Left = 401
    Top = 48
    Width = 73
    Height = 31
    Caption = 'Negrita'
    Color = 14540253
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    TabOrder = 9
    OnClick = Panel4Click
    OnMouseUp = Panel4MouseUp
  end
  object Panel5: TPanel
    Left = 480
    Top = 48
    Width = 73
    Height = 31
    Caption = 'Oblicua'
    Color = 14540253
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsItalic]
    ParentBackground = False
    ParentFont = False
    TabOrder = 10
    OnClick = Panel5Click
    OnMouseUp = Panel5MouseUp
  end
  object Panel6: TPanel
    Left = 559
    Top = 48
    Width = 73
    Height = 31
    Caption = 'Subrayada'
    Color = 14540253
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsUnderline]
    ParentBackground = False
    ParentFont = False
    TabOrder = 11
    OnClick = Panel6Click
    OnMouseUp = Panel6MouseUp
  end
  object ComboBox1: TComboBox
    Left = 166
    Top = 48
    Width = 227
    Height = 31
    Style = csOwnerDrawVariable
    DropDownCount = 20
    ItemHeight = 25
    TabOrder = 12
    OnChange = ComboBox1Change
    OnDrawItem = ComboBox1DrawItem
    OnMeasureItem = ComboBox1MeasureItem
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
    Left = 726
    Top = 10
  end
  object QueryReceta: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 776
    Top = 8
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 678
    Top = 8
  end
  object ColorDialog1: TColorDialog
    Left = 64
    Top = 48
  end
end
