#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Cita.h"
using namespace std;

int arrayIndex = 0;
string mystr;

cita arreglo[200];

void registrarArchivo() {
	 ofstream oFile("citas.txt");
	 if (oFile.is_open()) {
		  for (int x = 0; x < arrayIndex+1; x++) {
			   std::stringstream  ss;
			   ss << arreglo[x].getNombre() << " " << arreglo[x].getId() << " " << arreglo[x].getTelefono() << " " << arreglo[x].getBarbero() << " " << arreglo[x].getFecha() << " " << arreglo[x].getHora() << " " << arreglo[x].getTipo() << "\n";
			   std::string s = ss.str();
			   oFile << s;
		  }
		  oFile.close();
	 }
}

void addArreglo(cita Cita) {
	 if (arrayIndex < 200) {
		  arreglo[arrayIndex] = Cita;
		  registrarArchivo();
		  arrayIndex++;
	 } 
}
void registrarCita() {
	 std::stringstream sFecha;
	 std::stringstream sHora;
	 int selec, mes, dia, horas, minuto;
	 std::cout << "\n";
	 string nombre, telefono, barbero, fecha, hora;
	 std::cout << "Nombre:\n";
	 std::cin >> nombre;
	 std::cout << "\n";

	 std::cout << "Telefono:\n";
	 std::cin >> telefono;
	 std::cout << "\n";

	 std::cout << "Barbero: (A / B / C / D)\n";//Se necesitan poner los nombres de los barberos, no solo letras
	 //Requerimientos del profe (dichos en persona)
	 std::cin >> barbero;
	 std::cout << "\n";

	 /* std::cout << "Fecha: (DD-MM-AA)\n";
	 std::cin >> fecha;
	 std::cout << "\n";

	 std::cout << "Hora: (HH:MM)\n";
	 std::cin >> hora;
	 std::cout << "\n"; */
							//Nuevo modelo de ingresar fecha y hora
	 std::cout<<"Ingresar la fecha: \n";
	 loopMes:
	 std::cout<<"Ingresar Mes: \n";
	 std::cin>>mes;
		if(mes>12&&mes<1){
			std::cout<<"Por favor recuerda que un mes solo puede tener 12 meses. \n";
			goto loopMes;
		}
		if(mes>0||mes<13){
			goto loopDia;
		}	
		
	 loopDia:
	 std::cout<<"Ingresar dia: \n";
	 std::cin>>dia;
	 if(mes==2&&dia>28){
		 std::cout<<"Febrero solo tiene 28 dias, por favor ingresa nuevamente el dia. \n";
		 goto loopDia;
	 }
	 if(dia<1||dia>31){
		 std::cout<<"Por favor intenta nuevamente. \n";
		 goto loopDia;
	 }
	 if(dia>0||dia<32){
		 sFecha<<mes+"/"+dia;
	 	fecha=sFecha.str();
	 	goto loopHora;
	 }
		/* else{
			std::cout<<"Por favor intenta nuevamente. \n";
			goto loopDia;
		} */
		
	 loopHora:
	 std::cout<<"Ingresar hora: \n";
	 std::cin>>horas;
	 if(horas<8||horas>20){
	 std::cout<<"Por favor captura a una hora que estemos abiertos. \n";
	 goto loopHora;
	 }
	 if(horas>7||horas<20){
		 goto loopMinuto;
	 }
	 /* else{
		 goto loopHora;
	 } */
	 
	 loopMinuto:
	 std::cout<<"Ingresar minuto: \n";
	 std::cin>>minuto;
	 if(minuto<0||minuto>59){
		 std::cout<<"Por favor recuerda que una hora solo tiene 60 minutos \n";
	 goto loopMinuto;
	}
	if(minuto>0||minuto<60){
		sHora<<horas+":"+minuto;
	 	hora=sHora.str();
	}
	/* else{
		std::cout<<"Por favor recuerda que una hora solo tiene 60 minutos \n";
		goto loopMinuto;
	} */
	//fin nuevo modelo
	 cita newCita(std::to_string(arrayIndex), nombre, telefono, barbero, fecha, hora);
     addArreglo(newCita);
}

