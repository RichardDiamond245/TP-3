#include <cstddef>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Dict.hpp"

Dict::Dict(){
	this->m_root = new Node(' ');
}
Dict::~Dict(){
	this->freeDictMemory();
}

// Add a word to the dictionnary
void Dict::addWord(std::string word){
	this->cleanWord(word);
	this->m_root->addWord(word);
}
// Remove non-[a-z] characters and put the word in lowercase
void Dict::cleanWord(std::string& word){
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); } ), word.end());
}
// Check whether a word exists in the dictionnary
bool Dict::isWord(std::string word){
	return (this->getWordEnd(word) != NULL ? true : false);
}
// Print all words of the dictionnary, in alphabetical order std::sort(data.begin(), data.end());
void Dict::printDictWords(){
	this->m_root->printDictWords("");
}
// Return the number of times a word was seen while building the dictionnary
int Dict::getWordFrequency(std::string word){
	Node* node = this->getWordEnd(word);
	return (node != NULL ? node->m_frequency : -1);
}
// Print the graph into a file in Graphviz (xdot) format
void Dict::generateGraphFile(std::string filename){
	std::ofstream stream(filename);
    this->m_root->printGraphLabels(stream);
    this->m_root->printGraphNodes(stream);
    stream.close();
}
// Build the dictionnary from a file
void Dict::buildDictionnary(std::string fileName){
	std::ifstream ifs(fileName);
    if(ifs.good()){
		std::string word;
		while(ifs>>word){
			this->addWord(word);
		}
	}
}
// Return the shortest word found in the dictionnary
std::string Dict::getShortestWord(){
	return this->m_root->getShortestWord("");
}
// Return the longuest word found in the dictionnary
std::string Dict::getLongestWord(){
	return this->m_root->getLongestWord("");
}
Node* Dict::getWordEnd(std::string word){
	Node* node = this->m_root;
	const char* letters = word.c_str();
	int wordSize(word.length());
	for(int i = 0; i < wordSize; i++){
		node = node->getNext(letters[i]);
		if(node == NULL)
			return NULL;
	}
	return node;
}
void Dict::freeDictMemory(){
	this->m_root->deepFreeNodeMemory();
}