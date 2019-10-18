#ifndef CIRCULARSHIFTER_HPP
#define CIRCULARSHIFTER_HPP


#include <stdlib.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;


/*  
   The function of this class is to generate valid permutations of a title. We define valid permutations as permutations of a title that do not
start with a stop word and preserve the word order in a circular way.

    After the permutations are generated, a SortAlgorithm is applied to order those permutations, e.g. alphabetically.  
*/
template <typename SortAlgorithm>
class CircularShifter : public SortAlgorithm
{
    public: 
        
        // Default constructor
        CircularShifter(list<list<pair<string, int>>> processed_titles, list<list<string>> titles_words);
        void printShiftedTitles();
        void printOrderedShiftedTitles();
        list<list<string>> getTitles();
    
    protected:

        list<list<string>> list_kwic;
        list<list<string>> list_kwic_ordered;
        list<list<list<string>>> shifted_titles_words;

        // During the processing, titles are divided into individual words. This function reagroup this individual words into a single string.
        list<list<string>> groupWords();
        
        /*  This is where valid permutations of a title are generated. This function returns a list<list<list<string>>>.

            The structure of the returned list is the following:

                1. The first list (A) is where the individual words of a single permutation are stored.
                2. A title usually have multiple permutations. This means that we need multiple sublists of type (A) to store multiple permutations.
            Essentially, we group this sublists into a list of type (B), that contains all words of all permutations of a single title.
                3. Finally, we may have multiple titles in our bibliography file. This means that we need another list of type (C), which will store
            all words of all permutations of all titles.

            (A) -> list<string>
            (B) -> list<list<string>>
            (C) -> list<list<list<string>>>

            **OBS: This structure is created for processing purposes. Words will be then reagrouped into a single string, 
            making the code easier to read.
        */
        list<list<list<string>>> shiftTitles(list<list<pair<string, int>>> processed_titles_keywords, list<list<string>> titles_words);
};

#endif