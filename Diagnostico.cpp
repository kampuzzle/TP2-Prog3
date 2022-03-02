#include "Diagnostico.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Tokenizer.h"

using namespace cpp_util;

Diagnostico::Diagnostico(){};

void Diagnostico::le_arquivo_candidatos(string file){    
    ifstream in(file);
	string linha;
    getline(in, linha);

	while (getline(in, linha)) { // lendo a linha do arquivo
        Tokenizer tok2(linha, ',');
	    vector<string> vec = tok2.remaining();

        if(vec[7].compare("Válido") == 0){
            Candidato* candidato = new Candidato(stoi(vec[0]),stoi(vec[1]),vec[2],vec[3],vec[4],vec[5][0],vec[6],vec[7],stoi(vec[8]));
            candidatos.push_back(candidato);
        }
    }

	in.close();
}

void Diagnostico::le_arquivo_partidos(string file){    
    ifstream in(file);
	string linha;
    getline(in, linha);

	while (getline(in, linha)) { // lendo a linha do arquivo
        Tokenizer tok2(linha, ',');
	    vector<string> vec = tok2.remaining();

        Partido* partido = new Partido(stoi(vec[0]),stoi(vec[1]),vec[2],vec[3]);
        partidos.push_back(partido);
    }

	in.close();
}

void Diagnostico::set_partidos_candidatos(){
    for(auto c: this->candidatos){
        c->set_partido(this->partidos);
    }
}

int Diagnostico::num_vagas(){
    int vagas=0;
    for(auto c: this->candidatos){
        if(c->eleito() == 1){
            vagas++;
        }
    }

    return vagas;
}

void Diagnostico::print_questao_1(){
    cout << "Número de vagas: " << num_vagas() << endl;
}

void Diagnostico::candidatos_eleitos(){
    for(auto c: this->candidatos){
        if(c->eleito() == 1){
            
        }
    }
}