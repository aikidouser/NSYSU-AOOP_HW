#include "mytar.h"

// #include <fstream>
// #include <iostream>

// using namespace std;

bool extCheck(string filename);

int main(int argc, char** argv) {
    ifstream is(argv[1], ifstream::in | ifstream::binary);
    string filename = argv[1];

    if (extCheck(filename))
        TarHandler tar_file(is);

    is.close();

    return 0;
}

bool extCheck(string filename) {
    if (filename.find(".tar") == string::npos) {
        cout << "mytar: " << filename << ": Cannot open: No such file or directory" << endl;
        cout << "mytar: Error is not recoverable: exiting now" << endl;

        return false;
    }
    return true;
}