////////////////////////////////////////////////////////////////////////////////////////
//      Generalised Data Structure Library
////////////////////////////////////////////////////////////////////////////////////////


/*
---------------------------------------------------------------------------------------
Type                        Name of class for node        Name of class for fucntinality
-----------------------------------------------------------------------------------------
Singly Linear               SinglyLLLnode                   SinglyLLL
Doubly Linear               DoublyLLLnode                   DoublyLLL
Singly Circular             SinglyCLLnode                   SinglyCLL
Doubly Circular             DoublyCLLnode                   DoublyCLL
Stack                       Stacknode                       Stack
Queue                       Queuenode                       Queue
-----------------------------------------------------------------------------------------
*/
#include<iostream>
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

    if(this->first == NULL)
    {
        cout<<"Linked List is empty \n";
        return;
    }

    for (iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<"NULL\n";
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
        cout<<"Invalid Position\n";
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
        cout<<"Invalid Position\n";
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

class DoublyLLLnode
{
public:
    T data;
    DoublyLLLnode *prev;
    DoublyLLLnode *next;

    DoublyLLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
private:
    DoublyLLLnode<T> *first;
    int iCount;

public:
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
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

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
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

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
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

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

        newn = new DoublyLLLnode<T>(no);

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
    DoublyLLLnode<T> *temp = NULL;

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
    DoublyLLLnode<T> *temp = NULL;

    DoublyLLLnode<T> *target = NULL;


    int iCnt = 0;

    if (pos < 1 || pos > this->iCount)
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
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Linked List is empty \n";
        return;
    }
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

///////////////////////////////////////////////////////////////////////////////////////
// Final code of Singly Circular LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>

class SinglyCLLnode
{
    public: 
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();    
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Linked List gets created\n";
    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
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


template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    (this->last)->next = this->first;
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

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;
    newn = new SinglyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else 
    {
        this->last->next = newn;
        this->last = newn;
        
    }
    (this->last)->next = this->first;
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

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *newn = NULL;

    if(pos < 1 || pos > (iCount + 1))
    {
        cout<<"Invalid Position";
        return;
    }
    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new SinglyCLLnode<T>(no);

        newn->data = no;
        newn->next = NULL;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
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
//  Function Name : DeleteFirst
//  Input         : Nothing
//  Output        : Delete First node
//  Description   : Used to delete node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 19/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);              

        this->first = NULL;
        this->last = NULL;  
    }
    else
    {
        temp = this->first;
        this->first = (this->first)->next;
        delete(temp);

        (this->last)->next = this->first;
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


template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);        
        
        this->first = NULL;
        this->last = NULL; 
    }
    else
    {
        temp = this->first;
        while(temp->next != this->last)
        {
            temp = temp->next;
        }
        delete(this->last);
        this->last = temp;
        temp->next = this->first;      
    }
    iCount--;
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


template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;

    if(pos < 1 || pos > (iCount + 1))
    {
        cout<<"Invalid Position";
        return;
    }
    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        
        target = temp->next;
        temp->next = target->next;
        delete(target);
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


template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> *temp = NULL;

    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Linked List is empty \n";
        return;
    }

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"\n";
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

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Final code of Doubly Circular LinkedList using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>

class DoublyCLLnode
{
    public: 
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();    
};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Linked List gets created\n";
    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at first position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        newn->prev = this->last;
        newn->next->prev = newn;
        this->first = newn;
    }
    (this->last)->next = this->first;
    (this->first)->prev = this->last;
    this->iCount++;
    
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Input         : Data of node
//  Output        : Nothing
//  Description   : Used to insert node at last position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = NULL;
    
    newn = new DoublyCLLnode<T>(no);
    
    if((this->first == NULL) && (this->last == NULL))
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->prev = this->last;
        (this->last)->next = newn;
        this->last  = newn;
    }
    
    (this->last)->next = this->first;
    (this->first)->prev = this->last;
    this->iCount++;
 
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InseretAtPos
//  Input         : Position of node
//  Output        : node inserted
//  Description   : Used to insert the node at given position
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    int iCnt = 0;
    
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *newn = NULL;

    if(pos < 1 || pos > (iCount + 1))
    {
        cout<<"Invalid Position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {  
        temp = this->first;
        newn = new DoublyCLLnode<T>(no);

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        newn->next->prev = newn;
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
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> *temp = NULL;
    
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);              
        
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = (this->first)->next;
        delete(temp);
        (this->last)->next = this->first;
        (this->first)->prev = this->last;
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
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> *temp = NULL;
    
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    { 
        delete(this->first);        
        
        this->first = NULL;
        this->last = NULL;
        
    }
    else
    {    temp = this->last;
        this->last = (this->last)->prev;

        delete(temp);

        (this->last)->next = this->first;
    (this->first)->prev = this->last;
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
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    DoublyCLLnode<T> *temp = NULL;
    DoublyCLLnode<T> *target = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete(target);
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
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> *temp = this->first;
    
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"LinkedList is empty \n";
        return;
    }
    
    cout<<"<=>";
    do
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Count
//  Description   : Used to Count all nodes in a Linked List
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

