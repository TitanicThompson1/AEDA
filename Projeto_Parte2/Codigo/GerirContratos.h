//
// Created by flavi on 12/11/2019.
//

#ifndef PROJAEDA_GERIRCONTRATOS_H
#define PROJAEDA_GERIRCONTRATOS_H

#include "Contrato.h"
#include "Imovel.h"
#include "Erro.h"


/**
 *Funcao para procurar contrato tendo o id dado como parâmetro
 * @param contratos
 * @param id
 * @return posicao no vector do contrato pretendido caso não exista retorna -1
 */
int procuraContrato(vector<Contrato*> &contratos, unsigned int id);


/***
 * Funcao para utilziador inserir contrato usando teclado
 * @param cont vector de contratos
 * @return 0 se insere contrato 1 caso contrario
 */
void inserirContrato(Imovel &aux,vector<Contrato *> &contratos);



/***
 * 
 * @param cont
 * @return
 */
void eliminaContrato(vector<Contrato *> &contratos, unsigned int id);


/**
 *
 * @param cont
 * @return
 */

/**
 *
 * @param cont
 */


void alteraContrato(Imovel &imov, vector<Contrato *> &contratos);

#endif //PROJAEDA_GERIRCONTRATOS_H
