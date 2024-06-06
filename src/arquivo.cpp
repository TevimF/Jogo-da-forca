#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "../include/arquivo.hpp"


extern std::string palavra_secreta;

void salvar_arquivo(std::vector<std::string> nova_lista){
    std::ofstream arquivo;
    arquivo.open("palavras/palavras.txt");
    if (!arquivo.is_open()){
        std::cout << "Arquivo não foi aberto!" << std::endl;
        exit(0);
    }
    arquivo << nova_lista.size() << std::endl;
    for (std::string palavra : nova_lista){
        arquivo << palavra << std::endl;
    }
    std::cout << "Nova palavra adicionada ao banco de palavras." << std::endl;
    arquivo.close();
}

std::vector<std::string> ler_arquivo(){
    std::ifstream arquivo;
    arquivo.open("palavras/palavras.txt");
    if (!arquivo.is_open()){
        std::cout << "Arquivo não foi aberto!" << std::endl;
        exit(0);
    }
    int quantidade_de_palavras;
    arquivo >> quantidade_de_palavras;
    std::vector<std::string> palavras_do_arquivo;

    for (int i = 0; i < quantidade_de_palavras; i++){
        std::string palavra_lida;
        arquivo >> palavra_lida;
        palavras_do_arquivo.push_back(palavra_lida);
    }
    arquivo.close();
    if (palavras_do_arquivo.size() == 0){
        std::cout << "Banco de palavras vazio!" << std::endl;
        exit(0);
    }
    return palavras_do_arquivo;
}

void sorteia_palavra(){
    std::vector<std::string> palavras = ler_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void adiciona_palavra(){
    std::cout << "Digite a nova palavra MAIUSCULA sem espaços e acentos:" << std::endl;
    std::string nova_palavra;
    std::cin >> nova_palavra;
    std::vector<std::string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);
    salvar_arquivo(lista_palavras);
}

