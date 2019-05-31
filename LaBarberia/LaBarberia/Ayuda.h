#pragma once
#include <string>
#include <iostream>
using namespace std;

class Ayuda {
	 public:
		  // pido
		  string Fecha, Hora;
		  int mes, dia; // retorno de fecha
		  int hora,minuto;

		  Ayuda(string fecha,string hora) {
			   Fecha = fecha;
			   Hora = hora;

		  }

		  void setFecha(string fecha);
		  void setHora(string hora);
};

void Ayuda::setFecha(string sFecha) {
	 //formato fecha MM:DD
	 string tmp;
	 for (int x = 0; x < sizeof(sFecha); x++) {
		  if (sFecha[x] != '/') {
			   tmp += sFecha[x];
		  }
		  else {
			   mes = std::stoi(tmp);
			   tmp = "";
		  }
	 }
			   dia = std::stoi(tmp);
}

void Ayuda::setHora(string sHora) {
	 //formato hora HH:MM
	 string tmp;
	 for (int x = 0; x < sizeof(sHora); x++) {
		  if (sHora[x] != ':') {
			   tmp += sHora[x];
		  }
		  else {
			   minuto = std::stoi(tmp);
			   tmp = "";
		  }
	 }
			   hora = std::stoi(tmp);
}


