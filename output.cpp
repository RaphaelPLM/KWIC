#include "output.hpp"

template <typename OutputFormat>
OutputModule<OutputFormat>::OutputModule(list<list<string>> p, list<string> titles)
{
    permutations = p;
    original_titles = titles;
}

template <typename OutputFormat>
void OutputModule<OutputFormat>::triggerGenerateOutput()
{
    OutputFormat::generateOutput(permutations, original_titles);
}

void OutputTXT::generateOutput(list<list<string>> permutations, list<string> original_titles)
{
    std::ofstream outfile;
    outfile.open("outputKWIC.txt");
    
    outfile << "Bibliography:" << endl << endl;

    // The first lines of the file consists of the original titles
    for(auto title : original_titles)
    {
        outfile << title << endl;
    }

    // Separator
    outfile << endl << "-----------------------------------------" << endl;

    outfile << endl << "Keywords in Context:" << endl << endl;

    // After the separator, the keywords in context of each title will be listed.
    for(auto titles_set : permutations)
    {   
        for(auto title : titles_set)
        {
            outfile << title << endl;
        }

        outfile << endl;
    }
}

