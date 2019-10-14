#include "output.hpp"

OutputModule::OutputModule(list<list<string>> p, list<string> titles)
{
    permutations = p;
    original_titles = titles;
}

void OutputModule::generateOutput()
{
    std::ofstream outfile;
    outfile.open("outputKWIC2.txt");//std::ios_base::app
    
    outfile << "Bibliography:" << endl << endl;

    for(auto title : original_titles)
    {
        outfile << title << endl;
    }

    outfile << endl << "-----------------------------------------" << endl;

    outfile << endl << "Keywords in Context:" << endl << endl;

    for(auto titles_set : permutations)
    {   
        for(auto title : titles_set)
        {
            outfile << title << endl;
        }

        outfile << endl;
    }
}