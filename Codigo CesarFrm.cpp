///-----------------------------------------------------------------
///
/// @file      Codigo CesarFrm.cpp
/// @author    PerozoToyo
/// Created:   07/05/2017 11:29:17
/// @section   DESCRIPTION
///            Codigo_Cesar class implementation
///
///------------------------------------------------------------------

#include "Codigo CesarFrm.h"
#include <wx/textfile.h>
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Codigo_Cesar
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Codigo_Cesar,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Codigo_Cesar::OnClose)
	EVT_ACTIVATE(Codigo_Cesar::Codigo_CesarActivate)
	EVT_MENU(wxID_NEW, Codigo_Cesar::WxnewClick1)
	EVT_MENU(wxID_OPEN, Codigo_Cesar::WxopenClick)
	EVT_MENU(wxID_SAVE, Codigo_Cesar::WxsaveClick)
	EVT_MENU(wxID_SAVEAS, Codigo_Cesar::WxsaveasClick)
	EVT_MENU(wxID_EXIT, Codigo_Cesar::WxexitClick)
	
	EVT_TEXT(ID_WXEDIT2,Codigo_Cesar::WxEdit2Updated)
	
	EVT_TEXT(ID_WXEDIT1,Codigo_Cesar::WxEdit1Updated)
	EVT_BUTTON(ID_WXBUTTON2,Codigo_Cesar::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,Codigo_Cesar::WxButton1Click)
END_EVENT_TABLE()
////Event Table End

Codigo_Cesar::Codigo_Cesar(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Codigo_Cesar::~Codigo_Cesar()
{
}

void Codigo_Cesar::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-1, -4), wxSize(519, 414));
	WxPanel1->SetBackgroundColour(wxColour(166,210,255));

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, _("Cifrado Cesar"), wxPoint(51, 37), wxDefaultSize, 0, _("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(18, wxSWISS, wxITALIC, wxBOLD, false, _("Times New Roman")));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("Codificar"), wxPoint(261, 181), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));
	WxButton1->Enable(false);

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("Decodificar"), wxPoint(257, 363), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->Enable(false);

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _(""), wxPoint(379, 139), wxSize(37, 19), 0, wxTextValidator(wxFILTER_NUMERIC, NULL), _("WxEdit1"));

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _(""), wxPoint(372, 333), wxSize(37, 19), 0, wxTextValidator(wxFILTER_NUMERIC, NULL), _("WxEdit2"));

	WxMemo1 = new wxTextCtrl(WxPanel1, ID_WXMEMO1, wxEmptyString, wxPoint(26, 74), wxSize(228, 143), wxTE_MULTILINE, wxDefaultValidator, _("WxMemo1"));
	WxMemo1->SetMaxLength(0);
	WxMemo1->SetFocus();
	WxMemo1->SetInsertionPointEnd();

	WxMemo2 = new wxTextCtrl(WxPanel1, ID_WXMEMO2, wxEmptyString, wxPoint(24, 252), wxSize(226, 144), wxTE_MULTILINE, wxDefaultValidator, _("WxMemo2"));
	WxMemo2->SetMaxLength(0);
	WxMemo2->SetFocus();
	WxMemo2->SetInsertionPointEnd();

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, _("Panel de Codificado"), wxPoint(266, 74), wxDefaultSize, 0, _("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxBOLD, false, _("System")));

	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, _("Panel de Decodificado"), wxPoint(251, 259), wxDefaultSize, 0, _("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxBOLD, false, _("System")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Nro de Decodificado:"), wxPoint(254, 328), wxDefaultSize, 0, _("WxStaticText1"));
	WxStaticText1->SetBackgroundColour(wxColour(159,207,255));
	WxStaticText1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Small Fonts")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Nro de codificado:"), wxPoint(265, 136), wxDefaultSize, 0, _("WxStaticText2"));
	WxStaticText2->SetBackgroundColour(wxColour(164,209,255));
	WxStaticText2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Small Fonts")));

	WxMenuBar1 = new wxMenuBar();
	wxMenu *wxID_FILE_Mnu_Obj = new wxMenu();
	wxID_FILE_Mnu_Obj->Append(wxID_NEW, _("Nuevo"), _(""), wxITEM_NORMAL);
	wxID_FILE_Mnu_Obj->Append(wxID_OPEN, _("Abrir"), _(""), wxITEM_NORMAL);
	wxID_FILE_Mnu_Obj->Append(wxID_SAVE, _("Guardar"), _(""), wxITEM_NORMAL);
	wxID_FILE_Mnu_Obj->Append(wxID_SAVEAS, _("Guardar Como"), _(""), wxITEM_NORMAL);
	wxID_FILE_Mnu_Obj->Append(wxID_EXIT, _("Salir"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(wxID_FILE_Mnu_Obj, _("Archivo"));
	SetMenuBar(WxMenuBar1);

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	WxSaveFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);

	SetTitle(_("Codigo Cesar"));
	SetIcon(wxNullIcon);
	SetSize(8,8,437,438);
	Center();
	
	////GUI Items Creation End
}

