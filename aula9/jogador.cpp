#include "jogador.h"

//a alterar
void Jogador::adicionaAposta(const Aposta & ap)
{
    apostas.insert(ap);
}

//a alterar
unsigned Jogador::apostasNoNumero(unsigned num) const
{
    unsigned res=0;
    tabHInt tbl;
    for(auto it=apostas.begin();it!=apostas.end();it++){
        tbl = it->getNumeros();
        if(tbl.find(num)!=tbl.end()){
            res++;
        }
    }
	return res;
}

//a alterar
tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;
	tabHInt tbl;
	unsigned n;
	for(auto it=apostas.begin();it!= apostas.end();it++){
	    n=0;
	    tbl=it->getNumeros();
	    for(auto it1=sorteio.begin();it1!=sorteio.end();it1++){
	        if(tbl.find(*it1) != tbl.end()){
	            n++;
	        }
	    }
	    if(n>3){
	        money.insert(*it);
	    }
	}
	return money;
}
