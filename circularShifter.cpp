#include "parser.h"
#include "processor.h"

using namespace std;

class CircularShifter {
        
    public: 
        
        CircularShifter(list<list<pair<string, int>>> processed_titles, list<list<string>> titles_words)
        {
            shifted_titles_words = shiftTitles(processed_titles, titles_words);
        }

        void printShiftedTitles()
        {
            for(auto list_title_permutations : shifted_titles_words)
            {
                for(auto title_permutation : list_title_permutations)
                {
                    int count = 0;
                    
                    for (auto word : title_permutation)
                    {
                        if(count < title_permutation.size() - 1)                        
                            cout << word << " ";
                        else
                            cout << word << endl;
                    
                        count++;
                    }

                    cout << endl;
                }
            }
        }

    protected:

        // TODO: Função que agrupa as palavras de um título em uma unica string title

        list<list<list<string>>> shifted_titles_words;

        list<list<list<string>>> shiftTitles(list<list<pair<string, int>>> processed_titles_keywords, list<list<string>> titles_words)
        {
            // TODO: Mudar nome
            list<list<list<string>>> shifted_titles_words;
            
            auto it = processed_titles_keywords.begin();

            for (auto list_words : titles_words)
            {
                list<list<string>> list_permutations;
                
                list<pair<string, int>> list_keywords = *it; 

                for(auto keyword : list_keywords)
                {
                    string word = keyword.first;
                    int index = keyword.second;

                    list<string> title_permutation = list_words;
                        
                    // Move the back element to the front of the list, until the first word is the desired keyword.
                    for (int i = title_permutation.size(); i > index; i--)
                    {
                        string last_word = title_permutation.back();
                        title_permutation.pop_back();
                        title_permutation.push_front(last_word);
                    }

                    list_permutations.push_back(title_permutation);
                }

                advance(it, 1);

                shifted_titles_words.push_back(list_permutations);
            }

            return shifted_titles_words;
        }
};

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

    //main_processor.printProcessedTitles();

    list<list<pair<string, int>>> indexed_keywords = main_processor.getProcessedTitles();

    // for (auto title : indexed_keywords)
    // {
    //     for (auto word : title)
    //     {
    //         cout << word.second << ". " << word.first << endl;
    //     }

    //     cout << endl;
    // }

    CircularShifter shifterModule(indexed_keywords, list_titles_words);

    shifterModule.printShiftedTitles();

    return 0;
}