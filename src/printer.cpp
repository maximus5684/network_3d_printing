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

#include <printer.hpp>

#include <string>

// G Commands
static constexpr char CMD_HOME[] = "G28";                // Homes all axes - optionally add axes as arguments

// M Commands
static constexpr char CMD_STOP[] = "M0";                 // Stops what the printer is currently doing
static constexpr char CMD_SLEEP[] = "M1";                // Put the printer to sleep (M & G commands wake it up)
static constexpr char CMD_SD_SELECT_FILE[] = "M23";      // Select file on SD card - provide file path/name as argument
static constexpr char CMD_SD_PRINT_SELECTED[] = "M24";   // Print the file selected using M23 from the SD card
static constexpr char CMD_SD_START_WRITE[] = "M28";      // Start writing datagrams to SD card
static constexpr char CMD_SD_END_WRITE[] = "M29";        // Stop writing datagrams to SD card
static constexpr char CMD_SD_DELETE_FILE[] = "M30";      // Delete file on SD card - requires filename argument
static constexpr char CMD_EMERGENCY_STOP[] = "M112";     // Immediately stop what the printer is doing and shut down hardware
static constexpr char CMD_SD_PRINT_FILE[] = "M6030";     // (QIDI) Start printing the file provided as argument

// M Queries
static constexpr char QRY_SD_FILE_LIST[] = "M20";        // List directory contents - optional folder argument
static constexpr char QRY_SD_PRINTING_STATUS[] = "M27";  // Get SD printing status
static constexpr char QRY_CURRENT_POSITION[] = "M114";   // Get position
static constexpr char QRY_FIRMWARE_INFO[] = "M115";      // Get firmware info
static constexpr char QRY_ENDSTOP_STATE[] = "M119";      // Get endstop states
static constexpr char QRY_HW_STATUS[] = "M4000";         // (QIDI) Get temperatures/positions
static constexpr char QRY_POS[] = "M4001";               // (QIDI) Get position information
static constexpr char QRY_FW_VERSION[] = "M4002";        // (QIDI) Get firmware version

namespace Network3DPrinting
{
Printer::Printer(std::string && model, uint32_t port) :
  model_name_(model),
  udp_port_(port)
{
}

Printer::~Printer() {}

QidiTechXPro::QidiTechXPro() :
  Printer("Qidi Tech X-Pro", 3000)
{
}

QidiTechXPro::~QidiTechXPro() {}

std::map<std::string, uint32_t> QidiTechXPro::get_files(std::string folder)
{
  std::map<std::string, uint32_t> files;
  // submit QRY_SD_FILE_LIST
  // parse response
  return files;
}
}  // namespace Network3DPrinting
