#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace  std;


#include "node.h"

template <class Data_Type >
class Linked_List
{
private:
    Node<Data_Type>* head;
    int n;
public:
    void Create_List(int size);
    Linked_List(int size);
    Linked_List();
    ~Linked_List();
    // copy constructor;
    Linked_List(const Linked_List& Copy);
    Linked_List& operator = (const Linked_List& copy);

    Data_Type* Add(Data_Type added_data);
    Data_Type* Add_First(Data_Type added_data);
    int Find(Data_Type Search_Data);
    void Delete(Data_Type Delete_Data);
    void insert(Data_Type inserted_data, int pos);
    int Size();
    Data_Type& operator [] (int pos);
    // VERY IMPORTANT template <typename Data_Type >
    // this part for Errors as this is a friend operator function
    // Very Important >> Make the template selection data type with a different name from class's datatype(Data_Type)
    // we will name it Data_Typ without e
    template <typename Data_Typ > friend ostream& operator << (ostream& COUT, Linked_List<Data_Typ> List);
    template <typename Data_Typ > friend istream& operator >> (istream& CIN, Linked_List<Data_Typ>& List);

};

template <class Data_Type >
Linked_List <Data_Type> ::	Linked_List()
    {
        n = 0;
        head = NULL;
    }
template <class Data_Type >
void Linked_List <Data_Type> :: Create_List(int size)
    {
        n = size;
        head = new Node<Data_Type>;
        head->next = NULL;
        Node<Data_Type>* pointer = head;
        for (int i = 1; i < n; i++)
        {
            while (pointer->next != NULL)
            {
                pointer = pointer->next;
            }
            Node<Data_Type>* new_node = new Node<Data_Type>;
            pointer->next = new_node;
            new_node->next = NULL;
        }
    }
template <class Data_Type >
Linked_List <Data_Type> ::	Linked_List(int size)
    {
        Create_List(size);
    }

template <class Data_Type >
Linked_List <Data_Type> ::	~Linked_List()
    {
        // free All the LinkedList
        // temp pointer
        Node<Data_Type>* pointer = head;
        // free the First Node each time
        while (pointer != NULL)
        {
            // make the pointer points at the next node ........ free the head(free the first Node)
            pointer = pointer->next;
            delete head;
            // make the head points at the new first node of deleting List
            head = pointer;
        }
    }
    // copy constructor
template <class Data_Type >
Linked_List <Data_Type> ::	Linked_List(const Linked_List <Data_Type>& Copy)
    {
        n = Copy.n;
        Create_List(Copy.n);
        *this = Copy;

    }
template <class Data_Type >
Linked_List <Data_Type>& Linked_List <Data_Type> ::operator = (const Linked_List <Data_Type>& copy)
    {
        // check if it is not the same size
        if (n != copy.n)
        {
            cout << "Error in operator ===========" << "\n" ;
            // system("pause");
            exit(1);
        }
        // temp pointers to each Linked_List
        Node<Data_Type>* pointer = head;
        Node<Data_Type>* copy_ptr = copy.head;
        // copying Data in each Node
        while (pointer != NULL && copy_ptr != NULL)
        {
            // VERY IMPORTANT
            // WE MUS T DECLARE = Operator in the DataType data of Node if DataType is a class
            pointer->data = copy_ptr->data;

            pointer = pointer->next;
            copy_ptr = copy_ptr->next;
        }
        return *this;
    }
template <class Data_Type >
Data_Type* Linked_List <Data_Type> :: Add(Data_Type added_data)
    {
        // if head== NULL (the List is not created) we should add the first element of it
        if (head == NULL)
        {
            // allocate 1 node and point it by the head
            head = new Node<Data_Type>;
            // as it is 1 node set the next ptr to NULL
            head->next = NULL;
            n++;
            head->data = added_data;
            return &head->data;
        }
        // Allocate memory for 1 Node and point to it by new_node pointer
        Node<Data_Type>* new_node = new Node<Data_Type>;
        // pointer is a temp ptr to Access all the Nodes of linked list
        Node<Data_Type>* pointer = head;
        // Access the last Node in the List
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        // Make the Last Node point at the added Node
        pointer->next = new_node;
        // Make the Added Node (which is last Node Now) points at NULL
        new_node->next = NULL;
        // add the data
        new_node->data = added_data;
        n++;
        // pointer to the data
        return &  new_node->data;
    }
