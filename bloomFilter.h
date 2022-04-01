//
// Created by 16541 on 2022/3/6.
//

#ifndef BLOOMFILTER_BLOOMFILTER_H
#define BLOOMFILTER_BLOOMFILTER_H
#include <vector>
#define  INPUT_SIZE 1000


class bloomFilter {
public:
    bloomFilter(int size);
    int hash(int key);
    void insert(int key);
    void multiInsert(int begin, int end);
    bool isFalseJudge(int key);
    double rate_FalseJudge(int begin, int end);
    bool judge(int key);  //
    bool isInserted(int key);
    void setNum(int num);
    int getSize()const {return size;}
    int getNumOfHash() const {return num_of_hash;}
    void clear();

private:
    int size;
    int num_of_hash;
    std::vector<bool> bloomtable;
    std::vector<int> insertTable;


};

#endif //BLOOMFILTER_BLOOMFILTER_H
