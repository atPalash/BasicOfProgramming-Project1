#include "Splitter.h"

#include <vector>
#include <string>

using namespace std;

Splitter::Splitter(string line)
{
    str_ = line;
}

vector<string> Splitter::splitString(char separator, bool ignore_empty){
    vector<string> vStr;
    string::size_type startPos=0;
    string::size_type pos = str_.find(separator, startPos);
    string temp="";
    while(pos!=string::npos){
        temp = str_.substr(startPos,pos-startPos);
        if((temp==""&&ignore_empty==false)||(temp!="")){
            vStr.push_back(temp);
        }
        startPos = pos+1;
        pos=str_.find(separator, startPos);
    }
    vStr.push_back(str_.substr(startPos));
    return vStr;
}
