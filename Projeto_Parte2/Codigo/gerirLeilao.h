//
// Created by Ricardo Nunes on 02/01/2020.
//

#ifndef PROJ_GERIRLEILAO_H
#define PROJ_GERIRLEILAO_H

#include <iostream>
#include <sstream>
#include "leilao.h"
#include "OurCompany.h"

void displayLeiloes(OurCompany &c);

/**
 * Verifica se já existe um leilao para o imovel
 * @param leiloes vector de leiloes
 * @param idI id do imovel
 * @return true se o imovel ja estiver a ser leiloado; false caso contrario
 */
bool existeLeilao(vector<Leilao> leiloes, uint idI);

#endif //PROJ_GERIRLEILAO_H
