#include "ParserClass.h"
#include <ctype.h>

ParserClass::ParserClass(std::string &line)
{
	size_t pos = line.find(CurrentEngineSpeed);
	if (pos != std::string::npos)
	{
		std::cout << line << std::endl;
		ParserLine(line);
	 }
	else 
		std::cout <<  "Not Found!"  << std::endl;
}

void ParserClass::ParserLine(std::string& line)
{
	std::string number;
	size_t pos = line.find("Data:");
	for (pos; pos < line.size()-1; ++pos)
	{
		if (line[pos] == '0')
		{
			int i = 0;
			while (!isspace(line[pos]) && (pos != line.size()-1))
			{
				number.resize(4);
				number[i++] = line[pos];
				++pos;
			}
			int value = std::stoi(number, nullptr, 16);
			std::cout << number << "  Value: " << value << std::endl;
		}
		
	}
}

ParserClass::~ParserClass()
{}
