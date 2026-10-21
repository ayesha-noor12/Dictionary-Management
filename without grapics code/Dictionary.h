// Dictionary.h
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
using namespace std;

struct Node {
    string word;
    string meaning;
    Node* lchild;
    Node* rchild;
};

class Dictionary {
public:
    Node* root;

    Dictionary();
    ~Dictionary();

    void insert(const string& word, const string& meaning);
    void del(const string& word);
    void updateWord(const string& word, const string& newMeaning);
    void searchWord(const string& word);
    void displayAll();

private:
    void find(const string& key, Node** par, Node** loc);
    void inorder(Node* ptr);
    void deleteTree(Node* node);
};

#endif  // DICTIONARY_H




