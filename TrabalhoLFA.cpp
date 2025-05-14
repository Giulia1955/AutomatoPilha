#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <limits>

using namespace std;

struct transicao{
    char condicao;
    char empilha;
    char desempilha;
    int prox;
};

bool testaPalavra(vector <vector <transicao>> grafo, vector <char> alfabeto, int inicio, string palavra, vector <int> estadosFinais){
    int marcador  = inicio;
    stack <char> pilha;
    pilha.push('Z');
    bool achouCondicao = false;
    for(char p : palavra){
        bool achou = false;
        for(auto i = alfabeto.begin(); i != alfabeto.end(); i++){
            if(p == *i){
                achou = true;
            }
        }
        if(!achou){
            return false;

        }
    }
    for(char p : palavra){
        achouCondicao = false;
        vector <transicao> v = grafo.at(marcador);
        for(auto i = v.begin(); i != v.end(); i++){
            if((i->condicao == p && (((!pilha.empty() && i->desempilha == pilha.top())) || i->desempilha == '#'))){
                if(i->desempilha != '#'){
                    pilha.pop();
                }
                if(i->empilha != '#'){
                    pilha.push(i->empilha);
                }               
                marcador = i->prox;
                achouCondicao = true;
                break;     
            }
            if(i->condicao == '#' && pilha.top() == 'Z'){
                if(i->empilha != '#'){
                    pilha.push(i->empilha);
                }               
                marcador = i->prox;
                achouCondicao = true;
                break;
            }
        }
        if(!achouCondicao){
            return false;
        }
    }
    vector <transicao> v = grafo.at(marcador);
    for(auto i = v.begin(); i != v.end(); i++){
        if(i->condicao == '#' && !pilha.empty() && pilha.top() == i->desempilha){
            if(i->desempilha != '#') pilha.pop();
            if(i->empilha != '#') pilha.push(i->empilha);
        marcador = i->prox;
        break;
        }   
    }
    auto it = find(estadosFinais.begin(), estadosFinais.end(), marcador);
    if (it != estadosFinais.end() && pilha.size() == 0) {
        return true;
    }
    return false;
}

int main (){
    vector <vector <transicao>> grafo;
    vector <char> alfabeto;
    vector <int> estadosFinais;
    char a;

    int num, inicio, fim, qtd;

    cout << "Coloque o alfabeto nessa poha" << endl;
    while ((a = cin.get()) != '\n'){
        if(a != ' '){
            alfabeto.push_back(a);
        }      
    }

    cout << "Quantos automatos nesse caminhao de coco?" << endl;
    cin >> num;

    cout << "Qual automato vai ser o inicial nesse cacete?" << endl;
    cin >> inicio;

    cout << "Quantos automatos finais terao?" << endl;
    cin >> qtd;

    cout << "Quais automatos serao os finais nesse lixo?" << endl;
    for(int i = 0; i < qtd; i++){
        cin >> fim;
        estadosFinais.push_back(fim);
    }

    if(fim > num){
        cout << "seu burro do caralho digite algo certo uma vez na vida" << endl;
        return -1;
    }
    
    for(int i = 0; i < num; i++){
        cout << "Quantas ligacoes essa poha de automato " << i << " faz?" << endl;
        int x;
        cin >> x;
        vector <transicao> v;
        for(int j = 0; j < x; j++){
            transicao t1;
            cout << "ligacao " << j + 1 << ":" << endl;
            cout << "condicao: "<< endl;
            cin >> t1.condicao;
            cout << "desempilha: "<< endl;
            cin >> t1.desempilha;
            cout << "empilha: "<< endl;
            cin >> t1.empilha;
            cout << "proximo: " << endl;
            cin >> t1.prox;
            v.push_back(t1);
        }
        grafo.push_back(v);
    }

    cout << "Quantos testes voce quer fazer nessa merda?" << endl;
    cin >> num;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for(int i = 0; i < num ; i++){
        string palavra;
        cin >> palavra;
        bool conf = testaPalavra(grafo, alfabeto, inicio, palavra, estadosFinais);

        if(conf){
            cout << "Essa coisa horrorosa foi aceita" << endl;
        }
        else{
            cout << "????? Ta louco? Esta errado" << endl;
        }
    }   
    return 0;
}
