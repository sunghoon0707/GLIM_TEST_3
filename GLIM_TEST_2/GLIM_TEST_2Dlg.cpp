
// GLIM_TEST_2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "GLIM_TEST_2.h"
#include "GLIM_TEST_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CGLIMTEST2Dlg 대화 상자



CGLIMTEST2Dlg::CGLIMTEST2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIM_TEST_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Back = nullptr;
	m_Back_Right = nullptr;
	m_Back_UnderLeft = nullptr;
	m_Back_UnderRight = nullptr;
}

void CGLIMTEST2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CENTER, m_CenterPoint);
	DDX_Control(pDX, IDC_EDIT_CENTER2, m_CenterPoint2);
	DDX_Control(pDX, IDC_EDIT_CENTER3, m_CenterPoint3);
	DDX_Control(pDX, IDC_EDIT_CENTER4, m_CenterPoint4);
	DDX_Control(pDX, IDC_EDIT_INPUTR, m_InputRds);
}

BEGIN_MESSAGE_MAP(CGLIMTEST2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CGLIMTEST2Dlg::OnBnClickedBtnDraw)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CGLIMTEST2Dlg 메시지 처리기

BOOL CGLIMTEST2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	Initialize_Back();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGLIMTEST2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGLIMTEST2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGLIMTEST2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGLIMTEST2Dlg::Initialize_Back()
{
	MoveWindow(0, 0, 1100, 520);

	m_Back = new CBackImage;
	m_Back->Create(IDD_CBackImage, this);
	m_Back->ShowWindow(SW_SHOW);
	m_Back->MoveWindow(0, 0, 400, 240);

	m_Back_Right = new CBackImage2;
	m_Back_Right->Create(IDD_CBackImage2, this);
	m_Back_Right->ShowWindow(SW_SHOW);
	m_Back_Right->MoveWindow(400, 0, 400, 240);

	m_Back_UnderLeft = new CBackImage3;
	m_Back_UnderLeft->Create(IDD_CBackImage3, this);
	m_Back_UnderLeft->ShowWindow(SW_SHOW);
	m_Back_UnderLeft->MoveWindow(0, 240, 400, 240);

	m_Back_UnderRight = new CBackImage4;
	m_Back_UnderRight->Create(IDD_CBackImage4, this);
	m_Back_UnderRight->ShowWindow(SW_SHOW);
	m_Back_UnderRight->MoveWindow(400, 240, 400, 240);
}


void CGLIMTEST2Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	delete m_Back;
	delete m_Back_Right;
	delete m_Back_UnderLeft;
	delete m_Back_UnderRight;

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CGLIMTEST2Dlg::OnBnClickedBtnDraw()
{
	CString str_UserInput;
	m_InputRds.GetWindowText(str_UserInput);
	int n_Rds = _wtoi(str_UserInput);

	if (str_UserInput == "")
	{
		AfxMessageBox(_T("반지름을 입력해주세요"));
		return;
	}
	else
	{
		if (n_Rds >= 20 && n_Rds <= 110)
		{
			Draw_Circle_Letf(n_Rds);
			Draw_Circle_Right(n_Rds);
			Draw_Circle_Under_Letf(n_Rds);
			Draw_Circle_Under_Right(n_Rds);

			UpdateWindow();
		}
		else
		{
			AfxMessageBox(_T("20~110 사이의 값으로 적어주세요"));
		}
	}
}

void CGLIMTEST2Dlg::Draw_Circle_Letf(int n_Rds)
{
	int n_Width = m_Back->back.GetWidth();
	int n_Height = m_Back->back.GetHeight();

	// 배경색 흰색으로 초기화
	CClientDC dc(m_Back);
	dc.FillSolidRect(0, 0, n_Width, n_Height, RGB(255, 255, 255));

	// 최대치
	int n_MaxX = n_Width - n_Rds;
	int n_MaxY = n_Height - n_Rds;

	// 랜덤 무게중심 생성
	int n_CenterX = n_Rds + rand() % (n_MaxX - n_Rds);
	int n_CenterY = n_Rds + rand() % (n_MaxY - n_Rds);

	cout << "1번 원의 중심값 (" << n_CenterX << ", " << n_CenterY << ")" << endl;


	PointShow_Left(n_CenterX, n_CenterY);

	// 가운데 십자가
	int n_point = n_Rds / 10;
	if (n_point <= n_Rds)
	{
		n_point = 5;
	}

	DrawBorder(dc, n_CenterX, n_CenterY, n_point, n_Rds);
}

void CGLIMTEST2Dlg::PointShow_Left(int n_CenterX, int n_CenterY)
{
	CString str_CenterPoint;
	str_CenterPoint.Format(_T("X축 %d, Y축 %d"), n_CenterX, n_CenterY);

	m_CenterPoint.SetWindowTextW(str_CenterPoint);
}

