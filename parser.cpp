/* 
    This module handles the inputs of KWIC.
*/
#include "parser.h"

using namespace std;

// Constructor - takes an input (file_name) and generate a list of words
template <typename InputFormat>
ParserModule<InputFormat>::ParserModule(string file_name)
{
    list_input = InputFormat::generateListWords(file_name);   
}


// Prints the elements of a list.
template <typename InputFormat>
list<string> ParserModule<InputFormat>::getListWords()
{
    return list_input;
}

template <typename InputFormat>
list<list<string>> BibliographyManager<InputFormat>::getListTitlesWords()
{
    return titles_words;
}

// Breaks a title into multiple words (including stop words)
template <typename InputFormat>
list<list<string>> BibliographyManager<InputFormat>::extractWords(list<string> titles)
{            
    list<list<string>> titles_words;
    
    for (auto i = titles.begin(); i != titles.end(); i++)
    {
        string title = *i;
        // Instantiates a whitespace regex 
        regex ws_re("\\s+");

        // Applies the regex into a title
        list<string> title_words{sregex_token_iterator(title.begin(), title.end(), ws_re, -1), {}};
        // Pushes the words of a title into the main list
        titles_words.push_back(title_words);
    }
    
    return titles_words;
}

/* 
    Set the list of words in a list of titles.
        *TODO: extractWords(titles) should initialize a list<list<string>> in instantiation time. Currently, it depends on the call of the function setListTitlesWords(...);
*/
template <typename InputFormat>
void BibliographyManager<InputFormat>::setListTitlesWords(list<string> titles)
{
    titles_words = extractWords(titles);
}

// Generate a list of titles (or single words, in case of stop words module)
list<string> InputTXT::generateListWords(string file_name)
{
    ifstream f_words;

    list<string> list_words;
    
    // Opens the file based on the file_name provided
    f_words.open(file_name + ".txt");
    
    if(!f_words)
        cout << "Unable to read file " << file_name << ".txt." << endl; 
    
    // This variable stores a line of the .txt file.
    string word;
    
    // While !EOF
    while(getline(f_words, word))
    {
        list_words.push_back(word);
    }
    
    // Orders the stop words list.
    list_words.sort();
    
    return list_words;   
}

// Instantiates all needed templates. This is needed to avoid undefined references during files linking.
template class BibliographyManager<InputTXT>;
template class ParserModule<BibliographyManager<InputTXT>>;
template class ParserModule<InputTXT>;

