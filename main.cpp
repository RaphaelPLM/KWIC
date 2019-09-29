#include "parser.h"
#include "processor.h"
#include "circularShifter.hpp"

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

    // Creates a list of all titles, separated by w
    list<list<string>> list_titles_words = bib.getListTitlesWords();

    WordProcessor main_processor(list_titles_words, list_stop_words);

    list<list<pair<string, int>>> indexed_keywords = main_processor.getProcessedTitles();

    CircularShifter shifterModule(indexed_keywords, list_titles_words);

    shifterModule.printShiftedTitles();

    return 0;
}