void CGLIMTEST2Dlg::Draw_Circle_Right(int n_Rds)
{
	int n_Width = m_Back_Right->back_2.GetWidth();
	int n_Height = m_Back_Right->back_2.GetHeight();

	// 배경색 흰색으로 초기화
	CClientDC dc(m_Back_Right);
	dc.FillSolidRect(0, 0, n_Width, n_Height, RGB(255, 255, 255));

	// 최대치
	int n_MaxX = n_Width - n_Rds;
	int n_MaxY = n_Height - n_Rds;

	// 랜덤 무게중심 생성
	int n_CenterX = n_Rds + rand() % (n_MaxX - n_Rds);
	int n_CenterY = n_Rds + rand() % (n_MaxY - n_Rds);

	cout << "2번 원의 중심값 (" << n_CenterX << ", " << n_CenterY << ")" << endl;


	PointShow_Right(n_CenterX, n_CenterY);

	// 가운데 십자가
	int n_point = n_Rds / 10;
	if (n_point <= n_Rds)
	{
		n_point = 5;
	}
	DrawBorder(dc, n_CenterX, n_CenterY, n_point, n_Rds);
}

void CGLIMTEST2Dlg::PointShow_Right(int n_CenterX, int n_CenterY)
{
	CString str_CenterPoint;
	str_CenterPoint.Format(_T("X축 %d, Y축 %d"), n_CenterX, n_CenterY);

	m_CenterPoint2.SetWindowTextW(str_CenterPoint);
}


void CGLIMTEST2Dlg::Draw_Circle_Under_Letf(int n_Rds)
{
	int n_Width = m_Back_UnderLeft->back_3.GetWidth();
	int n_Height = m_Back_UnderLeft->back_3.GetHeight();

	// 배경색 흰색으로 초기화
	CClientDC dc(m_Back_UnderLeft);
	dc.FillSolidRect(0, 0, n_Width, n_Height, RGB(255, 255, 255));

	// 최대치
	int n_MaxX = n_Width - n_Rds;
	int n_MaxY = n_Height - n_Rds;

	// 랜덤 무게중심 생성
	int n_CenterX = n_Rds + rand() % (n_MaxX - n_Rds);
	int n_CenterY = n_Rds + rand() % (n_MaxY - n_Rds);

	cout << "3번 원의 중심값 (" << n_CenterX << ", " << n_CenterY << ")" << endl;


	PointShow_Under_Left(n_CenterX, n_CenterY);

	// 가운데 십자가
	int n_point = n_Rds / 10;
	if (n_point <= n_Rds)
	{
		n_point = 5;
	}

	DrawBorder(dc, n_CenterX, n_CenterY, n_point, n_Rds);
}

void CGLIMTEST2Dlg::PointShow_Under_Left(int n_CenterX, int n_CenterY)
{
	CString str_CenterPoint;
	str_CenterPoint.Format(_T("X축 %d, Y축 %d"), n_CenterX, n_CenterY);

	m_CenterPoint3.SetWindowTextW(str_CenterPoint);
}


void CGLIMTEST2Dlg::Draw_Circle_Under_Right(int n_Rds)
{
	int n_Width = m_Back_UnderRight->back_4.GetWidth();
	int n_Height = m_Back_UnderRight->back_4.GetHeight();

	// 배경색 흰색으로 초기화
	CClientDC dc(m_Back_UnderRight);
	dc.FillSolidRect(0, 0, n_Width, n_Height, RGB(255, 255, 255));

	// 최대치
	int n_MaxX = n_Width - n_Rds;
	int n_MaxY = n_Height - n_Rds;

	// 랜덤 무게중심 생성
	int n_CenterX = n_Rds + rand() % (n_MaxX - n_Rds);
	int n_CenterY = n_Rds + rand() % (n_MaxY - n_Rds);

	cout << "4번 원의 중심값 (" << n_CenterX << ", " << n_CenterY << ")" << endl;
	cout << "==============================================" << endl;
	PointShow_Under_Right(n_CenterX, n_CenterY);

	// 가운데 십자가
	int n_point = n_Rds / 10;
	if (n_point <= n_Rds)
	{
		n_point = 5;
	}

	DrawBorder(dc, n_CenterX, n_CenterY, n_point, n_Rds);
}

void CGLIMTEST2Dlg::PointShow_Under_Right(int n_CenterX, int n_CenterY)
{
	CString str_CenterPoint;
	str_CenterPoint.Format(_T("X축 %d, Y축 %d"), n_CenterX, n_CenterY);

	m_CenterPoint4.SetWindowTextW(str_CenterPoint);
}

void CGLIMTEST2Dlg::DrawBorder(CClientDC& dc, int n_CenterX, int n_CenterY, int n_point, int n_Rds)
{
	int n_penWidth = 2;

	// 테두리 그리기
	CPen draw_Pen(PS_SOLID, n_penWidth, RGB(255, 255, 0));
	CPen* oldPen = dc.SelectObject(&draw_Pen);
	dc.Ellipse(n_CenterX - n_Rds, n_CenterY - n_Rds, n_CenterX + n_Rds, n_CenterY + n_Rds);
	dc.SelectObject(oldPen);

	
	// 선긋기
	dc.MoveTo(n_CenterX - n_point, n_CenterY);
	dc.LineTo(n_CenterX + n_point + 1, n_CenterY);
	dc.MoveTo(n_CenterX, n_CenterY - n_point);
	dc.LineTo(n_CenterX, n_CenterY + n_point + 1);
}