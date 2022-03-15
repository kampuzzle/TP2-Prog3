#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include <iostream>
#include <list>
#include "DateUtils.h"
#include "Partido.h"
#include "StringUtils.h"
using namespace std;
using namespace cpp_util;

class Partido;//forward declaration

class Candidato{
    int numero;
    int votos_nominais;
    string situacao;
    string nome;
    string nome_urna;
    char sexo;
    time_t data_nasc;
    string destino_voto;
    int numero_partido;
    Partido* partido;
    int idade;

    public:
        Candidato(int numero, int votos_nominais,const string& situacao,string& nome,string& nome_urna, char sexo,const string& data_nasc,const string& destino_voto, int numero_partido);

        int eleito();
        void set_partido(vector<Partido*> partidos);
        int get_votos_nominais() const;
        int get_numero_partido() const;
        const string& get_situacao() const;
        char get_sexo() const;
        time_t get_data_nasc()const;
        void calcula_idade(time_t dataEleicao);
        int age(int pd, int pm, int py,int bd, int bm, int by);
        int get_idade()const;
        Partido* get_partido()const;
        const string& get_nome_urna()const;
        int get_numero()const;
        void print() const;
        
};

string rtrim(const string &s);
bool ordenaCandidato1(Candidato *c1, Candidato *c2);
bool ordenaCandidato2(Candidato* c1, Candidato *c2);

#endif