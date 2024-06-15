#pragma once
#include <string>
#include <iosfwd>

class HTNode
{
public:
	std::string key;
	int value;
	HTNode* next;

	HTNode(std::string key, int value)
	{
		this->key = key;
		this->value = value;
		next = nullptr;
	}
};

