//
// Created by Ricardo Nunes on 01/11/2019.
//

#include "Imovel.h"

uint Imovel::lastID = 0;

Imovel::Imovel(string tipo, string nome, uint area, Address morada, uint idContrato, vector<Intervalo> indis, uint idP)
{

    this->id=++lastID;
    this->tipo=tipo;
    this->nome=nome;
    this->area=area;
    this->morada=morada;
    this->idContrato=idContrato;
    this->indis=indis;
    this->idProprietario=idP;
}

void Imovel::setImovel(string tipo, string nome, uint area, Address morada, uint idContrato, vector<Intervalo> indis, uint idProprietario)
{
    this->id=++lastID;
    this->tipo=tipo;
    this->nome=nome;
    this->area=area;
    this->morada=morada;
    this->idContrato=idContrato;
    this->indis=indis;
    this->idProprietario=idProprietario;
}


ostream& operator<<(ostream& out, const Imovel& im){
    out << "ID:  " << im.id << endl
        << "Tipo de Imovel:  " << im.tipo << endl
        << "Nome do Imovel:  " << im.nome << endl
        << "Morada" << im.morada << endl
        << "Area do Imovel:  " << im.area << endl;
    return out;

}


bool Imovel::operator<(const Imovel &i1) const {
    if (i1.morada.getFreguesia() < morada.getFreguesia()) {
        return true;
    } else if (i1.morada.getFreguesia() == morada.getFreguesia()) {
        if (i1.morada.getCodPos() < morada.getCodPos()) {
            return true;
        } else if (i1.morada.getCodPos() == morada.getCodPos()) {
            if (i1.tipo < tipo) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}

string Imovel::getIndsFormatted() const{
    string result="";

    for(int i=0;i<indis.size();i++){
        result+=indis.at(i).getDataInicio().getDateFormatted() + "-" + indis.at(i).getDataFim().getDateFormatted() + "," ;
    }
    return result.substr(0,result.size()-1);
}


vector<Intervalo> IndisFromString(string s){
    istringstream sstream(s),sstream1;
    string temp;
    vector<Intervalo> res;
    Intervalo itemp;
    while(getline(sstream,temp,',')){
        itemp.setIntervaloFromString(temp);
        res.push_back(itemp);
    }
    return res;
}

