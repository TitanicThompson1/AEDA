//
// Created by Ricardo Nunes on 01/01/2020.
//

#ifndef PROJ_LEILAO_H
#define PROJ_LEILAO_H

#include <queue>
#include <sstream>
#include <iostream>
#include "globais.h"
#include "Date.h"

using namespace std;

class ItemLeilao{
private:
    double montante;
    uint licitador;
public:
    ItemLeilao(){};
    ItemLeilao(uint lic, double mont): montante(mont), licitador(lic){};

    //GET methods
    double getMontante() const {return montante;};
    uint getLicitador() const {return licitador;};

    bool operator< (const ItemLeilao &il)const {return montante<il.montante;};


};

class Leilao{
private:
    static uint lastID;

    //id do leilao
    uint id;
    //licitacoes
    priority_queue<ItemLeilao> licitacoes;
    //id do imovel a licitar
    uint im;
    //data final do leilao
    Date end;
public:
    Leilao(){};
    Leilao(priority_queue<ItemLeilao> lic,uint imo,Date fim);
    Leilao(uint imo,Date fim):im(imo),end(fim) {id=++lastID;};

    //GET methods
    uint getImovel() const {return im;};
    uint getID() const {return id;};
    priority_queue<ItemLeilao> getBiddings() const {return licitacoes;};
    string getBiddingsFormatted() const;
    Date getEndDate() const {return end;};

    /**
     * Adiciona uma licitacao nova. Se o licitador ja tiver uma licitacao, elimina-a.
     * @param il licitacao nova
     */
    void addBidding(ItemLeilao il);

    /**
     * Elimina a licitacao feita pelo utilizador de id idP (se nao existir, faz nada)
     * @param idP id da pessoa que fez a licitacao
     */
    void eraseBidding(uint idP);

    friend ostream& operator<<(ostream& out, const Leilao& im);

};


priority_queue<ItemLeilao> getBiddingsFromString(string lic);


#endif //PROJ_LEILAO_H
