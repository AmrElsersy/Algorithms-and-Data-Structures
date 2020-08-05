#ifndef HQ9_H_INCLUDED
#define HQ9_H_INCLUDED

void HQ()
{
    string x ; cin >> x ;
    int pos = x.find_first_of("HQ9");
    if(pos != -1)
        cout << "YES";
    else
        cout << "NO";
}

#endif // HQ9_H_INCLUDED
