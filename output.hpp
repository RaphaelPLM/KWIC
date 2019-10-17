#include <bits/stdc++.h>

using namespace std;

template <typename OutputFormat>
class OutputModule : OutputFormat
{
    public:
        // Constructor
        OutputModule(list<list<string>> p, list<string> titles);
        void triggerGenerateOutput();
    
    protected:
        list<list<string>> permutations;
        list<string> original_titles;
};

class OutputFormat
{
    protected:    
        virtual void generateOutput(list<list<string>> permutations, list<string> titles) = 0;
};

class OutputTXT : OutputFormat
{   
    protected:    
        void generateOutput(list<list<string>> permutations, list<string> titles) override;
};

template class OutputModule<OutputTXT>;