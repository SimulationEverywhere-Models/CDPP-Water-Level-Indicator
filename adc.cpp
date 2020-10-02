/*******************************************************************
 *
 *  DESCRIPTION: Atomic Model Adc
 *
 *  AUTHOR: Balogun Adebusola
 *
 *  EMAIL: mailto://busolabalogun@cmail.carleton.ca
 *
 *  DATE: 02/11/2017
 *
 *******************************************************************/

/** include files **/
#include "adc.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
 * Function Name: Adc
 * Description:
 ********************************************************************/
Adc::Adc( const string &name )
: Atomic( name )
, SIn( addInputPort( "SIn" ) )
, DigOut( addOutputPort( "DigOut" ) )
, levelOut( addOutputPort( "levelOut" ) )
, ToBuzz( addOutputPort( "ToBuzz" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
 * Function Name: initFunction
 * Description: Resetea la lista
 * Precondition: El tiempo del proximo evento interno es Infinito
 ********************************************************************/
Model &Adc::initFunction()
{
	this-> passivate();
	level = 0;

	return *this ;
}

/*******************************************************************
 * Function Name: externalFunction
 * Description:
 ********************************************************************/
Model &Adc::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == SIn )
	{
		level = static_cast < int > (msg.value());
		holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
 * Function Name: internalFunction
 * Description:
 ********************************************************************/
Model &Adc::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
 * Function Name: outputFunction
 * Description:
 ********************************************************************/
Model &Adc::outputFunction( const InternalMessage &msg )
{
	if (level <=11)
	{
	sendOutput( msg.time(), levelOut, level);
	}
	if ((level >=0) && (level <=3))
	{
		sendOutput( msg.time(), DigOut, 0);
		sendOutput( msg.time(), ToBuzz, 0);
	}
	if ((level >=4) && (level <= 7))
	{
		sendOutput( msg.time(), DigOut, 1);
	}
	if (level >=8 && level <= 10)
	{
		sendOutput( msg.time(), DigOut, 2);

	}
	if ((level == 11) ||(level == 10))
	{
		sendOutput( msg.time(), DigOut, 3);
		sendOutput( msg.time(), ToBuzz, 3);
	}
	return *this ;
}
