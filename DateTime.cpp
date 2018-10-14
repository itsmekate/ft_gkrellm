//
// Created by Kateryna PRASOL on 13.10.2018.
//

#include "DateTime.h"

DateTime::DateTime()
{
    time_t now = time(0);
    _dateTime = ctime(&now);
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
    time_t now = time(0);
    _dateTime = ctime(&now);
    return _dateTime;
}