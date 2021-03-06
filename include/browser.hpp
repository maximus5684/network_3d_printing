// Copyright 2020 Joshua Whitley
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef N3DP_BROWSER_HPP
#define N3DP_BROWSER_HPP

#include <memory>
#include <cstdio>
#include <mutex>
#include <map>
#include <iomanip>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif

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
