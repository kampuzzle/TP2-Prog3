#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
#include <vector>
#include "Partido.h"
#include "Candidato.h"
#include "StringUtils.h"

class Partido;
class Candidato;

class Diagnostico{
    vector<Partido*> partidos;
    vector<Candidato*> candidatos;
    //data

public:
    
    Diagnostico();
    //leitura dos arquivos q era pra ser em verificacoes mas n sei como eh
    //utility class em c++
    void le_arquivo_candidatos(string file); 
    void le_arquivo_partidos(string file); 
    void set_partidos_candidatos();
    int num_vagas();
    void print_questao_1();
    void candidatos_eleitos();
    void candidatos_mais_votados();
    void candidatos_nao_eleitos();
    void nao_deviam_ser_eleitos();
    //~Diagnostico(); 
};

#endif