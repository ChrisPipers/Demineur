#include "headers/model/timeT.h"
#include <time.h>

namespace model{

TimeT::TimeT()
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
    return timePassed_;
}

void TimeT::setTimePassed()
{
    timePassed_ += time_/1000;
}


void TimeT::resetTimePassed()
{
    this->timePassed_=0;
}

}//end namespace model


