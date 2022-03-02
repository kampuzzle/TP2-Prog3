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

    //Candidato c1(1,1,"ok","amanda","ama",'f',"20/06/2002","aba",2);
    //c1.print();
}