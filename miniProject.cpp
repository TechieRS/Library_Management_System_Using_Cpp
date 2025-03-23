#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title, author, isbn;
    bool available = true;
    string borrower;
};

vector<Book> books;

void addBook() {
    Book b;
    cin.ignore();  
    cout << "Enter Title: ";
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    cout << "Enter ISBN: ";
    getline(cin, b.isbn);
    books.push_back(b);
    cout << "Book added successfully!\n";
}

void searchBook() {
    if (books.empty()) {
        cout << "No books available to search.\n";
        return;
    }

    string input;
    cin.ignore();
    cout << "Enter Title or Author to search: ";
    getline(cin, input);
    bool found = false;

    for (auto &b : books) {
        if (b.title == input || b.author == input) {
            cout << "Found: " << b.title << " by " << b.author
                << " (ISBN: " << b.isbn << "), Available: "
                << (b.available ? "Yes" : "No, Borrowed by " + b.borrower) << endl;
            found = true;
        }
    }
    if (!found) cout << "Book not found!\n";
}

void displayBooks() {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    cout << "\nLibrary Books:\n";
    for (auto &b : books) {
        cout << "Title: " << b.title << ", Author: " << b.author
            << ", ISBN: " << b.isbn << ", Available: "
            << (b.available ? "Yes" : "No, Borrowed by " + b.borrower) << endl;
    }
}

void borrowBook() {
    if (books.empty()) {
        cout << "No books available to borrow.\n";
        return;
    }

    string isbn;
    cin.ignore();
    cout << "Enter ISBN to borrow: ";
    getline(cin, isbn);

    for (auto &b : books) {
        if (b.isbn == isbn) {
            if (b.available) {
                cout << "Enter your name: ";
                getline(cin, b.borrower);
                b.available = false;
                cout << "You borrowed: " << b.title << endl;
            } else {
                cout << "Book is already borrowed by " << b.borrower << endl;
            }
            return;
        }
    }
    cout << "Book not found!\n";
}

void returnBook() {
    if (books.empty()) {
        cout << "No books available to return.\n";
        return;
    }

    string isbn;
    cin.ignore();
    cout << "Enter ISBN to return: ";
    getline(cin, isbn);

    for (auto &b : books) {
        if (b.isbn == isbn && !b.available) {
            cout << "Book '" << b.title << "' returned by " << b.borrower << endl;
            b.available = true;
            b.borrower.clear();
            return;
        }
    }
    cout << "Invalid ISBN or book was not borrowed!\n";
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n2. Search Book\n3. Display Books\n4. Borrow Book\n5. Return Book\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: displayBooks(); break;
            case 4: borrowBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
