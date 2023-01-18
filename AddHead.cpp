#include <iostream>
using namespace std;
struct Element
{
    //������
    char data;
    //����� ���������� �������� ������
    Element* Next;
};
//����������� ������
class List
{
    //����� ��������� �������� ������
    Element* Head;
    //����� ��������� �������� ������
    Element* Tail;
    //���������� ��������� ������
    int Count;
public:
    //�����������
    List();
    //����������
    ~List();
    //���������� �������� � ������
    //(����� ������� ���������� ���������)
    void Add(char data);
    //�������� �������� ������
    //(��������� �������� �������)
    void Del();
    //�������� ����� ������
    void DelAll();
    //���������� ����������� ������
    //(���������� ���������� � ��������� ��������) 
    void Print();
    //��������� ���������� ���������,
    //����������� � ������
    int GetCount();
    void PrintHead() const;
    void PrintTail() const;
    void PrintPos(int value) const;

    void AddHead(char data);
};
List::List()
{
    //���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}
List::~List()
{
    //����� ������� ��������
    DelAll();
}
int List::GetCount()
{
    //���������� ���������� ���������
    return Count;
}
void List::Add(char data)
{
    //�������� ������ ��������
    Element* temp = new Element;
    //���������� �������
    temp->data = data;
    //��������� ������� �����������
    temp->Next = NULL;
    //����� ������� ���������� ��������� ��������� ������
    //���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    //����� ������� ���������� ������������
    //���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
    Count++;
}
void List::Del()
{
    //���������� ����� ��������� ��������
    Element* temp = Head;
    //������������� ������ �� ��������� �������
    Head = Head->Next;
    //������� ������ �������� �������
    delete temp;
    Count--;
}
void List::DelAll()
{
    //���� ��� ���� �������� 
    while (Head != 0)
        //������� �������� �� ������
        Del();
    Count = 0;
}
void List::Print()
{
    //���������� ����� ��������� ��������
    Element* temp = Head;
    //���� ��� ���� ��������
    while (temp != 0)
    {
        //������� ������
        cout << temp->data << " ";
        //��������� �� ��������� �������
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


//�������� ������
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