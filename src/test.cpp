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
        Author(string name, std::nullptr_t) : fullName(name), books() {}
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
        int id = randomId();
        string bookName;
        Book() : bookName(""), author(), available(), borrowedUser(nullptr) {};
        Book(string bookN, const Author& author, bool available = true, User* borrowedUser = nullptr) {
            bookName = bookN;
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
        int id = randomId();
        string fullName;
        Book* borrowedBooks[10];
        int numBorrowedBooks = 0;
    public:
        string username;

        User() {
            this -> fullName = "";
            this -> username = "";
            for (int i  = 0; i < 10; i++) {
                borrowedBooks[i] = nullptr;
            }
        }

        User (string fullName, string username, Book* borrowedBooks[]) {
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
    Author author1;  // Empty name, empty books list
    Book book1;  // Empty title, empty author, available, no borrower
    string name = "William Shakespeare";
    Author author2(name);  // Name: "William Shakespeare", empty books list

    std::vector<Book> shakespeareBooks;  // Prepare a vector of Book objects (implementation not shown here)
    Author author3("William Shakespeare", shakespeareBooks);


    // Assuming you have Author objects created (implementation not shown):
    Author author4("J.R.R. Tolkien", nullptr);

    Book book2("The Lord of the Rings", author4, false);  // Title: "The Lord of the Rings", Author: author4, Borrowed, no borrower specified
    Book book3("Pride and Prejudice", Author("Jane Austen", nullptr), true);  // Title: "Pride and Prejudice", Available, no borrower specified

    // You can add a User object (assuming User class is defined) for the borrower later
    User borrower;
    book2.borrowedUser = &borrower;  // Assign the borrower to book2

    User user1;  // Empty full name, username, no borrowed books

    // Assuming you have Book objects created (implementation not shown):
    Book borrowedBooks[2] = {book1, book2};  // Borrowed books: book1, book2

    User user2("Praboth Malsha", "malshapraboth", borrowedBooks);  // Full name, username, borrowed books assigned (assuming `uBorrowBook` is implemented)
    return 0;

}