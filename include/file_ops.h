#ifndef FILE_OPS_H
#define FILE_OPS_H
#include <string>
void createFile(const std::string& name);
void deleteFile(const std::string& name);
void copyFile(const std::string& src, const std::string& dest);
void moveFile(const std::string& src, const std::string& dest);
#endif
