#include "ext_ReverseAlphabetizer.hpp"

list<list<string>> ReverseAlphabetizer::sortTitles(list<list<string>> i_list)
{
    list<list<string>> ordered_list;
    
    for (auto i = i_list.begin(); i != i_list.end(); i++)
    {
        list<string> sublist = *i;

        sublist.sort();

        ordered_list.push_back(sublist);

    }
    
    list<list<string>> reverse_ordered_list;

    for (auto list_titles : ordered_list)
    {
        list<string> reverse_ordered_sublist;
        
        for (auto i = list_titles.begin(); i != list_titles.end(); i++)
        {            
            // Pushing to the front of the list will create a reverse ordered collection
            reverse_ordered_sublist.push_front(*i);
        }

        reverse_ordered_list.push_back(reverse_ordered_sublist);
    }

    return reverse_ordered_list;
    
}