#pragma once

#include "../include/main.hpp"
#include "../include/game.hpp"
#include "../include/arquivo.hpp"

#include <iostream>

int main () {
    imprime_cabecalho();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;
        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S' || resposta == 's'){
            adiciona_palavra();
        }
        else{
            cout << "Obrigado por jogar! Tchau." << endl;
        }
    }
}