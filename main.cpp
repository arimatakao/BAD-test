// Compiler parameters: --std=c++17 -g -o program main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>
#include <cctype>

using namespace std;

char mostUniqFirstSymbol(string in)
{
    stringstream ss(in);
    string word;
    // First symbol, Counter, Place in text
    map<char, pair<int, int>> firstChar; 
    // Place counter
    int place = 0; 

    // extract words from string
    while(ss >> word)
    {
        // if char exist in map add increase char counter, else add new element in map
        if(auto it = firstChar.find(word[0]); it != firstChar.end())
        {
            int tmpCount = it->second.first;
            firstChar[word[0]] = make_pair(++tmpCount, place);
        }
        else
        {
            ++place;
            firstChar.emplace(make_pair(word[0], make_pair(1, place)));
        }
    }
    
    // Element of map
    auto checkVal = make_pair(firstChar.begin()->first, firstChar.begin()->second);
    
    // Find lowest value in Counter
    for (const auto& [k, v] : firstChar)
    {    
        if(checkVal.second.first > v.first)
        {
            checkVal = make_pair(k, v);
            if(checkVal.second.first == 1)
                break;
        }
    }

    // Find least value in place
    for (const auto& [k, v] : firstChar)
        if(checkVal.second.first == v.first && checkVal.second.second > v.second) 
            checkVal = make_pair(k, v);

    return checkVal.first;
}

int main()
{
    string input;
    
    getline(cin, input);

    if(input.empty())
    {
        cout << "Error: empty input" << endl;
        return 1;
    }    
    
    cout << endl <<  mostUniqFirstSymbol(input) << endl;
    
    return 0;
}