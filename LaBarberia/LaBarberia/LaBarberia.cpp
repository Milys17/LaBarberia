#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "Cita.h"
#include <stdlib.h>
#include <conio.h>
#include "Ayuda.h"
#include <ctime>
#include <time.h>


using namespace std;

int arrayIndex = 0;
string mystr;
string regexNombre = "^[A-Za-z/s]+$", regexTelefono = "^([0-9]{7}|[0-9]{10})$", regexBarbero = "^[A-Da-d]$", regexSelector= "^([1-3]{1})$";
const string barberoA = "Antonio_Rivera", barberoB = "Andre_Herrera", barberoC = "Miriam_Bonilla", barberoD = "Jose_Romo";
cita arreglo[200];

void registrarArchivo() {
	 ofstream oFile("citas.txt",std::ofstream::out);
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
		  std::cout << "Nombre:\n";
		  std::cin >> nombre;
		  if (nombre == "-1")return;
		  std::regex r(regexNombre);
		  std::smatch m;
		  if (!(regex_search(nombre, m, r)))throw 'ex';
	 }
	 catch (...) {
		  cout << "\nFormato de nombre invalido. \n";
		  goto loopNombre;
	 }

	 cout << "\n";

loopTelefono:
	 try {
		  cout << "Telefono:\n";
		  cin >> telefono;
		  if (telefono == "-1")return;
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
			 if (barbero == "-1")return;
			 std::regex r(regexBarbero);
			 std::smatch m;
			 if (!(regex_search(barbero, m, r))) throw 'ex';
			 switch (*barbero.c_str()) {
			 case 'a':
			 case 'A':
				 barbero = barberoA;
				 break;

			 case 'b':
			 case 'B':
				 barbero = barberoB;
				 break;

			 case 'c':
			 case 'C':
				 barbero = barberoC;
				 break;

			 case 'd':
			 case 'D':
				 barbero = barberoD;
				 break;
			 }
	 }
	 catch (...) {
		  cout << "\nFormato barbero invalido\n";
		  goto loopBarbero;
	 }
	 cout << "\n";

	 time_t now = time(0);
	 struct tm newTime;
	 localtime_s(&newTime, &now);

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
	 if (mes == -1)return;

		if(mes>12||mes<1){
			cout<<"\nPor favor recuerda que un mes solo puede tener 12 meses. \n";
			goto loopMes;
		}
		else {
			 int mesAct = newTime.tm_mon;
			 mesAct++;
			 if (mes < mesAct) {
				  cout << "\n Mes invalido, intente de nuevo\n";
				  goto loopMes;
			 }
		}

loopDia:
	cout<<"Ingresar dia: \n";
	while(!(cin>>dia)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor ingresa numeros solamente. \n";
			   goto loopDia;
	}

	if (dia == -1)return;
	
	if(mes==2&&dia>28){
		 cout<<"\nFebrero solo tiene 28 dias, por favor ingresa nuevamente el dia. \n";
		 goto loopDia;
	 }
	 if(dia<1||dia>31){
		 cout<<"\nPor favor intenta nuevamente. \n";
		 goto loopDia;
	 }
	 else {
		  if (mes <= ++newTime.tm_mon && dia < newTime.tm_mday) {
			   cout << "\nDia invalido\n";
			   goto loopDia;
		  }
	 }

		  	
loopHora:
	cout<<"Ingresar hora: \n";
	while(!(cin>>horas)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor ingresa numeros solamente. \n";
			   goto loopHora;
	}
	if (horas == -1)return;
	 if(horas<8||horas>20){
		  cout<<"Por favor captura a una hora que estemos abiertos. \n";
		  goto loopHora;
	 }
	 else {
		  if (dia == newTime.tm_mday && horas < newTime.tm_hour) {
			   cout << "\nHora invalida\n";
			   goto loopHora;
		  }
	 }
	 
