/*
 * Hospital.cpp
 */

#include "Hospital.h"
//
#include <algorithm>


Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
    int count=0;
	for(auto it=doctors.begin();it!=doctors.end();it++){
	    if(it->getMedicalSpecialty()==medicalSpecialty){
	        count+=it->getPatients().size();
	    }
	}
	return count;

}

void Hospital::sortDoctors() {

    doctors.sort();

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
    int cnt=0;
	for(auto it=doctors.begin();it!=doctors.end();it++){
	    if(it->getMedicalSpecialty()==medicalSpecialty1){
	        cnt++;
	    }
	}
	if(cnt>=3)
	    return false;

	Doctor d(codM1,medicalSpecialty1);
	doctors.push_back(d);
	return true;

}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {

	queue<Patient> p1;
	bool encontrou=false;

	for(auto it=doctors.begin();it!=doctors.end();it++){
	    if(it->getCode()==codM1){
	        p1=it->getPatients();
	        doctors.erase(it);
	        encontrou=true;
	        break;
	    }
	}
	if(!encontrou)
	    throw DoctorInexistent();
	return p1;

}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {

    int min,i=0;
    list<Doctor>::iterator doc;
    bool primeiro= true;

    for(auto it=doctors.begin();it!=doctors.end();it++){
        if(it->getMedicalSpecialty()==medicalSpecialty1){
            if(primeiro){
                min=it->getPatients().size();
                doc=it;
                primeiro=false;
            }else if(min>it->getPatients().size()){
                min=it->getPatients().size();
                doc=it;
            }
        }
        i++;
    }
    if(primeiro){
        return false;
    }else{
        Patient p(cod1,medicalSpecialty1);
        doc->addPatient(p);
    }
	return true;

}



void Hospital::processPatient(unsigned codM1) {

    Patient p(1,"ola");
    auto it=doctors.begin();
    /*Find Doctor*/
    for(it;it!=doctors.end();it++){
        if(it->getCode()==codM1){
            try{
                p= it->removeNextPatient();
            }catch (...){
                return;
            }
            break;
        }
    }
    /*Nao encontrou o dotor*/
    if(it==doctors.end())
        return;


    for(auto it2=letterTray.begin();it2!=letterTray.end();it2++){
        if(it2->size()!=trayCapacity){
            it2->push(p);
            return;
        }
    }
    stack<Patient> sp;
    sp.push(p);
    letterTray.push_back(sp);

}


unsigned Hospital::removePatients(unsigned codP1) {
    int cnt=0;

    for(auto it=letterTray.begin();it!=letterTray.end();it++){
        if(it->top().getCode()==codP1){
            it->pop();
            cnt++;
            if(it->empty()){
                it=letterTray.erase(it);
                it--;
            }
        }
    }
	return cnt;

}



