/*
 * Purchase.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: hlc
 */

#include "Purchase.h"

using namespace std;

Purchase::Purchase(long cli) : client (cli) {
}

long Purchase::getClient() const {
	return client;
}

list< stack<Article*> > Purchase::getBags() const {
	return bags;
}

/**
 * Create an Article associated with the client of this purchase.
 */
Article* Purchase::createArticle(long barCode, bool present, bool deliverHome) {

	Article *a= new Article(client,barCode);
	a->setDeliverHome(deliverHome);
	a->setPresent(present);

	return a;

}

/**
 * Add an Article to the bags of this purchase. A new bag is added when the last bag is full.
 */
void Purchase::putInBag(Article* article) {

	if(bags.back().size()==Purchase::BAG_SIZE || bags.size()==0){
	    stack<Article*> temp;
	    temp.push(article);
	    bags.push_back(temp);
	}else{
        bags.back().push(article);
	}

}

/**
 * Pop from the bags all articles that are presents.
 * All other articles are pushed back into the bags where they were, maintaining order.
 */
vector<Article*> Purchase::popPresents() {

	vector<Article*> presents;

	for(auto it=bags.begin();it!=bags.end();it++){
	    stack<Article *> temp;
	    int tamanho1=it->size();
	    for(int i=0;i<tamanho1;i++){
	        Article *a = it->top();
	        it->pop();
	        if(a->getPresent()){
	            presents.push_back(a);
	        }else{
	            temp.push(a);
	        }
	    }
	    int tamanho=temp.size();
	    for(int i=0;i<tamanho;i++){
            it->push(temp.top());
            temp.pop();

	    }

	}
	return presents;

}

