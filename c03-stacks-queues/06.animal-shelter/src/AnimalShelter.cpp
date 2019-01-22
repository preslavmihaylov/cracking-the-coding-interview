#include <AnimalShelter.h>
#include <Cat.h>
#include <Dog.h>

void AnimalShelter::enqueue(std::shared_ptr<Dog> dog)
{
    dog->setOrder();
    dogs.enqueue(dog);
}

void AnimalShelter::enqueue(std::shared_ptr<Cat> cat)
{
    cat->setOrder();
    cats.enqueue(cat);
}

std::shared_ptr<Animal> AnimalShelter::dequeueAny()
{
    if (dogs.isEmpty()) return std::static_pointer_cast<Animal>(cats.dequeue());
    if (cats.isEmpty()) return std::static_pointer_cast<Animal>(dogs.dequeue());
    
    std::shared_ptr<Dog> dog = dogs.peek();
    std::shared_ptr<Cat> cat = cats.peek();
    
    if (dog->getOrder() < cat->getOrder())
    {
        return dogs.dequeue();
    }
    else
    {
        return cats.dequeue();
    }
}

std::shared_ptr<Cat> AnimalShelter::dequeueCat()
{
    return cats.dequeue();
}

std::shared_ptr<Dog> AnimalShelter::dequeueDog()
{
    return dogs.dequeue();
}

bool AnimalShelter::anyAnimalsLeft()
{
    return dogs.getSize() + cats.getSize() > 0;
}
