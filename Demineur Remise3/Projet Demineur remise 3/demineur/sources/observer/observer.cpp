#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include "headers/observer/observable.h"

namespace model {

class Observable;

class Observer
{
public:

    virtual void update(Observable* observable)=0;

    virtual ~Observer()=default;

};

}
#endif // OBSERVER_H
