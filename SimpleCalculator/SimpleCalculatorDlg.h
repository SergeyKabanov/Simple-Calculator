
// SimpleCalculatorDlg.h : header file
//
#pragma once
#include "definitions.h"
#include "ColorEdit.h"
#include "afxwin.h"

// CSimpleCalculatorDlg dialog
class CSimpleCalculatorDlg : public CDialogEx
{
// Construction
public:
	CSimpleCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SIMPLECALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CString m_sStringDigits;
	CColorEdit m_EditDigits;
	CButton m_Button0;
	CButton m_Button1;
	CButton m_Button2;
	CButton m_Button3;
	CButton m_Button4;
	CButton m_Button5;
	CButton m_Button6;
	CButton m_Button7;
	CButton m_Button8;
	CButton m_Button9;
	CButton m_ButtonPlus;
	CButton m_ButtonMinus;
	CButton m_ButtonMul;
	CButton m_ButtonDiv;
	CButton m_ButtonEqual;
	CButton m_ButtonReset;
	CButton m_ButtonInfo;

	HICON m_hIcon;
	bool m_bActionWasSet;
	long m_lLastEnteredValue;
	long m_lResultValue;
	T_ACTION m_PreviousAction;
	TCHAR m_SafeCharArray[SAFE_CHAR_ARRAY_SIZE];
	TCHAR m_InputSafeBuffer[SAFE_CHAR_ARRAY_SIZE];
	TCHAR* m_pInputSafeBufferEndPointer;

	HACCEL  m_hAccelTable;

	void Init();
	void AddDigit(const TCHAR& c);
	void SetAction(T_ACTION CurrentAction);
	void ErrorRequiresReset(const CString& OurString);
	void DisableButtons();
	void EnableButtons();
    void DisableActions();
	void EnableActions();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonInfo();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCommand0();
	afx_msg void OnUpdateCommand0(CCmdUI *pCmdUI);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
