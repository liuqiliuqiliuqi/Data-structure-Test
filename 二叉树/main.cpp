#include<iostream>
using namespace std;

//typedef int ElemType;
//typedef struct BtNode // binarytreenode
//{
//	BtNode *leftchild;
//	BtNode *rightchild;
//	ElemType data;
//}BtNode, *BinaryTree;
//
//void PreOrder(BtNode *p)//前序遍历
//{
//	if (p != NULL)
//	{
//		cout << p->data << " ";
//		PreOrder(p->leftchild);
//		PreOrder(p->rightchild);
//	}
//}
//
//void InOrder(BtNode *p)//中序遍历
//{
//	if (p != NULL)
//	{
//		InOrder(p->leftchild);
//		cout << p->data << " ";
//		InOrder(p->rightchild);
//	}
//}
//
//void PastOrder(BtNode *p)//后序遍历
//{
//	if (p != NULL)
//	{
//		PastOrder(p->leftchild);
//		PastOrder(p->rightchild);
//		cout << p->data << " ";
//	}
//}
//
//BtNode *Buynode()//购买结点
//{
//	BtNode *s = (BtNode*)malloc(sizeof(BtNode));
//	if (NULL == s) exit(1);
//	memset(s, 0, sizeof(BtNode));
//	return s;
//}
//
//void Freenode(BtNode *p)//释放结点
//{
//	free(p);
//}
//
//BtNode * CreateTree_1()//利用#构造二叉树
//{
//	BtNode *s = NULL;
//	ElemType item;
//	cin >> item;
//	
//	if (item != '#')
//	{
//		s = Buynode();
//		s->data = item;
//		s->leftchild=CreateTree_1();
//		s->rightchild=CreateTree_1();
//	}
//	return s;
//}
//
//BtNode * CreateTree_2(ElemType *&str)
//{
//	BtNode *s = NULL;
//	if (*str != '#')
//	{
//		s = Buynode();
//		s->data = *str;
//		s->leftchild = CreateTree_2(++str);
//		s->rightchild = CreateTree_2(++str);
//	}
//	return s;
//}
//
//void CreateTree_3(BtNode *&ptr, ElemType *&str)//这里注意对指针的引用
//{
//	if (NULL == str || *str == '#')
//	{
//		ptr = NULL;
//	}
//	else
//	{
//		ptr = Buynode();
//		ptr->data = *str;
//		CreateTree_3(ptr->leftchild, ++str);
//		CreateTree_3(ptr->rightchild, ++str);
//	}
//}
//
////找出根节点在中序列遍历中的位置。
//
//int Findpos(ElemType x, ElemType *is,int n)
//{
//	int pos = -1;
//	for (int i = 0; i<n; i++)
//	{
//		if (x == is[i])
//		{
//			pos=i;
//			break;
//		}
//	}
//	return pos;
//}
//
////前中序造二叉树
//
//BtNode *CreatePI(ElemType *ps, ElemType *is, int n)
//{
//	BtNode *s = NULL;
//	if (n > 0)
//	{
//		s = Buynode();
//		s->data = ps[0];
//		int pos = Findpos(ps[0], is, n);
//		if (pos == -1)exit(1);
//		s->leftchild = CreatePI(ps+1,is,pos);
//		s->rightchild = CreatePI(ps + 1 + pos, is + 1 + pos, n - pos - 1);
//	}
//	return s;
//}
//BtNode * CreateTreePI(ElemType *ps, ElemType *is, int n)
//{
//	if (NULL == ps || NULL == is || n < 1)
//		return NULL;
//	else
//		return CreatePI(ps, is, n);
//}
//
////后中序造二叉树
//
//BtNode *CreateIL(ElemType *is, ElemType *ls, int n)
//{
//	BtNode *s = NULL;
//	if (n>0)
//	{
//		s = Buynode();
//		s->data = ls[n-1];
//		int pos = Findpos(ls[n - 1], is,n);
//		if (pos == -1) exit(0);
//		s->leftchild = CreateIL(is, ls, pos);
//		s->rightchild = CreateIL(is + pos + 1, ls + pos, n - pos - 1);
//	}
//	return s;
//}
//BtNode *CreateTreeIL(ElemType *is, ElemType *ls, int n)
//{
//	if (is == NULL || ls == NULL || n < 1)
//	{
//		return NULL;
//	}
//	else
//	{
//		return CreateIL(is, ls, n);
//	}
//}
//
////把一个完全二叉树的物理数组按照中序遍历序列输出
//
//void ArrayTree_InOrder(int *ar, int i, int n)
//{
//	if (i<n) // p != NULL
//	{
//		ArrayTree_InOrder(ar, i * 2 + 1, n); // p->leftchild;
//		cout << ar[i] << " ";
//		ArrayTree_InOrder(ar, i * 2 + 2, n); // p->rightchild;
//	}
//}
//
////利用一个完全二叉树的物理数组构建一个完全二叉树
//
//BtNode *CreateArrayTree(int *arr, int i, int n)
//{
//	BtNode *s = NULL;
//	if (i < n)
//	{
//		s = Buynode();
//		s->leftchild = CreateArrayTree(arr, i * 2 + 1, n);
//		s->rightchild = CreateArrayTree(arr, i * 2 + 2, n);
//		s->data = arr[i];
//	}
//	return s;
//}
//
////给定一个完全二叉树将其物理数组返回；
//
//int * Tree_Array(BtNode *ptr, int * br, int i)
//{
//	if (ptr != NULL)
//	{
//		br[i] = ptr->data;
//		Tree_Array(ptr->leftchild, br, i * 2 + 1);
//		Tree_Array(ptr->rightchild, br, i * 2 + 2);
//	}
//	return br;
//}
//
////利用数组构建一个平衡二叉树（二分法）
//BtNode * BinaryCreate(int *ar, int left, int right)
//{
//	BtNode *s = NULL;
//	if (left <= right)
//	{
//		int mid = (right - left + 1) / 2 + left;
//		s = Buynode();
//		s->data = ar[mid];
//		s->leftchild = BinaryCreate(ar, left, mid - 1);
//		s->rightchild = BinaryCreate(ar, mid + 1, right);
//	}
//	return s;
//}
//BtNode * BinaryCreate(int *ar, int n)
//{
//	if (NULL == ar || n < 1) return NULL;
//	else return BinaryCreate(ar, 0, n - 1);
//}





