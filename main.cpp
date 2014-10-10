#include <iostream>
#include <string>
#include "Create.h"
#include "CreateArray.h"
using namespace std;


Create<int> getInt()
{
    Create<int> n = 7;
    return n;
}

int main()
{
    Create<int> n = getInt();
    CreateArray<int> k;
    for(int i = 0; i < 10; i++)
        k[i] = i;
    for(int i = 0; i < 10; i++)
        cout << k[i] << ',';
    Create<int> p;
    p = 10;
    cin >> p;
    cout << p << endl;
    p = p << 1;
    p = p >> 2;
    //k = n;
    //n = n << 2;
    //n = 14;
    cout << p << endl;
    int m = *k;
    cout << "Our number:" << m << endl;

    Create<string> name = string("Michael");
    string name1;
    name1 = name;
    name1 = string("Hello World!");
    cout << name1 << endl;
    cout << name << endl;

    return 0;
}
