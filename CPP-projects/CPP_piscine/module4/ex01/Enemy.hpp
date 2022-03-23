#ifndef Enemy_CLASS_H
# define Enemy_CLASS_H
# include <string>

class Enemy
{
public:
//construcotr
	Enemy(std::string const & type, int hp);
	Enemy(Enemy const & src);
	virtual	~Enemy();
//operator overload
	Enemy & operator=(Enemy const & src);
//member functions
	int		gethp(void)			const;
	void		sethp(unsigned int hp);
	std::string	gettype(void)		const;
	void		settype(std::string type);
	virtual void	takeDamage(int damage);

protected:
	Enemy();
	int		_HP;
	std::string	_type;
};
#endif
