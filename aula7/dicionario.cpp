#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}


bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
    if (palavra <  ps1.palavra)
        return true;
    else
        return false;
}

ostream& operator<< (ostream& out, const PalavraSignificado &p1){
    out << p1.palavra << endl
        << p1.significado;
    return out;
}


void Dicionario::lerDicionario(ifstream &fich)
{
    string pal,sign;
    while(!fich.eof())
    {
        getline(fich,pal);
        getline(fich,sign);
        PalavraSignificado temp(pal,sign);
        palavras.insert(temp);
    }
    return;
}

//a alterar
string Dicionario::consulta(string palavra) const
{
    auto it=palavras.begin(),ait=it;
    for (it;it!=palavras.end();it++){
        if((*it).getPalavra()==palavra){
            return (*it).getSignificado();
        }else if(palavra < (*it).getPalavra())
            break;
        ait=it;
    }


    if(it!=palavras.end()) {
        throw PalavraNaoExiste((*ait), (*it));
    }else
        throw PalavraNaoExiste((*ait),PalavraSignificado("",""));



}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    return true;
}

//a alterar
void Dicionario::imprime() const
{
    palavras.printTree();
}

