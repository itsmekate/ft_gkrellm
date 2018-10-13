//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "DateTime.h"
#include <iostream>

DateTime::DateTime()
{
    time_t now = time(0);
    _dateTime = ctime(&now);
    std::cout << "The local date and time is: " << _dateTime << std::endl;
}

DateTime::DateTime(DateTime const & rhs)
{
    *this = rhs;
}
DateTime & DateTime::operator=(DateTime const &rhs)
{
    if (this != &rhs)
    {
        _dateTime=rhs._dateTime;
    }
    return (*this);
}
DateTime::~DateTime()
{

}

std::string DateTime::getDateTime()
{
    return _dateTime;
}