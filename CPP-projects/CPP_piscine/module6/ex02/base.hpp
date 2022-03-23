#ifndef Base_H
# define Base_H
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

class Base
{
public:
	virtual ~Base();
};

Base::~Base() {}

class A : public  Base {};
class B : public  Base {};
class C : public  Base {};
#endif
