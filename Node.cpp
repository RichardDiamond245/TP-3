#include "Node.hpp"
#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>

#include <sstream>

static int ID=0;
static int nbNode=0;
Node::Node(char letter){
	nbNode++;
	this->m_id = ID++;
	this->m_letter = letter;
	this->m_wordEnd = false;
	this->m_frequency = 1;
	for(int i = 0; i < 26; i++)
		this->m_next[i] = NULL;
}

Node* Node::getNext(char letter){
	for(int i = 0; i < 26; i++){
		if(this->m_next[i] != NULL){
			if(this->m_next[i]->m_letter == letter)
				return this->m_next[i];
		}
	}
	return NULL;
}
Node* Node::getNext(int index){
	if(index > 0 && index < 26)
		return this->m_next[index];
	else{
		return NULL;
	}
}

void Node::addWord(std::string word){
	const char* letters = word.substr(0,1).c_str();
	char letter(letters[0]);
	Node* node = this->getNext(letter);
	if(node == NULL){
		if(this->m_next[letter - 'a'] == NULL){
			node = new Node(letter);
			this->m_next[letter - 'a'] = node;
			if(word.length() == 1)
				node->m_wordEnd = true;
		}
	}else{
		node->m_frequency++;
		if(word.length() == 1)
			node->m_wordEnd = true;
	}
	
	if(word.length() > 1){
		std::string restWord = word.substr(1, word.length());
		node->addWord(restWord);
	}
}

bool Node::isEndOfWord(){
	return this->m_wordEnd;
}
int Node::getFrequency(){
	return this->m_frequency;
}

void Node::printGraphLabels(std::ofstream& stream){
	if(stream.good()){
		if(this->m_letter == ' ')
			stream << "digraph G {\n" << this->m_id << " [label=\" \", shape=diamond];\n";
		for(int i = 0; i < 26; i++){
			if(this->m_next[i] != NULL){
				stream << this->m_next[i]->m_id << " [label=\"" << this->m_next[i]->m_letter 
					<< " (" << this->m_next[i]->m_frequency << ")\"";
				if(this->m_next[i]->m_wordEnd)
					stream << ", shape=box";
				stream << "];\n"; 
				this->m_next[i]->printGraphLabels(stream);
			}
		}
	}

}

void Node::printGraphNodes(std::ofstream& stream){
	if(stream.good()){
		for(int i = 0; i < 26; i++){
			if(this->m_next[i] != NULL){
				stream << this->m_id << " -> " << this->m_next[i]->m_id << "\n";
				this->m_next[i]->printGraphNodes(stream);
			}
		}
		if(this->m_letter == ' ')
			stream << "}";
	}
}
void Node::printDictWords(std::string word){
	if(this->m_wordEnd)
		std::cout << word.substr(1,word.length()) << this->m_letter << std::endl;
	for(int i = 0; i < 26; i++){
		if(this->m_next[i] != NULL){
			std::string words = word + this->m_letter;
			this->m_next[i]->printDictWords(words);
		}
	}
}
std::string Node::getShortestWord(std::string prefix){
	if(this->m_wordEnd)
		return prefix.substr(1,prefix.length()) + this->m_letter;
	for(int i = 0; i < 26; i++){
		if(this->m_next[i] != NULL){
			std::string words = prefix + this->m_letter;
			return this->m_next[i]->getShortestWord(words);
		}
	}
	return "";
}
std::string Node::getLongestWord(std::string longest){
	std::string wordR = "";
	std::stringstream ss;
    auto old_buf = std::cout.rdbuf(ss.rdbuf()); //Change le buffer de cout pour diriger vers le stringstream ss
    this->printDictWords(""); //Tout les output vont dans la variable ss
    std::cout.rdbuf(old_buf); //reset le buffer de sortie cout
    std::string word;
    while(ss >> word){
    	if(word.length() > wordR.length())
    		wordR = word;
    }
    return wordR;
}
void Node::deepFreeNodeMemory(){
	for(int i = 0; i < 26; i++)
		if(this->m_next[i] != NULL)
			this->m_next[i]->deepFreeNodeMemory();
	//std::cout << "freeing " << this->m_letter <<" nb: "<< nbNode--<< std::endl;
	//std::cout << "left:"<<nbNode << std::endl;
	delete this;
}