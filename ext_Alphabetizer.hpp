#ifndef EXT_ALPHABETIZER_HPP
#define EXT_ALPHABETIZER_HPP


#include <stdlib.h>
#include <list>
#include <string>

using namespace std;

class Alphabetizer
{    
    protected:
        list<list<string>> sortTitles(list<list<string>> list);
};

#endif