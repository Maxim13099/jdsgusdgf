#include "base_sqlite.h"
#include <iostream>
#include <string>
using namespace std;
static sqlite3 *bd; //handle of BD

bool openBd(const char* bdName) {
    int status = sqlite3_open(bdName, &bd);
    assert(status == SQLITE_OK);

    return status;
}

bool closeBd() {
    int status = sqlite3_close(bd);
    assert(status == SQLITE_OK);
    return status;
}

bool request_insert_create(const char* sqlString) {
    char* errMsg;
    int er = sqlite3_exec(bd, sqlString, nullptr, nullptr, &errMsg);
    if (er) {
        std::cerr << "error request " << sqlString << " : " << errMsg << std::endl;   //std::cout
    }

    return er;
}
int getLastRowId() {
    int last_id = sqlite3_last_insert_rowid(bd);
    return last_id;
}

int callback(void* outputStruct, int countRec, char** argv, char** colName) {
    //void* -- c-style
    //outputStructure allow to return back the data for processing....
    for (int i = 0; i < countRec; i++) {
        std::cout << "\t" << colName[i] << " '" << argv[i] << "'";
    }
    std::cout << std::endl;
    return 0;
}

bool request_select(const char* sqlString) {
    char* errMsg;
    int er = sqlite3_exec(bd, sqlString, callback, nullptr /*input arguments*/, &errMsg);

    if (er != SQLITE_OK) {
        std::cerr << "error request " << sqlString << " : " << errMsg << std::endl;
    }
    assert(er == SQLITE_OK);

    return er;
}
