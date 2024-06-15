#pragma once
#include <iostream>
#include "HTNode.h"
#include <vector>
#include <string> // 
#include <unordered_map>

class HashTable
{
private:
	static const int SIZE = 7;
	HTNode* dataMap[SIZE];

public:
	~HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{			
			HTNode* head = dataMap[i];
			while (head != nullptr)
			{
				HTNode* temp = head;
				head = head->next;
				delete temp;
				temp = nullptr;
			}
		}
	}

	void printTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << i << ":" << std::endl;
			if (dataMap[i])
			{
				HTNode* temp = dataMap[i];
				while (temp)
				{
					std::cout << " {" << temp->key << ", " << temp->value << "}" << std::endl;
					temp = temp->next;
				}
			}
		}
	}

	int hash(std::string key)
	{
		int hash = 0;
		for (int i = 0; i < key.length(); i++)
		{
			int asciiValue = int(key[i]);
			hash = (hash + asciiValue * 23) % SIZE; // Multiplying by 23 makes the results more random reducing the chance of collisions
		}
		return hash;
	}

	void set(std::string key, int value)
	{
		int index = hash(key);
		HTNode* newNode = new HTNode(key, value);
		if (dataMap[index] == nullptr)
		{
			dataMap[index] = newNode;
		}
		else
		{ 
			HTNode* temp = dataMap[index];
			while (temp->next != nullptr && temp->next->key != key)
			{
				temp = temp->next;
			}
			if (temp->next != nullptr && temp->next->key == key)
			{
				delete newNode;  //dont use the newNode since the key exist alread
				temp->next->value = value;
			}
			else
			{
				temp->next = newNode;
			}
		}
	}

	//example to get the actual keyvalue pair
	HTNode* getKVP(std::string key)
	{
		HTNode* returnNode = nullptr;
		int index = hash(key);
		HTNode* current = dataMap[index];
		while (current != nullptr && current->key != key)
		{
			current = current->next;
		}
		returnNode = current;
		std::cout << "\nHashed index for key:" << key << " equals:" << index;
		return returnNode;
	}

	//example to get the actual value of the hash table item if found
	int get(std::string key)
	{
		int index = hash(key);
		HTNode* current = dataMap[index];
		while (current != nullptr)
		{
			if (current->key == key) return current->value;
			current = current->next;
		}
		return 0; // returning 0 indicates that this value is not used so we should not have an item with value of 0 - jss
	}

	std::vector<std::string> keys()
	{
		std::vector<std::string> returnVector;		
		for (int i = 0; i < SIZE; i++)
		{
			HTNode* current = dataMap[i];
			while (current != nullptr)
			{
				returnVector.push_back(current->key);
				current = current->next;
			}
		}
		return returnVector;
	}

	bool keyExist(std::string key)
	{
		int hashValue = hash(key);
		return dataMap[hashValue] != nullptr ? true : false;
	}

	static bool itemInCommonMyVersion(std::vector<int> vect1, std::vector<int> vect2)
	{
		HashTable hashTableCommon;
		for (int i = 0; i < vect1.size(); i++)
		{
			hashTableCommon.set(std::to_string(vect1[i]), vect1[i]);
		}

		for (int i = 0; i < vect1.size(); i++)
		{
			if (hashTableCommon.keyExist(std::to_string(vect1[i])))
			{
				return true;
			}
		}
		return false;
	}

	// check if duplicates exist between two vector<int> using an unordered_map with 
	bool itemInCommon(std::vector<int> vect1, std::vector<int> vect2) {

		std::unordered_map<std::string, int> umap;
		for (size_t i = 0; i < vect1.size(); i++)
		{
			umap[std::to_string(vect1[i])] = vect1[i];
		}

		for (size_t i = 0; i < vect2.size(); i++)
		{
			std::unordered_map<std::string, int >::const_iterator val = umap.find(std::to_string(vect2[i]));
			if (val != umap.end())
			{
				return true;
			}
		}
		return false;
	}


};

