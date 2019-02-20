#ifndef TIME_H
#define TIME_H

namespace model {

/** \Time
 * @brief The Time class
 *
 * This class allows to build and manage the time of a part of game
 *
 */
class Time
{

public:

    /**
     * @brief Time
     *
     * This is the constructor of the class Time without parameter
     */
    Time();

    /**
     * @brief Time
     *
     * This is the constructor of the class Time with an integer parameter
     *
     * @param time is an integer to attribuate and build the time
     */
    Time(int time);

    //const de recopie
    /**
     * @brief Time
     *
     * This is the constructor by copy of the class Time
     *
     * @param time is the constant Time valor to copy to a new time
     * with the same valor
     */
    Time(const Time &time);

    /**
     * @brief ~Time
     *
     * This is the destructor of the class Time
     * This destructor is by default
     */
    ~Time()=default;

    /**
     * @brief getTimePassed
     *
     * This is a getter to know the valor of the Time
     *
     * @return a double to represent the valor of the time
     */
    double getTimePassed();

    /**
     * @brief resetTimePassed
     *
     * This method allows to reset the valor of the time at zero
     */
    void resetTimePassed();

private:

    /**
     * @brief timePassed_
     *
     * This attribute is a double of the valor of the Time passed
     *
     */
    double timePassed_;
};


}



#endif // TIME_H
