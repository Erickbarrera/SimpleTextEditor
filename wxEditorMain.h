/***************************************************************
 * Name:      wxEditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Erick Barrera (me@erickbarrera.com)
 * Created:   2014-01-27
 * Copyright: Erick Barrera (ErickBarrera.com)
 * License:
 **************************************************************/

#ifndef WXEDITORMAIN_H
#define WXEDITORMAIN_H

//(*Headers(wxEditorFrame)
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/filedlg.h>
//*)

class wxEditorFrame: public wxFrame
{
    public:

        wxEditorFrame(wxWindow* parent,wxWindowID id = -1);
        wxTextCtrl* textControl;
        wxFileDialog*  openDialog;
       // void OnOpen(wxCommandEvent& event);
        virtual ~wxEditorFrame();

    private:

        //(*Handlers(wxEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnOpen(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxEditorFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)


        //(*Declarations(wxEditorFrame)
        wxStatusBar* StatusBar1;
        //*)


        DECLARE_EVENT_TABLE()
};

enum{
    ID_TextBox,
    idMenuQuit = 1000,
    idMenuAbout,
    idMenuOpen,
    idMenuSave
};

#endif // WXEDITORMAIN_H4
