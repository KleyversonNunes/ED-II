#include <iostream>
#include <string>

int main()
{
    std::cout << "Ola, C++ Moderno!" << std::endl;
    std::string name;
    std::cout << "Qual e o seu nome: ";
    std::cin >> name;
    std::cout << "\n\nBoa noite! " << name << std::endl;
    return 0;
}