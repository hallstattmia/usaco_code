#include <iostream>
using namespace std;

void Pour(int &m0, int &m, int &c)
{
    
    if (m0 <= c - m)
    {
        //bucket b; m -> m + m0
        m = m + m0;
        //bucket a is empty
        m0 = 0;
    }
    else
    {   
        //bucekt a: m0 --> m0 - (c - m)
        m0 = m0 - (c - m);
        //bucket b is full
        m = c;
    }
}

int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;
    for (int i = 1; i <= 33; i = i + 1)   
    {
        Pour(m1, m2, c2);
        Pour(m2, m3, c3);
        Pour(m3, m1, c1);
    }
    Pour(m1, m2, c2);
    cout << m1 << "\n"
         << m2 << "\n"
         << m3;
}
