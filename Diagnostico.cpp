#include "Diagnostico.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Tokenizer.h"
#include "NumberUtils.h"

using namespace cpp_util;

Diagnostico::Diagnostico(const string& data){
    this->data = parseDate(data,DATE_FORMAT_PT_BR_SHORT);
};

void Diagnostico::le_arquivo_candidatos(string file){    
    ifstream in(file);
	string linha;
    getline(in, linha);

	while (getline(in, linha)) { // lendo a linha do arquivo
        Tokenizer tok2(linha, ',');
	    vector<string> vec = tok2.remaining();

        if(vec[7].compare("Válido") == 0){
            Candidato* candidato = new Candidato(stoi(vec[0]),stoi(vec[1]),vec[2],vec[3],vec[4],vec[5][0],vec[6],vec[7],stoi(vec[8]));
            candidatos.push_back(candidato);
        }
    }

	in.close();
}

void Diagnostico::le_arquivo_partidos(string file){    
    ifstream in(file);
	string linha;
    getline(in, linha);

	while (getline(in, linha)) { // lendo a linha do arquivo
        Tokenizer tok2(linha, ',');
	    vector<string> vec = tok2.remaining();

        Partido* partido = new Partido(stoi(vec[0]),stoi(vec[1]),vec[2],vec[3]);
        partidos.push_back(partido);
    }

	in.close();
}

void Diagnostico::set_partidos_candidatos(){
    for(auto c: this->candidatos){
        c->set_partido(this->partidos);
    }

    for(auto p: this->partidos){
        p->set_candidatos(this->candidatos);
        p->numero_de_eleitos();
    }

}

void Diagnostico::set_idades(){
    for(auto c:candidatos){
        c->calcula_idade(data);  
    }
}

int Diagnostico::num_vagas(){
    int vagas=0;
    for(auto c: this->candidatos){
        if(c->eleito() == 1){
            vagas++;
        }
    }

    return vagas;
}

void Diagnostico::print_questao_1(){
    cout << "Número de vagas: " << num_vagas() << endl << endl;
}

void Diagnostico::candidatos_eleitos(){
    cout << "Vereadores eleitos:" << endl;
    int i = 1;

    //ordenacao
    sort(candidatos.begin(),candidatos.end(),ordenaCandidato1);

    for(auto c: this->candidatos){
        if(c->eleito() == 1){
            cout << i << " - ";
            c->print();
            i++;
        }
    }
}

void Diagnostico::candidatos_mais_votados(){
    int vagas = num_vagas();
    int contador = 0;

    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    for(auto c: this->candidatos){
        if(contador < vagas){
            cout << contador + 1 << " - ";
            c->print();
        }
        contador++;
    }
}

void Diagnostico::candidatos_nao_eleitos(){
    int vagas = num_vagas();
    int contador = 0;

    cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;

    for(auto c: this->candidatos){
        if(contador < vagas){
            if(c->eleito() == 1){
                cout << contador + 1 << " - ";
                c->print();
            }          
        }
        contador++;
    }
}

void Diagnostico::nao_deviam_ser_eleitos(){
    int vagas = num_vagas();
    int contador = 0;

    cout << "\nEleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;

    for(auto c: this->candidatos){
        if(contador < vagas){
        
        }else{
            if(c->eleito() == 1){
                cout << contador+1 << " - ";
                c->print();
            }
        }
        contador++;
    }
}

void Diagnostico::votos_totais_e_num_eleitos(){
    cout << "\nVotação dos partidos e número de candidatos eleitos:" << endl;

    int contador = 1;

    for(auto p: this->partidos){
        p->votos_totais();
    }

    //ordenacao
    sort(partidos.begin(),partidos.end(),ordenaPartido1);

    for(auto p: this->partidos){
        cout << contador << " - ";
        contador++;
        p->print();

        if(p->get_qtd_votos() <= 1){
            cout << p->get_qtd_votos() << " voto (";
        }else{
            cout << p->get_qtd_votos() << " votos (";
        }

        if(p->get_qtd_votos() - p->get_votos_legenda() <= 1){
            cout << p->get_qtd_votos() - p->get_votos_legenda() << " nominal e ";
        }else{
            cout << p->get_qtd_votos() - p->get_votos_legenda() << " nominais e ";
        }

        cout << p->get_votos_legenda() << " de legenda), ";
        cout << p->get_qtd_eleitos();

        if(p->get_qtd_eleitos() <= 1){
            cout << " candidato eleito" << endl;
        }else{
            cout << " candidatos eleitos" << endl;
        }
    }
}

