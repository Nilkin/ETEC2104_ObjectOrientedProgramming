#include <myLinkedList.h>
#define PUSHTOLIST(x) myDLList->push(&myDLList->head,x)
#define APPENDTOLIST(x) myDLList->append(&myDLList->head,x)
#define VIRTUAL_PRINTLIST myDLList->printList(myDLList->head)
#define PRINTLIST myDLList->head->printList();

using namespace std;

int main()
{
    myLinkedList *myDLList = new myLinkedList();
    daddyLister *ohDaddyLister = new daddyLister();
    APPENDTOLIST(1);
    PUSHTOLIST(2);
    PUSHTOLIST(4);
    PUSHTOLIST(8);
    std::cout<<"Here is my virtual printList from myDLList: "<<std::endl;
    VIRTUAL_PRINTLIST; //print out all the nodes in order then in reverse order
    std::cout<<"\nHere is my nodes printList: "<<std::endl;
    PRINTLIST;
    std::cout<<"\nHere is DaddyListers printList: "<<std::endl;
    ohDaddyLister->printList();

    return 0;
}
