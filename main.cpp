#include <iostream>
#include <string>
#include <cstring>
#include "realize.h"
#include "base_sqlite.h"
using namespace std;

class BdSorts{
private:
	void openBD(const char* nameBd){                 openBd(nameBd);
         };

};

class Requests{
    public :
        void Creates(){
            request_insert_create("CREATE TABLE IF NOT EXISTS sorts(id integer primary key autoincrement, nameSort varchar(32));");
            request_insert_create("CREATE TABLE IF NOT EXISTS  sizears(id integer primary key autoincrement,sizeAr varchar(32));");
            request_insert_create("CREATE TABLE IF NOT EXISTS  ressorts(id integer primary key autoincrement, dursurtMS integer, idSort integer, idsizeAr integer, FOREIGN KEY(idSort) REFERENCES sorts(id), FOREIGN KEY(idsizeAr) REFERENCES sizears(id));");
        }

        void openBD(const char* nameBd){
		openBd(nameBd);
	};

        void insertIntoSorts(int size);
        int getIdFromSortsBySize(int size);
        int getLastRowId();
    public:
        Requests(){openBd("test");};
        Requests(const char* nameBd){
            openBd(nameBd);
        }

        ~Requests(){closeBd();};

        int addSize(int size);

        void Inserts(int size){
            string InsertSizeArs = "INSERT INTO sizears(`sizeAr`) VALUES("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+"),("+to_string(size)+");";
            string InsertTime = "INSERT INTO ressorts(`dursurtMS`,`idSort`,`idsizeAr`) VALUES("+to_string(BubbleSortTime(size))+",1,1),("+to_string(SelectionSortTime(size))+",2,2),("+to_string(InsertionSortTime(size))+",3,3), ("+to_string(CountingSortTime(size))+",4,4),("+to_string(MergeSortTime(size))+",5,5);";

            request_insert_create(InsertSizeArs.c_str());
            request_insert_create("INSERT INTO Sorts(`nameSort`) VALUES('BubbleSort'),('SelectionSort'),('InsertionSort'),('CountingSort'),('MergeSort');");
            request_insert_create(InsertTime.c_str());
        }

        void Select(){
            request_select("SELECT `sorts`.`nameSort`, `sizears`.`sizeAr`, `ressorts`.`dursurtMS` FROM `ressorts` INNER JOIN `sorts` ON `ressorts`.`idSort` = `Sorts`.`id` INNER JOIN `sizears` ON `ressorts`.`idsizeAr` = `SizeArs`.`id`");
        }
};
#define MEAS    1
#define LIST    2

class Keys {
    private:
        int meas;
        int size;
        int step;

    public:
        int getSize(){return size;}
        int getStep(){return step;}
        int getMeas(){return meas;}

        Keys(int argc, const char* argv[]){
            size = 1000;
            step = size;
            meas = 0;
            for (int i = 1; i < argc; i++){
                if (!strcmp(argv[i], "--meas")) {
                    meas = MEAS;
                }
                else if (!strcmp(argv[i], "--size"))
                    size = atoi(argv[++i]);
                else if (!strcmp(argv[i], "--step"))
                    step = atoi(argv[++i]);
            }
        }
};

int main(int argc, const char* argv[]){
    openBd("test.bd\0");
    Requests test();
    Keys keys(argc, argv);
    test.Creates();
    if (keys.getMeas() == MEAS){
        int size =keys.getSize();
        int step =keys.getStep();
        int arr[size / step];

        for (int i = step; i <= size; i += step){

        }
        test.Select();
    }
    else if (keys.getMeas() == LIST) {

    }
    return 0;
}
