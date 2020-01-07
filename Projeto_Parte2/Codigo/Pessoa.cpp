//
// Created by debor on 08/11/2019.
//

#include "Pessoa.h"

uint Registrado::lastID = 0;

//OVERLOAD Operators - Pessoa

ostream& operator<<(ostream& out, const Registrado& p){
    out << "Nome:  " << p.nome << endl
        << "E-mail: " << p.email << endl;
    return out;
}

bool Registrado::operator== (const Registrado &p1) const
{
    if(NIF == p1.NIF || email == p1.email)
        return true;
    else
        return false;
}

//Construtores Registrado

Registrado::Registrado(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis,
                       vector<string> interesses, string webPassword, bool isSingular,vector <unsigned int> contractsClient):  isSingular(isSingular) {
    this->id=++lastID;
    this->nome=nome;
    this->NIF=NIF;
    this->email=email;
    this->qtdeImoveis=qtdeImoveis;
    this->listaImoveis=listaImoveis;

    this->interesses=interesses;
    this->webPassword=webPassword;
    this-> contractsClient = contractsClient;

    if(contractsClient.size() == 0){
        this->isClient = false;

    }
    else{
        this->isClient = true;

    }



};

void Registrado::setRegistrado(string nome, uint NIF, string email, uint qtdeImoveis, vector<uint> listaImoveis, vector <string> interesses, string webPassword,vector <unsigned int> contractsClient){
    this->id=++lastID;
    this->nome=nome;
    this->NIF=NIF;
    this->email=email;
    this->qtdeImoveis=qtdeImoveis;
    this->listaImoveis=listaImoveis;



    this->interesses = interesses;
    this->webPassword = webPassword;
    this->contractsClient = contractsClient;

    if(contractsClient.size() == 0){
        this->isClient = false;

    }
    else{
        this->isClient = true;

    }




};

//Methods

string Registrado::getInteressesFormated() const {
    string result;
    for (int i = 0; i<interesses.size(); i++) {
        if(i==interesses.size()-1) {
            result+=interesses.at(i);
        }else{
            result+=interesses.at(i) + ',';
        }
    }
    return result;
}

string Registrado::getImoveisFormated() const {
    string result = "";
    if(listaImoveis.empty()) {
        return "0";
    }
    for (int i = 0; i<listaImoveis.size(); i++) {
        if(i==listaImoveis.size()-1) {
            result+=to_string(listaImoveis.at(i));
        }else{
            result+=to_string(listaImoveis.at(i)) + ',';
        }
    }
    return result;
}

void Registrado::addListaImoveis(uint idImovel) {
    listaImoveis.push_back(idImovel);
}

void Registrado::setContrato(unsigned int idContr) {
    contractsClient.push_back(idContr);
}

string Registrado::getContractsFormated() const {
    string aux;

    if(contractsClient.size() == 0){
        return "0";
    }
    else{

        for( int i = 0; i < contractsClient.size(); i ++){
            aux += contractsClient.at(i);
            if( i < contractsClient.size() - 1){
                aux +=", ";
            }

        }

        return aux;

    }
}



//EMPRESA

ostream& operator<<(ostream& out, const Empresa& e) {
    out << "Nome:  " << e.nome << endl
        << "E-mail: " << e.email << endl
        << "Isenção de Impostos: " << e.isencaoImpostos << "%" << endl;
    return out;
}

//SINGULAR

ostream& operator<<(ostream& out, const Singular& s) {
    out << "Nome:  " << s.nome << endl
        << "E-mail: " << s.email << endl
        << "Isenção de Impostos: " << s.reducaoImpostos << "%" << endl;
    return out;
}