#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
  private:
  
  public:
    MutantStack() {}
  
    MutantStack(const MutantStack &other) { *this = other; }
  
    MutantStack &operator=(const MutantStack &other) {
      std::stack<T>::operator=(other);
      return (*this);
    }

    ~MutantStack() { }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};


#endif // MUTANTSTACK_HPP
