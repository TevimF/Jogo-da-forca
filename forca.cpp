#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

string palavra_secreta = "MELANCIA"; 
map<char, bool> chutou;
vector<char> chutes_errados;
const string ENDERECO_ARQUIVO = "./palavras/palavras.txt";

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

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

void adiciona_palavra(){
    cout << "Digite a nova palavra usando letras maiúsculas" << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = ler_arquivo();
    lista_palavras.push_back(nova_palavra);

    salvar_arquivo(lista_palavras);
}

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