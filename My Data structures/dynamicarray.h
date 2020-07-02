#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
using namespace std;

template <class Data_Type>
class DynamicArray
{
public:
    Data_Type* pointer;
    int n;

public:
    DynamicArray();
    DynamicArray(int value_n);
    DynamicArray(const DynamicArray& Copy);
    ~DynamicArray();

    // [1,2,3] ...arr += 5 ... [1,2,3,5] (OR arr.Add_Last(5))
    // add to the end of the array
    void Add_Last(Data_Type new_value);
    DynamicArray& operator += (Data_Type value);

    // [1,2,3] ... arr.Add_First(5) ... [5,1,2,3]
    // add to the begin of the array
    void Add_First(Data_Type new_value);
    // inserting element at any position (without replacing)
    // [1,2,3] ... arr.Insert(5,1) ... [1,5,2,3]
    void Insert(Data_Type value, int pos);
    // search for the element and return its position
    // if not found return -1
    int search(Data_Type value);
    // delete element Dynamically
    void Delete(Data_Type value);
    // return the size (length) of the array
    int size();
    // return the max of min element in the array
    Data_Type max();
    Data_Type min();
    // use it like the array
    // if we use -ve numbers it will count from the end to begin
    // arr = [1,2,3,4] ... arr[-1] = 4 ... arr[-2] = 3
    Data_Type& operator [] (int pos);
    // initial all the array's elments by a value ... arr = 0 ... arr = [0,,0,0,0,0]
    void operator = (Data_Type initial_value);
    // adding 2 arrays ...  arr1 [1,2,3] , arr2 [4 , 5 ,6 ]  .... arr1 += arr2 .... arr1 = [1,2,3,4,5,6]
    DynamicArray& operator += (DynamicArray& added_array);

    template <typename data_Type> friend DynamicArray <data_Type> operator + (DynamicArray<data_Type> First_array ,const DynamicArray <data_Type> added_array);
    // Swap any 2 elements in the array by thier position
    void Swap(int pos1, int pos2);
    // Sorting the elements of the array
    void Sort();
    // print the array like any variable  .... cout << object ;
    template <typename Data_Typ > friend ostream& operator << (ostream& our_cout, DynamicArray<Data_Typ> printed_array);
    // cin >> object ;
    template <typename Data_Typ > friend istream& operator >> (istream& our_cin, DynamicArray<Data_Typ>& Get_array);

    DynamicArray& operator = (const DynamicArray& Copy);
};

template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray()
{
    pointer = NULL ;
    n=0;
}
template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray (int value_n )
{
    n = value_n;
    pointer = new Data_Type[n];
}
template <class Data_Type>
DynamicArray <Data_Type> :: ~DynamicArray ()
{
    delete[] pointer;
}
template <class Data_Type>
DynamicArray <Data_Type>::DynamicArray (const DynamicArray <Data_Type>& Copy)
{
    n = Copy.n;
    pointer = new Data_Type[n];
    *this = Copy;
}

