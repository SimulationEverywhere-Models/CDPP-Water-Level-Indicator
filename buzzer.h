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

#ifndef __BUZZER_H
#define __BUZZER_H

//#include <list>
#include "atomic.h"     // class Atomic

class Buzzer : public Atomic
{
public:
	Buzzer( const string &name = "Buzzer" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &buzzIn;

	Port &buzzOut;

	Time buzzTime;
	int B;

//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Buzzer

// ** inline ** // 
inline
string Buzzer::className() const
{
	return "Buzzer" ;
}

#endif   //__BUZZER_H
