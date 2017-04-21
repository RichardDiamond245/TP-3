#include "Dict.hpp"
#include <string>
#include <iostream>



void test_read_and_graph(int number)
{
    std::cout << "Running test_read_and_graph " << std::to_string(number) << std::endl;
    Dict* dict = new Dict();
    std::string file = "words-" + std::to_string(number);
    dict->buildDictionnary((file + ".txt"));
    dict->generateGraphFile((file + ".dot"));
    delete dict;
}

void test_print_dict(int number)
{
    std::cout << "Running test_print_dict " << std::to_string(number) << std::endl;
    Dict* dict = new Dict();
    std::string file = "words-" + std::to_string(number) + ".txt";
    dict->buildDictionnary(file);
    dict->printDictWords();
    delete dict;
}

void test_word(Dict* dict, std::string word)
{
    std::cout << "    isWord(\"" << word << "\"):\t" << dict->isWord(word) ;
    std::cout << "      gWF(\"" << word << "\"):\t" << dict->getWordFrequency(word);
    std::cout << std::endl;
}

void test_word_and_freq(int number)
{
	std::cout << std::endl << "Running test_word_and_freq " << std::to_string(number) << std::endl;
    Dict* dict = new Dict();
    std::string file = "words-" + std::to_string(number) + ".txt";
    dict->buildDictionnary(file);
    test_word(dict, "aa");
    test_word(dict, "alex");
    test_word(dict, "fre");
    test_word(dict, "ab");
    test_word(dict, "abring");
    test_word(dict, "a");
    test_word(dict, "dot");
    test_word(dict, "alexa");
    test_word(dict, "free");
    test_word(dict, "designed");
    test_word(dict, "nuts");
    test_word(dict, "and");
    test_word(dict, "why");
    test_word(dict, "all");
    test_word(dict, "squirrel");
    delete dict;
}

void test_shortest(int number)
{
    std::cout << std::endl << "Running test_shortest " << std::to_string(number) << std::endl;
    std::string file = "words-" + std::to_string(number) + ".txt";
    Dict* dict = new Dict();
    dict->buildDictionnary(file);
    std::cout << "    " << dict->getShortestWord() << std::endl;
    delete dict;
}

void test_longest(int number)
{
    std::cout << std::endl << "Running test_longest " << std::to_string(number) << std::endl;
    std::string file = "words-" + std::to_string(number) + ".txt";
    Dict* dict = new Dict();
    dict->buildDictionnary(file);
    std::cout << "    " << dict->getLongestWord() << std::endl;
    delete dict;
}

int main(int argc, char** argv)
{
    /*Node* root = new Node(' ');
    root->addWord("allo");
    root->addWord("alex");
    root->addWord("allons");
    std::ofstream stream("t.dot");
    root->printGraphLabels(stream);
    root->printGraphNodes(stream);
    root->printDictWords("");
    Dict* d = new Dict();
    d->addWord("allo");
    d->addWord("alex");
    d->addWord("alex");
    d->addWord("aler");
    d->addWord("al");
    d->addWord("allons");
    d->generateGraphFile("t.dot");
    d->printDictWords();
    std::string s = "AlLo";
    d->cleanWord(s);
    std::cout << s << std::endl;
    Node* n = d->getWordEnd("alex");
    std::cout<<n->m_letter<<std::endl;
    d->generateGraphFile("t2.dot");
    if (d->isWord("alex"))
    {
        std::cout<<d->getWordFrequency("alex")<<std::endl;

    }
    std::cout<<"short:"<<d->getShortestWord()<<std::endl;
    std::cout<<"long:"<<d->getLongestWord()<<std::endl;
    delete d;
    Dict* d2 = new Dict();
    d2->buildDictionnary("words-0.txt");
    d->generateGraphFile("t2.dot");*/
    for (int i=0; i<5; i++) {
        test_read_and_graph(i);
        test_print_dict(i);  
        test_word_and_freq(i);
        test_shortest(i);
        test_longest(i);
        std::cout << std::endl << "-------------------" << std::endl;
    }
    return 0;
}


