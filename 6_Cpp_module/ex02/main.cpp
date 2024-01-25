#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include <typeinfo>
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    int randomNum;

    srand(time(NULL));
    randomNum = rand() % 3;
    std::cout << "randomNum = " << randomNum << std::endl;
    switch (randomNum)
    {
    case 0:
        return (new A);
    case 1:
        return (new B);
    case 2:
        return (new C);
    default:
        return (new A);
    }
    return (NULL);
};

// void identify(Base *p) {
//     if (typeid(*p) == typeid(A)) {
//         std::cout << "A" << std::endl;
//     } else if (typeid(*p) == typeid(B)) {
//         std::cout << "B" << std::endl;
//     } else if (typeid(*p) == typeid(C)) {
//         std::cout << "C" << std::endl;
//     } else {
//         std::cout << "Unknown type" << std::endl;
//     }
// }

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
        return ;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
        return ;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
        return ;
    }
    std::cout << "Non of them" << std::endl;
};

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e) {
    }
    std::cout << "Non of them" << std::endl;
};

int main(int ac, char **av) {
    (void)ac;
    (void)av;
    Base *ptr;
    ptr = generate();
    Base &a = *ptr;
    identify(ptr);
    identify(a);
}