#include "BinTree.h"
#include <queue>
//bool BinTree::insert(int value)
//{
//    bool returnVal = false;
//    if (root == nullptr)
//    {
//        root = new BinNode(value);
//        returnVal = true;
//    }
//    else
//    {
//        BinNode** temp = &root;
//        bool earlyExit = false;
//        while (*temp != nullptr)
//        {
//            if ((*temp)->value == value)
//            {
//                earlyExit = true;
//                break;
//            }
//            else if ((*temp)->value > value)
//            {
//                temp = &(*temp)->left;
//            }
//            else { temp = &(*temp)->right; }
//        }
//        if (!earlyExit) {
//            *temp = new BinNode(value);
//            returnVal = true;
//        }
//    }
//    return returnVal;
//}

bool BinTree::insert(int value)
{
    bool returnVal = false;
    if (root == nullptr)
    {
        root = new BinNode(value);
        returnVal = true;
    }
    else
    {
        BinNode* temp = root;
        bool earlyExit = false;
        while (temp != nullptr)
        {
            if (temp->value == value)
            {
                earlyExit = true;
                break;
            }
            else if (temp->value > value)
            {
                if(temp->left == nullptr)
                { 
                    temp->left = new BinNode(value);
                    returnVal = true;
                    break;
                }
                temp = temp->left;
            }
            else { 
                if (temp->right == nullptr)
                {
                    temp->right = new BinNode(value);
                    returnVal = true;
                    break;
                }
                temp = temp->right; 
            }
        }
    }
    return returnVal;
}

void BinTree::levelOrder()
{
    QueueTemplate<BinNode*>* queue = new QueueTemplate<BinNode*>();
    BinNode* current = root;
    while (current != nullptr)
    {
        std::cout << current->value << ", ";
        if (current->left) {
            queue->Enqueue(current->left);
        }
        if (current->right)
        {
            queue->Enqueue(current->right);
        }
        if (queue->getLength() > 0)
        {
            current = *(queue->Dequeue());
        }
        else
        {
            current = nullptr;
        }
    }
}


void BinTree::printTree(TreeOrder order, BinNode* current)
{
    if (root == nullptr) return;
    //if (order == LevelOrder) {
    //    levelOrder();
    //    return;
    //}

    if (current == nullptr)
    {
        current = root;
    }

    switch (order)
    {
    case BinTree::PreOrder:
        //right
        std::cout << current->value << ", ";
        if (current->left != nullptr)
        {
            printTree(PreOrder, current->left);
        }
        
        if (current->right != nullptr)
        {
            printTree(PreOrder, current->right);
        }

        break;
    case BinTree::InOrder:
        //up
        if (current->left != nullptr)
        {
            printTree(InOrder, current->left);
        }
        
        std::cout << current->value << ", ";
        
        if (current->right != nullptr)
        {
            printTree(InOrder, current->right);
        }
       break;
    case BinTree::PostOrder:
        //left
        if (current->left != nullptr)
        {
            printTree(PostOrder, current->left);
        }        

        if (current->right != nullptr)
        {
            printTree(PostOrder, current->right);
        }

        std::cout << current->value << ", ";
        break;
    case BinTree::LevelOrder:
        //LevelOrder
        BFS();

    default:
        break;
    }
}

void BinTree::BFS()
{
    std::queue<BinNode*> myQueue;
    if (root != nullptr)
    {
        myQueue.push(root);
        BinNode* currentNode = nullptr;
        if (myQueue.size() > 0)
        {
            currentNode = myQueue.front();
        }
        while (currentNode != nullptr)
        {            
            std::cout << currentNode->value << ", ";
            myQueue.pop();
            if (currentNode->left != nullptr) { myQueue.push(currentNode->left); }
            if (currentNode->right != nullptr) { myQueue.push(currentNode->right); }
            if (myQueue.size() > 0)
            {
                currentNode = myQueue.front();
            }
            else { currentNode = nullptr; }
        }
    }
}

