#include <iostream>
using namespace std;
struct Element
{
    //Данные
    char data;
    //Адрес следующего элемента списка
    Element* Next;
};
//Односвязный список
class List
{
    //Адрес головного элемента списка
    Element* Head;
    //Адрес концевого элемента списка
    Element* Tail;
    //Количество элементов списка
    int Count;
public:
    //Конструктор
    List();
    //Деструктор
    ~List();
    //Добавление элемента в список
    //(Новый элемент становится последним)
    void Add(char data);
    //Удаление элемента списка
    //(Удаляется головной элемент)
    void Del();
    //Удаление всего списка
    void DelAll();
    //Распечатка содержимого списка
    //(Распечатка начинается с головного элемента) 
    void Print();
    //Получение количества элементов,
    //находящихся в списке
    int GetCount();
    void PrintHead() const;
    void PrintTail() const;
    void PrintPos(int value) const;

    void AddHead(char data);
};
List::List()
{
    //Изначально список пуст
    Head = Tail = NULL;
    Count = 0;
}
List::~List()
{
    //Вызов функции удаления
    DelAll();
}
int List::GetCount()
{
    //Возвращаем количество элементов
    return Count;
}
void List::Add(char data)
{
    //создание нового элемента
    Element* temp = new Element;
    //заполнение данными
    temp->data = data;
    //следующий элемент отсутствует
    temp->Next = NULL;
    //новый элемент становится последним элементом списка
    //если он не первый добавленный
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    //новый элемент становится единственным
    //если он первый добавленный
    else {
        Head = Tail = temp;
    }
    Count++;
}
void List::Del()
{
    //запоминаем адрес головного элемента
    Element* temp = Head;
    //перебрасываем голову на следующий элемент
    Head = Head->Next;
    //удаляем бывший головной элемент
    delete temp;
    Count--;
}
void List::DelAll()
{
    //Пока еще есть элементы 
    while (Head != 0)
        //Удаляем элементы по одному
        Del();
    Count = 0;
}
void List::Print()
{
    //запоминаем адрес головного элемента
    Element* temp = Head;
    //Пока еще есть элементы
    while (temp != 0)
    {
        //Выводим данные
        cout << temp->data << " ";
        //Переходим на следующий элемент
        temp = temp->Next;
    }
    cout << "\n\n";
}



void List::PrintHead() const
{
    cout << Head->data << endl;
}



void List::PrintTail() const
{
    cout << this->Tail->data << endl;
}



void List::PrintPos(int value) const
{
    if (value > this->Count)
        return;



    Element* temp = Head;
    while (value != 0)
    {
        value--;
        temp = temp->Next;
    }
    cout << temp->data;
}

void List::AddHead(char data)
{
    Element* temp = new Element{ data };
    temp->Next = Head;

    Head == nullptr ? Head = temp : Head = temp;

    Count++;
}


//Тестовый пример
void main()
{

    List lst;

    char s[] = "Hello, World !!!";

    int len = strlen(s);

    for (int i = 0; i < len; i++)
        lst.Add(s[i]);

    lst.AddHead('H');

    lst.Print();

    // Method AddHead With Empty List

    List listEmpty;
    char str[] = "";

    listEmpty.AddHead('S');
    listEmpty.Print();
    cout << listEmpty.GetCount();
}