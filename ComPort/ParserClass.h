#pragma once
#include <iostream>
#include <fstream>
#include <string>



class ParserClass
{
public:
	ParserClass(std::string&);
	~ParserClass();

private:
	const char CurrentEngineSpeed[6] = "0x200"; // ������� ������� ���������
	void ParserLine(std::string& line);
};

