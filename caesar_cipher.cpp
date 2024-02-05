#include <iostream>
#include <string>
#include <map>

struct Alphabet
{
    const std::map<char, char> a_lower = {
        {'a', 'a'},
        {'b', 'b'},
        {'c', 'c'},
        {'d', 'd'},
        {'e', 'e'},
        {'f', 'f'},
        {'g', 'g'},
        {'h', 'h'},
        {'i', 'i'},
        {'j', 'j'},
        {'k', 'k'},
        {'l', 'l'},
        {'m', 'm'},
        {'n', 'n'},
        {'o', 'o'},
        {'p', 'p'},
        {'q', 'q'},
        {'r', 'r'},
        {'s', 's'},
        {'t', 't'},
        {'u', 'u'},
        {'v', 'v'},
        {'w', 'w'},
        {'x', 'x'},
        {'y', 'y'},
        {'z', 'z'}
    };
    const std::map<char, char> a_upper = {
        {'A', 'A'},
        {'B', 'B'},
        {'C', 'C'},
        {'D', 'D'},
        {'E', 'E'},
        {'F', 'F'},
        {'G', 'G'},
        {'H', 'H'},
        {'I', 'I'},
        {'J', 'J'},
        {'K', 'K'},
        {'L', 'L'},
        {'M', 'M'},
        {'N', 'N'},
        {'O', 'O'},
        {'P', 'P'},
        {'Q', 'Q'},
        {'R', 'R'},
        {'S', 'S'},
        {'T', 'T'},
        {'U', 'U'},
        {'V', 'V'},
        {'W', 'W'},
        {'X', 'X'},
        {'Y', 'Y'},
        {'Z', 'Z'}
    };
};

void ceaser_cipher_encrypt(std::string &word, const std::map<char, char> a_upper, const std::map<char, char> a_lower)
{
    for (auto i = 0; i != word.size() && i >= 0; ++i)
    {
        if (a_upper.find(word[i]) != a_upper.cend())
        {
            word[i] = a_upper.find(word[i])->second+1;
        }
        else if (a_lower.find(word[i]) != a_lower.cend())
        {
            word[i] = a_lower.find(word[i])->second+1;
        }
    }
}

void ceaser_cipher_decrypt(std::string &word, const std::map<char, char> a_upper, const std::map<char, char> a_lower)
{
    for (auto i = 0; i != word.size() && i >= 0; ++i)
    {
        if (a_upper.find(word[i]) != a_upper.cend())
        {
            word[i] = a_upper.find(word[i])->second-1;
        }
        else if (a_lower.find(word[i]) != a_lower.cend())
        {
            word[i] = a_lower.find(word[i])->second-1;
        }
    }
}

void menu()
{
    std::cout << "===================" << std::endl;
    std::cout << "   CEASER CIPHER   " << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
    std::cout << "3. Quit" << std::endl;
}

void run()
{
    std::string word;
    unsigned input = 0;
    Alphabet alphabet;

    for (unsigned i = 0; i < 1 && input != 3; ++i)
    {
        menu();
        std::cout << "Selected number: ";
        std::cin >> input;
        switch (input)
        {
            case 1:
                std::cout << "Decrypted word: ";
                std::cin >> word;
                
                ceaser_cipher_encrypt(word, alphabet.a_upper, alphabet.a_lower);

                std::cout << "Encrypted word: " << word << std::endl;
                break;
            case 2:
                std::cout << "Decrypted word: ";
                std::cin >> word;

                ceaser_cipher_decrypt(word, alphabet.a_upper, alphabet.a_lower);

                std::cout << "Decrypted word: " << word << std::endl;
                break;
            case 3:
                break;
            default:
                std::cout << "Choose between 1, 2, and 3." << std::endl;
                break;
        }
    }
}

int main()
{
    run();
    return 0;
}
