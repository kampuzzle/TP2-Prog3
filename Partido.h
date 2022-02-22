#include <string>
#include <iostream>
using namespace std;

class Partido{
    int numero_partido;
    int votos_legenda;
    string nome_partido;
    string sigla_partido;
    int qtd_votos;
    int qtd_eleitos;
    //lista de candidatos

    public:
        Partido(int numero_partido, int votos_legenda, string nome_partido, string sigla_partido);

        //função de set candidatos

        int votos_totais(){
            int votos = 0;

            
        }

};