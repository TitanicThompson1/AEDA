#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include "veiculo.h"
using namespace std;

class Frota {
	vector<Veiculo *> veiculos;
public:
    void adicionaVeiculo(Veiculo *v1);
    int numVeiculos()const;
    int menorAno()const;
    vector<Veiculo *> operator () (int anoM) const;
    float totalImposto() const;

    friend ostream & operator<<(ostream & o, const Frota & f);

};

#endif /*FROTA_H_*/
