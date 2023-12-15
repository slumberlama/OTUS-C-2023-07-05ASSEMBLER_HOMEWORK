#include <stdio.h>
#include <stdlib.h>

//объявляем односвязный список
typedef struct Node {
    long int value;          // значение
    struct Node *next;  //ссылка на следующий элемент
} Node;

//вывод int
void print_int(long int a)
{
    printf("%ld ", a);
    fflush(stdout);
}

//функция m
void m(Node **head, void (*c)(long int))
{
    Node *tmp = *head;
    while(*head) {
        c( (*head)->value );
        (*head)=(*head)->next;
    }
    (*head)=tmp;
}

//функция p, проверка на чётность
int p(long int b)
{
    return (b & 1) == 1;
}

//создание элемента списка
void add_element(Node **head, long int data){

    Node *tmp=(Node*)malloc(sizeof(Node));
    if(!tmp){abort();}
    tmp->value=data;
    tmp->next=(*head);
    (*head)=tmp;
}


//функция f, проверка на чётность
void f(Node *head, Node **head_2, int (*d)(long int))
{
    Node *list = head;
    if(head==NULL) {printf("%d ", 500);}

    while(list) {
        if(d(list->value)) {
                add_element(head_2, list->value);
        }
        list=list->next;
    }
}

long int data[6]={4,8,15,16,23,26};
int data_length = 6;
char* empty_str = " ";

int main ()
{
    Node *head = NULL;
    Node *head_2 = NULL;
    //создаём список из массива
    if((data==NULL) || (data_length==0)) {return 0;}
    for(int i = 5; i >= 0; i--) {
        add_element(&head, data[i]);
    }
    m(&head, print_int);
    puts(empty_str);

    f(head, &head_2, p);

    m(&head_2, print_int);
    puts(empty_str);

    free(head); //устранена утечка памяти malloc
    free(head_2); //устранена утечка памяти malloc

    return 0;
}
