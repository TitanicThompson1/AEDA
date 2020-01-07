//
// Created by debor on 15/11/2019.
//

#ifndef PROJ_FILESINOUT_H
#define PROJ_FILESINOUT_H


#include "Reserva.h"
#include "Pessoa.h"
#include "Contrato.h"
#include "Imovel.h"
#include "utils.h"
#include "Erro.h"
#include "leilao.h"

/**
 * Importa todos os registrados existentes num ficheiro para um vector de registrados
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param clientes vector de regitrados
 * @param filename nome do ficheiro com os registrados
 */
void importaRegistrado(vector<Registrado*> &clientes, const string &filename);

/**
 * Exporta os registrados existentes no vector de registrados para um ficheiro
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param clientes vector de regitrados
 * @param filename nome do ficheiro a exportar para
 */
void exportaRegistrado(const vector<Registrado*> &clientes, const string &filename);

/**
 * Importa os contratos existentes num ficheiro para o vector de Contratos
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param cont vector de Contratos
 * @param filename nome do ficheiro com os Contratos
 */
void importaContrato(vector<Contrato*> &cont,const string &filename);

/**
 * Exporta os Contratos existentes num vector para um ficheiro de texto
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param cont vector de Contratos
 * @param filename nome do ficheiro de texto
 */
void exportaContrato(vector<Contrato*> &cont, const string &filename);


/**
 * Importa os imoveis existentes num ficheiro para um vector de imoveis
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param imoveis vector de imoveis a preencher
 * @param filename nome do ficheiro com os imoveis
 */
void importaImoveis(vector<Imovel> &imoveis,  const string &filename);

/**
 * Exporta os imoveis existentes num vector de Imoveis para um ficheiro
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param imoveis imoveis a exportar
 * @param filename nome do ficheiro a exportar para
 */
void exportaImoveis(vector<Imovel> &imoveis,  const string &filename);

/**
 * Importa as reservas existentes num ficheiro de texto para um vector de reservas
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param reservas reservas a exportar
 * @param filename nome do ficheiro de texto
 */
void importaReservas(vector<Reserva> &reservas, const string &filename);

/**
 * Exporta as reservas existentes num vector de reservas para um ficheiro de texto
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param reservas vector de reservas
 * @param filename nome do ficheiro de texto
 */
void exportaReservas(vector<Reserva> &reservas, const string &filename);

/**
 * Importa os leiloes existentes num ficheiro de texto para um vector de leiloes
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param leiloes vector de leiloes
 * @param filename nome do ficheiro de texto
 */
void importaLeilao(vector<Leilao> &leiloes, const string &filename);


/**
 * Exporta os leiloes existentes num vector de leiloes para um ficheiro de texto
 * Lanca uma exceccao do tipo FicheiroNaoExistente se o ficheiro nao existir
 * @param leiloes vector de leiloes
 * @param filename nome do ficheiro de texto
 */
void exportaLeilao(vector<Leilao> &leiloes, const string &filename);


#endif //PROJ_FILESINOUT_H
