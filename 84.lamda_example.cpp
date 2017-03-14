#include <iostream>
#include <random>		// C++11에서 추가된 랜덤함수들의 라이브러리
#include <algorithm>	// STL인 알고리즘 제공 라이브러리

using namespace std;

int main()
{
	default_random_engine dre;		// 난수 생성 기본 엔진
	uniform_int_distribution<> uid;	// 모든 정수에서 균등한 확률을 가진 난수 생성기

	int a[100000];

	for (auto& d : a)		// 100만개를 담는 배열 요소 하나하나에
		d = uid(dre);		// 랜덤값을 저장

	//qsort(a, 100000, sizeof(int), (비교 기준이 되는 함수));

	sort(begin(a), end(a), [](int a, int b)->bool {
		return a < b;
	});

	for (auto& d : a)
		cout << d << endl;
}

// 9번 줄
// C++11에서 제공하는 random 라이브러리 중 난수 생성 기본 엔진이다.
// STL에서 자세히 다룬다.

// 10번 줄
// C++11에서 제공하는 random 라이브러리에 포함된 기능이다.
// 모든 정수에서 균등한 확률로 정수를 뽑는 난수 생성기이다.
// 범위를 정해주면 정해진 범위 내에서 균등한 확률로 정수를 뽑아낸다.
// STL에서 자세히 다룬다.

// 14, 15번 줄
// 범위기반 루프를 이용하여 랜덤값을 배열에 저장한다.
// 난수 생성기를 이용하여 균등한 확률로 정수를 뽑아 저장하는 것.
// 이것도 STL에서 자세히 다룬다.

// 17번 줄
// C언어에서 제공하는 제너릭 함수인 qsort를 사용하는 방법이다.
// 배열, 개수, 크기, 비교기준 제공 함수를 사용하면 사용할 수 있다.
// 하지만 여기서는 람다를 사용할 수 없다.
// 한마디로 인자로 함수를 넘겨줄 수 없다는 것.
// 제너릭 함수에 대한 이야기는 STL에서 자세하게 다룬다.

// 19 ~ 21번 줄
// sort는 STL인 algorithm 라이브러리에 있다.
// 배열의 시작(begin)에서 배열의 끝(end)까지 정의해준 람다식을 기준으로 정렬하는 함수다.
// 람다식에서는 두 값을 받아서 bool로 값을 비교하는 내용을 정의해주고 있다.
// 람다식을 C언어의 qsort()처럼 값을 비교하는 함수를 정의하여 인자로 넘겨줘도 된다.
// 이것에 대한 내용도 STL에서 자세히 다룬다.

// 람다식을 제너릭 함수에서 사용할 수 있음을 보여주는 예제다.