#include <iostream>

using namespace std;

class CTest
{
private:
	int m_nData;		// private로 선언된 멤버변수다.
public:
	CTest(int nParam) : m_nData(nParam) {}
	int GetData() const { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	friend void PrintData(const CTest &rData);		// 외부에서 접근하는 함수를 friend로 선언, 함수의 원형을 써도 좋다.
};

void PrintData(const CTest& rData)
{
	cout << "PrintData() : " << rData.m_nData << endl;		// 여기 중요
}

int main()
{
	CTest a(5);
	PrintData(a);
}

// 14번 줄
// 외부에서 접근하는 함수를 friend로 선언하였다.
// 함수의 원형을 써도 좋다.
// friend void PrintData(const CTest&)만 써도 된다는 뜻이다.

// 19번 줄
// 외부 함수에서 private선언된 멤버변수에 접근하여 출력하고 있다.
// GetData()가 아니라 바로 접근이 가능한 것이 friend의 힘이다.

// 쌔빠지게 객체지향 공부했는데 다 열어주는 friend를 배우네?
// 두 클래스가 완전히 무관하게 설계하거나, 떨어져있더라도 서로 긴밀한 관계라면 friend를 써줄 수 있다.

// friend가 존재하는 이유는 응집도(Cohesion) 때문이다.
// 응집도는 한 모듈 내에 있는 구성 요소의 기능적 관련성을 평가하는 것이다.
// 클래스 혹은 모듈 단위로 필요한 기능이 잘 뭉쳐져 있으면 높은 응집도를 가졌다.
// 응집도가 높으면 프로그램을 쉽게 이해할 수 있으므로 유지보수성이 높아진다.
// 응집도가 낮다는 뜻은, 클래스나 모듈 내에 있는 기능의 관련성이 낮다는 뜻이다.
// 예를 들면 dog라는 클래스에 GrabTheSpoon이라는 멤버함수가 있는 것처럼 하면 연관성이 떨어지므로 응집도가 낮은 것이다.
//
// 응집도가 낮은 클래스의 문제점
// 1. 이해하기 힘들고
// 2. 따로 재사용하기 힘들며
// 3. 유지보수하기 힘들고
// 4. 다른 클래스의 변화에 민감하다.
//
// 이와 같이 소프트웨어를 평가하는 방법중 또 한가지는 결합도(Coupling)이다.
// 결합도는 클래스 혹은 모듈간의 상호 의존도를 측정하는 것이다.
// 클래스 혹은 모둘간에 의존도가 낮으면 낮은 결합도를 가진다.
// 결합도가 낮으면 클래스 혹은 모듈간의 독립성이 높아지므로 유지보수성이 높아진다.
// 결합도가 높다는 뜻은, 클래스나 모듈 간에 서로 간섭하는 빈도가 많다는 뜻이다.
// 예를 들면 dog라는 클래스가 bark라는 기능을 사용하기 위해서 cat의 bark를 호출하면 결합도가 높은 것이다.
//
// 결합도가 높은 클래스의 문제점
// 1. 연관된 다른 클래스가 변경되면 더불어 변경해야 하고,
// 2. 수정하려는 클래스를 이해하기 위해 연관된 다른 클래스를 함께 이해해야 하고
// 3. 나중에 다른 프로그램에서 클래스를 재사용하기도 힘들다.

// 소프트웨어를 잘 만들기 위해서는
// 1. 높은 응집도(High Cohesion)
// 2. 낮은 결합도(Low Coupling)
// 이 두가지를 잘 지키야한다.