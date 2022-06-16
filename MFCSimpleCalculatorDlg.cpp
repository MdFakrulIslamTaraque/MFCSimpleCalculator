
// MFCSimpleCalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCSimpleCalculator.h"
#include "MFCSimpleCalculatorDlg.h"
#include "afxdialogex.h"
#include<string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCSimpleCalculatorDlg dialog



CMFCSimpleCalculatorDlg::CMFCSimpleCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCSIMPLECALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSimpleCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Display, m_display);
	DDX_Control(pDX, IDC_History, m_history);
}

BEGIN_MESSAGE_MAP(CMFCSimpleCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CMFCSimpleCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CMFCSimpleCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CMFCSimpleCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CMFCSimpleCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CMFCSimpleCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CMFCSimpleCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CMFCSimpleCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CMFCSimpleCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CMFCSimpleCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CMFCSimpleCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CMFCSimpleCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_Plus, &CMFCSimpleCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_Minus, &CMFCSimpleCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_Mul, &CMFCSimpleCalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_Div, &CMFCSimpleCalculatorDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_E, &CMFCSimpleCalculatorDlg::OnBnClickedButtonE)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CMFCSimpleCalculatorDlg::OnBnClickedButtonCe)
	ON_BN_CLICKED(IDC_BUTTON_D, &CMFCSimpleCalculatorDlg::OnBnClickedButtonD)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CMFCSimpleCalculatorDlg::OnBnClickedButtonDel)
END_MESSAGE_MAP()


// CMFCSimpleCalculatorDlg message handlers

BOOL CMFCSimpleCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	CString display;
	display.Format("%d", 0);
	m_display.SetWindowText(display);

	m_history.SetWindowText(display);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCSimpleCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCSimpleCalculatorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCSimpleCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


