#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Candidato.h"
#include "Partido.h"
#include "Tokenizer.h"

using namespace std;
using namespace cpp_util;

void quebraLinha(const string& s) { // passando por referência e como const
    istringstream ss(s); // define um fluxo sobre a string
    string token;
    while (getline(ss, token, ','))
        cout << token << endl;
}

int main () {
	ifstream in("candidatos.csv");
	string linha;
    getline(in, linha);
	while (getline(in, linha)) { // lendo a linha do arquivo
        //quebraLinha(linha);      // quebrar a linha em tokens separados por ' '
        Tokenizer tok2(linha, ',');
	    vector<string> vec = tok2.remaining();
	    cout << vec[0] <<endl;
        cout << vec[1] <<endl;
        cout << vec[2] <<endl;
        //for (string s : vec) cout << s << endl;
    }

	in.close();

    //Candidato c1(1,1,"ok","amanda","ama",'f',"20/06/2002","aba",2);
    //c1.print();
}