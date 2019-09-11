#include "filehandler.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
Filehandler::Filehandler(std::string filename1) : filename(filename1) {}

std::string Filehandler::read() {
    std::string text;
    std::string line;
    std::ifstream myFile(filename.c_str());
    if ((bool) myFile) {
        while(getline(myFile,line)) {
            text = text.append(line);
            text = text.append("\n");
        }
        myFile.close();
    } else {
        std::cerr << "File doesn't exist" << std::endl;
        exit(1);
    }
    return text;
}

int Filehandler::write(std::string text) {
    std::ifstream myFile(filename.c_str());
    if ((bool) myFile) {
        std::cerr << "File already exists" << std::endl;
        exit(33);
    } else {
        std::ofstream myFile(filename.c_str());
        myFile << text;
        std::cout << "Saved File" << std::endl;
        myFile.close();
    }
    
   return 1;
}

void Filehandler::filenameAdd() {
    filename = filename.append(".uf");
    std::cout << "Changed filename to " << filename << std::endl;
    return;
}

void Filehandler::filenameSubtract() {
    std::string ending = filename.substr(filename.length()-3, std::string::npos);
    if (ending.compare(".uf")!= 0) {
        std::cerr << "The filename doesn't end with .uf" <<std::endl;
        exit(1);
    } else {
        filename = filename.substr(0, filename.size() - 3);
        std::cout << "Changed filename to " << filename <<std::endl;
    }
    return;
}

