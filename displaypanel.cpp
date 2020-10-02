/*******************************************************************
*
*  DESCRIPTION: Atomic Model Displaypanel
*
*  AUTHOR: Balogun Adebusola
*
*  EMAIL: mailto://busolabalogun@cmail.carleton.ca
*
*  DATE: 02/11/2017
*
*******************************************************************/

/** include files **/
#include "displaypanel.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Displaypanel
* Description: 
********************************************************************/
Displaypanel::Displaypanel( const string &name )
: Atomic( name )
, DPIn1( addInputPort( "DPIn1" ) )
, DPIn2( addInputPort( "DPIn2" ) )
, greenOut( addOutputPort( "greenOut" ) )
, yellowOut( addOutputPort( "yellowOut" ) )
, redOut( addOutputPort( "redOut" ) )
, DPLevel( addOutputPort( "DPLevel" ) )

, displayTime( 0, 0, 2, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "display" ) ) ;

	if( time != "" )
		displayTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Displaypanel::initFunction()
{
	this-> passivate();
	Color = 0;
	D_level=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Displaypanel::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == DPIn1 )
	{
		Color = static_cast < int > (msg.value());
		holdIn( active, displayTime );
	}
	if( msg.port() == DPIn2 )
		{
			D_level = static_cast < int > (msg.value());
			holdIn( active, displayTime );
		}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Displaypanel::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Displaypanel::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), DPLevel, D_level);
if (Color == 1)
{
	sendOutput( msg.time(), redOut, 1);
}
if (Color == 2)
{
	sendOutput( msg.time(), greenOut, 1);
}
if (Color == 3)
{
	sendOutput( msg.time(), yellowOut, 1);
}

	return *this ;
}
