#pragma once 
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack() {};
        MutantStack(const MutantStack &obj):std::stack<T>(obj){};
        ~MutantStack() {};
        MutantStack &operator=(const MutantStack &obj)
        {
            std::stack<T> ::operator=(obj);
            return (*this);
        };
    // Function to get iterator pointing to the beginning
    iterator begin() { return (this->c.begin());  }

    // Function to get iterator pointing to the end
    iterator end() {return (this->c.end());}

    const_iterator cbegin() { return(this->c.begin());  }

    // Function to get iterator pointing to the end
    const_iterator cend() {return (this->c.end());}

    reverse_iterator rbegin(){return (this->c.rbegin());}
    reverse_iterator rend(){return (this->c.rend());}

    const_reverse_iterator crbegin(){return (this->c.rbegin());}
    const_reverse_iterator crend(){return (this->c.rend());}
};