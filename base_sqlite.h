#ifndef USEPROFILER_BASE_SQLITE_H
#define USEPROFILER_BASE_SQLITE_H

#include <iostream>
#include <string>
#include <assert.h>

#include "sqlite3.h"

bool openBd(const char* bdName);
bool closeBd();
bool request_insert_create(const char* sqlString);
int getLastRowId();
bool request_select(const char* sqlSting);


#endif //USEPROFILER_BASE_SQLITE_H
