
#include "easyfind.hpp"
int main()
{
   try
   {
		  int arr[] = {11,17, 22, 33, 44,10, 55, 66, 77};
      std::vector<int> v1(arr, arr + 7);
      std::cout << "should find___"<<*(easyfind(v1, 55))<< "\n";
      std::cout << "shouldn't find___"<< *(easyfind(v1, 5))<< "\n";
   }
    catch(const std::out_of_range &error)
    {
        std::cout << "Error:" << std::endl;
        std::cout << error.what();
    }
      return 0;
}
