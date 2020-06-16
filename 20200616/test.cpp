#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>

using namespace std;
//
//template <class T>
//void printlist(const list<T>& lst) {
//	for (auto& e : lst)
//		cout << e << " ";
//	cout << endl;
//}
//
//void test() {
//	list<int> lst;
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);
//	lst.push_back(4);
//	list<int> lst2;
//	lst2.push_back(5);
//	lst2.push_back(6);
//	lst2.push_back(7);
//	//splice:拼接作用,被拼接的元素直接存入第一个list,第二个list不保留被拼接的元素
//	lst.splice(lst.begin(), lst2);  //5671234
//	printlist(lst);
//	lst2.splice(lst2.begin(), lst, ++lst.begin(), --lst.end());
//	printlist(lst2); //67123
//	printlist(lst); //54
//	lst2.splice(lst2.end(), lst, --lst.end());
//	printlist(lst2); //671234
//
//	//unique:删除重复出现的元素,前提是元素有效,无效时不做任何操作
//	int arr[7] = { 1,1,3,3,4,5,5 };
//	list<int> lst3(arr, arr + 7);
//	lst3.unique();
//	printlist(lst3);
//
//	//sort:排序,如果给自定义类型成员排序,自定义类型需要支持比较运算
//
//	//merge:归并两个有序list
//
//	//reverse:逆置list
//	list<int> copy(lst3);
//	copy.reverse();
//	printlist(copy);
//}
//
//int main() {
//	test();
//	return 0;
//}
//
//template <class T>
//class Vector {
//	//析构函数
//	~Vector() {
//		if (_start) {
//			delete[]_start;
//			_start = _finish = _eos = nullptr;
//		}
//	}
//
//	Vector(const Vector& v)
//		:_start(new T[v.capacity()]);
//	{
//		//深拷贝
//		for (auto& e : v) {
//			_start[i] = v[i];
//		}
//		_finish = _start + v.size();
//		_eos = _start + v.capacity();
//	}
//
//	Vector<T>& operator=(const Vector v) {
//		Swap(v);
//		return *this;
//	}
//	void Swap(const Vector<T>& v) {
//		swap(_start, v._start);
//		swap(_finish, v. _finish);
//		swap(_eos, v._eos);
//	}
//private:
//	T* _start;
//	T* _finish;
//	T* _eos;
//};


template<class T,class Container = deque<T>>
class Queue {
public:
	void pop() {
		_c.pop_front();
	}

	void push(const T& val) {
		_c.push_back(val);
	}

	const T& front() {
		return _c.front();
	}
	const T& back() {
		return _c.back();
	}

	size_t size()const {
		return _c.size();
	}

	bool empty() {
		return _c.empty();
	}

private:
	Container _c;
};

void test() {
	Queue<int,deque<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
template<class T>
struct Greater {
	bool operator()(const T& val1, const T& val2) {
		return val1 > val2;
	}
};
template<class T>
struct Less {
	bool operator()(const T& val1, const T& val2) {
		return val1 < val2;
	}
};
template<class T,class Container = vector<T>,class compare = Greater<T>>
class Priority_queue {
public:
	void push(const T& val) {
		_c.push_back(val);
		ShiftUp(_c.size() - 1);
	}
	void pop() {
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		ShiftDown(0);
	}
	T& top() {
		return _c.front();
	}
	size_t size()const {
		return _c.size();
	}
	bool empty() {
		return _c.empty();
	}
private:
	void ShiftDown(int parent) {
		int child = 2 * parent + 1;
		while (child < _c.size()) {
			if (child + 1 < _c.size() && _c[child] < _c[child + 1])
				child++;
			if (_c[child] > _c[parent]) {
				swap(_c[child], _c[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
	void ShiftUp(int child) {
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (_c[child] > _c[parent]) {
				swap(_c[child], _c[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	Container _c;
	compare _cmp;
};

void test2() {
	Priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4); 

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
int main() {

	test2();
	return 0;
}