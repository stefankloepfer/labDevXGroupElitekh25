/*
 * CContainer.h
 *
 *  Created on: Feb 27, 2017
 *      Author: vmuser
 */

#ifndef CCONTAINER_H_
#define CCONTAINER_H_
#include "vector"
#include "pthread.h"

class CContainer {
public:
	CContainer();
	~CContainer();

	void fillMyContainer(int& para);  // setter
	void emptyMyContainer(); // getter

private:
	std::vector<int> container_;
	int id_;
	pthread_mutex_t* fathymutex_;

};

#endif /* CCONTAINER_H_ */
