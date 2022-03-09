#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
#include <vector>
#include "Partido.h"
#include "Candidato.h"
#include "StringUtils.h"
#include "DateUtils.h"
using namespace cpp_util;

class Partido;
class Candidato;

class Diagnostico{
    vector<Partido*> partidos;
    vector<Candidato*> candidatos;
    time_t data;

public:
    
    Diagnostico(const string& data);
    //leitura dos arquivos q era pra ser em verificacoes mas n sei como eh
    //utility class em c++
    void le_arquivo_candidatos(string file); 
    void le_arquivo_partidos(string file); 
    void set_partidos_candidatos();
    void set_idades();
    int num_vagas();
    void print_questao_1();
    void candidatos_eleitos()const;
    void candidatos_mais_votados();
    void candidatos_nao_eleitos();
    void nao_deviam_ser_eleitos();
    void votos_totais_e_num_eleitos()const;
    void votos_legenda();
    void eleitos_por_idade();
    void eleitos_por_sexo();
    void total_votos_validos();
    double calcula_porc(int v1,int v2);
    void precisao_double(double num);
    ~Diagnostico(); 
};

#endif