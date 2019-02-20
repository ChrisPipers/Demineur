#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

#include "headers/observer/observable.h"

namespace model {

class Observable;

class Observer
{
private:

public:

    virtual void update()=0;

    virtual ~Observer();

};

}
#endif // OBSERVER_H
