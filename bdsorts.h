#pragma once
#include <iostream>
#include "sqlite3.h"
class BDSorts{
public:
    void OpenBd(const char*);
    void CloseBd();
    void CreateTables();
    void Inserts(const char*);
    void Select(const char*, int (*callback) (void*, int, char**, char**));
public:
    Bdsorts();
    Bdsorts(const char*);
    ~Bdsorts();
    void CheckNoteTable()
    int getIdFromSortsBySize(int size);
    int getLastRowId();
};
#define BDSORTS_H
