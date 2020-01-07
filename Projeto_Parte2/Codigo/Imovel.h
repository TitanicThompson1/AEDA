//
// Created by Ricardo Nunes on 01/11/2019. mudei
//

#ifndef PROJ_IMOVEL_H
#define PROJ_IMOVEL_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "globais.h"
#include "Address.h"
#include "Date.h"



using namespace std;



class Imovel{
private:
    static uint lastID;

    uint id;                            // id associado à moradia
    string tipo;                        // tipo de Imovel (Vivenda, Casa, ou Apartamento)
    string nome;                        // Nome do Imovel
    uint area;                          // Area em m2 da Imovel
    Address morada;                     // Morada do Imovel
    uint idContrato;
    vector<Intervalo> indis;
    uint idProprietario;

public:

    /*Construtores*/
    Imovel(){};
    Imovel(string tipo, string nome, uint area, Address morada, uint idContrato, vector<Intervalo> indis, uint idP);

    //GET-Methods
    string getTipo() const {return tipo;};
    string getNome() const {return nome;};
    uint getArea() const {return area;};
    Address getAddress() const {return morada;};
    uint getId() const {return id;};
    uint getContrato() const {return idContrato;};
    const vector<Intervalo>& getInds() const {return indis;};
    uint getProprietario() const {return idProprietario;};
    string getIndsFormatted() const;

    //SET-METHODS
    void setTipo(string tipo){this->tipo=tipo;};
    void setNome(string nome){this->nome=nome;};
    void setArea(uint area){this->area=area;};
    void setAddress(Address morada){this->morada=morada;};
    void setImovel(string tipo, string nome, uint area, Address morada, uint idContrato, vector<Intervalo> indis, uint idProprietario);
    void setId(uint id){this->id=id;};


    //addToVector
    void addIntervalo(Intervalo i) {indis.push_back(i);};

    //STATIC methods
    static void setLastID(uint id){lastID=id;};

    //sortIndisponibilidades
    void sortIndis(){sort(indis.begin(),indis.end());};


    friend ostream& operator<<(ostream& out, const Imovel& im);
    bool operator<(const Imovel &i1) const;
    bool operator== (const Imovel &i1) const {return morada==i1.morada;};


};
vector<Intervalo> IndisFromString(string s);

#endif //PROJ_IMOVEL_H
