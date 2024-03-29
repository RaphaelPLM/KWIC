#include "circularShifter.hpp"
#include "ext_Alphabetizer.hpp"
#include "ext_ReverseAlphabetizer.hpp"

using namespace std;

template <typename SortAlgorithm>
CircularShifter<SortAlgorithm>::CircularShifter(list<list<pair<string, int>>> processed_titles, list<list<string>> titles_words)
{
    shifted_titles_words = shiftTitles(processed_titles, titles_words);
    list_kwic = groupWords();
}

template <typename SortAlgorithm>
void CircularShifter<SortAlgorithm>::printShiftedTitles()
{
    for(auto title : list_kwic)
    {
        for(auto permutation : title)
        {
            cout << permutation << endl;
        }
        cout << endl;
    }
}

template <typename SortAlgorithm>
void CircularShifter<SortAlgorithm>::printOrderedShiftedTitles()
{
    for(auto title : list_kwic_ordered)
    {
        for(auto permutation : title)
        {
            cout << permutation << endl;
        }
        cout << endl;
    }
}

// During the processing, titles are break into individual words. This function reagroup this individual words into a single string.
template <typename SortAlgorithm>
list<list<string>> CircularShifter<SortAlgorithm>::groupWords()
{
    list<list<string>> list_kwic;
    
    for(auto list_title_permutations : shifted_titles_words)
    {
        list<string> group_title_words;
        
        for(auto title_permutation : list_title_permutations)
        {
            int count = 0;
            string resultant_title;
            

            /*  Concatenates each word of a permutation into a resultant string. At the end of the loop,
                a single string that contains all words of a title is expected */
            for (auto word : title_permutation)
            {
                if(count < title_permutation.size() - 1)                        
                    resultant_title += word + " ";
                else
                    resultant_title += word;
                count++;
            }
            group_title_words.push_back(resultant_title);
        }
       
        list_kwic.push_back(group_title_words);
    }            

    list_kwic_ordered = SortAlgorithm::sortTitles(list_kwic);

    return list_kwic;
}

template <typename SortAlgorithm>
list<list<string>> CircularShifter<SortAlgorithm>::getTitles()
{
    return list_kwic_ordered;
}

template <typename SortAlgorithm>
list<list<list<string>>> CircularShifter<SortAlgorithm>::shiftTitles(list<list<pair<string, int>>> processed_titles_keywords, list<list<string>> titles_words)
{
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

// Instantiates all needed templates. This is needed to avoid undefined references during files linking.
template class CircularShifter<Alphabetizer>;
template class CircularShifter<ReverseAlphabetizer>;
