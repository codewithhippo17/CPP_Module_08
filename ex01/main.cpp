#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main() {
    std::srand(std::time(NULL));
    std::cout << "=== Phase 1: The Subject Test ===" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl << "=== Phase 2: The Safety Test ===" << std::endl;

    Span safe(1);
    try {
        std::cout << "Trying shortestSpan on empty span... ";
        std::cout << safe.shortestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        safe.addNumber(42);
        std::cout << "Added first number. Trying to add second... ";
        safe.addNumber(99);
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Phase 3: The Massive Load Test ===" << std::endl;

    Span massive(20000);
    std::vector<int> bigList;

    for (int i = 0; i < 20000; ++i) {
        bigList.push_back(std::rand());
    }

    try {
        massive.addNumbers(bigList.begin(), bigList.end());
        std::cout << "Loaded 20,000 numbers via addNumbers template." << std::endl;
        std::cout << "Shortest span: " << massive.shortestSpan() << std::endl;
        std::cout << "Longest span: " << massive.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
