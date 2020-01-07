//
// Created by debor on 12/11/2019.
//

#ifndef PROJ_GERIRREGISTRADOS_H
#define PROJ_GERIRREGISTRADOS_H

#include "gerirImoveis.h"
#include "Pessoa.h"
#include "Erro.h"
#include "utils.h"
#include "OurCompany.h"
#include "utils.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

/**
 * Funcao que adiciona um novo Registrado ao vector<Registrado*> ao atributo clientes da OurCompany
 * @param c Objeto OurCompany
 */
void adicionaRegistrado(OurCompany& c);

/**
 * Funcao que elimina Registrado do atributo vector<Registrado*> clientes da OurCompany
 * @param clientes Vector de Clientes
 * @param id Id do Cliente a ser eliminado
 */
void eliminaRegistrado(vector<Registrado*> &clientes, uint id);

/**
 *
 * @param R Registrado
 * @param opcao Numero relacionado a que informacao alterar (1: nome, 2:NIF, 3:email, 4: interesses, 5: imoveis, 6:password)
 * @param c1 OurCompany
 */
void alteraRegistrado(Registrado &R, uint opcao, OurCompany &c1);

/**
 * Funcao que procura por um Registrado no vector<Registrado*> e retorna o seu iterador
 * @param inicio Iterador Inicial
 * @param fim Iterador Final
 * @param R Registrado a ser encontrado
 * @return
 */

vector<Registrado*>::const_iterator findClient(vector<Registrado*>::const_iterator inicio, vector<Registrado*>::const_iterator fim, Registrado &R);

#endif //PROJ_GERIRREGISTRADOS_H
