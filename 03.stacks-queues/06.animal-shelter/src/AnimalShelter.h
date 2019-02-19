#ifndef _ANIMAL_SHELTER_H
#define _ANIMAL_SHELTER_H

#include <memory>
#include <pstructs/queue.h>

class Animal;
class Dog;
class Cat;

class AnimalShelter
{
public:
    void enqueue(std::shared_ptr<Dog> dog);
    void enqueue(std::shared_ptr<Cat> cat);
    
    std::shared_ptr<Animal> dequeueAny();
    std::shared_ptr<Cat> dequeueCat();
    std::shared_ptr<Dog> dequeueDog();
    
    bool anyAnimalsLeft();

private:
    pstructs::queue<std::shared_ptr<Cat> > cats;
    pstructs::queue<std::shared_ptr<Dog> > dogs;
};

#endif