//////////////////////////////////////////////////////////////////////////////////////
// Final code of Stack using Generic Approach
/////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);     
        T pop();
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created succesfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : push
//  Input         : new element
//  Output        : element gets added
//  Description   : Used to insert element in stack
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : pop
//  Input         : Nothing
//  Output        : element gets deleted
//  Description   : Used to delete last element from stack 
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}   

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : peep
//  Input         : Nothing
//  Output        : last element
//  Description   : To view the top element of the stack without removing it.
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;    
    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : All stack elements
//  Description   : view the all stack elements
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Total elements
//  Description   : It is used to count the total number of elements from stack
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 20/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Final code of Queue using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};


template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T>*last;

        int iCount;

        public:
            Queue();
            void enqueue(T);
            T dequeue();
            void Display();
            int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully...\n";
    this->first =NULL;
    this->last =NULL;

    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : enqueue
//  Input         : element
//  Output        : New element added
//  Description   : It is used to insert the element are last position in Queue
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 21/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;
    
    newn = new Queuenode<T>(no);
    
    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : dequeue
//  Input         : Nothing
//  Output        : Remove element
//  Description   : It is used to delete the first element from Queue
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 21/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value=0;
    Queuenode<T> *temp = NULL;
    
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        Value = this->first->data;
        temp = this->first;
        this->first = first->next;
        delete temp;
        this->iCount--;
        return Value;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : All Queue elements
//  Description   : view the all Queue elements
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 21/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////


template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;
    
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty \n";
        return;
    }

    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";  
}

////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Total elements
//  Description   : It is used to count the total number of elements from Queue
//  Author        : Uddhav Venkatesh Khatal
//  Date          : 21/02/2026
//
/////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}


//////////////////////////////////// End of Library //////////////////////////////////////

int main()
{
    cout<<"--------------Singly Linear Linked List-------------------\n\n";
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
    cout<<"\n--------------Doubly Linear Linked List-------------------\n\n";
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
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\n--------------Singly Circular Linked List-------------------\n\n";
    
    SinglyCLL<float> *scobj = new SinglyCLL<float>(); 
    
    scobj->InsertFirst(51.3);
    scobj->InsertFirst(21.2);
    scobj->InsertFirst(11.1);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    scobj->InsertLast(101.4);
    scobj->InsertLast(121.5);
    scobj->InsertLast(151.6);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    scobj->DeleteFirst();
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    scobj->DeleteLast();
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    scobj->InsertAtPos(45.77,4);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    scobj->DeleteAtPos(4);
    scobj->Display();
    cout<<"Total number of nodes are : "<<scobj->Count()<<"\n";
    
    delete scobj;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n--------------Doubly Circular Linked List-------------------\n\n";
    
    DoublyCLL<double> *dcobj = new DoublyCLL<double>(); 
    
    dcobj->InsertFirst(51.321);
    dcobj->InsertFirst(21.21);
    dcobj->InsertFirst(11.1);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->InsertLast(101.43);
    dcobj->InsertLast(121.543);
    dcobj->InsertLast(151.65);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteFirst();
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteLast();
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->InsertAtPos(455.89,4);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    dcobj->DeleteAtPos(4);
    dcobj->Display();
    cout<<"Total number of nodes are : "<<dcobj->Count()<<"\n";
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\n-------------------Stack-------------------\n\n";
    
    Stack<char> *sobj = new Stack<char>();
    
    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    
    sobj->Display();
    
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";
    
    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";
    
    sobj->Display();
    
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";
    
    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();
    
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";
    
    cout<<"Poped element is : "<<sobj->pop()<<"\n";
    
    sobj->Display();
    
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";
    
    sobj->push('e');
    sobj->Display();
    cout<<"Number of elements in Stack are : "<<sobj->Count()<<"\n";
    
    delete sobj;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n-------------------Queue-------------------\n\n";

    Queue<float> *qobj = new Queue<float>();

    qobj->enqueue(11.11);
    qobj->enqueue(21.21);
    qobj->enqueue(51.51);
    qobj->enqueue(101.11);

    qobj->Display();
    cout<<"Number of elements are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements are : "<<qobj->Count()<<"\n";

    qobj->enqueue(151.51);
    qobj->Display();
    cout<<"Number of elements are : "<<qobj->Count()<<"\n";

    delete qobj;
    
    return 0;
}