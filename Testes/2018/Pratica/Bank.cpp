/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
    double res=0;
    for(int i=0;i<accounts.size();i++){
        if(accounts.at(i)->getCodH()==cod1)
            res+=accounts.at(i)->getWithdraw();
    }
	return res;

}


// a alterar
vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res;
    auto it=bankOfficers.begin();
    while(it!=bankOfficers.end() && it->getName()!=name )
    {
	    it++;
    }
	if(it==bankOfficers.end())
	    return res;

	res=it->getAccounts();
	bankOfficers.erase(it);
	return res;
}


// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    BankOfficer *bo= new BankOfficer();
    int ind=-1;
    for(int i=0;i<bankOfficers.size();i++)
    {
        if(name==bankOfficers.at(i).getName()){
            ind=i;
            bo=&bankOfficers.at(i);
            break;
        }
    }
    if(ind==-1)
        throw NoBankOfficerException(name);
    bankOfficers.at(ind).addAccount(ac);
    return *bo;

}

bool ordena(Account *a1  , Account *a2 ){
    if(a1->getBalance()<a2->getBalance())
        return true;
    else if(a1->getBalance()==a2->getBalance() && a1->getCodIBAN()<a2->getCodIBAN())
        return true;
    return false;

}

void Bank::sortAccounts() {

    sort(accounts.begin(),accounts.end(),ordena);

}

