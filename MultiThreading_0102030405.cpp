
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
#include<mutex>
#include<condition_variable>

using namespace std;
condition_variable cond_var;
mutex mu;

int limit; 
int  current = 1;
int reset_zero = 0;

void print_zero()
{
    
    for(int i = 0; i <limit; ++i)
    {
        unique_lock<mutex> u_lock(mu);
     
        cond_var.wait(u_lock,[]{ return (reset_zero == 0);  });
        
        cout << "0" ;
        
        if(current % 2 == 1)
        {
            reset_zero = 1;
        }
        else
            reset_zero = 2;
            
        u_lock.unlock();
        
        cond_var.notify_all();
    }
}

void print_even()
{

    while( current < limit) 
    {
        unique_lock<mutex> u_lock(mu);
    
        cond_var.wait(u_lock,[] { return reset_zero == 2; });
        
        cout << current++ ;
        
        reset_zero = 0;
        
        u_lock.unlock();
        
        cond_var.notify_all();
    }
}

void print_odd()
{

    while(current < limit) 
    {
        unique_lock<mutex> u_lock(mu);
        
        cond_var.wait(u_lock,[] { return (reset_zero == 1 );});
       
        cout << current++ ;
        
        reset_zero = 0;
        
        u_lock.unlock();
        
        cond_var.notify_all();
    }

}
int main()
{
    cin >> limit;
    thread t1(print_zero);
    thread t2(print_odd);
    thread t3(print_even);
    
    t1.join();
    t2.join();
    t3.join();

    return 0;
}