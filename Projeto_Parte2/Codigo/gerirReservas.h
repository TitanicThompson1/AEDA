//
// Created by Ricardo Nunes on 12/11/2019.
//

#ifndef PROJ_GERIRRESERVAS_H
#define PROJ_GERIRRESERVAS_H

#include <vector>

#include "Reserva.h"
#include "Erro.h"

/**
 * Remove uma reserva de um vetor de reservas
 * @param reservas vector de reservas
 * @param id id da reserva a eliminar
 */
void removeReserva(vector<Reserva> &reservas, uint id);

/**
 * Encontra uma reserva num vector de reservas
 * @param reservas vector de reservas a procurar
 * @param id id da reserva a procurar
 * @return true se encontrou; false caso contrario
 */
bool findReserva(vector<Reserva> &reservas, uint id);


#endif //PROJ_GERIRRESERVAS_H
