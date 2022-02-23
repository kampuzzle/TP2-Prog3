#include "Candidato.h"

Candidato::Candidato(int numero, int votos_nominais,string situacao, string nome, string nome_urna, char sexo, string data_nasc,string destino_voto, int numero_partido){
    this->numero = numero;
	this->votos_nominais = votos_nominais;
	this->situacao = situacao;
	this->nome = nome;
	this->nome_urna = nome_urna;
	this->sexo = sexo;
	//String data [] = data_nasc.split("/");
	//this.data_nasc = LocalDate.of(Verificacoes.parse_int(data[2]),Verificacoes.parse_int(data[1]),Verificacoes.parse_int(data[0]));
	this->destino_voto = destino_voto;
	this->numero_partido = numero_partido;
}


void Candidato::print()const{
    //pegar sigla partido
    if(this->votos_nominais <= 1){
        cout << this->nome;
    }
}