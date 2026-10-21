// DictionaryImpl.cpp
#include "Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary() : root(nullptr) {}
Dictionary::~Dictionary() { deleteTree(root); }

void Dictionary::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->lchild);
    deleteTree(node->rchild);
    delete node;
}

void Dictionary::find(const string& key, Node** par, Node** loc) {
    Node* ptr = root;
    *par = nullptr;
    while (ptr) {
        if (key == ptr->word) {
            *loc = ptr;
            return;
        }
        *par = ptr;
        ptr = (key < ptr->word) ? ptr->lchild : ptr->rchild;
    }
    *loc = nullptr;
}

void Dictionary::insert(const string& word, const string& meaning) {
    Node *parent, *location;
    find(word, &parent, &location);
    if (location) {
        cout << "Word already exists.\n";
        return;
    }
    Node* tmp = new Node{word, meaning, nullptr, nullptr};
    if (!parent)      root = tmp;
    else if (word < parent->word) parent->lchild = tmp;
    else                           parent->rchild = tmp;
    cout << "Added: " << word << "\n";
}

void Dictionary::del(const string& word) {
    Node *parent, *location;
    find(word, &parent, &location);
    if (!location) {
        cout << "Word not found.\n";
        return;
    }
    if (!location->lchild || !location->rchild) {
        Node* child = location->lchild ? location->lchild : location->rchild;
        if (!parent)           root = child;
        else if (parent->lchild == location) parent->lchild = child;
        else                                parent->rchild = child;
        delete location;
    } else {
        Node** succp = &location->rchild;
        while ((*succp)->lchild) succp = &(*succp)->lchild;
        swap(location->word, (*succp)->word);
        swap(location->meaning, (*succp)->meaning);
        Node* tmp = *succp;
        *succp = tmp->rchild;
        delete tmp;
    }
    cout << "Deleted: " << word << "\n";
}

void Dictionary::updateWord(const string& word, const string& newMeaning) {
    Node* p = root;
    while (p && p->word != word)
        p = (word < p->word) ? p->lchild : p->rchild;
    if (!p) cout << "Word not found.\n";
    else {
        p->meaning = newMeaning;
        cout << "Updated meaning of " << word << "\n";
    }
}

void Dictionary::searchWord(const string& word) {
    Node* p = root;
    while (p && p->word != word)
        p = (word < p->word) ? p->lchild : p->rchild;
    if (!p) cout << word << " not found.\n";
    else    cout << p->word << ": " << p->meaning << "\n";
}

void Dictionary::inorder(Node* ptr) {
    if (!ptr) return;
    inorder(ptr->lchild);
    cout << ptr->word << ": " << ptr->meaning << "\n";
    inorder(ptr->rchild);
}

void Dictionary::displayAll() {
    if (!root) {
        cout << "Dictionary is empty.\n";
    } else {
        inorder(root);
    }
}


