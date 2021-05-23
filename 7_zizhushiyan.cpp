//#include <bits/stdc++.h>
//using namespace std;
//char str[200];
//struct tree               // 定义结构体
//{
//	double data;           // 定义一个数据域
//	char symbol;                      //  用来存放符号
//	struct tree* left = NULL;       // 定义左子树指针
//	struct tree* right = NULL;       // 定义右子树指针
//};
//typedef struct tree btnode;      // 树的结构类型
//typedef btnode* bt;
//stack<btnode*>z;
//stack<char>c;
//void zhongxu(btnode* root)
//{
//	if (root == NULL)
//		return;
//	zhongxu(root->left);
//	if (root->symbol == '!') cout << root->data << " ";
//	else cout << root->symbol << " ";
//	zhongxu(root->right);
//}
//void qianxu(btnode* root)
//{
//	if (root == NULL)
//		return;
//	if (root->symbol == '!') cout << root->data << " ";
//	else cout << root->symbol << " ";
//	qianxu(root->left);
//	qianxu(root->right);
//}
//void houxu(btnode* root)
//{
//	if (root == NULL)
//		return;
//	houxu(root->left);
//	houxu(root->right);
//	if (root->symbol == '!') cout << root->data << " ";
//	else cout << root->symbol << " ";
//}
//double f(char c, double a, double b)
//{
//	switch (c)
//	{
//	case'*':return (a * b);
//	case'/':
//	{
//		if (b == 0)
//		{
//			cout << "error";
//			exit(0);
//		}
//		else return (a / b);
//	}
//	case'+':return (a + b);
//	case'-':return (a - b);
//	}
//}
//double cal(btnode* root)
//{
//	double a = 0;
//	double b = 0;
//	if (root->left == NULL && root->right == NULL) return root->data;
//	else
//	{
//		a = cal(root->left);
//		b = cal(root->right);
//		return f(root->symbol, a, b);
//	}
//}
//void creat(btnode*& root)
//{
//	for (int i = 0; i < strlen(str); i++)
//	{
//		if (i == 0 && str[i] == '-')
//		{
//			btnode* p = (btnode*)malloc(sizeof(btnode));
//			p->data = 0;
//			p->left = NULL;
//			p->right = NULL;
//			p->symbol = '!';
//			i++;
//			double d = 0;
//			while (str[i] <= '9' && str[i] >= '0')
//				d = d * 10 + str[i++] - '0';
//			if (str[i] == '.')
//			{
//				double x = 0.1;
//				i++;
//				while (str[i] >= '0' && str[i] <= '9')
//				{
//					d = d + x * (str[i++] - '0');
//					x *= 0.1;
//				}
//			}
//			i--;
//			btnode* q = (btnode*)malloc(sizeof(btnode));
//			q->data = d;
//			q->left = NULL;
//			q->right = NULL;
//			q->symbol = '!';
//			btnode* s = (btnode*)malloc(sizeof(btnode));
//			s->data = 10001;
//			s->left = p;
//			s->right = q;
//			s->symbol = '-';
//			z.push(s);
//			root = s;
//		}
//		else if (str[i] >= '0' && str[i] <= '9')
//		{
//			double d = 0;
//			while (str[i] <= '9' && str[i] >= '0')
//				d = d * 10 + str[i++] - '0';
//			if (str[i] == '.')
//			{
//				double x = 0.1;
//				i++;
//				while (str[i] >= '0' && str[i] <= '9')
//				{
//					d = d + x * (str[i++] - '0');
//					x *= 0.1;
//				}
//			}
//			i--;
//			btnode* q = (btnode*)malloc(sizeof(btnode));
//			q->data = d;
//			q->left = NULL;
//			q->right = NULL;
//			q->symbol = '!';
//			z.push(q);
//		}
//		else if (str[i] == '(')
//			c.push(str[i]);
//		else if (str[i] == '*' || str[i] == '/')
//		{
//			if (c.size() == 0 || c.top() == '+' || c.top() == '-' || c.top() == '(')
//				c.push(str[i]);
//			else
//			{
//				while (c.top() == '*' || c.top() == '/')
//				{
//					char ch = c.top();
//					c.pop();
//					btnode* s = (btnode*)malloc(sizeof(btnode));
//					s->data = 10001;
//					s->right = z.top();
//					z.pop();
//					s->left = z.top();
//					z.pop();
//					s->symbol = ch;
//					z.push(s);
//					root = s;
//					if (c.size() == 0)
//						break;
//				}
//				c.push(str[i]);
//			}
//		}
//		else if (str[i] == '+' || str[i] == '-')
//		{
//			if (c.size() == 0 || c.top() == '(')
//				c.push(str[i]);
//			else
//			{
//				while (c.top() == '*' || c.top() == '/' || c.top() == '+' || c.top() == '-')
//				{
//					char ch = c.top();
//					c.pop();
//					btnode* s = (btnode*)malloc(sizeof(btnode));
//					s->data = 10001;
//					s->right = z.top();
//					z.pop();
//					s->left = z.top();
//					z.pop();
//					s->symbol = ch;
//					z.push(s);
//					root = s;
//					if (c.size() == 0)
//						break;
//				}
//				c.push(str[i]);
//			}
//		}
//		else if (str[i] == ')')
//		{
//			while (c.top() != '(')
//			{
//				char ch = c.top();
//				c.pop();
//				btnode* s = (btnode*)malloc(sizeof(btnode));
//				s->data = 10001;
//				s->right = z.top();
//				z.pop();
//				s->left = z.top();
//				z.pop();
//				s->symbol = ch;
//				z.push(s);
//				root = s;
//			}
//			c.pop();
//		}
//	}
//	if (c.size() != 0)
//	{
//		while (c.size())
//		{
//			char ch = c.top();
//			c.pop();
//			btnode* s = (btnode*)malloc(sizeof(btnode));
//			s->data = 10001;
//			s->right = z.top();
//			z.pop();
//			s->left = z.top();
//			z.pop();
//			s->symbol = ch;
//			z.push(s);
//			root = s;
//		}
//	}
//	return;
//}
//
//int main()
//{
//	scanf("%s", str);
//	bt root = NULL;
//	creat(root);
//	qianxu(root);
//	cout << endl;
//	zhongxu(root);
//	cout << endl;
//	houxu(root);
//	cout << endl;
//	double ans = cal(root);
//	printf("%.3f", ans);
//	return 0;
//}
