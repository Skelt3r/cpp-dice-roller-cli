#include <iostream>
#include <random>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int num_dice = 1, num_sides = 20, mod = 0, sum = 0;
    char d = 'd', oper = '+';
    string input, result = "";
    srand(time(0));

    while (true) {
        cout << "Roll the dice:\n> ";
        cin >> input;
        istringstream stream(input);
        stream >> num_dice >> d >> num_sides >> oper >> mod;
        int *rolls = new int[num_dice];

        if (input == "exit") {
            return 0;
        }
        else if (d != 'd') {
            cout << "\nInvalid format.\nTry: num_dice >> d >> num_sides >> oper (optional) >> mod (optional)\nValid examples: 1d20 | 1d12+5 | 2d6-1\n\n";
            continue;
        }
        else if (num_dice < 1 || num_sides < 2) {
            cout << "\nMust roll at least 1 dice with at least 2 sides.\n\n";
            continue;
        }
        else {
            for (int i = 0; i < num_dice; i++) {
                rolls[i] = rand() % num_sides + 1;
                sum += rolls[i];
                result.append(to_string(rolls[i]));
                if (i < num_dice - 1) result.append(", ");
            }
            if (oper == '+') sum += mod;
            else if (oper == '-') sum -= mod;
        }

        cout << "\nResult: " << result << "\n";
        if (num_dice > 1 || mod != 0)
            cout << "Mod: " << oper << mod << "\n" << "Sum: " << sum << "\n";
        cout << "\n";

        delete[] rolls;
        result = "";
        oper = '+';
        mod = 0;
        sum = 0;
    }
}
