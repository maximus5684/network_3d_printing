#include <browser.hpp>

namespace Network3DPrinting
{
  BrowserFrame::BrowserFrame(
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
  {
    InitUI();
  }

  void BrowserFrame::InitUI()
  {
    wxMenu* menu_file = new wxMenu;
    menu_file->Append(wxID_EXIT);

    wxMenu* menu_help = new wxMenu;
    menu_help->Append(wxID_ABOUT);

    wxMenuBar* menu_bar = new wxMenuBar;
    menu_bar->Append(menu_file, "&File");
    menu_bar->Append(menu_help, "&Help");

    SetMenuBar(menu_bar);
  }

  void BrowserFrame::OnExit(wxCommandEvent& event)
  {
    static_cast<void>(event);
    Close(true);
  }

  bool Browser::OnInit()
  {
    // wxWidgets Init
    frame = new BrowserFrame("Network 3D Printing Browser", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);

    SetTopWindow(frame);

    return true;
  }
}
