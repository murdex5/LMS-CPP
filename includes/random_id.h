#include <iostream>
#include <cstdlib>
#include <ctime>

int randomId() {
    std::srand(static_cast<unsigned>(std::time(0)));

    int randomInt = std::rand() % 101;

    return randomInt;
}