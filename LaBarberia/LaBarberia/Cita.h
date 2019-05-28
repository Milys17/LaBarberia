#pragma once
#include "pch.h"
#include <string>
using namespace std;

class cita {
public:
	 string id, nombre, telefono, barbero, fecha, hora, tipo;
	 
	 cita() {

	 }

	 cita(string Id, string Nombre, string Telefono, string Barbero, string Fecha, string Hora) {
		  id = Id;
		  nombre = Nombre;
		  telefono = Telefono;
		  barbero = Barbero;
		  fecha = Fecha;
		  hora = Hora;
		  tipo = "0";
	 }

	 cita(string Id, string Nombre, string Fecha) {
		  id = Id;
		  nombre = Nombre;
		  telefono = "x";
		  barbero = "x";
		  hora = "x";
		  fecha = Fecha;
		  tipo = "1";
	 }

	 void setId(string id);
	 string getId();

	 void setNombre(string nombre);
	 string getNombre();

	 void setTelefono(string telefono);
	 string getTelefono();

	 void setBarbero(string barbero);
	 string getBarbero();

	 void setFecha(string fecha);
	 string getFecha();

	 void setHora(string hora);
	 string getHora();

	 void setTipo(string tipo);
	 string getTipo();
};

void cita::setId(string sId) {
	 id = sId;
}

string cita::getId() {
	 return id;
}

void cita::setNombre(string sNom) {
	 nombre = sNom;
}

string cita::getNombre() {
	 return nombre;
}

void cita::setTelefono(string sTel) {
	 telefono = sTel;
}

string cita::getTelefono() {
	 return telefono;
}

void cita::setFecha(string sFecha) {
	 fecha = sFecha;
}

string cita::getFecha() {
	 return fecha;
}

void cita::setHora(string sHora) {
	 hora = sHora;
}

string cita::getHora() {
	 return hora;
}

void cita::setBarbero(string sBar) {
	 barbero = sBar;
}

string cita::getBarbero() {
	 return barbero;
}

void cita::setTipo(string sTipo) {
	 tipo = sTipo;
}

string cita::getTipo() {
	 return tipo;
}