typedef char ElemType;
#define END '#'
typedef enum{ LINK = 0, THREAD = 1 } PointerTag;
typedef struct BiThrNode // binarytreenode
{
	BiThrNode *leftchild;
	BiThrNode *rightchild;
	PointerTag Ltag, Rtag;
	ElemType data;
}BiThrNode, *BinaryThreadTree;

BiThrNode *Buynode()
{
	BiThrNode *s = (BiThrNode*)malloc(sizeof(BiThrNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(BiThrNode));
	return s;
}
void Freenode(BiThrNode *p)
{
	free(p);
}


BiThrNode * CreateTree2(ElemType *&str)
{
	BiThrNode *s = NULL;
	if (*str != END)
	{
		s = Buynode();
		s->data = *str;
		s->leftchild = CreateTree2(++str);
		s->rightchild = CreateTree2(++str);
	}
	return s;
}
void InOrder(BiThrNode *p)
{
	if (p != NULL)
	{
		InOrder(p->leftchild);
		cout << p->data << " ";
		InOrder(p->rightchild);
	}
}
void MakeThread(BiThrNode *p, BiThrNode *&ptr)
{
	if (p != NULL)
	{
		MakeThread(p->leftchild, ptr);
		if (p->leftchild == NULL)
		{
			p->leftchild = ptr;
			p->Ltag = THREAD;
		}
		if (ptr != NULL && ptr->rightchild == NULL)
		{
			ptr->rightchild = p;
			ptr->Rtag = THREAD;
		}
		ptr = p;
		MakeThread(p->rightchild, ptr);

	}
}
void MakeThreadTree(BiThrNode *p)
{
	BiThrNode *ptr = NULL;
	MakeThread(p, ptr);
	ptr->rightchild = NULL;
	ptr->Rtag = THREAD;
}

BiThrNode * First(BiThrNode *ptr)
{
	while (ptr != NULL && ptr->Ltag != THREAD)
	{
		ptr = ptr->leftchild;
	}
	return ptr;
}
BiThrNode * Next(BiThrNode *ptr)
{
	if (NULL == ptr) return NULL;
	if (ptr->Rtag == THREAD)
	{
		return ptr->rightchild;
	}
	else
	{
		return First(ptr->rightchild);
	}
}
BiThrNode *Last(BiThrNode *ptr)
{
	while (ptr != NULL && ptr->Rtag != THREAD)
	{
		ptr = ptr->rightchild;
	}
	return ptr;
}
BiThrNode *Prev(BiThrNode *ptr)
{
	if (NULL == ptr) return NULL;
	if (ptr->Ltag == THREAD)
	{
		return ptr->leftchild;
	}
	else
	{
		return Last(ptr->leftchild);
	}
}
void InOrderThread(BiThrNode *ptr)
{
	for (BiThrNode *p = First(ptr); p != NULL; p = Next(p))
	{
		cout << p->data << " ";
	}
	cout << endl;
}
void ResInOrderThread(BiThrNode *ptr)
{
	for (BiThrNode *p = Last(ptr); p != NULL; p = Prev(p))
	{
		cout << p->data << " ";
	}
	cout << endl;
}
int main()
{
	ElemType *ar = "ABC##DE##F##G#H##";
	BinaryThreadTree root = NULL;
	root = CreateTree2(ar);

	InOrder(root);
	cout << endl;
	MakeThreadTree(root);
	InOrderThread(root);
	ResInOrderThread(root);
	return 0;
}



//int main()
//{
	/*BinaryTree root = NULL;
	int ar[] = { 31, 23, 12, 66, 94, 5, 17, 70, 62, 49, 55, 88 };
	const int n = sizeof(ar) / sizeof(ar[0]);
	root=BinaryCreate(ar, n);
	PreOrder(root);
*/

	/*int ar[] = { 31, 23, 12, 66, 94, 5, 17, 70, 62, 49, 55, 88 };
	const int n = sizeof(ar) / sizeof(ar[0]);
	ArrayTree_InOrder(ar, 0, n);
	cout << endl;*/


	/*BinaryTree root = NULL;
	int br[] = { 31, 23, 12, 66, 94, 5, 17, 70, 62, 49, 55, 88 };
	const int n = sizeof(br) / sizeof(br[0]);
	root = CreateArrayTree(br, 0, n);
	InOrder(root);
	cout << endl;
	int cr[n];
	int *dr;
	dr = Tree_Array(root, cr, 0);
	for (int i = 0; i < n; i++)
	{
		cout << dr[i] << " ";
	}*/


	//char *ps = "ABCDEFGH";
	//char *is = "CBEDFAGH";
	//char *ls = "CEFDBHGA";
	//int n=strlen(ps);
	//BinaryTree root = NULL;
	////root=CreateTreePI(ps, is, n);
	//root = CreateTreeIL(is, ls, n);
	//PreOrder(root);
	//cout << endl;
	//InOrder(root);
	//cout << endl;
	//PastOrder(root);
	//cout << endl;
	//return 0;


	/*BinaryTree root1 = NULL;
	root1 = CreateTree_1();*/
	
	/*BinaryTree root2 = NULL;
	char *str = "ABC##DE##F##G#H##";
    root2 = CreateTree_2(str);*/

	//BinaryTree root3 = NULL;
	//char *str = "ABC##DE##F##G#H##";
 //   CreateTree_3(root3,str);
	//
	//PreOrder(root3);
	//cout << endl;
	//InOrder(root3);
	//cout << endl;
	//PastOrder(root3);
	//cout << endl;
	//return 0;
//}