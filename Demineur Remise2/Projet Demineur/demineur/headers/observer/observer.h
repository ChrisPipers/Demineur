#ifndef OBSERVER_H
#define OBSERVER_H

namespace model {

class Observable;

/** \Observer
 *
 * @brief The Observer class is one of the two classes for
 * implement the patron Observer/Observable
 *
 * This class allows to implement the method necessary to implement
 * the Observable class
 *
 */
class Observer{

public:

    /**
     * @brief Observer
     *
     * This method is the constructor of the class
     * This is the constructor by default
     *
     */
    Observer()=default;

    /**
     * @brief update
     *
     * This method is virtual, is implement in each class inherited
     * the class Observer, each class implement this method how
     * update her valor according the situation
     *
     */
    virtual void update()=0;

    /**
     * @brief ~Observer
     *
     * This is the destructor of the class
     * This method is virtual
     */
    virtual ~Observer(){}

};

}

#endif // OBSERVER_H
