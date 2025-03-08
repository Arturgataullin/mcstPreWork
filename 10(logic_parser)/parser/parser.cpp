//
// Created by artur on 08.03.2025.
//

#include <algorithm>
#include <vector>
#include "parser.h"

namespace logic_parser_ns {
    void Parser::parse(const std::string& str_to_parse) {
        std::string buf;
        std::vector<std::string> tokens;
        bool is_open = false;
        unsigned priority_buff = 0;
        std::for_each(str_to_parse.begin(), str_to_parse.end(), [&](auto symb){
            if (symb <= 'Z' && symb >= 'A')
                buf += symb;
            else if (symb == '(' && !is_open) {
                priority_buff++;
                is_open = true;
                tokens.push_back(buf);
            }
            else if (symb == ')' && is_open) {
                priority_buff--;
                is_open = false;
                tokens.push_back(buf);
            }
            else if (symb == ' ') {
                tokens.push_back(buf);
            }
            else if () {

            }
            else {

            }
        });
    }
}
