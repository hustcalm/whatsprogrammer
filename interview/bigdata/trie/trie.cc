/****************************************************************************
* Name: main.cpp
* Author: Carlos F. Perea
* Description: Trie data structure
* Copyright: OPEN
* http://cperea.com/programming/implementation-of-a-trie-in-c/
****************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
 
using namespace std;
 
/**
* Class: Node
* Represents a node within a trie tree
*/
class Node
{
public:
    char value;             // the character value (a-z)
    bool end;               // indicates whether this node completes a word
    Node * children[26];    // represents the 26 letters in the alphabet
    Node(char value);
    ~Node();
};
 
/**
* Constructor method
*/
Node::Node(char value)
{
    this->value = value;
    // Initializes all of the children with NULL value
    for (int i = 0; i < 26; ++i)
        children[i] = NULL;
}
 
/**
* Destructor method
*/
Node::~Node()
{
    // free resources
}
 
/**
* Class: Trie
* Represents a trie tree data structure
*/
class Trie
{
public:
    Trie();
    ~Trie();
    void addWord(string word);
    bool searchForWord(string word);
    void deleteWord(string word);
    Node * getRoot();
private:
    Node * root;
};
 
/**
* Constructor method
*/
Trie::Trie()
{
    // Initialize the trie
    root = new Node(' ');
    root->end = true;
}
 
/**
* Destructor method
*/
Trie::~Trie()
{
    // Free resources
}
 
/**
* Gets the root of the trie
* @return Node *    Pointer to the root node
*/
Node * Trie::getRoot()
{
    return root;
}
 
/**
* Add a word to the trie
* @param string Word to add to the trie
* @return void
*/
void Trie::addWord(string word)
{
    Node * currentNode = root;
 
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);     // Makes sure the character is between a-z
        if (currentNode->children[index] != NULL)
        {
            // check if the current node has the current character as one of its decendants
            currentNode = currentNode->children[index];
        }
        else
        {
            // the current node doesn't have the current character as one of its decendants
            Node * newNode = new Node(currentChar);
            currentNode->children[index] = newNode;
            currentNode = newNode;
        }
        if (i == word.size() - 1)
        {
            // the last character of the word has been reached
            currentNode->end = true;
        }
    }
}
 
/**
* Searches for a word in the trie
* @param string The word to search in the trie
* @return bool  True if it's found, false otherwise
*/
bool Trie::searchForWord(string word)
{
    Node * currentNode = root;
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);
        // if the current node has the current character as one of its decendants
        if (currentNode->children[index] != NULL)
            currentNode = currentNode->children[index];
        else
            return false;
        // makes sure the last node is marked as an end for a word
        if (i == word.size() - 1 && !currentNode->end)
            return false;
    }
    return true;
}
 
/**
* Deletes a word from the trie
* @param string The word to be deleted from the trie
* @return void
*/
void Trie::deleteWord(string word)
{
    Node * currentNode = root;
    Node * lastWord = root;
    for (int i = 0; i < word.size(); ++i)
    {
        char currentChar = tolower(word.at(i));
        int index = currentChar - 'a';
        assert(index >= 0);
        // if the current node has the current character as one of its decendants
        if (currentNode->children[index] != NULL)
            currentNode = currentNode->children[index];
        // the current node doesn't have the current character which means the word is not in the trie
        else
            return;
        if (i == word.size() - 1 && currentNode->end)
            currentNode->end = false;
    }
}
 
/**
* Traverse the trie in-order fashion to print the words in lexicographical order
*/
void alphabetize(Node * node, string prefix = "")
{
    if (node->end)
        cout << prefix << endl;
    for (int i = 0; i < 26; ++i)
    {
        if (node->children[i] != NULL)
        {
            string currentString = prefix + node->children[i]->value;
            alphabetize(node->children[i], currentString);
        }
    }
}
 
int main()
{
    Trie * t = new Trie();
    t->addWord("Carlos");
    t->addWord("Perea");
    t->addWord("Hello");
    t->addWord("Ball");
    t->addWord("Balloon");
    t->addWord("Show");
    t->addWord("Shower");
    alphabetize(t->getRoot());
    /*
    Outputs:
    ball
    balloon
    carlos
    hello
    perea
    show
    shower
    */
    return 0;
}

