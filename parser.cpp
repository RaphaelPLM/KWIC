/* 
    This module handles the inputs of KWIC.
*/
#include "parser.hpp"

using namespace std;

// Constructor - takes an input (file_name) and generate a list of words
template <typename InputFormat>
ParserModule<InputFormat>::ParserModule(string file_name)
{
    file_name = file_name;
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
void BibliographyManager<InputFormat>::initializeListTitlesWords(list<string> titles)
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

    if (!f_words)
        cout << "Unable to read file " << file_name << ".txt." << endl;

    // This variable stores a line of the .txt file.
    string word;

    // While !EOF
    while (getline(f_words, word))
    {
        list_words.push_back(word);
    }

    // Orders the stop words list.
    list_words.sort();

    return list_words;
}

// Generate a list of titles (or single words, in case of stop words module)
list<string> InputXML::generateListWords(string file_name)
{
    ifstream f_words;

    list<string> list_words;

    // Opens the file based on the provided file_name
    f_words.open(file_name + ".xml");

    if (!f_words)
        cout << "Unable to read file " << file_name << ".xml." << endl;

    // This variable stores a line of the .txt file.
    string word;

    string title_opening_tag;
    string title_closing_tag;

    // First, the file pointer is advanced line by line, until one of the tags below is found.
    while(getline(f_words, word))
    {
        if(word.find("<Bibliography>") != string::npos)
        {   
            title_opening_tag = "<Title>";
            title_closing_tag = "</Title>";
            break;
        }
        else if(word.find("<StopWords>") != string::npos)
        {
            title_opening_tag = "<Word>";
            title_closing_tag = "</Word>";
            break;
        }
    }

    // While !EOF
    while (getline(f_words, word))
    {   
        size_t opening_tag_pos = word.find(title_opening_tag);
        size_t closing_tag_pos = word.find(title_closing_tag);
        string filtered_word;
        
        // If the line start with a title tag, remove the opening and closing tags and push the title to a list
        if (opening_tag_pos != string::npos and closing_tag_pos != string::npos)
        {
            filtered_word = word.substr(0, closing_tag_pos);
            filtered_word.erase(0, opening_tag_pos + title_opening_tag.length());
            list_words.push_back(filtered_word);
        }
    }

    // Orders the words list.
    list_words.sort();

    return list_words;
}

// Instantiates all needed templates. This is needed to avoid undefined references during files linking.
template class BibliographyManager<InputTXT>;
template class BibliographyManager<InputXML>;
template class ParserModule<BibliographyManager<InputTXT>>;
template class ParserModule<BibliographyManager<InputXML>>;
template class ParserModule<InputTXT>;
template class ParserModule<InputXML>;
