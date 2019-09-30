#include<bits/stdc++.h>

using namespace std;

template <typename SortAlgorithm>
class CircularShifter : public SortAlgorithm
{
    public: 
        
        CircularShifter(list<list<pair<string, int>>> processed_titles, list<list<string>> titles_words);
        void printShiftedTitles();
        void printOrderedShiftedTitles();
    
    protected:

        list<list<string>> list_kwic;
        list<list<string>> list_kwic_ordered;
        list<list<list<string>>> shifted_titles_words;

        // During the processing, titles are break into individual words. This function reagroup this individual words into a single string.
        list<list<string>> groupWords();
        list<list<list<string>>> shiftTitles(list<list<pair<string, int>>> processed_titles_keywords, list<list<string>> titles_words);
};