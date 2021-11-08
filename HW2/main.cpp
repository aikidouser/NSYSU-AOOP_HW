#include "mytar.h"

int main(int argc, char** argv) {
    string filename = argv[1];

    TarHandler tar_handler(filename);

    return 0;
}
