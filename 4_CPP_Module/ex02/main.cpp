#include "cat.hpp"
#include "dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


void test1() {
const Animal* j = new Dog();
// {
//     Dog tmp;
//     tmp = *j;
//     // assert(tmp._b != j->_b);
// }
delete j;//should not create a leak

}

// void test2() {

//     const Animal* i = new Cat();
//     const Animal *i = new  Cat();
  
//     Animal* arr[10];// = new Animal[10];

//     for (int i = 0; i < 10; i++)
//     {
//         if (i % 2 == 0)
//             arr[i] = new Cat();
//         else if (i % 2)
//             arr[i] = new Dog();
//     }

//     for (int i = 0; i < 10; i++)
//         arr[i]->makeSound();

//     for (int i = 0; i < 10; i++)
//         delete arr[i];
//     delete i;
// }

int main()
{
   test1();
    return 0;
}