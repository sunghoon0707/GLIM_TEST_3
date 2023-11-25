#pragma once
#include "afxdialogex.h"


// CBackImage3 대화 상자

class CBackImage3 : public CDialogEx
{
	DECLARE_DYNAMIC(CBackImage3)

public:
	CBackImage3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBackImage3();
	
	CImage back_3;
	CWnd* m_pParent;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CBackImage3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void startBack_UnderLeft();
};
