#include <iostream>

using namespace std;

int CompareData(const void *pLeft, const void *pRight)
{
	return *(int*)pLeft - *(int*)pRight;
}

int main()
{	
	int aList[5]{ 30, 50, 10, 20, 40 };

	qsort(aList, 5, sizeof(int), CompareData);		// 여기서 callback 발생
	for (auto &n : aList)
		cout << n << " ";

	cout << endl;
}

// 5 ~ 8번 줄
// 두 값을 빼고 그 값을 반환하는 함수를 구현했다.

// 14번 줄
// qsort를 사용하여 배열을 정렬한다.
// 인자는 배열이름, 갯수, 요소의 크기, 비교 기준이 되는 함수가 된다.
// 여기서 함수의 이름이 제일 중요하다.
// qsort() 함수 내부에서 두 요소를 비교할 때마다 이 주소를 호출한다.
// 이벤트가 생길때 마다 호출하는 것을 callback(역호출)이라고 한다.
// 함수에서는 두 값을 빼서 0이면 같은 값, 양수면 오른쪽이 크고, 음수면 왼쪽이 더 큰 것이다.
//
// 만약 이 함수를 람다로 표현한다면 어떨까?

// 굳이 이렇게 함수를 만들어서 해야하나?
// 정렬의 대상이 문자열이라면 비교하기 힘들다.
// 그러므로 정렬하려는 대상에 따라 비교 방법을 사용자가 정의해줘야 한다.