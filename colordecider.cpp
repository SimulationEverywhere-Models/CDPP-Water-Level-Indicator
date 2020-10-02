/*******************************************************************
*
*  DESCRIPTION: Atomic Model Colordecider
*
*  AUTHOR: Balogun Adebusola
*
*  EMAIL: mailto://busolabalogun@cmail.carleton.ca
*
*  DATE: 02/11/2017
*
*******************************************************************/

/** include files **/
#include "colordecider.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Colordecider
* Description: 
********************************************************************/
Colordecider::Colordecider( const string &name )
: Atomic( name )
, CDIn1( addInputPort( "CDIn1" ) )
, CDIn2( addInputPort( "CDIn2" ) )
, CDOut( addOutputPort( "CDOut" ) )
, L_Out( addOutputPort( "L_Out" ) )

, decisionTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "decision" ) ) ;

	if( time != "" )
		decisionTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Colordecider::initFunction()
{
	this-> passivate();
	Disp = 0;
	Clevel=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Colordecider::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == CDIn1 )
	{
		Disp = static_cast < int > (msg.value());
		holdIn( active, decisionTime );
	}
	if( msg.port() == CDIn2 )
		{
			Clevel = static_cast < int > (msg.value());
			holdIn( active, decisionTime );
		}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Colordecider::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Colordecider::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), L_Out, Clevel);
if ((Disp ==0)||(Disp==3))
{
	sendOutput( msg.time(), CDOut, 1);
}
if (Disp ==1)
{
	sendOutput( msg.time(), CDOut, 2);
}
if (Disp ==2)
{
	sendOutput( msg.time(), CDOut, 3);
}

	return *this ;
}
