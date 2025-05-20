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

Node *head= nullptr;

Node *tail = nullptr;
    
Node* GetNewNode(int Val)
{
    Node *NewNode = new Node;
    NewNode->data = Val;
    NewNode->prev = nullptr;
    NewNode->next = nullptr;
    
    return NewNode;
}
void InsertAtHead(int value)
{
    Node *newNode = GetNewNode(value);
    
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
}
void InsertAtEnd(int value)
{
    Node *newNode = GetNewNode(value);
    
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    while(tail->next != nullptr)
    {
        tail = tail->next;
    }
    
    
    tail->next = newNode;
    newNode->prev = tail;
  //  head = newNode;
}   

void InsertAfterIndex(int index, int data)
{
    Node *newNode = GetNewNode(data);
    
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        cout<< "First Node , Inserction opration invalid" << endl;
        return;
    }
    
    Node *temp = head;
    int count = 0;
    while(temp->next != nullptr)
    {
        temp = temp->next;
        ++count;
        if(count == index)
        {
            break;
        }
    }

        newNode->prev = temp;
        newNode->next = temp->next;
        
        temp->next = newNode;
        
}
void InsertBeforIndex(int index,int value)
{
    Node *newNode = GetNewNode(value);
    
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
        cout<< "First Node , Inserction opration invalid" << endl;
        return;
    }
    
    Node *curr = head;
    
    Node *prev = nullptr;
    int count = 0;
    while(curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
        ++count;
        if(count == index)
        {
            break;
        }
    }
    
    prev->next = newNode;
    newNode->next = curr;
}
void DeleteAfterIndexNode(int index)
{
 Node *curr = head;
 Node *prev = nullptr;
 
 auto count = 0;
 
 while(curr->next != nullptr)
 {
     prev = curr;
     
     curr = curr->next;
     
     if(count == index)
     {
         break;
     }
    
      ++count;
 }
 
 prev->next = curr->next;
 curr->next = nullptr;
 //pr = last->
}
void DeleteKNode(int k)
{
    Node *curr = head;
    
    Node *prev = nullptr;
    
    auto count = 0;
    
    while(curr->next != nullptr)
    {
        if(count == k)
        {
            break;
        }
        ++count;
        
        prev = curr;
        
        curr= curr->next;
        
        
    }
    
    prev->next = curr->next;
    
    curr->next = nullptr;
    
}
void DeleteEnd()
{
    Node *last = head;
    
    Node *prev = nullptr;
    
    while(last->next != nullptr)
    {
        prev = last;
        last = last->next;
    }
    
    prev->next = nullptr;
    
    delete last;
    
}
void DeleteFront()
{
    Node *curr = head;
    
    head = head->next;
    
    if(head != nullptr)
        head->prev = nullptr;
        
    delete curr;
}
void display()
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    InsertAtEnd(20);
    InsertAtHead(10);
    InsertAtEnd(30);
    InsertAtEnd(40);
    InsertAfterIndex(2,35);
    InsertBeforIndex(2,25);
    display();
    cout << "After delete operation 1" << endl;
    DeleteFront();
    display();
   /* cout << "After delete operation 2" << endl;
    DeleteAfterIndexNode(1);
    display();
    cout << "After delete operation 3" << endl;
    DeleteKNode(2);
    display();
        */
        
}