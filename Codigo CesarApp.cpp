//---------------------------------------------------------------------------
//
// Name:        Codigo CesarApp.cpp
// Author:      PerozoToyo
// Created:     07/05/2017 11:29:17
// Description: 
//
//---------------------------------------------------------------------------

#include "Codigo CesarApp.h"
#include "Codigo CesarFrm.h"
#include <wx/textfile.h>
IMPLEMENT_APP(Codigo_CesarApp)

bool Codigo_CesarApp::OnInit()
{
    Codigo_Cesar* frame = new Codigo_Cesar(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Codigo_CesarApp::OnExit()
{
	return 0;
}
