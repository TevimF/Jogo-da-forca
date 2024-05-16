#pragma once

#include "main.hpp"
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

void salvar_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open(ENDERECO_ARQUIVO);
    if (!arquivo.is_open()){
        cout << "Arquivo não foi aberto!" << endl;
        exit(0);
    }
    arquivo << nova_lista.size() << endl;
    for (string palavra : nova_lista){
        arquivo << palavra << endl;
    }
    cout << "Nova palavra adicionada ao banco de palavras." << endl;
    arquivo.close();
}

vector<string> ler_arquivo(){
    ifstream arquivo;
    arquivo.open(ENDERECO_ARQUIVO);
    if (!arquivo.is_open()){
        cout << "Arquivo não foi aberto!" << endl;
        exit(0);
    }
    int quantidade_de_palavras;
    arquivo >> quantidade_de_palavras;
    vector<string> palavras_do_arquivo;

    for (int i = 0; i < quantidade_de_palavras; i++){
        string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    arquivo.close();
    if (palavras_do_arquivo.size() == 0){
        cout << "Banco de palavras vazio!" << endl;
        exit(0);
    }
    return palavras_do_arquivo;
}

void sorteia_palavra(){
    vector<string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}


void adiciona_palavra(){
    cout << "Digite a nova palavra MAIUSCULA sem espaços e acentos:" << endl;
    string nova_palavra;
    cin >> nova_palavra;
    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);
    salvar_arquivo(lista_palavras);
}

