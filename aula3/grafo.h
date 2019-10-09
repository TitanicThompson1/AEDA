#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

/**Classe Nós
 *
 * @tparam N
 * @tparam A
 */
template <class N, class A>
class No {
public:
    /*Nome do nó*/
	N info;

	/*Arestas que começam no nó*/
	vector< Aresta<N,A> > arestas;

	/*Construtor da classe nó*/
	No(N inf) {
		info = inf;
	}
};

/**Classe Aresta
 *
 * @tparam N
 * @tparam A
 */
template <class N, class A>
class Aresta {
public:
    /*Valor da aresta*/
	A valor;

	/*Nó de destino*/
	No<N,A> *destino;

	/*Construtor de da classe Aresta*/
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};
/**
 * Classe Grafo
 * @tparam N
 * @tparam A
 */
template <class N, class A> 
class Grafo {
    /*Vector de pointers que apontam para os nós do grafo*/
	vector< No<N,A> *> nos;
  public:
    /*Construtor da classe Grafo*/
    Grafo();

    /*Desconstrutor da classe Grafo*/
    ~Grafo();

    /**Insere um nó no grafo
     *
     * @param dados Info do nó a inserir
     * @return Grafo com o nó acrescentado
     */
    Grafo & inserirNo(const N &dados);

    /**Insere uma aresta no grafo
     *
     * @param inicio Nó onde a aresta inicia
     * @param fim Nó onde a aresta acaba
     * @param val Valor da aresta a acrescentar
     * @return Grafo com a aresta acrescentada
     */
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);

    /**Elimina uma aresta do grafo
     *
     * @param inicio Nó onde a aresta inicia
     * @param fim Nó onde a aresta acaba
     * @return Grafo com a aresta removida
     */
    Grafo & eliminarAresta(const N &inicio, const N &fim);

    /**Retorna o valor de uma dada aresta do grafo
     *
     * @param inicio Nó onde a aresta inicia
     * @param fim Nó onde a aresta acaba
     * @return Valor da aresta pretendida
     */
    A & valorAresta(const N &inicio, const N &fim);

    /**Retorna o número de arestas existentes no grafo
     *
     * @return Numero de arestas no grafo
     */
    int numArestas(void) const;

    /**Retorna o número de nós existentes no grafo
     *
     * @return Numero de nós no grafo
     */
    int numNos(void) const;

    /**Escreve, para um stream de saída, a informação do grafo
     *
     * @param os stream de saida
     */
    void imprimir(std::ostream &os);

};

/**Overload do operator<<. Dá display numa formatação predefina
 *
 * @tparam N
 * @tparam A
 * @param out stream de saida
 * @param g Grafo a fazer display
 * @return stream de saida com informação formatada
 */
template <class N, class A>
std::ostream & operator<<(std::ostream &out, Grafo<N,A> &g/*Ver como a prof fez com const*/){

    g.imprimir(out);
    return out;
}



/**Exceção NoRepetido
 *
 * @tparam N
 */
template <class N>
class NoRepetido
{
public:

   N info;

   NoRepetido(N inf) { info=inf; }
};

/**Overload do operator << para a exceção NoRepetido. Dá display numa formatação predefina
 *
 * @tparam N
 * @param out stream de saida
 * @param no nodulo repetido
 * @return stream de saida com informção formatada
 */
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


/** Excecao NoInexistente
 *
 * @tparam N
 */
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

/**Overload do operator << para a exceção NoInexistente. Dá display numa formatação predefina
 *
 * @tparam N
 * @param out stream de saida
 * @param ni nodulo inexistente
 * @return stream de saida com informção formatada
 */
template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

/**Excecao ArestaRepetida
 *
 * @tparam N
 */
template <class N>
class ArestaRepetida {
public:

    N IniInfo, FimInfo;
    ArestaRepetida(N IniInf,N FimInf){
        IniInfo=IniInf;
        FimInfo=FimInf;
    }
};

/**Excecao ArestaInexistente
 *
 * @tparam N
 */
template <class N>
class ArestaInexistente {
public:

    N IniInfo, FimInfo;
    ArestaInexistente(N IniInf,N FimInf){
        IniInfo=IniInf;
        FimInfo=FimInf;
    }
};

/**Overload do operator << para a exceção ArestaRepetida. Dá display numa formatação predefina
 *
 * @tparam N
 * @param out stream de saida
 * @param aresta aresta repetida
 * @return stream de saida com informção formatada
 */
