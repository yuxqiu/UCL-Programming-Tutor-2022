#include <iostream>

void f(int s) { (void)s; }
void f(int &s) { (void)s; }
// causes problem due to overload resolution rules
// void f(const int& s);

int main(void) { f(1); }
