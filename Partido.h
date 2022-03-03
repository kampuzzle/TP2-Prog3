#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include <iostream>
#include <vector>
#include "Candidato.h"
using namespace std;

class Candidato;//forward declaration

class Partido{
    int numero_partido;
    int votos_legenda;
    string nome_partido;
    string sigla_partido;
    int qtd_votos;
    int qtd_eleitos;
    vector<Candidato*> candidatos_part;

    public:
        Partido(int numero_partido, int votos_legenda,const string& nome_partido, const string& sigla_partido);
        
        void set_candidatos(const vector<Candidato*>& candidatos);
        int get_numero_partido() const;
        int get_qtd_votos() const;
        int get_votos_legenda() const;
        int get_qtd_eleitos() const;
        int get_num_eleitos() const;
        string get_sigla() const;
        void print() const;
        int votos_totais();
        void numero_de_eleitos();
        double calcula_porcentagem(int votos1,int votos2)const;
        /*
        double calcula_porcentagem(int totais, int part) const;
        ??? vector<Candidato*> get_candidatos() const;
        const string& get_sigla_partido() const;
        const string& get_nome_partido()const;  
        void set_qtd_votos(int qtd);
        ~Partido();*/
};

#endif