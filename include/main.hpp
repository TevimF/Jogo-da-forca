#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

string palavra_secreta = "MELANCIA"; 
map<char, bool> chutou;
vector<char> chutes_errados;
const string ENDERECO_ARQUIVO = "../palavras/palavras.txt";

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


