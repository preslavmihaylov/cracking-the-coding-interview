#ifndef _DOG_H
#define _DOG_H

#include <memory>
#include <string>
#include <Animal.h>
#include <AnimalShelter.h>

class Dog : public Animal
{
public:
    Dog(std::string name) : Animal(name) {}

    void getAdopted(AnimalShelter& shelter)
    {
        shelter.enqueue(std::shared_ptr<Dog>(this));
    }
};

#endif
