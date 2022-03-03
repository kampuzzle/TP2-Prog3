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

int Partido::get_qtd_votos() const{
	return this->qtd_votos;
}

int Partido::get_votos_legenda() const{
	return this->votos_legenda;
}

int Partido::get_qtd_eleitos() const{
	return this->qtd_eleitos;
}

string Partido::get_sigla() const{
	return this->sigla_partido;
}

void Partido::print() const{
	cout << sigla_partido << " - " << numero_partido << ", ";
}

int Partido::votos_totais(){
	int votos = 0;

	for(auto c: this->candidatos_part){
		votos += c->get_votos_nominais();
	}
	votos += this->votos_legenda;
	this->qtd_votos = votos;

	return votos;
}