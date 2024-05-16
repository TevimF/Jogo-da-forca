#pragma once

#include "main.hpp"

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

void chuta(){
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[toupper(chute)] = true;

    if(letra_existe(toupper(chute))){
        cout << "Você acertou! Seu chute está na palavra." << endl;
    }
    else{
        cout << "Você errou! Seu chute não está na palavra." << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}
