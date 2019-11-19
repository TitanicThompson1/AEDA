/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"

unsigned int lastID=0;
BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

// a alterar
BankOfficer::BankOfficer(string name) {
    this->name=name;
    id=++lastID;

}

bool BankOfficer::operator>(const BankOfficer &b)
{
    if(myAccounts.size()>b.getAccounts().size() )
        return true;
    else if(myAccounts.size()==b.getAccounts().size() && name>b.name )
        return true;
    return false;
}


