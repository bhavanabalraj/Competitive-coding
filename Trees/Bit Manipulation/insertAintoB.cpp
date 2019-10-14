//
// Created by cegbh on 10/13/2019.
//
#include<iostream>
#include<bitset>

using namespace std;

void insertAintoB(const string &b1, const string &b2, int i, int j){
    std::bitset<32> bit1(b1);
    std::bitset<32> bit2(b2);
    bit1 = bit1 | (bit2 << i);
    cout << bit1 << endl;
}

void decimal(double d){
    std::bitset<32> bit3(d);
    cout << bit3;
}

void pairSwap(int b1){
    std::bitset<32> bit1(b1);
    std::bitset<32> bit2(b1);
    bit1 = ((bit1 >> 1) | (bit2 << 1));
    cout << bit1 << endl;
    cout << ((b1 >> 1) | (b1 << 1));
}

int main() {
    std::bitset<32> b1("10000000000");
    std::bitset<32> b2("10011");
    cout << b1 << " " << b2 << endl;
    insertAintoB("10000000000", "10011", 2, 6);
    //decimal(0.72);
    pairSwap(10);
}

