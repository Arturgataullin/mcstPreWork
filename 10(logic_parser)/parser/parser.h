//
// Created by artur on 08.03.2025.
//

#ifndef MCSTSTAJ_PARSER_H
#define MCSTSTAJ_PARSER_H

#include <string>

namespace logic_parser_ns {
    class Parser {
    private:
        std::string str;
    public:
        Parser() = default;
        ~Parser() = default;
        void parse(const std::string& str_to_parse);
    };
}

#endif //MCSTSTAJ_PARSER_H
