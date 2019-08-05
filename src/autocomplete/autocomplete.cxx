#include "autocomplete/autocomplete.hpp"
#include <bits/stdc++.h> 
using namespace std;

void AutoComplete::insertWord(AutoCompleteNodes root, string word, int startPosition) {
    if(word.length() <= 0 || startPosition < 0 || startPosition > word.length())
        return;
    
    char targetChar = tolower(word[startPosition]);

    // get the Node of the first character
    if(root.find(targetChar) == root.end()) {
        TrieNode* node = new TrieNode;
        node->nodeType = 0;
        root[targetChar] = node;
    }
    
    if(startPosition == word.length() - 1) {
        root[targetChar]->nodeType |= NODE_TYPE_WORD_COMPLETE;
        return;
    }

    insertWord(root[targetChar]->nodes, word, startPosition + 1);
}

AutoComplete::AutoComplete(string input) {
    init(input);
    printAll(root);
}

AutoComplete::~AutoComplete() {
    return;
    cleanupNode(root);    
}

void AutoComplete::cleanupNode(AutoCompleteNodes root) {    
}

void AutoComplete::printAll(AutoCompleteNodes root) {
    
}

void AutoComplete::init(string input) {
    stringstream sstream(input);
    string word;
    while(getline(sstream, word, ' ')) {
        insertWord(root, word, 0);
    }
}

vector<string> AutoComplete::complete(string input){
    vector<string> result;
    return result;
}
