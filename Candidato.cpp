#include "Candidato.h"
#include "Tokenizer.h"

Candidato::Candidato(int numero, int votos_nominais,const string& situacao,const string& nome,const string& nome_urna, char sexo,const string& data_nasc,const string& destino_voto, int numero_partido){
    this->numero = numero;
	this->votos_nominais = votos_nominais;
	this->situacao = situacao;
	this->nome = nome;
	this->nome_urna = nome_urna;
	this->sexo = sexo;
	this->data_nasc = parseDate(data_nasc,DATE_FORMAT_PT_BR_SHORT);
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
	for(auto p: partidos){
	 	if(this->numero_partido == p->get_numero_partido()){
	 		this->partido = p;
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

int Candidato::get_votos_nominais() const{
	return this->votos_nominais;
}

int Candidato::get_numero_partido() const{
	return this->numero_partido;
}

const string& Candidato::get_situacao() const{
	return this->situacao;
}

char Candidato::get_sexo() const{
	return this->sexo;
}

time_t Candidato::get_data_nasc()const{
	return this->data_nasc;
}

int Candidato::age(int pd, int pm, int py,int bd, int bm, int by){
	int m, y;
	y = py - by;

	if (pm < bm){
    	y--;
    	m = 12 - (bm - pm);       
  	} else{
		m = pm - bm;
  	}

  	if (pd < bd){
    	m--;
  	}
  	return y;
}

void Candidato::calcula_idade(time_t dataEleicao){
	string dataNasc = formatDate(data_nasc,DATE_FORMAT_PT_BR_SHORT);
	Tokenizer tok2(dataNasc, '/');
	vector<string> nasc = tok2.remaining();

	string data_eleicao = formatDate(dataEleicao,DATE_FORMAT_PT_BR_SHORT);
	Tokenizer tok3(data_eleicao, '/');
	vector<string> eleicao = tok3.remaining();
	
	idade = this->age(stoi(eleicao[0]),stoi(eleicao[1]),stoi(eleicao[2]),stoi(nasc[0]),stoi(nasc[1]),stoi(nasc[2]));
}

int Candidato::get_idade()const{
	return this->idade;
}

Partido* Candidato::get_partido()const{
	return partido;
}

const string& Candidato::get_nome_urna()const{
	return nome_urna;
}

int Candidato::get_numero()const{
	return numero;
}

bool ordenaCandidato1(Candidato *c1,Candidato *c2){
	int dif = c1->get_votos_nominais() - c2->get_votos_nominais();

	if(dif == 0){
		dif = difftime(c1->get_data_nasc(),c2->get_data_nasc());
		if(dif < 0){
			return true;
		}
		return false;
	}

	if(dif < 0 ){
		return false;
	}
	return true;
}

bool ordenaCandidato2(Candidato* c1, Candidato *c2){
	int dif = c1->get_votos_nominais() - c2->get_votos_nominais();

	if(dif == 0){
		int numParti = c1->get_numero_partido() - c2->get_numero_partido();

		if(numParti != 0){
			if(c1->get_numero_partido() - c2->get_numero_partido() < 0){
				return true;
			}
			return false;
		}

		double diff = difftime(c1->get_data_nasc(),c2->get_data_nasc());

		if( diff < 0){
			return true;
		}
		return false;
	}

	if(dif < 0 ){
		return false;
	}
	return true;
}