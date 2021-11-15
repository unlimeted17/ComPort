
#include "stdfax.h"

union Count
{
	int coll;
	char data[4];

};

class ParserClass
{
public:
	ParserClass(std::string&);
	~ParserClass();
	int VALUE = 0;

private:
	const char CurrentEngineSpeed[6] = "0x200"; // текущие обороты двигателя
	void ParserLine(std::string& line);
	void show_vector(std::vector<int>& a);

};

