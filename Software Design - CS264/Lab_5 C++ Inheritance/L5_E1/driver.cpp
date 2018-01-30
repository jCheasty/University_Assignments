// Chapter 9 of C++ How to Program
// driver for race car and car
#include <iostream>

using std::cout;
using std::endl;

#include "car.h"
#include "racecar.h"

/*Develop a Racecar class that inherits publicly for a class Car, which represents
a car by its maximum speed, the number of engine valves, its colour and its name. A
Racecar is distinguished by its gearbox (the number of gears it has), its sponsor and the
presence of a parachute.
To complete this problem you should use the template code in the Exercise1 directory as a
starting point. Comments in each of the files will guide you through the functionality and definitions
that need to be added. The driver.cpp file contains a main method that you can use
to test your solution. The result of running this code should look something like the following:

chevy:
Car: Chevrolette is black and has a 4-valve engine. MAX SPEED = 95 mph.

f1:
Car: Ferrari is red and has a 40-valve engine. MAX SPEED = 220 mph.
Ferrari also has 7 gears and is sponsored by Bug2Bug.
Ferrari has used its parachute.
*/

int main()
{
    Car chevy( "Chevrolette", "black" );

    cout << "chevy: \n";
    chevy.print();

    Racecar f1( "Ferrari", "red", "Bug2Bug" );

    f1.setEngineValves( 40 );
    f1.setMaxSpeed( 220 );
    f1.setGearbox( 7 );
    f1.useParachute();

    cout << "\n\nf1: \n";
    f1.print();

    return 0;

} // end main


/*Output:

chevy:
Car: Chevrolette is black and has a 4-valve engine. MAX SPEED = 95 mph.


f1:
Car: Ferrari is red and has a 40-valve engine. MAX SPEED = 220 mph.
Ferrari also has 7 gears and is sponsored by Bug2Bug.
Ferrari has used its parachute.

Process finished with exit code 0


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