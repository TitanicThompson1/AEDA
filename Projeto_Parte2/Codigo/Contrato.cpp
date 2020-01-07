//
// Created by flavi on 08/11/2019.
//

#include "Contrato.h"

unsigned int Contrato::idcount = 0;


Contrato::Contrato (double pr,Date dataAss){
    preco = pr;
    this->dataAss = dataAss;
    id = idcount +1;
    idcount++;
    //Obter data actual para comparacao




}

ContratoException::ContratoException(int id){

    this-> id = id;
}


LongaDuracao::LongaDuracao(double pr,Date dataAss, bool renovavel, unsigned int periodo):Contrato(pr, dataAss){

    this->type=3;
    if(periodo < 6){
        this->periodo = 6;//contratos longa duracao minimo 6 meses
    }
    else{
        this->periodo = periodo;
    }

    this->renovavel = renovavel;
}

Flexivel::Flexivel(double pr, Date dataAss ,unsigned int periodo, bool renovavel, string base): Contrato(pr,dataAss) {

    this->type=2;
    this->renovavel = renovavel;
    this->periodo = periodo;
    this->base = base;
}
