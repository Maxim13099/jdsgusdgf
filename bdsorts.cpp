#include "bdsorts.h"


BDSorts::Bdsorts(){

}

void BDSorts::OpenBd(){
    int status = sqlite3_open(bdName, &bd);
    assert(status == SQLITE_OK);

    return status;
}

void BDSorts::CloseBd(){
    closeBd();
}

void BDSorts::CreateTables(){
    request_insert_create("CREATE TABLE IF NOT EXISTS sorts(id integer primary key autoincrement, nameSort varchar(32));");
    request_insert_create("CREATE TABLE IF NOT EXISTS  sizears(id integer primary key autoincrement,sizeAr varchar(32));");
    request_insert_create("CREATE TABLE IF NOT EXISTS  ressorts(id integer primary key autoincrement, `dursurtMS` varchar(32), idSort varchar(32) ,idsizeAr varchar(32),FOREIGN KEY(idSort) REFERENCES sorts(id), FOREIGN KEY(idsizeAr) REFERENCES sizears(id));");
        }
}

void BDSorts::Inserts(int size){
    string InsertSizeArs = "INSERT INTO sizears(`sizeAr`) VALUES("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+");";
    string InsertTime = "INSERT INTO ressorts(`dursurtMS`,`idSort`,`idsizeAr`) VALUES("+to_string(BubbleSortTime(size))+",1,1),("+to_string(SelectionSortTime(size))+",2,2),("+to_string(InsertionSortTime(size))+",3,3), ("+to_string(CountingSortTime(size))+",4,4),("+to_string(MergeSortTime(size))+",5,5);";

    request_insert_create(InsertSizeArs.c_str());
    request_insert_create("INSERT INTO Sorts(`nameSort`) VALUES('BubbleSort'),('SelectionSort'),('InsertionSort'),('CountingSort'),('MergeSort');");
    request_insert_create(InsertTime.c_str());
}

void BDSorts::Select(const char*, int (*callback) (void*, int, char**, char**)){
    request_select("SELECT `sorts`.`nameSort`, `sizears`.`sizeAr`, `ressorts`.`dursurtMS` FROM `ressorts` INNER JOIN `sorts` ON `ressorts`.`idSort` = `Sorts`.`id` INNER JOIN `sizears` ON `ressorts`.`idsizeAr` = `SizeArs`.`id`");
}
