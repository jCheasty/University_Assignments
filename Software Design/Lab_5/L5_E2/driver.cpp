// Chapter 9 of C++ How to Program
// driver for inheritance hierarchy
#include <iostream>

using std::cout;
using std::endl;

#include "vehicle.h"
#include "taxi.h"
#include "truck.h"

    /*Develop a class hierarchy of Vehicles. Create two classes, Taxi and Truck,
    that inherit publicly from class Vehicle. A Taxi should contain a data member that
    indicates whether it is carrying passengers. A Truck should contain a data member that
    indicates whether it is carrying cargo. Add the necessary member functions to manipulate
    and access class data. Write a driver that prints a Truck object and a Taxi object to the
    screen (using an overloaded stream-insertion operator).
    To complete this problem you should use the template code in the Exercise2 directory
    as a starting point. Comments in each of the files will guide you through the
    functionality and definitions that need to be added. The driver.cpp file contains a main
    method that provides a partial implementation of the driver code mentioned above. The
    result of running this code should look something like the following:

Vehicle
    Number of doors: 2
    Number of cylinders: 6
    Transmission type: 3
    Colour: blue
    Fuel level: 14.6

Taxi
    Number of doors: 4
    Number of cylinders: 6
    Transmission type: 5
    Colour: yellow
    Fuel level: 3.3
    The taxi currently has no customers

Truck
    Number of doors: 2
    Number of cylinders: 16
    Transmission type: 8
    Colour: black
    Fuel level: 7.54
    The truck is currently carrying cargo.
*/

int main()
{
    Vehicle car( 2, 6, "blue", 14.6, 3 );
    Taxi cab( 3.3 );
    Truck mack( 7.54 );

    mack.setCargo(true);


    cout<<car<<endl<<cab<<endl<<mack;

    return 0;

} // end main

/*Output:

Vehicle
        Number of doors: 2
        Number of cylinders: 6
        Transmission type: 3
        Color: blue
        Fuel level: 14.6

Taxi
        Number of doors: 4
        Number of cylinders: 6
        Transmission type: 5
        Color: yellow
        Fuel level: 3.3
        The taxi has no passengers.

Truck
        Number of doors: 2
        Number of cylinders: 16
        Transmission type: 8
        Color: black
        Fuel level: 7.54
        The truck is carrying cargo.

Process finished with exit code 0
*/

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