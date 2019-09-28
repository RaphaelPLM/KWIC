#include<bits/stdc++.h>
using namespace std;

class WordProcessor
{
    public:
        WordProcessor(list<list<string>> p_titles, list<string> p_stop_words);
        
        void printProcessedTitles();

        list<list<pair<string, int>>> getProcessedTitles();
    protected:
        list<list<string>> titles;
        list<string> stop_words;
        
        //Titles without stop words
        list<list<pair<string, int>>> processed_titles;

        list<list<pair<string, int>>> filterStopWords();

        // Stores a list containing all circular shifts of a word (desconsidering stop words)
        list<list<string>> list_circular_shifts;

        list<list<pair<string, int>>> enumerateWords();
};