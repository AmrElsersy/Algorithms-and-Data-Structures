#ifndef MAMMOTH_GENOME_DECODING_H
#define MAMMOTH_GENOME_DECODING_H
#include "my_stl.h"

bool comp(pair<int,char> x , pair<int,char> y)
{
    if( x.first  < y.first  )
        return true;
    return false;
}
void Mammoth()
{
    uint n ; cin >> n;
    string s  ; cin >> s;
    map<char,uint> ACGT ;
    ACGT['A'] = 0;
    ACGT['C'] = 0;
    ACGT['G'] = 0;
    ACGT['T'] = 0;
    ACGT['?'] = 0;

    if (n %4 !=0 )
    {
        cout << "===" << endl;
        return;
    }

    for (uint8_t i = 0; i < n; ++i) {
        ACGT[s[i]] ++;
    }

    uint x = n/4;
    map<char,uint> t(ACGT.begin(), ACGT.end());

    for (uint i = 0 ; i < ACGT['?'] ;i++) {
        if (ACGT['A'] < x)
            ACGT['A'] = ACGT['A']+1;
        else if (ACGT['C'] < x)
            ACGT['C'] =ACGT['C']+1;
        else if (ACGT['G'] < x)
            ACGT['G'] =ACGT['G']+1;
        else if (ACGT['T'] < x)
            ACGT['T'] =ACGT['T']+1;
    }


    if (ACGT['A'] == x && ACGT['C'] == x && ACGT['G'] == x && ACGT['T'] == x)
    {
        while (true)
        {
            string y ;
            if (t['A'] < x)
            {t['A'] = t['A']+1; y = "A" ;  }
            else if (t['C'] < x)
            {t['C'] = t['C']+1; y = "C" ;  }
            else if (t['G'] < x)
            {t['G'] = t['G']+1; y = "G" ;  }
            else if (t['T'] < x)
            {t['A'] = t['T']+1; y = "T" ;  }

            int pos = -1;
            pos = s.find_first_of('?', pos+1);
            if(pos != -1)
            {
                s.replace(pos,1,y);
                continue;
            }
            break;
        }
        cout << s << endl;
        return ;
    }
    cout << "===" << endl;

}
#endif // MAMMOTH_GENOME_DECODING_H
