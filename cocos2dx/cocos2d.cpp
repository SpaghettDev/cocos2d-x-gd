/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "cocos2d.h"

NS_CC_BEGIN

const char* cocos2dVersion()
{
    return "2.2.3";
}

NS_CC_END

#include <fstream>

namespace matdash {
    struct Console {
        std::ofstream out, in;
        Console() {
            AllocConsole();
            out = decltype(out)("CONOUT$", std::ios::out);
            in = decltype(in)("CONIN$", std::ios::in);
            std::cout.rdbuf(out.rdbuf());
            std::cerr.rdbuf(out.rdbuf());
            std::cin.rdbuf(in.rdbuf());

            FILE* dummy;
            freopen_s(&dummy, "CONOUT$", "w", stdout);
            freopen_s(&dummy, "CONOUT$", "w", stderr);
        }
        ~Console() {
            out.close();
            in.close();
        }
    };
}

static matdash::Console console;

void impl_ROB_UNIMPLEMENTED(std::source_location loc) {
    std::stringstream ss;
    ss << "Unimplemented function " << loc.function_name() << " at " << loc.file_name() << ":" << loc.line();
    auto str = ss.str();
    CCLOG("%s", str.c_str());
    cocos2d::CCMessageBox(str.c_str(), "Unimplemented function");
    std::abort();
}