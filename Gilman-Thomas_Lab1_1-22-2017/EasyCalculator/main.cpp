#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

//std::string delimiter = ("+-*/");
std::string numIn, OpCount, OpChar, Op;
int TimesToAsk;
//take a string and parse it to find the different numbers to perform an operation on
int main()
{
    while(OpChar!="esc")
    {
        std::cout << "Operators: +,-,*,/ type esc to escape: \nhow many numbers do you want to perform operations on?:" << std::endl;
        std::getline(std::cin,OpCount);
        //set list length
        TimesToAsk = atoi(OpCount.c_str());
        if(TimesToAsk<=1)//makes sure equation is longer than just one number
        {
            cout<<"please input a larger number:"<<endl;
            std::getline(std::cin,OpCount);
            TimesToAsk = atoi(OpCount.c_str());
        }

        //THESE ARE THE LISTS!!!
        string* OpList = new string[TimesToAsk-1];
        int* NumList = new int[TimesToAsk];

        for(int i = 0;i<TimesToAsk;i++)//asks for as many numbers as specified
        {
            std::cout<<"Whats your "<<i<<" number?"<<endl;
            std::getline(std::cin,numIn);
            NumList[i]=atoi(numIn.c_str());//Populates the i position of NumList and fills up TimesToAsk many times
            if(i<TimesToAsk-1) //The amount of operators is TimesToAsk many - 1
            {
                std::cout<<"What Operation do you want to perform?"<<endl;
                std::getline(std::cin,OpChar);
                OpList[i]=OpChar;
            }
        }

        int x=NumList[0]; //starts with the first number in the list and performs the operation to it
        for(int m=1;m<TimesToAsk;m++)
        {
            int y = NumList[m];
            if((m-1)<TimesToAsk)
            {
               Op = OpList[m-1];
            }
            if(Op=="+"){
                x+=y;
            }
            else if(Op=="-"){
                x-=y;
            }
            else if(Op=="*"){
                x*=y;
            }
            else if(Op=="/"){
                x/=y;
            }
            else
                cout<<"Unknown Operator entered"<<endl;
        }
        cout<<"result: "<<x<<endl;
        delete[] NumList;
        delete[] OpList;
    }

    return 0;
}
