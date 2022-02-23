#include <string>
#include <iostream>
#include <list>
using namespace std;

class Partido{
    int numero_partido;
    int votos_legenda;
    string nome_partido;
    string sigla_partido;
    int qtd_votos;
    int qtd_eleitos;
    //list<Candidato> candidatos_part;

    public:
        Partido(int numero_partido, int votos_legenda, string nome_partido, string sigla_partido);

        /*void set_candidatos(list<Candidato> candidato);

        int votos_totais();
        int numero_de_eleitos() const;
        double calcula_porcentagem(int totais, int part) const;
        list<Candidato> get_candidatos() const;
        int get_votos_legenda() const;
        int get_numero_partido() const;
        string get_sigla_partido() const;
        string get_nome_partido() const;
        int get_qtd_votos() const;
        int get_qtd_eleitos() const;
        void set_qtd_votos(int qtd);

        void print() const;

        ~Partido();*/
};