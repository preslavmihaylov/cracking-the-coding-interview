#ifndef _CAT_H
#define _CAT_H

#include <memory>
#include <string>
#include <AnimalShelter.h>
#include <Animal.h>

class Cat : public Animal
{
public:
    Cat(std::string name) : Animal(name) {}

    void getAdopted(AnimalShelter& shelter)
    {
        shelter.enqueue(std::shared_ptr<Cat>(this));
    }
};

#endif
