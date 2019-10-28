/*
 * PostOffice.cpp
 */

#include "PostOffice.h"
#include <string>

PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}

vector<Mail *> PostOffice::removePostman(string name)
{
    vector<Mail *> res;
    auto it=postmen.begin();
    for (it;it!=postmen.end();it++){
        if(it->getName()== name){
            res=it->getMail();
            postmen.erase(it);
            break;
        }

    }
    return res;
}

vector<Mail *> PostOffice::endOfDay(unsigned int &balance){
    balance=0;
    vector<Mail *> res;
    auto it=mailToSend.begin();
    for(it;it!=mailToSend.end();it++){
        balance+=(*it)->getPrice();
        if((*it)->getZipCode()>firstZipCode && (*it)->getZipCode()<lastZipCode){
            addMailToDeliver(*it);
        }else {
            res.push_back(*it);
        }
        it=mailToSend.erase(it);
        it--;
    }
    return res;

}

Postman PostOffice::addMailToPostman(Mail *m, string name)
{
    int i=0;
    for(i;i<postmen.size();i++){
        if(postmen.at(i).getName()==name){
            break;
        }
    }
    if (i==postmen.size())
        throw NoPostmanException(name);
    postmen.at(i).addMail(m);
    return postmen.at(i);
}
