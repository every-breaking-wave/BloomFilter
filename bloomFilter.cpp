//
// Created by 16541 on 2022/3/6.
//
#include <iostream>
#include "bloomFilter.h"
using namespace std;

bloomFilter::bloomFilter(int size) {
    this->size = size;
    for(int i = 0; i < INPUT_SIZE ; i++){
        this->bloomtable.push_back(false);
    }
}

int  bloomFilter::hash(int key){
    return key % size;
}

void bloomFilter::insert(int key){
    int start_id = hash(key);
    for(int i = start_id; i < start_id + num_of_hash; i++){
        this->bloomtable[i % size] = true;
    }
    insertTable.push_back(key);
}

void bloomFilter::multiInsert(int begin, int end) {
    for(int i = begin; i < end; i++){
        insert(i);
    }
}

bool bloomFilter::isFalseJudge(int key){
//     return (judge(key) && !isInserted(key));
    return (judge(key));
}

double bloomFilter::rate_FalseJudge(int begin, int end){
    int falseNum = 0;
    for(int i = begin; i < end; i++){
        if(isFalseJudge(i)) {
            falseNum++;
        }
    }

    return (double) falseNum/(double)(end - begin + 1);
}

bool bloomFilter::judge(int key){
    int start_id = hash(key);
    for(int i = start_id; i < start_id + num_of_hash; i++){
        if(!bloomtable[i % size])   //  只要有一个hash位置不在，就一定没有
            return false;
    }
    return true;
}

bool bloomFilter::isInserted(int key) {
    for(int i = 0; i < insertTable.size(); i++){
        if(insertTable[i] == key){
            return true;
        }
    }
    return false;
}

void bloomFilter:: setNum(int num){
    this->num_of_hash = num;
}

void bloomFilter::clear() {
    this->bloomtable.clear();
    for(int i = 0; i < INPUT_SIZE ; i++){
        this->bloomtable.push_back(false);
    }
}