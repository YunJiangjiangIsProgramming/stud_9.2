#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <vector>
#include <list>
#include <map>
#include <array>
#include<assert.h>
#include<unordered_map>
#include<string>
using namespace std;


class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void testdate()
{

		vector<int> v1 = { 1, 2, 3, 4 };
		vector<int> v2{ 1, 2, 3, 4,6,7,7};
	
		list<int> lt = { 1, 2 };
	
		Date d1{ 1, 1, 1 }; //���캯��
		//Date d2{1, 1, 1, 1};
	
		auto il = { 1, 2, 3, 4, 5 };
		cout << typeid(il).name() << endl;
	
		vector<Date> v3 = { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 } };
		map<string, string> dict = { { "�ַ���", "string" }, { "����", "sort" } };
	
}


template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	decltype(t1 * t2) ret = t1 * t2;
	cout << typeid(ret).name() << endl;
	cout << ret << endl;
}



void test2()
{

		//// ��ֵ����ֻ��������ֵ������������ֵ��
	int a = 10;
	int& ra1 = a;   // raΪa�ı���
	//int& ra2 = 10;   // ����ʧ�ܣ���Ϊ10����ֵ

	//// const��ֵ���üȿ�������ֵ��Ҳ��������ֵ��
	const int& ra3 = 10;
	const int& ra4 = a;

	// ��ֵ����ֻ����ֵ������������ֵ��
	int&& r1 = 10;

	// error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
	// message : �޷�����ֵ�󶨵���ֵ����
	//int a = 10;
	//int&& r2 = a;

	// ��ֵ���ÿ�������move�Ժ����ֵ
	int&& r3 = std::move(a);
}



template<class T>
void func1(const T& x)
{

}

template<class T>
const T& func2(const T& x)
{
	// ...

	return x;
}


template<class T>
T func3(const T& x)
{
	T ret;

	return ret;
}





void generate(int numRows, vector<vector<int>>& vv) {
	vv.resize(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		vv[i].resize(i + 1, 1);
	}

	for (int i = 2; i < numRows; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
}

void testfun()
{
	vector<int> v1(10, 0);
	func1(v1);
	func1(vector<int>(10, 0));
	func2(v1);
	func3(v1);
}



namespace luow
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// �ƶ�����
		string(string&& s)
		{
			cout << "string(const string& s) -- �ƶ�����" << endl;

			swap(s);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string s) -- �ƶ���ֵ" << endl;
			swap(s);

			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // �������������ʶ��\0
	};

	string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		luow::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

//https://leetcode.cn/problems/roman-to-integer/description/

class Solution0{
public:
	int romanToInt(string s) {
		unordered_map<string, int> m = { {"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000} };
		int r = m[s.substr(0, 1)];
		for (int i = 1; i < s.size(); ++i) {
			string two = s.substr(i - 1, 2);
			string one = s.substr(i, 1);
			r += m[two] ? m[two] : m[one];
		}
		return r;
	}
};
int main()
{
	list<luow::string> lt;
	luow::string s1("111111");
	lt.push_back(move(s1));

	lt.push_back(luow::string("222222"));

	lt.push_back("333333");

	return 0;
}