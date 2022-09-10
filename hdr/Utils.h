#pragma once
void cleanup(std::vector<int> &rolls, std::string &result, char &oper, int &mod, int &sum);
void error_message(int id);
bool parse_input(char &d, char &oper, int &num_dice, int &num_sides);
