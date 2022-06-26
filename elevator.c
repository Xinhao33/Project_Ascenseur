#include "elevator.h" 
#include <stdlib.h>

Elevator* create_elevator(int capacity, int currentFloor, PersonList *persons)
{
    Elevator* res = malloc(sizeof(Elevator));
    res -> capacity = capacity;
    res -> currentFloor = currentFloor;
    res -> targetFloor = currentFloor;
    res -> persons = persons;

    return res;

}

Building* create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
    Building* res = malloc(sizeof(Building));
    res -> nbFloor = nbFloor;
    res -> elevator = elevator;
    res -> waitingLists = waitingLists;

    return res;
}
