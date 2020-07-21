#include "publish_test.h"
#include "publish.h"
#include "config.h"

//=======================================================================================
/*! \test TEST( PublishTest, test_constructor )
 * \brief Various constructors.
 */
TEST( PublishTest, test_constructor )
{
    Publish pub1;
    Config config;
    Publish pub2( config );
}
//=======================================================================================
/*! \test TEST( PublishTest, test_send )
 * \brief send to ZCM.
 */
TEST( PublishTest, test_send )
{
    Config conf;
    conf.send.ch = "OutChannel";

    Publish publisher( conf );

    ZcmService msg;
    publisher.send( 0, msg );
}
//=======================================================================================
