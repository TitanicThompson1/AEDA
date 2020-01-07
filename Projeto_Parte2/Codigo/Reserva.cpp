//
// Created by Ricardo Nunes on 12/11/2019.
//

#include "Reserva.h"

uint Reserva::lastID = 0;

Reserva::Reserva(uint idP, uint idC, Intervalo per, uint idI, double val)
{

    id=++lastID;
    idProprietario=idP;
    idContratante=idC;
    periodo=per;
    idImovel=idI;
    valor=val;
}

ostream& operator<< (ostream& out, Reserva& r){
    out << "ID:  " << r.id << endl
        << "ID Proprietario:  " << r.idProprietario << endl
        << "Id Contratante:  " << r.idContratante << endl
        << "Periodo:  " << r.periodo << endl
        << "Id Imovel:  " << r.idImovel << endl;
    return out;
}


