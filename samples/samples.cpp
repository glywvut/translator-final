#include "translator.h" 

int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    cout << "Введите выражение: ";
    getline(cin, str);
    ArithmeticExpression ar(str);
    cout << ar.GetResult();
}
