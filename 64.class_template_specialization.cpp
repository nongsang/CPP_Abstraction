#include <iostream>
using namespace std;

template<typename T>
class CTest
{
	T m_Data;
public:
	CTest(T param) : m_Data(param) { }

	T GetData() const { return m_Data; }
	void SetData(T param) { m_Data = param; }
};

template<>		// 여기서부터 템플릿 특수화를 사용해준다는 의미
class CTest<char*>		// 형태를 잘 보렴	. 명시적으로 특수화를 사용하겠다는 뜻
{
	char *m_pData;
public:
	CTest(char *pszParam)
	{
		int nLen = strlen(pszParam);
		m_pData = new char[nLen + 1];
		strcpy_s(m_pData, nLen + 1, pszParam);
	}
	~CTest() { delete[] m_pData; }

	char* GetData() const { return m_pData; }
};

int main()
{
	CTest<char*> a("Hello");		// 클래스 템플릿 특수화 사용
	cout << a.GetData() << endl;
}

// 4 ~ 13번 줄
// 일반적인 템플릿 클래스를 정의해주었다.

// 15번 줄
// 이제부터 템플릿 특수화를 사용하겠다는 의미

// 16번 줄
// 클래스 템플릿 특수화를 사용하는 방법이다.
// 클래스 이름 옆에 특수하게 사용할 자료형을 붙여준다.

// 33번 줄
// 클래스 템플릿 특수화로 정의한 클래스가 호출된다.

// 65.template_specialization_summary에서 정리해보자.