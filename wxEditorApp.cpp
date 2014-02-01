/***************************************************************
 * Name:      wxEditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Erick Barrera (me@erickbarrera.com)
 * Created:   2014-01-27
 * Copyright: Erick Barrera (ErickBarrera.com)
 * License:
 **************************************************************/

#include "wxEditorApp.h"

//(*AppHeaders
#include "wxEditorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxEditorApp);

bool wxEditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxEditorFrame* Frame = new wxEditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
