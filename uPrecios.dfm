object fPrecios: TfPrecios
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Definir precios'
  ClientHeight = 202
  ClientWidth = 186
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
    Left = 18
    Top = 19
    Width = 67
    Height = 13
    Caption = 'Precio Lista 1:'
  end
  object Label2: TLabel
    Left = 18
    Top = 57
    Width = 67
    Height = 13
    Caption = 'Precio Lista 2:'
  end
  object Label3: TLabel
    Left = 18
    Top = 95
    Width = 67
    Height = 13
    Caption = 'Precio Lista 3:'
  end
  object Label4: TLabel
    Left = 18
    Top = 134
    Width = 67
    Height = 13
    Caption = 'Precio Lista 4:'
  end
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 171
    Height = 157
    Brush.Style = bsClear
  end
  object Button1: TButton
    Left = 7
    Top = 171
    Width = 171
    Height = 25
    Caption = 'Guardar cambios'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 108
    Top = 16
    Width = 60
    Height = 21
    Alignment = taCenter
    TabOrder = 1
    Text = 'Edit1'
    OnEnter = Edit1Enter
    OnExit = Edit1Exit
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 108
    Top = 54
    Width = 60
    Height = 21
    Alignment = taCenter
    TabOrder = 2
    Text = 'Edit2'
    OnEnter = Edit2Enter
    OnExit = Edit2Exit
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 108
    Top = 92
    Width = 60
    Height = 21
    Alignment = taCenter
    TabOrder = 3
    Text = 'Edit3'
    OnEnter = Edit3Enter
    OnExit = Edit3Exit
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 108
    Top = 131
    Width = 60
    Height = 21
    Alignment = taCenter
    TabOrder = 4
    Text = 'Edit4'
    OnEnter = Edit4Enter
    OnExit = Edit4Exit
    OnKeyPress = Edit4KeyPress
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
      'User_Name=elsembrador'
      'Password=*-elsembrador63/*'
      'ServerCharSet=utf8'
      'BlobSize=-1'
      'ErrorResourceFile='
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'ConnectTimeout=60')
    Left = 279
    Top = 23
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 319
    Top = 23
  end
end
