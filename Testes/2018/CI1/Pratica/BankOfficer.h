/*
 * BankOfficer.h
 */

#ifndef SRC_BANKOFFICER_H_
#define SRC_BANKOFFICER_H_

#include "Account.h"
#include <string>
#include <vector>

class BankOfficer {
	unsigned int id;
	string name;
	vector<Account *> myAccounts;
public:
    static unsigned int lasID;
	BankOfficer();

	void setName(string nm);
	void addAccount(Account *a);
	void addAccount(vector<Account *> accounts);
	string getName() const;
	vector<Account *> getAccounts() const;
	unsigned int getID() const;

	//-------
	BankOfficer(string nm);
	vector<Account *> removeBankOfficer(string name);
	bool operator> (const BankOfficer &b);
};

template <class T>
unsigned int numberDifferent (const vector<T> & v1){
    vector<T> temp;
    bool found=false;
    if (v1.size()==0)
        return 0;
    temp.push_back(v1.at(0));
    for(int i=1;i<v1.size();i++){
        for(int j=0;j<temp.size();j++){
            if(temp.at(j)==v1.at(i)){
                found=true;
                break;
            }

        }
        if(!found){
            temp.push_back(v1.at(i));
        }
        found=false;
    }
    return temp.size();
}

class NoBankOfficerException
{
private:
    string name;
public:
    NoBankOfficerException(string name){this->name=name;};
    string getName() const {return name;};
};



#endif /* SRC_BANKOFFICER_H_ */
