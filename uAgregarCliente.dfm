object fAgregarCliente: TfAgregarCliente
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Agregar un nuevo cliente'
  ClientHeight = 493
  ClientWidth = 713
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  inline Frame11: TFrame1
    Left = 8
    Top = 8
    Width = 699
    Height = 433
    TabOrder = 0
    ExplicitLeft = 8
    ExplicitTop = 8
    ExplicitWidth = 699
    ExplicitHeight = 433
    inherited SQLTable1: TSQLTable
      Left = 640
      Top = 104
    end
    inherited Query3: TSQLQuery
      Left = 648
      Top = 232
    end
  end
  object Button1: TButton
    Left = 71
    Top = 460
    Width = 150
    Height = 25
    Caption = 'Guardar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 279
    Top = 460
    Width = 150
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 487
    Top = 460
    Width = 150
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = Button3Click
  end
end
