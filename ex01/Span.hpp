#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  unsigned int N;
  std::vector<int> vect;

public:
  Span();
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  Span(unsigned int n);

  template <typename It>
  void addNumbers(It begin, It end)
  {
    for (It it = begin; it != end; ++it) {
      addNumber(*it);
    }
  }

  void addNumber(int);

  unsigned int shortestSpan(void) const;
  unsigned int longestSpan(void) const;
};

#endif // SPAN_HPP
