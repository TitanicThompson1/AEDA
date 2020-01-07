//
// Created by Ricardo Nunes on 08/11/2019. mudei
//

#ifndef PROJ_GERIRIMOVEIS_H
#define PROJ_GERIRIMOVEIS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>


#include "utils.h"
#include "gerirAddress.h"
#include "Imovel.h"
#include "Erro.h"
#include "Pessoa.h"
#include "GerirContratos.h"

using namespace std;

/**
 * Funcao que adiciona um imovel a um vetor de imoveis, perguntando ao utilizador os parametros do imovel(com prevencao de erros).
 * Lança a exceccao ImovelJaExistente se o imovel ja existir (ou seja, se existir um imovel com igual morada)
 *
 * @param imoveis vetor de imoveis
 * @param id id da pessoa que quer comprar
 */
void adicionaImovel(vector<Imovel> &imoveis, uint id);

/**
 * Funcao que elimina um imovel de um vetor de imoveis pelo ID.
 * Lança execcao ImovelInexistente se nao encontrar
 *
 * @param imoveis vector de imoveis
 * @param im imovel a eliminar
 */
void eliminaImovel(vector<Imovel> &imoveis, uint idI);

/**
 * Altera o imovel I no campo
 * @param I
 * @param campo
 */
void alteraImovel(Imovel &I, uint campo,vector<Contrato*> &contratos);


/**
 * Imprime na consola os imoveis presentes no vector imoveis (ID, tipo, nome, morada, e area)
 * @param imoveis vector de imoveis a imprimir
 */
void displayImoveis(const vector<Imovel> &imoveis);

/**
 * Lista os imoveis presentes no vector imoveis na seguinte formatacao: <n ID> - <Nome do imovel>
 * @param imoveis vector de imoveis
 */
void listarImoveis(vector<Imovel> &imoveis);


int procuraIdEmImoveis(const vector<Imovel> &i, uint id);


#endif //PROJ_GERIRIMOVEIS_H
