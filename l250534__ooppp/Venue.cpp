#include "Venue.h"
#include <iostream>
using namespace std;

Venue::Venue()
{
    roomId = "";
    capacity = 0;
    hasComputers = false;
}

Venue::Venue(string roomId, int capacity, bool hasComputers) 
{
    this->roomId = roomId;
    this->capacity = capacity;
    this->hasComputers = hasComputers;
}

bool Venue::canAccommodate(int studentCount) 
{
    return capacity >= studentCount;
}

void Venue::display() {
    cout << "  Room     : " << roomId << endl;
    cout << "  Capacity : " << capacity << endl;
    cout << "  Computers: " << (hasComputers ? "Yes" : "No") << endl;
}

string Venue::getRoomId() {
    return roomId; 
}
int    Venue::getCapacity() {
    return capacity; 
}
bool   Venue::getHasComputers() { 
    return hasComputers; 
}
