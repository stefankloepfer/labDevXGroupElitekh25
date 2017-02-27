/*
 * CContainer.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: vmuser
 */

#include "CContainer.h"

CContainer::CContainer()
{
id_ = 0;
this->container_.empty();
fathymutex_ = new pthread_mutex_t();

}

CContainer::~CContainer()
{
delete fathymutex_;
};

CContainer::fillMyContainer(int& para)
{
	container_.push_back(para);
	std::cout<<"Ich habe reingespeichert"<<para<<std::endl;
};

CContainer::emptyMyContainer()
{
	int variable=0;
	pthread_mutex_lock(&fathymutex_);
	variable = container_.pop_back();
	pthread_mutex_unlock(&fathymutex_);

	std::cout<<"Ich habe rausgeholt"<<variable<<std::endl;
}

