//
// Created by Ricardo Nunes on 01/11/2019.
//


#include "Address.h"



//mudei

// A ordem de uma morada deve ser :
// <tipo de rua> <nome da rua> <num da porta> <piso se houver>
// <freguesia>
// <codigo postal> <localidade/cidade>

Address::Address(string rua, uint num, string freguesia, string codpos, string loc)
{
    this->rua = rua;
    this->num = num;
    this->freguesia = freguesia;
    this->codpos = codpos;
    this->loc = loc;
}

// Neste trabalho, a ordem da morada sera:
// <tipo de rua> <nome da rua>,
// <num da porta>,
// <freguesia>,
// <codigo postal>,
// <localidade/cidade>

Address::Address(string morada)
{
    string temp;
    istringstream sstring(morada);

    getline(sstring, temp, ',');
    rua = temp;

    getline(sstring, temp, ',');
    num = stoi(temp);

    getline(sstring, temp, ',');
    freguesia = temp;

    getline(sstring, temp, ',');
    codpos = temp;

    getline(sstring, temp);
    loc = temp;
}


void Address::setAddress(string morada)
{
    string temp;
    istringstream sstring(morada);

    getline(sstring, temp, ',');
    rua = temp;

    getline(sstring, temp, ',');
    num = stoi(temp);

    getline(sstring, temp, ',');
    freguesia = temp;

    getline(sstring, temp, ',');
    codpos = temp;

    getline(sstring, temp);
    loc = temp;
}

string Address::getAddressFormated() const
{
    string result = rua + "," + to_string(num) + "," + freguesia + "," + codpos + "," + loc;
    return result;
}

ostream &operator<<(ostream &out, const Address &ad)
{
    out << "Rua:  " << ad.rua << endl
        << "Numero da porta:  " << ad.num << endl
        << "Freguesia: " << ad.freguesia << endl
        << "Codigo Postal:  " << ad.codpos << endl
        << "Localizacao:  " << ad.loc << endl;
    return out;
}

bool Address::operator==(const Address &a1) const
{
    if (a1.rua == rua && a1.num == this->num && a1.loc == loc && a1.codpos == codpos && a1.freguesia == freguesia)
        return true;
    else
        return false;
}