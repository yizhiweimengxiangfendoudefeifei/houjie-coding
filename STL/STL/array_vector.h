#pragma once
#ifndef __array_vector__
#define __array_vector__

using namespace std;
const long ASIZE = 500000L;

//STL
long get_a_target_long()
{
	long target = 0;

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	return target;
}

string get_a_target_string()
{
	long target = 0;
	char buf[10];

	cout << "target (0~" << RAND_MAX << "): ";
	cin >> target;
	snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
	//cout << *(long*)a << endl;
	return (*(long*)a - *(long*)b);
}

int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}
#include<iostream>
#include<array>
#include<algorithm>
namespace glf00 {

	void test_array(){
		cout << "\n--------------test_array----------\n";
		array<long, ASIZE> c;

		clock_t timeStart = clock();
		for (int i = 0; i < ASIZE; i++) {
			c[i] = rand();
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "c size  " << c.size() << endl;
		cout << "c front  " << c.front() << endl;
		cout << "c back  " << c.back() << endl;
		cout << "c data  " << c.data() << endl;

		clock_t timeStart1 = clock();
		::qsort((c.data()), ASIZE, sizeof(long), compareLongs);

		long target = get_a_target_long();
		long* pI = (long*)::bsearch(&target, (c.data()), ASIZE, sizeof(long),compareLongs);
		cout << "qsort + qsort mili-seconds:  " << clock() - timeStart1 << endl;
		if (pI != NULL) {
			cout << "found： " << *pI << endl;
		}
		else {
			cout << "not found" << endl;
		}
		

	}
}


#include<vector>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstdio> //sprintf
#include<iostream>
#include<cstdlib>
namespace glf01
{
	void test_vector(long& value) {
		cout << "\n--------------test_vector----------\n";
		vector<string> v;
		char buf[10];

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				v.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;//119586578 p.what:bad allocation
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "c size  " << v.size() << endl;
		cout << "c front  " << v.front() << endl;
		cout << "c back  " << v.back() << endl;
		cout << "c data  " << v.data() << endl;

		
		string target = get_a_target_string();

		{
			timeStart = clock();
			auto pI = ::find(v.begin(),v.end(),target);
			cout << "find mili-seconds:  " << clock() - timeStart << endl;
			if (pI != v.end()) {
				cout << "find :" << *pI << endl;
			}
			else {
				cout << "not find :" << endl;
			}
		}

		{
			timeStart = clock();
			::qsort(v.data(), value, sizeof(string), compareStrings);
			auto* pI = (string*)::bsearch(&target, (v.data()), value, sizeof(string), compareStrings);
			cout << "qsort + bsearch mili-seconds:  " << clock() - timeStart << endl;
			if (pI != NULL) {
				cout << "find :" << *pI << endl;
			}
			else {
				cout << "not find :" << endl;
			}
		}
		v.clear();
	}
}

#include<deque>
namespace glf02
{
	void test_deque(long& value) {
		cout << "\n--------------test_deque----------\n";
		deque<string> deq;
		char buf[10];

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				deq.push_back(string(buf));
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;//119586578 p.what:bad allocation
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "deq size  " << deq.size() << endl;
		cout << "deq front  " << deq.front() << endl;
		cout << "deq back  " << deq.back() << endl;
		cout << "deq max_size  " << deq.max_size() << endl;

		string target = get_a_target_string();

		{
			timeStart = clock();
			auto pI = ::find(deq.begin(), deq.end(), target);
			cout << "find mili-seconds:  " << clock() - timeStart << endl;
			if (pI != deq.end()) {
				cout << "find :" << *pI << endl;
			}
			else {
				cout << "not find :" << endl;
			}
		}

		{
			timeStart = clock();
			::sort(deq.begin(), deq.end());
			
			cout << "sort mili-seconds: " << clock() - timeStart << endl;
		}
		deq.clear();
	}
}

#include<list>
#include<ctime>
#include<algorithm>
using namespace std;
namespace glf03
{
	void test_list(long& value) {
		cout << "\n--------------test_list---------\n";
		
		list<string> l;
		
		char buf[10]; 

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				l.push_back(string(buf));
				
			}
			catch (exception& p) {
				cout << "i = " << i << " " << p.what() << endl;//119586578 p.what:bad allocation
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "deq size  " << l.size() << endl;
		cout << "deq front  " << l.front() << endl;
		cout << "deq back  " << l.back() << endl;
		cout << "deq max_size  " << l.max_size() << endl;

		string target = get_a_target_string();

		{
			timeStart = clock();
			auto pI = ::find(l.begin(), l.end(), target);
			cout << "find mili-seconds:  " << clock() - timeStart << endl;
			if (pI != l.end()) {
				cout << "find :" << *pI << endl;
			}
			else {
				cout << "not find :" << endl;
			}
		}

		{
			timeStart = clock();
			l.sort();
			cout << "l.sort mili-seconds: " << clock() - timeStart << endl;
			

		}
		l.clear();
	}
}

#include<set>

namespace glf04
{
	void test_multiset(long& value) {
		cout << "\n--------------test_multiset---------\n";
		multiset<string> s;
		char buf[10];

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try{
				snprintf(buf, 10, "%d", rand());
				s.insert(string(buf));
				
			}
			catch (exception& p) {
				cout << "i = " << i << p.what() << endl;
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "multiset size  " << s.size() << endl;
		cout << "multiset max_size  " << s.max_size() << endl;

		string target = get_a_target_string();

		auto pItem = s.find(target);

		if (pItem != s.end()) {
			cout << "find :" << (*pItem)<< endl;
		}
		else {
			cout << "not find :" << endl;
		}
		
		cout << "s.find mili-seconds: " << clock() - timeStart << endl;
		
		s.clear();
	}
}

#include<map>
namespace glf05
{
	void test_multimap(long& value) {
		cout << "\n--------------test_multimap---------\n";
		multimap<long,string> m;
		char buf[10];

		clock_t timeStart = clock();
		for (long i = 0; i < value; ++i) {
			try {
				snprintf(buf, 10, "%d", rand());
				m.insert(pair<long, string>(i, buf));
			}
			catch (exception& e) {
				cout << "i = " << i << e.what() << endl;
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "multimap size  " << m.size() << endl;
		cout << "multimap max_size  " << m.max_size() << endl;

		long target = get_a_target_long();
		{
			clock_t timeStart = clock();
			auto pItem = m.find(target);
			if (pItem != m.end()) {
				cout << "find :" << (*pItem).second << endl;
			}
			else {
				cout << "not find :" << endl;
			}

			cout << "s.find mili-seconds: " << clock() - timeStart << endl;
		}
		

		m.clear();
	}
}

namespace glf06
{
	void test_set(long& value) {
		cout << "\n--------------test_set---------\n";
		set<string> s;
		char buf[10];

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				s.insert(string(buf));

			}
			catch (exception& p) {
				cout << "i = " << i << p.what() << endl;
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "set size  " << s.size() << endl;
		cout << "set max_size  " << s.max_size() << endl;

		string target = get_a_target_string();

		auto pItem = s.find(target);

		if (pItem != s.end()) {
			cout << "find :" << (*pItem) << endl;
		}
		else {
			cout << "not find :" << endl;
		}

		cout << "s.find mili-seconds: " << clock() - timeStart << endl;

		s.clear();
	}
}

#include<map>
namespace glf07
{
	void test_map(long& value) {
		cout << "\n--------------test_map---------\n";
		map<long,string> s;
		char buf[10];

		clock_t timeStart = clock();
		for (int i = 0; i < value; i++) {
			try {
				snprintf(buf, 10, "%d", rand());
				s.insert(pair<long,string>(i,buf));

			}
			catch (exception& p) {
				cout << "i = " << i << p.what() << endl;
				abort();
			}
		}

		cout << "mili-seconds:  " << clock() - timeStart << endl;
		cout << "map size  " << s.size() << endl;
		cout << "map max_size  " << s.max_size() << endl;

		long target = get_a_target_long();

		auto pItem = s.find(target);

		if (pItem != s.end()) {
			cout << "find :" << (*pItem).second << endl;
		}
		else {
			cout << "not find :" << endl;
		}

		cout << "s.find mili-seconds: " << clock() - timeStart << endl;

		s.clear();
	}
}


#include <typeinfo>     // typeid
#include<forward_list>
#include <unordered_set>
#include <unordered_map>
namespace glf08 {//迭代器类型
	//函数重载
	void _display_category(random_access_iterator_tag) {
		cout << "random_access_iterato" << endl;
	}
	void _display_category(bidirectional_iterator_tag) {
		cout << "bidirectional_iterator" << endl;
	}
	void _display_category(forward_iterator_tag) {
		cout << "forward_iterator" << endl;
	}
	void _display_category(input_iterator_tag) {
		cout << "input_iterator \n";
	}
	void _display_category(output_iterator_tag) {
		cout << "output_iterator \n";
	}
	//模板调用
	template<typename T>
	void display_category(T ite) {
		typename iterator_traits<T>::iterator_category cagy;
		_display_category(cagy);
		cout << "typeid(ite).name()= " << typeid(ite).name() << endl;

	}

	void test_iterator() {
		cout << "____________________test_iterator_________________" << endl;
		display_category(array<int,10>::iterator());
		display_category(vector<int>::iterator());
		display_category(list<int>::iterator());
		display_category(forward_list<int>::iterator());
		display_category(deque<int>::iterator());

		display_category(set<int>::iterator());
		display_category(map<int, int>::iterator());
		display_category(multiset<int>::iterator());
		display_category(multimap<int, int>::iterator());
		display_category(unordered_set<int>::iterator());
		display_category(unordered_map<int, int>::iterator());
		display_category(unordered_multiset<int>::iterator());
		display_category(unordered_multimap<int, int>::iterator());

		display_category(istream_iterator<int>());
		display_category(ostream_iterator<int>(cout, ""));

	}
}


#include <numeric>      // std::accumulate
namespace glf09 {
	int myfunc(int a, int b) { return a + 2*b; }

	class myclass
	{
	public:
		int operator() (int x, int y){
			return x + 3 * y;
		}
	}myobject;
	void test_accumulate() {
		cout << "____________test_accumulate_________________\n";

		int init = 100;
		int arr[] = { 1,2,3 };

		cout << "using default accumulate: ";
		cout << accumulate(arr, arr+3, init) << endl;//地址直接加3表示另一个地址

		cout << "using functional's minus: ";
		cout << accumulate(arr, arr + 3, init, minus<int>()) << endl;

		cout << "using custom function: ";
		cout << accumulate(arr, arr + 3, init, myfunc)<<endl;//小括号能够作用到myfunc上
		
		cout << "using custom object:  ";
		cout << accumulate(arr, arr + 3, init, myobject) << endl;//函数对象里边重载小括号
	}
}

#include<iostream>
using namespace std;
namespace glf10 {

	void myfunc(int a) {
		cout << a << " ";
	}
	
	struct myclass
	{
		void operator()(int& a) {
			a *= 2;
			cout << a << " ";
		}
	}myobject;
	//cout << endl;这样是错误的，为什么？？？

	void test_for_each() {
		cout << "__________________test_for_each_________________" << endl;
		int arr[] = { 1,2,3,4,5,6 };

		vector<int> vec(arr, arr + 6);
		for_each(vec.begin(), vec.end(), myfunc);
		cout << endl;

		for_each(vec.begin(), vec.end(), myobject);
		cout << endl;

		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;

	}
}

namespace glf11 {
	bool myfunc(int a) {
		return a < 7;
	}
	void test_count() {
		cout << "______________test_count_________________\n";

		int arr[] = { 1,2,3,4,5,6,7 };
		vector<int> vec(arr, arr + 7);

		cout << count(vec.begin(), vec.end(), 1) << endl;

		cout << count_if(vec.begin(), vec.end(), myfunc) << endl;
	}
}

namespace glf12 {
	bool myfunc(int a) {
		return a == 3;
	}
	void test_find_if() {
		cout << "_____________________test_find_if____________________\n";
		int arr[] = { 1,2,3,4,5,6,7};
		vector<int> vec(arr, arr + 7);

		auto it = find_if(vec.begin(), vec.end(), myfunc);
		cout << "the first myfunc value: " << *it << endl;
	}
}

namespace glf13 {
	bool myfunc(int a,int b) {
		return a > b;
	}
	struct myclass
	{
		bool operator()(int a, int b) {
			return a < b;
		}
	}myobject;
	void test_sort() {
		cout << "____________________test_sort__________________________\n";
		int arr[] = { 1,3,2,7,6,4,10,6};
		vector<int> vec(arr, arr + 8);

		sort(vec.begin(), vec.end());
		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;

		sort(vec.begin(), vec.end(),myfunc);
		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;

		sort(vec.begin(), vec.end(), myobject);
		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;

		//reverse
		sort(vec.rbegin(), vec.rend());
		for (auto i : vec) {
			cout << i << " ";
		}
		cout << endl;

	}
}



#include <functional>
using namespace std::placeholders;
namespace glf14 {
	double my_divide(double a, double b)
	{
		return a / b;
	}
	struct my_multi {
		
		double a, b;
		double multi() {
			return a * b;
		}
	};
	void test_bind() {
		cout << "_________________test_bind_____________\n";
		auto fn_five = bind(my_divide, 10, 2);
		cout << fn_five() << endl;

		auto fn_half = bind(my_divide, _1, 2);
		cout << fn_half(10) << endl;

		auto fn_invert = bind(my_divide, _2, _1);
		cout << fn_invert(10, 2) << "\n";

		auto fn_rounding = bind<int>(my_divide, _1, _2);
		cout << fn_rounding(10, 3) << "\n";

		//绑定成员函数
		my_multi members {10,2};
		auto fn_memfn = bind(&my_multi::multi, _1);
		cout << fn_memfn(members) << "\n";

		//绑定成员函数数据
		auto fn_memdata1 = bind(&my_multi::a, members);
		cout << fn_memdata1() << endl;

		auto fn_memdata2 = bind(&my_multi::b, _1);
		cout << fn_memdata2(members) << endl;

		vector<int> v{ 15,37,94,50,73,58,28,98 };
		int n = count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 50)));
		cout << "n = " << n << endl;

		auto fn_ = bind(less<int>(), _1, 50);
		cout << count_if(v.cbegin(), v.cend(), fn_) << endl;
		cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50)) << endl;

	}
}
#endif // !__array_vector__
