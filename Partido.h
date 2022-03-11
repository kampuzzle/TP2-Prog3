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
        vector<Candidato*> get_candidatos() const;
};

bool ordenaPartido1(Partido *p1,Partido *p2);
bool ordenaPartido2(Partido *p1,Partido *p2);

#endif