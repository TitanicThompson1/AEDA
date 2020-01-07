//
// Created by debor on 08/11/2019.
//
#ifndef PROJ_PESSOA_H
#define PROJ_PESSOA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "globais.h"
#include "Imovel.h"
#include "Contrato.h"
#include "globais.h"
#include <ctime>


using namespace std;


class Registrado{
protected:


    static uint lastID;

    uint id; // id associado ao Registrado
    string nome;
    uint NIF;
    string email;
    bool isClient; //Se true, o registrado já possui contratos e é, portanto, cliente
    vector <string> interesses;
    uint qtdeImoveis;
    vector <uint> listaImoveis;
    string webPassword;
    vector <unsigned int> contractsClient;
    bool isSingular = false;
    bool isCompany = false;
    bool inactivo = true;

public:
    Registrado(){};
    Registrado(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis,
               vector<string> interesses, string webPassword, bool isSingular,
               vector<unsigned int> contractsClient);

    virtual ~Registrado(){};

    //SET Methods
    void setNome(string nome) {this->nome=nome;};
    void setNIF(uint NIF){this->NIF=NIF;};
    void setEmail(string email){this->email=email;}
    void setIsClient(bool isClient){this->isClient=isClient;};
    void setListaImoveis (vector<uint> listaImoveis) {this->listaImoveis=listaImoveis;};
    void setInteresses(vector<string> interesses) {this->interesses=interesses;};
    void setQtdeImoveis(uint qtdeImoveis) {this->qtdeImoveis=qtdeImoveis;};
    void setWebPassword(string webPassword) {this->webPassword=webPassword;};
    void setId(uint id){this->id=id;};
    void setContrato(unsigned int contrato);
    void setInactivo(bool inact){this->inactivo = inact;};
    /**
     * Faz set dos atributos apos criacao de um Registrado
     * @param nome
     * @param NIF
     * @param email
     * @param qtdeImoveis
     * @param listaImoveis
     * @param interesses
     * @param isClient
     * @param webPassword
     */

    //GET Methods
    uint getId() const {return id;};
    uint getNIF() const {return NIF;};
    string getNome() const {return nome;};
    string getEmail() const {return email;}
    bool getIsClient() {return isClient;};
    vector <uint> getListaImoveis() const {return listaImoveis;};
    vector <string> getInteresses() const {return interesses;};
    uint getQtdeImoveis() const {return listaImoveis.size();};
    string getWebPassword() const {return webPassword;};
    bool getIsCompany() const {return isCompany;};
    bool getIsSingular() const {return isSingular;};
    vector<unsigned int> getContratos() const {return contractsClient ;};
    bool getIsInact() const {return inactivo; };
    /**
     * Funcao que retorna a lista de interesses do Registrado formatados de acordo com o file clients.txt
     * Utiliza getInteresses() e faz parse das strings, adicionando as vírgulas
     * @return String com interesses separados por virgulas
     */
    string getInteressesFormated() const;
    /**
     * Funcao que retorna a lista de Imoveis do Registrado formatados de acordo com o file clients.txt
     * Utiliza getListaImoveis() e faz parse das strings, adicionando as vírgulas
     * @return String com ids dos imoveis separados por virgulas
     */
    string getImoveisFormated() const;
    string getContractsFormated() const;

    //STATIC methods

    static void setLastID(uint id){lastID=id;};

    //OVERLOAD Operators
    /**
     *
     * @param out outstream
     * @param p Registrado
     * @return
     */
    friend ostream& operator<<(ostream& out, const Registrado& p);
    bool operator== (const Registrado &p1) const;

    //Other Methods
    /**
     * Funcao que adiciona o id de um Imovel para o atributo vector<uint>listaImoveis do Registrado
     * @param idImovel
     */
    void addListaImoveis(uint idImovel);

    void setRegistrado(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis,
                       vector<string> interesses, string webPassword,
                       vector<unsigned int> contractsClient);
};

class Empresa : public Registrado {
private:
    uint isencaoImpostos;

public: 
    Empresa(){};
    Empresa(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis,
            vector<string> interesses, string webPassword, bool isSingular,
            vector<unsigned int> contractsClient, uint isencaoImpostos) : Registrado(nome,  NIF, email,  qtdeImoveis,  listaImoveis,
     interesses,  webPassword, false, contractsClient) {
        this->isencaoImpostos=isencaoImpostos;
        isCompany = true;
    };

    //SET Methods
    void setIsencaoImpostos(uint isencaoImpostos) {this->isencaoImpostos=isencaoImpostos;};

    //GET Methods
    uint getIsencaoImpostos() const {return isencaoImpostos;};
    bool getIsCompany() const {return isCompany;};

    //OVERLOAD Operators
    friend ostream& operator<<(ostream& out, const Empresa& e);

};

class Singular : public Registrado {
private:
    uint reducaoImpostos;

public:
    Singular(){};
    Singular(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis, vector <string> interesses, bool isClient, string webPassword, uint reducaoImpostos, vector<uint> contractsClient) :
    Registrado(nome,  NIF, email,  qtdeImoveis,  listaImoveis,interesses,  webPassword, false, contractsClient) {
        this->reducaoImpostos=reducaoImpostos;
        isSingular = true;
    };

    //SET Methods
    void setReducaoImpostos(uint reducaoImpostos) {this->reducaoImpostos=reducaoImpostos;};

    //GET Methods
    uint getReducaoImpostos() const {return reducaoImpostos;};
    bool getIsSingular() const {return isSingular;};

    //OVERLOAD Operators
    friend ostream& operator<<(ostream& out, const Singular& s);

};

#endif //PROJ_PESSOA_H
