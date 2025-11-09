#include "file_ops.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

void createFile(const string& name) {
    ofstream file(name.c_str());
    if (file) cout << "File created: " << name << endl;
    else cerr << "Error creating file.\n";
}

void deleteFile(const string& name) {
    if (remove(name.c_str()) == 0)
        cout << "Deleted: " << name << endl;
    else
        perror("remove");
}

void copyFile(const string& src, const string& dest) {
    ifstream in(src.c_str(), ios::binary);
    ofstream out(dest.c_str(), ios::binary);
    if (!in || !out) {
        cerr << "Copy failed.\n";
        return;
    }
    out << in.rdbuf();
    cout << "Copied " << src << " to " << dest << endl;
}

void moveFile(const string& src, const string& dest) {
    if (rename(src.c_str(), dest.c_str()) == 0)
        cout << "Moved " << src << " to " << dest << endl;
    else
        perror("rename");
}
