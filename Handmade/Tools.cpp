#include "Tools.h"



Tools::Tools()
{
}


Tools::~Tools()
{
}

int Tools::GetData(string _name, string _line)
{
	int data;
	if (_line.find(_name, 0) != _line.npos)
	{
		string New = _line.substr(_line.find('=') + 1);
		data = atoi(New.c_str());
		return data;
	}
}

string Tools::GetText(string _name, string _line)
{
	if (_line.find(_name, 0) != _line.npos)
	{
		string New = _line.substr(_line.find('=') + 1);
		
		return New;
	}
}
