/*! \file main.cpp
 * \brief Entry app file.
 *
 * \authors Dmitrii Leliuhin
 * \date July 2020
 *
 * Details.
 *
 */

//=======================================================================================

#include "subscribe.h"
#include "publish.h"
#include "config.h"
#include "core.h"
#ifdef GUI
#include "view.h"
#endif

#include "niias_arguments.h"

#include "vapplication.h"
#include "vthread.h"

#include "vzcm.h"

#include <iostream>

//=======================================================================================
/*! \fn int main( int argc, char **argv )
 * \brief Entry point.
 *
 * Execution of the program starts here.
 *
 * \param argc Number of arguments.
 * \param argv List of arguments.
 *
 * \return App exit status.
 */
int main( int argc, char **argv )
{
    niias::arguments nargs( argc, argv,
                            "cservice_template - JSC NIIAS",
                            Config::by_default() );
    Config config;
    {
        config.capture( nargs.settings() );
        config.logs.setup();
    }

    //-----------------------------------------------------------------------------------

    Subscribe subscriber( config );
    Publish publisher( config );
    Core core( config );

    subscriber.received.link( &core, &Core::run );

    core.processed.link( &publisher, &Publish::send );

    //-----------------------------------------------------------------------------------

#ifdef GUI
    vthread thread;
    thread.invoke( [&]
    {
        View viewer( nargs.app_name() );
        viewer.run();
    } );
#endif

    //-----------------------------------------------------------------------------------

    vapplication::poll();

    return EXIT_SUCCESS;
}
//=======================================================================================
