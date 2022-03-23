#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H
# include <string>

class Weapon
{
	public:
	Weapon(std::string type);
	Weapon();
	~Weapon();
	std::string		getType(void) const;
	void			setType(std::string type);
	
	private:
	std::string	_type;
};
#endif
