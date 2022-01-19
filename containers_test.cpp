#include<bits/stdc++.h>
using namespace std;
//tool--------------------------------------------------------
const long ASIZE = 50000;
int get_a_target_int()
{
    int target = 0;
    cout << "target (0~" << RAND_MAX << "):  ";
    cin >> target;
    return target;
}
long get_a_target_long()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX << "):  ";
    cin >> target;
    return target;
}
string get_a_target_string()
{
    string str;
    cout << "target (0~" << RAND_MAX << "):  ";
    cin >> str;
    return str;
}
long get_len()
{
    long num;
    cout << "how many elements: ";
    cin >> num;
    return num;
}
//tool--------------------------------------------------------
//array-------------------------------------------------------
bool cmp_array(int& a,int& b)
{
    return a < b;
}
void test_array()
{
    cout << "test array" << endl;
    array<int,ASIZE> nums;
    time_t timestart = clock();
    for(int& i : nums)
    {
        i = rand();
    }
    cout << "milli-seconds : " << (clock()-timestart) << endl;	//
	cout << "array.size()= " << nums.size() << endl;		
	cout << "array.front()= " << nums.front() << endl;	
	cout << "array.back()= " << nums.back() << endl;	
	cout << "array.data()= " << nums.data() << endl;//返回一个指向首个元素的指针	
    
    int target = get_a_target_int();
    timestart = clock();
    sort(nums.begin(),nums.end(),cmp_array);
    bool flag = binary_search(nums.begin(),nums.end(),target);
    cout << "sort() + binary_search(),milli-seconds : " << (clock() - timestart) << endl;
    if(flag)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
//array-------------------------------------------------------
//vector------------------------------------------------------
class cmp_vector
{
public:
    bool operator ()(const int& a,const int& b)
    {
        return a < b;
    }
};
void test_vector()
{
    cout << "test vector" << endl;
    vector<int> vec;
    cout << "how many elements: ";
    int value;
    cin >> value;
    srand(time(0));
    time_t timestart = clock();
    for(int i = 0;i < value;i++)
    {
        try
        {
            int tmp = rand();
            vec.push_back(tmp);
            //每次内存不足了，进行两倍扩充，在其他地方找到一块新的内存，再进行搬运
        }
        catch(const std::exception& e)
        {
            cout << "i = " << i << " " << e.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << (clock()-timestart) << endl;	
	cout << "vector.max_size()= " << vec.max_size() << endl;	
	cout << "vector.size()= " << vec.size() << endl;		
	cout << "vector.front()= " << vec.front() << endl;	
	cout << "vector.back()= " << vec.back() << endl;	
	cout << "vector.data()= " << vec.data() << endl;
	cout << "vector.capacity()= " << vec.capacity() << endl << endl;
    int target;
    target = get_a_target_int();
    timestart = clock();
    auto pItem = find(vec.begin(),vec.end(),target);
    if(pItem != vec.end())
    {
        cout << "found " << *pItem;
    }
    else
    {
        cout << "not found";
    }
    cout << " find() milli-seconds: " << clock() - timestart << endl;
    timestart = clock();
    sort(vec.begin(),vec.end(),cmp_vector());
    bool flag = binary_search(vec.begin(),vec.end(),target);
    if(flag)
    {
        cout << "found " << target;
    }
    else
    {
        cout << "not found";
    }
    cout << " sort() + binary_search() milli-seconds: " << clock() - timestart << endl;
}
//vector------------------------------------------------------
//list----------------------------------------------------------
class cmp_list_string
{
public:
    bool operator()(const string& str1,const string& str2)
    {
        if(str1.size() != str2.size())
        {
            return str1.size() < str2.size();
        }
        else
        {
            return str1 < str2;
        }
    }
};
void test_list()
{
	cout << "\ntest_list().......... \n";
    int value;
    cin >> value; 
    list<string> c;
    srand(time(0));  		
    clock_t timeStart = clock();							
    for(long i=0; i< value; ++i)
    {
    	try {
    		int tmp = rand();
        	c.push_back(to_string(tmp));    	
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "list.size()= " << c.size() << endl;
	cout << "list.max_size()= " << c.max_size() << endl;    //357913941
	cout << "list.front()= " << c.front() << endl;	
	cout << "list.back()= " << c.back() << endl;		
		
    int target = get_a_target_int();		
    timeStart = clock();		
    auto pItem = find(c.begin(), c.end(), to_string(target));						
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	
  	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	c.sort();//运用成员函数sort()优于全局函数sort()	
    //sort(c.begin(),c.end(),cmp_list_string());					
	cout << "c.sort(), milli-seconds : " << (clock()-timeStart) << endl;		    	 
}
//list-----------------------------------------------------------------------
//deque----------------------------------------------------------------------
void test_deque()
{
    cout << "\ntest_deque().......... \n";
    int value;
    cin >> value;    
    deque<string> c;  	
    srand(0);
    clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
            int tmp = rand();
        	c.push_back(to_string(tmp));
            //deque的扩充，一次扩充一个buffer，每个buffer由一个指针指向，使用迭代器进行遍历时，由于重载了++表面是连续的    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "deque.size()= " << c.size() << endl;
	cout << "deque.front()= " << c.front() << endl;	
	cout << "deque.back()= " << c.back() << endl;	
	cout << "deque.max_size()= " << c.max_size() << endl;	//1073741821	
	
    int target = get_a_target_int();	
    timeStart = clock();			
    auto pItem = find(c.begin(), c.end(), to_string(target));	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;	
	
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
    	
    timeStart = clock();		
	sort(c.begin(), c.end());						
	cout << "sort(), milli-seconds : " << (clock()-timeStart) << endl;		
	
	c.clear();    
}
//deque----------------------------------------------------------------------
//set------------------------------------------------------------------------
void test_set(long& value)
{
	cout << "\ntest_set().......... \n";
     
set<string> c;  	
char buf[10];

clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));     					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "set.size()= " << c.size() << endl;
	cout << "set.max_size()= " << c.max_size() << endl;	   //214748364
		
string target = get_a_target_string();	
	{
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}
 	
 	{
    timeStart = clock();		
auto pItem = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	}							
}	
//set------------------------------------------------------------------------
//map------------------------------------------------------------------------
void test_map(long& value)
{
	cout << "\ntest_map().......... \n";
     
map<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);  					
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;	
	cout << "map.size()= " << c.size() << endl;	
	cout << "map.max_size()= " << c.max_size() << endl;		//178956970
	
long target = get_a_target_long();		
    timeStart = clock();		
auto pItem = c.find(target);								
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;			
    	
    c.clear();					
}		
//map------------------------------------------------------------------------
//unordered_set--------------------------------------------------------------
void test_unordered_set(long& value)
{
	cout << "\ntest_unordered_set().......... \n";
     
unordered_set<string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
        	c.insert(string(buf));    			 		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_set.size()= " << c.size() << endl;	
	cout << "unordered_set.max_size()= " << c.max_size() << endl;  //357913941
	cout << "unordered_set.bucket_count()= " << c.bucket_count() << endl;	
	cout << "unordered_set.load_factor()= " << c.load_factor() << endl;	
	cout << "unordered_set.max_load_factor()= " << c.max_load_factor() << endl;	
	cout << "unordered_set.max_bucket_count()= " << c.max_bucket_count() << endl;			
  	for (unsigned i=0; i< 20; ++i) {
    	cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
  	}			
	
string target = get_a_target_string();	
	
    timeStart = clock();
auto pItem = find(c.begin(), c.end(), target);	//比 c.find(...) 慢很多	
	cout << "std::find(), milli-seconds : " << (clock()-timeStart) << endl;		
	if (pItem != c.end())
    	cout << "found, " << *pItem << endl;
  	else
    	cout << "not found! " << endl;	
 	
 
 	
    timeStart = clock();		
auto pItem2 = c.find(target);		//比 std::find(...) 快很多							
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem2 != c.end())
    	cout << "found, " << *pItem2 << endl;
  	else
    	cout << "not found! " << endl;	
 		
}
//unordered_set
//unordered_map
void test_unordered_map(long& value)
{
	cout << "\ntest_unordered_map().......... \n";

unordered_map<long, string> c;  	
char buf[10];
			
clock_t timeStart = clock();								
    for(long i=0; i< value; ++i)
    {
    	try {
    		snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);  		
		}
		catch(exception& p) {
			cout << "i=" << i << " " << p.what() << endl;	
			abort();
		}
	}
	cout << "milli-seconds : " << (clock()-timeStart) << endl;		
	cout << "unordered_map.size()= " << c.size() << endl;	//357913941
	cout << "unordered_map.max_size()= " << c.max_size() << endl;	
	
long target = get_a_target_long();		
    timeStart = clock();	
//! auto pItem = find(c.begin(), c.end(), target);	//map 不適用 std::find() 			
auto pItem = c.find(target);
						
	cout << "c.find(), milli-seconds : " << (clock()-timeStart) << endl;		 
	if (pItem != c.end())
    	cout << "found, value=" << (*pItem).second << endl;
  	else
    	cout << "not found! " << endl;		
}		
//unordered_map
int main()
{
    //test_array();
    //test_vector();
    //test_list();
    //test_deque();
    long value = get_len();
    //test_set(value);
    //test_unordered_set(value);
    //test_map(value);
    //test_unordered_map(value);
    return 0;
}