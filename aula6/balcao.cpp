#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

//a alterar
Cliente::Cliente() {
    numPresentes= rand()%5 + 1;
}

//a alterar
int Cliente::getNumPresentes() const {
    return numPresentes;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {
    tempo_atual=0;
    prox_chegada=rand()%20+1;
    prox_saida=0;
    clientes_atendidos=0;
}

//a alterar
void Balcao:: proximoEvento()
{
    int prev;
    if(prox_saida>prox_chegada || prox_saida==0){
        tempo_atual=prox_chegada;
        chegada();
    }
    else {
        saida();
        tempo_atual=prox_saida;

    }



}

//a alterar
void Balcao::chegada()
{
    Cliente c1;

    if(clientes.empty()){
        prox_saida= tempo_atual + c1.getNumPresentes()*tempo_embrulho;
    }
    clientes.push(c1);
    prox_chegada= tempo_atual + rand() % 20 + 1;

    printf("tempo= %d\nchegou novo cliente com %d presentes\n", tempo_atual,c1.getNumPresentes());
}

//a alterar
void Balcao::saida()
{
    if(clientes.empty())
        throw FilaVazia();
    printf("tempo= %d\nsaiu um cliente com %d presentes\n", tempo_atual,clientes.front().getNumPresentes());
    clientes.pop();
    if(clientes.empty()){
        prox_saida=0;
    }else{
        prox_saida= tempo_atual + clientes.front().getNumPresentes()*tempo_embrulho;
    }
    clientes_atendidos++;

}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

//a alterar
int Balcao::getTempoEmbrulho() const {
	return tempo_embrulho;
}

//a alterar
int Balcao::getProxSaida() const {
	return prox_saida;
}


int Balcao::getClientesAtendidos() const {
	return clientes_atendidos;
}

//a alterar
Cliente & Balcao::getProxCliente() {
    if(clientes.empty())
        throw FilaVazia();

    return clientes.front();
}

      
