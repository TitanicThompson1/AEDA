#ifndef VEICULO_H_
#define VEICULO_H_

#include <string>
using namespace std;

class  Veiculo {
protected:
   string marca;
   int mes, ano;
public:
   Veiculo(string mc, int m, int a);
   //virtual ~Veiculo(){};
   int getAno() const;
   string getMarca() const;
   virtual int info() const;
   virtual ostream& info(ostream & o) const;

    bool operator < (const Veiculo & v) const;
   virtual float calcImposto() const = 0;
};

class Motorizado: public Veiculo {
   string combustivel; int cilindrada;
public:
   Motorizado(string mc, int m, int a,string c,int cil);
   string getCombustivel() const;
   //int getCilindrada() const;
   virtual int info() const;
   virtual ostream& info(ostream & o) const;
   float calcImposto() const;
};

class Automovel: public Motorizado {
public:
   Automovel(string mc, int m, int a,string c, int cil);
   int info() const;
   ostream& info(ostream& o) const;
};


class Camiao: public Motorizado {
   int carga_maxima;
public:
   Camiao(string mc, int m, int a,string c, int cil,int cm);
   int info() const;
   ostream& info(ostream& o) const;

};


class Bicicleta: public Veiculo {
  string tipo;
public:
   Bicicleta(string mc, int m, int a,string t);
   int info() const;
   ostream& info(ostream& o) const;
   float calcImposto() const;
};



#endif /* VEICULO_H_ */
