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
     * \param[in] fname Path to configuration file.
     * \details Initialize _zcm node
     */
    Subscribe( const Config& conf );

    //! \brief default destructor.
    ~Subscribe() = default;

    //-----------------------------------------------------------------------------------

    /*!
     * \brief received emit signal if ZCM message received
     * \arg int64_t raw timestamp.
     * \arg ZcmService data from ZCM bus.
     */
    vsignal<Pack> received;

    //-----------------------------------------------------------------------------------

private:

    //! \param _conf configuration parameters
    Config _conf;

    //! \param _zcm ZCM node
    vzcm _zcm;

    //! \param _pack Data aggregated from multiple sensors.
    Pack _pack;

};
//=======================================================================================

#endif // SUBSCRIBER_H
