/***************************************************************
 * Name:      wxEditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Erick Barrera (me@erickbarrera.com)
 * Created:   2014-01-27
 * Copyright: Erick Barrera (ErickBarrera.com)
 * License:
 **************************************************************/

#include "wxEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxEditorFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(wxEditorFrame)
const long wxEditorFrame::idMenuQuit = wxNewId();
const long wxEditorFrame::idMenuAbout = wxNewId();
const long wxEditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxEditorFrame,wxFrame)
    //(*EventTable(wxEditorFrame)
    // EVT_CLOSE(wxEditorFrame::OnClose)
    EVT_MENU(idMenuQuit, wxEditorFrame::OnQuit)
    EVT_MENU(idMenuAbout, wxEditorFrame::OnAbout)
    EVT_MENU(idMenuOpen, wxEditorFrame::OnOpen)
    EVT_MENU(idMenuSave, wxEditorFrame::OnSave)
    //*)
END_EVENT_TABLE()

wxEditorFrame::wxEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxEditorFrame)
    wxMenuItem* MenuItem4; //Save
    wxMenuItem* MenuItem3; //Open
    wxMenuItem* MenuItem2; //About
    wxMenuItem* MenuItem1; //Quit
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, _("Erick\'s Simple Pad"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("Open"), _("Open a File"), wxITEM_NORMAL);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSave, _("Save"), _("Save a File"), wxITEM_NORMAL);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->Append(MenuItem4);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    textControl = new wxTextCtrl(this, ID_TextBox,
                                 wxT(""), wxDefaultPosition, wxDefaultSize,
                                 wxTE_MULTILINE | wxTE_RICH , wxDefaultValidator, wxTextCtrlNameStr);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxEditorFrame::OnOpen);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxEditorFrame::OnAbout);
    //*)

}

wxEditorFrame::~wxEditorFrame()
{
    //(*Destroy(wxEditorFrame)
    //*)
}

void wxEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxEditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxEditorFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""),
            wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"),
            wxFD_OPEN );
    int response = openDialog->ShowModal();
    if(response == wxID_OK)
    {
        //if response ok, then load contents into textControl
        this->textControl->LoadFile(openDialog->GetPath());
    }


}

void wxEditorFrame::OnSave(wxCommandEvent& event)
{
    wxFileDialog *openDialog = new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""),
            wxT("Text Files (*.txt)|*.txt|C++ Files (*.cpp)|*.cpp|Header Files (*.h)|*.h"),
            wxFD_SAVE );
    int response = openDialog->ShowModal();
     if(response == wxID_OK)
    {
        //if response ok, then save contents into chosen file
        this->textControl->SaveFile(openDialog->GetPath());
    }

}
