//#pragma once
//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-5.
@file NotFoundExcep.h */

#ifndef NOTFOUNDEXCEP_
#define NOTFOUNDEXCEP_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
	NotFoundException(const std::string& message = "");
}; // end NotFoundException 
#endif
