#include "navigation.h"
#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <cstring>
using namespace std;

static string previousDir;

void listFiles() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    cout << "\nCurrent Directory: " << cwd << "\n";

    DIR *dir = opendir(cwd);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
        cout << " - " << entry->d_name << endl;

    closedir(dir);
}

void changeDirectory(const string& dir) {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    previousDir = cwd;

    if (chdir(dir.c_str()) == 0)
        cout << "Changed to: " << dir << endl;
    else
        perror("chdir");
}

void goBack() {
    if (!previousDir.empty()) {
        chdir(previousDir.c_str());
        cout << "Returned to: " << previousDir << endl;
    } else cout << "No previous directory.\n";
}

void goHome() {
    const char* home = getenv("HOME");
    if (home) chdir(home);
    cout << "Returned to home directory.\n";
}
