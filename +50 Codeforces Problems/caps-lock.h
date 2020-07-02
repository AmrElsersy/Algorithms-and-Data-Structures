#ifndef CAPS-LOCK_H_INCLUDED
#define CAPS-LOCK_H_INCLUDED
void CAPS()
{
    string x ;  cin >> x;
    bool upperCase = true;

    for (int i =1 ; i < x.size(); i++)
        if (x[i] >= 'a')
            upperCase = false;

    if ( upperCase )
    {
        for (int i = 0 ; i < x.size() ; i++)
        {
            if(x[i] < 'a')
                x[i] += 32;
            else
                x[i] -= 32;
        }
    }
    cout << x << endl;

}


#endif // CAPS-LOCK_H_INCLUDED
