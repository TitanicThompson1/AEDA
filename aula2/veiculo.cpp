#include "veiculo.h"
#include <iostream>

using namespace std;

//constructor de veiculo
Veiculo::Veiculo(string mc, int m, int a)
{
    marca=mc;
    mes=m;
    ano=a;
}

int Veiculo::getAno() const
{
    return ano;
}

int Veiculo::info() const
{
    cout << "Marca:  " << marca << endl;
    cout << "Mes:  " << mes << endl;
    cout << "Ano:  " << ano << endl;
    return 3;

}
ostream& Veiculo::info(ostream & o ) const
{
    o << "Marca:  " << marca << endl;
    o << "Mes:  " << mes << endl;
    o << "Ano:  " << ano << endl;
    return o;
}

string Veiculo::getMarca() const
{
    return marca;
}

bool Veiculo::operator<(const Veiculo &v) const
{
    if((ano<v.ano)|| (ano==v.ano && mes<v.mes))
        return true;
    return false;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil): Veiculo(mc,m,a)
{
    combustivel=c;
    cilindrada=cil;
}

int Motorizado::info() const
{
    int result;
    result=Veiculo::info();
    cout << "Combustivel:  " << combustivel << endl;
    cout << "Cilindrada:  " << cilindrada << endl;
    return result+2;
}

ostream& Motorizado::info(ostream & o) const
{
    Veiculo::info(o);
    cout << "Combustivel:  " << combustivel << endl;
    cout << "Cilindrada:  " << cilindrada << endl;
    return o;
}


string Motorizado::getCombustivel() const {return combustivel;}

float Motorizado::calcImposto() const
{
    if (ano>1995)
    {
        if((combustivel=="gasolina" && cilindrada<=1000) || combustivel=="outro" && cilindrada<=1500)
            return 14.56;
        else if((combustivel=="gasolina" && cilindrada<=1300) || combustivel=="outro" && cilindrada<=2000)
            return 29.06;
        else if ((combustivel=="gasolina" && cilindrada<=1750) || combustivel=="outro" && cilindrada<=3000)
            return 45.15;
        else if ((combustivel=="gasolina" && cilindrada<=2600) || combustivel=="outro" && cilindrada>3000)
            return 113.98;
        else if (combustivel=="gasolina" && cilindrada<=3500)
            return 181.17;
        else if (combustivel=="gasolina" && cilindrada>3000)
            return 320.89;

    }
    else
    {
        if((combustivel=="gasolina" && cilindrada<=1000) || combustivel=="outro" && cilindrada<=1500)
            return 8.10;
        else if((combustivel=="gasolina" && cilindrada<=1300) || combustivel=="outro" && cilindrada<=2000)
            return 14.56;
        else if ((combustivel=="gasolina" && cilindrada<=1750) || combustivel=="outro" && cilindrada<=3000)
            return 22.65;
        else if ((combustivel=="gasolina" && cilindrada<=2600) || combustivel=="outro" && cilindrada>3000)
            return 54.89;
        else if (combustivel=="gasolina" && cilindrada<=3500)
            return 87.13;
        else if (combustivel=="gasolina" && cilindrada>3000)
            return 148.37;
    }
}


Automovel::Automovel(string mc, int m, int a, string c, int cil): Motorizado(mc, m, a, c, cil){}

int Automovel::info() const {return Motorizado::info();}

ostream& Automovel::info(ostream &o) const { return Motorizado::info(o);}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm):Motorizado(mc, m, a, c, cil) , carga_maxima(cm){}

int Camiao::info() const
{
    int result=Motorizado::info();
    cout << "Carga Maxima:  " << carga_maxima << endl;
    return result + 1;
}

ostream& Camiao::info(ostream &o) const
{
    Motorizado::info(o);
    o << "Carga Maxima:  " << carga_maxima << endl;
    return o;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t):Veiculo(mc,m,a), tipo(t) {}

int Bicicleta::info() const
{
    int result=Veiculo::info();
    cout << "Tipo:  " << tipo << endl;
    return result + 1;
}

ostream& Bicicleta::info(ostream &o) const
{
    Veiculo::info(o);
    o << "Tipo:  " << tipo << endl;
    return o;
}

float Bicicleta::calcImposto() const { return 0;}






