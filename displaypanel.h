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

#ifndef __DISPLAYPANEL_H
#define __DISPLAYPANEL_H

//#include <list>
#include "atomic.h"     // class Atomic

class Displaypanel : public Atomic
{
public:
	Displaypanel( const string &name = "Displaypanel" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &DPIn1;
	const Port &DPIn2;
	Port &redOut;
	Port &greenOut;
	Port &yellowOut;
	Port &DPLevel;
	Time displayTime;
	int Color;
	int D_level;
//	typedef list<Value> ElementList ;
//	ElementList elements ;

//	Time timeLeft;

};	// class Displaypanel

// ** inline ** // 
inline
string Displaypanel::className() const
{
	return "Displaypanel" ;
}

#endif   //__DISPLAYPANEL_H
