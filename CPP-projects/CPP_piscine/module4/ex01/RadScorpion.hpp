#ifndef RadScorpion_CLASS_H
# define RadScorpion_CLASS_H
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
//construcotrs
	RadScorpion();
	virtual ~RadScorpion();
	RadScorpion(RadScorpion const & src);
//operator overloads
	RadScorpion & operator=(RadScorpion const & src);
//member functions
	using Enemy::takeDamage;
};

#endif
