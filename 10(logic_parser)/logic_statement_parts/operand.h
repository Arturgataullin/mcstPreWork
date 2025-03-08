//
// Created by artur on 08.03.2025.
//

#ifndef MCSTSTAJ_OPERAND_H
#define MCSTSTAJ_OPERAND_H

#include <string>

namespace logic_parser_ns {
    class Operand {
    private:
        std::string name;
        bool value;
    public:
        Operand() = default;
        Operand(const std::string& name, bool logic_val) : name(name), value(logic_val) {}
        Operand(const Operand& other) : name(other.name), value(other.value) {}

        ~Operand() = default;
    };
}
#endif //MCSTSTAJ_OPERAND_H
