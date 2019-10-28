/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <algorithm>

using namespace std;

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle){
    if(vehicles.size()==capacity)
        return false;
    for(int i=0;i<vehicles.size();i++){
        if (*(vehicles.at(i))==*vehicle){
            return false;
        }
    }
    vehicles.push_back(vehicle);
    return true;
}
bool ordena(Car *c1,Car *c2){
    if(c1->getBrand()<c2->getBrand())
        return true;
    else if (c1->getBrand()==c2->getBrand() && c1->getPrice() > c2->getPrice())
        return true;
    return false;

}


template<class Vehicle>
void Garage<Vehicle>::sortVehicles()
{
    sort(vehicles.begin(),vehicles.end(),ordena);
}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model){

    Vehicle *temp;
    auto it=vehicles.begin();
    for(it;it!=vehicles.end();it++){
        if((*it)->getBrand()==brand && (*it)->getModel()==model){
            temp=*it;
            vehicles.erase(it);
        }
    }
    if (it==vehicles.end())
        throw NoSuchVehicleException();
    return temp;
}

class NoSuchBrandException{
    private:
        string brand;
    public:
        NoSuchBrandException(string brand){this->brand=brand;};
        string getBrand(){return brand;};

};

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const{
    float res=0;
    float n=0;
    for(int i=0;i<vehicles.size();i++){
        if (vehicles.at(i)->getBrand()==brand){
            n++;
            res+=vehicles.at(i)->getPrice();
        }
    }
    if(n==0)
        throw NoSuchBrandException(brand);
    return res/n;
}



#endif /* SRC_GARAGE_H_ */
