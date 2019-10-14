#include <bits/stdc++.h>

using namespace std;


class OutputModule
{
    public:
        // Constructor
        OutputModule(list<list<string>> p, list<string> titles);
        void generateOutput();
    
    protected:
        list<list<string>> permutations;
        list<string> original_titles;
};