#include "commands.h"
#include <iostream>
using namespace std;

int main() {
    cout << "___________________________________" << endl;
    cout << " Linux File Explorer (C++11)" << endl;
    cout << " Type 'help' for available commands" << endl;
    cout << "___________________________________" << endl;

    string input;
    while (true) {
        cout << "\nExplorer> ";
        getline(cin, input);
        if (input == "exit") break;
        handleCommand(input);
    }

    cout << "Goodbye!\n";
    return 0;
}
