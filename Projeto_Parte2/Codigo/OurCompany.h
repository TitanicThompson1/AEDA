//
// Created by Ricardo Nunes on 12/11/2019. mudei
//

#ifndef PROJ_OURCOMPANY_H
#define PROJ_OURCOMPANY_H

#include <vector>
#include <fstream>

#include "Address.h"
#include "Imovel.h"
#include "Reserva.h"
#include "Erro.h"
#include "FilesInOut.h"
#include "gerirImoveis.h"
#include "gerirReservas.h"
#include "leilao.h"
#include <ctime>
#include "bst.h"



class OurCompany{
private:
    string nome;
    Address morada;
    string imovelFile,contractFile, clientsFile,reservFile,leilaoFile;
    vector<Registrado*> clientes;
    vector<Reserva> reservas;

    /**
     * Vê todos os leilôes em que o dia final seja menor que o dia atual. Elimina esse leilao do vector e atribui à pessoa o imovel-
     * @param current data atual
     */
    void limpaLeiloes(Date current);

public:
    BST<Imovel> treeImoveis;
    vector<Imovel> imoveis;
    vector<Imovel> filtrados;
    Registrado* PessoaAtual;
    vector<Contrato*> contratos;
    vector<Leilao> leiloes;


    OurCompany() : treeImoveis(Imovel()) {PessoaAtual=NULL;};
    void importCompany(const string &filename);
    void exportCompany(const string &filename);

    void addRegistrado(Registrado *R) {clientes.push_back(R);};
    void addReserva(Reserva r){reservas.push_back(r);};
    void addInterEmImovel(uint id, Intervalo inter){ imoveis.at(id-1).addIntervalo(inter);};
    void sortIntervalosDeImovel(uint id){imoveis.at(id-1).sortIndis();};

    void eraseImovel(uint id){eliminaImovel(imoveis,id);};
    void eraseReserva(uint id){removeReserva(reservas,id);};

    const vector<Registrado*>& getRegistrados() const {return clientes;};
    const vector<Reserva>& getReservas() const {return reservas;};
    const vector<Imovel>& getImoveis() const {return imoveis;};

    bool addImovel(Imovel newImovel); // add novo imovel a arvore binaria
    bool createUpdateTree();
    int showTreeImoveis(string filterType, string filterWord); // imprimir imoveis a partir de um filtro (tipo, codpos, freguesia)

    void limpaFiltros(){filtrados=imoveis;};
    void personalizaFiltros();
    void verifyInactRegis();


    friend ostream& operator<< (ostream& out, OurCompany& company);

};

#endif //PROJ_OURCOMPANY_H
