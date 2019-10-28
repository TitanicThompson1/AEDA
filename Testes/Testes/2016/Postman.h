/*
 * Postman.h
 */

#ifndef SRC_POSTMAN_H_
#define SRC_POSTMAN_H_

#include "Mail.h"
#include <string>
#include <vector>

class Postman {
	unsigned int id;
	string name;
	vector<Mail *> myMail;
	static unsigned int lastId;
public:
	Postman();
    Postman(string name);
	void setName(string nm);
	void addMail(Mail *m);
	void addMail(vector<Mail *> mails);
	string getName() const;
	vector<Mail *> getMail() const;
	unsigned int getID() const;
	bool operator<(Postman &p1);
};

template<class T>
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



#endif /* SRC_POSTMAN_H_ */
