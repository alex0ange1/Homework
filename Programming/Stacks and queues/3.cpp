#include <iostream>
#include <limits.h>
using namespace std;

struct queue
{
	int inf;
	queue *next;
};

void push(queue *&h, queue *&t, int x){
	queue *r = new queue;
	r->inf = x;
	r->next = NULL;

	if (!h && !t)
	{
		h = t = r;
	}
	else
	{
		t -> next = r;
		t = r;
	}
}

int pop (queue *&h, queue *&t){ //удаление элемента из очереди
    queue *r = h;
    int i = h->inf;
    h = h->next;
    if (!h)
        t = NULL;
    delete r;
    return i;
}

void print(queue *&head)
{
	queue *t = head;
	while (t)
	{
		int x = pop(head, t);
		cout << x << " ";
	}
    cout << endl;
}

int min_el(queue *h, queue*t, int n){
	queue *h1 = h;
	queue *t1 = t;
	int mini = INT_MAX;
	int cnt = 0;
	while(cnt < n){
		int x = pop(h, t);
		if (x < mini)
			mini = x;
		push(h, t, x);
		cnt++;
	}
	return mini;
}

queue *vstavka(queue *&h, queue *&t, int mini){
	queue *res = NULL;
	queue *h1 = res;
	queue *t1 = res;
    int first_el = h -> inf;
    cout << "first: " << first_el << endl;
	cout << "min = " << mini << endl;
	while(h){
		int x = pop(h, t);
		push(h1, t1, x);
		if (x == first_el)
			push(h1, t1, mini);
	}
    return h1;
}

int main(){
	queue *head = NULL;
	queue *t = head;

	int n, x;
	cout << "n = "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push(head, t, x);
	}
	int mini = min_el(head, t, n);
    queue *res = vstavka(head, t, mini);
	print(res);
}
