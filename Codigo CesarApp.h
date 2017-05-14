//---------------------------------------------------------------------------
//
// Name:        Codigo CesarApp.h
// Author:      PerozoToyo
// Created:     07/05/2017 11:29:17
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __CODIGO_CESARApp_h__
#define __CODIGO_CESARApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Codigo_CesarApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
