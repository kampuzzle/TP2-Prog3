#include "Candidato.h"

Candidato::Candidato(int numero, int votos_nominais,const string& situacao,const string& nome,const string& nome_urna, char sexo,const string& data_nasc,const string& destino_voto, int numero_partido){
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

int Candidato::eleito(){
	if(this->situacao.compare("Eleito") == 0){
		return 1;
	}
	return 0;
}

void Candidato::set_partido(vector<Partido*> partidos){
	// for(auto p: partidos){
	// 	if(this->numero_partido == p.get_numero_partido()){
	// 		this->partido = p;
	// 		this->partido->print();
	// 	}
	// }

	//COM WARNING
	for(int i = 0; i < partidos.size(); i++){
		if(this->numero_partido == partidos[i]->get_numero_partido()){
			this->partido = partidos[i];
		}
	}
}

void Candidato::print()const{
	string siglaPartido = this->partido->get_sigla();
		
	if(votos_nominais<=1){
		cout << nome << " / " << nome_urna << " (" << siglaPartido << ", " << votos_nominais << " voto)" << endl;
	}
	else{
		cout << nome << " / " << nome_urna << " (" << siglaPartido << ", " << votos_nominais << " votos)" << endl;
	}
}