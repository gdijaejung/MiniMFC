
#include "stdafx.h"
#include "MiniMFC.h"
#include "MiniMFCDlg.h"
#include "afxdialogex.h"
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMiniMFCDlg::CMiniMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMiniMFCDlg::IDD, pParent)
	, m_loop(true)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMiniMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMiniMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMiniMFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMiniMFCDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


BOOL CMiniMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;
}


void CMiniMFCDlg::OnPaint()
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

HCURSOR CMiniMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMiniMFCDlg::OnBnClickedOk()
{
//	CDialogEx::OnOK();
}


void CMiniMFCDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
	m_loop = false;
}


void CMiniMFCDlg::MainLoop()
{
	//메시지 구조체
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	int oldT = 0;
	while (m_loop)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		const int curT = timeGetTime();
		const int deltaT = curT - oldT;
		if (deltaT > 10)
		{
			oldT = curT;
		}
	}
}
