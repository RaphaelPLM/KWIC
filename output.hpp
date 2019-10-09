#include <bits/stdc++.h>

using namespace std;


class OutputModule
{
    public:
        // Constructor
        OutputModule(list<list<string>> p);
    
    protected:
        list<list<string>> permutations;
    
        void generateOutput();
};