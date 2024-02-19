object fImprimirCuentas: TfImprimirCuentas
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Impresion de res'#250'menes'
  ClientHeight = 703
  ClientWidth = 973
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
    Left = 273
    Top = 42
    Width = 625
    Height = 650
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnColExit = DBGrid1ColExit
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnKeyPress = DBGrid1KeyPress
    Columns = <
      item
        Expanded = False
        FieldName = 'calle'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'Calle'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 122
        Visible = True
      end
      item
        Alignment = taRightJustify
        Expanded = False
        FieldName = 'numero'
        ReadOnly = True
        Title.Alignment = taCenter
        Title.Caption = 'N'#250'mero'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 71
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'unidadesPeriodo'
        Title.Alignment = taCenter
        Title.Caption = 'Unid.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 75
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'saldoAnterior'
        Title.Alignment = taCenter
        Title.Caption = 'Saldo'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 75
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'subtotal'
        Title.Alignment = taCenter
        Title.Caption = 'Subtotal'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 75
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'deudaTotal'
        Title.Alignment = taCenter
        Title.Caption = 'Total'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 75
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'agregado'
        Title.Alignment = taCenter
        Title.Caption = 'Agregar'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 75
        Visible = True
      end
      item
        Alignment = taCenter
        DropDownRows = 2
        Expanded = False
        FieldName = 'imprimir'
        Title.Alignment = taCenter
        Title.Caption = 'I'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 16
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 8
    Top = 369
    Width = 259
    Height = 28
    Caption = 'Calcular deudas'
    TabOrder = 1
    OnClick = Button1Click
  end
  object MC: TMonthCalendar
    Left = 8
    Top = 8
    Width = 259
    Height = 160
    Date = 43949.846167986110000000
    MaxSelectRange = 500
    TabOrder = 2
    OnClick = MCClick
  end
  object RG1: TRadioGroup
    Left = 8
    Top = 199
    Width = 121
    Height = 107
    ItemIndex = 0
    Items.Strings = (
      'Semanal'
      'Mensual'
      'Diario')
    TabOrder = 3
    OnClick = RG1Click
  end
  object CB: TDBCheckBox
    Left = 912
    Top = 187
    Width = 14
    Height = 17
    DataField = 'imprimir'
    DataSource = DataSource1
    TabOrder = 4
    ValueChecked = '1'
    ValueUnchecked = '0'
    Visible = False
  end
  object Button4: TButton
    Left = 8
    Top = 467
    Width = 259
    Height = 28
    Caption = 'Imprimir desde seleccionado'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 273
    Top = 8
    Width = 113
    Height = 28
    Caption = 'Marcar todas'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 416
    Top = 8
    Width = 113
    Height = 28
    Caption = 'Desmarcar todas'
    TabOrder = 7
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 426
    Width = 259
    Height = 28
    Caption = 'Imprimir todo'
    TabOrder = 8
    OnClick = Button7Click
  end
  object RG2: TRadioGroup
    Left = 144
    Top = 199
    Width = 123
    Height = 107
    ItemIndex = 0
    Items.Strings = (
      'Lunes a viernes'
      'Sabados')
    TabOrder = 9
  end
  object Button8: TButton
    Left = 8
    Top = 331
    Width = 259
    Height = 28
    Caption = 'Seleccionar un cliente'
    TabOrder = 10
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 608
    Width = 259
    Height = 28
    Caption = 'Comoprobante manual'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Button2: TButton
    Left = 8
    Top = 642
    Width = 259
    Height = 28
    Caption = 'Imprimir en PDF'
    TabOrder = 12
    OnClick = Button2Click
  end
  object chbTicket: TCheckBox
    Left = 8
    Top = 512
    Width = 177
    Height = 17
    Caption = 'Imprimir en impresora de planillas'
    TabOrder = 13
    OnClick = chbTicketClick
  end
  object CheckBox1: TCheckBox
    Left = 550
    Top = 13
    Width = 169
    Height = 17
    Caption = 'Forzar rec'#225'lculo completo'
    TabOrder = 14
  end
  object DataSource1: TDataSource
    DataSet = CDS
    Left = 839
    Top = 168
  end
  object CDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 839
    Top = 208
    object CDSidCliente: TIntegerField
      FieldName = 'idCliente'
    end
    object CDScalle: TWideStringField
      FieldName = 'calle'
    end
    object CDSnumero: TWideStringField
      FieldName = 'numero'
    end
    object CDSunidadesPeriodo: TFMTBCDField
      FieldName = 'unidadesPeriodo'
      DisplayFormat = '0.00'
    end
    object CDSdeudaTotal: TFMTBCDField
      FieldName = 'deudaTotal'
      DisplayFormat = '$ 0.00'
    end
    object CDSsaldoAnterior: TFMTBCDField
      FieldName = 'saldoAnterior'
      DisplayFormat = '$ 0.00'
    end
    object CDSnombre: TWideStringField
      FieldName = 'nombre'
    end
    object CDSapellido: TWideStringField
      FieldName = 'apellido'
    end
    object CDSprecio: TFMTBCDField
      FieldName = 'precio'
    end
    object CDSagregado: TFMTBCDField
      FieldName = 'agregado'
      DisplayFormat = '0.00'
    end
    object CDSimprimir: TLargeintField
      FieldName = 'imprimir'
    end
    object CDSrep: TLargeintField
      FieldName = 'rep'
    end
    object CDSsubtotal: TFMTBCDField
      FieldName = 'subtotal'
      DisplayFormat = '$ 0.00'
      Size = 10
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 778
    Top = 208
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 714
    Top = 208
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
    Left = 648
    Top = 208
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 959
    Top = 208
  end
  object frxReport1: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 43953.765854699100000000
    ReportOptions.LastChange = 43953.782712442130000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 912
    Top = 80
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 148.000000000000000000
      PaperHeight = 210.000000000000000000
      PaperSize = 11
      LeftMargin = 4.500000000000000000
      RightMargin = 5.000000000000000000
      TopMargin = 8.000000000000000000
      BottomMargin = 12.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object mDia: TfrxMemoView
        AllowVectorExport = True
        Left = 355.275820000000000000
        Top = 71.811070000000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        AutoWidth = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          '31')
        ParentFont = False
        VAlign = vaCenter
      end
      object mMes: TfrxMemoView
        AllowVectorExport = True
        Left = 385.512060000000000000
        Top = 71.811070000000000000
        Width = 30.236240000000000000
        Height = 18.897650000000000000
        AutoWidth = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          '12')
        ParentFont = False
        VAlign = vaCenter
      end
      object mAno: TfrxMemoView
        AllowVectorExport = True
        Left = 419.527830000000000000
        Top = 71.811070000000000000
        Width = 49.133890000000000000
        Height = 18.897650000000000000
        AutoWidth = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          '2020')
        ParentFont = False
        VAlign = vaCenter
      end
      object mCliente: TfrxMemoView
        AllowVectorExport = True
        Left = 79.370130000000000000
        Top = 192.756030000000000000
        Width = 71.811070000000000000
        Height = 18.897650000000000000
        AutoWidth = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Cliente')
        ParentFont = False
        VAlign = vaCenter
      end
      object mUnidades: TfrxMemoView
        AllowVectorExport = True
        Left = 7.559060000000000000
        Top = 306.141930000000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          '888')
        ParentFont = False
        VAlign = vaCenter
      end
      object mDomicilio: TfrxMemoView
        AllowVectorExport = True
        Left = 49.133890000000000000
        Top = 306.141930000000000000
        Width = 306.141930000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Domicilio')
        ParentFont = False
        VAlign = vaCenter
      end
      object mPrecio: TfrxMemoView
        AllowVectorExport = True
        Left = 359.055350000000000000
        Top = 306.141930000000000000
        Width = 94.488250000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'Precio/Un.')
        ParentFont = False
        VAlign = vaCenter
      end
      object mSubtotal: TfrxMemoView
        AllowVectorExport = True
        Left = 464.882190000000000000
        Top = 306.141930000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'subtotal')
        ParentFont = False
        VAlign = vaCenter
      end
      object mDeudaSaldo: TfrxMemoView
        AllowVectorExport = True
        Left = 52.913420000000000000
        Top = 377.953000000000000000
        Width = 105.826840000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'Deuda anterior')
        ParentFont = False
        VAlign = vaCenter
      end
      object mSaldo: TfrxMemoView
        AllowVectorExport = True
        Left = 464.882190000000000000
        Top = 377.953000000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'saldo')
        ParentFont = False
        VAlign = vaCenter
      end
      object mTotal: TfrxMemoView
        AllowVectorExport = True
        Left = 411.968770000000000000
        Top = 680.315400000000000000
        Width = 109.606370000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haRight
        Memo.UTF8W = (
          '9875,50.-')
        ParentFont = False
        VAlign = vaCenter
      end
    end
  end
  object frxDBDataset2: TfrxDBDataset
    UserName = 'frxDBDataset2'
    CloseDataSource = False
    FieldAliases.Strings = (
      'unidades=unidades'
      'valorUnidad=valorUnidad'
      'subtotal=subtotal'
      'detalle=detalle')
    DataSource = DataSource2
    BCDToCurrency = False
    Left = 816
    Top = 360
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 720
    Top = 424
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query2
    Left = 784
    Top = 424
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    Left = 864
    Top = 424
    object CDS2detalle: TWideStringField
      FieldName = 'detalle'
    end
    object CDS2valorUnidad: TFMTBCDField
      FieldName = 'valorUnidad'
      DisplayFormat = '$ 0.00'
    end
    object CDS2subtotal: TFMTBCDField
      FieldName = 'subtotal'
      DisplayFormat = '$ 0.00'
      Size = 10
    end
    object CDS2unidades: TFMTBCDField
      FieldName = 'unidades'
      DisplayFormat = '0.0'
      Size = 2
    end
  end
  object DataSource2: TDataSource
    DataSet = CDS2
    Left = 927
    Top = 424
  end
  object frxReport2: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 43988.808184317130000000
    ReportOptions.LastChange = 44007.984956712960000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 720
    Top = 296
    Datasets = <
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 148.000000000000000000
      PaperHeight = 210.000000000000000000
      PaperSize = 11
      LeftMargin = 4.500000000000000000
      RightMargin = 5.000000000000000000
      TopMargin = 7.000000000000000000
      BottomMargin = 16.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 302.362204724409400000
        Top = 18.897650000000000000
        Width = 523.464905000000000000
        object mDia: TfrxMemoView
          AllowVectorExport = True
          Left = 347.055350000000000000
          Top = 73.913420000000000000
          Width = 26.456710000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'dfechaDetalle'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."dfechaDetalle"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object mMes: TfrxMemoView
          AllowVectorExport = True
          Left = 389.291590000000000000
          Top = 73.913420000000000000
          Width = 30.236240000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'mfechaDetalle'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."mfechaDetalle"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object mAno: TfrxMemoView
          AllowVectorExport = True
          Left = 432.307360000000000000
          Top = 73.913420000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'yfechaDetalle'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."yfechaDetalle"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590551180000000000
          Top = 164.740157480000000000
          Width = 317.480520000000000000
          Height = 30.236220470000000000
          DataField = 'cliente'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."cliente"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590551180000000000
          Top = 194.976377950000000000
          Width = 317.480520000000000000
          Height = 30.236220470000000000
          DataField = 'domicilio'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."domicilio"]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 26.456692910000000000
        Top = 381.732530000000000000
        Width = 523.464905000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 49.133890000000000000
          Top = 7.559060000000000000
          Width = 302.362400000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'detalle'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."detalle"]')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 3.779530000000000000
          Top = 7.559060000000000000
          Width = 41.574830000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'unidades'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."unidades"]')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 366.614410000000000000
          Top = 7.559060000000000000
          Width = 83.149660000000000000
          Height = 18.897650000000000000
          DataField = 'valorUnidad'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."valorUnidad"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 454.543600000000000000
          Top = 7.559060000000000000
          Width = 68.031540000000000000
          Height = 18.897650000000000000
          DataField = 'subtotal'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."subtotal"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Height = 30.236220472440940000
        Top = 468.661720000000000000
        Width = 523.464905000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 642.520100000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[Page#]')
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 393.071120000000000000
          Top = 1.779530000000000000
          Width = 128.504020000000000000
          Height = 26.456710000000000000
          DataField = 'total'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset3."total"]')
          ParentFont = False
        end
      end
    end
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset3'
    CloseDataSource = False
    FieldAliases.Strings = (
      'cliente=cliente'
      'domicilio=domicilio'
      'total=total'
      'dfechaDetalle=dfechaDetalle'
      'mfechaDetalle=mfechaDetalle'
      'yfechaDetalle=yfechaDetalle'
      'fechaDetalleMensual=fechaDetalleMensual')
    DataSource = DataSource3
    BCDToCurrency = False
    Left = 672
    Top = 360
  end
  object Query3: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 720
    Top = 536
  end
  object DataSetProvider3: TDataSetProvider
    DataSet = Query3
    Left = 784
    Top = 536
  end
  object CDS3: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider3'
    Left = 864
    Top = 536
    object CDS3cliente: TWideStringField
      FieldName = 'cliente'
    end
    object CDS3domicilio: TWideStringField
      FieldName = 'domicilio'
    end
    object CDS3total: TFloatField
      FieldName = 'total'
      DisplayFormat = '0.00'
    end
    object CDS3dfechaDetalle: TDateField
      FieldName = 'dfechaDetalle'
      DisplayFormat = 'dd'
    end
    object CDS3mfechaDetalle: TDateField
      FieldName = 'mfechaDetalle'
      DisplayFormat = 'mm'
    end
    object CDS3yfechaDetalle: TDateField
      FieldName = 'yfechaDetalle'
      DisplayFormat = 'yyyy'
    end
    object CDS3fechaDetalleMensual: TDateField
      FieldName = 'fechaDetalleMensual'
      DisplayFormat = 'dd/mm/yyyy'
    end
  end
  object DataSource3: TDataSource
    DataSet = CDS3
    Left = 927
    Top = 536
  end
  object frxReport3: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 43988.808184317100000000
    ReportOptions.LastChange = 44055.313016782400000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 848
    Top = 296
    Datasets = <
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 4.500000000000000000
      RightMargin = 5.000000000000000000
      TopMargin = 8.000000000000000000
      BottomMargin = 12.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 295.023612280000000000
        Top = 18.897650000000000000
        Width = 757.795765000000000000
        object Shape1: TfrxShapeView
          AllowVectorExport = True
          Left = 343.937230000000000000
          Top = 36.000000000000000000
          Width = 60.472480000000000000
          Height = 68.031540000000000000
          Frame.Typ = []
        end
        object mAno: TfrxMemoView
          AllowVectorExport = True
          Left = 495.779840000000000000
          Top = 62.409400000000000000
          Width = 249.448980000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'fechaDetalleMensual'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."fechaDetalleMensual"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 87.590600000000000000
          Top = 191.929190000000000000
          Width = 340.157700000000000000
          Height = 18.897650000000000000
          DataField = 'cliente'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."cliente"]')
          ParentFont = False
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 87.590600000000000000
          Top = 224.165430000000000000
          Width = 340.157700000000000000
          Height = 18.897650000000000000
          DataField = 'domicilio'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."domicilio"]')
          ParentFont = False
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 431.748300000000000000
          Top = 61.684987500000000000
          Width = 68.031540000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Fecha:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 192.653602500000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Cliente:')
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 224.165430000000000000
          Width = 75.590600000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio:')
          ParentFont = False
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 3.779530000000000000
          Top = 262.740260000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Unid.')
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 79.370130000000000000
          Top = 262.740260000000000000
          Width = 476.220780000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Descripci'#243'n')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Left = 563.149970000000000000
          Top = 262.740260000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Precio')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 661.417750000000000000
          Top = 262.740260000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -15
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Subtotal')
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          AllowVectorExport = True
          Left = 8.000000000000000000
          Top = 153.118120000000000000
          Width = 714.331170000000000000
          Height = 26.456710000000000000
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          DisplayFormat.FormatStr = 'mmmm'
          DisplayFormat.Kind = fkDateTime
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            
              'Detalle de viandas entregadas en [frxDBDataset3."fechaDetalleMen' +
              'sual"]')
          ParentFont = False
        end
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 34.897650000000000000
          Top = 60.456710000000000000
          Width = 264.567100000000000000
          Height = 56.692950000000000000
          Frame.Typ = []
          Picture.Data = {
            0A54504E474F626A65637489504E470D0A1A0A0000000D494844520000023800
            000073080600000095757870000000097048597300002C4A00002C4A01777A74
            4D00002C844944415478DAED5DDD95E336B22EEFFAFDF644603902B723301D81
            DB112CFD76DFDC8E60B9116CCFDB7DB31CC1F644B09C08B627026B2270CFFBEC
            F16549050982F053008AA428D6778E8E5A2D8A408140D58742A1F0C59F7FFE09
            8A737CF9D7BFDE7FFEEF7F5FE6AE8742718DF8BFF75F6C86B7667899F7D7E165
            C64BFFBFDFFDD9CF5D478542A1F84209CE0903B16987377CC140709AB9EBA350
            5C1388D874C3EB6F894B3F0DAF67BC76203B3BC1B25F87FBBDCEDD0E0A856219
            583DC1416F0D1C48CDC3F0FA8AFEFDCB40709EE6AE9B42712D1808463BBCE198
            F89FCC9FBE8503D129262643D97770F010E17B33DC4BBDAB8AD1403601FBDA86
            5EF7F4FEAA13DF6561750467E8BC1B38B8D5CDEB2BCF65DFEA1295427100919B
            5F2B6E811E9DC781986C0BCB476FD00FF4F18D7A71143E0CBABD19DEB6C36B57
            F073243129F2FE5E09CEB270530467E8E0C8BAEFAD7F35F4BE8113134F75E28F
            4327DECC2D8B42710D10203736DEC381E8B0270F43F95B382D897D187E7BCFFD
            AD625D2082F3EF118B5082B330DC1AC1791CDEFE59799BB743277E9C5B168562
            6E0CE402C9440FF9CB5229FC0689F81C5A96DAC2C973B3FFDDF09B76EE76515C
            27C83BDFC261328B2107D2FD5609CEC2706B04076786DF54DEE6C7A1133FCF2D
            8B4231370692D10F6FDF8D5804121D1C6B2F86EC10A942E384930CD740FD385C
            A76353910479F37BA8B7073694E02C0CB746701AEB232A4AFCFC43CE3D860EFC
            C5DC722814734378694A0A1A7FA36083480E4E7ABFAABD174109CEC2705304C7
            078A88EF81E7AE7C3774E087B9EBAC50CC8D81E0EC40CE3048E0DD406E746C2A
            B22014B660A0046761B8798283A0FC369CD9E84F4307DECE5D5F85624E0CE406
            89C4BFE6AE87035D9E526483E2727E17BA9D129C85612D046703BC4EFEF5D081
            7773D757A19813CEB6EC6BC0C781DC6CE6AE84629918F43F2E6B4A041C2BC159
            18D642707099EA3F89CB3E0C9D57B7A02A560DDABDF4C7DCF570F0CB407034F1
            A6A20883FEEF4126585E09CEC2B01682C371B9EBF670C5EA11599EFA00871D4F
            3D7DBE875320FF98B13AEABD51544109CE7AB1168283B3BF9F139769F662C5EA
            E124D6437C1C5E6DEC004DDA71D5C13844E77B3DBC5351032538EBC55A08CE0E
            E2CAF7D3D071EFE6AEA74231379CDD53E8B569B85BB387DF76C3DBDF05ABF376
            285BBDAA8A2A28C1592F6E9EE030E36F7E1B3A6E3B775D158A39E1C4DF64911B
            EB1E38DED0635A6B50346BB142044A70D68B35101C4E1E04DD1EAE583D0672D2
            C0E12C1F3C1CB3EAD4EE8AD3C7114A6E14625082B35EAC81E0708E6F7833745C
            CD90AA583D889840E9C9DFCEBDD023F408FE63177C4062D5E98E29852494E0AC
            17374D702855776ACBAB765A85626410716AE0B0F3CA9D70E029E3B8436BAB47
            3128A4A10467BDB87582D3423A83F12F43A7D519A342A150DC2094E0AC17B74E
            70381959757BB842A150DC2894E0AC17B74E7052C27D1C3AEC66EE7A2A140A85
            621C28C1592F6E96E068F6628542A15028C1592F6E99E06CE13C23AB0F3F0E1D
            564F285628148A1B85129CF5E29609CE0E12A9E387CEFAC5DCF55428140AC578
            5082B35EDC24C161662F7E3774D687B9EBAA5028148AF1A00467BDB85582D341
            FA4C1CCD5EAC502814370E2538EBC52C048712F0A19765432F83DDF07AA9DDB6
            CDCC5EFCF550CE4E502694A321B9F07517A8C37B7A7F21797B8EBC964CFF18AE
            EFA4EAED29C73C1B946543AF902C785ED12BC9F242B288B5A9800C1B7A7F8991
            59E6B3FB44321A799F05FA29A75C84E9333DC9326BDC187948EFA8EEA6ADBBA1
            5EFD9CF51A515E23A3E953DBD0B3A767FA60B58D6B58F159BEC4EE515957BB9E
            E63901FD1DCA266DC631A207213D2C284F03E7F6C20D3DF84875DED71B1C9DBA
            248243FDE71ECE7542482FECEB44EF467E94F5E59A33F3938CF86AF03D760E24
            3D7F7B3CD9ED607432EAC3679FED998CE0D0AE2653D1AF129763877D2C51E4D4
            78BF272EFB30DCFB5E40A60DC9D4429A50C5800FAA87D3833AEB9C8E4CE28909
            4981B7244BAD224065F994E31D1BCA6FE0D02F108644C4602B6EF7B3AFFE5E52
            488920DB0A993F92ACECE7416DFD48E5A6C64108D85FB0AF745C423994FB44ED
            C4695F83C6FA3BA66411DF5F0BC1A1E7BAA18F9C3A35CEE79461B99095FA7007
            797DE9DDF06A6B8C11F5275BB7969CFD1582E967DB299F2D19B54792A9541E1C
            9B5BEB75B50487E46D49DE529DE002F5700F02449A56441066721783990CD868
            E87DE393CF170B4B63B8CB6C8F0B3D3F2AC121C38C15F59D45F381DE634A33FB
            946F66F6E2AAEDE1245707E95D5A3EBCB7FEC6FBB80FF0C278393BC2C40C49A6
            1CA65ED88153C913111F49862DA31E5887D492620DCE3A3E192334F835A4D495
            F521A6482C622329273E9347661BF720A3E443B826823399ACF45CB7C01B133E
            EC4F6DCF2539D4875BF08F5D244E7B4F067DDEC0C1E8D41850ECE3ED98CFB890
            247280E34482F889111C8B98A2BCDC6782B603F596999072DB297BD2E9D47554
            2F884D7088EC613D4B75F319671885E02494F93FE0C02A77746D0771A59FE5B1
            183B7B319D4E8E75CE193038C05086278F7726D6D17D24B0DA905099581F2E41
            3B53C2A488FECDFC6D72965AC8D6737024382392297CC60FBE674383F67944F9
            921301CB5B155BAAA8C135119C2792750C398FB2069E2BF68357C87BD6EC0917
            4D4A503E9F8EFB0D125E3D81FE2F9E3B8CF411D6EBE7CA5B99E53FBC1FB69334
            5112213852DE09662A141B452475EC09832138D42ED8B7ED718B75BE83BCB17C
            4CFF224E7068296A0B7E8FCD836FF02518E2A7E13777C004836D66DDCFBA2FFE
            061B2DF741A3C26B9871361DA4954F95210974A218B083DD7B8819A7AE06AC59
            2A296F549EB58ACEC55E391428845C7CA2B6DA5932A111EC613C636BC00E9A27
            92FE4FE1F2AF86E058726E204C06AA6485530C9D79AE685C3B3828E32DE43FEF
            644C2063EC062752CE7D6A9F7F91D7295097DA193BE21F109E3CE69C669F4215
            C1A1FE88B2E6DA90E08E5F66BCE9C5FDA060697404CFF71E48703C3B9FF7641D
            0E13955C427EB4F1620427E11588CE3019A484A53C99D98B4B96BD50362CBFE4
            C1E67AA0B06EB125B662435268E0BF0F7825B04D76C0571C6CA5388297051520
            966B2B75B3468DFFDF40DD7ABF8DA312F4901B136B65C82E9629A52CF0DE1BAE
            D21AA18DAF8EE058B272BCBA59B2C2692905DB1D8DC53353FF8490D291A843B8
            C43F39A9E2E4094BA03A8E5188FC2789FD3504191339782E9435487E33BDE936
            92CBEA81F250EFE36F24BDD16FE0644B502FE3787AC9ECF32EF6FD4284E02458
            38C77D9EAA048B24300D78F6F6F04296BC474932C184F1C9362415042D7A5657
            016162E71E1AEE8D865ACAEB81B3EBEFACBF2F76FC087B5ABE85D38E0EA308DE
            52B9EE2CB38172C5E7226B879D701B5F33C1D9407AE3410E70068C84E94824A8
            0C7CDEA5ED19F42C5790D1E03361C62AA650BCA35368BCB1CA9F9BE054B635C7
            7EEEA08C70B0571704E5F1C18CA7E324B872B2B0BF27DA9A6A8293E8A82C6F09
            83E0703BF20ED20FFA4D8E6BAE9245D630FE10A9CA3224637A9F0A3B3A8B6056
            B67B08A95972893CDE72E0E01932F58FCA5C310B73917578ACF092DDD5121C92
            15EB261D4760071B4BDC3FB43BABB46F04BD7AA417FE106883EC741B425E0076
            5F9F93E00818EAE47142954B8EA52447727264EAB15FDE2F581DF0029D0B5504
            4782DCD07D5295E0B82139D98BB33A28F39E62E53965E3EF7C8A2D97E0D4B8E7
            A3CAAB7066CC5A4A11500C2E92DE2341A58FEE5FA3BCB9DEC71DC8B87DD90647
            782676ED04A703D925B963B0AD809E30B8D07302C639A8876B3CD3BE76E04268
            C93027E6AC871908CE985E3D4F39351E4A6F9C65A2CC1E64270CC7E7291823F8
            7531C149909BDC8E501D83C3546063ECC88AA16A9D3AD089D83BC02A953A6B86
            54C8E493CF41D06818B00CBF90D237608F03416F4A8EE2C7BA49788E10D74E70
            A409F3D1132CE86D74D3196C406669ED4DC08BD343BD91CAF51AB6504FAA73CB
            949013916BD76A7549CE92FE646551791DC84D18CEECA4A00EFEBE88E024C84D
            6EB023C790259795988D92430E3630A27261D6A101C70071637A040802ABC317
            2A0F2E7992DAE297A3284AE409816DF40515063B2E4298445E3BC169408ECC9D
            794504FB8C4B70A466B2DE650EC17AB3749CD4D203647A8DE6203842CF8E3D21
            1722D973E8AB0B3905F57E3EC1610487E52EA1B41067F4492F08938CCC31D340
            549D79E52E5D64109C1EEA063537EE09652BF13C24C9A66047CF31FA3DC828C3
            2CEF9DA0C290F69E72B126827336A6C7EAA763935EC1BECEDDE52A254FAE8D91
            929335B604895C0EE168A1DE5EE510B80EE408CED116487B95B3080EE3C195AC
            C76E216E2039CB192D08672F167C80D9EB9B4E3DCE66021C8223D449C6565AC9
            E7B1708233577F5382E397B3819196E3C66AC305119C49E3CC7277A6CE40705A
            10981CE7C829E88D9D9AACBA998C1B101AA7D941C68965A022439E88E1E006A4
            72626592D1E8CE3D7B905BAAC8CEBD63D5E3ACE332098E44DDB9312BA5AE588E
            676EC9042777CB365EAB0467242C84E09C8DB905119C645F178C812AD9C92425
            2797E0ECA09EC865AD3850B912FD901B9AD0C175139C7DFBB1090E638DAF243F
            4BAAD373060E6BE7CB8CACDFA078A9CA26812939A4987CC6525803851D92218B
            129C0264CEFC94E054CA2A64D02E08BF609FF07A5826263852C9164B5609A4E4
            4C121C414F4A0991DB81CC4E4C4ECC6B07E3109C0DC8C4BEEEFB098BE0308848
            5604B675DF1EC21D8F15C3C09C1964D76FA4BC194524C7560E0C5220116C9693
            63A28172C311358A0B2738B3ED4A5082E395B381F108CE16EA77C0F9B6884BD5
            D91BEF36655F17CC9B92B51356584E0EC191DA51372791E3A465E960247D2544
            D4F6DED024C161064C95247B6A203C7873CE6FDAC238D98B39F72D41495D3AA0
            CEC420383BA8EF1C39C166785DA9124E25C05B32C1C95D2AC2FA29C119092313
            9CDA7B07277302C420385999AAAFCF9D8E60628223B5C5393B4BB4A0978C933D
            19EB3616C1C1B26B62988EE4904370528D5674BA6CA2D3E5448F7314400901EB
            609C53A711593139B6972A66BCE6708F562AAFE8205682530625385E391B18D1
            C8563CBF8B035A85EE1BACAB756FFCFF1404A756061B25BA7C2A39A51285224A
            3C551D086D8C4979F0C7D65715CFEC6CB21025380CA59095F3C6BA6F2C303527
            5119C7A01725DB1356883EB04F74A575C916FF4E1002A9BC193984A0A69D6A0F
            611D439E1E94E09460D50487CAE820EF19E2D93B0F29835DE115487948518629
            0CBF5439A567FB4D25277E37A7A7AA838988E4040407C9E216F23C527844CEA3
            6D53530407058C2D7794AC1386F2E8649F89C15CEF2CF230D1FDA5947F082C05
            9751DF2DC82CAB4D4570520A43094E0194E078E56C6002E34393910EE2A7D3E3
            B87FCA98C8E59E2787BAF491114781F79CC2F0EF40E8F4E92B27381DC8118CB9
            094E2A3E52ACACC4AA4433BCA1FDC6F7D0784267C193AFBE4182C3F40664B90B
            23F13C45865E3A7BB1E7FE5B18270EC7062AA336670B7BA4BE3DC80C6464C25B
            E6B548584BBD464A704EE562FD94E08C843966D7447636CEBF5F2A7262757050
            F6B1B41AA847BA898F25996A1C979EE6DDC3340447F280E01282837593EAE3A9
            F001FC6E527D45CE913BE7B7D136F2121C6660716E1C496816521AC3B381F476
            32D66165956548213BA8CC53DFB13D4ED25082732A17EBA7046724CCBD7C3082
            2CAEB2EF33B3FB4A1ED311ECEB5395939015DB65514B71503031BF7582538210
            C1E1543E2710183B39CE2C6C37257A6D1E4B1505D3C3549C60CF2A670BE37B71
            0CD8713981BA4A192B9C091679BD32F11223B74A70CAA004C72B670337427004
            DA2277C92B8518C1C1FF4BB5FB6A084EE1521CD66D92B65E2CC1617A6F72F2A4
            A001EBACFBA1F17C12F05670B6C4559D0345E5A09C3547DEE7A274B9AE819915
            893494E09441098E57CE0694E0982DB8B89422A9CF94E080AC075D098E0C7C04
            A785F41E74CEF9501B38C471D81D0B633B58EBC3897B73B7E3159FE45DD02692
            2809B86E40094E084A70C2E52AC1B9315903F2B77088DF315E1BD4313B183906
            4738F055094E5C4EAC9B121C0B3E82B38374C47B30B8D8DA45602FEBBC8703B1
            E9252ACDCC5E2C6AA4275EAA4264911C25385128C109973B19C121DD806D62DE
            7D78A1572FB5BB90CAC6F2564570ACF412F8B275FA5EB7C0C193336A5F172638
            6364CC179193CAB92582135DA55924C161369037AFCC14C4C62A6B0B69B2919D
            288951AED4AE032E58DB3DA96E0D28C10941094EB8DC51094EC4C87220A63FD6
            4270C8BB8D24C0F6D6B8D82FDD4FD1D785094ED1460C2538F275582AC1D94226
            7120D727BEEC0E340AB1B1CAE4642F2EDE1E1E29573A388F8BE449E84A70A250
            82132E7714824363056592D8368BFAA4ADF1E8DC32C1B1480DBED871894A70E4
            E4A47294E04C242B1747829311D7F22DBDB7F4B28387D939184AC1DC76987DD4
            7C46F973909CE47295129C2894E084CB152738D41751174806B2B2BD990139B1
            4E37457048A616E249056D9C6DBA508223272795A304672259B9B0094E0BBC40
            5ADCE5631BF78F7058CBDD4A04F4A63076F662661DAE8EE428C18942094EB85C
            51823341407ED1CEC85B22389E80610E7CA795A30C4B2238639C7B28222795A3
            04672259B9B0094ECE49A4C65BF324BD0C9402330E26B9A423508F39480E92CB
            C64724A7ECDC5341094E19E6223870081EB6C98D9D4F09BF1349D70F0524E716
            080E6DAEC0095E6E3B7AF3814D4470A4CEC78B961383129C5164ED6029042763
            790A13D16DC7260F214C91BD38B33E580E2A9C2977577967314A70A25082132E
            57AA8D7F8153BE2BF4EA3EBA7A42D8D865C5D82D99E0141E3C68103C6C782282
            83FFD73C389950822303437038DBAE11E281BB39602AC8A2AD8495F5DAC2B424
            E7629BFE08A79FCFFAAC49262538059889E0A0B706C9CDC589BE4E7952240749
            D43D77597CA90487267548144B3DC5B18341F1FF4A7084CABF824345B16E4A70
            2C1882C33A246CEE593DB3A356672F2EAC1B963915C909B99C25CFA29AA51D47
            9247094EB85CC93EC39259B08DA73AF5DEC5240447208BFA54470B28C1912D07
            919DA456B8ADA3C71C2D8DE0F4907E30B3069E662CA3659D701E290F491FBA76
            B75C432FEC828FC1BB0C276CAC460DD4E640094E19662438ACB127A888D16BB4
            E11882A5111CA118BFE82465814B37D74E7072E25853D0D3C40560080EA70356
            1F5C5903E6EE8CE07A7341793D1C0645AEA1E2D45302170340780631DA567B2E
            94E09461268293A51F04DDF9AC67BB4082B3857A8F7094704E68F83979CBAACB
            B902393B90DB315642705A90B33D29722C26EBA804E7AF7FF9CB06D281BB88A2
            1C0452600E78B13A5A83229B344D44722E32350BCF201073C75C29C129C05C41
            C63999C305E56511F125111CA9BAA6FAC112976E0A6353A692931BCBCA4109C1
            E9408E604575FF92084E03BCC13437C1A9CE5E4C24690387EDEDA9CCC03DD0A0
            281C542D8C4B722E9E87700747887BEDAC0CB73DE31928C129C0DC89FE98E562
            DB48118EA9337D8F4D70B650EFBD49F6BF090D3F2BC693832B27381BE0390B38
            C84E7532A50E5912C169816788674B6EC5544ED1EDE14E06E464009733288A64
            1F99E45C0CB61176522144629AAC3A6EE1A4BC532E742538055802C1112E3B49
            C4174670249674AE89E0B420A707B3F5D194635A70392EDBA1204824397262DD
            164170B8159D93E0701E5C2AEADBDC83B58DDC1914C5DEAB11BC2A06DE4E2838
            C0A2E514B6C5164EE486338894E01460410447EAF0DAE432D552080EF3281A0E
            AE89E06C40CEB351D2CF269193CADA82CC6EDA1282232567B26C25384C60E74F
            3172664062D4A567DD83B5FDD9E92C55465E38F8D7204470A4E37010D54B559E
            819F7C0E4A70CAB0208223D95753DEC006964170A4EA79350487CA9222B32559
            ACA794B305196F55763E37413993B1974A7018B0F23CE0CB7B5A7006FB0F2E3B
            394A83955FC0D359B2F31214C89003AFD11E7159AC88E450CC0D1A32BB2D59D9
            A695E094614104474C66484F701A5806C1916A93E4189BD8F04B2D9FCCE9D9E0
            C8896DBE830996183D654B8C656ED07E074A70E2B0587DB05199063BE522DDC2
            C17BC066C59E415195F86E844480C15D2B232C5319BC870011F5D40107FA23BD
            DCBA70B7F62AC129C04A094E2A6F4703EB223888ABD8264E656D4066925762F8
            279393CADB8280AECF1CC71B90695FD66EC825119C1678337ED1032C9D4E104B
            276E5F1742CCD8DB8C9A4D523C83A22AC78EE0DABA41D08D3862DC8F01A6E3C7
            BED0DB5E2D6AEB66783DD0CB47B2D829F695E094614104A70139D2119DBC2C88
            E0B420E7814D913E94614AC32F525EAE419C41CE0DC8900D7640B550FFCE499C
            D9C142080EB7612473CCD8197F53837007E9F89B60477014067B99293028AA14
            9B6072B3A81B51D04D3A067248A6129C02AC94E0A4BCB892652D2106078106EB
            3EA21BA5E262B8865F4AB6ACC9B6A0DE658F69212F0E5B4E21FD91A32725CADB
            636C82C33E495CE2104B8770A49412A76E2963BF8343E7CEAA7FC0D05D4BB031
            2740B78371BD3825C835FA4A700AB0528293D2039265897AB39D7AA20C92F17A
            1FE070F8696F9551733AB90F39861FEB513BBED8F18053F631A75CBCAEE61C31
            04FBB81C8176CD3DBCB60339FB521CDF9A8239AA81C3E45981A1198D8203AF89
            09C6EC9CC1CEEE90A95CD6DF83BFC3142B37A140BB9C412635439300DBFD4975
            E7126F0E94E084CB9D93E06C40D098C7E49EF29C9E5A087A1C6CA0BE35636F92
            1D9D01D9A496EAB9E79EF592F2668EAD16EA961BD9611102E33837516707331E
            4BC145D669E2501868EB9931B08C1D33F5752CFE66070745917DAE5264606431
            5DE79E1204877D7C02291394E31A96AAE6CC749B43707620635CB262B6E65218
            73121CE1F2530447F2205CB133EF0275ED601AEF2B929EC996A884E54B7AE447
            D8D881C8D563B575481239812322B28E591192CBC668073B1B82B301DE4C2A6B
            164E0DD1C081DC18A38183AAE51869E640F07638E7B725B91362DE8FA2E53A81
            D944891C92E7A34C59EF0EE4947CCEEE3931830BF5315FA5602BAC15119C2DC8
            1ABB31E370A688A1DBEB6190F1A6949CD7D7437D7FF7F6736A3FFCBF79DE3829
            95F288651BE3CABEC749BA5773FFD2F41F3B906BD36C5EC1C59EE06436120E8C
            0726ABC48EF09DF3DB2643E9B79076F15D184F67F65F7A026D4AF1E69E9E5CBB
            E452BC4D9DDA1107FC1C9E9C1272836D8504536C0031F3EE4893416E52496983
            96B38C79F30467A43C5459BAACA05D243D4E2E8EC1C782866AEF59B6BCF590D8
            D586D7F550EF417A47E599E78065B6701A4B6F5156909B3C4403B723F2621D4B
            4848D4F857F6ED6CCF0D95D9827CAE35F1730F1136C1C9352A66ABB0DDF01B38
            6C136E3CF7C1EB1F0BBC3FA9658A3302E31873EC1C0D7749C7299BA3787170B5
            CC6D755B2867D9553978A8FC3996AB4AC90DFE463A1B736AB79E94C2B5C1EA7F
            23B9D2597DF3D6090E1900D45363C4A2A167A0AB1D9B91B619232BF9599F1436
            569827CB2612A9C38FC7187336F69EA51132C9B357211C7991B47690AF8383BA
            AB50777CA2FA67C792924D7E2E908103EC3F9DA467F44870A8F26318416CCCC7
            0AEF034701A2A2D9C18160D9C4AAC6EB6197BBF75AD1FDEFE96F3360F6F20DAF
            679F31A934D845032922D358E4C145D600A24183AFFB91EB8603A8B795051940
            7C7EF84CA5033B0D906CE033DCDA333F5A8643B9A5833E0DF039F454761F58CA
            BD398243467B03E3B6AD0BEC5BD8CEA8037612A4279005BCB68E0FAE9E1AE928
            19D6528E6739490A47CFC748F221503FE3BD9F32F2D56CE0A08373EB7341160B
            C9297B526E95D30D6F26C7D9149B56F0D9ED75167D2E1E4F6704878441238383
            4A42D963633EE6BAF39CFA9406E6D6661E360DE375115247C5BAD906796F40AD
            CFA5061BCBEC4ADC874CD91A388F8B92043BDBB1559F0E26DCD26ECFF4858399
            53382301C2F13E29848EF6B8458283F5988AD8F82076402DC9D341DDF888EA13
            612255340BA7E5E12DC84CAECFC22826E80FA52912BA8C7A1D1D05F4BC5AC85B
            C22CF68E4CACA7BC752F1D4F17048704AA65D5486C9E245C4D056E4CF4E63CD4
            7A3DAC87CA49018FDF4B0C201C984F63B9BC3D7537EBD5125E939A01D4513D76
            91CB7689EF6D6CE8E5C3771E8283CA3DD45F5E23DFB940427B17F9EEC14370DE
            47EED7031F4DA23DB62B2338F81C62B3D41DF0FB938D0D84FB965D97464A2E92
            09CBEC209C21DC87BD3E818077D953460B076F66EE2C1D752E8EA16D8DDE4D1C
            EFC205C6DC744E86F51EE2FAD9DE428F788178DF41605D4D60F563A9DCE45030
            1E64E9651FF35CD81EA6401D537A8ADB663EC47426D077AFA204C7126C0307C3
            838D9FEAF4D800D898CF358D19A94B477509791DDE51D95BC1F2105B8E3CD456
            E688027C689CCE8A1DB037AF31DA8D29EB1DD5BBA1BA73149C59FEC0D728CF5C
            313E6E91E0DC3AC828E26B13B8A41F5E2F1587031BE3DD442E33C4BFB89C441D
            8C2EC53AA43CCDD1A5228A653231A63B7A7F955AFA1794D9B439BE36904F343F
            C0E9F0EAFEDAE49B035182E38266BB2E26ED28442436F6FFC6DAAE59594F9BE1
            BBB8BAC1E5A9FF06C20A7414A5A6981E4A70144B40C0F65CA5EE17963B66470C
            541F07904570140AC56DE18608CEA8C9F7140AC5F2A00447A158316E88E08806
            F62A148AE543098E42B162DC10C111390C58A150DC0E94E028142BC60D9D263E
            EA01980A8562795082A350AC18374470AAB37D2B148ADB82121C8562C5B82182
            F3EDB5EF4C542814D342098E42B162CC4C70C40E94D42DE20A85C285121C8562
            C59899E07420734487EEA0522814175082A350AC1833139C2DC81CB2F8CB58E7
            B6AD01943578A36D7896D5FDB5E4B46D81F23754BE782662EB0CABEC7B5BF55A
            54D67A25380AC58A3133C1C1EB25CE70FB7AC6634E5A38649AAD3AEF67863A6F
            E0741C031E2BB3DA206DEB581E6C0BD31F2789E9B28E43B24FEBFE34947D577E
            D7A46CC9F13276BDA682121C8562C59899E0607AF9DA030667CB60EC78A07E1B
            EAD1CE518F827A77702037F621BBB391C4B941ED619FB7389921B788847DC0A8
            484EA7C05992ACF1421B001AA75E8BE9E3064A70148A15632E8243CAF7778172
            675B9E72DA6E51CA9F962BFEA08FAB3FE6C2D9D137F9B374E2D144BD69B404F9
            2FFAF876B8F763C66F716CFD3C46BDA680121C8562C59891E0D84AB71478A2FD
            66AE83060719767038E9FAE3F06A96E401A193ABFF431FB38CDE2DC2D9D137B9
            2177BC81A2DE3447B61F73628BE82476E3E97BB3B4433D95E028142BC68C04C7
            9E199662F6ECC538F35FE289D63546EF1631B721B7C9F250F6662CD972D22938
            5EBE45EE545482A350AC1833129C1D1C147A29D06B72BFB419E5B5A0D4E8DD22
            E636E4CE72ADB837CD1AE359B2395ED645EE545482A350AC1873101CA1F81B71
            AF03D66B49CB4C95B29AE7BEFA434AE736E4B4ABED57FA28DAAF6B641B73D96C
            2A28C15128568C99084EEDF254F12C97624FB670D8268DEF1D7DD5D2DF681070
            7B30CA82DEA1D656EC44CE1EE93A44178BD7A0F2F0BECDF0DAD16F37F419BF7B
            70EEFF40D7E335CF76B02B05C23EC2696BF76FF839E6C5F2ECA4F930BCB0FD8D
            418D1A3D5ACA6AE9B7BF51DD5A238F2F18976478A06B80DAB2CF8D6BB1DA1ADB
            09B7387FA4FBB491DFD86DF462B5A5B7BDE937582F63C8CFB68713F9C07B7C45
            6DE7FB7D43F2DED3338BB5A7A91F5E8B9EA32DD52FB93C46EDD15159AF741FB3
            8D1BEFF7E88E4167ACED65A33A74F4BF2E346EAD5D8ED16533F2809936FF8EDA
            E9C97DDECE75F7701A67DBB1C893121C8562C5989AE09092DB41F9F6F02A8F83
            6769EC9355977D4C8FB3A3E618E74306C628656390823B90AC99F99E88C041A9
            E3BD4C3E9233C341C4604B659CE563A17B3DD17DF065B6FD06098AF51B041ABF
            AD27B8DB9BEF859E13CA89F533A4EF893E9BBAFDE4316246E60F54666F1959B6
            178088614FCFE6A7E1F54CEDF76F0804015B3B9142EDED7D5621436EB59FFDBC
            2FE2BE9CF81DAF8CD49E5BBAEE1DD56B47FF6BA8FCE012925397969E83791ED8
            9FBD5BDBADFEFE89AE7DA67B009C766D5D4C18B841E856BD5E4926ACC33FC1D9
            0060F527ECB76FE144B0706970B45D6B4A70148A15630682D341F9F10C498F45
            A2EC162E0DD67B3828FE9D312EA1980C9AE9BF20A1B00C47C8686259BF8263B4
            9CE486678683EE6966E76609EF7B38CDF41B6B067E41C002E5A3A1B977BC44A6
            EEDE99B9638C8ECFD5317A88AF3DDE2D53EF2309B10804DB900DBF79A1F28F84
            D6F2B45CD4DB2251670438D6DE1E997CCFA3A1F637D7F8084ED4D3E1B4E76F1E
            AF9C79965EB26A9346BBAF399EA70BE2EF3C0F1C3BF8796B3D17D30F2EC891E3
            F9F12E9B396416FBE6AB33BEEDBE63EA7A2CCB599A1B65094C098E42B1523886
            BC164982E3319039A89EE59192EDC993B1A17FA351C019A76BAC8D82DF1314E3
            7942E5EC1A0EB75E9697E4621BBB63008E86C32C65A1917214FFB770308E8DF1
            B4383BA02EDADDFDBDB3E4623F736F9B5AA4C047088CC1B820764EBD8EED6911
            00560C88D3BEB6070D9F1F1A4997C4C4DADB36D4BEB6F21A726A436CF336D6DE
            1C4F8745D62E3C344E7FB8F0A639F777FBA8FD5B9F37CDAE3712F9D710F97303
            CDAD3A873C43D83E1704DAF2669DFDCE2253C73E67DF63ACC48A4A70148A95C2
            993DD6224A709C25871CA0027D94C84B824AD6B324848631E405D9C7DA10C169
            E1A0C81F63C9CF9C2538DF6C1FDBE0C2A8D03D917C3DDB9E0A6AB39D7D1FCBF8
            20DE38061DE57B89946F2F51F98C225EFF77F09385A8318F9037ACD31DF7E803
            A75FBA5E95C62118767BFBE431ED1D32D45E434E86BA238F59ACBDA39E0EE7FB
            0B2F05A37E78FD57816789B2FE2D726F7BE9CCF73C4DD96E5FC4E76508A6CF33
            64F78323698DF5FD1031A667FD32D66E4825380AC54AC14CB687EE675BF96CC0
            BFBD1B8D312ABA67679669020BED94EF5C542D4939B2623D36961704E53006D7
            9B2C90DAA72152D3C08168EC9C389E90C1F326210C6DD94502E559D2794FF7D8
            58D7E1DFC6F8F8BC283D90C10C946F1B5CB7EE297296E3392ACE8EECF12C0697
            2F12CB56F67D524B38AE57A8A378ACE035741DD66BDF173C5E10FBB721EF8EE9
            0F3E4F20B6BF218C6F3CCFD2941D5A26B58D7B0ED98E263DB47EE7C62C99FFFB
            64B149E264799794E028142B45201E06032051F9BCC466DC348B6BE8F583F335
            1A57FC2D1A986F200F9FA8FC6ECC6DA9B16518EB9A276A87AD23B799BDBA4671
            031183C6D9B2EB59C67397446CE373768F98E7C3BA06DBD46B1463E487BE4F2D
            5BA0FCC67B149431F3F920BCC1B7A1A5AC407BA796704281CBC16B9C67E55B7E
            C26B631E9660FD1CB2E9230C296F9A7DEF14D9F679AFBC41D3A13E4CB2EE7700
            06FAB5DDB726CB40AE0447A158291C45F60F386CEDCC563AA48C5B386D27CE85
            598AC1D7F3D88ACF51D2C153A34D906920360771361365C4536C21B01D39700F
            9F57C29E09BBC627BA9B27169CEC18D42C6F87739D4D082E029C339E914BF47C
            0425B5FC936A0FCEEEA7D8F214D6C73C4F976C26DB2B468052B97132638B52C1
            D57620B7EDF58A7908F77586D3819CF8FF2EB2C51DEF8B6D693C9F939CF7A504
            47A1582948E97470D859C18A8F60DEB7A13F37F4F2A1A7F7D1D6DF23F5DB4122
            2DBEC997E351F066F9C8B7F324785F8740C4CAB50DAA3BABC7DF7897A71CC314
            DACD83F73206D5F50CB57032A8B1D81CEFF711198A0D994BF6C0C95C6D3D0B9F
            210EB695A7BD424B3CF63D5C6F9DBB8CE60673073D6DCCFA1DDBF0B327D3746C
            0794F33DC247EEBC9E2987FCBB24D8AE339257BC27122FD6C4C813F3377AF240
            25380A856235F89279B2B2BD253CF05B77BBAF3D234EC55384762FD946D347A0
            62CB5351B95CE3E4B937CA1B4A7667933344D430790C59F1D94E8EA1B6974472
            029E7DDF63FB1B42170B320F2D4FD9F7F711DA1E9C5C46DCFA7D99383AC2A97B
            CADB165ADEF37AA612FDC06E8FA2649B8ED76C742F8E121C8542B11A380A3C14
            77B181833BDDDD7562FFF647DAF1B4DFD51333981E82607E8BBFE9AD2DB62992
            72B13C85869E76FA6079B12DC376DDDFD176749413DCC0694FB0AC7DEFBDB781
            7EDB843C39BEB62A7C5E76BBDA5B8C63E4C36DEFEFCD33B23C1576FD4C32C57B
            C7A0874880596EB9032B46C6694FE35DF2B567A87EE6593610C973E490BE9F3E
            9F1238BE50D9769BF9BC47F6FD5DA27EE6A1B483F39D362B3AE836E5B9928612
            1C8542B11A3846CBBBB59D66DFFDE744423752D6CF64F0F1DABFFBEE4BF1102D
            9C0CDADE587AB6AD6F213C7BC6EBCE0C0379311EC9B8C6CA6FE0DCA3B2377A54
            DE3391ADD0EE2E3776E22DED2A33E40BEFF1004EEC546A8926F06CF03EBBCFE1
            BC3D76D2C598BCA64E6704C36EEF8021EF8DC14D2C4FE1FDF17AE3893084D5D7
            9EBEE527FB39EFEB67DA99FA952D9BEBA9C3EFEC1D895F5B04F59EFA95ED25F1
            798FB0ADCC4E3B3B878DDD4F0C696BE1941EC1FCEEA2CD9DBEF642F56848BEDE
            B9660791E5354928C1512814AB81B37536149CD9788C5203CE0E253236AF4416
            F06F5F0657BC0F1A9C1D1C8C83491C78DC826E9581D78462782E76AF38063554
            FEDE7053F96701B58EC10F111CE379718D391A4DAC13D6FF67CFEF5AC8C852EB
            B4AFEB2D3104C75EA20AC98BF73184E09809D931D417CB8986B059F7F7EE70A2
            FB6FA90C43E0DED0BB4D9042EDF900A7A30D42F5B365739341DA7DC9106DFC7F
            67050A9F11F1483BFBC8D359B9446A1EC983D3C389E0F8029F4DFDCCD8F9C377
            ED979E2CD56341098E42A1580D1CF7BE6F1794211EEE965AFCEE6850E1E0D5C0
            979935DBDF9B650354F43DDDF36CC9C1361C74FF544C89BD2B06B31B63FD5E3E
            9FD2DEDBE51BE384DFE1EF8C17669FC08F3C162DC9D9D2EF2F82A789406DE060
            B4F6C69CBC0D0D1C0C6A6397EBE452315E84E8418DD6F578CDF1780A8BB060FD
            2EB23207E435EDDD809388CEDE11E7921792EF05AC1D733E02E5DCBFA5E761BC
            691DB541E7F433BB3D1B2ACBD71FF0FA87CFA773C77E75BE37CFA1A3D7377022
            DA26D0B777088CCF1BB783F0D6737CDEC6B384A4ED9EEE6B489BED957397B60C
            713332D89E3F3B1BB5DDCFA3C1EA125082A350285603379E044E8732E2FB0E0E
            0AFA35F1BB77F49BEDE7F383387FB7EEFB4CD71BB273DCF143E5BC3A06C2361E
            A96DC1587E035686674FF94FF4DAC1C9201F8D13D0E9D79641C7FB1CE32BE074
            5ABAFBDBB7F49D6BC8C05AB67BA0EBBDA76F479E8DA9C33166064E07389E65B3
            760CE57BAAC3CF567B1F9788A80D7686343A04E203BDF78E37CD7E1E2637D413
            9C0E2D357535799B5066FB7049BBBFFC42FDE56F56FDB04EE684F257B08E5170
            8888E94B589F27223BC6038265F770C812DD38FDE4ECEC29CBB375711E9625B3
            BDB4F51E4EA7AFF79E7A997EB423D9EF4C9FB0EE67DAD9904CE3F1432F50510C
            4F2E94E028148A55C189893146E239B1F5794F68805CEBBEEBC9B877703064C7
            D3B4E9BB96BE4363B6F5047EE2F71BFAB8F56CEBC5EF1EA9DE788F2E52FE8355
            4E677DB75F7E83D3D6DE174F1DF0FA3BBAE691BC5377703AF5FA99EEDB3B6DD3
            81752A36B569565E25CBE384F731C6BF87401A0332DA2DB5F77B6A13BBBD0DC1
            7BF20421A31C260EE5C9136F65EA720CCCA6EBCCFDCD72CC57F45D1768CF96CA
            717F7FD61F48463B86C93C4BD397BACFE7E76499FA3ED9BF25F2B32542619EF9
            0F70EAE74F9F0347AA38327DA4E7EF5B86EAE044840C017B8A4C0CB03F7E03A7
            7C57CFA541E7B9F87FB766183F39F5EFE10000000049454E44AE426082}
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 431.748300000000000000
          Top = 98.196815000000000000
          Width = 98.267780000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Detalle N'#176':')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          AllowVectorExport = True
          Left = 532.795610000000000000
          Top = 98.252010000000000000
          Width = 211.653680000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '000126')
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          AllowVectorExport = True
          Left = 349.496290000000000000
          Top = 43.779530000000000000
          Width = 49.133890000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Recibo')
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          AllowVectorExport = True
          Left = 356.055350000000000000
          Top = 60.677180000000000000
          Width = 37.795300000000000000
          Height = 37.795300000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -37
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'X')
          ParentFont = False
          VAlign = vaCenter
        end
        object Line4: TfrxLineView
          AllowVectorExport = True
          Left = 657.638220000000000000
          Top = 260.905690000000000000
          Height = 26.456710000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line5: TfrxLineView
          AllowVectorExport = True
          Left = 559.370440000000000000
          Top = 260.905690000000000000
          Height = 26.456710000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line6: TfrxLineView
          AllowVectorExport = True
          Left = 71.811070000000000000
          Top = 260.905690000000000000
          Height = 26.456710000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line7: TfrxLineView
          AllowVectorExport = True
          Top = 260.905690000000000000
          Width = 757.795275590000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line8: TfrxLineView
          AllowVectorExport = True
          Top = 287.362400000000000000
          Width = 757.795275590000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line10: TfrxLineView
          AllowVectorExport = True
          Height = 287.244094488189000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line12: TfrxLineView
          AllowVectorExport = True
          Left = 757.795275590000000000
          Height = 287.244094488189000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line9: TfrxLineView
          AllowVectorExport = True
          Top = 36.000000000000000000
          Width = 757.795275590000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line11: TfrxLineView
          AllowVectorExport = True
          Top = 138.267780000000000000
          Width = 757.795275590000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line13: TfrxLineView
          AllowVectorExport = True
          Left = 374.173470000000000000
          Top = 104.252010000000000000
          Height = 34.015770000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line14: TfrxLineView
          AllowVectorExport = True
          Width = 757.795275590000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Memo20: TfrxMemoView
          AllowVectorExport = True
          Left = 236.669450000000000000
          Top = 1.779530000000000000
          Width = 275.905690000000000000
          Height = 30.236240000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -24
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'DETALLE')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 374.173470000000000000
        Width = 757.795765000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 79.370130000000000000
          Top = 2.000000000000000000
          Width = 476.220780000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'detalle'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."detalle"]')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 3.779530000000000000
          Top = 2.000000000000000000
          Width = 56.692950000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'unidades'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."unidades"]')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 558.149970000000000000
          Top = 2.000000000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'valorUnidad'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset2."valorUnidad"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 656.417750000000000000
          Top = 2.000000000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'subtotal'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset2."subtotal"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Height = 68.031540000000000000
        Top = 457.323130000000000000
        Width = 757.795765000000000000
        object Shape2: TfrxShapeView
          AllowVectorExport = True
          Width = 759.685530000000000000
          Height = 68.031540000000000000
          Frame.Typ = []
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 343.937230000000000000
          Top = 25.779530000000000000
          Width = 404.409710000000000000
          Height = 18.897650000000000000
          DataField = 'total'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset3."total"]')
          ParentFont = False
          VAlign = vaCenter
        end
      end
    end
  end
  object frxReport5: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 43988.808184317100000000
    ReportOptions.LastChange = 44061.592999074080000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 448
    Top = 352
    Datasets = <
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 80.000000000000000000
      PaperHeight = 260.000000000000000000
      PaperSize = 256
      LeftMargin = 3.000000000000000000
      RightMargin = 2.000000000000000000
      TopMargin = 5.000000000000000000
      BottomMargin = 15.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 207.873954720000000000
        Top = 18.897650000000000000
        Width = 283.464750000000000000
        object mDia: TfrxMemoView
          AllowVectorExport = True
          Left = 72.606370000000000000
          Top = 110.881880000000000000
          Width = 185.196970000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'fechaDetalleMensual'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."fechaDetalleMensual"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 72.606321180000000000
          Top = 135.015667480000000000
          Width = 185.196970000000000000
          Height = 15.118100470000000000
          DataField = 'cliente'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."cliente"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 72.606321180000000000
          Top = 154.472357950000000000
          Width = 185.196970000000000000
          Height = 18.897630470000000000
          DataField = 'domicilio'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."domicilio"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 0.559060000000000000
          Top = 134.795300000000000000
          Width = 52.913420000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Cliente:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 1.559060000000000000
          Top = 154.252010000000000000
          Width = 68.031540000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 0.559060000000000000
          Top = 110.559060000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Fecha:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 4.779530000000000000
          Top = 187.811070000000000000
          Width = 30.236240000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'U.')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Left = 38.118120000000000000
          Top = 187.811070000000000000
          Width = 117.165430000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Descripci'#243'n')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 155.196970000000000000
          Top = 187.811070000000000000
          Width = 60.472480000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Precio')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          AllowVectorExport = True
          Left = 217.094620000000000000
          Top = 187.031540000000000000
          Width = 60.472480000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Subt.')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Top = 182.811070000000000000
          Width = 283.464750000000000000
          Color = clBlack
          Frame.Typ = []
          Frame.Width = 2.000000000000000000
          Diagonal = True
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 119.417440000000000000
          Top = 14.740157480000000000
          Width = 37.795275590000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -24
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'X')
          ParentFont = False
          VAlign = vaCenter
        end
        object Shape1: TfrxShapeView
          AllowVectorExport = True
          Left = 119.299320000000000000
          Top = 1.543290000000000000
          Width = 37.795300000000000000
          Height = 38.929136300000000000
          Frame.Typ = []
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 119.078850000000000000
          Top = 2.000000000000000000
          Width = 37.795275590000000000
          Height = 11.338590000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Recibo')
          ParentFont = False
          VAlign = vaCenter
        end
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 68.811070000000000000
          Top = 50.913420000000000000
          Width = 139.842610000000000000
          Height = 30.236240000000000000
          Frame.Typ = []
          Picture.Data = {
            0A54504E474F626A65637489504E470D0A1A0A0000000D494844520000023800
            000073080600000095757870000000097048597300002C4A00002C4A01777A74
            4D00002C844944415478DAED5DDD95E336B22EEFFAFDF644603902B723301D81
            DB112CFD76DFDC8E60B9116CCFDB7DB31CC1F644B09C08B627026B2270CFFBEC
            F16549050982F053008AA428D6778E8E5A2D8A408140D58742A1F0C59F7FFE09
            8A737CF9D7BFDE7FFEEF7F5FE6AE8742718DF8BFF75F6C86B7667899F7D7E165
            C64BFFBFDFFDD9CF5D478542A1F84209CE0903B16987377CC140709AB9EBA350
            5C1388D874C3EB6F894B3F0DAF67BC76203B3BC1B25F87FBBDCEDD0E0A856219
            583DC1416F0D1C48CDC3F0FA8AFEFDCB40709EE6AE9B42712D1808463BBCE198
            F89FCC9FBE8503D129262643D97770F010E17B33DC4BBDAB8AD1403601FBDA86
            5EF7F4FEAA13DF6561750467E8BC1B38B8D5CDEB2BCF65DFEA1295427100919B
            5F2B6E811E9DC781986C0BCB476FD00FF4F18D7A71143E0CBABD19DEB6C36B57
            F073243129F2FE5E09CEB270530467E8E0C8BAEFAD7F35F4BE8113134F75E28F
            4327DECC2D8B42710D10203736DEC381E8B0270F43F95B382D897D187E7BCFFD
            AD625D2082F3EF118B5082B330DC1AC1791CDEFE59799BB743277E9C5B168562
            6E0CE402C9440FF9CB5229FC0689F81C5A96DAC2C973B3FFDDF09B76EE76515C
            27C83BDFC261328B2107D2FD5609CEC2706B04076786DF54DEE6C7A1133FCF2D
            8B4231370692D10F6FDF8D5804121D1C6B2F86EC10A942E384930CD740FD385C
            A76353910479F37BA8B7073694E02C0CB746701AEB232A4AFCFC43CE3D860EFC
            C5DC722814734378694A0A1A7FA36083480E4E7ABFAABD174109CEC2705304C7
            078A88EF81E7AE7C3774E087B9EBAC50CC8D81E0EC40CE3048E0DD406E746C2A
            B22014B660A0046761B8798283A0FC369CD9E84F4307DECE5D5F85624E0CE406
            89C4BFE6AE87035D9E526483E2727E17BA9D129C85612D046703BC4EFEF5D081
            7773D757A19813CEB6EC6BC0C781DC6CE6AE84629918F43F2E6B4A041C2BC159
            18D642707099EA3F89CB3E0C9D57B7A02A560DDABDF4C7DCF570F0CB407034F1
            A6A20883FEEF4126585E09CEC2B01682C371B9EBF670C5EA11599EFA00871D4F
            3D7DBE875320FF98B13AEABD51544109CE7AB1168283B3BF9F139769F662C5EA
            E124D6437C1C5E6DEC004DDA71D5C13844E77B3DBC5351032538EBC55A08CE0E
            E2CAF7D3D071EFE6AEA74231379CDD53E8B569B85BB387DF76C3DBDF05ABF376
            285BBDAA8A2A28C1592F6E9EE030E36F7E1B3A6E3B775D158A39E1C4DF64911B
            EB1E38DED0635A6B50346BB142044A70D68B35101C4E1E04DD1EAE583D0672D2
            C0E12C1F3C1CB3EAD4EE8AD3C7114A6E14625082B35EAC81E0708E6F7833745C
            CD90AA583D889840E9C9DFCEBDD023F408FE63177C4062D5E98E29852494E0AC
            17374D702855776ACBAB765A85626410716AE0B0F3CA9D70E029E3B8436BAB47
            3128A4A10467BDB87582D3423A83F12F43A7D519A342A150DC2094E0AC17B74E
            70381959757BB842A150DC2894E0AC17B74E7052C27D1C3AEC66EE7A2A140A85
            621C28C1592F6E96E068F6628542A15028C1592F6E99E06CE13C23AB0F3F0E1D
            564F285628148A1B85129CF5E29609CE0E12A9E387CEFAC5DCF55428140AC578
            5082B35EDC24C161662F7E3774D687B9EBAA5028148AF1A00467BDB85582D341
            FA4C1CCD5EAC502814370E2538EBC52C048712F0A19765432F83DDF07AA9DDB6
            CDCC5EFCF550CE4E502694A321B9F07517A8C37B7A7F21797B8EBC964CFF18AE
            EFA4EAED29C73C1B946543AF902C785ED12BC9F242B288B5A9800C1B7A7F8991
            59E6B3FB44321A799F05FA29A75C84E9333DC9326BDC187948EFA8EEA6ADBBA1
            5EFD9CF51A515E23A3E953DBD0B3A767FA60B58D6B58F159BEC4EE515957BB9E
            E63901FD1DCA266DC631A207213D2C284F03E7F6C20D3DF84875DED71B1C9DBA
            248243FDE71ECE7542482FECEB44EF467E94F5E59A33F3938CF86AF03D760E24
            3D7F7B3CD9ED607432EAC3679FED998CE0D0AE2653D1AF129763877D2C51E4D4
            78BF272EFB30DCFB5E40A60DC9D4429A50C5800FAA87D3833AEB9C8E4CE28909
            4981B7244BAD224065F994E31D1BCA6FE0D02F108644C4602B6EF7B3AFFE5E52
            488920DB0A993F92ACECE7416DFD48E5A6C64108D85FB0AF745C423994FB44ED
            C4695F83C6FA3BA66411DF5F0BC1A1E7BAA18F9C3A35CEE79461B99095FA7007
            797DE9DDF06A6B8C11F5275BB7969CFD1582E967DB299F2D19B54792A9541E1C
            9B5BEB75B50487E46D49DE529DE002F5700F02449A56441066721783990CD868
            E87DE393CF170B4B63B8CB6C8F0B3D3F2AC121C38C15F59D45F381DE634A33FB
            946F66F6E2AAEDE1245707E95D5A3EBCB7FEC6FBB80FF0C278393BC2C40C49A6
            1CA65ED88153C913111F49862DA31E5887D492620DCE3A3E192334F835A4D495
            F521A6482C622329273E9347661BF720A3E443B826823399ACF45CB7C01B133E
            EC4F6DCF2539D4875BF08F5D244E7B4F067DDEC0C1E8D41850ECE3ED98CFB890
            247280E34482F889111C8B98A2BCDC6782B603F596999072DB297BD2E9D47554
            2F884D7088EC613D4B75F319671885E02494F93FE0C02A77746D0771A59FE5B1
            183B7B319D4E8E75CE193038C05086278F7726D6D17D24B0DA905099581F2E41
            3B53C2A488FECDFC6D72965AC8D6737024382392297CC60FBE674383F67944F9
            921301CB5B155BAAA8C135119C2792750C398FB2069E2BF68357C87BD6EC0917
            4D4A503E9F8EFB0D125E3D81FE2F9E3B8CF411D6EBE7CA5B99E53FBC1FB69334
            5112213852DE09662A141B452475EC09832138D42ED8B7ED718B75BE83BCB17C
            4CFF224E7068296A0B7E8FCD836FF02518E2A7E13777C004836D66DDCFBA2FFE
            061B2DF741A3C26B9871361DA4954F95210974A218B083DD7B8819A7AE06AC59
            2A296F549EB58ACEC55E391428845C7CA2B6DA5932A111EC613C636BC00E9A27
            92FE4FE1F2AF86E058726E204C06AA6485530C9D79AE685C3B3828E32DE43FEF
            644C2063EC062752CE7D6A9F7F91D7295097DA193BE21F109E3CE69C669F4215
            C1A1FE88B2E6DA90E08E5F66BCE9C5FDA060697404CFF71E48703C3B9FF7641D
            0E13955C427EB4F1620427E11588CE3019A484A53C99D98B4B96BD50362CBFE4
            C1E67AA0B06EB125B662435268E0BF0F7825B04D76C0571C6CA5388297051520
            966B2B75B3468DFFDF40DD7ABF8DA312F4901B136B65C82E9629A52CF0DE1BAE
            D21AA18DAF8EE058B272BCBA59B2C2692905DB1D8DC53353FF8490D291A843B8
            C43F39A9E2E4094BA03A8E5188FC2789FD3504191339782E9435487E33BDE936
            92CBEA81F250EFE36F24BDD16FE0644B502FE3787AC9ECF32EF6FD4284E02458
            38C77D9EAA048B24300D78F6F6F04296BC474932C184F1C9362415042D7A5657
            016162E71E1AEE8D865ACAEB81B3EBEFACBF2F76FC087B5ABE85D38E0EA308DE
            52B9EE2CB38172C5E7226B879D701B5F33C1D9407AE3410E70068C84E94824A8
            0C7CDEA5ED19F42C5790D1E03361C62AA650BCA35368BCB1CA9F9BE054B635C7
            7EEEA08C70B0571704E5F1C18CA7E324B872B2B0BF27DA9A6A8293E8A82C6F09
            83E0703BF20ED20FFA4D8E6BAE9245D630FE10A9CA3224637A9F0A3B3A8B6056
            B67B08A95972893CDE72E0E01932F58FCA5C310B73917578ACF092DDD5121C92
            15EB261D4760071B4BDC3FB43BABB46F04BD7AA417FE106883EC741B425E0076
            5F9F93E00818EAE47142954B8EA52447727264EAB15FDE2F581DF0029D0B5504
            4782DCD07D5295E0B82139D98BB33A28F39E62E53965E3EF7C8A2D97E0D4B8E7
            A3CAAB7066CC5A4A11500C2E92DE2341A58FEE5FA3BCB9DEC71DC8B87DD90647
            782676ED04A703D925B963B0AD809E30B8D07302C639A8876B3CD3BE76E04268
            C93027E6AC871908CE985E3D4F39351E4A6F9C65A2CC1E64270CC7E7291823F8
            7531C149909BDC8E501D83C3546063ECC88AA16A9D3AD089D83BC02A953A6B86
            54C8E493CF41D06818B00CBF90D237608F03416F4A8EE2C7BA49788E10D74E70
            A409F3D1132CE86D74D3196C406669ED4DC08BD343BD91CAF51AB6504FAA73CB
            949013916BD76A7549CE92FE646551791DC84D18CEECA4A00EFEBE88E024C84D
            6EB023C790259795988D92430E3630A27261D6A101C70071637A040802ABC317
            2A0F2E7992DAE297A3284AE409816DF40515063B2E4298445E3BC169408ECC9D
            794504FB8C4B70A466B2DE650EC17AB3749CD4D203647A8DE6203842CF8E3D21
            1722D973E8AB0B3905F57E3EC1610487E52EA1B41067F4492F08938CCC31D340
            549D79E52E5D64109C1EEA063537EE09652BF13C24C9A66047CF31FA3DC828C3
            2CEF9DA0C290F69E72B126827336A6C7EAA763935EC1BECEDDE52A254FAE8D91
            929335B604895C0EE168A1DE5EE510B80EE408CED116487B95B3080EE3C195AC
            C76E216E2039CB192D08672F167C80D9EB9B4E3DCE66021C8223D449C6565AC9
            E7B1708233577F5382E397B3819196E3C66AC305119C49E3CC7277A6CE40705A
            10981CE7C829E88D9D9AACBA998C1B101AA7D941C68965A022439E88E1E006A4
            72626592D1E8CE3D7B905BAAC8CEBD63D5E3ACE332098E44DDB9312BA5AE588E
            676EC9042777CB365EAB0467242C84E09C8DB905119C645F178C812AD9C92425
            2797E0ECA09EC865AD3850B912FD901B9AD0C175139C7DFBB1090E638DAF243F
            4BAAD373060E6BE7CB8CACDFA078A9CA26812939A4987CC6525803851D92218B
            129C0264CEFC94E054CA2A64D02E08BF609FF07A5826263852C9164B5609A4E4
            4C121C414F4A0991DB81CC4E4C4ECC6B07E3109C0DC8C4BEEEFB098BE0308848
            5604B675DF1EC21D8F15C3C09C1964D76FA4BC194524C7560E0C5220116C9693
            63A28172C311358A0B2738B3ED4A5082E395B381F108CE16EA77C0F9B6884BD5
            D91BEF36655F17CC9B92B51356584E0EC191DA51372791E3A465E960247D2544
            D4F6DED024C161064C95247B6A203C7873CE6FDAC238D98B39F72D41495D3AA0
            CEC420383BA8EF1C39C166785DA9124E25C05B32C1C95D2AC2FA29C119092313
            9CDA7B07277302C420385999AAAFCF9D8E60628223B5C5393B4BB4A0978C933D
            19EB3616C1C1B26B62988EE4904370528D5674BA6CA2D3E5448F7314400901EB
            609C53A711593139B6972A66BCE6708F562AAFE8205682530625385E391B18D1
            C8563CBF8B035A85EE1BACAB756FFCFF1404A756061B25BA7C2A39A51285224A
            3C551D086D8C4979F0C7D65715CFEC6CB21025380CA59095F3C6BA6F2C303527
            5119C7A01725DB1356883EB04F74A575C916FF4E1002A9BC193984A0A69D6A0F
            611D439E1E94E09460D50487CAE820EF19E2D93B0F29835DE115487948518629
            0CBF5439A567FB4D25277E37A7A7AA838988E4040407C9E216F23C527844CEA3
            6D53530407058C2D7794AC1386F2E8649F89C15CEF2CF230D1FDA5947F082C05
            9751DF2DC82CAB4D4570520A43094E0194E078E56C6002E34393910EE2A7D3E3
            B87FCA98C8E59E2787BAF491114781F79CC2F0EF40E8F4E92B27381DC8118CB9
            094E2A3E52ACACC4AA4433BCA1FDC6F7D0784267C193AFBE4182C3F40664B90B
            23F13C45865E3A7BB1E7FE5B18270EC7062AA336670B7BA4BE3DC80C6464C25B
            E6B548584BBD464A704EE562FD94E08C843966D7447636CEBF5F2A7262757050
            F6B1B41AA847BA898F25996A1C979EE6DDC3340447F280E01282837593EAE3A9
            F001FC6E527D45CE913BE7B7D136F2121C6660716E1C496816521AC3B381F476
            32D66165956548213BA8CC53DFB13D4ED25082732A17EBA7046724CCBD7C3082
            2CAEB2EF33B3FB4A1ED311ECEB5395939015DB65514B71503031BF7582538210
            C1E1543E2710183B39CE2C6C37257A6D1E4B1505D3C3549C60CF2A670BE37B71
            0CD8713981BA4A192B9C091679BD32F11223B74A70CAA004C72B670337427004
            DA2277C92B8518C1C1FF4BB5FB6A084EE1521CD66D92B65E2CC1617A6F72F2A4
            A001EBACFBA1F17C12F05670B6C4559D0345E5A09C3547DEE7A274B9AE819915
            893494E09441098E57CE0694E0982DB8B89422A9CF94E080AC075D098E0C7C04
            A785F41E74CEF9501B38C471D81D0B633B58EBC3897B73B7E3159FE45DD02692
            2809B86E40094E084A70C2E52AC1B9315903F2B77088DF315E1BD4313B183906
            4738F055094E5C4EAC9B121C0B3E82B38374C47B30B8D8DA45602FEBBC8703B1
            E9252ACDCC5E2C6AA4275EAA4264911C25385128C109973B19C121DD806D62DE
            7D78A1572FB5BB90CAC6F2564570ACF412F8B275FA5EB7C0C193336A5F172638
            6364CC179193CAB92582135DA55924C161369037AFCC14C4C62A6B0B69B2919D
            288951AED4AE032E58DB3DA96E0D28C10941094EB8DC51094EC4C87220A63FD6
            4270C8BB8D24C0F6D6B8D82FDD4FD1D785094ED1460C2538F275582AC1D94226
            7120D727BEEC0E340AB1B1CAE4642F2EDE1E1E29573A388F8BE449E84A70A250
            82132E7714824363056592D8368BFAA4ADF1E8DC32C1B1480DBED871894A70E4
            E4A47294E04C242B1747829311D7F22DBDB7F4B28387D939184AC1DC76987DD4
            7C46F973909CE47295129C2894E084CB152738D41751174806B2B2BD990139B1
            4E37457048A616E249056D9C6DBA508223272795A304672259B9B0094E0BBC40
            5ADCE5631BF78F7058CBDD4A04F4A63076F662661DAE8EE428C18942094EB85C
            51823341407ED1CEC85B22389E80610E7CA795A30C4B2238639C7B28222795A3
            04672259B9B0094ECE49A4C65BF324BD0C9402330E26B9A423508F39480E92CB
            C64724A7ECDC5341094E19E6223870081EB6C98D9D4F09BF1349D70F0524E716
            080E6DAEC0095E6E3B7AF3814D4470A4CEC78B961383129C5164ED6029042763
            790A13D16DC7260F214C91BD38B33E580E2A9C2977577967314A70A25082132E
            57AA8D7F8153BE2BF4EA3EBA7A42D8D865C5D82D99E0141E3C68103C6C782282
            83FFD73C389950822303437038DBAE11E281BB39602AC8A2AD8495F5DAC2B424
            E7629BFE08A79FCFFAAC49262538059889E0A0B706C9CDC589BE4E7952240749
            D43D77597CA90487267548144B3DC5B18341F1FF4A7084CABF824345B16E4A70
            2C1882C33A246CEE593DB3A356672F2EAC1B963915C909B99C25CFA29AA51D47
            9247094EB85CC93EC39259B08DA73AF5DEC5240447208BFA54470B28C1912D07
            919DA456B8ADA3C71C2D8DE0F4907E30B3069E662CA3659D701E290F491FBA76
            B75C432FEC828FC1BB0C276CAC460DD4E640094E19662438ACB127A888D16BB4
            E11882A5111CA118BFE82465814B37D74E7072E25853D0D3C40560080EA70356
            1F5C5903E6EE8CE07A7341793D1C0645AEA1E2D45302170340780631DA567B2E
            94E09461268293A51F04DDF9AC67BB4082B3857A8F7094704E68F83979CBAACB
            B902393B90DB315642705A90B33D29722C26EBA804E7AF7FF9CB06D281BB88A2
            1C0452600E78B13A5A83229B344D44722E32350BCF201073C75C29C129C05C41
            C63999C305E56511F125111CA9BAA6FAC112976E0A6353A692931BCBCA4109C1
            E9408E604575FF92084E03BCC13437C1A9CE5E4C24690387EDEDA9CCC03DD0A0
            281C542D8C4B722E9E87700747887BEDAC0CB73DE31928C129C0DC89FE98E562
            DB48118EA9337D8F4D70B650EFBD49F6BF090D3F2BC693832B27381BE0390B38
            C84E7532A50E5912C169816788674B6EC5544ED1EDE14E06E464009733288A64
            1F99E45C0CB61176522144629AAC3A6EE1A4BC532E742538055802C1112E3B49
            C4174670249674AE89E0B420A707B3F5D194635A70392EDBA1204824397262DD
            164170B8159D93E0701E5C2AEADBDC83B58DDC1914C5DEAB11BC2A06DE4E2838
            C0A2E514B6C5164EE486338894E01460410447EAF0DAE432D552080EF3281A0E
            AE89E06C40CEB351D2CF269193CADA82CC6EDA1282232567B26C25384C60E74F
            3172664062D4A567DD83B5FDD9E92C55465E38F8D7204470A4E37010D54B559E
            819F7C0E4A70CAB0208223D95753DEC006964170A4EA79350487CA9222B32559
            ACA794B305196F55763E37413993B1974A7018B0F23CE0CB7B5A7006FB0F2E3B
            394A83955FC0D359B2F31214C89003AFD11E7159AC88E450CC0D1A32BB2D59D9
            A695E094614104474C66484F701A5806C1916A93E4189BD8F04B2D9FCCE9D9E0
            C8896DBE830996183D654B8C656ED07E074A70E2B0587DB05199063BE522DDC2
            C17BC066C59E415195F86E844480C15D2B232C5319BC870011F5D40107FA23BD
            DCBA70B7F62AC129C04A094E2A6F4703EB223888ABD8264E656D4066925762F8
            279393CADB8280AECF1CC71B90695FD66EC825119C1678337ED1032C9D4E104B
            276E5F1742CCD8DB8C9A4D523C83A22AC78EE0DABA41D08D3862DC8F01A6E3C7
            BED0DB5E2D6AEB66783DD0CB47B2D829F695E094614104A70139D2119DBC2C88
            E0B420E7814D913E94614AC32F525EAE419C41CE0DC8900D7640B550FFCE499C
            D9C142080EB7612473CCD8197F53837007E9F89B60477014067B99293028AA14
            9B6072B3A81B51D04D3A067248A6129C02AC94E0A4BCB892652D2106078106EB
            3EA21BA5E262B8865F4AB6ACC9B6A0DE658F69212F0E5B4E21FD91A32725CADB
            636C82C33E495CE2104B8770A49412A76E2963BF8343E7CEAA7FC0D05D4BB031
            2740B78371BD3825C835FA4A700AB0528293D2039265897AB39D7AA20C92F17A
            1FE070F8696F9551733AB90F39861FEB513BBED8F18053F631A75CBCAEE61C31
            04FBB81C8176CD3DBCB60339FB521CDF9A8239AA81C3E45981A1198D8203AF89
            09C6EC9CC1CEEE90A95CD6DF83BFC3142B37A140BB9C412635439300DBFD4975
            E7126F0E94E084CB9D93E06C40D098C7E49EF29C9E5A087A1C6CA0BE35636F92
            1D9D01D9A496EAB9E79EF592F2668EAD16EA961BD9611102E33837516707331E
            4BC145D669E2501868EB9931B08C1D33F5752CFE66070745917DAE5264606431
            5DE79E1204877D7C02291394E31A96AAE6CC749B43707620635CB262B6E65218
            73121CE1F2530447F2205CB133EF0275ED601AEF2B929EC996A884E54B7AE447
            D8D881C8D563B575481239812322B28E591192CBC668073B1B82B301DE4C2A6B
            164E0DD1C081DC18A38183AAE51869E640F07638E7B725B91362DE8FA2E53A81
            D944891C92E7A34C59EF0EE4947CCEEE3931830BF5315FA5602BAC15119C2DC8
            1ABB31E370A688A1DBEB6190F1A6949CD7D7437D7FF7F6736A3FFCBF79DE3829
            95F288651BE3CABEC749BA5773FFD2F41F3B906BD36C5EC1C59EE06436120E8C
            0726ABC48EF09DF3DB2643E9B79076F15D184F67F65F7A026D4AF1E69E9E5CBB
            E452BC4D9DDA1107FC1C9E9C1272836D8504536C0031F3EE4893416E52496983
            96B38C79F30467A43C5459BAACA05D243D4E2E8EC1C782866AEF59B6BCF590D8
            D586D7F550EF417A47E599E78065B6701A4B6F5156909B3C4403B723F2621D4B
            4848D4F857F6ED6CCF0D95D9827CAE35F1730F1136C1C9352A66ABB0DDF01B38
            6C136E3CF7C1EB1F0BBC3FA9658A3302E31873EC1C0D7749C7299BA3787170B5
            CC6D755B2867D9553978A8FC3996AB4AC90DFE463A1B736AB79E94C2B5C1EA7F
            23B9D2597DF3D6090E1900D45363C4A2A167A0AB1D9B91B619232BF9599F1436
            569827CB2612A9C38FC7187336F69EA51132C9B357211C7991B47690AF8383BA
            AB50777CA2FA67C792924D7E2E908103EC3F9DA467F44870A8F26318416CCCC7
            0AEF034701A2A2D9C18160D9C4AAC6EB6197BBF75AD1FDEFE96F3360F6F20DAF
            679F31A934D845032922D358E4C145D600A24183AFFB91EB8603A8B795051940
            7C7EF84CA5033B0D906CE033DCDA333F5A8643B9A5833E0DF039F454761F58CA
            BD398243467B03E3B6AD0BEC5BD8CEA8037612A4279005BCB68E0FAE9E1AE928
            19D6528E6739490A47CFC748F221503FE3BD9F32F2D56CE0A08373EB7341160B
            C9297B526E95D30D6F26C7D9149B56F0D9ED75167D2E1E4F6704878441238383
            4A42D963633EE6BAF39CFA9406E6D6661E360DE375115247C5BAD906796F40AD
            CFA5061BCBEC4ADC874CD91A388F8B92043BDBB1559F0E26DCD26ECFF4858399
            53382301C2F13E29848EF6B8458283F5988AD8F82076402DC9D341DDF888EA13
            612255340BA7E5E12DC84CAECFC22826E80FA52912BA8C7A1D1D05F4BC5AC85B
            C22CF68E4CACA7BC752F1D4F17048704AA65D5486C9E245C4D056E4CF4E63CD4
            7A3DAC87CA49018FDF4B0C201C984F63B9BC3D7537EBD5125E939A01D4513D76
            91CB7689EF6D6CE8E5C3771E8283CA3DD45F5E23DFB940427B17F9EEC14370DE
            47EED7031F4DA23DB62B2338F81C62B3D41DF0FB938D0D84FB965D97464A2E92
            09CBEC209C21DC87BD3E818077D953460B076F66EE2C1D752E8EA16D8DDE4D1C
            EFC205C6DC744E86F51EE2FAD9DE428F788178DF41605D4D60F563A9DCE45030
            1E64E9651FF35CD81EA6401D537A8ADB663EC47426D077AFA204C7126C0307C3
            838D9FEAF4D800D898CF358D19A94B477509791DDE51D95BC1F2105B8E3CD456
            E688027C689CCE8A1DB037AF31DA8D29EB1DD5BBA1BA73149C59FEC0D728CF5C
            313E6E91E0DC3AC828E26B13B8A41F5E2F1587031BE3DD442E33C4BFB89C441D
            8C2EC53AA43CCDD1A5228A653231A63B7A7F955AFA1794D9B439BE36904F343F
            C0E9F0EAFEDAE49B035182E38266BB2E26ED28442436F6FFC6DAAE59594F9BE1
            BBB8BAC1E5A9FF06C20A7414A5A6981E4A70144B40C0F65CA5EE17963B66470C
            541F07904570140AC56DE18608CEA8C9F7140AC5F2A00447A158316E88E08806
            F62A148AE543098E42B162DC10C111390C58A150DC0E94E028142BC60D9D263E
            EA01980A8562795082A350AC18374470AAB37D2B148ADB82121C8562C5B82182
            F3EDB5EF4C542814D342098E42B162CC4C70C40E94D42DE20A85C285121C8562
            C59899E07420734487EEA0522814175082A350AC1833139C2DC81CB2F8CB58E7
            B6AD01943578A36D7896D5FDB5E4B46D81F23754BE782662EB0CABEC7B5BF55A
            54D67A25380AC58A3133C1C1EB25CE70FB7AC6634E5A38649AAD3AEF67863A6F
            E0741C031E2BB3DA206DEB581E6C0BD31F2789E9B28E43B24FEBFE34947D577E
            D7A46CC9F13276BDA682121C8562C59899E0607AF9DA030667CB60EC78A07E1B
            EAD1CE518F827A77702037F621BBB391C4B941ED619FB7389921B788847DC0A8
            484EA7C05992ACF1421B001AA75E8BE9E3064A70148A15632E8243CAF7778172
            675B9E72DA6E51CA9F962BFEA08FAB3FE6C2D9D137F9B374E2D144BD69B404F9
            2FFAF876B8F763C66F716CFD3C46BDA680121C8562C59891E0D84AB71478A2FD
            66AE83060719767038E9FAE3F06A96E401A193ABFF431FB38CDE2DC2D9D137B9
            2177BC81A2DE3447B61F73628BE82476E3E97BB3B4433D95E028142BC68C04C7
            9E199662F6ECC538F35FE289D63546EF1631B721B7C9F250F6662CD972D22938
            5EBE45EE545482A350AC1833129C1D1C147A29D06B72BFB419E5B5A0D4E8DD22
            E636E4CE72ADB837CD1AE359B2395ED645EE545482A350AC1873101CA1F81B71
            AF03D66B49CB4C95B29AE7BEFA434AE736E4B4ABED57FA28DAAF6B641B73D96C
            2A28C15128568C99084EEDF254F12C97624FB670D8268DEF1D7DD5D2DF681070
            7B30CA82DEA1D656EC44CE1EE93A44178BD7A0F2F0BECDF0DAD16F37F419BF7B
            70EEFF40D7E335CF76B02B05C23EC2696BF76FF839E6C5F2ECA4F930BCB0FD8D
            418D1A3D5ACA6AE9B7BF51DD5A238F2F18976478A06B80DAB2CF8D6BB1DA1ADB
            09B7387FA4FBB491DFD86DF462B5A5B7BDE937582F63C8CFB68713F9C07B7C45
            6DE7FB7D43F2DED3338BB5A7A91F5E8B9EA32DD52FB93C46EDD15159AF741FB3
            8D1BEFF7E88E4167ACED65A33A74F4BF2E346EAD5D8ED16533F2809936FF8EDA
            E9C97DDECE75F7701A67DBB1C893121C8562C5989AE09092DB41F9F6F02A8F83
            6769EC9355977D4C8FB3A3E618E74306C628656390823B90AC99F99E88C041A9
            E3BD4C3E9233C341C4604B659CE563A17B3DD17DF065B6FD06098AF51B041ABF
            AD27B8DB9BEF859E13CA89F533A4EF893E9BBAFDE4316246E60F54666F1959B6
            178088614FCFE6A7E1F54CEDF76F0804015B3B9142EDED7D5621436EB59FFDBC
            2FE2BE9CF81DAF8CD49E5BBAEE1DD56B47FF6BA8FCE012925397969E83791ED8
            9FBD5BDBADFEFE89AE7DA67B009C766D5D4C18B841E856BD5E4926ACC33FC1D9
            0060F527ECB76FE144B0706970B45D6B4A70148A15630682D341F9F10C498F45
            A2EC162E0DD67B3828FE9D312EA1980C9AE9BF20A1B00C47C8686259BF8263B4
            9CE486678683EE6966E76609EF7B38CDF41B6B067E41C002E5A3A1B977BC44A6
            EEDE99B9638C8ECFD5317A88AF3DDE2D53EF2309B10804DB900DBF79A1F28F84
            D6F2B45CD4DB2251670438D6DE1E997CCFA3A1F637D7F8084ED4D3E1B4E76F1E
            AF9C79965EB26A9346BBAF399EA70BE2EF3C0F1C3BF8796B3D17D30F2EC891E3
            F9F12E9B396416FBE6AB33BEEDBE63EA7A2CCB599A1B65094C098E42B1523886
            BC164982E3319039A89EE59192EDC993B1A17FA351C019A76BAC8D82DF1314E3
            7942E5EC1A0EB75E9697E4621BBB63008E86C32C65A1917214FFB770308E8DF1
            B4383BA02EDADDFDBDB3E4623F736F9B5AA4C047088CC1B820764EBD8EED6911
            00560C88D3BEB6070D9F1F1A4997C4C4DADB36D4BEB6F21A726A436CF336D6DE
            1C4F8745D62E3C344E7FB8F0A639F777FBA8FD5B9F37CDAE3712F9D710F97303
            CDAD3A873C43D83E1704DAF2669DFDCE2253C73E67DF63ACC48A4A70148A95C2
            993DD6224A709C25871CA0027D94C84B824AD6B324848631E405D9C7DA10C169
            E1A0C81F63C9CF9C2538DF6C1FDBE0C2A8D03D917C3DDB9E0A6AB39D7D1FCBF8
            20DE38061DE57B89946F2F51F98C225EFF77F09385A8318F9037ACD31DF7E803
            A75FBA5E95C62118767BFBE431ED1D32D45E434E86BA238F59ACBDA39E0EE7FB
            0B2F05A37E78FD57816789B2FE2D726F7BE9CCF73C4DD96E5FC4E76508A6CF33
            64F78323698DF5FD1031A667FD32D66E4825380AC54AC14CB687EE675BF96CC0
            BFBD1B8D312ABA67679669020BED94EF5C542D4939B2623D36961704E53006D7
            9B2C90DAA72152D3C08168EC9C389E90C1F326210C6DD94502E559D2794FF7D8
            58D7E1DFC6F8F8BC283D90C10C946F1B5CB7EE297296E3392ACE8EECF12C0697
            2F12CB56F67D524B38AE57A8A378ACE035741DD66BDF173C5E10FBB721EF8EE9
            0F3E4F20B6BF218C6F3CCFD2941D5A26B58D7B0ED98E263DB47EE7C62C99FFFB
            64B149E264799794E028142B45201E06032051F9BCC466DC348B6BE8F583F335
            1A57FC2D1A986F200F9FA8FC6ECC6DA9B16518EB9A276A87AD23B799BDBA4671
            031183C6D9B2EB59C67397446CE373768F98E7C3BA06DBD46B1463E487BE4F2D
            5BA0FCC67B149431F3F920BCC1B7A1A5AC407BA796704281CBC16B9C67E55B7E
            C26B631E9660FD1CB2E9230C296F9A7DEF14D9F679AFBC41D3A13E4CB2EE7700
            06FAB5DDB726CB40AE0447A158291C45F60F386CEDCC563AA48C5B386D27CE85
            598AC1D7F3D88ACF51D2C153A34D906920360771361365C4536C21B01D39700F
            9F57C29E09BBC627BA9B27169CEC18D42C6F87739D4D082E029C339E914BF47C
            0425B5FC936A0FCEEEA7D8F214D6C73C4F976C26DB2B468052B97132638B52C1
            D57620B7EDF58A7908F77586D3819CF8FF2EB2C51DEF8B6D693C9F939CF7A504
            47A1582948E97470D859C18A8F60DEB7A13F37F4F2A1A7F7D1D6DF23F5DB4122
            2DBEC997E351F066F9C8B7F324785F8740C4CAB50DAA3BABC7DF7897A71CC314
            DACD83F73206D5F50CB57032A8B1D81CEFF711198A0D994BF6C0C95C6D3D0B9F
            210EB695A7BD424B3CF63D5C6F9DBB8CE60673073D6DCCFA1DDBF0B327D3746C
            0794F33DC247EEBC9E2987FCBB24D8AE339257BC27122FD6C4C813F3377AF240
            25380A856235F89279B2B2BD253CF05B77BBAF3D234EC55384762FD946D347A0
            62CB5351B95CE3E4B937CA1B4A7667933344D430790C59F1D94E8EA1B6974472
            029E7DDF63FB1B42170B320F2D4FD9F7F711DA1E9C5C46DCFA7D99383AC2A97B
            CADB165ADEF37AA612FDC06E8FA2649B8ED76C742F8E121C8542B11A380A3C14
            77B181833BDDDD7562FFF647DAF1B4DFD51333981E82607E8BBFE9AD2DB62992
            72B13C85869E76FA6079B12DC376DDDFD176749413DCC0694FB0AC7DEFBDB781
            7EDB843C39BEB62A7C5E76BBDA5B8C63E4C36DEFEFCD33B23C1576FD4C32C57B
            C7A0874880596EB9032B46C6694FE35DF2B567A87EE6593610C973E490BE9F3E
            9F1238BE50D9769BF9BC47F6FD5DA27EE6A1B483F39D362B3AE836E5B9928612
            1C8542B11A3846CBBBB59D66DFFDE744423752D6CF64F0F1DABFFBEE4BF1102D
            9C0CDADE587AB6AD6F213C7BC6EBCE0C0379311EC9B8C6CA6FE0DCA3B2377A54
            DE3391ADD0EE2E3776E22DED2A33E40BEFF1004EEC546A8926F06CF03EBBCFE1
            BC3D76D2C598BCA64E6704C36EEF8021EF8DC14D2C4FE1FDF17AE3893084D5D7
            9EBEE527FB39EFEB67DA99FA952D9BEBA9C3EFEC1D895F5B04F59EFA95ED25F1
            798FB0ADCC4E3B3B878DDD4F0C696BE1941EC1FCEEA2CD9DBEF642F56848BEDE
            B9660791E5354928C1512814AB81B37536149CD9788C5203CE0E253236AF4416
            F06F5F0657BC0F1A9C1D1C8C83491C78DC826E9581D78462782E76AF38063554
            FEDE7053F96701B58EC10F111CE379718D391A4DAC13D6FF67CFEF5AC8C852EB
            B4AFEB2D3104C75EA20AC98BF73184E09809D931D417CB8986B059F7F7EE70A2
            FB6FA90C43E0DED0BB4D9042EDF900A7A30D42F5B365739341DA7DC9106DFC7F
            67050A9F11F1483BFBC8D359B9446A1EC983D3C389E0F8029F4DFDCCD8F9C377
            ED979E2CD56341098E42A1580D1CF7BE6F1794211EEE965AFCEE6850E1E0D5C0
            979935DBDF9B650354F43DDDF36CC9C1361C74FF544C89BD2B06B31B63FD5E3E
            9FD2DEDBE51BE384DFE1EF8C17669FC08F3C162DC9D9D2EF2F82A789406DE060
            B4F6C69CBC0D0D1C0C6A6397EBE452315E84E8418DD6F578CDF1780A8BB060FD
            2EB23207E435EDDD809388CEDE11E7921792EF05AC1D733E02E5DCBFA5E761BC
            691DB541E7F433BB3D1B2ACBD71FF0FA87CFA773C77E75BE37CFA1A3D7377022
            DA26D0B777088CCF1BB783F0D6737CDEC6B384A4ED9EEE6B489BED957397B60C
            713332D89E3F3B1BB5DDCFA3C1EA125082A350285603379E044E8732E2FB0E0E
            0AFA35F1BB77F49BEDE7F383387FB7EEFB4CD71BB273DCF143E5BC3A06C2361E
            A96DC1587E035686674FF94FF4DAC1C9201F8D13D0E9D79641C7FB1CE32BE074
            5ABAFBDBB7F49D6BC8C05AB67BA0EBBDA76F479E8DA9C33166064E07389E65B3
            760CE57BAAC3CF567B1F9788A80D7686343A04E203BDF78E37CD7E1E2637D413
            9C0E2D357535799B5066FB7049BBBFFC42FDE56F56FDB04EE684F257B08E5170
            8888E94B589F27223BC6038265F770C812DD38FDE4ECEC29CBB375711E9625B3
            BDB4F51E4EA7AFF79E7A997EB423D9EF4C9FB0EE67DAD9904CE3F1432F50510C
            4F2E94E028148A55C189893146E239B1F5794F68805CEBBEEBC9B877703064C7
            D3B4E9BB96BE4363B6F5047EE2F71BFAB8F56CEBC5EF1EA9DE788F2E52FE8355
            4E677DB75F7E83D3D6DE174F1DF0FA3BBAE691BC5377703AF5FA99EEDB3B6DD3
            81752A36B569565E25CBE384F731C6BF87401A0332DA2DB5F77B6A13BBBD0DC1
            7BF20421A31C260EE5C9136F65EA720CCCA6EBCCFDCD72CC57F45D1768CF96CA
            717F7FD61F48463B86C93C4BD397BACFE7E76499FA3ED9BF25F2B32542619EF9
            0F70EAE74F9F0347AA38327DA4E7EF5B86EAE044840C017B8A4C0CB03F7E03A7
            7C57CFA541E7B9F87FB766183F39F5EFE10000000049454E44AE426082}
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
        object Memo17: TfrxMemoView
          AllowVectorExport = True
          Left = 0.779530000000000000
          Top = 90.590600000000000000
          Width = 73.322846850000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Recibo N'#176':')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo18: TfrxMemoView
          AllowVectorExport = True
          Left = 73.692950000000000000
          Top = 90.370130000000000000
          Width = 185.196970000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '000126')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677162910000000000
        Top = 287.244280000000000000
        Width = 283.464750000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 38.456710000000000000
          Top = 0.779530000000000000
          Width = 117.165430000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'detalle'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."detalle"]')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 4.559060000000000000
          Top = 0.779530000000000000
          Width = 30.236240000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'unidades'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."unidades"]')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 155.417440000000000000
          Top = 0.779530000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          DataField = 'valorUnidad'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."valorUnidad"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 217.330737950000000000
          Top = 0.779530000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          DataField = 'subtotal'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."subtotal"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        Height = 41.574810470000000000
        ParentFont = False
        Top = 370.393940000000000000
        Width = 283.464750000000000000
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 12.220470000000000000
          Top = 2.000000000000000000
          Width = 264.567100000000000000
          Height = 30.236240000000000000
          DataField = 'total'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset3."total"]')
          ParentFont = False
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Top = 41.574830000000000000
          Width = 283.464750000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
      end
    end
  end
  object frxReport4: TfrxReport
    Version = '6.9.3'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 43988.808184317100000000
    ReportOptions.LastChange = 44054.623554502300000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      ''
      'begin'
      ''
      'end.')
    Left = 456
    Top = 224
    Datasets = <
      item
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
      end
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 80.000000000000000000
      PaperHeight = 135.000000000000000000
      PaperSize = 256
      LeftMargin = 3.000000000000000000
      RightMargin = 2.000000000000000000
      TopMargin = 5.000000000000000000
      BottomMargin = 15.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Frame.Typ = []
        Height = 207.873954720000000000
        Top = 18.897650000000000000
        Width = 283.464750000000000000
        object mDia: TfrxMemoView
          AllowVectorExport = True
          Left = 49.929190000000000000
          Top = 109.881880000000000000
          Width = 226.771800000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'fechaDetalleMensual'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."fechaDetalleMensual"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 53.708671180000000000
          Top = 135.015667480000000000
          Width = 185.196970000000000000
          Height = 15.118100470000000000
          DataField = 'cliente'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."cliente"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 68.826791180000000000
          Top = 154.472357950000000000
          Width = 185.196970000000000000
          Height = 18.897630470000000000
          DataField = 'domicilio'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset3."domicilio"]')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 0.559060000000000000
          Top = 134.795300000000000000
          Width = 52.913420000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Cliente:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 1.559060000000000000
          Top = 154.252010000000000000
          Width = 68.031540000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Domicilio:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 0.559060000000000000
          Top = 110.559060000000000000
          Width = 49.133890000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Fecha:')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo13: TfrxMemoView
          AllowVectorExport = True
          Left = 4.779530000000000000
          Top = 187.811070000000000000
          Width = 30.236240000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'U.')
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          AllowVectorExport = True
          Left = 38.118120000000000000
          Top = 187.811070000000000000
          Width = 117.165430000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Descripci'#243'n')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          AllowVectorExport = True
          Left = 155.196970000000000000
          Top = 187.811070000000000000
          Width = 60.472480000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Precio')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          AllowVectorExport = True
          Left = 217.094620000000000000
          Top = 187.031540000000000000
          Width = 60.472480000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -12
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Subt.')
          ParentFont = False
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Top = 182.811070000000000000
          Width = 283.464750000000000000
          Color = clBlack
          Frame.Typ = []
          Frame.Width = 2.000000000000000000
          Diagonal = True
        end
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 119.417440000000000000
          Top = 14.740157480000000000
          Width = 37.795275590000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -24
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'X')
          ParentFont = False
          VAlign = vaCenter
        end
        object Shape1: TfrxShapeView
          AllowVectorExport = True
          Left = 119.299320000000000000
          Top = 1.543290000000000000
          Width = 37.795300000000000000
          Height = 38.929136300000000000
          Frame.Typ = []
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 119.078850000000000000
          Top = 2.000000000000000000
          Width = 37.795275590000000000
          Height = 11.338590000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Recibo')
          ParentFont = False
          VAlign = vaCenter
        end
        object Picture1: TfrxPictureView
          AllowVectorExport = True
          Left = 62.472480000000000000
          Top = 47.133890000000000000
          Width = 158.740260000000000000
          Height = 34.015770000000000000
          Frame.Typ = []
          Picture.Data = {
            0A54504E474F626A65637489504E470D0A1A0A0000000D494844520000023800
            000073080600000095757870000000097048597300002C4A00002C4A01777A74
            4D00002C844944415478DAED5DDD95E336B22EEFFAFDF644603902B723301D81
            DB112CFD76DFDC8E60B9116CCFDB7DB31CC1F644B09C08B627026B2270CFFBEC
            F16549050982F053008AA428D6778E8E5A2D8A408140D58742A1F0C59F7FFE09
            8A737CF9D7BFDE7FFEEF7F5FE6AE8742718DF8BFF75F6C86B7667899F7D7E165
            C64BFFBFDFFDD9CF5D478542A1F84209CE0903B16987377CC140709AB9EBA350
            5C1388D874C3EB6F894B3F0DAF67BC76203B3BC1B25F87FBBDCEDD0E0A856219
            583DC1416F0D1C48CDC3F0FA8AFEFDCB40709EE6AE9B42712D1808463BBCE198
            F89FCC9FBE8503D129262643D97770F010E17B33DC4BBDAB8AD1403601FBDA86
            5EF7F4FEAA13DF6561750467E8BC1B38B8D5CDEB2BCF65DFEA1295427100919B
            5F2B6E811E9DC781986C0BCB476FD00FF4F18D7A71143E0CBABD19DEB6C36B57
            F073243129F2FE5E09CEB270530467E8E0C8BAEFAD7F35F4BE8113134F75E28F
            4327DECC2D8B42710D10203736DEC381E8B0270F43F95B382D897D187E7BCFFD
            AD625D2082F3EF118B5082B330DC1AC1791CDEFE59799BB743277E9C5B168562
            6E0CE402C9440FF9CB5229FC0689F81C5A96DAC2C973B3FFDDF09B76EE76515C
            27C83BDFC261328B2107D2FD5609CEC2706B04076786DF54DEE6C7A1133FCF2D
            8B4231370692D10F6FDF8D5804121D1C6B2F86EC10A942E384930CD740FD385C
            A76353910479F37BA8B7073694E02C0CB746701AEB232A4AFCFC43CE3D860EFC
            C5DC722814734378694A0A1A7FA36083480E4E7ABFAABD174109CEC2705304C7
            078A88EF81E7AE7C3774E087B9EBAC50CC8D81E0EC40CE3048E0DD406E746C2A
            B22014B660A0046761B8798283A0FC369CD9E84F4307DECE5D5F85624E0CE406
            89C4BFE6AE87035D9E526483E2727E17BA9D129C85612D046703BC4EFEF5D081
            7773D757A19813CEB6EC6BC0C781DC6CE6AE84629918F43F2E6B4A041C2BC159
            18D642707099EA3F89CB3E0C9D57B7A02A560DDABDF4C7DCF570F0CB407034F1
            A6A20883FEEF4126585E09CEC2B01682C371B9EBF670C5EA11599EFA00871D4F
            3D7DBE875320FF98B13AEABD51544109CE7AB1168283B3BF9F139769F662C5EA
            E124D6437C1C5E6DEC004DDA71D5C13844E77B3DBC5351032538EBC55A08CE0E
            E2CAF7D3D071EFE6AEA74231379CDD53E8B569B85BB387DF76C3DBDF05ABF376
            285BBDAA8A2A28C1592F6E9EE030E36F7E1B3A6E3B775D158A39E1C4DF64911B
            EB1E38DED0635A6B50346BB142044A70D68B35101C4E1E04DD1EAE583D0672D2
            C0E12C1F3C1CB3EAD4EE8AD3C7114A6E14625082B35EAC81E0708E6F7833745C
            CD90AA583D889840E9C9DFCEBDD023F408FE63177C4062D5E98E29852494E0AC
            17374D702855776ACBAB765A85626410716AE0B0F3CA9D70E029E3B8436BAB47
            3128A4A10467BDB87582D3423A83F12F43A7D519A342A150DC2094E0AC17B74E
            70381959757BB842A150DC2894E0AC17B74E7052C27D1C3AEC66EE7A2A140A85
            621C28C1592F6E96E068F6628542A15028C1592F6E99E06CE13C23AB0F3F0E1D
            564F285628148A1B85129CF5E29609CE0E12A9E387CEFAC5DCF55428140AC578
            5082B35EDC24C161662F7E3774D687B9EBAA5028148AF1A00467BDB85582D341
            FA4C1CCD5EAC502814370E2538EBC52C048712F0A19765432F83DDF07AA9DDB6
            CDCC5EFCF550CE4E502694A321B9F07517A8C37B7A7F21797B8EBC964CFF18AE
            EFA4EAED29C73C1B946543AF902C785ED12BC9F242B288B5A9800C1B7A7F8991
            59E6B3FB44321A799F05FA29A75C84E9333DC9326BDC187948EFA8EEA6ADBBA1
            5EFD9CF51A515E23A3E953DBD0B3A767FA60B58D6B58F159BEC4EE515957BB9E
            E63901FD1DCA266DC631A207213D2C284F03E7F6C20D3DF84875DED71B1C9DBA
            248243FDE71ECE7542482FECEB44EF467E94F5E59A33F3938CF86AF03D760E24
            3D7F7B3CD9ED607432EAC3679FED998CE0D0AE2653D1AF129763877D2C51E4D4
            78BF272EFB30DCFB5E40A60DC9D4429A50C5800FAA87D3833AEB9C8E4CE28909
            4981B7244BAD224065F994E31D1BCA6FE0D02F108644C4602B6EF7B3AFFE5E52
            488920DB0A993F92ACECE7416DFD48E5A6C64108D85FB0AF745C423994FB44ED
            C4695F83C6FA3BA66411DF5F0BC1A1E7BAA18F9C3A35CEE79461B99095FA7007
            797DE9DDF06A6B8C11F5275BB7969CFD1582E967DB299F2D19B54792A9541E1C
            9B5BEB75B50487E46D49DE529DE002F5700F02449A56441066721783990CD868
            E87DE393CF170B4B63B8CB6C8F0B3D3F2AC121C38C15F59D45F381DE634A33FB
            946F66F6E2AAEDE1245707E95D5A3EBCB7FEC6FBB80FF0C278393BC2C40C49A6
            1CA65ED88153C913111F49862DA31E5887D492620DCE3A3E192334F835A4D495
            F521A6482C622329273E9347661BF720A3E443B826823399ACF45CB7C01B133E
            EC4F6DCF2539D4875BF08F5D244E7B4F067DDEC0C1E8D41850ECE3ED98CFB890
            247280E34482F889111C8B98A2BCDC6782B603F596999072DB297BD2E9D47554
            2F884D7088EC613D4B75F319671885E02494F93FE0C02A77746D0771A59FE5B1
            183B7B319D4E8E75CE193038C05086278F7726D6D17D24B0DA905099581F2E41
            3B53C2A488FECDFC6D72965AC8D6737024382392297CC60FBE674383F67944F9
            921301CB5B155BAAA8C135119C2792750C398FB2069E2BF68357C87BD6EC0917
            4D4A503E9F8EFB0D125E3D81FE2F9E3B8CF411D6EBE7CA5B99E53FBC1FB69334
            5112213852DE09662A141B452475EC09832138D42ED8B7ED718B75BE83BCB17C
            4CFF224E7068296A0B7E8FCD836FF02518E2A7E13777C004836D66DDCFBA2FFE
            061B2DF741A3C26B9871361DA4954F95210974A218B083DD7B8819A7AE06AC59
            2A296F549EB58ACEC55E391428845C7CA2B6DA5932A111EC613C636BC00E9A27
            92FE4FE1F2AF86E058726E204C06AA6485530C9D79AE685C3B3828E32DE43FEF
            644C2063EC062752CE7D6A9F7F91D7295097DA193BE21F109E3CE69C669F4215
            C1A1FE88B2E6DA90E08E5F66BCE9C5FDA060697404CFF71E48703C3B9FF7641D
            0E13955C427EB4F1620427E11588CE3019A484A53C99D98B4B96BD50362CBFE4
            C1E67AA0B06EB125B662435268E0BF0F7825B04D76C0571C6CA5388297051520
            966B2B75B3468DFFDF40DD7ABF8DA312F4901B136B65C82E9629A52CF0DE1BAE
            D21AA18DAF8EE058B272BCBA59B2C2692905DB1D8DC53353FF8490D291A843B8
            C43F39A9E2E4094BA03A8E5188FC2789FD3504191339782E9435487E33BDE936
            92CBEA81F250EFE36F24BDD16FE0644B502FE3787AC9ECF32EF6FD4284E02458
            38C77D9EAA048B24300D78F6F6F04296BC474932C184F1C9362415042D7A5657
            016162E71E1AEE8D865ACAEB81B3EBEFACBF2F76FC087B5ABE85D38E0EA308DE
            52B9EE2CB38172C5E7226B879D701B5F33C1D9407AE3410E70068C84E94824A8
            0C7CDEA5ED19F42C5790D1E03361C62AA650BCA35368BCB1CA9F9BE054B635C7
            7EEEA08C70B0571704E5F1C18CA7E324B872B2B0BF27DA9A6A8293E8A82C6F09
            83E0703BF20ED20FFA4D8E6BAE9245D630FE10A9CA3224637A9F0A3B3A8B6056
            B67B08A95972893CDE72E0E01932F58FCA5C310B73917578ACF092DDD5121C92
            15EB261D4760071B4BDC3FB43BABB46F04BD7AA417FE106883EC741B425E0076
            5F9F93E00818EAE47142954B8EA52447727264EAB15FDE2F581DF0029D0B5504
            4782DCD07D5295E0B82139D98BB33A28F39E62E53965E3EF7C8A2D97E0D4B8E7
            A3CAAB7066CC5A4A11500C2E92DE2341A58FEE5FA3BCB9DEC71DC8B87DD90647
            782676ED04A703D925B963B0AD809E30B8D07302C639A8876B3CD3BE76E04268
            C93027E6AC871908CE985E3D4F39351E4A6F9C65A2CC1E64270CC7E7291823F8
            7531C149909BDC8E501D83C3546063ECC88AA16A9D3AD089D83BC02A953A6B86
            54C8E493CF41D06818B00CBF90D237608F03416F4A8EE2C7BA49788E10D74E70
            A409F3D1132CE86D74D3196C406669ED4DC08BD343BD91CAF51AB6504FAA73CB
            949013916BD76A7549CE92FE646551791DC84D18CEECA4A00EFEBE88E024C84D
            6EB023C790259795988D92430E3630A27261D6A101C70071637A040802ABC317
            2A0F2E7992DAE297A3284AE409816DF40515063B2E4298445E3BC169408ECC9D
            794504FB8C4B70A466B2DE650EC17AB3749CD4D203647A8DE6203842CF8E3D21
            1722D973E8AB0B3905F57E3EC1610487E52EA1B41067F4492F08938CCC31D340
            549D79E52E5D64109C1EEA063537EE09652BF13C24C9A66047CF31FA3DC828C3
            2CEF9DA0C290F69E72B126827336A6C7EAA763935EC1BECEDDE52A254FAE8D91
            929335B604895C0EE168A1DE5EE510B80EE408CED116487B95B3080EE3C195AC
            C76E216E2039CB192D08672F167C80D9EB9B4E3DCE66021C8223D449C6565AC9
            E7B1708233577F5382E397B3819196E3C66AC305119C49E3CC7277A6CE40705A
            10981CE7C829E88D9D9AACBA998C1B101AA7D941C68965A022439E88E1E006A4
            72626592D1E8CE3D7B905BAAC8CEBD63D5E3ACE332098E44DDB9312BA5AE588E
            676EC9042777CB365EAB0467242C84E09C8DB905119C645F178C812AD9C92425
            2797E0ECA09EC865AD3850B912FD901B9AD0C175139C7DFBB1090E638DAF243F
            4BAAD373060E6BE7CB8CACDFA078A9CA26812939A4987CC6525803851D92218B
            129C0264CEFC94E054CA2A64D02E08BF609FF07A5826263852C9164B5609A4E4
            4C121C414F4A0991DB81CC4E4C4ECC6B07E3109C0DC8C4BEEEFB098BE0308848
            5604B675DF1EC21D8F15C3C09C1964D76FA4BC194524C7560E0C5220116C9693
            63A28172C311358A0B2738B3ED4A5082E395B381F108CE16EA77C0F9B6884BD5
            D91BEF36655F17CC9B92B51356584E0EC191DA51372791E3A465E960247D2544
            D4F6DED024C161064C95247B6A203C7873CE6FDAC238D98B39F72D41495D3AA0
            CEC420383BA8EF1C39C166785DA9124E25C05B32C1C95D2AC2FA29C119092313
            9CDA7B07277302C420385999AAAFCF9D8E60628223B5C5393B4BB4A0978C933D
            19EB3616C1C1B26B62988EE4904370528D5674BA6CA2D3E5448F7314400901EB
            609C53A711593139B6972A66BCE6708F562AAFE8205682530625385E391B18D1
            C8563CBF8B035A85EE1BACAB756FFCFF1404A756061B25BA7C2A39A51285224A
            3C551D086D8C4979F0C7D65715CFEC6CB21025380CA59095F3C6BA6F2C303527
            5119C7A01725DB1356883EB04F74A575C916FF4E1002A9BC193984A0A69D6A0F
            611D439E1E94E09460D50487CAE820EF19E2D93B0F29835DE115487948518629
            0CBF5439A567FB4D25277E37A7A7AA838988E4040407C9E216F23C527844CEA3
            6D53530407058C2D7794AC1386F2E8649F89C15CEF2CF230D1FDA5947F082C05
            9751DF2DC82CAB4D4570520A43094E0194E078E56C6002E34393910EE2A7D3E3
            B87FCA98C8E59E2787BAF491114781F79CC2F0EF40E8F4E92B27381DC8118CB9
            094E2A3E52ACACC4AA4433BCA1FDC6F7D0784267C193AFBE4182C3F40664B90B
            23F13C45865E3A7BB1E7FE5B18270EC7062AA336670B7BA4BE3DC80C6464C25B
            E6B548584BBD464A704EE562FD94E08C843966D7447636CEBF5F2A7262757050
            F6B1B41AA847BA898F25996A1C979EE6DDC3340447F280E01282837593EAE3A9
            F001FC6E527D45CE913BE7B7D136F2121C6660716E1C496816521AC3B381F476
            32D66165956548213BA8CC53DFB13D4ED25082732A17EBA7046724CCBD7C3082
            2CAEB2EF33B3FB4A1ED311ECEB5395939015DB65514B71503031BF7582538210
            C1E1543E2710183B39CE2C6C37257A6D1E4B1505D3C3549C60CF2A670BE37B71
            0CD8713981BA4A192B9C091679BD32F11223B74A70CAA004C72B670337427004
            DA2277C92B8518C1C1FF4BB5FB6A084EE1521CD66D92B65E2CC1617A6F72F2A4
            A001EBACFBA1F17C12F05670B6C4559D0345E5A09C3547DEE7A274B9AE819915
            893494E09441098E57CE0694E0982DB8B89422A9CF94E080AC075D098E0C7C04
            A785F41E74CEF9501B38C471D81D0B633B58EBC3897B73B7E3159FE45DD02692
            2809B86E40094E084A70C2E52AC1B9315903F2B77088DF315E1BD4313B183906
            4738F055094E5C4EAC9B121C0B3E82B38374C47B30B8D8DA45602FEBBC8703B1
            E9252ACDCC5E2C6AA4275EAA4264911C25385128C109973B19C121DD806D62DE
            7D78A1572FB5BB90CAC6F2564570ACF412F8B275FA5EB7C0C193336A5F172638
            6364CC179193CAB92582135DA55924C161369037AFCC14C4C62A6B0B69B2919D
            288951AED4AE032E58DB3DA96E0D28C10941094EB8DC51094EC4C87220A63FD6
            4270C8BB8D24C0F6D6B8D82FDD4FD1D785094ED1460C2538F275582AC1D94226
            7120D727BEEC0E340AB1B1CAE4642F2EDE1E1E29573A388F8BE449E84A70A250
            82132E7714824363056592D8368BFAA4ADF1E8DC32C1B1480DBED871894A70E4
            E4A47294E04C242B1747829311D7F22DBDB7F4B28387D939184AC1DC76987DD4
            7C46F973909CE47295129C2894E084CB152738D41751174806B2B2BD990139B1
            4E37457048A616E249056D9C6DBA508223272795A304672259B9B0094E0BBC40
            5ADCE5631BF78F7058CBDD4A04F4A63076F662661DAE8EE428C18942094EB85C
            51823341407ED1CEC85B22389E80610E7CA795A30C4B2238639C7B28222795A3
            04672259B9B0094ECE49A4C65BF324BD0C9402330E26B9A423508F39480E92CB
            C64724A7ECDC5341094E19E6223870081EB6C98D9D4F09BF1349D70F0524E716
            080E6DAEC0095E6E3B7AF3814D4470A4CEC78B961383129C5164ED6029042763
            790A13D16DC7260F214C91BD38B33E580E2A9C2977577967314A70A25082132E
            57AA8D7F8153BE2BF4EA3EBA7A42D8D865C5D82D99E0141E3C68103C6C782282
            83FFD73C389950822303437038DBAE11E281BB39602AC8A2AD8495F5DAC2B424
            E7629BFE08A79FCFFAAC49262538059889E0A0B706C9CDC589BE4E7952240749
            D43D77597CA90487267548144B3DC5B18341F1FF4A7084CABF824345B16E4A70
            2C1882C33A246CEE593DB3A356672F2EAC1B963915C909B99C25CFA29AA51D47
            9247094EB85CC93EC39259B08DA73AF5DEC5240447208BFA54470B28C1912D07
            919DA456B8ADA3C71C2D8DE0F4907E30B3069E662CA3659D701E290F491FBA76
            B75C432FEC828FC1BB0C276CAC460DD4E640094E19662438ACB127A888D16BB4
            E11882A5111CA118BFE82465814B37D74E7072E25853D0D3C40560080EA70356
            1F5C5903E6EE8CE07A7341793D1C0645AEA1E2D45302170340780631DA567B2E
            94E09461268293A51F04DDF9AC67BB4082B3857A8F7094704E68F83979CBAACB
            B902393B90DB315642705A90B33D29722C26EBA804E7AF7FF9CB06D281BB88A2
            1C0452600E78B13A5A83229B344D44722E32350BCF201073C75C29C129C05C41
            C63999C305E56511F125111CA9BAA6FAC112976E0A6353A692931BCBCA4109C1
            E9408E604575FF92084E03BCC13437C1A9CE5E4C24690387EDEDA9CCC03DD0A0
            281C542D8C4B722E9E87700747887BEDAC0CB73DE31928C129C0DC89FE98E562
            DB48118EA9337D8F4D70B650EFBD49F6BF090D3F2BC693832B27381BE0390B38
            C84E7532A50E5912C169816788674B6EC5544ED1EDE14E06E464009733288A64
            1F99E45C0CB61176522144629AAC3A6EE1A4BC532E742538055802C1112E3B49
            C4174670249674AE89E0B420A707B3F5D194635A70392EDBA1204824397262DD
            164170B8159D93E0701E5C2AEADBDC83B58DDC1914C5DEAB11BC2A06DE4E2838
            C0A2E514B6C5164EE486338894E01460410447EAF0DAE432D552080EF3281A0E
            AE89E06C40CEB351D2CF269193CADA82CC6EDA1282232567B26C25384C60E74F
            3172664062D4A567DD83B5FDD9E92C55465E38F8D7204470A4E37010D54B559E
            819F7C0E4A70CAB0208223D95753DEC006964170A4EA79350487CA9222B32559
            ACA794B305196F55763E37413993B1974A7018B0F23CE0CB7B5A7006FB0F2E3B
            394A83955FC0D359B2F31214C89003AFD11E7159AC88E450CC0D1A32BB2D59D9
            A695E094614104474C66484F701A5806C1916A93E4189BD8F04B2D9FCCE9D9E0
            C8896DBE830996183D654B8C656ED07E074A70E2B0587DB05199063BE522DDC2
            C17BC066C59E415195F86E844480C15D2B232C5319BC870011F5D40107FA23BD
            DCBA70B7F62AC129C04A094E2A6F4703EB223888ABD8264E656D4066925762F8
            279393CADB8280AECF1CC71B90695FD66EC825119C1678337ED1032C9D4E104B
            276E5F1742CCD8DB8C9A4D523C83A22AC78EE0DABA41D08D3862DC8F01A6E3C7
            BED0DB5E2D6AEB66783DD0CB47B2D829F695E094614104A70139D2119DBC2C88
            E0B420E7814D913E94614AC32F525EAE419C41CE0DC8900D7640B550FFCE499C
            D9C142080EB7612473CCD8197F53837007E9F89B60477014067B99293028AA14
            9B6072B3A81B51D04D3A067248A6129C02AC94E0A4BCB892652D2106078106EB
            3EA21BA5E262B8865F4AB6ACC9B6A0DE658F69212F0E5B4E21FD91A32725CADB
            636C82C33E495CE2104B8770A49412A76E2963BF8343E7CEAA7FC0D05D4BB031
            2740B78371BD3825C835FA4A700AB0528293D2039265897AB39D7AA20C92F17A
            1FE070F8696F9551733AB90F39861FEB513BBED8F18053F631A75CBCAEE61C31
            04FBB81C8176CD3DBCB60339FB521CDF9A8239AA81C3E45981A1198D8203AF89
            09C6EC9CC1CEEE90A95CD6DF83BFC3142B37A140BB9C412635439300DBFD4975
            E7126F0E94E084CB9D93E06C40D098C7E49EF29C9E5A087A1C6CA0BE35636F92
            1D9D01D9A496EAB9E79EF592F2668EAD16EA961BD9611102E33837516707331E
            4BC145D669E2501868EB9931B08C1D33F5752CFE66070745917DAE5264606431
            5DE79E1204877D7C02291394E31A96AAE6CC749B43707620635CB262B6E65218
            73121CE1F2530447F2205CB133EF0275ED601AEF2B929EC996A884E54B7AE447
            D8D881C8D563B575481239812322B28E591192CBC668073B1B82B301DE4C2A6B
            164E0DD1C081DC18A38183AAE51869E640F07638E7B725B91362DE8FA2E53A81
            D944891C92E7A34C59EF0EE4947CCEEE3931830BF5315FA5602BAC15119C2DC8
            1ABB31E370A688A1DBEB6190F1A6949CD7D7437D7FF7F6736A3FFCBF79DE3829
            95F288651BE3CABEC749BA5773FFD2F41F3B906BD36C5EC1C59EE06436120E8C
            0726ABC48EF09DF3DB2643E9B79076F15D184F67F65F7A026D4AF1E69E9E5CBB
            E452BC4D9DDA1107FC1C9E9C1272836D8504536C0031F3EE4893416E52496983
            96B38C79F30467A43C5459BAACA05D243D4E2E8EC1C782866AEF59B6BCF590D8
            D586D7F550EF417A47E599E78065B6701A4B6F5156909B3C4403B723F2621D4B
            4848D4F857F6ED6CCF0D95D9827CAE35F1730F1136C1C9352A66ABB0DDF01B38
            6C136E3CF7C1EB1F0BBC3FA9658A3302E31873EC1C0D7749C7299BA3787170B5
            CC6D755B2867D9553978A8FC3996AB4AC90DFE463A1B736AB79E94C2B5C1EA7F
            23B9D2597DF3D6090E1900D45363C4A2A167A0AB1D9B91B619232BF9599F1436
            569827CB2612A9C38FC7187336F69EA51132C9B357211C7991B47690AF8383BA
            AB50777CA2FA67C792924D7E2E908103EC3F9DA467F44870A8F26318416CCCC7
            0AEF034701A2A2D9C18160D9C4AAC6EB6197BBF75AD1FDEFE96F3360F6F20DAF
            679F31A934D845032922D358E4C145D600A24183AFFB91EB8603A8B795051940
            7C7EF84CA5033B0D906CE033DCDA333F5A8643B9A5833E0DF039F454761F58CA
            BD398243467B03E3B6AD0BEC5BD8CEA8037612A4279005BCB68E0FAE9E1AE928
            19D6528E6739490A47CFC748F221503FE3BD9F32F2D56CE0A08373EB7341160B
            C9297B526E95D30D6F26C7D9149B56F0D9ED75167D2E1E4F6704878441238383
            4A42D963633EE6BAF39CFA9406E6D6661E360DE375115247C5BAD906796F40AD
            CFA5061BCBEC4ADC874CD91A388F8B92043BDBB1559F0E26DCD26ECFF4858399
            53382301C2F13E29848EF6B8458283F5988AD8F82076402DC9D341DDF888EA13
            612255340BA7E5E12DC84CAECFC22826E80FA52912BA8C7A1D1D05F4BC5AC85B
            C22CF68E4CACA7BC752F1D4F17048704AA65D5486C9E245C4D056E4CF4E63CD4
            7A3DAC87CA49018FDF4B0C201C984F63B9BC3D7537EBD5125E939A01D4513D76
            91CB7689EF6D6CE8E5C3771E8283CA3DD45F5E23DFB940427B17F9EEC14370DE
            47EED7031F4DA23DB62B2338F81C62B3D41DF0FB938D0D84FB965D97464A2E92
            09CBEC209C21DC87BD3E818077D953460B076F66EE2C1D752E8EA16D8DDE4D1C
            EFC205C6DC744E86F51EE2FAD9DE428F788178DF41605D4D60F563A9DCE45030
            1E64E9651FF35CD81EA6401D537A8ADB663EC47426D077AFA204C7126C0307C3
            838D9FEAF4D800D898CF358D19A94B477509791DDE51D95BC1F2105B8E3CD456
            E688027C689CCE8A1DB037AF31DA8D29EB1DD5BBA1BA73149C59FEC0D728CF5C
            313E6E91E0DC3AC828E26B13B8A41F5E2F1587031BE3DD442E33C4BFB89C441D
            8C2EC53AA43CCDD1A5228A653231A63B7A7F955AFA1794D9B439BE36904F343F
            C0E9F0EAFEDAE49B035182E38266BB2E26ED28442436F6FFC6DAAE59594F9BE1
            BBB8BAC1E5A9FF06C20A7414A5A6981E4A70144B40C0F65CA5EE17963B66470C
            541F07904570140AC56DE18608CEA8C9F7140AC5F2A00447A158316E88E08806
            F62A148AE543098E42B162DC10C111390C58A150DC0E94E028142BC60D9D263E
            EA01980A8562795082A350AC18374470AAB37D2B148ADB82121C8562C5B82182
            F3EDB5EF4C542814D342098E42B162CC4C70C40E94D42DE20A85C285121C8562
            C59899E07420734487EEA0522814175082A350AC1833139C2DC81CB2F8CB58E7
            B6AD01943578A36D7896D5FDB5E4B46D81F23754BE782662EB0CABEC7B5BF55A
            54D67A25380AC58A3133C1C1EB25CE70FB7AC6634E5A38649AAD3AEF67863A6F
            E0741C031E2BB3DA206DEB581E6C0BD31F2789E9B28E43B24FEBFE34947D577E
            D7A46CC9F13276BDA682121C8562C59899E0607AF9DA030667CB60EC78A07E1B
            EAD1CE518F827A77702037F621BBB391C4B941ED619FB7389921B788847DC0A8
            484EA7C05992ACF1421B001AA75E8BE9E3064A70148A15632E8243CAF7778172
            675B9E72DA6E51CA9F962BFEA08FAB3FE6C2D9D137F9B374E2D144BD69B404F9
            2FFAF876B8F763C66F716CFD3C46BDA680121C8562C59891E0D84AB71478A2FD
            66AE83060719767038E9FAE3F06A96E401A193ABFF431FB38CDE2DC2D9D137B9
            2177BC81A2DE3447B61F73628BE82476E3E97BB3B4433D95E028142BC68C04C7
            9E199662F6ECC538F35FE289D63546EF1631B721B7C9F250F6662CD972D22938
            5EBE45EE545482A350AC1833129C1D1C147A29D06B72BFB419E5B5A0D4E8DD22
            E636E4CE72ADB837CD1AE359B2395ED645EE545482A350AC1873101CA1F81B71
            AF03D66B49CB4C95B29AE7BEFA434AE736E4B4ABED57FA28DAAF6B641B73D96C
            2A28C15128568C99084EEDF254F12C97624FB670D8268DEF1D7DD5D2DF681070
            7B30CA82DEA1D656EC44CE1EE93A44178BD7A0F2F0BECDF0DAD16F37F419BF7B
            70EEFF40D7E335CF76B02B05C23EC2696BF76FF839E6C5F2ECA4F930BCB0FD8D
            418D1A3D5ACA6AE9B7BF51DD5A238F2F18976478A06B80DAB2CF8D6BB1DA1ADB
            09B7387FA4FBB491DFD86DF462B5A5B7BDE937582F63C8CFB68713F9C07B7C45
            6DE7FB7D43F2DED3338BB5A7A91F5E8B9EA32DD52FB93C46EDD15159AF741FB3
            8D1BEFF7E88E4167ACED65A33A74F4BF2E346EAD5D8ED16533F2809936FF8EDA
            E9C97DDECE75F7701A67DBB1C893121C8562C5989AE09092DB41F9F6F02A8F83
            6769EC9355977D4C8FB3A3E618E74306C628656390823B90AC99F99E88C041A9
            E3BD4C3E9233C341C4604B659CE563A17B3DD17DF065B6FD06098AF51B041ABF
            AD27B8DB9BEF859E13CA89F533A4EF893E9BBAFDE4316246E60F54666F1959B6
            178088614FCFE6A7E1F54CEDF76F0804015B3B9142EDED7D5621436EB59FFDBC
            2FE2BE9CF81DAF8CD49E5BBAEE1DD56B47FF6BA8FCE012925397969E83791ED8
            9FBD5BDBADFEFE89AE7DA67B009C766D5D4C18B841E856BD5E4926ACC33FC1D9
            0060F527ECB76FE144B0706970B45D6B4A70148A15630682D341F9F10C498F45
            A2EC162E0DD67B3828FE9D312EA1980C9AE9BF20A1B00C47C8686259BF8263B4
            9CE486678683EE6966E76609EF7B38CDF41B6B067E41C002E5A3A1B977BC44A6
            EEDE99B9638C8ECFD5317A88AF3DDE2D53EF2309B10804DB900DBF79A1F28F84
            D6F2B45CD4DB2251670438D6DE1E997CCFA3A1F637D7F8084ED4D3E1B4E76F1E
            AF9C79965EB26A9346BBAF399EA70BE2EF3C0F1C3BF8796B3D17D30F2EC891E3
            F9F12E9B396416FBE6AB33BEEDBE63EA7A2CCB599A1B65094C098E42B1523886
            BC164982E3319039A89EE59192EDC993B1A17FA351C019A76BAC8D82DF1314E3
            7942E5EC1A0EB75E9697E4621BBB63008E86C32C65A1917214FFB770308E8DF1
            B4383BA02EDADDFDBDB3E4623F736F9B5AA4C047088CC1B820764EBD8EED6911
            00560C88D3BEB6070D9F1F1A4997C4C4DADB36D4BEB6F21A726A436CF336D6DE
            1C4F8745D62E3C344E7FB8F0A639F777FBA8FD5B9F37CDAE3712F9D710F97303
            CDAD3A873C43D83E1704DAF2669DFDCE2253C73E67DF63ACC48A4A70148A95C2
            993DD6224A709C25871CA0027D94C84B824AD6B324848631E405D9C7DA10C169
            E1A0C81F63C9CF9C2538DF6C1FDBE0C2A8D03D917C3DDB9E0A6AB39D7D1FCBF8
            20DE38061DE57B89946F2F51F98C225EFF77F09385A8318F9037ACD31DF7E803
            A75FBA5E95C62118767BFBE431ED1D32D45E434E86BA238F59ACBDA39E0EE7FB
            0B2F05A37E78FD57816789B2FE2D726F7BE9CCF73C4DD96E5FC4E76508A6CF33
            64F78323698DF5FD1031A667FD32D66E4825380AC54AC14CB687EE675BF96CC0
            BFBD1B8D312ABA67679669020BED94EF5C542D4939B2623D36961704E53006D7
            9B2C90DAA72152D3C08168EC9C389E90C1F326210C6DD94502E559D2794FF7D8
            58D7E1DFC6F8F8BC283D90C10C946F1B5CB7EE297296E3392ACE8EECF12C0697
            2F12CB56F67D524B38AE57A8A378ACE035741DD66BDF173C5E10FBB721EF8EE9
            0F3E4F20B6BF218C6F3CCFD2941D5A26B58D7B0ED98E263DB47EE7C62C99FFFB
            64B149E264799794E028142B45201E06032051F9BCC466DC348B6BE8F583F335
            1A57FC2D1A986F200F9FA8FC6ECC6DA9B16518EB9A276A87AD23B799BDBA4671
            031183C6D9B2EB59C67397446CE373768F98E7C3BA06DBD46B1463E487BE4F2D
            5BA0FCC67B149431F3F920BCC1B7A1A5AC407BA796704281CBC16B9C67E55B7E
            C26B631E9660FD1CB2E9230C296F9A7DEF14D9F679AFBC41D3A13E4CB2EE7700
            06FAB5DDB726CB40AE0447A158291C45F60F386CEDCC563AA48C5B386D27CE85
            598AC1D7F3D88ACF51D2C153A34D906920360771361365C4536C21B01D39700F
            9F57C29E09BBC627BA9B27169CEC18D42C6F87739D4D082E029C339E914BF47C
            0425B5FC936A0FCEEEA7D8F214D6C73C4F976C26DB2B468052B97132638B52C1
            D57620B7EDF58A7908F77586D3819CF8FF2EB2C51DEF8B6D693C9F939CF7A504
            47A1582948E97470D859C18A8F60DEB7A13F37F4F2A1A7F7D1D6DF23F5DB4122
            2DBEC997E351F066F9C8B7F324785F8740C4CAB50DAA3BABC7DF7897A71CC314
            DACD83F73206D5F50CB57032A8B1D81CEFF711198A0D994BF6C0C95C6D3D0B9F
            210EB695A7BD424B3CF63D5C6F9DBB8CE60673073D6DCCFA1DDBF0B327D3746C
            0794F33DC247EEBC9E2987FCBB24D8AE339257BC27122FD6C4C813F3377AF240
            25380A856235F89279B2B2BD253CF05B77BBAF3D234EC55384762FD946D347A0
            62CB5351B95CE3E4B937CA1B4A7667933344D430790C59F1D94E8EA1B6974472
            029E7DDF63FB1B42170B320F2D4FD9F7F711DA1E9C5C46DCFA7D99383AC2A97B
            CADB165ADEF37AA612FDC06E8FA2649B8ED76C742F8E121C8542B11A380A3C14
            77B181833BDDDD7562FFF647DAF1B4DFD51333981E82607E8BBFE9AD2DB62992
            72B13C85869E76FA6079B12DC376DDDFD176749413DCC0694FB0AC7DEFBDB781
            7EDB843C39BEB62A7C5E76BBDA5B8C63E4C36DEFEFCD33B23C1576FD4C32C57B
            C7A0874880596EB9032B46C6694FE35DF2B567A87EE6593610C973E490BE9F3E
            9F1238BE50D9769BF9BC47F6FD5DA27EE6A1B483F39D362B3AE836E5B9928612
            1C8542B11A3846CBBBB59D66DFFDE744423752D6CF64F0F1DABFFBEE4BF1102D
            9C0CDADE587AB6AD6F213C7BC6EBCE0C0379311EC9B8C6CA6FE0DCA3B2377A54
            DE3391ADD0EE2E3776E22DED2A33E40BEFF1004EEC546A8926F06CF03EBBCFE1
            BC3D76D2C598BCA64E6704C36EEF8021EF8DC14D2C4FE1FDF17AE3893084D5D7
            9EBEE527FB39EFEB67DA99FA952D9BEBA9C3EFEC1D895F5B04F59EFA95ED25F1
            798FB0ADCC4E3B3B878DDD4F0C696BE1941EC1FCEEA2CD9DBEF642F56848BEDE
            B9660791E5354928C1512814AB81B37536149CD9788C5203CE0E253236AF4416
            F06F5F0657BC0F1A9C1D1C8C83491C78DC826E9581D78462782E76AF38063554
            FEDE7053F96701B58EC10F111CE379718D391A4DAC13D6FF67CFEF5AC8C852EB
            B4AFEB2D3104C75EA20AC98BF73184E09809D931D417CB8986B059F7F7EE70A2
            FB6FA90C43E0DED0BB4D9042EDF900A7A30D42F5B365739341DA7DC9106DFC7F
            67050A9F11F1483BFBC8D359B9446A1EC983D3C389E0F8029F4DFDCCD8F9C377
            ED979E2CD56341098E42A1580D1CF7BE6F1794211EEE965AFCEE6850E1E0D5C0
            979935DBDF9B650354F43DDDF36CC9C1361C74FF544C89BD2B06B31B63FD5E3E
            9FD2DEDBE51BE384DFE1EF8C17669FC08F3C162DC9D9D2EF2F82A789406DE060
            B4F6C69CBC0D0D1C0C6A6397EBE452315E84E8418DD6F578CDF1780A8BB060FD
            2EB23207E435EDDD809388CEDE11E7921792EF05AC1D733E02E5DCBFA5E761BC
            691DB541E7F433BB3D1B2ACBD71FF0FA87CFA773C77E75BE37CFA1A3D7377022
            DA26D0B777088CCF1BB783F0D6737CDEC6B384A4ED9EEE6B489BED957397B60C
            713332D89E3F3B1BB5DDCFA3C1EA125082A350285603379E044E8732E2FB0E0E
            0AFA35F1BB77F49BEDE7F383387FB7EEFB4CD71BB273DCF143E5BC3A06C2361E
            A96DC1587E035686674FF94FF4DAC1C9201F8D13D0E9D79641C7FB1CE32BE074
            5ABAFBDBB7F49D6BC8C05AB67BA0EBBDA76F479E8DA9C33166064E07389E65B3
            760CE57BAAC3CF567B1F9788A80D7686343A04E203BDF78E37CD7E1E2637D413
            9C0E2D357535799B5066FB7049BBBFFC42FDE56F56FDB04EE684F257B08E5170
            8888E94B589F27223BC6038265F770C812DD38FDE4ECEC29CBB375711E9625B3
            BDB4F51E4EA7AFF79E7A997EB423D9EF4C9FB0EE67DAD9904CE3F1432F50510C
            4F2E94E028148A55C189893146E239B1F5794F68805CEBBEEBC9B877703064C7
            D3B4E9BB96BE4363B6F5047EE2F71BFAB8F56CEBC5EF1EA9DE788F2E52FE8355
            4E677DB75F7E83D3D6DE174F1DF0FA3BBAE691BC5377703AF5FA99EEDB3B6DD3
            81752A36B569565E25CBE384F731C6BF87401A0332DA2DB5F77B6A13BBBD0DC1
            7BF20421A31C260EE5C9136F65EA720CCCA6EBCCFDCD72CC57F45D1768CF96CA
            717F7FD61F48463B86C93C4BD397BACFE7E76499FA3ED9BF25F2B32542619EF9
            0F70EAE74F9F0347AA38327DA4E7EF5B86EAE044840C017B8A4C0CB03F7E03A7
            7C57CFA541E7B9F87FB766183F39F5EFE10000000049454E44AE426082}
          HightQuality = False
          Transparent = False
          TransparentColor = clWhite
        end
        object Memo17: TfrxMemoView
          AllowVectorExport = True
          Left = 0.779530000000000000
          Top = 90.590600000000000000
          Width = 73.322846850000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Recibo N'#176':')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo18: TfrxMemoView
          AllowVectorExport = True
          Left = 73.692950000000000000
          Top = 90.370130000000000000
          Width = 185.196970000000000000
          Height = 15.118120000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            '000126')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Frame.Typ = []
        Height = 22.677162910000000000
        Top = 287.244280000000000000
        Width = 283.464750000000000000
        DataSet = frxDBDataset2
        DataSetName = 'frxDBDataset2'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 38.456710000000000000
          Top = 0.779530000000000000
          Width = 117.165430000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'detalle'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDataset2."detalle"]')
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 4.559060000000000000
          Top = 0.779530000000000000
          Width = 30.236240000000000000
          Height = 18.897650000000000000
          AutoWidth = True
          DataField = 'unidades'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."unidades"]')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 155.417440000000000000
          Top = 0.779530000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          DataField = 'valorUnidad'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."valorUnidad"]')
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 217.330737950000000000
          Top = 0.779530000000000000
          Width = 60.472480000000000000
          Height = 18.897650000000000000
          DataField = 'subtotal'
          DataSet = frxDBDataset2
          DataSetName = 'frxDBDataset2'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -11
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset2."subtotal"]')
          ParentFont = False
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        Frame.Typ = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = []
        Height = 34.015750470000000000
        ParentFont = False
        Top = 370.393940000000000000
        Width = 283.464750000000000000
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 18.779530000000000000
          Top = 1.000000000000000000
          Width = 257.008040000000000000
          Height = 22.677180000000000000
          DataField = 'total'
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          HAlign = haRight
          Memo.UTF8W = (
            '[frxDBDataset3."total"]')
          ParentFont = False
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Top = 34.015770000000000000
          Width = 283.464750000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
      end
    end
  end
  object frxPDFExport1: TfrxPDFExport
    ShowDialog = False
    UseFileCache = True
    ShowProgress = False
    OverwritePrompt = False
    DataOnly = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Transparency = False
    Author = 'ElSembrador'
    Subject = 'FastReport PDF export'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 464
    Top = 288
  end
end