loopMinuto:
	 cout<<"Ingresar minuto: \n";
	 while(!(cin>>minuto)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Por favor ingresa numeros solamente. \n";
			goto loopMinuto;
	}

	 if (minuto == -1)return;

	 if(minuto<0||minuto>59){
		 cout<<"\nPor favor recuerda que una hora solo tiene 60 minutos \n";
		 goto loopMinuto;
	 }
	 if(horas==20&&minuto>45){
		 cout<<"Tu cita no puede ser a a partir de las 8:45 p.m.\nNo podemos cerrar despues de las 9:00 p.m.\n";
		 cout<<"Por favor elige otra hora \n";
		 goto loopMinuto;
	 }
	 else {
		  if (dia == newTime.tm_mday && horas == newTime.tm_hour && minuto < newTime.tm_min) {
			   cout << "Tiempo invalido\n";
			   goto loopMinuto;
		  }

		  bool horaExistente = false;
		  string Hour;
		  int horaSegundos, minutoSegundos, Segundos, hs1, hs2, ms1, ms2;
		  int segundosPropuesta;
		  segundosPropuesta = horas * 3600 + minuto * 60;
		  for (int i = 0; i < arrayIndex + 1; i++) {
			   if (barbero == arreglo[i].getBarbero()) {
					if (fecha == arreglo[i].getFecha()) {
						 Hour = arreglo[i].getHora();
						 hs1 = Hour[0] - '0';
						 hs2 = Hour[1] - '0';
						 ms1 = Hour[3] - '0';
						 ms2 = Hour[4] - '0';
						 horaSegundos = (hs1 * 10 + hs2) * 3600;
						 minutoSegundos = (ms1 * 10 + ms2) * 60;
						 Segundos = horaSegundos + minutoSegundos;

						 if ((segundosPropuesta >= Segundos && segundosPropuesta < Segundos + 900) || (segundosPropuesta <= Segundos && segundosPropuesta + 900 > Segundos)) {
							  cout << "Esta hora no esta disponible, por favor escoja otra\n";
							  horaExistente = true;
							  break;
						 }
					}
			   }

		  }

		  if (!horaExistente) {
			   std::cout << "Su hora solicitada esta disponible\n";
			   if (horas < 10) {
					sHora << "0" << horas << ":" << minuto;
			   }
			   else if (minuto < 10) {
					sHora << horas << ":0" << minuto;
			   }
			   else if (horas < 10 && minuto < 10) {
					sHora << "0" << horas << ":0" << minuto;
			   }
			   else {
					sHora << horas << ":" << minuto;
			   }
			   hora = sHora.str();
		  }
		  else {
			   goto loopMes;
		  }

		  sFecha << mes << "/" << dia;
		  fecha = sFecha.str();

		  cita newCita(std::to_string(arrayIndex), nombre, telefono, barbero, fecha, hora);
		  addArreglo(newCita);
	 }
}

void verCita() {
		  bool reg = false;
		  cout << "\n";
		  for (int y = 0; y < arrayIndex + 1; y++) {
			   if (arreglo[y].getTipo() == "0") {
					cout << arreglo[y].getId() << " " << arreglo[y].getNombre() << " " << arreglo[y].getTelefono() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getFecha() << " " << arreglo[y].getHora() <<"\n";
					reg = true;
			   }
		  }
					if (!reg) cout << "No tienes citas programadas...\n";
					cout << "\n";
					cout<<"\nPresiona cualquier tecla para volver al menu principal. \n";
					_getch();
}

