#include <stdio.h>

int main(){
    FILE *loop=fopen ("loop.txt","r");
    int i,j,loopcount;
    if (fscanf(loop,"%i",&loopcount)!=1) loopcount=1000;
    fclose(loop);
    volatile int arrayee[100000];
    for (j=0;j<loopcount;){
        for (i=0;i<100000;i++){
            arrayee[i]+=1;
        }
    }
    return 0;
}