template <class Data_Type >
Data_Type* Linked_List <Data_Type>:: Add_First(Data_Type added_data)
    {
        Node<Data_Type>* new_node = new Node<Data_Type>;

        new_node->next = head;
        new_node->data = added_data;

        head = new_node;
        n++;
        return &new_node->data;
    }
template <class Data_Type >
int Linked_List <Data_Type>:: Find(Data_Type Search_Data)
    {
        Node<Data_Type>* pointer = head;
        for (int i = 0; i < n; i++)
        {
            if (pointer->data == Search_Data)
                return i;
            pointer = pointer->next;
        }
        return -1;
    }
template <class Data_Type >
void Linked_List <Data_Type>:: Delete(Data_Type Delete_Data)
    {
        int pos = Find(Delete_Data);
        if (pos == -1)
        {
            return;
        }
        Node<Data_Type>* ptr_befor = head;
        // if the deleted data at first so ther is no ptr_befor
        if (pos == 0)
        {
            // update head pointer to point at next node
            head = head->next;
            delete ptr_befor;
            n--;
            return;
        }
        // Get a pointer to the element befor the Deleted
        for (int i = 0; i < pos - 1; i++)
        {
            ptr_befor = ptr_befor->next;
        }
        // pointer to deleted element to free its memory
        Node<Data_Type>* deleted = ptr_befor->next;
        // connect the Linked List
        ptr_befor->next = deleted->next;
        delete deleted;
        n--;
        return;
    }
template <class Data_Type >
void Linked_List <Data_Type>:: insert(Data_Type inserted_data, int pos)
    {
        // if you want to insert at the begin use Add_First
        if (pos == 0)
        {
            Add_First(inserted_data);
            return;

        }
        Node<Data_Type>* new_node = new Node<Data_Type>;
        Node<Data_Type>* ptr_befor = head;

        // Get a pointer to the element befor the Inserted pos
        for (int i = 0; i < pos - 1; i++)
        {
            ptr_befor = ptr_befor->next;
        }

        new_node->data = inserted_data;
        // make the inserted element points at the next element
        new_node->next = ptr_befor->next;
        // make the element befor the inserted one .. points at the inserted
        ptr_befor->next = new_node;

        n++;
        return;
    }
template <class Data_Type>
int Linked_List <Data_Type>:: Size()
    {
        return n;
    }
template <class Data_Type>
Data_Type& Linked_List <Data_Type> :: operator [] (int pos)
    {
        Node<Data_Type>* pointer = head;
        if (pos > 0 && pos < n)
        {
            for (int i = 0; i < pos; i++)
            {
                pointer = pointer->next;
            }
        }
        else if (pos < 0 && n + pos >= 0)
        {
            for (int i = 0; i < n + pos; i++)
            {
                pointer = pointer->next;
            }
        }
        return pointer->data;
    }
template <typename Data_Typ > ostream& operator << (ostream& COUT, Linked_List<Data_Typ> List)
{
    // Don't print if there is No list
    if (List.head == NULL)
    {
        return COUT;
    }
    Node<Data_Typ>* pointer = List.head;
    int i = 1;
    while (pointer != NULL)
    {
        // printing the Number of cound
        cout << i << "-";
        i++;

        COUT << pointer->data << "\n";
        pointer = pointer->next;
    }
    return COUT;
}
template <typename Data_Typ > istream& operator >> (istream& CIN , Linked_List<Data_Typ>& List)
{
    Node<Data_Typ>* pointer = List.head;
    while (pointer != NULL)
    {
        CIN >> pointer->data;
        pointer = pointer->next;
    }
    return CIN;
}

#endif // LINKED_LIST_H
