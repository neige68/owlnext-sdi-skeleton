// <main.cpp>
//
// Project owlnext-sdi-skeleton
// Copyright (C) 2023 neige68
//
// Note: main
//
// Compiler: VC14.2
// Library:  OWL7
//

#include "pch.h"
#pragma hdrstop

#include "misc.h"
#include "version.h"

#include <owl/dialog.h>         // owl::TDialog
#include <owl/string.h>         // owl::TString

#include <vector>               // std::vector

#include "res.rh"

//------------------------------------------------------------
//
// class TVersionInfoDialog
//

/// バージョン情報ダイアログ
class TVersionInfoDialog : public owl::TDialog {
public:
    TVersionInfoDialog(TWindow* parent) : owl::TDialog(parent, IDD_VERSION) {}
    void SetupWindow() override {
        owl::TDialog::SetupWindow();
        //
        SetDlgItemText(IDC_PRODUCTNAME, owl::TString(VER_PRODUCTNAME));
        SetDlgItemText(IDC_COPYRIGHT, owl::TString(VER_LEGALCOPYRIGHT));
        // 横方向中央に移動
        MoveDlgItemToCenter(IDC_PRODUCTNAME);
        MoveDlgItemToCenter(IDC_COPYRIGHT);
    }
private:
    void MoveDlgItemToCenter(int id) {
        owl::TRect clientRect = GetClientRect();
        HWND hwnd = GetDlgItem(id);
        owl::TRect scRect;
        ::GetWindowRect(hwnd, &scRect);
        owl::TRect ccRect = MapScreenToClient(scRect);
        owl::TScreenDC dc;
        dc.SelectObject(owl::TFont(GetWindowFont()));
        owl::tstring text = GetDlgItemText(id);
        int width = dc.GetTextExtent(text, int(text.length())).cx;
        ::SetWindowPos(hwnd, 0,
                       (clientRect.Width() - width) / 2, ccRect.top, width + 2, ccRect.Height(),
                       SWP_NOZORDER);
    }
};

//------------------------------------------------------------
//
// class TMyClientWindow
//

/// アプリケーションフレームのクライアントウィンドウ
class TMyClientWindow : public owl::TWindow {

    // *** constructor ***
public:
    TMyClientWindow() : owl::TWindow(static_cast<TWindow*>(nullptr)) {}

};

//------------------------------------------------------------
//
// class TMyFrameWindow
//

/// アプリケーションのフレームウインドウ
class TMyFrameWindow : public owl::TFrameWindow {
public:
    TMyFrameWindow(LPCTSTR title, TWindow* clientWnd)
        : owl::TFrameWindow(/*parent*/nullptr, title, clientWnd) {
        AssignMenu(MAIN_MENU);
    }
};

//------------------------------------------------------------
//
// class TMyApp
//

/// アプリケーションクラス
class TMyApp : public owl::TApplication {
public:
    TMyApp(LPCTSTR title) : owl::TApplication(title) {}
    virtual void InitMainWindow() override;
    void CmHelpAbout();
    void CmSample();

    DECLARE_RESPONSE_TABLE(TMyApp);
};

DEFINE_RESPONSE_TABLE1(TMyApp, owl::TApplication)
    EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
    EV_COMMAND(CM_SAMPLE, CmSample),
END_RESPONSE_TABLE;

void TMyApp::InitMainWindow() 
{
    TMyFrameWindow* frame = new TMyFrameWindow{GetName(), new TMyClientWindow};
    frame->SetIcon(this, IDI_APP);
    frame->SetIconSm(this, IDI_APP);
    SetMainWindow(frame);
}

void TMyApp::CmHelpAbout()
{
    TVersionInfoDialog(GetMainWindow()).Execute();
}

void TMyApp::CmSample()
{
    owl::TDialog{GetMainWindow(), IDD_SAMPLE}.Execute();
}

//------------------------------------------------------------
//
// OwlMain 
//

int OwlMain(int /*argc*/, TCHAR** /*argv*/)
{
    owl::tstring title = _T("(title not loaded)");
    int result = -1;
    try {
        title = owl::GetGlobalModule().LoadString(IDS_APPNAME);
        TMyApp app{title.c_str()};
        result = app.Run();
        ODS("OwlMain|result=" << result);
    }
    catch (const std::exception& x) {
        MessageBox(0, owl::TString{x.what()}, title.c_str(), MB_ICONSTOP | MB_OK);
    }
    catch (...) {
        MessageBox(0, _T("Unexpected exception."), title.c_str(), MB_ICONSTOP | MB_OK);
    }
    return result;
}

//------------------------------------------------------------

// end of <main.cpp>
