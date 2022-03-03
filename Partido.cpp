#include "Partido.h"
#include <cstdio>

Partido::Partido(int numero_partido, int votos_legenda,const string& nome_partido,const string& sigla_partido){
    this->numero_partido = numero_partido;
	this->votos_legenda = votos_legenda;
	this->nome_partido = nome_partido;
	this->sigla_partido = sigla_partido;
	this->qtd_eleitos = 0;
}

void Partido::set_candidatos( const vector<Candidato*>& candidatos){
	vector<Candidato*> candidatos_do_partido;

	for(auto c: candidatos){
		if(c->get_numero_partido() == numero_partido){
			candidatos_do_partido.push_back(c);
		}
	}

	candidatos_part = candidatos_do_partido;
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

void Partido::numero_de_eleitos(){
	for(auto c: candidatos_part){
		if(c->eleito() == 1){
			qtd_eleitos++;
		}
	}
}

double Partido::calcula_porcentagem(int votos1,int votos2)const{
	return (double)votos2 * 100 / votos1;

}