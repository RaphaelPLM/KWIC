#include "processor.hpp"

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
            cout << word.first << " ";
        }
        cout << endl;
    }
}

list<list<pair<string, int>>> WordProcessor::getProcessedTitles()
{
    return processed_titles;
}

// This function adds an index to each word, in the form pair<string, int>. This is essential to order words correctly when performing the circular shifts.
list<list<pair<string, int>>> WordProcessor::enumerateWords()
{
    list<list<pair<string, int>>> indexed_titles_words;

    for (auto title : titles)
    {
        int idx = 0;
        list<pair<string, int>> aux_list;

        for (auto word : title)
        {
            pair<string, int> word_idx = make_pair(word, idx);
            aux_list.push_back(word_idx);

            idx++;
        }

        indexed_titles_words.push_back(aux_list);
    }

    return indexed_titles_words;
}

list<list<pair<string, int>>> WordProcessor::filterStopWords()
{   
    list<list<pair<string, int>>> aux_list = enumerateWords();
    list<list<pair<string, int>>> filtered_titles;
    
    for(auto title : aux_list)
    {
        list<pair<string, int>> aux_title = title;
        
        for (list<pair<string, int>>::iterator i = aux_title.begin(); i != aux_title.end(); i++)
        {
            pair<string,int> word = *i;
            
            for (auto stop_word : stop_words)
            {
                for (int i = 0; i < word.first.length(); i++)
                {
                    word.first[i] = tolower(word.first[i]); 
                }

                for (int i = 0; i < stop_word.length(); i++)
                {
                    stop_word[i] = tolower(stop_word[i]); 
                }

                if(word.first == stop_word)
                {
                    aux_title.erase(i);
                    i--;
                }
            }
        }
    
        
        list<pair<string, int>> filtered_title = aux_title;
        filtered_titles.push_back(filtered_title);
    }
    
    return filtered_titles;
}