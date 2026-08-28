#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::cout << "=== Testing std::vector<int> ===" << std::endl;

    std::vector<char> vec;
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('d');
    vec.push_back('e');

    try
    {
        std::vector<char>::iterator it = easyfind(vec, 'e');
        std::cout << "Found in vector: " << *it << std::endl;
        it = easyfind(vec, 't');
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Testing std::list<int> ===" << std::endl;

    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);

    try
    {
        std::list<int>::iterator it = easyfind(lst, 200);
        std::cout << "Found in list: " << *it << std::endl;
        it = easyfind(lst, 999);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
