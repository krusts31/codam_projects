#ifndef Meseeks_CLASS_H
# define Meseeks_CLASS_H
# include "Enemy.hpp"

class Meseeks : public Enemy
{
public:
//construcotrs
	Meseeks();
	virtual ~Meseeks();
	Meseeks(Meseeks const & src);
//operator overloads
	Meseeks & operator=(Meseeks const & src);
//member functions
	using Enemy::takeDamage;
};

#endif
