#include <bits/stdc++.h>

using namespace std;

class Alphabetizer
{    
    protected:
        static bool compareFunction (string a, string b){return a < b;}
        list<list<string>> sortTitles(list<list<string>> list);
};