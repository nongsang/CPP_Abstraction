#include <iostream>

using namespace std;

class CTest
{
public:
	CTest() = default;
	CTest() = delete;
};
int main()
{
	CTest C;
}

// 8번째 줄
// 디폴트 생성자를 default로 간단하게 정의할 수 있다.
// 일반적인 상황에서는 디버그를 위해서 정의해주는게 좋다.
// 이 정의는 템플릿에서 사용하므로 알아두기만 하자.

// 9번째 줄
// 불필요한 멤버함수를 제거하는 키워드로 delete를 사용한다.
// 개발자가 멤버함수를 사용하다가 사용하지 않는 경우 간단하게 사용하지 않음을 알릴 수 있다.

// 13번째 줄
// 9번째 줄에서 생성자를 사용하지 않음을 명시하였으므로 오류를 뿜는다.