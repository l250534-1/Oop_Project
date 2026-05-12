#pragma once
#include <string>
using namespace std;

class Venue 
{
private:
    string roomId;
    int capacity;
    bool hasComputers;

public:
    Venue();
    Venue(string roomId, int capacity, bool hasComputers);
    bool canAccommodate(int studentCount);
    void display();
    string getRoomId();
    int getCapacity();
    bool getHasComputers();
};
