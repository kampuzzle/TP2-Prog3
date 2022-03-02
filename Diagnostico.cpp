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
            c->print();
        }
    }
}

void Diagnostico::candidatos_mais_votados(){
    int vagas = num_vagas();
    int contador = 0;

    for(auto c: this->candidatos){
        if(contador < vagas){
            cout << contador + 1 << " - ";
            c->print();
        }
        contador++;
    }
}

void Diagnostico::candidatos_nao_eleitos(){
    int vagas = num_vagas();
    int contador = 0;

    cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;

    for(auto c: this->candidatos){
        if(contador < vagas){
            if(c->eleito() == 1){
                cout << contador + 1 << " - ";
                c->print();
            }          
        }
        contador++;
    }
}

void Diagnostico::nao_deviam_ser_eleitos(){
    int vagas = num_vagas();
    int contador = 0;

    cout << "\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;

    for(auto c: this->candidatos){
        if(contador < vagas){
        
        }else{
            if(c->eleito() == 1){
                cout << contador+1 << " - ";
                c->print();
            }
        }
        contador++;
    }
}