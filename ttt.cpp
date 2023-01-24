#include <iostream>
#include <vector>
#include "ttt_header.hpp"
using namespace std;


int main() {

vector<char> position = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
bool victory1 = false;
bool victory2 = false;
int turns = 0;
int choice;

greet();
show_positions();
play(victory1, victory2, turns, choice, position);


system("pause");
}