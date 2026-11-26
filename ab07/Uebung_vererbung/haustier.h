/*
 * haustier.h
 *
 *  Created on: 23.11.2026
 *      Author: n3034770
 */

#ifndef HAUSTIER_H_
#define HAUSTIER_H_

#include <string>


class Haustier{
private:
	std::string _name;
public:
	Haustier(const std::string& name)
	: _name(name)
	{
	}
	virtual ~Haustier() {
	}
	std::string get_name() const
	{
		return _name;
	}
	virtual std::string gib_laut() const
	{
		return "#";
	}
};


class Hund: public Haustier{
private:
	std::string _hundeschule;
public:
	Hund(const std::string& name,const std::string& hundeschule)
	: Haustier(name), _hundeschule(hundeschule)
	{
	}
	std::string get_schule() const
	{
		return _hundeschule;
	}
	virtual std::string gib_laut() const
	{
		return "Wau, Wau";
	}
};

class Katze: public Haustier{
private:
public:
	Katze(const std::string& name)
	: Haustier(name)
	{
	}

	virtual std::string gib_laut() const
	{
		return "Miau";
	}
	std::string gib_laut_basis() const
	{
		return Haustier::gib_laut();
	}
};


#endif /* HAUSTIER_H_ */
