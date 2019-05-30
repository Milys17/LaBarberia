#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "Cita.h"
using namespace std;

int arrayIndex = 0;
string mystr;
string regexNombre = "^[A-Za-z/s]+$", regexTelefono = "^[0-9]+$", regexBarbero = "^[A-Da-d]$";

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

	 cout << "\n";
	 string nombre, telefono, barbero, fecha, hora;

loopNombre:
	 try {
		  cout << "Nombre:\n";
		  cin >> nombre;
		  std::regex r(regexNombre);
		  std::smatch m;
		  if (!(regex_search(nombre, m, r)))throw 'ex';
	 }
	 catch (...) {
		  cout << "\nFormato de nombre invalido\n";
		  goto loopNombre;
	 }

	 cout << "\n";

loopTelefono:
	 try {
		  cout << "Telefono:\n";
		  cin >> telefono;
		  std::regex r(regexTelefono);
		  std::smatch m;
		  if (!(regex_search(telefono, m, r)))throw 'ex';
	 }
	 catch (...) {
		  cout << "\nFormato de telefono invalido\n";
		  goto loopTelefono;
	 }
	 cout << "\n";

loopBarbero:
	 try {
			 cout << "Barbero:\nA) Antonio Rivera \nB) Andre Herrera \nC) Miriam Bonilla\nD) Jose Romo\n";
			 cin >> barbero;
			 std::regex r(regexBarbero);
			 std::smatch m;
			 if (!(regex_search(barbero, m, r))) throw 'ex';
			 switch (*barbero.c_str()) {
			 case 'a':
			 case 'A':
				 barbero = "Antonio_Rivera";
				 break;

			 case 'b':
			 case 'B':
				 barbero = "Andre_Herrera";
				 break;

			 case 'c':
			 case 'C':
				 barbero = "Miriam_Bonilla";
				 break;

			 case 'd':
			 case 'D':
				 barbero = "Jose_Romo";
				 break;
			 }
	 }
	 catch (...) {
		  cout << "\nFormato barbero invalido\n";
		  goto loopBarbero;
	 }
	 cout << "\n";

	  //Nuevo modelo de ingresar fecha y hora
	 cout << "Ingresar la fecha. \n";
	 loopMes:
	 cout<<"Ingresar Mes: \n";
	 while(!(cin>>mes)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor ingresa numeros solamente. \n";
			   goto loopMes;
	}
		if(mes>12||mes<1){
			cout<<"\nPor favor recuerda que un mes solo puede tener 12 meses. \n";
			goto loopMes;
		}		
	loopDia:
	cout<<"Ingresar dia: \n";
	while(!(cin>>dia)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor ingresa numeros solamente. \n";
			   goto loopDia;
	}
	 if(mes==2&&dia>28){
		 cout<<"\nFebrero solo tiene 28 dias, por favor ingresa nuevamente el dia. \n";
		 goto loopDia;
	 }
	 if(dia<1||dia>31){
		 cout<<"\nPor favor intenta nuevamente. \n";
		 goto loopDia;
	 }

		  	
	 loopHora:
	cout<<"Ingresar hora: \n";
	while(!(cin>>horas)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor ingresa numeros solamente. \n";
			   goto loopHora;
	}
	 if(horas<8||horas>20){
		  cout<<"Por favor captura a una hora que estemos abiertos. \n";
		  goto loopHora;
	 }
	 
	 loopMinuto:
	 cout<<"Ingresar minuto: \n";
	 while(!(cin>>minuto)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Por favor ingresa numeros solamente. \n";
			goto loopMinuto;
	}
	 if(minuto<0||minuto>59){
		 cout<<"\nPor favor recuerda que una hora solo tiene 60 minutos \n";
		 goto loopMinuto;
	 }
		sFecha << mes << "/" << dia;
		fecha = sFecha.str();
		sHora << horas << ":" << minuto;
	 	hora=sHora.str();
		 
	 cita newCita(to_string(arrayIndex), nombre, telefono, barbero, fecha, hora);
     addArreglo(newCita);
}

