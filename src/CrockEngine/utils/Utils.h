//
// Created by issbe on 29/06/2025.
//


#ifndef UTILS_H
#define UTILS_H

#endif //UTILS_H

#include <iostream>
#include <string>

class Utils {
public:
    static std::string getFileExt(const std::string& filePath) {
        std::string ext;
        for (int i = 0; i < filePath.length(); i++) {
            if (filePath[i] == '.') {
                for (int j = i + 1; j < filePath.length(); j++) {
                    ext+= filePath[j];
                }
            }
        }
        // std::cout << ext << std::endl;
        return ext;
    }

};