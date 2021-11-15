#include<bits/stdc++.h>
#include "String.h"
using namespace std;
int main()
{
    String s1;
    String s2("hello");
    String s3(s2);
    s1 = s2;
    cout << s1 << endl;
    cout << s3 << endl;
    String s4("We");
    s4 = s2;
    String s5 = s2;
    cout << s5 << endl;
    return 0;
}