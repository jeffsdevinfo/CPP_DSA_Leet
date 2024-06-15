// CPP_DSA_Leet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BaseRunner.h"
#include "LinkedListRunner.h"
#include "DoublyLinkedListRunner.h"
#include "StackRunner.h"
#include "QueueRunner.h"
#include "BinTreeRunner.h"
#include "QueueTemplateRunner.h"
#include "HashTableRunner.h"
#include "HaversineRunner.h"
#include "HTInterviewQuestions.h"
#include "HeapRunner.h"
#include "SortUtilitiesRunner.h"

int main()
{
    BaseRunner* genericRunner = nullptr;
    //genericRunner = new LinkedListRunner();
    //genericRunner = new DoublyLinkedListRunner();
    //genericRunner = new StackRunner();
    //genericRunner = new QueueRunner();
    //genericRunner = new BinTreeRunner();
    //genericRunner = new QueueTemplateRunner();
    //genericRunner = new HashTableRunner();
    //genericRunner = new HaversineRunner();
    //genericRunner->Run();

    //const std::string test = "aabbcc";
    //char result = firstNonRepeatingChar(test);
    //genericRunner = new GroupAnagramRunner();
    //genericRunner = new HeapRunner();
    genericRunner = new SortUtilitiesRunner();
    genericRunner->Run();

    //std::vector<std::vector<std::string>> returnVector;
    //std::vector<std::string> mystrings = { "hello", "googby" };
    //returnVector.push_back(mystrings);

    


    //.std::cout << result;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
