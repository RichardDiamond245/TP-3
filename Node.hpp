#ifndef __NODE_HPP__
#define __NODE_HPP__
#include <vector>
#include <string>

static const int ALPHABET_SIZE = 26;

class Node
{
public:
//private:
    int m_id;
    char m_letter;
    bool m_wordEnd;
    int m_frequency;
    Node* m_next[26];
    
//public:
    // Constructor
    Node(char letter);

    // Insert the remaining of the word into the structure
    void addWord(std::string word);

    // Return the pointer to the corresponding node
    Node* getNext(char letter);
    Node* getNext(int index);

    // Return true if the letter is the last of an existing word
    bool isEndOfWord();

    // Return the frequency of the letter
    int getFrequency();

    // Print the graph into a file in Graphviz (xdot) format
    void printGraphLabels(std::ofstream& stream);
    void printGraphNodes(std::ofstream& stream);

    // Print dictionary words
    void printDictWords(std::string word);

    // Return the shortest word found in the dictionnary
    std::string getShortestWord(std::string prefix);

    // Return the longuest word found in the dictionnary
    std::string getLongestWord(std::string longest);

    // Memory management
    void deepFreeNodeMemory();//But de la fonctin incomprise... explication?
};


#endif
