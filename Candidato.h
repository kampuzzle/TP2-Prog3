#include <string>
#include <iostream>
#include <list>
#include <Partido.h>
using namespace std;

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
    Partido partido;
    int idade;

    public:
        Candidato(int numero, int votos_nominais,string situacao, string nome, string nome_urna, char sexo, string data_nasc,string destino_voto, int numero_partido);

        int eleito();
        void set_partido(list<Partido> partidos);
        
};