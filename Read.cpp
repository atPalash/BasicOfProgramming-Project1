#include "Read.h"
#include "Splitter.h"

#include <string>
#include<fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

Read::Read()
{
    string line;
    ifstream myfile(fileName_);
    if(myfile.is_open()){
        vector<string> tempData;
        while(getline(myfile,line)){
            Splitter lineToSplit(line);
            tempData = lineToSplit.splitString(';',true);
            productsData_.push_back(tempData);
        }
    }
}

vector<vector<string>> Read::getProductsData(){
    return productsData_;
}

void Read::makeChainProductsMap(vector<vector<string>> productsData){
    multimap<string, string> productCost;
    multimap<string, multimap<string,string>> locationProductCost;

    for (int i = 0; i < productsData.size(); i++)
    {
        for(int j=0; j <productsData[i].size(); j=j+4){
        string Cost = productsData[i][3];
        string Name = productsData[i][2];
        string Location = productsData[i][1];
        string Chain = productsData[i][0];
        //cout << Chain << ";" << Location << ";" << Name << ";" << Cost << endl;
        productCost.insert(make_pair(Name,Cost));
        locationProductCost.insert(make_pair(Location, productCost));
        chainProductsMap_.insert(make_pair(Chain, locationProductCost));

        productCost.clear();
        locationProductCost.clear();}
    }
}

multimap<string, multimap<string,multimap<string,string>>> Read::getChainProductsMap(){
    return chainProductsMap_;
}

void Read::print(){
    for(int i = 0; i < productsData_.size(); i++){
        for(int j = 0; j < productsData_.at(i).size(); j++){
            cout << productsData_[i][j] << " " ;
        }
        cout <<endl;
    }

}


