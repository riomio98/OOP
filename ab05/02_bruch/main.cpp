/*
 * main.cpp
 *
 *  Created on: 22.10.2026
 *      Author: n3034770
 */

class Bruch{
private:
	int _z;
	int _n;
public:
	Bruch(int z, int n = 1)
	:_z(z), _n(n)
	{

	}
	int zaehler() const
	{
		return _z;
	}
	int nenner() const
	{
		return _n;
	}
	bool operator==(const Bruch& other) const
	{

		return (_z == other._z and _n == other._n)? true : false;

	}
	bool operator!=(const Bruch& other) const
		{
		return (_z != other._z and _n != other._n)? true : false;
		}


};


int main()
{
	Bruch a(1,4);
	Bruch b(1,4);



	return 0;
}


