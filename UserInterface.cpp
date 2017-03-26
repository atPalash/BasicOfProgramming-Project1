#include "UserInterface.h"
#include "Splitter.h"

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

UserInterface::UserInterface(string query)
{
    query_ = query;
    Splitter queryString(query);
    queryData_ = queryString.splitString(' ', true);
}

void UserInterface::response(multimap<string, multimap<string,multimap<string,string>>> chainLocationProductCostMap){
    if(queryData_[0]=="chains"){
        set<string> Chains;
        for(auto iter=chainLocationProductCostMap.begin(); iter!=chainLocationProductCostMap.end();++iter){
            Chains.insert(iter->first);
        }
        for(auto iter = Chains.begin(); iter!=Chains.end(); ++iter){
            cout << *iter << endl;
        }
    }
    else if(queryData_[0] == "stores"){
            pair <multimap<string, multimap<string,multimap<string,string>>>::iterator, multimap<string, multimap<string,multimap<string,string>>>::iterator> retLocation;
            retLocation = chainLocationProductCostMap.equal_range(queryData_[1]);
            set<string> storeLocation;
            for (auto j = retLocation.first; j != retLocation.second; ++j){
                auto b = j->second;
                for (auto k = b.begin(); k != b.end(); ++k){
                        string loc = k->first;
                        set<string>::iterator iter = storeLocation.find(loc);
                        if(iter==storeLocation.end()){
                        storeLocation.insert(loc);
                        }
                    }
            }
            for(auto i= storeLocation.begin();i!=storeLocation.end();++i){
                cout << *i << endl;
            }
        }
    else if(queryData_[0] == "cheapest"){
        if((queryData_[1]=="milk")||(queryData_[1]=="peanut_butter")){
        double cheapest = 100.0;
        string cheapestChain = "";
        string cheapestLocation = "";
        for( auto j = chainLocationProductCostMap.begin(); j!=chainLocationProductCostMap.end(); ++j){
            multimap<string, multimap<string,string>> locationProductCostTemp = j->second;
            string queryChain = j->first;
            for(auto k = locationProductCostTemp.begin(); k!=locationProductCostTemp.end();++k){
                string queryLocation = k->first;
                multimap<string,string> productCostTemp = k->second;
                for(auto l = productCostTemp.begin(); l!=productCostTemp.end();++l){
                string queryProduct = l->first;
                string queryCost = l->second;
                double tempqueryCost = atof(queryCost.c_str());

                if((queryProduct==queryData_[1])&&(tempqueryCost<cheapest)){
                    cheapest = tempqueryCost;
                    cheapestChain = queryChain;
                    cheapestLocation = queryLocation;
                    }
                }
                productCostTemp.clear();
            }
            locationProductCostTemp.clear();
        }
        cout << cheapest << endl;
        cout << cheapestChain << " " << cheapestLocation << endl;
        }else{
            cout <<"This product is not available anywhere." << endl;
    }}
    else if(queryData_[0] == "selection"){
        string chain = queryData_[1];
        string location = queryData_[2];
        pair <multimap<string, multimap<string,multimap<string,string>>>::iterator, multimap<string, multimap<string,multimap<string,string>>>::iterator> retLocation;
        retLocation = chainLocationProductCostMap.equal_range(chain);
        for (auto j = retLocation.first; j != retLocation.second; ++j){
            multimap<string, multimap<string,string>> locationProductCostTemp = j->second;
            for (auto k = locationProductCostTemp.begin(); k != locationProductCostTemp.end(); ++k){
                    if(k->first==location){
                    multimap<string,string> productCostTemp;
                    productCostTemp = k->second;
                    for (auto l = productCostTemp.begin(); l != productCostTemp.end(); ++l){
                        cout << l->first << ' ' << l->second << endl;
                    }}
                }
        }
    }
    else{
        cout << "Not valid query" << endl;
    }
}
