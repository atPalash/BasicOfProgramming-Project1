#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Splitter.h"

#include<map>
#include <vector>
#include <string>
#include <set>

using namespace std;

class UserInterface
{
    public:
        UserInterface(string query);
        void response(multimap<string, multimap<string,multimap<string,string>>> chainLocationProductCostMap);
    private:
        string query_;
        vector<string> queryData_;
};

#endif // USERINTERFACE_H
