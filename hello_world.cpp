#include <iostream>
#include <string>

// Program greeting the user.

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Hello world from " << name << std::endl;

    return 0;
}
