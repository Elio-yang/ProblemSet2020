/*
 ## 表达式树括号 (10分)

请编写程序将表达式树按中缀表达式输出，并填加必要的括号，要求括号不能冗余，即保证正确运算次序所需的最少括号。如*a*∗(*b*+*c*)和*a*+(*b*−*c*)中的括号是必要的，而*a*+(*b*∗*c*) 的括号则是冗余的。假定表达式树中的运算均为二元运算，只涉及加、减、乘、除运算。

### 输入格式:

输入为一行字符串，表示带空指针信息的表达式树先根序列，空指针信息用#表示，操作数为a-z的小写字母，运算符为+、-、*、/。

### 输出格式:

输出为一行字符串，表示填加必要括号后的中缀表达式。

### 输入样例1:

```in
*a##+b##c##
```

### 输出样例1:

```out
a*(b+c)
```

### 输入样例2:

```in
+a##*b##c##
```

### 输出样例2:

```out
a+b*c
```

 */
#include <cstdlib>
#include <iostream>
#include <cctype>
struct node {
	char key;
	struct node *lchild;
	struct node *rchild;
};

node* creat();
void in_order(node *T);
int order_op(char op_r);
int main() {
	auto T = new node;
	T = creat();
	in_order(T);
	return 0;
}

node* creat() {
	char k;
	scanf("%c", &k);
	node* T;
	if (k == '#') {
		T = NULL;
	}
	else {
		T = new node;
		T->key = k;
		T->lchild = creat();
		T->rchild = creat();
	}
	return T;
}
void in_order(node *T) {
	if (T != nullptr) {
		if (T->lchild){
			bool flag = order_op(T->key) > order_op(T->lchild->key);
			if (flag) {
				printf("(");
			}
			in_order(T->lchild);
			if (flag) {
				printf(")");
			}
		}
		printf("%c", T->key);
		if (T->rchild) {
			bool flag = order_op(T->key) >= order_op(T->rchild->key);
			if (flag ) {
				printf("(");
			}
			in_order(T->rchild);
			if (flag ) {
				printf(")");
			}
		}
	}
}
int order_op(char op_r) {
	if (op_r == '+' || op_r == '-') {
		return 1;
	}
	else if (op_r == '*' || op_r == '/') {
		return 2;
	}
	else if ('a' <= op_r && op_r <= 'z') {
		return 3;
	}
}
