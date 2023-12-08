// <misc.cpp>
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

#include "pch.h"
#pragma hdrstop

#include "misc.h"

//------------------------------------------------------------
//
// class TDebugMonitorStarter
//

//static
TDebugMonitorStarter& TDebugMonitorStarter::Instance()
{
    static TDebugMonitorStarter instance;
    return instance;
};

//
// end of class TDebugMonitorStarter
//
//------------------------------------------------------------
//
// システムのエラーメッセージを取得
//

owl::tstring GetErrorMessage(DWORD id, DWORD dwLanguageId)
{
    TCHAR* buf = 0;
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
                  | FORMAT_MESSAGE_MAX_WIDTH_MASK, 
                  0, id, dwLanguageId, (LPTSTR)&buf, 1, 0);
    owl::tstring result(buf ? buf : _T(""));
    LocalFree(buf);
    return result;
}

//------------------------------------------------------------

// end of <misc.cpp>
