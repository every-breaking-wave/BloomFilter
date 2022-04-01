#include <iostream>
#include "bloomFilter.h"
using namespace std;


int main() {
    int size = 300;
    int num_of_hash = 1;
    vector<bloomFilter *> bloomTables;
    // 创建 4 * 5个各不相同的对象
    for(int i = 2; i < 6; i++){  // i represents m/n
        for(int k = 1; k < 6; k++){   // k represents num_of_hash
            bloomFilter *filter = new bloomFilter(i * 1000);
            filter->setNum(k);
            bloomTables.push_back(filter);
        }
    }


    for(int i = 0; i < 20; i++){
        double rate = 0;
        for(int j = 0; j < 100; j++){
            bloomTables[i]->clear();
            bloomTables[i]->multiInsert(0,999);
            rate+= bloomTables[i]->rate_FalseJudge(1000,1999);
        }
        rate = (double ) rate / 100;
        cout<<"m = "<<bloomTables[i]->getSize()<<" n = "<<INPUT_SIZE<<" k = "<<bloomTables[i]->getNumOfHash()
            <<endl<<" rate of false judge is :" <<rate<<endl;
    }

    for(int i = 0; i < 20; i++){
        delete bloomTables[i];
    }

    return 0;
}
