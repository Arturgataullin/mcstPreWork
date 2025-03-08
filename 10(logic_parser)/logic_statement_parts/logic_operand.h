//
// Created by artur on 08.03.2025.
//

#ifndef MCSTSTAJ_LOGIC_OPERAND_H
#define MCSTSTAJ_LOGIC_OPERAND_H

#include <vector>
#include "operand.h"

namespace logic_parser_ns {
    class LogicOperand {
    private:
        unsigned priority;
        std::vector<Operand> operands_belong;
    public:
        LogicOperand(unsigned priority, Operand& oper1, Operand& oper2) : priority(priority) {
            operands_belong.push_back(oper1);
            operands_belong.push_back(oper2);
        }

        ~LogicOperand() = default;

        void increase_priority() {
            priority++;
        }
    };
}
#endif //MCSTSTAJ_LOGIC_OPERAND_H
