#include <iostream>
#include <vector>
#include "Utils.h"

void cleanup(std::vector<int> &rolls, std::string &result, char &oper, int &mod, int &sum)
{
    rolls.clear();
    result = "";
    oper = '+';
    mod = sum = 0;
}

void error_message(int id)
{
    switch (id)
    {
    case 1:
        std::cout << "\nInvalid format.\n"
                  << "Try: # dice >> d >> # sides >> operator >> modifier\n"
                  << "Valid examples : 1d20 | 1d12+5 | 2d6-1\n\n";
        break;
    case 2:
        std::cout << "\nMust roll at least 1 dice with at least 2 sides.\n\n";
        break;
    case 3:
        std::cout << "\nArithmetic operator must be \"+\" or \"-\".\n\n";
    }
}

bool parse_input(char &d, char &oper, int &num_dice, int &num_sides)
{
    if (d != 'd')
    {
        error_message(1);
        return false;
    }
    else if (num_dice < 1 || num_sides < 2)
    {
        error_message(2);
        return false;
    }
    else if (oper != '+' && oper != '-')
    {
        error_message(3);
        return false;
    }
    else
        return true;
}
