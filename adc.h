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

#ifndef __ADC_H
#define __ADC_H

//#include <list>
#include "atomic.h"     // class Atomic

class Adc : public Atomic
{
public:
	Adc( const string &name = "Adc" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &SIn;
	Port &DigOut;
	Port &levelOut;
	Port &ToBuzz;
	Time preparationTime;
	int level;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Adc

// ** inline ** // 
inline
string Adc::className() const
{
	return "Adc" ;
}

#endif   //__ADC_H
