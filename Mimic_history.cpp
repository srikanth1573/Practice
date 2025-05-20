/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;

std::vector<std::string> history;

void run_cmd()
{
    std::cout << "Simple Shell History. Type 'history' to see past commands. Type 'exit' to quit.\n";

    std::string input;
    while(true)
    {
        cout << "> ";
        
        cin >> input;
        
        if(input == "exit")
            break;
            
        if(input == "history")
        {
            for(auto i =0 ; i < history.size(); i++)
            {
                cout <<i + 1 << " " << history[i] << endl;
            }
        }
        else
        {
            history.push_back(input);
        }
    }
}
int main()
{
    run_cmd();
    
    return 0;
}

    