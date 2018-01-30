#include "parkinglot.h"

ParkingLot::ParkingLot() {
    count=0;
}

ParkingLot::~ParkingLot() {}

void ParkingLot::addVehicle(Vehicle* t){
    count++;
    vehicles.push_back(t);
}

void ParkingLot::printVehicles() const {
    for(auto i=vehicles.begin(); i!=vehicles.end(); ++i){
        (*i)->print();
        (*i)->horn();
    }
}

int ParkingLot::getVehicleCount() const {
    return count;
}
