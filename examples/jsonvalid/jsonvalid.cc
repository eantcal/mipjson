//  
// This file is part of MipTknzr Library Project
// Copyright (c) Antonino Calderone (antonino.calderone@gmail.com)
// All rights reserved.  
// Licensed under the MIT License. 
// See COPYING file in the project root for full license information.
//


/* -------------------------------------------------------------------------- */

#include <assert.h>
#include <sstream>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <memory>
#include <set>
#include <map>
#include <fstream>
#include <string>

#ifdef _UNICODE
#include <locale> 
#include <codecvt>
#include <iomanip>
#endif

#include "mip_json_obj.h"
#include "mip_json_parser.h"


/* -------------------------------------------------------------------------- */

int main(int argc, mip::char_t* argv[])
{
    if (argc<2) {
        std::_cerr << _T("File name missing") << std::endl;
        return 1;
    }

    mip::json_parser_t parser(& std::_cout);

    const mip::char_t* filename = argv[1];

    mip::_ifstream is(filename, std::ios::in | std::ios::binary);

    if (!is.is_open()) {
        std::_cerr << _T("Cannot open ") << filename << std::endl;
        return 1;
    }

#ifdef _UNICODE
    const std::locale utf16_locale
        = std::locale(
            std::locale(),
            new std::codecvt_utf16<
            wchar_t,
            0x10ffff,
            std::codecvt_mode(std::little_endian | std::consume_header)>());

    is.imbue(utf16_locale);
#endif

    if (!is.is_open() || is.bad()) {
        std::cerr << _T("error reading the input stream");
        return 1;
    }
    
    std::_cout << _T("Parsing ...") << std::endl << std::endl;

    mip::_stringstream errlog;
    auto res = parser.parse(is, errlog);

    std::_cout 
        << std::endl << std::endl 
        << _T("...done") 
        << std::endl << std::endl;

    if (! res.first) {
        std::_cerr  
            << std::endl 
            << _T("JSON text is Invalid: ") 
            << errlog.str()
            << std::endl;
        return 1;
    }

    std::_cout 
        << std::endl 
        << std::endl 
        << _T("JSON is Valid") 
        << std::endl 
        << std::endl;

    std::_cout 
        << _T("Compact representation")
        << std::endl 
        << std::endl;

    if (res.second) {
        std::_cout 
            << *res.second 
            << std::endl;
    }
    else {
        std::_cout << _T("null") << std::endl;
    }


    return 0;
}
