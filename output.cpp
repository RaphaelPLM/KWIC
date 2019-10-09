#include "output.hpp"


OutputModule::OutputModule(list<list<string>> p)
{
    permutations = p;
    generateOutput();
}

void OutputModule::generateOutput()
{
    std::ofstream outfile;
    outfile.open("outputKWIC.txt");//std::ios_base::app
    
    for(auto titles_set : permutations)
    {
        for(auto title : titles_set)
        {
            outfile << title << endl;
        }
        outfile << endl;
    }
}