void Codigo_Cesar::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Codigo_CesarActivate
 */
void Codigo_Cesar::Codigo_CesarActivate(wxActivateEvent& event)
{
	// insert your code here
}

/*
 * WxButton1Click
 */
void Codigo_Cesar::WxButton1Click(wxCommandEvent& event)
{
	int tam;
	long numero;
    wxString cadena,temporal;
    char temp;
    cadena=WxMemo1->GetValue();
	tam=cadena.size();
	temporal=WxEdit1->GetValue();
    
    if(!temporal.ToLong(&numero)) { /* error! */ }
    for(int x=0;x<tam;x++){
       temp=cadena[x];
       
       if(temp>='a' && temp<='z'){
            temp=temp-32;
        }
       if(temp>='A' && temp<='Z'){
            temp=temp-(numero%26);
       
            if(temp<'A'){
                temp=temp+26;
            }
       }     
       cadena[x]=temp;
    }       
	
    WxMemo2->SetValue(cadena);
    
    // insert your code here
}

/*
 * WxButton2Click
 */
void Codigo_Cesar::WxButton2Click(wxCommandEvent& event)
{
	int tam;
	long numero;
    wxString cadena,temporal;
    char temp;
    cadena=WxMemo2->GetValue();
	tam=cadena.size();
	temporal=WxEdit2->GetValue();   
    if(!temporal.ToLong(&numero)) { }
    
    for(int x=0;x<tam;x++){
       temp=cadena[x];
       
       if(temp>='a' && temp <='z'){
            temp=temp-32;
        }     
       
       if((temp>='A' && temp<='Z')){
            temp=temp+(numero%26);
       
            if(temp>'Z'){
                temp=temp-26;
            }
       }     
    cadena[x]=temp;
    }       
	
    WxMemo1->SetValue(cadena);
    // insert your code here
}

/*
 * WxEdit1Updated
 */
void Codigo_Cesar::WxEdit1Updated(wxCommandEvent& event)
{
	if(WxEdit1->GetValue()==""){
        WxButton1->Enable(false);
    }else{
        WxButton1->Enable(true);
    }
    // insert your code here
}





/*
 * WxButton2Click0
 */

/*
 * WxEdit2Updated
 */
void Codigo_Cesar::WxEdit2Updated(wxCommandEvent& event)
{
	
	if(WxEdit2->GetValue()==""){
        WxButton2->Enable(false);
    }else{
        WxButton2->Enable(true);
    }
   

    // insert your code here
}


void Codigo_Cesar::WxnewClick1(wxCommandEvent& event)
{
    archivo.Close();
	WxMemo1->SetValue("");
    WxMemo2->SetValue("");
    WxEdit1->SetValue("");
    WxEdit2->SetValue("");
    // insert your code here
}

/*
 * WxopenClick
 */
void Codigo_Cesar::WxopenClick(wxCommandEvent& event)
{
    if(WxOpenFileDialog1->ShowModal() == wxID_CANCEL){
        return ;
    }else{
        WxMemo2->SetValue("");
        
        filename=WxOpenFileDialog1->GetPath();
        archivo.Open(filename);
        mensaje = archivo.GetFirstLine();
        mensaje +='\n';
        WxMemo2->SetValue(mensaje);
        while(!archivo.Eof()){
            mensaje +=archivo.GetNextLine();
            mensaje +='\n';
            WxMemo2->SetValue(mensaje); 
        }
    }
    	// insert your code here
}

/*
 * WxsaveClick
 */
void Codigo_Cesar::WxsaveClick(wxCommandEvent& event)
{
	// insert your code here
	if(archivo.IsOpened() != false){
        wxString LMensaje;
        int n=WxMemo2->GetNumberOfLines();
        archivo.Clear();
        for(int x=0; x<n;x++){
            LMensaje=WxMemo2->GetLineText(x);
            archivo.AddLine( wxT(Mensaje) );
        }
        archivo.Write();
    }else{
        guardar();
    }    
	
}

/*
 * WxsaveasClick
 */
void Codigo_Cesar::WxsaveasClick(wxCommandEvent& event)
{
	guardar();
        
    // insert your code here
}

/*
 * Mnusalir1025Click
 */
void Codigo_Cesar::Mnusalir1025Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxexitClick
 */
void Codigo_Cesar::WxexitClick(wxCommandEvent& event)
{
	Close();
    // insert your code here
}
