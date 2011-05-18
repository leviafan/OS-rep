#include <stdio.h>

int main(){
    volatile int i,j,l,loopcount=1000;
    volatile int arrayee[1000][500];
    for (l=0;l<loopcount;l++){
        for (i=0;i<1000;i++){
            for (j=0;j<100;j++){
                arrayee[i][j]+=1;
            }    
        }
    }
    return 0;
}
