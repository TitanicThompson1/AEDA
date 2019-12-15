#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra() const { return palavra; }
       string getSignificado() const { return significado; }
       void setSignificado(string sig) { significado=sig; }
       bool operator < (const PalavraSignificado &ps1) const;
       friend ostream& operator<< (ostream& out, const PalavraSignificado &p1);
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario(): palavras(PalavraSignificado("","")){};
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);
      void imprime() const;
};

// a alterar
class PalavraNaoExiste
{
private:
    PalavraSignificado pa, pd;
public:
    PalavraNaoExiste(PalavraSignificado ps1,PalavraSignificado ps2): pa(ps1),pd(ps2){};
	string getPalavraAntes() const { return pa.getPalavra(); }
	string getSignificadoAntes() const { return pa.getSignificado(); }
	string getPalavraApos() const { return pd.getPalavra(); }
	string getSignificadoApos() const { return pd.getSignificado(); }
};


#endif
