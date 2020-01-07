//
// Created by flavi on 21/12/2019.
//

#ifndef PROJ_CONTRATOSINACTIVOS_H
#define PROJ_CONTRATOSINACTIVOS_H

#include <unordered_set>
#include "Pessoa.h"
#include "OurCompany.h"
struct eq {
    bool operator () (const Registrado &r1,const Registrado &r2) const{
        return r1.getId() == r2.getId();
    }
};
//Usaremos o id dos registrados como strings na função hash e 997 como suposto tamanho máximo da tabela
struct hashInact{
    int operator() (const Registrado &r1) const{
        int v = 0;
        ostringstream str1;

        str1 << r1.getId();
        string aux = str1.str();
        for(size_t i = 0; i< aux.size(); i++){
            v = 997*v + aux[i];
        }
        return v;
    }

};

//função para obter tabela de dispersão quando requisitado

unordered_set<unsigned int,hashInact, eq> getTabelaDispersaoInact(vector<Registrado*> &registrados);









#endif //PROJ_CONTRATOSINACTIVOS_H
