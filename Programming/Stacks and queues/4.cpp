#include<iostream>
#include <limits.h>
using namespace std;

struct stack{ 
    int inf;
    stack *next; 
};

void push(stack *&h, int x){//вставка 
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r; 
}
int pop (stack *&h){ //удаление 
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i; 
}

void reverse(stack *&h){ //"обращение"стека
    stack *head1 = NULL; //инициализация буферного стека 
    while (h) //пока стек не пуст
        push(head1, pop(h)); //переписываем из одного стека в другои? 
    h = head1; //переобозначаем указатели
}

stack *result(stack *&h){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    stack *t = h;
    stack *res = NULL;
    stack *t1 = h;
    while (t){
        int x = t -> inf;
        if (x > maxi)
            maxi = x;
        if (x < mini)
            mini = x;
        t = t->next;
    }
    cout << "min: " << mini << endl;
    cout << "max: " << maxi << endl;

    while(t1){
        int x = t1 -> inf;
        push(res, x);
        if (x == mini)
            push(res, maxi);
        t1 = t1 -> next;
    }
    return res;
}
int main(){ 
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL; //инициализация
    int x;
    for (int i = 0; i < n; i++){ //создаем стек
        cin >> x;
        push(head, x); 
    }
    stack *res = result(head);
    while(res)
        cout << pop(res) << " ";
    cout << endl;
}
