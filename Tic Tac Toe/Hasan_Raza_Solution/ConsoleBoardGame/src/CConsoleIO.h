/*
 * CConsoleIO.h
 *
 *  Created on: Nov 16, 2023
 *      Author: hasan.raza@stud.h-da.de
 *      \brief: This class will be for Console Input and Output activities
 */

#ifndef CCONSOLEIO_H_
#define CCONSOLEIO_H_
#include<iostream>
#include<string>
using namespace std;

class CConsoleIO {
public:

	/**
	 * \brief: This method prints the message on the console
	 * @param: [IN] string message
	 */
    void displayMessage(const string& message);


    //void displayError(const string& errorMessage);
    // Other console-related functions...
};




#endif /* CCONSOLEIO_H_ */
