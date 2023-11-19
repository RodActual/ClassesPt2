// Anthony Rodriguez
// CIS 1202 101
// November 1, 2023

#include "Publication.h"

void getPublications(Publication[], int&);
void showPublications(Publication[], int);
void showTitles(Publication[], int);
int findPublication(Publication[], int, string);
int getMenuChoice();

const int MAX_PUBLICATIONS = 100;
Publication publications[MAX_PUBLICATIONS];
int numPublications = 0;

int main() {
    getPublications(publications, numPublications);

    int choice;
    do {
        choice = getMenuChoice();
        cin.ignore();

        switch (choice) {
        case 1:
            showPublications(publications, numPublications);
            cout << endl;
            break;
        case 2:
            showTitles(publications, numPublications);
            cout << endl;
            break;
        case 3:
        {
            string title;
            cout << "Enter the title to find: ";
            getline(cin, title);
            int position = findPublication(publications, numPublications, title);
            if (position != -1) {
                publications[position].displayInfo();
            }
            else {
                cout << "Publication not found." << endl;
            }
            cout << endl;
        }
        break;
        case 4:
        {
            string title;
            cout << "Enter the title to check out: ";
            getline(cin, title);
            int position = findPublication(publications, numPublications, title);
            if (position != -1) {
                publications[position].checkOut();
            }
            else {
                cout << "Publication not found." << endl;
            }
            cout << endl;
        }
        break;
        case 5:
        {
            string title;
            cout << "Enter the title to check in: ";
            getline(cin, title);
            int position = findPublication(publications, numPublications, title);
            if (position != -1) {
                publications[position].checkIn();
            }
            else {
                cout << "Publication not found." << endl;
            }
            cout << endl;
        }
        break;
        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}

void getPublications(Publication publications[], int& numPublications) {
    ifstream inputFile("C:/Users/antho/11publications.txt");

    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        exit(1);
    }

    while (inputFile >> publications[numPublications]) {
        numPublications++;

        if (numPublications >= MAX_PUBLICATIONS) {
            cerr << "Array is full. Cannot store more publications." << endl;
            break;
        }
    }

    inputFile.close();
}

void showPublications(Publication publications[], int numPublications) {
    for (int i = 0; i < numPublications; i++) {
        publications[i].displayInfo();
    }
}

void showTitles(Publication publications[], int numPublications) {
    for (int i = 0; i < numPublications; i++) {
        cout << publications[i].getTitle() << endl;
    }
}

int findPublication(Publication publications[], int numPublications, string title) {
    for (int i = 0; i < numPublications; i++) {
        if (publications[i].getTitle() == title) {
            return i;
        }
    }
    return -1;
}

int getMenuChoice() {
    int choice;
    cout << "Menu:\n";
    cout << "1. Display all publications\n";
    cout << "2. Display publication titles\n";
    cout << "3. Find a publication\n";
    cout << "4. Check out\n";
    cout << "5. Check in\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    return choice;
}