#include <vector>
#include "vehicle.h"

class ParkingLot {

public:
	ParkingLot();
	virtual ~ParkingLot();

	virtual void addVehicle( Vehicle * );
	virtual	void printVehicles() const;
	virtual	int getVehicleCount() const;

private:
	std::vector< Vehicle * > vehicles;
	int count;

}; 
