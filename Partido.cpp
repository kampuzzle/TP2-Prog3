#include "Partido.h"
#include <cstdio>

Partido::Partido(int numero_partido, int votos_legenda, string nome_partido, string sigla_partido){
    this->numero_partido = numero_partido;
	this->votos_legenda = votos_legenda;
	this->nome_partido = nome_partido;
	this->sigla_partido = sigla_partido;
	this->qtd_eleitos = 0;
}

