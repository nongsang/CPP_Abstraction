#include <iostream>

using namespace std;

class CImage
{
protected:
	int m_nHeight{ 0 };
	int m_nWidth{ 0 };
public:
	CImage(int nHeight, int nWidth)
		: m_nHeight(nHeight), m_nWidth(nWidth)
	{
		cout << "CImage 생성자" << endl;
	}
	~CImage() { cout << "CImage 소멸자" << endl; }


	int GetHeight() const { return m_nHeight; }
	int GetWidth() const { return m_nWidth; }
	int GetSize() const { return 0; }			// 부모클래스인 CShape에도 있는 함수다.
};

class CShape
{
protected:
	int m_nType{ 0 };
public:
	CShape(int nType) : m_nType(nType)
	{
		cout << "CShape 생성자" << endl;
	}
	~CShape() { cout << "CShape 소멸자" << endl; }

	int GetType() const { return m_nType; }
	int GetSize() const { return 0; }			// 부모클래스인 CImage에도 있는 함수다.
};

class CPicture : public CImage, public CShape		// 다중상속
{
public:
	CPicture() : CImage(200, 120), CShape(1)
	{
		cout << "CPicture 생성자" << endl;
	}
	~CPicture() { cout << "CPicture 소멸자" << endl; }
};

int main()
{
	CPicture a;
	cout << "Height : " << a.GetHeight() << endl;
	cout << "Width : " << a.GetWidth() << endl;
	cout << "Type : " << a.GetType() << endl;

	//a.GetSize();			// 모호성 발생
	a.CImage::GetSize();	// 명시적으로 호출해야한다.
	a.CShape::GetSize();	// 이것도 마찬가지
}

// 39번 줄
// 두 부모클래스 CImage와 CShape를 다중상속하였다.
// CImage와 CShape 두가지 성질을 모두 가지는 셈이다.
// 하지만 여기서 문제가 발생한다.

// 21, 36번 줄
// 부모클래스들이 서로 같은 메서드를 갖고있다.

// 56번 줄
// 두 부모클래스들이 서로 같은 메서드를 갖고 있으므로 모호성이 발생한다.

// 57, 58번 줄
// 56번 줄에서 모호성이 발생하므로 명시적으로 호출해야한다.
// 여기서 중요한 것은 같은 구문이 두 가지 이상의 의미로 해석될 여지가 있어서는 안 된다는 것이다.
// 이를 죽음의 다이아몬드(the Deadly Diamond of Death. DDD)라고 부른다.

// 여기서부터 슬슬 다중상속이 힘들어진다.
// 다중상속은 웬만하면 쓰지 않는게 정신건강에 좋지만 한번 끝까지 가보자.
// 53.virtual_inheritance에서 추가로 설명