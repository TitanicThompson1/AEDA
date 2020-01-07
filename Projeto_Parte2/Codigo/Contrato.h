//
// Created by flavi on 08/11/2019.
//

#ifndef PROJAEDA_CONTRATO_H
#define PROJAEDA_CONTRATO_H

#include "stdio.h"
#include <iostream>
#include "Date.h"
#include <ctime>
using namespace std;

class Contrato{
    static unsigned int idcount;
    double preco ;
    int id;

protected:
    unsigned int  type;
    Date  dataAss;
public:
    double getPreco() const {return preco;};
    virtual ~Contrato(){};
    void setPreco(double preco){this->preco=preco;};
    void setId(unsigned int id){this->id=id;};
    unsigned int getId() const {return id;};
    Date getDataAss() const {return dataAss;};

    virtual bool getRenovavel() const {return true;};                //nunca sera chamado para contrato
    virtual string getBase() const {return "oi";};                   //nunca sera chamado para contrato
    virtual unsigned int getPeriodo() const{return 0;};              //nunca sera chamado para contrato
    virtual void setBase(string base){};                             //nunca sera chamado para contrato
    virtual void setRenovavel(bool renovavel){};
    virtual void setPeriodo(unsigned int periodo){};


    Contrato(){};
    Contrato(double pr,Date dataAss);
    virtual unsigned int returnType() const = 0;


};

class ContratoException{
    int id;
public:
    ContratoException(int id);
};

class Venda:public Contrato{
    public:

        Venda(double pr,Date dataAss) : Contrato(pr,dataAss) {type=1;};
        unsigned int returnType() const{return type;}
};


class Flexivel : public Contrato{

private:

    string base;
    unsigned int periodo;
    bool renovavel;

public:
    Flexivel(){};
    Flexivel(double pr,Date dataAss,unsigned int periodo, bool renovavel,string base);

    bool getRenovavel() const{return renovavel;} ;
    string getBase() const{return base;};
    unsigned int getPeriodo() const { return periodo;};
    void setBase(string base){this->base = base;} ;
    void setRenovavel(bool renovavel){this-> renovavel = renovavel;};
    void setPeriodo(unsigned int periodo){this->periodo = periodo;};
    unsigned int returnType() const{return type;};

};



class LongaDuracao: public Contrato{

    unsigned int periodo;  //meses
    bool renovavel;

public:
    LongaDuracao( double pr,Date dataAss,bool renovavel,unsigned int periodo);

    bool getRenovavel() const{return renovavel;} ;
    void setRenovavel(bool renov){ this->renovavel = renovavel;};
    unsigned int getPeriodo() const{return periodo;};
    void setPeriodo(unsigned int periodo){this->periodo = periodo;};
    unsigned int returnType() const {return type;};
};





#endif //PROJAEDA_CONTRATO_H
