#include <stdio.h>
#include <time.h>
int main(){
    FILE *out = fopen("result.txt","w");
    if (!out){
        return 1; //can't open result file for write          
    }
    int Arra[7000][70],i,j,l;
    clock_t start,mid_end,final;

    for (i=0;i<70;i++){
        for (j=0;j<7000;j++){
            Arra[j][i]=0;
        }
    }

    start = clock();
    for (l=0;l<50;l++){
        for (i=0;i<7000;i++){
            for (j=0;j<70;j++){
                Arra[i][j]++;
//                printf("%i\n",Arra[i][j]);
            }
        }
    }

    mid_end = clock();
    
    for (l=0;l<50;l++){
        for (i=0;i<70;i++){
            for (j=0;j<7000;j++){
                Arra[j][i]++;
//                printf("%i\n",Arra[j][i]);
            }
        }
    }

    final = clock();
    fprintf(out,"1st method: %.2f\n", (float)(mid_end - start));
    fprintf(out,"2nd method: %.2f\n", (float)(final - mid_end));
    return 0;
}
