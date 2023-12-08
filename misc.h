// <misc.h>
//
// Project owlnext-sdi-skeleton
// Copyright (C) 2023 neige68
//
/// \file
/// \brief misc
//
// Compiler: VC14.2
// Library:  OWL7
//

#ifndef misc_h
#define misc_h

//------------------------------------------------------------
//
/// OutputDebugString
//

#ifdef NDEBUG
# define ODS(s) ((void)0)
#else
# define ODS(s)                                         \
    do {                                                \
        TDebugMonitorStarter::Instance();               \
        owl::tostringstream ODS_oss;                    \
        ODS_oss << s << std::endl;                      \
        ::OutputDebugString(ODS_oss.str().c_str());     \
    } while (0)
#endif

//------------------------------------------------------------
//
/// \class TDebugMonitorStarter
//
/// デバッグモニタを始動

class TDebugMonitorStarter {
public:
    static TDebugMonitorStarter& Instance();
private:
    TDebugMonitorStarter() {
        PostMessage(HWND_BROADCAST, RegisterWindowMessage(_T("StartDebugMonitor")), GetCurrentProcessId(), 0);
        OutputDebugString(_T("StartDebugMonitor\r\n"));
    }
};

//------------------------------------------------------------

/// システムのエラーメッセージを取得
//
/// inserts は無視(そのまま)
owl::tstring GetErrorMessage(DWORD id, DWORD dwLanguageId = 0);

//------------------------------------------------------------

#endif // misc_h

// end of <misc.h>
