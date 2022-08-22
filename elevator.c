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


PersonList* exitElevator(Elevator *e){
    PersonList* actuel = e -> persons;
    PersonList* res = NULL;
    PersonList* remain = NULL;
    int destination = actuel ->person ->dest;
    int currentFloor = e ->currentFloor; 
    while (actuel != NULL) {
        if (destination == currentFloor){
            res = insert(actuel -> person, res);
        }
        else {
            remain = insert(actuel -> person, remain);
        }
        actuel = actuel -> next;
    }
    e -> persons = remain;
    return res;
};

int len_perlist(PersonList *list){
  int res = 0;
  while(list != NULL){
    res +=1;
    list = list -> next;
  }
  return res;
}

PersonList* enterElevator(Elevator *e, PersonList *list){
    int pointeur = e -> capacity - len_perlist(e -> persons);
    while ((pointeur != 0) && (list != NULL)){
        e -> persons = insert(list -> person, e -> persons);
        pointeur -= 1;
        list = list -> next;
    }
    return list; 
};

void stepElevator(Building *b);

