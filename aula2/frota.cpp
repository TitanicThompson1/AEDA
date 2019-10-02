#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1)
{
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const
{
    return veiculos.size();
}

int Frota::menorAno() const
{
    if(veiculos.size()==0)
        return 0;
    int menor= veiculos.at(0)->getAno();
    int candidato;
    for(int i=1;i<veiculos.size();i++)
    {
        candidato=veiculos.at(i)->getAno();
        if (candidato<menor)
        {
            menor= candidato;
        }
    }
    return menor;
}

ostream & operator<< (ostream & o, const Frota & f)
{
    int hello;
    for(int i=0;i<f.veiculos.size();i++)
    {
        f.veiculos.at(i)->info(o);
    }
    return o;
}
vector<Veiculo *> Frota::operator()(int anoM) const
{
    vector<Veiculo *> result;
    for(int i=0;i<veiculos.size();i++)
    {
        if (veiculos.at(i)->getAno()==anoM)
            result.push_back(veiculos.at(i));
    }
    return result;
}
float Frota::totalImposto() const
{
    float total;
    for(int i=0;i<veiculos.size();i++)
    {
        total+=veiculos.at(i)->calcImposto();
    }
    return total;
}
