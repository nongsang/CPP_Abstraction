#include <iostream>

using namespace std;

class Data
{
	int m_nNum{ 10 };		// 유니폼 초기화
public:
	Data() {}
	void PrintData()
	{
		cout << "m_nNum : " << m_nNum << endl;
	}
};

int main()
{
	int i{ 3 };				// 유니폼 초기화
	cout << "i : " << i << endl;

	Data d;
	d.PrintData();
}

// 7 , 18번째 줄
// 유니폼 초기화를 하는 방법
// C++11에서는 변수, 객체 초기화를 하는 방법으로 유니폼 초기화를 지원하고 있다.
// 변수초기화는 '=' 만으로 가능하지만 객체는 그렇지 않다.
// 특히 객체를 배열 형태로 받을 수 있는 vector를 사용하려면 유니폼 초기화가 매우 유용하다.
// vector는 STL에서 나오므로 나중에 설명
// 앞으로 변수, 객체를 초기화할 때 유니폼 초기화가 유용하니 자주 사용하도록