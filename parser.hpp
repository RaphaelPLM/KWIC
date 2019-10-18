#ifndef PARSER_HPP
#define PARSER_HPP

/* 
    This module handles the inputs of KWIC.
*/

#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <list>
#include <string>
#include <regex>

using namespace std;

/* 
    Defines a template for the input module. 
    ParserModule consists of a list of words (stopwords or titles), and includes a method to print this list.
    (*) This list can be achieved based on different input formats, such as .txt or .xml, based on the selected mixing class.
*/
template <typename InputFormat>
class ParserModule : public InputFormat
{
    protected:
        // List generated by the input (specified by class InputFormat)
        list<string> list_input;
    
    public:        
        // Constructor - takes an input (file_name) and generate a list of words
        ParserModule(string file_name);

        // Prints the elements of the list.
        list<string> getListWords();
};

class InputFormat
{
    protected:    
        virtual list<string> generateListWords(string file_name) = 0;
};

// Implements a mixing class that reads data from a .txt file.
class InputTXT : InputFormat
{   
    protected:    
        list<string> generateListWords(string file_name) override;
};

// Implements a mixing class that reads data from a .xml file.
class InputXML : InputFormat
{
    protected:
        list<string> generateListWords(string file_name) override;
};

/*
    A bibliography is essentially a parser module with an extra list, that consists of each title's words, separatedly.
    * extractWords() - This function implements a logic that breaks titles (a set of words) into individual words, that together compose a list.
*/
template <typename InputFormat>
class BibliographyManager : public InputFormat 
{     
    protected: 
        // Breaks a title into multiple words (including stop words)
        list<list<string>> extractWords(list<string> titles);

        void initializeListTitlesWords(list<string> titles);

        // Each unit of the list corresponds to another list of words. This sub-list consists of all the words of a title, excluding the stop words.
        list<list<string>> titles_words;

    public:
        BibliographyManager()
        {
            // First, generateListWords(string) creates a list of titles. Then, setListTitlesWords will then call ExtractWords function
            initializeListTitlesWords(InputFormat::generateListWords("bibliography"));
        }
        
        list<list<string>> getListTitlesWords();
};

#endif