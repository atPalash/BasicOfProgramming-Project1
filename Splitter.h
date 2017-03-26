#ifndef SPLITTER_H
#define SPLITTER_H

#include <vector>
#include <string>

using namespace std;

class Splitter
{
    public:
        Splitter(string line);
        vector<string> splitString(char separator, bool ignore_empty);
    private:
        string str_;
};

#endif // SPLITTER_H