template < class N>
ostream & operator<<(ostream &out, const ArestaRepetida<N> aresta )
{
    return out << "Aresta repetida: "<< aresta.IniInfo << " , " << aresta.FimInfo;
}

/**Overload do operator << para a exceção ArestaInexistente. Dá display numa formatação predefina
 *
 * @tparam N
 * @param out stream de saida
 * @param aresta aresta inexistente
 * @return stream de saida com informção formatada
 */
template < class N>
ostream & operator<<(ostream &out, const ArestaInexistente<N> aresta )
{
    return out << "Aresta inexistente: "<< aresta.IniInfo << " , " << aresta.FimInfo;
}

//Construtor e destrutor de Grafo

template <class N, class A>
Grafo<N,A>::Grafo()
{
    vector<No<N,A> *> n;
    nos = n;

}


template <class N, class A>
Grafo<N,A>::~Grafo()
{
    for(int i=0;i<nos.size();i++)
        delete nos.at(i);


}

//Outros Metodos

template <class N, class A>
int Grafo<N,A>::numNos() const{ return nos.size();}


template <class N, class A>
int Grafo<N,A>::numArestas() const
{
    int soma=0;

    for(int i=0;i<nos.size();i++)
    {

        soma+=(*nos.at(i)).arestas.size();
    }
    return soma;
}

template <class N, class A>
Grafo<N,A>& Grafo<N,A>::inserirNo(const N &dados)
{
    No<N,A>  *novoNo= new No<N,A> (dados);
    bool found=false;
    int i;

    for(int i=0;i<nos.size();i++)
    {
        if (nos.at(i)->info==novoNo->info)
           throw NoRepetido<N>(dados);

    }
    nos.push_back(novoNo);
    return *this;


}

template <class N, class A>
Grafo<N,A> & Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val)
{
    bool found1=false, found2=false;
    int indIni,indFim;
    for(int i=0;i<nos.size();i++)
    {
        if (nos.at(i)->info==inicio){
            found1=true;
            indIni=i;
        }
        else if (nos.at(i)->info==fim){
            found2=true;
            indFim=i;

        }
    }
    if(!found1)
        throw NoInexistente<N>(inicio);
    else if(!found2)
        throw NoInexistente<N>(fim);

    for(int i=0;i<nos.at(indIni)->arestas.size();i++)
    {
        if(nos.at(indIni)->arestas.at(i).destino->info==fim)
            throw ArestaRepetida<N>(inicio,fim);
    }



    Aresta<N,A> a (nos.at(indFim),val);
    nos.at(indIni)->arestas.push_back(a);

    return *this;

}

template <class N, class A>
A & Grafo<N,A>::valorAresta(const N &inicio, const N &fim)
{
    bool found1N=false;
    for(int i=0;i<nos.size();i++)
    {
        if(nos.at(i)->info==inicio)
        {
            found1N=true;
            for(int j=0;j<nos.at(i)->arestas.size();j++)
            {
                if(nos.at(i)->arestas.at(j).destino->info==fim){
                    return nos.at(i)->arestas.at(j).valor;
                }
            }

        }

    }
    if (!found1N)
        throw NoInexistente<N>(inicio);
    else
        throw ArestaInexistente<N>(inicio,fim);

}
template <class N,class A>
Grafo<N,A> & Grafo<N,A>::eliminarAresta(const N &inicio, const N &fim)
{
    bool found1N=false;
    for(int i=0;i<nos.size();i++)
    {
        if(nos.at(i)->info==inicio)
        {
            found1N=true;
            for(int j=0;j<nos.at(i)->arestas.size();j++)
            {
                if(nos.at(i)->arestas.at(j).destino->info==fim){
                    nos.at(i)->arestas.erase(nos.at(i)->arestas.begin()+j);
                    return *this;
                }
            }

        }

    }
    if (!found1N)
        throw NoInexistente<N>(inicio);
    else
        throw ArestaInexistente<N>(inicio,fim);
}

template <class N,class A>
void Grafo<N,A>::imprimir(std::ostream &os)
{
    for(int i=0;i<nos.size();i++)
    {
        os << "( " << nos.at(i)->info << " ";
        for(int j=0;j<nos.at(i)->arestas.size();j++)
        {
            os << "[" << nos.at(i)->arestas.at(j).destino->info << " " << nos.at(i)->arestas.at(j).valor << "] ";
        }
        os << ") ";
    }
}

