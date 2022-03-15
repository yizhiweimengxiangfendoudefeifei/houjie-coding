#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include"array_vector.h"
#include<xmemory>


//range-based for statement
void test1()
{
	for (auto i : { 1,2,3,4,5,6,7,8,9 }) {
		cout << i;
	}
	cout << endl;
}
void test2() {
	int* p = allocator<int>().allocate(512, (int*)0);
	allocator<int>().deallocate(p, 512);
}

void test_containers()
{
	int choice;
	long value;
	cout << "input your choice: 0.array 1.vector 2.deque 3.list 4.multi_set 5.multi_map 6.set 7.map\n";
	cin >> choice;
	if (choice != 0) {
		cout << "how many elements: ";
		cin >> value;
	}
	switch (choice)
	{
	case 0:
		glf00::test_array();
		break;
	case 1:
		glf01::test_vector(value);
		break;
	case 2:
		glf02::test_deque(value);
		break;
	case 3:
		glf03::test_list(value);
		break;
	case 4:
		glf04::test_multiset(value);
		break;
	case 5:
		glf05::test_multimap(value);
		break;
	case 6:
		glf06::test_set(value);
		break;
	case 7:
		glf07::test_map(value);
		break;
	default:
		break;
	}
}
int main() {

	int ia[6] = { 41,52,12,30,99,30 };
	vector<int, allocator<int>> vi(ia, ia + 6);
	//输出容器中的内容
	for (auto& i : vi) {
		i *= 3;
		cout << i << " ";
	}
	cout << endl;
	for (auto i : vi) {
		
		cout << i << " ";
	}
	cout << endl;
	cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
	//test1();

	//jj01::test_array();
	/*long value;
	cout << "how many elements: ";
	cin >> value;
	jj02::test_vector(value);*/
	//glf00::test_array();
	/*cout << sizeof(list<int>) << endl;
	test_containers();*/
	//glf08::test_iterator();
	//glf09::test_accumulate();
	//glf10::test_for_each();
	//glf11::test_count();
	//glf12::test_find_if();
	//glf13::test_sort();
	glf14::test_bind();
	system("pause");
	
	return 0;
}


