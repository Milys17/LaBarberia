#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Cita.h"
using namespace std;

int regisActual = 1;

ofstream oFile("citas.txt");
ifstream iFile("citas.txt");

cita arreglo[200];

void registrarArchivo() {
	 if (oFile.is_open()) {
		  for (int x = 0; x < std::size(arreglo); x++) {
			   std::stringstream  ss;
			   ss << arreglo[x].getNombre() << " " << arreglo[x].getId() << " " << arreglo[x].getTelefono() << " " << arreglo[x].getBarbero() << " " << arreglo[x].getFecha() << " " << arreglo[x].getHora() << " " << arreglo[x].getTipo() << "\n";
			   std::string s = ss.str();
			   oFile << s;
		  }
		  oFile.close();
	 }
}

void addArreglo(cita Cita) {
	 if (regisActual < 200) {
		  arreglo[regisActual] = Cita;
		  registrarArchivo();
	 }
	 regisActual++;
}

void registrar() {
	 int selec;
	 std::cout << "\n";
	 std::cout << "Registrar:\n1) Cita\n2) En fila de espera\n";
	 std::cin >> selec;
	 std::cout << "\n";
	 if (selec == 1) {
		  string nombre, telefono, barbero, fecha, hora;
		  std::cout << "Nombre:\n";
		  std::cin >> nombre;
		  std::cout << "\n";

		  std::cout << "Telefono:\n";
		  std::cin >> telefono;
		  std::cout << "\n";

		  std::cout << "Barbero: (A / B / C / D)\n";
		  std::cin >> barbero;
		  std::cout << "\n";

		  std::cout << "Fecha: (DD-MM-AA)\n";
		  std::cin >> fecha;
		  std::cout << "\n";

		  std::cout << "Hora: (HH:MM)\n";
		  std::cin >> hora;

		  cita newCita(std::to_string(regisActual),nombre,telefono,barbero,fecha,hora);
		  addArreglo(newCita);
	 }
	 else {
		  string nombre, fecha;
		  std::cout << "Nombre:\n";
		  std::cin >> nombre;
		  std::cout << "\n";

		  std::cout << "FechaActual";
		  std::cin >> fecha;
	
		  cita newCita(std::to_string(regisActual), nombre, fecha);
		  addArreglo(newCita);
	 }
}


int main()
{
	 bool repetir = true;
	 while (repetir)
	 {
		  int selector;
		  std::cout << "Bienvenido a la Barberia!\n";
		  std::cout << "�Que desea hacer?\n1) Registrar\n2) Ver\n3) Modificar\n4) Cancelar\n5) Cerrar\n";

		  std::cin >> selector;
		  switch (selector)
		  {
		  case 1:
			   registrar();
			   break;

		  case 2:
			   for (int x = 0; x < regisActual;x++) {
					cout << arreglo[x].getId() << " " << arreglo[x].getNombre() << " " << arreglo[x].getTelefono() << " " << arreglo[x].getBarbero() << " " << arreglo[x].getFecha() << " " << arreglo[x].getHora() << " " << arreglo[x].getTipo() << "\n";
			   }
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
		  std::cout << "\n";
	 }
}