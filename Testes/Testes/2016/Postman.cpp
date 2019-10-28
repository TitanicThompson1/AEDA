/*
 * Postman.cpp
 */
#include "Postman.h"

unsigned int Postman::lastId=0;

Postman::Postman(): id(0) {}
Postman::Postman(string name)
{
    id=++lastId;
    this->name=name;

}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

bool Postman::operator<(Postman &p1){
    unsigned int temp1=0,temp=0;
    vector<string> zip,zip1;

    for(int i=0;i<p1.myMail.size();i++){
        zip1.push_back(p1.myMail.at(i)->getZipCode());
    }

    for(int i=0;i<myMail.size();i++){
        zip.push_back(myMail.at(i)->getZipCode());
    }

    temp1 = numberDifferent(zip1);
    temp = numberDifferent(zip);

    if(temp<temp1)
        return true;

    return false;
}




