#ifndef OBSERVABLE_H
#define OBSERVABLE_H

namespace model{

class Observer;

/** \Observable
 *
 * @brief The Observable class is one of the two classes for
 * implement the patron Observer/Observable
 *
 * This class allows to implement the method necessary to implement
 * the Observable class
 *
 */
class Observable{

protected:

    /**
     * @brief listObserver_
     *
     * This attribute is the list of observer who are registered
     * as observer
     */
    std::vector<Observer *> listObserver_;

public:

    /**
     * @brief ~Observable
     *
     * This method is the destructor of the class observable
     * This method is virtual
     */
    virtual ~Observable() {}

    /**
     * @brief addObserver
     *
     * This method allows to add an Observer at the vector listObserver_
     *
     * @param observer is the Observer to add at the listObserver_
     */
    void addObserver(Observer* observer);

    /**
     * @brief delObserver
     *
     * This method allows to delete an Observer at the vector listObserver_
     *
     * @param observer is the Observer to delete at the listObserver_
     */
    void delObserver(Observer* observer);


protected:

    /**
     * @brief notifyObserver
     *
     * This method allows to notify each Observer present in the listObserver_
     * This method is virtual
     *
     */
    virtual void notifyObserver();



};

}

#endif // OBSERVABLE_H
