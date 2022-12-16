#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------------\n"

static unsigned int count;
class Tree
{
	class Element
	{
		int Data;				//Значение элемента
		Element* pLeft, * pRight;//Адреса потомков

	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			count++;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			count--;
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;

public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

	void print(struct Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);


	}

	int minValue(struct Element* root)
	{
		struct Element* current = root;
		while (current->pLeft != NULL) 
		{
			current = current->pLeft;
		}
		return (current->Data);
	}
	int maxValue(struct Element* root)
	{
		struct Element* current = root;
		while (current->pRight != NULL)
		{
			current = current->pRight;
		}
		return (current->Data);
	}
	int Sum(struct Element* root)
	{
		if (root == nullptr) return 0;
		return(root->Data + Sum(root->pLeft) + Sum(root->pRight));
	}
	double Avg(struct Element* root)
	{
		if (root == nullptr) return 0;
		return (Sum(root)*1.0 / count);
	}
	int Depth(struct Element* root)
	{
		if (root == nullptr) return 0;
		int  LeftDepth = Depth(root->pLeft);
		int  RightDepth = Depth(root->pRight);

		if (LeftDepth > RightDepth) return LeftDepth + 1;
		else return RightDepth + 1;
	}

};


void main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << "\nОбщее количество элементов списка:" << count << endl;
	cout << endl;
	int min = tree.minValue(tree.getRoot());
	cout << "Минимальное значение: " << min << endl;
	int max = tree.maxValue(tree.getRoot());
	cout << "Максимальное значение: " << max << endl;
	int sum = tree.Sum(tree.getRoot());
	cout << "Сумма значение дерева: " << sum << endl;
	double avg = tree.Avg(tree.getRoot());
	cout << "Среднее арифметическое значение дерева: " << avg << endl;
	int depth = tree.Depth(tree.getRoot());
	cout << "Глубина дерева: " << depth << endl;

}