object fMenuSemanal: TfMenuSemanal
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Configuraci'#243'n de men'#250
  ClientHeight = 687
  ClientWidth = 1370
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
    Left = 293
    Top = 19
    Width = 160
    Height = 18
    Alignment = taCenter
    Caption = 'Men'#250' de un a'#241'o antes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 897
    Top = 19
    Width = 90
    Height = 18
    Alignment = taCenter
    Caption = 'Men'#250' actual'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 5
    Top = 8
    Width = 1357
    Height = 673
  end
  object Button1: TButton
    Left = 798
    Top = 90
    Width = 82
    Height = 25
    Caption = 'Lunes'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 798
    Top = 137
    Width = 82
    Height = 25
    Caption = 'Martes'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 798
    Top = 184
    Width = 82
    Height = 25
    Caption = 'Mi'#233'rcoles'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 798
    Top = 231
    Width = 82
    Height = 25
    Caption = 'Jueves'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 798
    Top = 280
    Width = 82
    Height = 25
    Caption = 'Viernes'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 798
    Top = 327
    Width = 82
    Height = 25
    Caption = 'S'#225'bado'
    TabOrder = 5
    OnClick = Button6Click
  end
  object MC1: TMonthCalendar
    Left = 16
    Top = 10
    Width = 260
    Height = 160
    MultiSelect = True
    Date = 43835.458730578710000000
    Enabled = False
    EndDate = 43835.000000000000000000
    MaxSelectRange = 10000
    ShowToday = False
    ShowTodayCircle = False
    TabOrder = 6
    OnClick = MC1Click
  end
  object Button7: TButton
    Left = 57
    Top = 176
    Width = 75
    Height = 25
    Caption = 'Anterior'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 154
    Top = 176
    Width = 81
    Height = 25
    Caption = 'Siguiente'
    TabOrder = 8
    OnClick = Button8Click
  end
  object ListBox1: TListBox
    Left = 897
    Top = 43
    Width = 457
    Height = 625
    Style = lbOwnerDrawFixed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 20
    ParentFont = False
    TabOrder = 9
    OnClick = ListBox1Click
    OnDrawItem = ListBox1DrawItem
  end
  object CheckBox1: TCheckBox
    Left = 908
    Top = 653
    Width = 15
    Height = 20
    TabOrder = 10
    Visible = False
    OnClick = CheckBox1Click
  end
  object MC2: TMonthCalendar
    Left = 16
    Top = 323
    Width = 260
    Height = 160
    MultiSelect = True
    Date = 43835.458730590280000000
    Enabled = False
    EndDate = 43835.000000000000000000
    MaxSelectRange = 10000
    ShowToday = False
    ShowTodayCircle = False
    TabOrder = 11
    OnClick = MC2Click
  end
  object Button9: TButton
    Left = 57
    Top = 490
    Width = 75
    Height = 25
    Caption = 'Anterior'
    TabOrder = 12
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 154
    Top = 490
    Width = 80
    Height = 25
    Caption = 'Siguiente'
    TabOrder = 13
    OnClick = Button10Click
  end
  object ListBox2: TListBox
    Left = 293
    Top = 43
    Width = 457
    Height = 625
    Style = lbOwnerDrawFixed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 20
    ParentFont = False
    TabOrder = 14
    OnClick = ListBox1Click
    OnDrawItem = ListBox2DrawItem
  end
  object Button11: TButton
    Left = 57
    Top = 531
    Width = 177
    Height = 25
    Caption = 'Copiar a la semana actual'
    TabOrder = 15
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 58
    Top = 213
    Width = 178
    Height = 25
    Caption = 'Eliminar men'#250' actual'
    TabOrder = 16
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 58
    Top = 242
    Width = 178
    Height = 25
    Caption = 'Generar planillas Word'
    TabOrder = 17
    OnClick = Button13Click
  end
  object Panel1: TPanel
    Left = 282
    Top = 465
    Width = 521
    Height = 124
    Caption = 'Generando planillas...'
    Color = 11786751
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Calibri'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    TabOrder = 18
    Visible = False
  end
  object Button14: TButton
    Left = 57
    Top = 581
    Width = 177
    Height = 25
    Caption = 'Agregar una comida'
    TabOrder = 19
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 57
    Top = 612
    Width = 177
    Height = 25
    Caption = 'Modificar una comida'
    TabOrder = 20
    OnClick = Button15Click
  end
  object Button16: TButton
    Left = 56
    Top = 643
    Width = 178
    Height = 25
    Caption = 'Lista de comidas no comprobadas'
    TabOrder = 21
    OnClick = Button16Click
  end
  object Button17: TButton
    Left = 58
    Top = 271
    Width = 177
    Height = 25
    Caption = 'Copiar en formato WhatsApp'
    TabOrder = 22
    OnClick = Button17Click
  end
  object Memo2: TMemo
    Left = 8
    Top = 285
    Width = 33
    Height = 32
    Lines.Strings = (
      'M'
      'e'
      'm'
      'o2')
    TabOrder = 23
    Visible = False
  end
  object Button18: TButton
    Left = 58
    Top = 300
    Width = 87
    Height = 25
    Caption = 'Iniciar copia'
    TabOrder = 24
    OnClick = Button18Click
  end
  object Button19: TButton
    Left = 151
    Top = 300
    Width = 84
    Height = 25
    Caption = 'Detener copia'
    TabOrder = 25
    OnClick = Button19Click
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
    Left = 4
    Top = 65531
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 80
    Top = 65530
  end
  object QueryMenu: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 776
    Top = 10
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 96
    Top = 65530
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 4000
    OnTimer = Timer1Timer
    Left = 256
    Top = 136
  end
end
