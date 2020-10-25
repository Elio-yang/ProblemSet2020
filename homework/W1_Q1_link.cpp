#include<iostream>
#include<cstdio>
using namespace std;
typedef struct node
{
	char word;
	struct node* next;
	struct node* back;
}zimu;
void shuru(char *a)
{
	int i;
	a[0] = getchar();
	for (i=0; a[i] != '\n';) {
		i++;
		a[i] = getchar();
	}
	a[i] = '\0';
	return;
}
void create(char *a,zimu *&head)
{
	int k = 0;
	zimu *p=head;
	for (int i = 0; a[i] != '\0'; i++) {
		char b = a[i];
		if (b == '[') {
			for (; p!= head; p = p->back) {
			}
			continue;
		}
		if (b == ']') {
			for (; p->next != nullptr; p = p->next) {
			}
			continue;
		}
		if (b == '{') {
			if (p!= head) {
				p = p->back;
			}
			continue;
		}
		if (b == '}') {
			if (p->next != nullptr) {
				p = p->next;
			}
			continue;
		}
		if(b=='-'){
			if (k == 0) {
				k = 1;
			}
			else {
				k = 0;
			}
			continue;
		}
		if (b == '=') {
			p->back->next = p->next;
			if (p->next!= nullptr) {
				p->next->back = p->back;
			}
			zimu *q=p;
			p = p->back;
			delete q;
			continue;
		}
		zimu *p1;
		if (k == 0) {
			p1 = new zimu;
			p1->next = nullptr;
			p1->back = nullptr;
			p1->next = p->next;
			p1->back = p;
			if (p1->next != nullptr) {
				p1->next->back = p1;
			}
			p->next = p1;
			p1->word = b;
			p = p->next;
		}
		if (k == 1) {
			p->next->word = b;
			p = p->next;
		}
	}
}
int main()
{
	zimu *head;
	head = new zimu;
	head->back = nullptr;
	head->next = nullptr;
	head->word = '0';
	char a[50000];
	shuru(a);
	create(a, head);
	zimu *g;
	g = head->next;
	for (; g != nullptr;g=g->next) {
		cout << g->word;
	}
	for (; g != nullptr; ) {
		zimu *f;
		f = g;
		g = g->next;
		delete f;
	}
}
//jilin[i lofe{{-v-} ] universiti=y