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
  frame->CenterOnScreen();
  frame->Show(true);

  SetTopWindow(frame);

  return true;
}
}  // namespace Network3DPrinting
