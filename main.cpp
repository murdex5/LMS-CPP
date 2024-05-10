#include <iostream>
#include <string>
#include <vector>
#include "includes/random_id.h"

using namespace::std;

class Book;
class User;

class Author {
    private:
        vector<Book> books;
    
    public:
        string fullName;
        Author() : fullName(""), books() {};
        Author(const char* name, std::nullptr_t) : fullName(name), books() {}
        Author(string fn, vector<Book>& books) {
            fullName = fn;
            for (const Book& book : books) {
                this -> books.push_back(book);
            }
        }

        string getName() {
            cout << fullName << endl;
            return fullName;
        }
        void getBooks();
};


class Book {
    private:
        int pages;
        Author author;
        bool available;
        User* borrowedUser;

    public:
        int id;
        string bookName;
        Book() : bookName(""), author(), available(), borrowedUser(nullptr) {};
        Book(int id,string bookN, const Author& author, bool available = true, User* borrowedUser = nullptr) {
            bookName = bookN;
            this -> id = id;
            this->pages = pages;
            this->author = author;
            this->available = available;
            this->borrowedUser = borrowedUser;
        }

        string getName() {
            return bookName;
        }
        void borrowBook();

        void returnBook() {
            available = true;
        }

        bool checkAvailability() {
            return available;
        }

        void getAuthor();
};

class User {
    private:
        int id;
        string fullName;
        Book* borrowedBooks[10];
        int numBorrowedBooks = 0;
    public:
        string username;

        User() {
            this -> id = 0;
            this -> fullName = "";
            this -> username = "";
            for (int i  = 0; i < 10; i++) {
                borrowedBooks[i] = nullptr;
            }
        }

        User (int id, string fullName, string username, Book* borrowedBooks[]) {
            this->id = id;
            this -> fullName = fullName;
            this -> username = username;
            borrowedBooks = borrowedBooks;
        }
        void uBorrowBook(const Book& book);
        void uReturnBook(const Book& book);

        int getNumBorrowedBooks() {
            return numBorrowedBooks;
        }
};


// Author Functions
void Author::getBooks() {
    for (const Book book : books) {
        cout << book.bookName << endl;
    }
};



// Book Functions
void Book::getAuthor() {
    cout << author.fullName << endl;
}

void Book::borrowBook() {
    if (available == true) {
        available = false;
    } else {
        cout << "The book is not currently available!";
    }
}

// User Function
void User::uBorrowBook(const Book& book) {
    if (numBorrowedBooks < 10) {
        borrowedBooks[numBorrowedBooks] = new Book(book);
        borrowedBooks[numBorrowedBooks]->borrowBook();
        numBorrowedBooks++;
    } else {
        cout << "You have reached your limit!";
    }
}

void User::uReturnBook(const Book& book) {
    int i;
    for (i = 0; i < numBorrowedBooks; i++) {
        if ( borrowedBooks[i]->id == book.id) {
            borrowedBooks[i]->returnBook();
            borrowedBooks[i] == nullptr;
        } else {
            cout << "You have not borrowed a Book from this id" << endl;
        }
    }
}
// User::~User() {
//     for (int i = 0; i < numBorrowedBooks; i++) {
//         delete[] borrowedBooks[i];
//     }
// }




int main() {
    int i = 4;
    Book book1("The Lord of the Rings", 1178, Author("J.R.R. Tolkien", nullptr), true);
    Book book2("Pride and Prejudice", 352, Author("Jane Austen", nullptr), true);

    vector<Book> authorBooks;
    authorBooks.push_back(book1);
    authorBooks.push_back(book2);

    Author author1("William Shakespeare", authorBooks);
    author1.getBooks();
    book1.getAuthor();
    return 0;

}