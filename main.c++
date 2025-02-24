#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Book
{
public:
    int id;
    string title, author;
    Book(int i, string t, string a) : id(i), title(t), author(a) {}
};

class Library
{
private:
    vector<Book> books;
    void saveToFile()
    {
        ofstream file("books.txt");
        for (const auto &book : books)
        {
            file << book.id << "," << book.title << "," << book.author << "\n";
        }
    }
    void loadFromFile()
    {
        ifstream file("books.txt");
        if (!file)
            return;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            int id;
            string title, author;
            char delimiter;
            ss >> id >> delimiter;
            getline(ss, title, ',');
            getline(ss, author);
            books.emplace_back(id, title, author);
        }
    }

public:
    Library() { loadFromFile(); }
    void addBook(int id, string title, string author)
    {
        books.push_back(Book(id, title, author));
        saveToFile();
    }
    void removeBook(int id)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->id == id)
            {
                books.erase(it);
                saveToFile();
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void searchBook(string title)
    {
        for (const auto &book : books)
        {
            if (book.title == title)
            {
                cout << "Found: " << book.title << " by " << book.author << "\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
    void displayBooks()
    {
        if (books.empty())
        {
            cout << "No books available.\n";
            return;
        }
        for (const auto &book : books)
        {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << "\n";
        }
    }
};

int main()
{
    Library library;
    int choice, id;
    string title, author;
    do
    {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Remove Book\n3. Search Book\n4. Display Books\n5. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter ID, Title, Author: ";
            cin >> id;
            cin.ignore();
            getline(cin, title);
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            cout << "Enter Book ID to remove: ";
            cin >> id;
            library.removeBook(id);
            break;
        case 3:
            cout << "Enter Book Title to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBook(title);
            break;
        case 4:
            library.displayBooks();
            break;
        case 5:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 5);
    return 0;
}