template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator = (const DynamicArray <Data_Type>& Copy)
{
    for (int i = 0; i < n; i++)
    {
        pointer[i] = Copy.pointer[i];
    }
    return *this;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Add_Last(Data_Type new_value)
{
    Data_Type* temp = new Data_Type[n + 1];
    // check if there is enough space

    // copy all the 2 arrays exept the last element
    for (int i = 0; i < n; i++)
        temp[i] = pointer[i];
    // put the new_value at the last element
    temp[n] = new_value;

    // free the space of the original pointer
    delete[] pointer;
    // make the pointer points at the new array you have made
    pointer = temp;
    n++;
}
template <class Data_Type>
void DynamicArray <Data_Type> :: Add_First(Data_Type new_value)
{
    Data_Type* temp = new Data_Type[n + 1];

    // check if there is enough space


    // copy all the 2 arrays exept the first element
    for (int i = 1; i <= n ; i++)
        temp[i] = pointer[i-1];
    // put the new_value at the first element
    temp[0] = new_value;

    // free the space of the original pointer
    delete[] pointer;
    // make the pointer point at the new array you have made
    pointer = temp;
    n++;
}
template <class Data_Type>
int DynamicArray <Data_Type>::search(Data_Type value)
{
    for (int i = 0; i < n; i++)
    {
        // return the position of the value that you want to search
        if (pointer[i] == value)
        {
            return i;
        }
    }
    return -1;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Delete(Data_Type value)
{
    // new array that has less space (n-1 ) as we delete 1 element
    Data_Type* temp = new Data_Type[n-1];


    // get the position of the value that you want to delete
    int position = search(value);



    for (int i = 0 , j =0 ; j< n-1 && i < n;  i++)
    {
        // copy all the 2 arrays exept the value that you want to delete
        if (i == position)
        {
            continue;
        }
        temp[j] = pointer[i];
        j++;
    }

    n--;
    delete[] pointer;
    pointer = temp;

}
template <class Data_Type>
void DynamicArray <Data_Type>::Insert(Data_Type value, int pos)
{
    // resize the array and add 1 more space
    n++;
    Data_Type* temp = new Data_Type[n];
    // check if there is enough space


    // variable that tell me that we inserted the value
    int variable_inserted = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            temp[pos] = value;
            variable_inserted = 1;
            continue;
        }
        // if we inserted the value .. we have to copy pointer [i-1] as we skiped this pos when we inserted the value
        if (variable_inserted == 1)
        {
            temp[i] = pointer[i - 1];
        }
        // if we didn't insert the value yet .. so we copy the elements normally from pointer to temp
        else if (variable_inserted == 0)
        {
            temp[i] = pointer[i];
        }
    }

    delete[] pointer;
    pointer = temp;
}
template <class Data_Type>
int DynamicArray <Data_Type>::size()
{
    return n;
}
template <class Data_Type>
Data_Type DynamicArray <Data_Type>::max()
{
    Data_Type max = pointer[0];
    for (int i = 1; i < n; i++)
    {
        // if the element is > than max .. make it max
        if (pointer[i] > max)
        {
            max = pointer[i];
        }
    }
    return max;
}
template <class Data_Type>
Data_Type DynamicArray <Data_Type>::min()
{
    Data_Type min = pointer[0];
    for (int i = 1; i < n; i++)
    {
        // if the element is less that the min .. make it min
        if (pointer[i] < min)
        {
            min = pointer[i];
        }
    }
    return min;
}
template <class Data_Type>
Data_Type& DynamicArray <Data_Type> :: operator [] (int pos)
{
    if (pos >= 0 && pos < n)
    {
        return pointer[pos];
    }

    // to support arr[-1] index from end ... like python ... arr = { 1, 2 ,3 }  .. arr[-1] = 3
    else if (pos < 0 && n + pos >= 0)
    {
        return pointer[n + pos];
    }


}
template <class Data_Type>
void DynamicArray <Data_Type> :: operator = (Data_Type initial_value)
{
    for (int i = 0; i < n; i++)
    {
        pointer[i] = initial_value;
    }
}
template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator += (Data_Type value)
{
    Add_Last(value);
    return *this;
}
template <class Data_Type>
DynamicArray <Data_Type>& DynamicArray <Data_Type> :: operator += (DynamicArray <Data_Type>& added_array)
{
    int temp_n = n;
    n += added_array.n;
    Data_Type* temp = new Data_Type[n];


    for (int i = 0; i < temp_n; i++)
    {
        temp[i] = pointer[i];
    }

    for (int i = temp_n , j = 0; j <added_array.n && i < n; j++ , i++)
    {
        temp[i] = added_array.pointer[j];
    }

    delete[] pointer;
    pointer = temp;

    return *this;
}
template <typename data_Type>
DynamicArray <data_Type> operator + (DynamicArray<data_Type> First_array ,DynamicArray <data_Type> added_array)
{
    First_array += added_array;
    return First_array;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Swap(int pos1, int pos2)
{
    Data_Type Temp = pointer[pos1];
    pointer[pos1] = pointer[pos2];
    pointer[pos2] = Temp;
}
template <class Data_Type>
void DynamicArray <Data_Type>::Sort()
{
    // Buble Sort Algorithm
    // iner loop is to Move the Bigest Element at Last
    // Outer loop is to repeat that operation until all thing is sorted
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            Data_Type Temp;
            if (pointer[i] > pointer[i + 1])
            {
                Swap(i, i + 1);
            }
        }
    }
}

template <typename Data_Typ > ostream& operator << (ostream& our_cout, DynamicArray<Data_Typ> printed_array)
{
    // very important
    // we send printed_array object by value but it didn't clear the original memory of the parameter and it works fine !!
    // Because Copy Constructor is called when we send the object by value and get a copy of it (not pointing at the same chunk of memory )
    // so we can now pass any object by value because of copy constructor
    for (int i = 0; i < printed_array.n; i++)
    {
        our_cout << printed_array.pointer[i];
        our_cout << "  ";
    }
    cout << "\n";
    return our_cout;
}

template <typename Data_Typ > istream& operator >> (istream& our_cin, DynamicArray<Data_Typ>& Get_array)
{
    for (int i = 0; i < Get_array.n; i++)
    {
        our_cin >> Get_array.pointer[i] ;
    }
    return our_cin;
}


//#include <QCoreApplication>
//#include "dynamicarray.h"
//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    DynamicArray <int>  Num(3);
//    DynamicArray <int>  NEW2(3);
//    DynamicArray <int>  s(6);
//    cout << "Enter List 1 then List 2" << endl;
//    cin >> Num;
//    cin >> NEW2;
//    s = Num + NEW2;
//    cout << Num << endl;
//    cout << NEW2 << endl ;
//    cout << s << endl;


//    Num.Add_Last(100);
//    Num.Add_First(300);

//    cout << "add first 300 last 100 :" << Num << endl;
//    Num.Insert(22, 2);
//    cout << "insert 22 :  " << Num << endl;
//    int find = Num.search(22);
//    cout << "find 22 :" << find << endl;
//    Num.Delete(3);
//    cout << Num;
//    int n = Num.size();
//    cout << "size  " << n << endl;
//    n = Num.max();
//    cout << "max " << n << endl;
//    cout << endl;
//    return a.exec();
//}

#endif // DYNAMICARRAY_H
