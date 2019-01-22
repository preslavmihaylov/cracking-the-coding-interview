#include <bits/stdc++.h>
#include <pstructs/queue.h>
#include <AnimalShelter.h>
#include <Cat.h>
#include <Dog.h>

using namespace std;

int main()
{
    AnimalShelter shelter;
    string line;

    getline(cin, line);

    while (line != "exit")
    {
        string cmd;
        string animalType;
        istringstream iss(line);
        iss >> cmd;
        iss >> animalType;
        std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
        std::transform(animalType.begin(), animalType.end(), animalType.begin(), ::tolower);

        if (cmd == "enqueue")
        {
            string name;
            iss >> name;
            
            if (animalType == "dog")
            {
                shelter.enqueue(make_shared<Dog>(name));
            }
            else if (animalType == "cat")
            {
                shelter.enqueue(make_shared<Cat>(name));
            }
            else
            {
                throw invalid_argument("invalid animal type for enqueue");
            }
        }
        else if (cmd == "dequeue")
        {
            if (animalType == "dog")
            {
                cout << shelter.dequeueDog()->getName() << endl;
            }
            else if (animalType == "cat")
            {
                cout << shelter.dequeueCat()->getName() << endl;
            }
            else if (animalType == "any")
            {
                cout << shelter.dequeueAny()->getName() << endl;
            }
            else
            {
                throw invalid_argument("invalid animal type for dequeue");
            }
        }

        getline(cin, line);
    }

    return 0;
}
