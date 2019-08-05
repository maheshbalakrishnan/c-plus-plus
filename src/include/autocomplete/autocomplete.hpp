#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

#define NODE_TYPE_ROOT              0x01
#define NODE_TYPE_WORD_COMPLETE     0x02

class TrieNode;

typedef unordered_map<char, TrieNode*> AutoCompleteNodes;

class TrieNode {
public:
    AutoCompleteNodes nodes;
    int nodeType;
};

class AutoComplete {
private:
    AutoCompleteNodes root;
    void insertWord(AutoCompleteNodes root, string word, int startPosition);
    void cleanupNode(AutoCompleteNodes root);
    void printAll(AutoCompleteNodes root);
    void init(string input);

public:
    AutoComplete(string input);
    ~AutoComplete();    
    vector<string> complete(string input);
};