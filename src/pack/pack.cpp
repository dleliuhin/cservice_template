/*! \file pack.cpp
 * \brief Pack class implementation.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#include "pack.h"

//=======================================================================================
void Data::operator =( const ZcmService& data )
{
    _timestamp = data.u_timestamp;
}
//=======================================================================================
void Data::clear()
{
    _timestamp = 0;
}
//=======================================================================================


//=======================================================================================
const int64_t & Data::timestamp() const
{
    return _timestamp;
}
//=======================================================================================




//=======================================================================================
void Pack::clear()
{
    data.clear();
}
//=======================================================================================
