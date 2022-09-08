#include <iostream>
#include <sstream>

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

        if (input == "exit") {
            return 0;
        }
        else if (d != 'd') {
            std::cout << "\nInvalid format.\n"
                      << "Try: num_dice >> d >> num_sides >> oper (optional) >> mod (optional)\n"
                      << "Valid examples : 1d20 | 1d12+5 | 2d6-1\n\n";
            continue;
        }
        else if (num_dice < 1 || num_sides < 2) {
            std::cout << "\nMust roll at least 1 dice with at least 2 sides.\n\n";
            continue;
        }
        else {
            for (int i = 0; i < num_dice; i++) {
                rolls[i] = rand() % num_sides + 1;
                sum += rolls[i];
                result.append(std::to_string(rolls[i]));
                if (i < num_dice - 1) result.append(", ");
            }
            if (oper == '+') sum += mod;
            else if (oper == '-') sum -= mod;
        }

        std::cout << "\nResult: " << result << "\n";
        if (num_dice > 1 || mod != 0)
            std::cout << "Mod: " << oper << mod << "\n" << "Sum: " << sum << "\n";
        std::cout << "\n";

        delete[] rolls;
        result = "";
        oper = '+';
        mod = 0;
        sum = 0;
    }
}
