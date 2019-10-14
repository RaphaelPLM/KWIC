#include "parser.h"
#include "processor.h"
#include "circularShifter.hpp"
#include "ext_Alphabetizer.hpp"
#include "ext_ReverseAlphabetizer.hpp"
#include "output.hpp"

int main()
{
    // Creates a module that handles stop words extraction by reading a .txt file
    ParserModule<InputTXT> stop_words("stopWords");
    
    // Creates a module that handles titles extraction by reading a file
    ParserModule<BibliographyManager<InputTXT>> bib("bibliography");

    // Gets the output from the ParserModule objects stop_words and bib
    list<string> list_stop_words = stop_words.getListWords();

    // Creates a list of all titles, separated by its words
    list<list<string>> list_titles_words = bib.getListTitlesWords();

    // Instantiates the main processor. Here, the words are numbered, in such a way that the shifter can correctly generate all valid permutations 
    WordProcessor main_processor(list_titles_words, list_stop_words);

    // Get pairs of indexed keywords
    list<list<pair<string, int>>> indexed_keywords = main_processor.getProcessedTitles();

    // Instantiates a circular shifter that will handle pre-processed words and generate valid permutations
    CircularShifter<ReverseAlphabetizer> shifterModule(indexed_keywords, list_titles_words);

    OutputModule outputHandler(shifterModule.getTitles(),bib.getListWords());

    outputHandler.generateOutput();

    return 0;
}