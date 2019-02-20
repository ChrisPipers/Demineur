#include <algorithm>
#include <iostream>
#include <vector>

#include "headers/observer/observable.h"
#include "headers/observer/observer.h"

using namespace std;

namespace model {

void Observable::addObserver(Observer * obs)
{

            listObserver_.push_back(obs);
}

void Observable::delObserver(Observer * obs)
{
    vector<Observer *>::iterator it = find(listObserver_.begin(), listObserver_.end(), obs);
        listObserver_.erase(it);

}

void Observable::notifyObserver()
{

    if (listObserver_.size()!=0)
    {
        for (unsigned i = 0 ; i < listObserver_.size() ; i++)
        {
            listObserver_.at(i)->update();
        }
    }
}



}

