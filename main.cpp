#include <iostream>
#include <string>
#include <vector>

using namespace::std;

class Author {
    public:
        char* fullName;
        //Borrowed Books
        Author(char* fullName);
        void getName();
};

// Author Functions
Author::Author(char* fullName) {
    this -> fullName = fullName;
}
void Author::getName() {
    cout << fullName << endl;
}

int main() {
    return 0;
}