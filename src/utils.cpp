#include <iostream>
#include <map>
#include <vector>

#include "../include/utils.hpp"
#include "../include/game.hpp"
#include "../include/arquivo.hpp"
using namespace std;

extern map<char, bool> chutou;
extern vector<char> chutes_errados;
extern string palavra_secreta;

void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros(){
    cout << "Chutes errados: ";
    for(char letra: chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout << "_ ";
        }
    }
    cout << endl;
}


