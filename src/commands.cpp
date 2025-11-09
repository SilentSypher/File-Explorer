#include "commands.h"
#include "file_ops.h"
#include "navigation.h"
#include "search.h"      
#include "permissions.h"
#include <sstream>
#include <iostream>
using namespace std;


void handleCommand(const string& input) {
    stringstream ss(input);
    string cmd, arg1, arg2;
    ss >> cmd >> arg1 >> arg2;

    if (cmd == "ls") listFiles();
    else if (cmd == "cd") changeDirectory(arg1);
    else if (cmd == "back") goBack();
    else if (cmd == "home") goHome();
    else if (cmd == "create") createFile(arg1);
    else if (cmd == "delete") deleteFile(arg1);
    else if (cmd == "copy") copyFile(arg1, arg2);
    else if (cmd == "move") moveFile(arg1, arg2);
    else if (cmd == "search") searchFile(arg1);
    else if (cmd == "chmod") changePermissions(arg1, arg2);
    else if (cmd == "help") {
        cout << "\nCommands:\n"
             << "ls, cd <dir>, back, home, create <file>, delete <file>\n"
             << "copy <src> <dest>, move <src> <dest>, search <name>\n"
             << "chmod <file> <mode>, exit\n";
    }
    else cout << "Unknown command. Type 'help' for help.\n";
}
