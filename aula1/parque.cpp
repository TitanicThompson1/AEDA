#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : numMaximoClientes(nMaxCli), lotacao(lot)
{
    vagas= lot;
    vector<InfoCartao> cli;
    clientes= cli;

}
unsigned int ParqueEstacionamento::getNumLugares() const
{
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const
{
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const
{
    for(int i=0;i<clientes.size();i++)
    {
        if(clientes.at(i).nome==nome)
        {
            return i;
        }
    }
    return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome)
{
    if(clientes.size()==numMaximoClientes)
    {
        return false;
    }
    InfoCartao novo;
    novo.nome=nome;
    novo.presente= false;
    clientes.push_back(novo);
    return true;

}

bool ParqueEstacionamento::entrar(const string &nome)
{
    int pos=posicaoCliente(nome);
    if (pos==-1 or clientes.at(pos).presente or vagas==0)
    {
        return false;
    }
    vagas--;
    clientes.at(pos).presente=true;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome)
{
    int pos= posicaoCliente(nome);
    if (pos==-1 or clientes.at(pos).presente==true)
    {
        return false;
    }
    clientes.erase(clientes.begin() + pos);
    return true;
}

bool ParqueEstacionamento::sair(const string & nome)
{
    int pos= posicaoCliente(nome);
    if (pos==-1 or clientes.at(pos).presente==false)
    {
        return false;
    }
    clientes.at(pos).presente=false;
    return true;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const
{
    return lotacao-vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const
{
    return clientes.size();
}