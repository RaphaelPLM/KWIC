#include "parser.h"
#include "processor.h"

using namespace std;

WordProcessor::WordProcessor(list<list<string>> p_titles, list<string> p_stop_words)
{
    titles = p_titles;
    stop_words = p_stop_words;
    processed_titles = filterStopWords();
}
void WordProcessor::printProcessedTitles()
{
    for(auto title : processed_titles)
    {            
        for(auto word : title)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}

list<list<string>> WordProcessor::filterStopWords()
{   
    list<list<string>> aux_list = titles;
    list<list<string>> filtered_titles;
    for(auto title : aux_list)
    {
        
        for(auto word: stop_words)
        {
            title.remove(word);
        }
        
        list<string> filtered_title = title;
        filtered_titles.push_back(filtered_title);
    }
    
    return filtered_titles;
}


int main()
{
    // Creates a module that handles stop words extraction
    ParserModule<InputTXT> stop_words("stopWords");
    
    // Creates a module that handles titles extraction
    ParserModule<BibliographyManager<InputTXT>> bib("bibliography");

    // This method breaks a title into a list of words. This is required for the stop words removal.
    bib.setListTitlesWords(bib.getListWords());

    // Gets the output from the ParserModule objects stop_words and bib
    list<string> list_stop_words = stop_words.getListWords();

    list<list<string>> list_titles_words = bib.getListTitlesWords();

    WordProcessor main_processor(list_titles_words, list_stop_words);

    main_processor.printProcessedTitles();

    return 0;
}
