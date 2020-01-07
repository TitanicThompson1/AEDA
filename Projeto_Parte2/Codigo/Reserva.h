//
// Created by Ricardo Nunes on 12/11/2019.
//

#ifndef PROJ_RESERVA_H
#define PROJ_RESERVA_H

#include "globais.h"
#include "Date.h"

class Reserva{
    static uint lastID;
    uint id;
    uint idProprietario;
    uint idContratante;
    Intervalo periodo;
    uint idImovel;
    double valor;

public:
    Reserva(){};
    Reserva(uint idP, uint idC, Intervalo per, uint idI, double val);


    /*SET-METHODS*/

    /*GET-METHODS*/
    uint getID() const {return id;};
    uint getIdProprietario() const { return idProprietario;};
    uint getIdContratante() const {return idContratante;};
    Intervalo getIntervalo() const {return periodo;};
    uint getIdImovel() const {return idImovel;};
    double getValor() const {return valor;};

    void setId(uint id) { this->id=id;};

    friend ostream& operator<< (ostream& out, Reserva& r);


};


#endif //PROJ_RESERVA_H
