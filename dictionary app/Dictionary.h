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
    void searchWord(const string& word);
    void displayAll();
    void drawTree();

private:
    void find(const string& key, Node** par, Node** loc);
    void inorder(Node* ptr);
    void display(Node* root, int x, int y, int level, int dx);
    void case_a(Node* par, Node* loc);
    void case_b(Node* par, Node* loc);
    void case_c(Node* par, Node* loc);
    void deleteTree(Node* node);
};

#endif

