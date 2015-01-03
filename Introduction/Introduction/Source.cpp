#include <iostream>
using namespace std;
template<class T>
class BSTNode
{
public:
	BSTNode(){ lChild = rChild = NULL; }
	BSTNode(T &x){ element = x; lChild = rChild = NULL; }
	//private:
	int element;
	BSTNode<T> *lChild, *rChild;
};
template<typename T>
BSTNode<T>* CreateBST(BSTNode<T> *t, T &x)  //递归创建二叉查找树
{
	BSTNode<T> *b = new BSTNode<T>(x);
	if (!t)
		return b;
	else if (b->element <= t->element)
	{
		t->lChild = CreateBST(t->lChild, b->element);
	}
	else
	{
		t->rChild = CreateBST(t->rChild, b->element);
	}
	return t;
}
template<typename T>
void InOrder(BSTNode<T> *t)  //中序遍历
{
	if (t)
	{
		InOrder(t->lChild);
		cout << t->element << " ";
		InOrder(t->rChild);
	}
}
template<typename T>
BSTNode<T>* Insert(BSTNode<T> *t, BSTNode<T> *b) //插入结点b
{
	BSTNode<T> *root = t;
	BSTNode<T> *temp = NULL;
	while (t)
	{
		temp = t;
		if (b->element <= t->element)
		{
			t = t->lChild;
		}
		else
		{
			t = t->rChild;
		}
	}
	if (!temp)
		return b;
	else
	{
		if (b->element <= temp->element)
		{

			temp->lChild = b;
		}
		else
		{
			temp->rChild = b;
		}
	}
	return root;
}
template<typename T>
BSTNode<T>* Search(BSTNode<T> *t, T key) //查询值为key的结点
{
	while (t && t->element != key)
	{
		if (key <= t->element)
		{
			t = t->lChild;
		}
		else
		{
			t = t->rChild;
		}
	}
	return t;
}
template<typename T>
BSTNode<T>* Minimum(BSTNode<T> *t) //返回最小元素
{
	while (t->lChild)
	{
		t = t->lChild;
	}
	return t;
}
template<typename T>
BSTNode<T>* Maximum(BSTNode<T> *t) //返回最大元素
{
	while (t->rChild)
	{
		t = t->rChild;
	}
	return t;
}
template<typename T>
BSTNode<T>* findParent(BSTNode<T> *t, BSTNode<T> *node) //寻找node结点的父结点
{
	BSTNode<T> *parent = NULL;
	if (t == node)
	{
		return NULL;
	}
	else
	{
		while (t)
		{
			if (!t->lChild && !t->rChild)
			{
				return NULL;
			}
			else if (t->lChild == node || t->rChild == node)
			{
				parent = t;
				break;
			}
			else if (node->element <= t->element)
			{
				t = t->lChild;
			}
			else
			{
				t = t->rChild;
			}
		}
	}
	return parent;
}
template<typename T>
BSTNode<T>* Delete(BSTNode<T> *t, int key) //删除值为key的结点
{
	BSTNode<T> *z = Search(t, key);
	BSTNode<T> *x = NULL, *y = NULL;
	if (z->lChild == NULL || z->rChild == NULL)
	{
		y = z;
	}
	else
	{
		y = Minimum(z->rChild);
	}
	if (y->lChild)
	{
		x = y->lChild;
	}
	else
	{
		x = y->rChild;
	}
	if (x)
	{
		BSTNode<T> *parent = findParent(t, y);
		if (!parent)
		{
			return x;
		}
		else if (parent->lChild == y)
		{
			parent->lChild = x;
		}
		else if (parent->rChild == y)
		{
			parent->rChild = x;
		}
	}
	if (y != z)
	{
		z->element = y->element;
	}
	delete y;
	return t;
}
int main()
{
	int x;
	cout << "Input Numbers: " << endl;
	BSTNode<int> *bstree = NULL;
	while ((cin >> x))
	{
		BSTNode<int> *b = new BSTNode<int>(x);
		bstree = Insert(bstree, b);
		cout << "Input Numbers: " << endl;
	}
	InOrder(bstree);
	BSTNode<int> *r = Search(bstree, 13);
	if (r)
	{
		cout << endl << r->element << endl;
	}
	BSTNode<int> *min = Minimum(bstree);
	cout << endl << "The minimum is : " << min->element << endl;
	BSTNode<int> *max = Maximum(bstree);
	cout << endl << "The maximum is: " << max->element << endl;
	bstree = Delete(bstree, 5);

	InOrder(bstree);
	return 0;
}