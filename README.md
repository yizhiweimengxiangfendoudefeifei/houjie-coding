# houjie-coding
这是侯捷老师C++课程的代码，所有的程序都是在vs2019上测试通过的，欢迎大家下载查看。
# string
1.包含指针的类，里边包含了侯捷老师提到的big three（拷贝构造、拷贝赋值、析构函数）  
2.构造函数要注意传进来的字符串为空，则申请一个字符来储存结束符0。  
3.拷贝构造new在堆区用指针接收这个新地址，防止浅拷贝。  
4.拷贝赋值中如果传进来的是本身，则return。  
5.析构要注意new array，delete array。  
# complex  
1.operator+=、-=、*=的使用，调用成员函数进行重载的计算  
2.如果函数不会被实现，那就没有必要写参数名称  
3.非成员函数重载+、-、*、/  
4.重载右移运算符的写法见complex.cpp
# STL  
1.增加了容器的测试，包括array,vector,deque(双向开口),list,multiset,multimap,set,map  
2.增加了迭代器的测试，测试迭代器的类型，其中包含函数重载、模板等知识点  
3.增加了算法的测试，包含accumulate(累加)，for_each(对每一个元素做你所指定的事情),count,find_if,sort  
4.增加了适配器bind
