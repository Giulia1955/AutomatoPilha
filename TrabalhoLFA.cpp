#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct transicao{
    char condicao;
    char empilha;
    char desempilha;
    int prox;
};

int main (){
    vector <vector <transicao>> grafo;
    vector <char> alfabeto;
    char a;

    int num, marcador, inicio, fim;

    cout << "Coloque o alfabeto nessa poha" << endl;
    while ((a = cin.get()) != '\n'){
        alfabeto.push_back(a);
    }

    cout << "Quantos automatos nesse caminhao de coco?" << endl;
    cin >> num;

    cout << "Qual automato vai ser o inicial nesse cacete?" << endl;
    cin >> inicio;
    marcador = inicio;

    cout << "Qual automato vai ser final nesse lixo?" << endl;
    cin >> fim;
    
    for(int i = 0; i < num; i++){
        cout << "Quantas ligações essa poha faz?" << endl;
        int x;
        cin >> x;
        vector <transicao> v;
        for(int j = 0; j < x; j++){
            transicao t1;
            cin >> t1.condicao
                >> t1.desempilha
                >> t1.empilha 
                >> t1.prox;
            v.push_back(t1);
        }
        grafo.push_back(v);
    }

    cout << "Quantos testes voce quer fazer nessa merda?" << endl;
    cin >> num;

    for(int i = 0; i < num ; i++){
        vector <char> palavra;
        char c;
        stack <char> pilha;

        while(cin >> c && c != '\n'){
            palavra.push_back(c);
        }
        for(int j = 0; j < palavra.size(); j++){
            auto it = find(alfabeto.begin(), alfabeto.end(), palavra[j]);
            if(it != alfabeto.end()){
                for(int k = 0; k < grafo[j].size(); k++){
                    if(c == grafo[j][k].condicao){
                        pilha.push(c);
                        
                        if ((grafo[j][k]).desempilha == pilha.top()){
                            pilha.pop();
                            marcador = grafo[j][k].prox;
                        } else {
                            break;
                            // ana elisa chora
                        }

                    }
                }
            }
            else{
                break;
                // ana elisa chora
            }
        }

        if(marcador == fim && pilha.empty()){
            cout << "Essa coisa horrorosa foi aceita" << endl;
        }
        else{
            cout << "????? Ta louco? Esta errado" << endl;
        }
        marcador = inicio;
        
    }
    

    return 0;
}