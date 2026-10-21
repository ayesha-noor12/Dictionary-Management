#ifndef DICTIONARY_IMPL_H
#define DICTIONARY_IMPL_H

#include "Dictionary.h"
#include <graphics.h>
#include <iostream>
using namespace std;

Dictionary::Dictionary() : root(NULL) {}

Dictionary::~Dictionary() {
    deleteTree(root);
}

void Dictionary::deleteTree(Node* node) {
    if (node != NULL) {
        deleteTree(node->lchild);
        deleteTree(node->rchild);
        delete node;
    }
}

void Dictionary::find(const string& key, Node** par, Node** loc) {
    Node* ptr = root;
    *par = NULL;

    while (ptr != NULL) {
        if (key == ptr->word) {
            *loc = ptr;
            return;
        }
        *par = ptr;
        if (key < ptr->word) {
            ptr = ptr->lchild;
        } else {
            ptr = ptr->rchild;
        }
    }
    *loc = NULL;
}

void Dictionary::insert(const string& word, const string& meaning) {
    Node *parent, *location;
    find(word, &parent, &location);

    if (location != NULL) {
        cout << "Word already exists in the dictionary.\n";
        return;
    }

    Node* tmp = new Node{word, meaning, NULL, NULL};

    if (parent == NULL) {
        root = tmp;
    } else if (word < parent->word) {
        parent->lchild = tmp;
    } else {
        parent->rchild = tmp;
    }

    cout << "Word added successfully.\n";
    drawTree();
}

void Dictionary::del(const string& word) {
    Node *parent, *location;
    find(word, &parent, &location);

    if (location == NULL) {
        cout << "Word not found in the dictionary.\n";
        return;
    }

    if (location->lchild == NULL && location->rchild == NULL) {
        case_a(parent, location);
    } else if (location->lchild != NULL && location->rchild == NULL) {
        case_b(parent, location);
    } else if (location->lchild == NULL && location->rchild != NULL) {
        case_b(parent, location);
    } else {
        case_c(parent, location);
    }

    delete location;
    cout << "Word deleted successfully.\n";
    drawTree();
}

void Dictionary::case_a(Node* par, Node* loc) {
    if (par == NULL) {
        root = NULL;
    } else if (loc == par->lchild) {
        par->lchild = NULL;
    } else {
        par->rchild = NULL;
    }
}

void Dictionary::case_b(Node* par, Node* loc) {
    Node* child = (loc->lchild != NULL) ? loc->lchild : loc->rchild;

    if (par == NULL) {
        root = child;
    } else if (loc == par->lchild) {
        par->lchild = child;
    } else {
        par->rchild = child;
    }
}

void Dictionary::case_c(Node* par, Node* loc) {
    Node* ptrsave = loc;
    Node* ptr = loc->rchild;

    while (ptr->lchild != NULL) {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }

    loc->word = ptr->word;
    loc->meaning = ptr->meaning;

    if (ptr->lchild == NULL && ptr->rchild == NULL) {
        case_a(ptrsave, ptr);
    } else {
        case_b(ptrsave, ptr);
    }
}

void Dictionary::inorder(Node* ptr) {
    if (ptr != NULL) {
        inorder(ptr->lchild);
        cout << ptr->word << ": " << ptr->meaning << endl;
        inorder(ptr->rchild);
    }
}

void Dictionary::displayAll() {
    if (root == NULL) {
        cout << "Dictionary is empty.\n";
    } else {
        inorder(root);
    }
}

void Dictionary::searchWord(const string& word) {
    Node *parent, *location;
    find(word, &parent, &location);

    if (location == NULL) {
        cout << "Word not found in the dictionary.\n";
    } else {
        cout << "Word: " << word << "\nMeaning: " << location->meaning << endl;
    }
}

void Dictionary::display(Node* root, int x, int y, int level, int dx) {
    if (root == NULL) return;

    char buffer[100];
    sprintf(buffer, "%s\n%s", root->word.c_str(), root->meaning.c_str());

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    setcolor(BLUE);
    fillellipse(x, y, 30, 30);
    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(x - 20, y - 10, buffer);

    if (root->lchild != NULL) {
        line(x, y + 30, x - dx, y + 100);
        display(root->lchild, x - dx, y + 100, level + 1, dx / 1.4);
    }
    if (root->rchild != NULL) {
        line(x, y + 30, x + dx, y + 100);
        display(root->rchild, x + dx, y + 100, level + 1, dx / 1.4);
    }
}

void Dictionary::drawTree() {
    cleardevice();
    int screenWidth = getmaxx();
    int dx = screenWidth / 5;
    display(root, screenWidth / 2, 50, 1, dx);
}

#endif

