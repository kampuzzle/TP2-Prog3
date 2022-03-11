#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Diagnostico.h"

using namespace std;

int main (int argc, char* argv[]) {
    Diagnostico* diagnostico = new Diagnostico("15/11/2020");
	diagnostico->le_arquivo_candidatos("candidatos.csv");
    diagnostico->le_arquivo_partidos("partidos.csv");

    /*Diagnostico* diagnostico = new Diagnostico(argv[3]);
	diagnostico->le_arquivo_candidatos(argv[1]);
    diagnostico->le_arquivo_partidos(argv[2]);*/

    diagnostico->set_partidos_candidatos();
    diagnostico->set_idades();

    diagnostico->print_questao_1();
    diagnostico->candidatos_eleitos();  
    diagnostico->candidatos_mais_votados();
    diagnostico->candidatos_nao_eleitos();
    diagnostico->nao_deviam_ser_eleitos();
    diagnostico->votos_totais_e_num_eleitos();
    diagnostico->votos_legenda();
    diagnostico->mais_e_menos_votados();
    diagnostico->eleitos_por_idade();
    diagnostico->eleitos_por_sexo();
    diagnostico->total_votos_validos();

    delete diagnostico;
}