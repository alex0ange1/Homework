#include<iostream>
using namespace std;

struct stack{ 
    int inf;
    stack *next; 
};

void push(stack *&h, int x){//вставка в начало
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r; 
}
int pop (stack *&h){ //удаление последнего элемента
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i; 
}
void reverse(stack *&h){ //разворот стека
    stack *head1 = NULL; //создаем новый стек
    while (h)
        push(head1, pop(h)); //добавляем эл-ты старого стека в новый стек
    h = head1; // меняем указатель
}

stack *result(stack *&h){
    stack *res = NULL; //новый стек, который будет возвращаться
    stack *h1 = NULL; //промежуточный стек
    bool chet = true; //булева функция для проверки четности
    while(h){
        while (chet){
            int x = pop(h);
            if (x % 2){ //если элемент нечетный
                push(res, x);//добавляем его в возвращаемый стек
                while(h){
                    int y = pop(h); //затем добавляем все остальные элементы
                    push(res, y);
                }
                chet = false; //меняем значение функции, тк на первом месте теперь нечетный элемент
            }
            else{
                push(h1, x); //иначе добавляем элемент в промежуточный стек
            }
        }
    }
    reverse(h1); //переворачиваем промежуточный стек
    while(h1){
        int x = pop(h1); //добавляем все элементы в финальный стек
        push(res, x);
    }
    reverse(res); //переворачиваем его и возвращаем
    return res; 
}
int main(){ 
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL; //инициализируем 2 стека на случай, если в очереди нет четных чисел
    stack *head1 = NULL;
    int x;
    for (int i = 0; i < n; i++){ //заполняем стек
        cin >> x;
        push(head, x); 
    }
    int cnt_nechet = 0; //считаем кол-во нечетных элементов
    while (head){
        int x = pop(head);
        if (x % 2)
            cnt_nechet++;
        push(head1, x);
    }
    reverse(head1);
    if (cnt_nechet > 0){
        reverse(head1); //если нашлись нечетные, то выполняем сдвиг
        stack *res = result(head1);
        cout << "The answer: ";
        while(res)
            cout << pop(res) << " "; //вывод
        cout << endl;
        return 0;
    }
    else{
        cout << "The answer: ";
        while (head1)
            cout << pop(head1) << " "; //иначе выводим начальную последовательность
    cout << endl;
    } 
}
