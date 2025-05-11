//
// Created by issbe on 11/05/2025.
//

#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <iostream>
#include <string>


std::string readFile(const char* path) {
    FILE* file;
    fopen_s(&file, path, "rt");
    if (!file) {
        std::cout << path << " not found" << std::endl;
        return "";
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    std::string content;
    content.reserve(size);

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c >= 0 && c <= 127) {
            content.push_back(c);
        } else {
            content.push_back(' ');
        }
    }

    fclose(file);
    return content;
}


#endif //FILEUTILS_H
