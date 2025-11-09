#include "search.h"
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <cstring>
using namespace std;

void searchFile(const string& name, const string& path) {
    DIR *dir = opendir(path.c_str());
    if (!dir) return;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        string entryName = entry->d_name;
        if (entryName == "." || entryName == "..") continue;

        string fullPath = path + "/" + entryName;

        if (entry->d_type == DT_DIR)
            searchFile(name, fullPath);
        else if (entryName == name)
            cout << "Found: " << fullPath << endl;
    }

    closedir(dir);
}
