#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Diagnostico.h"

using namespace std;

int main () {
    Diagnostico* diagnostico = new Diagnostico();
	diagnostico->le_arquivo_candidatos("candidatos.csv");
    diagnostico->le_arquivo_partidos("partidos.csv");
    diagnostico->set_partidos_candidatos();
    diagnostico->print_questao_1();
    diagnostico->candidatos_eleitos();  
    // PRECISA DA ORDENAÇÃO PRA FUNCIONAR DIREITO
    diagnostico->candidatos_mais_votados();
    // PRECISA DA ORDENAÇÃO PRA FUNCIONAR DIREITO
    diagnostico->candidatos_nao_eleitos();
    diagnostico->nao_deviam_ser_eleitos();
    diagnostico->votos_totais_e_num_eleitos();
    
}