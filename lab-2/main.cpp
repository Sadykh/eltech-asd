#include <iostream>

#include <Windows.h>
#include <ctime>
#include "Set.h"

using namespace std;

int main() {
    srand(time(NULL));

//	Set A = Set("BCDFILMNPTUYZ");
//	Set B = Set("DHJLMPQUVXYZ");
//	Set C = Set("ACGLPVWYZ");
//	Set D = Set("BCDFHIJNPQRSTUVWY");
    Set A = Set();
    Set B = Set();
    Set C = Set();
    Set D = Set();

    cout << "Множетсво А: ";
    A.Show();
    cout << "Множетсво B: ";
    B.Show();
    cout << "Множетсво C: ";
    C.Show();
    cout << "Множетсво D: ";
    D.Show();

    cout << "Множетсво E: ";
    (A & ~B & ~C | D).Show();
    int start, end, COUNT = 100000;
    start = clock();
    for (int i = 0; i < COUNT; i++)
        Set E = (A & ~B & ~C | D);
    end = clock();
    cout << "Время вычисления множества E " << COUNT << " раз: " << float(end - start) << " мс" << endl;
    system("pause");
    return 0;
}
