#include "aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

// a alterar
bool Aposta::contem(unsigned num) const
{
    if(numeros.find(num)==numeros.end())
        return false;
	return true;
}

//a alterar
void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{
    int i=0;
    while (n!=0){

        pair<itrH,bool> ele= numeros.insert(valores.at(i));
        if(ele.second==true){
            n--;
        }
        i++;
    }
}

//a alterar
unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
    unsigned result=0;
    for(auto it=numeros.begin();it!=numeros.end();it++){

        if(sorteio.find(*it)!=sorteio.end()) {
            result++;
        }
    }
    return result;
}





