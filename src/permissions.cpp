#include "permissions.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void changePermissions(const string& file, const string& perm) {
    string cmd = "chmod " + perm + " " + file;
    int result = system(cmd.c_str());
    if (result == 0)
        cout << "Permissions updated for " << file << endl;
    else
        cerr << "Failed to change permissions.\n";
}
