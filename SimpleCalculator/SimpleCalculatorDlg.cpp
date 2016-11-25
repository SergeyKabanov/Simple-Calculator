
// SimpleCalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleCalculator.h"
#include "SimpleCalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//###############################################################################################################################################
// CAboutDlg dialog used for App About
//###############################################################################################################################################
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
//###############################################################################################################################################
CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}
//###############################################################################################################################################
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
//###############################################################################################################################################
BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()
//###############################################################################################################################################
// CSimpleCalculatorDlg dialog
//###############################################################################################################################################
CSimpleCalculatorDlg::CSimpleCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimpleCalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sStringDigits = _T("");
	m_lLastEnteredValue = 0;
	m_lResultValue = 0;
	m_bActionWasSet = false;
	m_pInputSafeBufferEndPointer = m_InputSafeBuffer + SAFE_CHAR_ARRAY_SIZE;
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DIGITS, m_EditDigits);
	DDX_Text(pDX, IDC_EDIT_DIGITS, m_sStringDigits);
	DDX_Control(pDX, IDC_BUTTON_0, m_Button0);
	DDX_Control(pDX, IDC_BUTTON_1, m_Button1);
	DDX_Control(pDX, IDC_BUTTON_2, m_Button2);
	DDX_Control(pDX, IDC_BUTTON_3, m_Button3);
	DDX_Control(pDX, IDC_BUTTON_4, m_Button4);
	DDX_Control(pDX, IDC_BUTTON_5, m_Button5);
	DDX_Control(pDX, IDC_BUTTON_6, m_Button6);
	DDX_Control(pDX, IDC_BUTTON_7, m_Button7);
	DDX_Control(pDX, IDC_BUTTON_8, m_Button8);
	DDX_Control(pDX, IDC_BUTTON_9, m_Button9);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_ButtonPlus);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_ButtonMinus);
	DDX_Control(pDX, IDC_BUTTON_MUL, m_ButtonMul);
	DDX_Control(pDX, IDC_BUTTON_DIV, m_ButtonDiv);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_ButtonEqual);
	DDX_Control(pDX, IDC_BUTTON_RESET, m_ButtonReset);
	DDX_Control(pDX, IDC_BUTTON_INFO, m_ButtonInfo);
}
//###############################################################################################################################################
BEGIN_MESSAGE_MAP(CSimpleCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CSimpleCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CSimpleCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CSimpleCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CSimpleCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CSimpleCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CSimpleCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CSimpleCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CSimpleCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CSimpleCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CSimpleCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CSimpleCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CSimpleCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CSimpleCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CSimpleCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CSimpleCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CSimpleCalculatorDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_INFO, &CSimpleCalculatorDlg::OnBnClickedButtonInfo)
	ON_COMMAND(ID_COMMAND_0, &CSimpleCalculatorDlg::OnCommand0)
	ON_UPDATE_COMMAND_UI(ID_COMMAND_0, &CSimpleCalculatorDlg::OnUpdateCommand0)
