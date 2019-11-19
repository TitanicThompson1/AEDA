#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include <string>
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
    bool avariados[3]  = {true,false,false};

    srand (1);   //Criar Pistas e Karts de Teste
    for(int i=1;i<=50;i++){
        vector<CKart> frota;
        for(int j=1;j<=50;j++){
            frota.push_back(CKart(avariados[rand()% 3],
                                  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
        }
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}


vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}
 
//Exercicio 1 a)     
vector<CKart> CGrupo::ordenaKarts()
{
	vector<CKart> vord,temp;

	for(int i=0;i<this->pistasG.size();i++){

	    temp=this->pistasG.at(i).getFrotaActual();
	    for(int j=0;j<temp.size();j++){
	        vord.push_back(temp.at(i));
	    }

	}

	sort(vord.begin(),vord.end());
	return vord;
    
}

//Exercicio 1 b)  
int CGrupo::numAvariados(int cilind)
{
    vector<CKart> temp;
    int res=0;

    for(int i=0;i<pistasG.size();i++){

        temp=pistasG.at(i).getKartsAvariados();
        for(int j=0;j<temp.size();j++){
            if(temp.at(j).getCilindrada()==cilind){
                res++;
            }
        }

    }

    return res;
}

//Exercicio 1 c)   
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    queue<CKart> temp;
    int n=0;
    for(int i=0;i<frotaKartsPista.size();i++){
        CKart Ktemp=frotaKartsPista.at(i);
        temp.push(Ktemp);
        if(frotaKartsPista.at(i).getCilindrada()==cilind && !frotaKartsPista.at(i).getAvariado()){
            kartsLinhaPartida.push(Ktemp);
            n++;
        }

    }
    return n>=numeroKarts;


}

//Exercicio 1 d) 
int CPista::inicioCorrida()
{
    int n=0;
    int size=kartsLinhaPartida.size();
    for(int i=0;i<size;i++){
        //CKart temp=kartsLinhaPartida.front();
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
        n++;
    }
    return n;
}


bool CKart::operator<(CKart &kart){
    if(this->getNumero() < kart.getNumero())
        return true;
    return false;
}
