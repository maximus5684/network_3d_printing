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

#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include <map>
#include <string>

namespace Network3DPrinting
{
class Printer
{
public:
  Printer(std::string && model, uint32_t port);
  virtual ~Printer();
  virtual std::map<std::string, uint32_t> get_files(std::string folder = "") = 0;

private:
  std::string model_name_;
  uint32_t udp_port_;
};

class QidiTechXPro :
  public Printer
{
public:
  QidiTechXPro();
  ~QidiTechXPro();
  std::map<std::string, uint32_t> get_files(std::string folder = "");
};
}  // namespace Network3DPrinting

#endif  // PRINTER_HPP_
