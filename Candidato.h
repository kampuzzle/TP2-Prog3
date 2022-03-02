#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include <iostream>
#include <list>
#include "Partido.h"
using namespace std;

class Partido;//forward declaration

class Candidato{
    int numero;
    int votos_nominais;
    string situacao;
    string nome;
    string nome_urna;
    char sexo;
    //local date data_nasc;
    string destino_voto;
    int numero_partido;
    Partido* partido;
    int idade;

    public:
        Candidato(int numero, int votos_nominais,const string& situacao,const string& nome,const string& nome_urna, char sexo,const string& data_nasc,const string& destino_voto, int numero_partido);

        int eleito();
        void set_partido(list<Partido> partidos);
        //void calcula_idade(LocalDate data_eleicao);
        //LocalDate get_data_nasc() const;
        /*Partido* get_partido();
        int get_numero() const;
        int get_idade() const;
        int get_votos_nominais() const;
        const string& get_situacao() const;
        const string& get_nome() const;
        const string& get_nome_urna() const;
        char get_sexo() const;
        const string& get_destino_voto() const;
        int get_numero_partido() const;*/

        void print() const;
        
        //~Candidato();
};

#endif