#include <iostream>
#include <vector>
#include <map>

using namespace std;
#include "Pilha.h"

struct transicao{
    char condicao;
    char empilha;
    char desempilha;
};

no criaAutomato(){
    cout << "Quantas ligações?" << endl;
    int num;
    cin >> num;
    transicao t[num];
    for(int i = 0; i < num; i++){
        cin >> t[i].condicao
            >> t[i].empilha
            >> t[i].desempilha;
    }


    

}

int main(){
    vector <string> estados;
    vector <char> linguagem;
    vector <char> entrada;
    vector <no> pilhas;
    char c;
    int num;

    cout << "quantos automatos?" << endl;
    cin >> num;
    for(int i = 0; i < num; i++){
        pilhas.push_back(criaAutomato());
    }

}