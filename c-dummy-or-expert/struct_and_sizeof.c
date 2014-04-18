#include <stdio.h>

struct X
{
    int a;
    char b;
    int c;

};

void set_value(struct X* this, int v) {this->a = v;}
int get_value(struct X* this) {return this->a;}
void increase_value(struct X* this) {this->a++;}

int main()
{
    printf("The size of struct X: %d.\n", sizeof(X));

    return 0;
}


