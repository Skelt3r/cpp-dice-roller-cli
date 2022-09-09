#include <iostream>
#include <sstream>

void error_message(int id) {
    switch (id) {
    case 0:
        std::cout << "\nInvalid format.\n"
                  << "Try: # dice >> d >> # sides >> operator >> modifier\n"
                  << "Valid examples : 1d20 | 1d12+5 | 2d6-1\n\n";
    case 1:
        std::cout << "\nMust roll at least 1 dice with at least 2 sides.\n\n";
    case 2:
        std::cout << "\nArithmetic operator must be \"+\" or \"-\".\n\n";
    }
}

int main() {
    int num_dice = 1, num_sides = 20, mod = 0, sum = 0;
    char d = 'd', oper = '+';
    std::string input, result = "";
    srand(time(0));

    while (true) {
        std::cout << "Roll the dice:\n> ";
        std::cin >> input;
        std::istringstream stream(input);
        stream >> num_dice >> d >> num_sides >> oper >> mod;
        int *rolls = new int[num_dice];

        if (input == "exit" || input == "quit") {
            return 0;
        }
        else if (d != 'd') {
            error_message(0);
            continue;
        }
        else if (num_dice < 1 || num_sides < 2) {
            error_message(1);
            continue;
        }
        else if (oper != '+' && oper != '-') {
            error_message(2);
            continue;
        }
        else {
            for (int i = 0; i < num_dice; i++) {
                rolls[i] = rand() % num_sides + 1;
                sum += rolls[i];
                result.append(std::to_string(rolls[i]));
                if (i < num_dice - 1) result.append(", ");
            }
            (oper == '+') ? sum += mod : sum -= mod;
        }

        std::cout << "\nResult: " << result << "\n"
                  << "Mod: " << oper << mod << "\n"
                  << "Sum: " << sum << "\n\n";

        delete[] rolls;
        result = "";
        oper = '+';
        mod = sum = 0;
    }
}
