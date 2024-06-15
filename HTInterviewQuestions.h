#pragma once
#include <string>
#include <unordered_map>
//#include "Queue.h"
#include <queue>
#include <cstddef>
#include <vector>
#include <unordered_map>
#include "BaseRunner.h"

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strings) 
{
	std::unordered_map<int, std::vector<std::string>> umap;
	for (int i = 0; i < strings.size(); i++)
	{
		std::cout << "\n" << strings[i];
		int currentValue = -1;
		std::string currentString = strings[i];
		for (int j = 0; j < currentString.length(); j++)
		{
			int asciiValue = int(currentString[j]);
			currentValue += asciiValue;

		}

		if (currentValue > 0)
		{
			umap[currentValue].push_back(strings[i]);		
		}
	}
	std::vector<std::vector<std::string>> thisIsAReturnVector;	
	for (const auto& pair : umap)
	{
		thisIsAReturnVector.push_back(pair.second);
	}

	return thisIsAReturnVector;
}

char firstNonRepeatingChar(const std::string& input_string) {
	//   +======================================================+
	//   |                 WRITE YOUR CODE HERE                 |
	//   | Description:                                         |
	//   | - This function finds the first non-repeating char   |
	//   |   in a given string.                                 |
	//   | - It uses an unordered_map to count char occurrences |
	//   | - Loops through the string to check counts.          |
	//   |                                                      |
	//   | Return type: char                                    |
	//   |                                                      |
	//   | Tips:                                                |
	//   | - 'charCounts' keeps track of each char's count.     |
	//   | - Loops twice: once to count, once to find answer.   |
	//   | - Returns '\0' if no non-repeating char is found.    |
	//   | - Check output from Test.cpp in "User logs".         |
	//   +======================================================+

	int index = -1;
	char returnVal = '\0';
	std::queue<size_t> queueOfLowestIndexes;
	std::unordered_map<char, int> umap;
	for (size_t i = 0; i < input_string.length(); i++)
	{
		char tempChar = input_string[i];
		std::unordered_map<char, int>::const_iterator val = umap.find(tempChar);
		if (val == umap.end())
		{
			if (index == -1)
			{
				index = i; returnVal = tempChar;
			}

			umap[tempChar] = 1;
			queueOfLowestIndexes.push(((size_t)i));
		}
		else
		{
			if (index != -1 && tempChar == input_string[index])
			{
				if(queueOfLowestIndexes.size() > 0)
				{					
					int tempIndex = static_cast<int>(queueOfLowestIndexes.front());
					queueOfLowestIndexes.pop();
					if (tempIndex != index)
					{
						returnVal = input_string[index];
						index = tempIndex;
					}
					else
					{
						index = -1;
						returnVal = '\0';
					}
				}
				else
				{
					index == -1;
					returnVal = '\0';
				}
			}
			else
			{
				if (queueOfLowestIndexes.size() > 0)
				{
					index = queueOfLowestIndexes.front();
					queueOfLowestIndexes.pop();
					returnVal = input_string[index];
				}
			}
			umap[tempChar]++;
		}
	}

	if (index == input_string.length())
	{
		returnVal = input_string[index];
	}
	return returnVal;
}

class GroupAnagramRunner : public BaseRunner
{
public:
	void Run()
	{
		std::vector<std::string> strings{ "listen", "silent", "dog", "god", "evil", "vile"};
		std::vector<std::vector<std::string>> result = groupAnagrams(strings);
		int i = 0;
	};
};