void registrarFila() {
	 int selec;
	 cout << "\n";
	 string nombre;

loopNombre:
	 try {
		  std::cout << "Nombre:\n";
		  std::cin >> nombre;
		  if (nombre == "-1")return;
		  std::regex r(regexNombre);
		  std::smatch m;
		  if (!(regex_search(nombre, m, r)))throw 'ex';
	 }
	 catch (...) {
		  cout << "\nFormato de nombre invalido\n";
		  goto loopNombre;
	 }

	 cout << "\n";

loopTime:
	 time_t now = time(0);
	 struct tm newTime;
	 localtime_s(&newTime, &now);

	 stringstream fechaAct, horaAct;
	 horaAct << newTime.tm_hour << ":" << newTime.tm_min;
	 fechaAct << newTime.tm_mday << "/" << ++newTime.tm_mon;

	 int hora = newTime.tm_hour, minuto = newTime.tm_min;

generarFila:

	 string Hour;
	 string BuscarCita,barbero;
	 int horaSegundos, minutoSegundos, Segundos, hs1, hs2, ms1, ms2;
	 int segundosPropuesta;
	 int barberoList = 0;

	 bool filaConfirmada = false;


	 while (!filaConfirmada) {
		  segundosPropuesta = hora * 3600 + minuto * 60;
		  filaConfirmada = true;
		  if (barberoList == 0) barbero = barberoA;
		  else if (barberoList == 1) barbero = barberoB;
		  else if (barberoList == 2) barbero = barberoC;
		  else if (barberoList == 3) barbero = barberoD;

		  for (int i = 0; i < arrayIndex; i++) {
			   if (barbero == arreglo[i].getBarbero()) {
					if (fechaAct.str() == arreglo[i].getFecha()) {
						 Hour = arreglo[i].getHora();
						 hs1 = Hour[0] - '0';
						 hs2 = Hour[1] - '0';
						 ms1 = Hour[3] - '0';
						 ms2 = Hour[4] - '0';
						 horaSegundos = (hs1 * 10 + hs2) * 3600;
						 minutoSegundos = (ms1 * 10 + ms2) * 60;
						 Segundos = horaSegundos + minutoSegundos;
						 if (
							  (segundosPropuesta >= Segundos && segundosPropuesta < Segundos + 900)
							  ||
							  (segundosPropuesta <= Segundos && segundosPropuesta + 900 > Segundos)
							  ) {
							  std::cout << "El barbero " << arreglo[i].getBarbero()
								   << " no esta disponible\n";
							  filaConfirmada = false;
							  barberoList++;
							  if (barberoList > 3) {
								   std::cout << "Ningun barbero puede atender a la hora\n";
								   std::cout << hora << ":" << minuto << "\n";
								   std::cout << "Desea continuar buscando cita? S= SI\n";
								   std::cin >> BuscarCita;
								   if (BuscarCita == "S") {
										barberoList = 0;
										minuto += 15;
										if (minuto >= 60) {
											 minuto -= 60;
											 hora++;
										}
								   }
								   else if (BuscarCita == "-1") return;
								   else {
										;
										break;
								   }
							  }
							  break;
						 }
					}
			   }
		  }

	 }

	 stringstream horaCita;
	 horaCita << hora << ":" << minuto;

	 cita newCita(std::to_string(arrayIndex), nombre, barbero, horaCita.str());
	 addArreglo(newCita);

	 cout << "Se registro una cita con el barbero " << barbero << " a las: " << hora << ":" << minuto;
}

void verFila() {
	 bool reg = false;
		  cout << "\n";
		  for (int y = 0; y < arrayIndex+1; y++) {
			   if (arreglo[y].getTipo() == "1") {
					cout << arreglo[y].getId() << " " << arreglo[y].getNombre() << " " << arreglo[y].getBarbero() << " " << arreglo[y].getHora() <<"\n";
					reg = true;
			   }
		  }
					if(!reg) cout << "No tienes clientes en fila...\n";
					cout << "\n";
					cout<<"\nPresiona cualquier tecla para volver al menu principal. \n";
					_getch();
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

int main(){
	system("color 0A");
	 IniciarArchivo();
	 bool repetir = true;
	 int selector, aux;
	 string selectorS;
	 while (repetir)
	 {
		 loopMenu:
		 system("cls");
		 cout << "Bienvenido a la Barberia!\n";
		 cout<<"Puedes elegir estas opciones: \n";
		 cout <<"1) Citas\n2) Fila\n3) Salir\n";
		 cout<<"Que deseas hacer?\n";
		 while(!(cin>>selectorS)){
			   cin.clear();
			   cin.ignore(1000,'\n');
			   cout<<"Por favor elige una opcion valida. \n";
				 _getch();
			   goto loopMenu;
		   }
			try{
		   		std::regex r(regexSelector);
		   		std::smatch m;
				if (!(regex_search(selectorS, m, r)))throw 'ex';
	 		}
			 catch (...) {
				cout<<"Por favor elige una opcion valida. \n";
				_getch();
		  		goto loopMenu;
	 		 }
			  std::istringstream(selectorS)>>selector;
		  switch (selector)
		  {
		  case 1:
		  		system("cls");
			    cout << "1) Crear citas\n2) Ver citas\n3)Presione cualquier tecla para salir\n";
			    cin >> selector;
				system("cls");
			    if (selector == 1) {
					registrarCita();
					break;
			   }
			   if(selector==2){
					verCita();
					break;
			   }
			   else
				   break;
	
	 	  case 2:
		    system("cls");
			cout << "1) Unirte a la fila\n2) Ver fila\n";
			cin >> selector;
			system("cls");
			if (selector == 1) {
				registrarFila();
				break;
			   }
			   if(selector==2){
				verFila();
				break;
			   }
			else 
				break;
			
		  case 3:
		  		system("cls");
		  		cout<<"Estas seguro que deseas salir?";
				cin>>mystr;
				if(mystr=="si"||mystr=="Si"||mystr=="SI"||mystr=="s"||mystr=="simon"||mystr=="S"){
			   		repetir = false;
					cout << "Adios! :D \n";
					_getch();
				}
			   break;
			default:
			cout<<"Por favor escoge una opcion valida. \n";
			break;
		  }
	 }
}