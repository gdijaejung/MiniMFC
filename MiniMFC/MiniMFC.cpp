
#include "stdafx.h"
#include "MiniMFC.h"
#include "MiniMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CMiniMFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CMiniMFCApp::CMiniMFCApp()
{
}

CMiniMFCApp theApp;

BOOL CMiniMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CMiniMFCDlg *dlg;
	dlg = new CMiniMFCDlg();
	dlg->Create(CMiniMFCDlg::IDD);
	m_pMainWnd = dlg;
	dlg->ShowWindow(SW_SHOW);

	dlg->MainLoop();

	delete dlg;
	return FALSE;
}

