/*
 * main.cpp
 *
 *  Created on: 25.11.2026
 *      Author: n3034770
 */



#include "stack.h"
#include "sequence.h"
#include "pbma.h"
#include <string>
#include <vector>


using namespace std;

bool check_line(string& line, size_t& col)
{
	Stack<char> s;
	for(col = 0; col < line.size(); col++)
	{
		if(line[col] == '(' or line[col] == '{' or line[col] == '[')
		{
			s.push(line[col]);
		}
		else if (line[col] == ')')
		{
		    if (s.is_empty())
		        return false;

		    if (s.top() != '(')
		        return false;

		    s.pop();
		}
		else if (line[col] == ']')
		{
		    if (s.is_empty())
		        return false;

		    if (s.top() != '[')
		        return false;

		    s.pop();
		}
		else if (line[col] == '}')
		{
		    if (s.is_empty())
		        return false;

		    if (s.top() != '{')
		        return false;

		    s.pop();
		}
	}
	return s.is_empty();
}

int main()
{


	string fname = "klammern.dat";
	vector<string> vec = read_lines(fname);

	for(size_t row = 0; row < vec.size(); row++)
	{
		string line = vec[row];
		size_t col = 0;
		if(!check_line(line, col))
		{
			cout << "Fehler an Zeile: " << row+1 << ", Spalte: " << col << endl;
		}

	}


	return 0;
}
