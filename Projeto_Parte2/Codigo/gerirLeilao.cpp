//
// Created by Ricardo Nunes on 02/01/2020.
//

#include "gerirLeilao.h"


void displayLeiloes(OurCompany &c){
    int i=1;
    if(c.leiloes.empty()){
        cout << "Nao existem leiloes!" << endl;
        return;
    }
    for (auto it=c.leiloes.begin();it!=c.leiloes.end();it++){
        cout << i << "- " << c.imoveis.at(it->getImovel()-1).getNome() << endl;
        cout << *it;
        i++;
    }
    cout << endl;
}

bool existeLeilao(vector<Leilao> leiloes, uint idI){

    for (auto it=leiloes.begin(); it!=leiloes.end();it++){
        if(it->getImovel()==idI){
            return true;
        }
    }
    return false;
}
