object fModificarComida: TfModificarComida
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Modificar una comida...'
  ClientHeight = 496
  ClientWidth = 608
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Shape2: TShape
    Left = 8
    Top = 202
    Width = 589
    Height = 252
    Brush.Style = bsClear
  end
  object Shape1: TShape
    Left = 8
    Top = 8
    Width = 589
    Height = 182
    Brush.Style = bsClear
  end
  inline Frame41: TFrame4
    Left = 14
    Top = 16
    Width = 580
    Height = 169
    Color = clBtnFace
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    ExplicitLeft = 14
    ExplicitTop = 16
    ExplicitWidth = 580
    inherited DBGrid1: TDBGrid
      OnDblClick = Frame41DBGrid1DblClick
    end
    inherited Edit1: TEdit
      OnKeyDown = Frame41Edit1KeyDown
    end
  end
  inline Frame31: TFrame3
    Left = 14
    Top = 212
    Width = 578
    Height = 237
    TabOrder = 1
    ExplicitLeft = 14
    ExplicitTop = 212
    ExplicitWidth = 578
    ExplicitHeight = 237
  end
  object Button1: TButton
    Left = 42
    Top = 463
    Width = 130
    Height = 25
    Caption = 'Guardar'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 235
    Top = 464
    Width = 130
    Height = 25
    Caption = 'Cancelar'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 429
    Top = 464
    Width = 130
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = Button3Click
  end
end