END_MESSAGE_MAP()
//################################################################################################################################################
// CSimpleCalculatorDlg message handlers
//###############################################################################################################################################
BOOL CSimpleCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	Init();
	return TRUE;  // return TRUE  unless you set the focus to a control
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
//###############################################################################################################################################
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// Here we add our own background color:
		CPaintDC dc(this); // device context for painting

		CRect OurRect;  
		GetClientRect(&OurRect);

		CBrush OurBrush(LIGHT_LIGHT_GREEN);
		dc.FillRect(&OurRect,&OurBrush);
		CDialogEx::OnPaint();
	}
}
//###############################################################################################################################################
// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimpleCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::Init()
{
	m_EditDigits.EnableWindow(FALSE);
	EnableButtons();
	m_sStringDigits = "0";
	SetDlgItemText(IDC_EDIT_DIGITS, m_sStringDigits); 
	m_lLastEnteredValue = 0;
	m_lResultValue = 0;
	m_PreviousAction = E_ACTION_NONE;
	m_bActionWasSet = false;
	errno = 0;
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::AddDigit(const TCHAR& c)
{
	if(0 == m_sStringDigits.Compare("0"))
	  {
		  m_sStringDigits = "";
	  }

	if(m_bActionWasSet)
	{
		m_sStringDigits = "";
		m_bActionWasSet = false;
		EnableActions();
	}

	//if(m_sStringDigits.GetLength() > MAX_DIGITS_POSSIBLE) return; // will be more than LONG_MAX value

	m_sStringDigits = m_sStringDigits + c;

	if(0 != m_sStringDigits.Compare("-"))
	{
		sprintf_s(m_InputSafeBuffer, "%s", m_sStringDigits);
		m_lLastEnteredValue = strtol(m_InputSafeBuffer, &m_pInputSafeBufferEndPointer, 10);
		if(errno == ERANGE)
		{
			ErrorRequiresReset("VALUE OUT OF RANGE");
			return;
		}
	}

	SetDlgItemText(IDC_EDIT_DIGITS, m_sStringDigits);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::SetAction(T_ACTION CurrentAction)
{
	long lControlValue;

	//if((0 == m_sStringDigits.Compare("-")) || (0 == m_sStringDigits.Compare("0"))) return;
	if(0 == m_sStringDigits.Compare("-")) return;

	if(E_ACTION_NONE == m_PreviousAction)
	{
		m_lResultValue = m_lLastEnteredValue;
	}
	else
	{
       switch(m_PreviousAction)
	   {
	      case E_ACTION_PLUS:
			  lControlValue = max(m_lResultValue, m_lLastEnteredValue);
			  m_lResultValue = m_lResultValue + m_lLastEnteredValue;
			  if(m_lResultValue < lControlValue) // means overflow
			  {
				  ErrorRequiresReset("OVERFLOW");
				  return;
			  }
			  break;

		  case E_ACTION_MINUS:
			  m_lResultValue = m_lResultValue - m_lLastEnteredValue;
			  break;

		  case E_ACTION_MUL:
			  lControlValue = max(m_lResultValue, m_lLastEnteredValue);
			  m_lResultValue = m_lResultValue * m_lLastEnteredValue;
			  if(m_lResultValue < lControlValue) // means overflow
			  {
				  ErrorRequiresReset("OVERFLOW");
				  return;
			  }
			  break;
			  
		  case E_ACTION_DIV:
			  if(0 == m_lLastEnteredValue)
			  {
				  ErrorRequiresReset("DIVISION BY ZERO");
				  return;
			  }
			  m_lResultValue = m_lResultValue / m_lLastEnteredValue;
			  break;
	   }
	}

	if(E_ACTION_EQUAL == CurrentAction)
	{
		m_lLastEnteredValue = m_lResultValue;
		m_PreviousAction = E_ACTION_NONE;
	}
	else
	{
		m_PreviousAction = CurrentAction;
	}

	_ltoa_s(m_lResultValue, m_SafeCharArray, SAFE_CHAR_ARRAY_SIZE, 10);
	m_sStringDigits.Format("%s",m_SafeCharArray);
	SetDlgItemText(IDC_EDIT_DIGITS, m_sStringDigits);
	m_bActionWasSet = true;

	if(E_ACTION_EQUAL != CurrentAction)
	{
	   DisableActions();
	}
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::ErrorRequiresReset(const CString& OurString)
{
   DisableButtons();
   SetDlgItemText(IDC_EDIT_DIGITS, OurString); 
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::DisableButtons()
{
    m_Button0.EnableWindow(FALSE);
	m_Button1.EnableWindow(FALSE);
	m_Button2.EnableWindow(FALSE);
	m_Button3.EnableWindow(FALSE);
	m_Button4.EnableWindow(FALSE);
	m_Button5.EnableWindow(FALSE);
	m_Button6.EnableWindow(FALSE);
	m_Button7.EnableWindow(FALSE);
	m_Button8.EnableWindow(FALSE);
	m_Button9.EnableWindow(FALSE);
	m_ButtonPlus.EnableWindow(FALSE);
	m_ButtonMinus.EnableWindow(FALSE);
	m_ButtonMul.EnableWindow(FALSE);
	m_ButtonDiv.EnableWindow(FALSE);
	m_ButtonEqual.EnableWindow(FALSE);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::EnableButtons()
{
    m_Button0.EnableWindow(TRUE);
	m_Button1.EnableWindow(TRUE);
	m_Button2.EnableWindow(TRUE);
	m_Button3.EnableWindow(TRUE);
	m_Button4.EnableWindow(TRUE);
	m_Button5.EnableWindow(TRUE);
	m_Button6.EnableWindow(TRUE);
	m_Button7.EnableWindow(TRUE);
	m_Button8.EnableWindow(TRUE);
	m_Button9.EnableWindow(TRUE);
	m_ButtonPlus.EnableWindow(TRUE);
	m_ButtonMinus.EnableWindow(TRUE);
	m_ButtonMul.EnableWindow(TRUE);
	m_ButtonDiv.EnableWindow(TRUE);
	m_ButtonEqual.EnableWindow(TRUE);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::DisableActions()
{
	m_ButtonPlus.EnableWindow(FALSE);
	m_ButtonMinus.EnableWindow(FALSE);
	m_ButtonMul.EnableWindow(FALSE);
	m_ButtonDiv.EnableWindow(FALSE);
	m_ButtonEqual.EnableWindow(FALSE);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::EnableActions()
{
	m_ButtonPlus.EnableWindow(TRUE);
	m_ButtonMinus.EnableWindow(TRUE);
	m_ButtonMul.EnableWindow(TRUE);
	m_ButtonDiv.EnableWindow(TRUE);
	m_ButtonEqual.EnableWindow(TRUE);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton0()
{
    // do notbing, if we have just 0
	if(0 == m_sStringDigits.Compare("0")) return;
	AddDigit('0');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton1()
{
	AddDigit('1');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton2()
{
    AddDigit('2');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton3()
{
    AddDigit('3');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton4()
{
	AddDigit('4');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton5()
{
	AddDigit('5');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton6()
{
	AddDigit('6');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton7()
{
	AddDigit('7');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton8()
{
	AddDigit('8');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButton9()
{
	AddDigit('9');
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonPlus()
{
	SetAction(E_ACTION_PLUS);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonMinus()
{
	if(0 == m_sStringDigits.Compare("0"))
	{
       AddDigit('-');
	}
	else
	{
	   SetAction(E_ACTION_MINUS);
	}
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonMul()
{
    SetAction(E_ACTION_MUL);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonDiv()
{
	SetAction(E_ACTION_DIV);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonEqual()
{
	SetAction(E_ACTION_EQUAL);
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonReset()
{
    Init();
}
//###############################################################################################################################################
void CSimpleCalculatorDlg::OnBnClickedButtonInfo()
{
    CAboutDlg dlg;
	dlg.DoModal();	
}
//###############################################################################################################################################
void CAboutDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
// TODO: Add your message handler code here and/or call default

	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
}
//################################################################################################################################################
void CAboutDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}
//################################################################################################################################################
void CSimpleCalculatorDlg::OnCommand0()
{
	TRACE("press menu: 0:\n");
}
//################################################################################################################################################
void CSimpleCalculatorDlg::OnUpdateCommand0(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(TRUE);
}
//################################################################################################################################################
BOOL CSimpleCalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (m_hAccelTable) 
	{
		if (::TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg)) 
		{
			TRACE("Press button\n");
			return(TRUE);
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
//################################################################################################################################################
