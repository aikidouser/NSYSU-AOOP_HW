#ifndef __MYTAR_H__
#define __MYTAR_H__

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

struct TarHeader {
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];

    /* USTAR Section*/
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
};

class TarHandler {
   public:
    TarHandler(ifstream& is);
    ~TarHandler();
    void tar_print();

   private:
    enum {
        BLOCK_SIZE = 512
    };
    int OctToDec(char* c);
    char getftype(char c);
    string getfmode(char* c);
    string unixConvert(char* c);
};

#endif
