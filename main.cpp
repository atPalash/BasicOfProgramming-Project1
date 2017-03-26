#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "Read.h"
#include "Splitter.h"
#include "UserInterface.h"

using namespace std;

int main () {
    Read inputFile;
    vector<vector<string>> productsDataVec = inputFile.getProductsData();
    inputFile.makeChainProductsMap(productsDataVec);
    multimap<string, multimap<string,multimap<string,string>>> chainLocationProductCostMap = inputFile.getChainProductsMap();

    while(cin){
        cout << "product search> " ;
        string query = " ";
        getline(cin,query);
        if(query=="quit"){
            break;
        }else{
            UserInterface userQuery(query);
            userQuery.response(chainLocationProductCostMap);
        }
    }


return 0;
}