double leftNum, rightNum, result;
char operation;
CString displaySingleNum{ "" }, displayHistory{ "" };
void CMFCSimpleCalculatorDlg::OnBnClickedButton0()
{
	CString zeroBtnValue;
	zeroBtnValue.Format("%d", 0);

	displaySingleNum += zeroBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += zeroBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton1()
{
	CString oneBtnValue;
	oneBtnValue.Format("%d", 1);
	displaySingleNum += oneBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += oneBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton2()
{
	CString twoBtnValue;
	twoBtnValue.Format("%d", 2);

	displaySingleNum += twoBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += twoBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton3()
{
	CString threeBtnValue;
	threeBtnValue.Format("%d", 3);

	displaySingleNum += threeBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += threeBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton4()
{
	CString fourBtnValue;
	fourBtnValue.Format("%d", 4);


	displaySingleNum += fourBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += fourBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton5()
{
	CString fiveBtnValue;
	fiveBtnValue.Format("%d", 5);


	displaySingleNum += fiveBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += fiveBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton6()
{
	CString sixBtnValue;
	sixBtnValue.Format("%d", 6);


	displaySingleNum += sixBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += sixBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton7()
{
	CString sevenBtnValue;
	sevenBtnValue.Format("%d", 7);


	displaySingleNum += sevenBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += sevenBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton8()
{
	CString eightBtnValue;
	eightBtnValue.Format("%d", 8);


	displaySingleNum += eightBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += eightBtnValue;
	m_history.SetWindowTextA(displayHistory);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButton9()
{
	CString nineBtnValue;
	nineBtnValue.Format("%d", 9);


	displaySingleNum += nineBtnValue;
	m_display.SetWindowTextA(displaySingleNum);

	displayHistory += nineBtnValue;
	m_history.SetWindowTextA(displayHistory);
}



void CMFCSimpleCalculatorDlg::OnBnClickedButtonClear()
{
	displaySingleNum = { "" };
	CString null;
	null.Format("%d", 0);
	m_display.SetWindowTextA(null);

	displayHistory = { "" };
	m_history.SetWindowTextA(null);
}

void CMFCSimpleCalculatorDlg::OnBnClickedButtonPlus()
{
	leftNum = atof(displaySingleNum);
	operation = '+';
	//OnBnClickedButtonClear();

	displayHistory += operation;
	m_history.SetWindowTextA(displayHistory);

	displaySingleNum = { "" };
	//CString null;
	//null.Format("%d", 0);
	//m_display.SetWindowTextA(null);
}


void CMFCSimpleCalculatorDlg::OnBnClickedButtonMinus()
{
	leftNum = atof(displaySingleNum);
	displaySingleNum = { "" };

	operation = '-';
	//OnBnClickedButtonClear();

	displayHistory += operation;
	m_history.SetWindowTextA(displayHistory);

}


void CMFCSimpleCalculatorDlg::OnBnClickedButtonMul()
{
	leftNum = atof(displaySingleNum);
	displaySingleNum = { "" };

	operation = 'x';
	//OnBnClickedButtonClear();

	displayHistory += operation;
	m_history.SetWindowTextA(displayHistory);

}


void CMFCSimpleCalculatorDlg::OnBnClickedButtonDiv()
{
	leftNum = atof(displaySingleNum);
	displaySingleNum = { "" };

	operation = '/';
	//OnBnClickedButtonClear();

	displayHistory += operation;
	m_history.SetWindowTextA(displayHistory);

}


void CMFCSimpleCalculatorDlg::OnBnClickedButtonE()
{
	rightNum = atof(displaySingleNum);
	displaySingleNum = { " " };
	int temp,intr;
	switch (operation)
	{
	case '+':
		result = leftNum + rightNum;
		temp = (int)result;
		if ((result - (double)temp) == 0.0)
		{
			intr = (int)result;
			displaySingleNum.Format("%d", intr);
		}
		else
		{
			displaySingleNum.Format("%f", result);
		}
		m_display.SetWindowText(displaySingleNum);
		break;
	case '-':
		result = leftNum - rightNum;
		displaySingleNum.Format("%f", result);
		temp = (int)result;
		if ((result - (double)temp) == 0.0)
		{
			intr = (int)result;
			displaySingleNum.Format("%d", intr);
		}
		else
		{
			displaySingleNum.Format("%f", result);
		}

		m_display.SetWindowText(displaySingleNum);
		break;
	case 'x':
		result = leftNum * rightNum;
		displaySingleNum.Format("%f", result);
		temp = (int)result;
		if ((result - (double)temp) == 0.0)
		{
			intr = (int)result;
			displaySingleNum.Format("%d", intr);
		}
		else
		{
			displaySingleNum.Format("%f", result);
		}
		m_display.SetWindowText(displaySingleNum);
		break;
	case '/':
		result = leftNum / rightNum;
		displaySingleNum.Format("%f", result);
		temp = (int)result;
		if ((result - (double)temp) == 0.0)
		{
			intr = (int)result;
			displaySingleNum.Format("%d", intr);
		}
		else
		{
			displaySingleNum.Format("%f", result);
		}
		m_display.SetWindowText(displaySingleNum);
		break;
	}
}


void CMFCSimpleCalculatorDlg::OnBnClickedButtonCe()
{
	displaySingleNum = { "" };
	CString null;
	null.Format("%d", 0);
	m_display.SetWindowTextA(null);
	//rightNum = 0;
	
	std::string historyString(displayHistory); //converting Cstring to std::string to get the erase funtion
	int strSize = historyString.length();
	int itrRight = strSize - 1;
	while (historyString[itrRight] != operation && itrRight>=0)
	{
		//deleteIndex = itrRight;
		//if (historyString[itrRight] == operation) break;
		itrRight--;
	}
	historyString.erase(historyString.begin()+ (itrRight+1), historyString.end());
	displayHistory = &(historyString[0]); //again transform the std::string to CString
	//displayHistory = { "" };
	m_history.SetWindowTextA(displayHistory);
}

int dotCount = 0;
void CMFCSimpleCalculatorDlg::OnBnClickedButtonD()
{
	//CString dotBtnValue;
	//nineBtnValue.Format("%d", 9);
	
	dotCount++;
	if (dotCount <= 1)
	{
		displaySingleNum += '.';
		m_display.SetWindowTextA(displaySingleNum);

		displayHistory += '.';
		m_history.SetWindowTextA(displayHistory);
	}
	
}

void CMFCSimpleCalculatorDlg::OnBnClickedButtonDel()
{
	std::string historyString(displayHistory); //converting Cstring(displayHistory) to std::string to get the erase funtion
	int strSize = historyString.length();
	int itrRight = strSize - 1;
	historyString.erase(historyString.begin() + itrRight, historyString.end());
	displayHistory = &(historyString[0]); //again transform the std::string to CString
	//displayHistory = { "" };
	m_history.SetWindowTextA(displayHistory);

	std::string singleNumString(displaySingleNum); //converting Cstring(displaySingleNum) to std::string to get the erase funtion
	strSize = singleNumString.length();
	itrRight = strSize - 1;
	singleNumString.erase(singleNumString.begin() + itrRight, singleNumString.end());
	displaySingleNum = &(singleNumString[0]); //again transform the std::string to CString
	//displayHistory = { "" };
	m_display.SetWindowTextA(displaySingleNum);
}
