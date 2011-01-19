#include <stdio.h>
int main(){
    int count=0;
    count = printf("Hello World!");
    if (count==12) return 0;
    if (!count) return 12;
    return count;
}
