#include <iostream>

using namespace std;

class CTest
{
	int m_nData{ 0 };
public:
	CTest() { cout << "CTest() 생성자" << endl; }
	virtual ~CTest() { cout << "CTest 소멸자" << endl; }
	void SetData(int nParam)
	{
		cout << "setter" << endl;
		m_nData = nParam;
	}
	int GetData() const
	{
		cout << "getter" << endl;
		return m_nData;
	}
};

class CTestEx : public CTest
{
	//int m_nNewData{ 0 };
public:
	CTestEx() { cout << "CTestEx() 생성자" << endl; }
	~CTestEx() { cout << "CTestEx() 소멸자" << endl; }
	void SetData(int nParam)
	{
		if (nParam > 10)
			nParam = 10;
		
		CTest::SetData(nParam);
	}
	void PrintData()
	{
		cout << "PrintData() : " << GetData() << endl;
		//cout << "New Data : " << m_nNewData << endl;
	}
};

int main()
{
	CTest *pData = new CTestEx;		// 참조형식으로 사용
	//CTest *pData = new CTest;
	CTestEx *pNewData = nullptr;

	pData->SetData(15);		// CTest형

	pNewData = static_cast<CTestEx*>(pData);		// 형변환 및 힙에 있는 데이터의 주소값 저장
	pNewData->PrintData();			// 값의 검사를 하지 않는다.
	delete pData;
	pData = nullptr;
}

// 45번 줄
// 가상함수는 소멸자밖에 없으므로 참조형식으로 사용한다.

// 49번 줄
// pData는 CTest형 포인터 이므로 값의 범위를 검사하지 않는다.

// 51번 줄
// CTest형 포인터인 pData를 CTestEx형 포인터로 형변환해주고 있다.
// pData의 값들을 CTestEx*형으로 변환하여 pNewData가 pData의 힙 위치를 가리키고 있는 것.
// pNewData는 CTestEx*형이므로 주소값을 받아야 한다.
// pData는 주소값이므로 자료형만 CTestEx*로 형변환하여 힙에 저장된 데이터를 가리키가 하는 것은 불가능하지 않다.
//
// 여기서 중요한 것은 CTestEx가 CTest를 '포함'하면서 더 많은 기능을 제공한다.
// CTest ⊂ CTestEx 이므로 형변환이 가능한 것이다.
//
// 매우 중요~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 46번 줄 처럼 CTest만큼의 크기를 힙에 생성하였다면,
// 51번 줄에서 형변환을 하여 값을 복사저장하면 제대로 될리가 없다.
// 47번 줄에서 nullptr로 생성하는 것은 가리키는 포인터를 생성한다는 것이지 기능을 사용하게끔 생성한다는 것이 아니기 때문
// 그래서 51번 줄에서는 CTest로 생성한 것을 CTestEx의 기능을 사용하게끔 형변환 한다는 것이지, CTestEx를 메모리에 생성한다는 것이 아니다. 
// 그 증거는 CTestEx의 생성자가 불리지 않고 소멸자가 불리지 않는다.
// 그 외에도 25, 39번 줄에서 CTestEx만의 멤버변수의 초기 값을 정해주고 출력했음에도 제대로된 값을 출력하지 못한다.

// 52번 줄
// 단순하게 CTestEx*형인 pNewData를 이용한 메서드의 호출이다.

// 50번 줄
// pData만 동적할당하였으므로 pData만 메모리 해제

// 여기서 중요한 것은 51번 줄 static_cast다.
// C++11에서는 명시적으로 형변환을 하게끔 권장한다.
// C스타일 형변환 형변환을 C++에서는 사용하지 않는 것이 좋다.
// 왜냐하면 형변환을 해서는 안되는 것을 되는 부분이 있기 때문이다.
//
// 형변환의 규칙이 있다.
// 1. 정수, 실수, 문자 사이에 형변환이 가능 (값이 출력되고 안되고는 별개의 문제)
// 2. 해당 자료형에서 자료형의 포인터형으로 형변환 가능 ( ex : int* a = static_cast<int*>(&b); -> b는 int형 )
// 3. 해당 포인터 자료형에서 자료형으로 형변환 불가능 ( ex : int a = static_cast<int>(b); -> b는 int*형 )
// 4. static_cast로는 포인터 자료형에서 다른 포인터 자료형으로 형변환 불가능
//		( ex : char * a = static_cast<char*>(&b); -> b는 int*형 )

// 4번 규칙은 다르게 말하면 C스타일 형변환은 포인터 자료형에서 다른 포인터 자료형으로 형변환이 가능하다.
// static_cast가 완벽한 울타리는 아니지만 적어도 C스타일 형변환보다는 안전하게 사용할 수 있다.
// 앞으로 동적할당이 아닌 형변환은 static_cast를 사용하자.