void verCita() {
	 if (arrayIndex == 0) {
		  std::cout << "No tienes citas programadas...\n";
	 }
	 else {
		  std:cout << "\n";
		  for (int y = 0; y < arrayIndex+1; y++) {
			   if (arreglo[y].getTipo() == "0")
					std::cout << arreglo[y].getId() << " " << arreglo[y].getNombre() << " " << arreglo[y].getTelefono() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getFecha() << " " << arreglo[y].getHora() << " " << "\n";
		  }
					std::cout << "\n";
	 }
}

void registrarFila() {
	 int selec;
	 std::cout << "\n";

	 string nombre, fecha;
	 std::cout << "Nombre:\n";
	 std::cin >> nombre;
	 std::cout << "\n";

	 std::cout << "FechaActual:\n";
	 std::cin >> fecha;
	 std:cout << "\n";
	 cita newCita(std::to_string(arrayIndex), nombre, fecha);
	 
	 if (arrayIndex < 200) {
		  addArreglo(newCita);
		  arrayIndex++;
	 }
	 else {
		  std::cout << "Citas llenas...\n";
	 }
}

void verFila() {
	 if (arrayIndex == 0) {
		  cout << "No tienes filas programadas...\n";
	 }
	 else {
		  std:cout << "\n";
		  for (int y = 0; y < arrayIndex+1; y++) {
			   if (arreglo[y].getTipo() == "1")
					std::cout << arreglo[y].getNombre() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getHora() << " " << "\n";
		  }
					std::cout << "\n";
	 }
}


void IniciarArchivo() {
	 ifstream iFile("citas.txt");
	 if (iFile.fail()) {
		  std::ofstream oFile("citas.txt");
		  oFile.close();
	 }
	 else {
		  ifstream iFile("citas.txt");
		  if (iFile.is_open()) {
			   string cad;
			   while (getline(iFile, cad)) {
					stringstream ss(cad);
					int c = 0;
					string w;
					cita tmp;

					while (ss >> w) {
						 switch (c) {

						 case 0:
							  tmp.setNombre(w);
							  break;

						 case 1:
							  tmp.setId(w);
							  break;

						 case 2:
							  tmp.setTelefono(w);
							  break;

						 case 3:
							  tmp.setBarbero(w);
							  break;

						 case 4:
							  tmp.setFecha(w);
							  break;

						 case 5:
							  tmp.setHora(w);
							  break;

						 case 6:
							  tmp.setTipo(w);
						 }

						 c++;
					}
					addArreglo(tmp);
			   }
			   iFile.close();
		  }

	 }
}

int main()
{
	 IniciarArchivo();
	 bool repetir = true;
	 while (repetir)
	 {
		  int selector;
		  std::cout << "Bienvenido a la Barberia!\n";
		  std::cout<<"Puedes elegir estas opciones: \n";
		  std::cout <<"1) Citas\n2) Fila\n3) Salir\n";
		  std::cout<<"Que deseas hacer?\n";
		  std::cin >> selector;
		  switch (selector)
		  {
		  case 1:
			   std::cout << "1) Crear citas\n2) Ver citas\n";
			   std::cin >> selector;
			   if (selector == 1) {
					registrarCita();
					break;
			   }
			   else {
					verCita();
					break;
			   }
	
	 	  case 2:
			   std::cout << "1) Crear filas\n2) Ver filas\n";
			   std::cin >> selector;
			   if (selector == 1) {
					registrarFila();
					break;
			   }
			   else {
					verFila();
					break;
			   }

		  case 3:
		  default:
		  		std::cout<<"Estas seguro que deseas salir?";
				std::cin>>mystr;
				if(mystr=="si"||mystr=="Si"||mystr=="SI"||mystr=="s"){
			   		repetir = false;
					std::cout << "Adios! :D \n";
				}
			   break;
		  }
	 }
}