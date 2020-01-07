//
// Created by Ricardo Nunes on 01/11/2019.
//

#ifndef PROJ_ADRESS_H
#define PROJ_ADRESS_H

#include <iostream>
#include <sstream>
#include "globais.h"

using namespace std;

//mudei

// A ordem de uma morada deve ser :
// <tipo de rua> <nome da rua> <num da porta> <piso se houver>
// <freguesia>
// <codigo postal> <localidade/cidade>

class Address
{
    string rua;       //Rua
    uint num;         //Numero da Porta
    string freguesia; //Freguesia
    string codpos;    //Codigo Postal
    string loc;       //Localidade

public:
    /**
     * Construtor da classe Address
     */
    Address(){};
    Address(string rua, uint num, string freguesia, string codpos, string loc);
    Address(string morada);

    /*SET-Methods*/
    void setAddress(string morada);

    /*GET-Methods*/
    string getRua() const { return rua; };
    uint getNum() const { return num; };
    string getFreguesia() const { return freguesia; };
    string getCodPos() const { return codpos; };
    string getLoc() const { return loc; };
    string getAddressFormated() const;

    friend ostream &operator<<(ostream &out, const Address &add);
    bool operator==(const Address &a1) const;
};

#endif //PROJ_ADRESS_H