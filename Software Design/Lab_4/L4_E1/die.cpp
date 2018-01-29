#include "die.h"

Die::Die(int in) {
    if(in<4){
        this->sides = 6;
        cerr<<"Error - Less than 4 sides, defaulting to 6 sides."<<endl;
    }
    else
        this->sides=in;
    srand(static_cast<unsigned int>(time(nullptr)));
}

Die::~Die() {
    cout<<"Destroying Object";
}

int Die::getNumSides(){
    return sides;
}

int Die::getValue(){
    return (roll()+roll());
}

int Die::roll(){
    return rand()%sides+1;
}