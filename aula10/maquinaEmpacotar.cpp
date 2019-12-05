#include "maquinaEmpacotar.h"
#include <sstream>


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
    unsigned res=0;
    for(auto it=objs.begin();it!=objs.end();it++){
        if(it->getPeso()<=capacidadeCaixas){
            objetos.push(*it);
            objs.erase(it);
            it--;
            res++;
        }
    }
    return res;
}

// a alterar
Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	Caixa cx;
	HEAP_CAIXAS temp;
	bool encontrou=false;

	while(!caixas.empty()){

        if(!encontrou && obj.getPeso() <= caixas.top().getCargaLivre()){
            cx=caixas.top();
            encontrou= true;
        }else{
            temp.push(caixas.top());
        }
        caixas.pop();
	}
    caixas=temp;
	return cx;
}

unsigned MaquinaEmpacotar::empacotaObjetos() {

    Caixa cx;
    Objeto obj(0,0);
    unsigned res=0,size;
    while(!objetos.empty()){

        size=caixas.size();             //utilizado para verificar se houve adição de caixas

        obj=objetos.top();              //objeto a empacotar
        cx = procuraCaixa(obj);         //caixa que se quer por o objeto em

        //adiciona objeto à caixa
        cx.addObjeto(obj);

        //tira o objeto da paleta
        objetos.pop();

        //poe a caixa novamente na fila
        caixas.push(cx);

        if(size != caixas.size()) res++;

    }
	return res;
}


string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {

    HEAP_OBJS temp=objetos;
    ostringstream sres;

    if(temp.empty()){
        return "Nao ha objetos!\n";
    }

    while(!temp.empty()){
        sres << temp.top() << "\n";
        temp.pop();
    }

	return sres.str();
}


Caixa MaquinaEmpacotar::caixaMaisObjetos() const {

    //erra nos testes (id diferente) nao percebo porquê
	Caixa cx;
	if(caixas.empty()) throw MaquinaSemCaixas();

	HEAP_CAIXAS temp=caixas;

	while(!temp.empty()){
        if(temp.top().getSize()>cx.getSize()){
            cx=temp.top();
        }
        temp.pop();
	}

	return cx;
}



