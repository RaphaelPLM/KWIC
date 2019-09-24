#include<bits/stdc++.h>

using namespace std;

class WordProcessor
{
    public:
        WordProcessor(list<list<string>> p_titles, list<string> p_stop_words);
        
        void printProcessedTitles();

    protected:
        list<list<string>> titles;
        list<string> stop_words;

        list<list<string>> processed_titles;

        list<list<string>> filterStopWords();
};