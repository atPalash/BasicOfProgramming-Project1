#ifndef READ_H
#define READ_H

#include "Splitter.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Read
{
    public:
        Read();
        string setFileName(string fileName);
        vector<vector<string>> getProductsData();
        void makeChainProductsMap(vector<vector<string>> productsData);
        multimap<string, multimap<string,multimap<string,string>>> getChainProductsMap();
        void print();
    private:
        string fileName_="products.txt";
        vector<vector<string>> productsData_;
        multimap<string, multimap<string,multimap<string,string>>> chainProductsMap_;
};

#endif // READ_H
