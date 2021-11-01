#include "mytar.h"

#include <math.h>

TarHandler::TarHandler(ifstream& is) {
    struct TarHeader tar_header;

    is.seekg(0, ios::end);
    long long tar_fsize = is.tellg();
    is.seekg(0, ios::beg);
    int num_blocks = tar_fsize / BLOCK_SIZE;

    for (int i = 0; i < num_blocks;) {
        int cur_fbnum = 0, cur_fsize = 0;

        is.read(tar_header.filename, 100);
        is.read(tar_header.filemode, 8);
        is.read(tar_header.userid, 8);
        is.read(tar_header.groupid, 8);
        is.read(tar_header.filesize, 12);
        is.read(tar_header.mtime, 12);
        is.read(tar_header.checksum, 8);
        is.get(tar_header.type);
        is.read(tar_header.lname, 100);

        is.read(tar_header.USTAR_id, 6);
        is.read(tar_header.USTAR_ver, 2);
        is.read(tar_header.username, 32);
        is.read(tar_header.groupname, 32);
        is.read(tar_header.devmajor, 8);
        is.read(tar_header.devminor, 8);
        is.read(tar_header.prefix, 155);
        is.read(tar_header.pad, 12);

        cur_fsize = get_fsize(tar_header.filesize);
        cur_fbnum = cur_fsize / BLOCK_SIZE;

        if (cur_fsize % BLOCK_SIZE)
            ++cur_fbnum;

        i += 1 + cur_fbnum;
        if (cur_fbnum)
            is.seekg(cur_fbnum * BLOCK_SIZE, ios::cur);
    }
}

TarHandler::~TarHandler() {}

int TarHandler::get_fsize(char* c) {
    int i = 0, dec_fsize = 0, oct_fsize = 0;

    oct_fsize = atoi(c);
    while (oct_fsize) {
        dec_fsize += (oct_fsize % 10) * pow(8, i);
        oct_fsize /= 10;
        i++;
    }
    return dec_fsize;
}