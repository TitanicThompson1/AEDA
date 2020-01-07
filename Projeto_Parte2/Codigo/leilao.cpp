//
// Created by Ricardo Nunes on 01/01/2020.
//

#include "leilao.h"

uint Leilao::lastID = 0;

Leilao::Leilao(priority_queue<ItemLeilao> lic,uint imo,Date fim): im(imo), licitacoes(lic),end(fim) {id=++lastID;}

string Leilao::getBiddingsFormatted() const
{
    string result="";
    priority_queue<ItemLeilao> temp=licitacoes;
    ItemLeilao il;
    int m;
    while(!temp.empty()){
        il=temp.top();
        m=il.getMontante();
        result+=to_string(m) + " " + to_string(il.getLicitador()) + ",";
        temp.pop();
    }
    result.substr(0,result.length()-1);
    return result;
}

priority_queue<ItemLeilao> getBiddingsFromString(string lic){
    istringstream sstring(lic);
    string temp;
    double mont;
    uint idP;
    priority_queue<ItemLeilao> res;

    while(getline(sstring,temp,',')){
        istringstream licit(temp);

        licit >> mont >> idP;
        ItemLeilao il(idP,mont);
        res.push(il);
    }
    return res;
}

ostream& operator<<(ostream& out, const Leilao& im){

    if(im.licitacoes.empty()){
        out << "Ainda nao existem licitacoes!";
        return out;
    }
    priority_queue<ItemLeilao> temp=im.licitacoes;

    ItemLeilao il;
    while(!temp.empty()){
        il=temp.top();
        out << "Montante: " << il.getMontante() << " - " << " ID do licitador: "<< il.getLicitador() << endl;
        temp.pop();
    }
    return out;
}

void Leilao::eraseBidding(uint idP)
{
    priority_queue<ItemLeilao> res;
    ItemLeilao atual;

    while(!licitacoes.empty()){
        atual=licitacoes.top();
        if(atual.getLicitador()!=idP){
            res.push(atual);
        }
        licitacoes.pop();
    }
    licitacoes=res;
}

void Leilao::addBidding(ItemLeilao il)
{
    eraseBidding(il.getLicitador());
    licitacoes.push(il);
}