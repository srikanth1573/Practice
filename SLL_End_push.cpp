/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head = nullptr;
    Node *end = nullptr;
    
    public:
    void InsertData(int value)
    {
        Node *newNode = new  Node;
        
        newNode->data = value;
        newNode->next = nullptr;
        
        if(head == nullptr)
        {
            head = newNode;
            end = newNode;
            return;
        }
     //  end = end->next;
     while(end->next != nullptr)
     {
         end = end->next;
     }
        end->next= newNode;
      //  newNode->next = nullptr;
    }
    void print()
    {
        if(head == nullptr)
            cout << "Empty list" << endl;
        else
        {
            Node *temp = head;
            while(temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
  LinkedList l_obj;
  l_obj.InsertData(10);
  l_obj.InsertData(20);
  l_obj.InsertData(30);
  l_obj.print();
}

    
    
    