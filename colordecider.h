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

#ifndef __COLORDECIDER_H
#define __COLORDECIDER_H

//#include <list>
#include "atomic.h"     // class Atomic

class Colordecider : public Atomic
{
public:
	Colordecider( const string &name = "Colordecider" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &CDIn1;
	const Port &CDIn2;
	Port &CDOut;
	Port &L_Out;
	Time decisionTime;
	int Disp;
	int Clevel;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Colordecider

// ** inline ** // 
inline
string Colordecider::className() const
{
	return "Colordecider" ;
}

#endif   //__COLORDECIDER_H
