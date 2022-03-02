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
    //~Diagnostico(); 
};

#endif