#include "Zombie.hpp"

int main()
{
	//gérer avec une string nulle ?
	std::cout << "Creation of a zombie on the heap :" << std::endl;
	 Zombie	*zombie1 = newZombie("chichaaaa");
	 if (zombie1)
	 {
		zombie1->announce();
		delete (zombie1);
	 }

	 std::cout << "Creation of a zombie on the stack :" << std::endl;
	std::cout << "> with the randomchump function :" << std::endl;
	randomChump("DARKZ");

	std::cout << "> directly in the main function :" << std::endl;
	Zombie	zombie2("oups");
	zombie2.announce();
}