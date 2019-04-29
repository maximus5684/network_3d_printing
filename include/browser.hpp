#ifndef N3DP_BROWSER_HPP
#define N3DP_BROWSER_HPP

#include <common.hpp>

namespace Network3DPrinting
{

  class BrowserFrame
    : public wxFrame
  {
    public:
      BrowserFrame(
        const wxString& title,
        const wxPoint& pos,
        const wxSize& size);

    private:
      void InitUI();
      void OnExit(wxCommandEvent& event);

      wxDECLARE_EVENT_TABLE();
  };

  class Browser
    : public wxApp
  {
    public:
      virtual bool OnInit();

    private:
      BrowserFrame* frame;
  };

  wxBEGIN_EVENT_TABLE(BrowserFrame, wxFrame)
    EVT_MENU(wxID_EXIT, BrowserFrame::OnExit)
  wxEND_EVENT_TABLE()

}  // namespace Network3DPrinting

wxIMPLEMENT_APP(Network3DPrinting::Browser);
wxDECLARE_APP(Network3DPrinting::Browser);

#endif  // N3DP_BROWSER_HPP
