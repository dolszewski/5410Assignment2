// file.h
// Header file for the file class. Handles reading and writing of files.

#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
class Filehandler {
    private:
      std::string filename;
    public:
      Filehandler(std::string filename1);
      std::string read();
      std::string write();
      void filenameAdd();
      void filenameSubtract();
}; //file

#endif
