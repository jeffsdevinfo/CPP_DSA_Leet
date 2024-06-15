#pragma once
#include "BaseRunner.h"
#include "HashTable.h"

class HashTableRunner : public BaseRunner
{
public:
	void Run() override;
	void GetKVPTesting(HashTable* ht);

};

