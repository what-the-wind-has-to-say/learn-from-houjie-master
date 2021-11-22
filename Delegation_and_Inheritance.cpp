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
const int NUM_IMAGES = 8;
vector<imageType>input = {LSAT,LSAT,LSAT,SPOT,LSAT,SPOT,SPOT,LSAT};
int test_prototype()
{
    Image* images[NUM_IMAGES];
    for(int i = 0;i < NUM_IMAGES;i++)
    {
        images[i] = Image::findAndClone(input[i]);
    }
    for(int i = 0;i < NUM_IMAGES;i++)
    {
        images[i]->draw();
    }
    for(int i = 0;i < NUM_IMAGES;i++)
    {
        delete images[i];
    }
    return 0;
}
int main()
{
    //test_observer();
    test_prototype();
    return 0;
}