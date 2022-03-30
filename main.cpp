#include <iostream>
#include <fstream>

using namespace std;

void elochcka(int height) // задача 4
{
    int height1 = height;\
    int num =1;

    while (height != 0)
    {
        char space = ' ';
        for (int i = height; i > 0; i--)
        {
            cout << ' ';
        }
        height--;
        for (int j = 0; j<num; j++)
        {
            cout << '*';
        }
        num+=2;
        cout << endl;
    }
}

string toBin(int num) // задача 2
{
    string bin = "";
    while (num > 0)
    {
        if (num%2 == 0)
        {
            bin+='1';
        }
        else
        {
            bin+='0';
        }
        num/= 2;
    }
    return bin;
}
void toFile(int result)
{
    ofstream results2;
    results2.open("results.txt", ios::out);
    results2 << result;
    results2.close();
}

struct Node
{
    Node* prev;
    Node* next;
    char* string;
    int size;
};
void linkedListToFile(FILE* out, Node* TAIL) // задача 6
{
    Node* cur_node = TAIL;
    int elements_num = 0;
    do
    {
        elements_num++;
        cur_node = cur_node->prev;
    }
    while(cur_node->prev != nullptr);
    cur_node = TAIL;
    do
    {
        fprintf(out, "%d\t%s\t%d\n", elements_num, cur_node->string, cur_node->size);
        elements_num--;
        cur_node = cur_node->prev;
    }
    while(cur_node->prev != nullptr);
}
void addElementToList(Node* HEAD, Node* el, const int index) // задача 7
{
    Node* cur_node = HEAD;
    int cur_index = 0;

    while(cur_index <= index)
    {
        cur_node = cur_node->next;
    }
    el->next = cur_node->next;
    el->prev = cur_node;
    cur_node->next->prev = el;
    cur_node->next = el;
}


int main() {

    return 0;
}
