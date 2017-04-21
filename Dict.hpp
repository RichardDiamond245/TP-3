#ifndef __DICT_HPP__
#define __DICT_HPP__

#include "Node.hpp"
#include <string>

class Dict
{
private:
    Node* m_root;

public:
    // Constructor and destructor
    Dict();
    ~Dict();

    // Add a word to the dictionnary
    void addWord(std::string word);

    // Remove non-[a-z] characters and put the word in lowercase
    void cleanWord(std::string& word);

    // Check whether a word exists in the dictionnary
    bool isWord(std::string word);

    // Print all words of the dictionnary, in alphabetical order std::sort(data.begin(), data.end());
    void printDictWords();

    // Return the number of times a word was seen while building the dictionnary
    int getWordFrequency(std::string word);

    // Print the graph into a file in Graphviz (xdot) format
    void generateGraphFile(std::string filename);

    // Build the dictionnary from a file
    void buildDictionnary(std::string filename);

    // Return the shortest word found in the dictionnary
    std::string getShortestWord();

    // Return the longuest word found in the dictionnary
    std::string getLongestWord();

//private:
    // Shared code used by getWordFrequency, isWord
    Node* getWordEnd(std::string word);

    // Memory management
    void freeDictMemory();
};


#endif

