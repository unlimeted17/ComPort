#include "ParserClass.h"


ParserClass::ParserClass(std::string& line)
{
	size_t pos = line.find(CurrentEngineSpeed);
	if (pos != std::string::npos)
	{
		std::cout << line << std::endl;
		ParserLine(line);
	}
	else
		std::cout << "Not Found!" << std::endl;
}

void ParserClass::ParserLine(std::string& line)
{
	std::vector<int> vec;
	int  globalInt = 0;
	std::string number;
	Count cor;
	size_t pos = line.find("Data:");
	for (pos; pos < line.size() - 1; ++pos)
	{
		if (line[pos] == '0')
		{
			int i = 0;
			while (!isspace(line[pos]) && (pos != line.size() - 1))
			{
				number.resize(4);
				number[i++] = line[pos];
				++pos;
			}
			int value = std::stoi(number, nullptr, 16);
			cor.data[globalInt++] = (char)value;
			if (globalInt == 4)
			{
				globalInt = 0;
				vec.push_back(cor.coll);
			}

			//std::cout   << std::endl;
			std::cout << number << "  Value: " << value << std::endl;
		}

	}
	show_vector(vec);

}

void ParserClass::show_vector(std::vector<int>& a)
{
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << *it << std::endl;
}

ParserClass::~ParserClass()
{}
