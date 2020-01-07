//
// Created by Ricardo Nunes on 01/11/2019.
//

#ifndef PROJ_ERRO_H
#define PROJ_ERRO_H

#include <iostream>


using namespace std;
typedef unsigned int uint;

/**
 * Classe InputInvalido
 */

class InputInvalido{
    int input;
public:
    /**Construtor
     *
     * @param input: o input posto
     */
    InputInvalido(int input){this->input=input;};

    /**Função que retorna o input
     *
     * @return o input invalido
     */
    int getInput() const { return input;};
};

/**
 * Classe ImovelInexistente
 */
class ImovelInexistente{
    uint id;    //username do Imovel
public:
    /**Construtor
     *
     * @param nome Nome do Imovel
     */
    ImovelInexistente(uint id){this->id=id;};

    /**Função que retorna o nome do Imovel
     *
     * @return nome do Imovel
     */
    uint getNome() const {return id;};

};

/**
 * Classe UtilizadorJaExistente
 */
class UtilizadorJaExistente{

    string username;    //username do utilizador
public:
    /**
     * Construtor
     * @param username  Username do utilizador já existente
     */
    UtilizadorJaExistente(string username) {this->username=username;};

    /**
     * Função que retorna o username
     * @return username
     */
    string getNome() const {return username;};
};

class PessoaJaExistente{
    uint NIF;
public:
    PessoaJaExistente(uint NIF){
        this->NIF=NIF;
    };
    uint getNIF() const {return NIF;};
};

class ImovelJaExistente{
    string nome;
public:
    ImovelJaExistente(string nome){this->nome=nome;};
    string getNome() const {return nome;};
};


class FicheiroNaoExistente{
    string filename;
public:
    FicheiroNaoExistente(string filename){this->filename=filename;};
    string getFilename() const {return filename;};
};

class ReservaNaoExistente{
    uint id;
public:
    ReservaNaoExistente(uint id){this->id=id;};
    uint getID() const {return id;};
};

class Cancela{
    string processo;
public:
    Cancela(string proc){processo=proc;};
    string getProcesso() const {return processo;};
};

class PessoaNaoExistente{
    uint id;
public:
    PessoaNaoExistente(uint id){this->id=id;};
    uint getNome()const { return id;};
};



#endif //PROJ_ERRO_H
