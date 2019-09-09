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
    std::ifstream ifile(filename.c_str()); //Problem exists here!!!
    std::cout << "conditional";
    if ((bool) ifile) {
        std::cout << "\nFile already exists\n";
        exit(33);
    } else {
        std::cout << "\nCreating File\n";
        std::ofstream myFile(filename.c_str());
        myFile.close();
    }
    
   return "nothing";
}

void Filehandler::filenameAdd() {
    return;
}

void Filehandler::filenameSubtract() {
    return;
}

