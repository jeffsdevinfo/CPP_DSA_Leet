#include "HashTableRunner.h"
#include "HTNode.h"

void HashTableRunner::Run()
{
	HashTable* ht = new HashTable();

	ht->set("nails", 100);
	ht->set("tile", 50);
	ht->set("lumber", 80);
	ht->set("bolts", 200);
	ht->set("screws", 140);	
	ht->printTable();

	std::vector<std::string> keys = ht->keys();

	std::cout << "\n\nKeys\n";
	for (int i = 0; i < keys.size(); i++)
	{		
		std::cout << keys[i] << ", ";
	}
	std::cout << "\n\n";

	GetKVPTesting(ht);
}

void HashTableRunner::GetKVPTesting(HashTable* ht)
{
	std::string searchKey = "tile";
	HTNode* foundNode = ht->getKVP(searchKey);
	if (foundNode)
	{
		std::cout << "\n" << searchKey << " value equals:" << foundNode->value;
	}
	else
	{
		std::cout << "\n" << searchKey << " item not found in hashTable";
	}

	searchKey = "screws";
	foundNode = ht->getKVP(searchKey);
	if (foundNode)
	{
		std::cout << "\n" << searchKey << " value equals:" << foundNode->value;
	}
	else
	{
		std::cout << "\n" << searchKey << " item not found in hashTable";
	}

	searchKey = "lumber";
	foundNode = ht->getKVP(searchKey);
	if (foundNode)
	{
		std::cout << "\n" << searchKey << " value equals:" << foundNode->value;
	}
	else
	{
		std::cout << "\n" << searchKey << " item not found in hashTable";
	}

	searchKey = "nails";
	foundNode = ht->getKVP(searchKey);
	if (foundNode)
	{
		std::cout << "\n" << searchKey << " value equals:" << foundNode->value;
	}
	else
	{
		std::cout << "\n" << searchKey << " item not found in hashTable";
	}

	searchKey = "cardboard";
	foundNode = ht->getKVP(searchKey);
	if (foundNode)
	{
		std::cout << "\n" << searchKey << " value equals:" << foundNode->value;
	}
	else
	{
		std::cout << "\n" << searchKey << " item not found in hashTable";
	}
}
