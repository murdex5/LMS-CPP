#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class Book;
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

    public:
        string bookName;
        Book(string bookN, int pages, const Author& author, bool available = true) {
            bookName = bookN;
            this->pages = pages;
            this->author = author;
            this->available = available;
        }

        string getName() {
            return bookName;
        }
        void borrowBook() {
            available = false;
        }

        void returnBook() {
            available = true;
        }

        bool checkAvailability() {
            return available;
        }

        void getAuthor();
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


int main() {
    // Assuming Book constructor implementation
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