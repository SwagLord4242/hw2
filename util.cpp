#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;

std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> keyWords;
    int start = 0;

    for(unsigned int i = 0; i < rawWords.size(); i++)
    {
        if(rawWords[i] < 'A' || rawWords[i] > 'z') //Check if not in A-z
        {
            //cout << "i=" << i << "(" << rawWords[i] << ")" << endl;
            //cout << "Start: " << start << endl;
            //cout << "End: " << i << endl;
            if(i - start >= 2)
            {
                keyWords.insert(rawWords.substr(start, i - start));
                //cout << i << " (" << rawWords.substr(start, i - start) << ")" << endl;
            }
            start = i + 1;
            //cout << "Start of next: " << rawWords[start] << endl;
            //cout << endl;
        }

        if(i == rawWords.size() - 1 && i - start >= 2)
        {
            keyWords.insert(rawWords.substr(start));
            //cout << "Last: (" << rawWords.substr(start) << ")" << endl;
        }

    }

    return keyWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
