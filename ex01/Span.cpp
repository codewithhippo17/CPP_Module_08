#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span() : N(0) {
}

Span::Span(const Span &other) {
  *this = other;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->N = other.N;
    this->vect = other.vect;
  }
  return (*this);
}

Span::~Span() {
}

Span::Span(unsigned int n) : N(n) { }

void Span::addNumber(int value) {
  if (this->vect.size() >= this->N) {
    throw std::out_of_range("Span is full");
  }
  else {
    this->vect.push_back(value);
  }
}

unsigned int Span::longestSpan(void) const {
  unsigned int res;
  if (this->vect.size() <= 1) {
    throw std::logic_error("Span should have more than one element");
  }
  res = *std::max_element(this->vect.begin(), this->vect.end());
  res -= *std::min_element(this->vect.begin(), this->vect.end());
  return (res);
}

unsigned int Span::shortestSpan(void) const {
  if (this->vect.size() <= 1)
    throw std::logic_error("Span should have more than one element");

  std::vector<int> copy = this->vect;
  std::sort(copy.begin(), copy.end());

  unsigned int min_span = static_cast<unsigned int>(-1);

  for (size_t i = 1; i < copy.size(); ++i) {
    unsigned int diff = static_cast<unsigned int>(copy[i] - copy[i - 1]);
    if (diff < min_span)
      min_span = diff;
    }

  return (min_span);
}
