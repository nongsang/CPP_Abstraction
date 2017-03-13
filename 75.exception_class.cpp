#include <iostream>

using namespace std;

class CException
{
	int m_nErrorCode;
	char m_szMsg[128];
public:
	CException(int nCode, const char *pszMsg) : m_nErrorCode(nCode)
	{
		strcpy_s(m_szMsg, sizeof(m_szMsg), pszMsg);
	}

	int GetErrorCode() const { return m_nErrorCode; }
	const char* GetMessage() { return m_szMsg; }
};

int main()
{
	try
	{
		int nInput = 0;
		cout << "양의 정수 : ";
		cin >> nInput;

		if (nInput < 0)
		{
			CException exp(10, "양의 정수를 입력해야 합니다.");	// 여기서 객체 생성
			throw exp;
		}
	}

	catch (CException &exp)		// 클래스 인스턴스를 받는다. 참조형으로
	{
		cout << "ERROR CODE [" << exp.GetErrorCode() << "]" << exp.GetMessage() << endl;
	}
}

// 29번 줄
// 입력값을 판단하여 오류코드를 보여주는 객체를 생성한다.
// 그리고 객체를 catch로 객체를 던져준다.

// 34번 줄
// 객체를 받아서 예외처리를 한다.
// 여기서 중요한 것은 참조형으로 받는다는 것이다.
// 객체는 크기가 크기때문에 참조형으로 이름만 사용하여 호출하는 것이 훨씬 좋다.

// 이처럼 예외처리 클래스를 만들어 사용하면 프로그램 내부에 만들어야 하는 모든 예외 정보를 한 클래스에서 만들어낼 수 있다.
// 각종 오류를 포함한 예외 상황들을 정책적으로 관리하기 용이하며 디버깅하기도 훨씬 수월하다.
// 공동 프로젝트를 진행 중이라면 더욱 그렇다.