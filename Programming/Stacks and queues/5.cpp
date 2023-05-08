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

int count_min(queue *h, queue*t, int n, int mini){
	queue *h1 = h;
	queue *t1 = t;
	int cnt = 0;
    int cnt_min = 0;
	while(cnt < n){
		int x = pop(h, t);
		if (x == mini)
			cnt_min++;
		push(h, t, x);
		cnt++;
	}
	return cnt_min;
}

queue *vstavka(queue *&head, queue*t, int mini, int cnt_min){
    cout << "min el = " << mini << endl;
    cout << "cnt min = " << cnt_min << endl;
    queue *res = NULL;
	queue *h1 = res;
	queue *t1 = res;
    int cnt_min1 = cnt_min;
    while(head){
        int x = pop(head, t);
        if (x == mini){
            if (cnt_min1 == cnt_min || cnt_min1 == 1){
                cnt_min1--;
                continue;
            }
            else{
                push(h1, t1, x);
                cnt_min1--;
            }
        }
        else
            push(h1, t1, x);
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
    int cnt_min = count_min(head, t, n, mini);
    queue *res = vstavka(head, t, mini, cnt_min);
    cout << "The answer:" << endl;
	print(res);
}
