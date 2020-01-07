//
// Created by Ricardo Nunes on 12/11/2019.
//

#include "gerirReservas.h"



void removeReserva(vector<Reserva> &reservas, uint id){
    bool encontrou=false;
    auto it=reservas.begin();

    for (it;it!=reservas.end();it++)
    {

        if(!encontrou && it->getID()==id){
            reservas.erase(it);
            it--;
            encontrou=true;
        }else if(encontrou){
            it->setId(it->getID()-1);
        }
    }
    if(!encontrou)
        throw ReservaNaoExistente(id);              //Fazer a interface primeiro pls
}

bool findReserva(vector<Reserva> &reservas, uint id){
    for(auto it=reservas.begin();it!=reservas.end();it++){
        if(it->getID()==id)
            return true;
    }
    return false;
}