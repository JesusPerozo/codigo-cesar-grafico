///-----------------------------------------------------------------
///
/// @file      Codigo CesarFrm.h
/// @author    PerozoToyo
/// Created:   07/05/2017 11:29:17
/// @section   DESCRIPTION
///            Codigo_Cesar class declaration
///
///------------------------------------------------------------------

#ifndef __CODIGO_CESAR_H__
#define __CODIGO_CESAR_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/textfile.h>
////Header Include End

////Dialog Style Start
#undef Codigo_Cesar_STYLE
#define Codigo_Cesar_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class Codigo_Cesar : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Codigo_Cesar(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Codigo Cesar"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Codigo_Cesar_STYLE);
		void WxButton1Click(wxCommandEvent& event);
		virtual ~Codigo_Cesar();
		void Codigo_CesarActivate(wxActivateEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxButton2Click0(wxCommandEvent& event);
		void WxEdit2Updated(wxCommandEvent& event);
		void WxnewClick(wxCommandEvent& event);
		void WxnewClick0(wxCommandEvent& event);
		void WxnewClick1(wxCommandEvent& event);
		void WxopenClick(wxCommandEvent& event);
		void WxsaveClick(wxCommandEvent& event);
		void WxsaveasClick(wxCommandEvent& event);
		void Mnusalir1025Click(wxCommandEvent& event);
		void WxexitClick(wxCommandEvent& event);
		
		void guardar(){
            if (WxSaveFileDialog1->ShowModal() == wxID_CANCEL){
                return;
            }else{
                
                wxString ruta=WxSaveFileDialog1->GetPath();
                wxString LMensaje;
                int n=WxMemo2->GetNumberOfLines(); 
                wxTextFile archivoGuardar(ruta);
                
                archivoGuardar.Create();
                archivoGuardar.Open();
                archivoGuardar.Clear();
                for(int x=0; x<n;x++){
                    LMensaje=WxMemo2->GetLineText(x);
                    archivoGuardar.AddLine( wxT(Mensaje) );
                }
         
                archivoGuardar.Write();
                archivoGuardar.Close();
            }
        }		
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *WxSaveFileDialog1;
		wxFileDialog *WxOpenFileDialog1;
		wxMenuBar *WxMenuBar1;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxStaticText *WxStaticText5;
		wxStaticText *WxStaticText4;
		wxTextCtrl *WxMemo2;
		wxTextCtrl *WxMemo1;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxStaticText *WxStaticText3;
		wxPanel *WxPanel1;
        ////GUI Control Declaration End
		wxTextFile archivo;
		wxString mensaje;
        wxString temp;
        wxString filename;
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT2 = 1008,
			ID_WXSTATICTEXT1 = 1007,
			ID_WXSTATICTEXT5 = 1019,
			ID_WXSTATICTEXT4 = 1018,
			ID_WXMEMO2 = 1017,
			ID_WXMEMO1 = 1016,
			ID_WXEDIT2 = 1015,
			ID_WXEDIT1 = 1014,
			ID_WXBUTTON2 = 1013,
			ID_WXBUTTON1 = 1012,
			ID_WXSTATICTEXT3 = 1011,
			ID_WXPANEL1 = 1009,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
