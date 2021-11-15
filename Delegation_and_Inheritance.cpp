#include<bits/stdc++.h>
#include "Delegation_and_Inheritance.h"
using namespace std;
int test_observer()
{
    Subject subj;
    Observer1 o1(&subj,4);
    Observer1 o2(&subj,3);
    Observer2 o3(&subj,3);
    o1.show();
    o2.show();
    o3.show();
    subj.set_val(3);
    subj.set_val(6);
    return 0;
}
int main()
{
    test_observer();
    return 0;
}