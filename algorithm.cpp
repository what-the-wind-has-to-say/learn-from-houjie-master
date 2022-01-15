//迭代器的分类
//random_access_iterator_tag  array vector Deque
//bidirectional_iterator_tag  List map set
//farward_iterator_tag  farward_list unordered_map unordered_set
//迭代器作为class的继承关系：input_iterator_tag -> farward_iterator_tag -> bidirection_iterator_tag -> randomaccess_iterator_tag
//algorithm 需要知道迭代器的分类，根据不同分类会有效率不同的做法

#include<bits/stdc++.h>
using namespace std;

void _display_category(random_access_iterator_tag)
{
    cout << "random_access_iterator_tag" << endl;
}
void _display_category(bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator_tag" << endl;
}
void _display_category(forward_iterator_tag)
{
    cout << "forward_iterator_tag" << endl;
}
template<class I>
void display_category(I iter)
{
    typename iterator_traits<I>::iterator_category c;
    _display_category(c);
}
//演示迭代器的分类
void display_iterator_category()
{
    display_category(array<int,10>::iterator());
    display_category(vector<int>::iterator());
    display_category(list<int>::iterator());
    display_category(deque<int>::iterator());
    display_category(set<int>::iterator());
    display_category(map<int,int>::iterator());
    display_category(unordered_set<int>::iterator());
    display_category(unordered_map<int,int>::iterator());
}
//sort()
//partial_sort()
void test_partial_sort()
{
    srand(time(NULL));
    vector<int>vec(10000,0);
    for(int i = 0;i < vec.size();i++)
    {
        vec[i] = rand();
    }
    partial_sort(vec.begin(),vec.begin() + 10,vec.end());
    for(int i = 0;i < 10;i++)
    {
        cout << vec[i] << " ";
    }
}
//nth_element()
template<class T>
struct cmp
{
    bool operator()(const T t1,const T t2)
    {
        return t1 > t2;
    }
};

void test_nth_element()
{
    srand(time(NULL));
    vector<int>vec(10000,0);
    for(int i = 0;i < vec.size();i++)
    {
        vec[i] = rand();
    }
    nth_element(vec.begin(),vec.begin() + 4,vec.end(),cmp<int>());
    for(int i = 0;i < 10;i++)
    {
        cout << vec[i] << " ";
    }
}
//is_sorted() && is_sorted_until()
void test_is_sorted()
{
    srand(time(NULL));
    vector<int>vec(10000,0);
    for(int i = 0;i < vec.size();i++)
    {
        vec[i] = rand();
    }
    auto iter = is_sorted_until(vec.begin(),vec.end());
    if(iter != vec.end())
    {
        cout << *iter << endl;
        sort(vec.begin(),vec.end());
    }
}
//list.sort() 不调用STL的sort()
int main()
{
    // test_partial_sort();
    // test_nth_element();
    // test_is_sorted();
    return 0;
}