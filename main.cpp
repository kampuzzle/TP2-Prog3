#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Candidato.h"
#include "Partido.h"
using namespace std;


void quebraLinha(const string& s) { // passando por referência e como const
    istringstream ss(s); // define um fluxo sobre a string
    string token;
    while (getline(ss, token, ','))
        cout << token << endl;
}

int main () {
	/*ifstream in("candidatos.csv");
	string linha;
    getline(in, linha);
	while (getline(in, linha)) { // lendo a linha do arquivo
        quebraLinha(linha);      // quebrar a linha em tokens separados por ' '
    }

	in.close();*/

    Candidato c1(1,1,"ok","amanda","ama",'f',"20/06/2002","aba",2);
    c1.print();
}