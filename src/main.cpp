#include <iostream>
#include <stdio.h>

#include "filehandler.h"
#include "crypt.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "generating filehandler";
    Filehandler myFile("hooray");
    cout << "entering write";
    myFile.write();
    std::cout << "Wrote File once.";
    myFile.write();
    std::cout << "Should've failed, but didn't";
    std::cout<<"I think we managed to do it";
    return 0;
} // main
