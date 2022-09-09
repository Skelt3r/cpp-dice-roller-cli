#include <iostream>
#include "Utils.h"

void cleanup(int rolls[], std::string &result, char &oper, int &mod, int &sum) {
    delete[] rolls;
    result = "";
    oper = '+';
    mod = sum = 0;
}

void error_message(int id) {
    switch (id) {
    case 0:
        std::cout << "\nInvalid format.\n"
            << "Try: # dice >> d >> # sides >> operator >> modifier\n"
            << "Valid examples : 1d20 | 1d12+5 | 2d6-1\n\n";
        break;
    case 1:
        std::cout << "\nMust roll at least 1 dice with at least 2 sides.\n\n";
        break;
    case 2:
        std::cout << "\nArithmetic operator must be \"+\" or \"-\".\n\n";
    }
}
