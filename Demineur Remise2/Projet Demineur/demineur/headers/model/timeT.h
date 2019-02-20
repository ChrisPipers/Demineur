#ifndef TIME_H
#define TIME_H

namespace model {

/** \Time
 * @brief The Time class
 *
 * This class allows to build and manage the time of a part of game
 *
 */
class TimeT
{

public:

    /**
     * @brief Time
     *
     * This is the constructor of the class Time without parameter
     */
    TimeT();

    /**
     * @brief Time
     *
     * This is the constructor of the class Time with an integer parameter
     *
     * @param time is an integer to attribuate and build the time
     */
    TimeT(int time);

    //const de recopie
    /**
     * @brief Time
     *
     * This is the constructor by copy of the class Time
     *
     * @param time is the constant Time valor to copy to a new time
     * with the same valor
     */
    TimeT(TimeT &time);

    /**
     * @brief ~Time
     *
     * This is the destructor of the class Time
     * This destructor is by default
     */
    ~TimeT()=default;

    /**
     * @brief getTime
     *
     * This getter allows to return the time at a moment T
     *
     * @return a double of the valor of the time at a moment T
     */
    double getTime();


    /**
     * @brief getTimePassed
     *
     * This is a getter to know the valor of the Time
     *
     * @return a double to represent the valor of the time
     */
    unsigned getTimePassed();

    /**
     * @brief setTimePassed
     *
     * This method allows to modify the valor of the time of the current
     * part
     *
     */
    void setTimePassed();

    /**
     * @brief resetTimePassed
     *
     * This method allows to reset the valor of the time at zero
     */
    void resetTimePassed();

private:


    /**
     * @brief time_
     *
     * This attribute is a double of the valor of the time T necessary for compute
     * the time passed after this tume T
     *
     */
    double time_;

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
