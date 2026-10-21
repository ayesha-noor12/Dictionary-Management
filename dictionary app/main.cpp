#include "Dictionary.h"
#include "DictionaryImpl.h"
#include <iostream>
using namespace std;

int main() {
    Dictionary dictionary;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int choice;
    while (true) {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Word\n";
        cout << "2. Delete Word\n";
        cout << "3. Search Word\n";
        cout << "4. Display All Words\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string word, meaning;
                cout << "Enter word: ";
                cin >> word;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, meaning);
                dictionary.insert(word, meaning);
                break;
            }
            case 2: {
                string word;
                cout << "Enter the word to delete: ";
                cin >> word;
                dictionary.del(word);
                break;
            }
            case 3: {
                string word;
                cout << "Enter the word to search: ";
                cin >> word;
                dictionary.searchWord(word);
                break;
            }
            case 4:
                dictionary.displayAll();
                break;
            case 5:
                cout << "Exiting...\n";
                closegraph();
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

