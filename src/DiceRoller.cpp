#include <iostream>
#include <sstream>
#include <vector>
#include "Utils.h"

int main()
{
    int num_dice = 1, num_sides = 20, mod = 0, sum = 0;
    char d = 'd', oper = '+';
    std::string input, result = "";
    std::vector<int> rolls;
    srand(time(0));

    while (true)
    {
        std::cout << "Roll the dice:\n> ";
        std::cin >> input;
        std::istringstream stream(input);
        stream >> num_dice >> d >> num_sides >> oper >> mod;

        if (input == "exit" || input == "quit") return 0;
        else if (!parse_input(d, oper, num_dice, num_sides))
        {
            cleanup(rolls, result, oper, mod, sum);
            continue;
        }

        for (int i = 0; i < num_dice; i++)
        {
            rolls.push_back(rand() % num_sides + 1);
            sum += rolls[i];
            result.append(std::to_string(rolls[i]));
            if (i < num_dice - 1) result.append(", ");
        }

        (oper == '+') ? sum += mod : sum -= mod;

        std::cout << "\nResult: " << result << "\n"
                  << "Mod: " << oper << mod << "\n"
                  << "Sum: " << sum << "\n\n";

        cleanup(rolls, result, oper, mod, sum);
    }
}
