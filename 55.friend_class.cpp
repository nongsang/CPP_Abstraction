#include <iostream>

using namespace std;

class CNode
{
private:
	char m_szName[32];			// ����� ������
	CNode *pNext = nullptr;		// ���� ��带 ����Ű�� ������ ����
private:
	friend class CList;		// CList�� friend�� ����
public:
	explicit CNode(const char *pszName)
	{
		strcpy_s(m_szName, sizeof(m_szName), pszName);	// m_szName�� �� ũ�⸸ŭ pszName�� �����Ѵ�.
	}
};

class CList
{
	CNode m_HeadNode;		// ���ÿ� ����带 ����
public:
	CList() : m_HeadNode("Dummy Head") { }		// ������ ȣ���ϸ� ���ÿ� ���� ��带 �����Ѵ�.
	~CList()
	{
		CNode *pNode = m_HeadNode.pNext;		// ��带 ����Ű�� �뵵�� pNode ����
		CNode *pDelete = nullptr;				// ������ ��带 �˸��� �뵵�� pDelete ����

		while (pNode)		// pNode�� ���� �����Ѵٸ�
		{
			pDelete = pNode;	// ��带 ����ϸ� ������ ������ �˸������� pDelete�� pNode�� ����Ű�� �Ѵ�. 
			pNode = pNode->pNext;		// ���� ��带 ã�� ���� �غ�

			cout << pDelete->m_szName << endl;		// ���⼭ �߿�.
			delete pDelete;				// ������ ��带 ����
		}

		m_HeadNode.pNext = nullptr;		// ���������� ���� ����尡 �ƹ��͵� ����Ű�� �ʰ� ����
	}

	void AddNewNode(const char *pszName)
	{
		CNode *pNode = new CNode(pszName);

		pNode->pNext = m_HeadNode.pNext;	// ���ο� ��尡 ����Ű�� ���� ����尡 ����Ű�� ���̴�.
		m_HeadNode.pNext = pNode;		// ���ÿ� �ִ� ����尡 ����Ű�� ���� ���Ӱ� ������ ����.
	}
};

int main()
{
	CList list;			// ȣ��� ���ÿ� ���ÿ� HeadNode�� ����
	list.AddNewNode("�浿");
	list.AddNewNode("ö��");
	list.AddNewNode("����");

	return 0;
}

// 55�� ��
// ���ÿ� HeadNode�� �����Ѵ�.
// ���⼭ HeadNode�� ���̶�� ���� �˷��ָ�, ����Ʈ�� ���� ��ġ�� �˷��ٻ� �� �ǹ̴� ����.
// �׸��� HeadNode�� �����ʹ� nullptr�̴�.

// 54 ~ 56�� ��
// ������ �ϳ��� �����ϴ� �۾��� �ϰ��ִ�.

// 41 ~ 47�� ��
// ���Ӱ� ��带 �����س��� ��������� �����̴�.
// ���� ���� ����־ ������ �˾ƺ���.
//
// 1. �浿�� ������ �浿�̶�� �����͸� ���� ��带 ���� �����Ҵ��Ѵ�.
// 2. �����Ҵ�� �浿����� �����ʹ� HeadNode�� ������, ��, nullptr�� �����Ѵ�.
// 3. HeadNode�� �����ʹ� ���� ������ ���, ��, �浿��带 ����Ų��.
// 4. ö���� ������ ö����� �����͸� ���� ��带 ���� �����Ҵ��Ѵ�.
// 5. �����Ҵ�� ö������� �����ʹ� HeadNode�� ������, �� �浿�� ����Ű�� �����Ѵ�.
// 6. HeadNode�� �����ʹ� ���� ������ ���, ��, ö����带 ����Ų��.
// 7. ���� ����.

// 24 ~ 39�� ��
// ��� �����͸� ����ϸ鼭 ��带 �����ϴ� �Ҹ����� �����̴�.
//
// 1. ����Ű�� �뵵�� pNode�� pDelete�� �����Ѵ�.
// 2. pNode�� HeadNode�� ���� ��� ��, �����带 ����Ű�� �Ѵ�.
// 3. pNode�� �������̸�, ���� �����ϹǷ� ������ ���� �˸��� ������ pDelete�� pNode, ��, �����带 ����Ű�� �Ѵ�.
// 4. pNode�� pNode�� ���� ���, ��, ö����带 ����Ű�� �Ѵ�.
// 5. pDelete�� ��, �������� ������ ���� ����ϰ� pDelete�� �����ϹǷ� �����带 ���ش�. -> �ſ� �߿�
// 6. pNode�� ö������̸�, ���� �����ϹǷ� ������ ���� �˸��� ������ pDelete�� pNode, ��, ö����带 ����Ű�� �Ѵ�.
// 7. pNode�� pNode�� ���� ���, ��, �浿��带 ����Ű�� �Ѵ�.
// 8. pDelete�� ��, ö������� ������ ���� ����ϰ� pDelete�� �����ϹǷ� ö����带 ���ش�.
// 9. �浿�� ����.

// 11�� ��
// 34�� �ٰ� ���� �ſ� �߿��� �����̴�.
// CNode�ȿ� CList Ŭ������ friend�� ������ ��.
// �Ѹ���� CList���� CNode�� ������� ������ �� �ְ� ���ش�.
// �ſ� ������ �߻�ƴѰ�?

// 34�� ��
// pDelete�� CNode Ŭ������ ������.
// �ű�� m_szName ��������� private�� ������ �Ǿ� �ִ�.
// CList Ŭ�������� CNode�� private�� ������ ��.
// ��������� private�� ����� ��������� �ٸ� Ŭ������ �����ϴ� ���� ���� �ȵȴ�.
// ������ CNode���� CList�� friend�� �����Ͽ����Ƿ� CNode�� ����� ������ �� �ִ� ���̴�.