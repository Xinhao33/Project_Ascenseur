#include "person.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Person* createPerson(int src, int destination)
{
    Person *res = malloc(sizeof(Person));
    res -> src = src;
    res -> dest = destination;
    

    return res;

}

PersonList* insert(Person *p, PersonList *list)
{
    PersonList *res = malloc(sizeof(PersonList));
    res -> person = p;
    res -> next = list; 
    
    return res; 
}




 


    