#include "ext_Alphabetizer.hpp"

list<list<string>> Alphabetizer::sortTitles(list<list<string>> i_list)
{
    list<list<string>> ordered_list;
    
    for (auto i = i_list.begin(); i != i_list.end(); i++)
    {
        list<string> sublist = *i;

        sublist.sort();

        ordered_list.push_back(sublist);

    }
    
    return ordered_list;
}