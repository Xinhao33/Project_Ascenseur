#include "elevator.h"
#include "person.h"
#include <stddef.h>
#include <stdio.h>
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

int len_perlist(PersonList* p){
    PersonList* actuel = p;
    int len = 0;
    while (actuel != NULL) {
        len += 1;
        actuel = actuel -> next;
    }
    return len;
}


PersonList* exitElevator(Elevator *e){
    PersonList* actuel = e -> persons;
    PersonList* res = NULL;
    PersonList* rest = NULL;


    while (actuel != NULL) {
        if (actuel -> person -> dest == e-> currentFloor){
            res = insert(actuel -> person, res);
        }
        else {
            rest = insert(actuel -> person, rest);
        }
        actuel = actuel -> next;
    }
    
    while (rest != NULL) {
        actuel = insert(rest -> person, actuel);
        rest = rest -> next;
    }
    e -> persons = actuel;
    return res;
};


PersonList* enterElevator(Elevator *e, PersonList *list){
    int pointeur = e -> capacity - len_perlist(e -> persons);
    while ((pointeur != 0) && (list != NULL)){
        e ->persons = insert(list -> person, e -> persons);
        pointeur -= 1;
        list = list -> next;
    }
    return list; 
};




