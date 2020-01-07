//
// Created by Ricardo Nunes on 01/11/2019.
//

#ifndef PROJ_MENU_H
#define PROJ_MENU_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "globais.h"
#include "OurCompany.h"
#include "Date.h"
#include "utils.h"
#include "Pessoa.h"
#include "gerirRegistrados.h"
#include "gerirLeilao.h"

/**
 * Menu Inicial
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuInicial(OurCompany &c);

/**
 * Footer
 * @param c A companhia de imobiliarios
 */
void displayFooter(OurCompany &c);

/**
 * Cria paragrafos no cout
 * @param num numero de paragrafos
 */
void criaparagrafo(int num);

/**
 * Menu Imoveis
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuImoveis(OurCompany &c);


/**
 * Menu Registrar
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuRegistrar(OurCompany& c);

/**
 * Imprime o cabeçalho no cout
 */
void displayHead();

/**
 * Menu Display Imoveis
 * @param c A companhia de imobiliarios
 * @param filtrados
 * @return Menu seguinte
 */
uint MenuDisplayImoveis(OurCompany& c);

void novaJanela();


/**
 * Menu de Login
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuLogin(OurCompany& c);

/**
 * Menu que limpa os filtros de pesquisa
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuLimparFiltros(OurCompany& c);

/**
 * Menu que filtra por tipo de imovel
 * @param filtrados vetor de imoveis
 * @return Menu seguinte
 */
uint MenuFiltrarTipo(OurCompany &c);

/**
 * Menu que filtra por localidade
 * @param filtrados vetor de imoveis
 * @return Menu seguinte
 */
uint MenuFiltrarFreg(OurCompany &c);

/**
 * Menu que filtra por preco
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuFiltrarPreco(OurCompany& c);

/**
 * Menu para comprar um imovel
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuComprarImovel(OurCompany& c);

/**
 * Menu para fazer logout
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuLogout(OurCompany& c);

/**
 * Menu do perfil
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuPerfil(OurCompany &c);

/**
 * Menu para alterar perfil
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuAlterarPerfil(OurCompany &c);

/**
 * Menu para ver Reservas
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuVerReservas(OurCompany &c);

/**
 * Menu dos Leiloes
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuLeiloes(OurCompany &c);

/**
 * Menu para criar um leilao
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuCriarLeilao(OurCompany &c);

/**
 * Menu para ver os leiloes existentes
 * @param c A companhia de imobiliarios
 * @return Menu seguinte
 */
uint MenuVerLeiloes(OurCompany &c);


#endif //PROJ_MENU_H
