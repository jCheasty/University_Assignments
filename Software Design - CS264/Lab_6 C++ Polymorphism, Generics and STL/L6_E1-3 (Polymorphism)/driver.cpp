// Chapter 10 of C++ How to Program
// driver for vehicle
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

#include <vector>

using std::vector;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"
#include "parkinglot.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    auto *parkingLot = new ParkingLot;
    int state;

    for (int i = 0; i < 10; ++i) {
        state=rand()%4+1;

        if (state== 1) {
            auto *cab = new Taxi(i);
            parkingLot->addVehicle(cab);
            cab->setCustomers(true);
        }
        else if(state==2){
            auto *mack = new Truck(i);
            parkingLot->addVehicle(mack);
            mack->setCargo(true);
        }
        else if(state==3){
            auto *cab = new Taxi(i);
            parkingLot->addVehicle(cab);
            cab->setCustomers(false);
        }
        else{
            auto *mack = new Truck(i);
            parkingLot->addVehicle(mack);
            mack->setCargo(false);
        }
    }

    parkingLot->printVehicles();
    cout << "There are " << parkingLot->getVehicleCount() << " vehicles in this parking Lot." << endl;
    return 0;

} // end main



/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