void verCita() {
	 if (arrayIndex == 0) {
		  cout << "No tienes citas programadas...\n";
	 }
	 else {
		  cout << "\n";
		  for (int y = 0; y < arrayIndex+1; y++) {
			   if (arreglo[y].getTipo() == "0")
					cout << arreglo[y].getId() << " " << arreglo[y].getNombre() << " " << arreglo[y].getTelefono() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getFecha() << " " << arreglo[y].getHora() << " " << "\n";
		  }
					cout << "\n";
	 }
}

void registrarFila() {
	 int selec;
	 cout << "\n";

	 string nombre;

loopNombre:
	 try {
		  cout << "Nombre:\n";
		  cin >> nombre;
		  std::regex r(regexNombre);
		  std::smatch m;
		  if (!(regex_search(nombre, m, r)))throw 'ex';
	 }
	 catch (...) {
		  cout << "\nFormato de nombre invalido\n";
		  goto loopNombre;
	 }

	 cout << "\n";

	 int mes, dia;
	 stringstream sFecha;
	 string fecha;

	 loopMes:
	 cout << "Ingresar la fecha: \n";
	 cout<<"Ingresar Mes: \n";
	 cin>>mes;
		if(mes>12&&mes<1){
			cout<<"Por favor recuerda que un mes solo puede tener 12 meses. \n";
			goto loopMes;
		}
		else {
			 goto loopDia;
		}
		
	 loopDia:
	 cout<<"Ingresar dia: \n";
	 cin>>dia;
	 if(mes==2&&dia>28){
		 cout<<"Febrero solo tiene 28 dias, por favor ingresa nuevamente el dia. \n";
		 goto loopDia;
	 }
	 if(dia<1||dia>31){
		 cout<<"Por favor intenta nuevamente. \n";
		 goto loopDia;
	 }
	 else {
		  sFecha << mes << "/" << dia;
		  fecha = sFecha.str();
	 }

	
	 cita newCita(std::to_string(arrayIndex), nombre, fecha);
	 addArreglo(newCita);
}

void verFila() {
	 if (arrayIndex == 0) {
		  cout << "No tienes filas programadas...\n";
	 }
	 else {
		  cout << "\n";
		  for (int y = 0; y < arrayIndex+1; y++) {
			   if (arreglo[y].getTipo() == "1")
					cout << arreglo[y].getNombre() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getHora() << " " << "\n";
		  }
					cout << "\n";
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
	 int selector;
	 while (repetir)
	 {
		  loopMenu:
		  cout << "Bienvenido a la Barberia!\n";
		  cout<<"Puedes elegir estas opciones: \n";
		  cout <<"1) Citas\n2) Fila\n3) Salir\n";
		  cout<<"Que deseas hacer?\n";

		  while(!(cin>>selector)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor elige una opcion valida. \n";
			   goto loopMenu;
		   }
		  switch (selector)
		  {
		  case 1:
			   cout << "1) Crear citas\n2) Ver citas\n";
			   cin >> selector;
			   if (selector == 1) {
					registrarCita();
					break;
			   }
			   else {
					verCita();
					break;
			   }
	
	 	  case 2:
			   cout << "1) Crear filas\n2) Ver filas\n";
			   cin >> selector;
			   if (selector == 1) {
					registrarFila();
					break;
			   }
			   else {
					verFila();
					break;
			   }

		  case 3:
		  		cout<<"Estas seguro que deseas salir?";
				cin>>mystr;
				if(mystr=="si"||mystr=="Si"||mystr=="SI"||mystr=="s"){
			   		repetir = false;
					cout << "Adios! :D \n";
				}
			   break;
			default:
			cout<<"Por favor escoge una opcion valida. \n";
			break;
		  }
	 }
}