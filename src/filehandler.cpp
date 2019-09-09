#include "filehandler.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
Filehandler::Filehandler(std::string filename1) : filename(filename1) {}

std::string Filehandler::read() {
    return NULL;
}

std::string Filehandler::write() {
    //std::ifstream myFile; //Problem exists here!!!
    //myFile.open(filename);
    struct stat buffer;
    int existenceFlag = stat(filename.c_str(),&buffer);

    if (existenceFlag != 0) {
        std::cout << "Creating the file";
    } else {
        std::cout << "\nFile already exists\n";
        exit(33);
    }
   return NULL;
}

void Filehandler::filenameAdd() {
    return;
}

void Filehandler::filenameSubtract() {
    return;
}
