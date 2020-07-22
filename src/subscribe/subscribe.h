/*! \file subscribe.h
 * \brief Subscribe class interface.
 *
 * ZCM message subscriber.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 */

//=======================================================================================

#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include "config.h"
#include "pack.h"

#include "vzcm.h"
#include "vsignal.h"

//=======================================================================================
/*! \class Subscribe
 * \brief ZCM message subscriber class.
 */
class Subscribe
{
public:

    /*!
     * \brief constructor.
     * \param[in] fname Configuration settings.
     * \details Initialize _zcm node
     */
    Subscribe( const Config& conf = {} );

    //! \brief default destructor.
    ~Subscribe() = default;

    //-----------------------------------------------------------------------------------

    /*!
     * \brief emit signal if ZCM message received.
     * \param Pack Data from ZCM bus.
     */
    vsignal<Pack> received;

    //-----------------------------------------------------------------------------------

private:

    //! \brief Configuration parameters.
    Config _conf;

    //! \brief ZCM node.
    vzcm _zcm;

    //! \brief Data aggregated from multiple sensors.
    Pack _pack;

};
//=======================================================================================

#endif // SUBSCRIBER_H
