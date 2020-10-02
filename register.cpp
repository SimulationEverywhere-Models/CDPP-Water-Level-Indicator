/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Balogun Adebusola
*
*  STUDENT#: 101027260
*
*  EMAIL:  mailto://busolabalogun@cmail.carleton.ca
*
*  DATE: 02/11/2017
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "adc.h"        // class Adc
#include "displaypanel.h"
#include "colordecider.h"
#include "buzzer.h"


void MainSimulator::registerNewAtomics()
{
 


	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Adc>(), "Adc" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Displaypanel>(), "Displaypanel" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Colordecider>(), "Colordecider" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Buzzer>(), "Buzzer" ) ;  }

