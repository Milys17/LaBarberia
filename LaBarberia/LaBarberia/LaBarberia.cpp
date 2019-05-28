// LaBarberia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

bool repetir = true;

int main()
{
	 while (repetir)
	 {

		  int selector;
		  std::cout << "Bienvenido a la Barberia!\n";
		  std::cout << "¿Que desea hacer?\n1) Registrar\n2) Ver\n3) Modificar\n4) Cancelar\n5) Cerrar";

		  std::cin >> selector;
		  switch (selector)
		  {
		  case 1:
			   break;

		  case 2:
			   break;

		  case 3:
			   break;

		  case 4:
			   break;

		  case 5:
		  default:
			   repetir = false;
			   break;
		  }
	 }
}