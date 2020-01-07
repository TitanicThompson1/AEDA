//
// Created by Ricardo Nunes on 08/11/2019. mudei
//

#ifndef PROJ_UTILS_H
#define PROJ_UTILS_H

#include <vector>
#include <iostream>
#include <sstream>

#include "Erro.h"


using namespace std;

static unsigned int indice;

typedef unsigned int uint;

template<class T>
bool valorEmArray(T arr[],int size, T valor){

    for(int i=0;i<size;i++)
    {
        if (arr[i]==valor) return true;
    }
    return false;
}

template<class T>
void atualizaIds(vector<T>& vetor){
    for (int i=0;i<vetor.size();i++){
        vetor.at(i).setId(i+1);
    }
}


template<class T>
T verificaValores(char op, string mensagem, T dados[], int size){
    T result;
    switch(op)
    {
        case '=':
            cout << mensagem; cin >> result;
            while(cin.fail() || !valorEmArray(dados,size,result)){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                cerr << "ERRRO: " + mensagem; cin >> result;
            }
            break;
        case '2':
            cout << mensagem; cin >> result;
            while(cin.fail() || dados[0] > result || dados[1]< result){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                cerr << "ERRRO: " + mensagem; cin >> result;
            }
            break;
        case '<':
            cout << mensagem; cin >> result;
            while(cin.fail() || dados[0] < result){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                cerr << "ERRRO: " + mensagem; cin >> result;
            }
            break;
        case '>':
            cout << mensagem; cin >> result;
            while(cin.fail() ||dados[0] > result){
                if(cin.fail()){
                    cin.clear();
                    cin.ignore();
                }
                cerr << "ERRRO: " + mensagem; cin >> result;
            }
            break;
        default:
            break;
    }
    return result;

}

vector<string> formatarInteresses(string interessesFile);

vector<uint> formatarListaImoveis(string imoveisFile);

void confirmaAssinatura(string nome);



#endif //PROJ_UTILS_H
