#ifndef _ANIMAL
#define _ANIMAL

#include <string>
#include <AnimalShelter.h>

class Animal
{
public:
    int getOrder() { return order; }
    std::string getName() { return name; }

    virtual void getAdopted(AnimalShelter& shelter) = 0;
    
    void setOrder()
    {
        order = Animal::getUniqueAnimalOrder();
    }

protected:
    Animal(std::string name) : name(name) {}

private:
    std::string name;
    int order;

    static int getUniqueAnimalOrder()
    {
        static int animalOrder = 0;
        
        int res = animalOrder;
        animalOrder++;

        return res;
    }

};

#endif
