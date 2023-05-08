#include<iostream>
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
    stack *res = NULL; //инициализация стека, который будет возращаться, стеков для четных и нечетных элементов
    stack *chet = NULL;
    stack *nechet = NULL;
    while(h){
        int x = pop(h);
        if (x % 2){ //если эл-т нечетный, то удаляем его из начального стека и добавляем в стек с нечетными элементами
            push(nechet, x);
        }
        else{ //
            push(chet, x);
        }
    }
    reverse(nechet);
    while(nechet){
        int x = pop(nechet);
        push(res, x);
    }
    reverse(chet);
    while(chet){
        int x = pop(chet);
        push(res, x);
    }
    reverse(res);
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
    reverse(head); //переворачиваем стек 
    stack *res = result(head); //результат
    while(res)
        cout << pop(res) << " "; //выводим на экран
    cout << endl;
    return 0; 
}
