#include "Partido.h"
#include <cstdio>

Partido::Partido(int numero_partido, int votos_legenda,const string& nome_partido,const string& sigla_partido){
    this->numero_partido = numero_partido;
	this->votos_legenda = votos_legenda;
	this->nome_partido = nome_partido;
	this->sigla_partido = sigla_partido;
	this->qtd_eleitos = 0;
}

int Partido::get_numero_partido() const{
	return this->numero_partido;
}

string Partido::get_sigla() const{
	return this->sigla_partido;
}

void Partido::print() const{
	cout << this->nome_partido << endl;
}