#include<iostream>
using namespace std;

struct stack{ 
    int inf;
    stack *next; 
};

void push(stack *&h, int x){//������� � ������
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r; 
}
int pop (stack *&h){ //�������� ���������� ��������
    int i = h->inf;
    stack *r = h;
    h = h->next;
    delete r;
    return i; 
}
void reverse(stack *&h){ //�������� �����
    stack *head1 = NULL; //������� ����� ����
    while (h)
        push(head1, pop(h)); //��������� ��-�� ������� ����� � ����� ����
    h = head1; // ������ ���������
}

stack *result(stack *&h){
    stack *res = NULL; //����� ����, ������� ����� ������������
    stack *h1 = NULL; //������������� ����
    bool chet = true; //������ ������� ��� �������� ��������
    while(h){
        while (chet){
            int x = pop(h);
            if (x % 2){ //���� ������� ��������
                push(res, x);//��������� ��� � ������������ ����
                while(h){
                    int y = pop(h); //����� ��������� ��� ��������� ��������
                    push(res, y);
                }
                chet = false; //������ �������� �������, �� �� ������ ����� ������ �������� �������
            }
            else{
                push(h1, x); //����� ��������� ������� � ������������� ����
            }
        }
    }
    reverse(h1); //�������������� ������������� ����
    while(h1){
        int x = pop(h1); //��������� ��� �������� � ��������� ����
        push(res, x);
    }
    reverse(res); //�������������� ��� � ����������
    return res; 
}
int main(){ 
    int n;
    cout << "n = ";
    cin >> n;
    stack *head = NULL; //�������������� 2 ����� �� ������, ���� � ������� ��� ������ �����
    stack *head1 = NULL;
    int x;
    for (int i = 0; i < n; i++){ //��������� ����
        cin >> x;
        push(head, x); 
    }
    int cnt_nechet = 0; //������� ���-�� �������� ���������
    while (head){
        int x = pop(head);
        if (x % 2)
            cnt_nechet++;
        push(head1, x);
    }
    reverse(head1);
    if (cnt_nechet > 0){
        reverse(head1); //���� ������� ��������, �� ��������� �����
        stack *res = result(head1);
        cout << "The answer: ";
        while(res)
            cout << pop(res) << " "; //�����
        cout << endl;
        return 0;
    }
    else{
        cout << "The answer: ";
        while (head1)
            cout << pop(head1) << " "; //����� ������� ��������� ������������������
    cout << endl;
    } 
}
