// main.cpp
#include "Dictionary.h"
#include <iostream>
using namespace std;

int main() {
    Dictionary dictionary;
    bool isAdmin = false;
    int roleChoice;

    // Ask for role
    cout << "Select role:  1) User  2) Administrator";
    cout << "\n Enter choice: ";
    cin >> roleChoice;

    if (roleChoice == 2) {
        string username, password;
        cout << "\n Enter username: ";
        cin >> username;
        cout << "\n Enter password: ";
        cin >> password;
        if (username == "admin" && password == "admin123") {
            isAdmin = true;
            cout << "\n Logged in as administrator.";
        } else {
            cout << "\n Invalid admin credentials. Continuing as user.";
        }
    } else {
        cout << "\n Logged in as user.";
    }

    int choice;
    while (true) {
        cout << "\n Dictionary Menu:";
        if (isAdmin) {
            cout << "\n1. Add Word";
            cout << "\n2. Delete Word";
            cout << "\n3. Change Meaning";
            cout << "\n4. Search Word";
            cout << "\n 5. Display All Words";
            cout << "\n6. Exit";
        } else {
            cout << "\n1. Search Word";
            cout << "\n2. Display All Words";
            cout << "\n3. Exit";
        }
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (isAdmin) {
            switch (choice) {
                case 1: {
                    string word, meaning;
                    cout << "\nEnter word: ";
                    cin >> word;
                    cout << "\nEnter meaning: ";
                    cin.ignore();
                    getline(cin, meaning);
                    dictionary.insert(word, meaning);
                    break;
                }
                case 2: {
                    string word;
                    cout << "\nEnter the word to delete: ";
                    cin >> word;
                    dictionary.del(word);
                    break;
                }
                case 3: {
                    string word, newMeaning;
                    cout << "\nEnter the word to change meaning: ";
                    cin >> word;
                    cout << "\nEnter new meaning: ";
                    cin.ignore();
                    getline(cin, newMeaning);
                    dictionary.updateWord(word, newMeaning);
                    break;
                }
                case 4: {
                    string word;
                    cout << "\nEnter the word to search: ";
                    cin >> word;
                    dictionary.searchWord(word);
                    break;
                }
                case 5:
                    dictionary.displayAll();
                    break;
                case 6:
                    cout << "\nExiting...";
                    return 0;
                default:
                    cout << "\nInvalid choice. Try again.";
            }
        } else {
            switch (choice) {
                case 1: {
                    string word;
                    cout << "\nEnter the word to search: ";
                    cin >> word;
                    dictionary.searchWord(word);
                    break;
                }
                case 2:
                    dictionary.displayAll();
                    break;
                case 3:
                    cout << "\nExiting...";
                    return 0;
                default:
                    cout << "\n Invalid choice. Try again.";
            }
        }
    }
}





