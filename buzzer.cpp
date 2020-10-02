/*******************************************************************
*
*  DESCRIPTION: Atomic Model Buzzer
*
*  AUTHOR: Balogun Adebusola
*
*  EMAIL: mailto://busolabalogun@cmail.carleton.ca
*
*  DATE: 02/11/2017
*
*******************************************************************/

/** include files **/
#include "buzzer.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Buzzer
* Description: 
********************************************************************/
Buzzer::Buzzer( const string &name )
: Atomic( name )
, buzzIn( addInputPort( "buzzIn" ) )
, buzzOut( addOutputPort( "buzzOut" ) )

, buzzTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "buzz" ) ) ;

	if( time != "" )
		buzzTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Buzzer::initFunction()
{
	this-> passivate();
	B = 0;

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Buzzer::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == buzzIn )
	{
		B = static_cast < int > (msg.value());
		holdIn( active, buzzTime );

	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Buzzer::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Buzzer::outputFunction( const InternalMessage &msg )
{

if (B == 0)
	sendOutput( msg.time(), buzzOut, 1);
if (B == 3)
	sendOutput( msg.time(), buzzOut, 1);


	return *this ;
}
