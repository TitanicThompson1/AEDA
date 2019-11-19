/*
 * Doctor.cpp
 */

#include "Doctor.h"


Patient::Patient(unsigned codP, string mS): codeP(codP), medicalSpecialty(mS)
{}

string Patient::getMedicalSpecialty() const {
	return medicalSpecialty;
}

unsigned Patient::getCode() const {
	return codeP;
}

Doctor::Doctor(unsigned codM, string mS): codeM(codM), medicalSpecialty(mS)
{}


Doctor::Doctor(unsigned codM, string mS, queue<Patient> patients1): codeM(codM), medicalSpecialty(mS), patients(patients1)
{}

unsigned Doctor::getCode() const {
	return codeM;
}

string Doctor::getMedicalSpecialty() const {
	return medicalSpecialty;
}

queue<Patient> Doctor::getPatients() const {
	return patients;
}

void Doctor::addPatient(const Patient &p1) {
	patients.push(p1);
}

Patient Doctor::removeNextPatient() {
	if (!patients.empty()) {
		Patient p1 = patients.front();
		patients.pop();
		return p1;
	}
	else throw PatientInexistent();
}




void Doctor::moveToFront(unsigned codP1) {
    list<Patient> temp;

	while(patients.size()!=0){
	    if(patients.front().getCode()!=codP1)
	        temp.push_back(patients.front());
	    else
	        temp.push_front(patients.front());
        patients.pop();
	}

	for(auto it=temp.begin();it!=temp.end();it++){
	    patients.push(*it);
	}
}

bool Doctor::operator< (Doctor &d){
    if(patients.size() < d.patients.size()){
        return true;
    }else if(patients.size() ==  d.patients.size() && medicalSpecialty < d.medicalSpecialty){
        return true;
    } else if(patients.size() ==  d.patients.size() && medicalSpecialty == d.medicalSpecialty && codeM < d.codeM){
        return true;
    }else {
        return false;
    }
}

