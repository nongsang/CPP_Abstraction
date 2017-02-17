#include <iostream>

using namespace std;

class CTest
{
	int* m_npData{ nullptr };
public:
	CTest(int nParam)
	{
		cout << "생성자" << endl;
		m_npData = new int;
		*m_npData = nParam;
	}

	~CTest()
	{
		cout << "소멸자" << endl;
		delete m_npData;
		m_npData = nullptr;			// 이부분 중요함
	}

	CTest(const CTest& rhs)
	{
		cout << "복사생성자" << endl;
		m_npData = new int;			// 멤버변수를 힙에 생성
		*m_npData = *rhs.m_npData;	// 힙에 생성된 멤버변수에 값을 참조하여 저장
	}

	int GetData() const { return *m_npData; }
};

int main()
{
	CTest a(10);
	CTest b(a);

	cout << a.GetData() << endl;
	cout << b.GetData() << endl;
}

// 23번째 줄
// 복사생성자를 정의해주었다.

// 26, 27번째 줄
// 복사생성한 클래스의 멤버변수를 동적할당하였다.
// 그리고 복사본의 멤버변수에 원본 클래스의 멤버변수를 참조하여 복사저장한다.

// 깊은 복사를 하게되면 복사 생성된 클래스도 힙에 생성이된다.
// 그러므로 소멸자의 메모리 해제도 할 수 있게 된다.

// 20번째 줄
// m_npData는 메모리 동적 할당에 사용되었다.
// 하지만 메모리가 해제된 시점에서도 동적할당 되었던 힙 영역을 가리키고 있게된다.
// 이 현상을 댕글링 포인터(dangling pointer)라고 한다.
// 그러므로 후에 일어날 일을 미연에 방지하기 위해서 nullptr로 아무것도 가리키지 않게 만들어야 한다.