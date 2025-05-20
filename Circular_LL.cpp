/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = nullptr;
Node *head_1 = nullptr;
Node* getNode(int val)
{
    Node *NewNode = new Node;
    NewNode->data = val;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;
    
    return NewNode;
}
void CreateCircularLL()
{
    head = getNode(1);
    Node *second = getNode(2);
    Node *third = getNode(3);
    Node *forth = getNode(4);
    
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = head;
    
}
void CreateCircularLL_1()
{
    head_1= getNode(1);
    Node *second = getNode(2);
    Node *third = getNode(3);
    Node *forth = getNode(4);
    
    head_1->next = second;
    second->next = third;
    third->next = forth;
    forth->next = head_1;
    
}
bool CheckCLL()
{
    Node *curr = head;
    while(curr && curr->next != head)
    {
        curr = curr->next;
    }
    
    if(!curr)
    {
        return false;
    }
    return true;
}
bool CheckCLL_Identical()
{
    Node* curr = head;
    Node *curr_1 = head_1;
    
    while((curr && curr->next != head) && (curr_1 && curr_1->next != head_1))
    {
        if(curr->data == curr_1->data)
        {
            curr = curr->next;
            curr_1 = curr_1->next;
        }
        else
        {
            return false;   
        }
    }
    return true;
}
int main()
{
    CreateCircularLL();
    CreateCircularLL_1();
    cout << CheckCLL() << endl;
    cout << CheckCLL_Identical() << endl;
}