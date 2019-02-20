#include "headers/model/timeT.h"
#include <time.h>

namespace model{

TimeT::TimeT():time_(clock()), timePassed_(0)
{
}

TimeT::TimeT(int time)
{
    time_= time;
    timePassed_ = 0;
}

TimeT::TimeT( TimeT &time)
{
    time_ = time.time_;
    timePassed_ = time.timePassed_;
}

double TimeT::getTime()
{
    return this->time_;
}

unsigned TimeT::getTimePassed()
{
    return this->timePassed_;
}

unsigned TimeT::stopTimePassed()
{
    timePassed_ = ((clock() - this->time_)/1000);
    return timePassed_;
}

void TimeT::setTimePassed()
{
    timePassed_ = ((clock() - this->time_)/1000);
}

void TimeT::resetTimePassed()
{
    this->timePassed_=0;
}

}//end namespace model


