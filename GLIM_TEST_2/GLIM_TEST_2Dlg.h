
// GLIM_TEST_2Dlg.h: 헤더 파일
//

#pragma once
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#include "CBackImage.h"
#include "CBackImage2.h"
#include "CBackImage3.h"
#include "CBackImage4.h"
#include <iostream>

using namespace std;

// CGLIMTEST2Dlg 대화 상자
class CGLIMTEST2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CGLIMTEST2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CBackImage* m_Back;
	CBackImage2* m_Back_Right;
	CBackImage3* m_Back_UnderLeft;
	CBackImage4* m_Back_UnderRight;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIM_TEST_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	CEdit m_InputRds;
	CEdit m_CenterPoint;
	CEdit m_CenterPoint2;
	CEdit m_CenterPoint3;
	CEdit m_CenterPoint4;
	afx_msg void OnBnClickedBtnDraw();

private:
	void Initialize_Back();
	void Draw_Circle_Letf(int n_Rds);
	void Draw_Circle_Right(int n_Rds);
	void Draw_Circle_Under_Letf(int n_Rds);
	void Draw_Circle_Under_Right(int n_Rds);
	void PointShow_Left(int n_CenterX, int n_CenterY);
	void PointShow_Right(int n_CenterX, int n_CenterY);
	void PointShow_Under_Left(int n_CenterX, int n_CenterY);
	void PointShow_Under_Right(int n_CenterX, int n_CenterY);
	void DrawBorder(CClientDC& dc, int n_CenterX, int n_CenterY, int n_point, int n_Rds);

	
};
