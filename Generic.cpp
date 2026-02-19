////////////////////////////////////////////////////////////////////////////////////////
//      Generalised Data Structure Library
////////////////////////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------------
Type                        Name of class for node        Name of class for fucntinality
-----------------------------------------------------------------------------------------
Singly Linear               SinglyLLLnode                   SinglyLLL
DOubly Linear               DoublyLLLnode                   DoublyLLL

-----------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
// Final Code of Singly Linear LinkedList Using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
public:
    T data;
    SinglyLLLnode<T> *next;

    SinglyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
    }
};

template <class T>
class SinglyLLL
{
private:
    SinglyLLLnode<T> *first;
    int iCount;

public:
    SinglyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    newn = new SinglyLLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at last position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->data = no;
    newn->next = NULL;

    if (this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        temp = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Delete First node
//  Description   : Used to delete node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>

void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL) // else if(Count = 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = (this->first)->next;
        delete (temp);
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input         : Nothing
//  Output        : DeleteLast node
//  Description   : Used to delete node at last position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if ((this->first)->next == NULL) // else if(Count = 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Display Linked List
//  Description   : Used to Display all nodes in a Linked List
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T> *temp = NULL;
    temp = this->first;
    int iCnt = 0;

    for (iCnt = 1; iCnt <= iCount; iCnt++)
    {
        printf("| %d |->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Count
//  Description   : Used to Count all nodes in a Linked List
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InseretAtPos
//  Input         : Position of node
//  Output        : node inserted
//  Description   : Used to insert the node at given position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    int iSize = 0;
    int iCnt = 0;
    SinglyLLLnode<T> *newn = NULL;
    SinglyLLLnode<T> *temp = NULL;

    if (pos < 1 || pos > this->iCount + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new SinglyLLLnode<T>(no);

        newn->data = no;
        newn->next = NULL;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input         : Position of node
//  Output        : node deleted
//  Description   : Used to delete the node at given position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iSize = 0;
    int iCnt = 0;
    SinglyLLLnode<T> *target = NULL;
    SinglyLLLnode<T> *temp = NULL;

    if (pos < 1 || pos > this->iCount)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
// Final code of Doubly Linear LinkedList using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>

class node
{
public:
    T data;
    node *prev;
    node *next;

    node(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
public:
    node<T> *first;
    int iCount;

    DoublyLLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    node<T> *newn = NULL;

    newn = new node<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at last position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    node<T> *newn = NULL;
    node<T> *temp = NULL;

    newn = new node<T>(no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InseretAtPos
//  Input         : Position of node
//  Output        : node inserted
//  Description   : Used to insert the node at given position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    node<T> *temp = NULL;
    node<T> *newn = NULL;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid position";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;

        newn = new node<T>(no);

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        newn->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Delete First node
//  Description   : Used to delete node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->next->prev = NULL; //
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Input         : Nothing
//  Output        : DeleteLast node
//  Description   : Used to delete node at last position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    node<T> *temp = NULL;

    if (this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Input         : Position of node
//  Output        : node deleted
//  Description   : Used to delete the node at given position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    node<T> *temp = NULL;
    ;
    node<T> *target = NULL;
    ;

    int iCnt = 0;

    if (pos < 1 || pos > this->iCount + 1)
    {
        cout << "Invalid position";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for (iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Display Linked List
//  Description   : Used to Display all nodes in a Linked List
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T>::Display()
{
    node<T> *temp = NULL;
    temp = this->first;

    cout << "\nNULL<=>";

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    }

    cout << "NULL\n";
}


////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Count
//  Description   : Used to Count all nodes in a Linked List
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

//////////////////////////////////// End of Library //////////////////////////////////////////

int main()
{
    cout<<"--------------Singly Linear Linked List-------------------\n";
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(121);
    obj->InsertLast(151);

    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";

    obj->DeleteFirst();
    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";

    obj->DeleteLast();
    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";
    
    obj->InsertAtPos(301, 5);
    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";
    
    obj->DeleteAtPos(4);
    obj->Display();
    iRet = obj->Count();
    cout << "Total Numbers of nodes are : " << iRet << "\n";
    
    delete obj;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n--------------Doubly Linear Linked List-------------------\n";
    DoublyLLL<char> *dobj = new DoublyLLL<char>();

    dobj->InsertFirst('c');
    dobj->InsertFirst('b');
    dobj->InsertFirst('a');
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('d');
    dobj->InsertLast('e');
    dobj->InsertLast('f');
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('h',3);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(3);
    dobj->Display();
    cout<<"Total number of elements are : "<<dobj->Count()<<"\n";
    delete dobj;

    return 0;
}