#include <string>
#include <iostream>
#include <list>
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
    //Partido partido;
    int idade;

    public:
        Candidato(int numero, int votos_nominais,string situacao, string nome, string nome_urna, char sexo, string data_nasc,string destino_voto, int numero_partido);

        /* int eleito();
        void set_partido(list<Partido> partidos);
        //void calcula_idade(LocalDate data_eleicao);
        //LocalDate get_data_nasc() const;
        Partido get_partido();
        int get_numero() const;
        int get_idade() const;
        int get_votos_nominais() const;
        string get_situacao() const;
        string get_nome() const;
        string get_nome_urna() const;
        char get_sexo() const;
        string get_destino_voto() const;
        int get_numero_partido() const;*/

        void print() const;
        
        //~Candidato();
};