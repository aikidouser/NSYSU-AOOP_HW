#include "mytar.h"

#include <math.h>
#include <string.h>
#include <time.h>

#include <map>

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

        cur_fsize = OctToDec(tar_header.filesize);
        cur_fbnum = cur_fsize / BLOCK_SIZE;

        if (cur_fsize % BLOCK_SIZE)
            ++cur_fbnum;

        i += 1 + cur_fbnum;
        if (cur_fbnum)
            is.seekg(cur_fbnum * BLOCK_SIZE, ios::cur);

        if (strlen(tar_header.filename) != 0) {
            cout << getftype(tar_header.type) << getfmode(tar_header.filemode) << " "
                 << tar_header.username << "/" << tar_header.groupname << " "
                 << right << setfill(' ') << setw(7) << cur_fsize << " ";
            print_time(tar_header.mtime);
            cout << " " << tar_header.filename << endl;
        }
    }
}

TarHandler::~TarHandler() {}

long long TarHandler::OctToDec(char* c) {
    int i = 0;
    long long dec = 0, oct = 0;

    oct = atoll(c);
    while (oct) {
        dec += (oct % 10) * pow(8, i);
        oct /= 10;
        i++;
    }
    return dec;
}

char TarHandler::getftype(char c) {
    map<char, char> type_table;

    type_table['0'] = '-';
    type_table['1'] = 'l';
    type_table['2'] = 'l';
    type_table['3'] = 'c';
    type_table['4'] = 'b';
    type_table['5'] = 'd';
    type_table['6'] = 'f';

    return type_table[c];
}

string TarHandler::getfmode(char* c) {
    map<char, string> mode_table;
    string mode_msg = "";

    mode_table['0'] = "---";
    mode_table['1'] = "--x";
    mode_table['2'] = "-w-";
    mode_table['3'] = "-wx";
    mode_table['4'] = "r--";
    mode_table['5'] = "r-x";
    mode_table['6'] = "rw-";
    mode_table['7'] = "rwx";

    for (size_t i = 4; i < strlen(c); i++) {
        mode_msg.append(mode_table[c[i]]);
    }

    return mode_msg;
}

void TarHandler::print_time(char* c) {
    string time_msg = "";
    struct tm* timeinfo;
    time_t unix_time = OctToDec(c) + 28800;

    timeinfo = gmtime(&unix_time);

    cout << 1900 + timeinfo->tm_year << "-"
         << setfill('0') << setw(2) << timeinfo->tm_mon << "-"
         << setfill('0') << setw(2) << timeinfo->tm_mday << " "
         << setfill('0') << setw(2) << timeinfo->tm_hour << ":"
         << setfill('0') << setw(2) << timeinfo->tm_min;
}