void Diagnostico::votos_legenda(){
    cout <<"\nVotação dos partidos (apenas votos de legenda):" << endl;
    
    //ordenacao

    int contador = 1;
    for(auto p: partidos){
        cout << contador << " - ";
        contador++;
        p->print();

        if(p->get_votos_legenda() == 0 || p->get_votos_legenda() == 1){
            cout << p->get_votos_legenda() << " voto de legenda (";    
        }else{
            cout << p->get_votos_legenda() << " votos de legenda (";
        }

        if(p->get_votos_legenda() == 0){
            cout << "proporção não calculada, 0 voto no partido)";
        } else{
            precisao_double(p->calcula_porcentagem(p->get_qtd_votos(), p->get_votos_legenda()));
            cout << "% do total do partido)" << endl;
        }
    }
}

double Diagnostico::calcula_porc(int v1,int v2){
    return (double)v2 *100/v1;
}

void Diagnostico::eleitos_por_idade(){
    cout <<"\nEleitos, por faixa etária (na data da eleição):" << endl;
    int idade;
	int menor30=0, menor40=0, menor50=0, menor60=0, maior60=0;
		
    //para cada candidato em candidatos, se ele for eleito, chama uma função para pegar a idade do candidato e, de acordo com a faixa etaria, iterar
    //um dos contadores
	for(auto c: candidatos){
		if(c->get_situacao().compare("Eleito") == 0){
			idade = c->get_idade();
			if(idade < 30){
				menor30++;
			}else if(30 <= idade && idade < 40){
				menor40++;
			}else if(40 <= idade && idade < 50){
				menor50++;
			}else if(50 <= idade && idade < 60){
				menor60++;
			}else{
				maior60++;
			}
		}
	}

    //calcula a porcentagem de cada faixa etaria chamando a funcao calcula_porc
    double porc = calcula_porc(num_vagas(), menor30);
    cout <<"      Idade < 30: " << menor30 << " (";
	precisao_double(porc);

	porc = calcula_porc(num_vagas(), menor40);
	cout << "%)\n30 <= Idade < 40: " << menor40 << " (";
	precisao_double(porc);

	porc = calcula_porc(num_vagas(), menor50);
	cout << "%)\n40 <= Idade < 50: " << menor50 << " (";
	precisao_double(porc);

	porc = calcula_porc(num_vagas(), menor60);
	cout << "%)\n50 <= Idade < 60: " << menor60 << " (";
	precisao_double(porc);

	porc = calcula_porc(num_vagas(), maior60);
	cout << "%)\n60 <= Idade     : " << maior60 << " (";
	precisao_double(porc);
	cout << "%)" << endl;
}

void Diagnostico::eleitos_por_sexo(){
    int m = 0, f = 0;
    for(auto c: candidatos){
        if(c->eleito() == 1){
            if(c->get_sexo() == 'M'){
                m++;
            }else{
                f++;
            }
        }
    }

    //double porc_fem = Verificacoes.calcula_porc(m+f, f);
    double porc_fem = (double)f * 100 / (m+f);
    double porc_masc = 100 - porc_fem;

    cout << "\nEleitos, por sexo:" << endl;
	cout << "Feminino:  " << f << " (";
	precisao_double(porc_fem);
	cout <<"%)" << endl;
	cout << "Masculino: " << m << " (";
	precisao_double(porc_masc);
	cout << "%)\n" << endl;
}

void Diagnostico::total_votos_validos(){
    int total_votos=0;
	int total_nominais=0;
	int total_legenda=0;

    //para cada partido, soma os todos os votos nominais e de legenda
	for(auto p: partidos){
		total_nominais += p->get_qtd_votos() - p->get_votos_legenda();
		total_legenda += p->get_votos_legenda();
	}

    //calcula o total de votos somando os votos nominais e de legenda
	total_votos = total_nominais + total_legenda;

	double porcentagemNominais=0, porcentagemLegenda=0;

    // calcula a porcentagem de votos nominais e de legenda
    porcentagemNominais = (double)total_nominais*100 /total_votos;
	porcentagemLegenda = 100 - porcentagemNominais;

	cout << "Total de votos válidos:    " << total_votos << endl;
	cout << "Total de votos nominais:   " << total_nominais << " (";
	precisao_double(porcentagemNominais);
	cout << "%)\nTotal de votos de legenda: " << total_legenda << " (";
	precisao_double(porcentagemLegenda);
	cout << "%)" << endl;

}

void Diagnostico::precisao_double(double num){
    // Create an output string stream
    ostringstream streamObj3;
    // Set Fixed -Point Notation
    streamObj3 << std::fixed;
    // Set precision to 2 digits
    streamObj3 << std::setprecision(2);
    //Add double to stream
    streamObj3 << num;
    // Get string from output string stream
    string formatada = streamObj3.str();

    int i=0,j=0;
    while(1){
        if( j != 0){
            j++;
        }
        if(formatada[i]=='.'){
            j++;
            cout << ',';
        } else {
            cout << formatada[i];
        }
        i++;
        if(j == 3){
            break;
        }
    }

}

Diagnostico::~Diagnostico(){
    for (auto c:candidatos){
        delete c;
    }

    for (auto p:partidos){
        delete p;
    }
}