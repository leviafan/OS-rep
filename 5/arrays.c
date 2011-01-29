#include stdio.h
#include time.h

int main(){
    FILE *out = fopen(result.txt,"w");
    int Arr[2000][2000],i,j;
    clock_t start,mid-end,final;
    start = clock();
    
    for (i=0;i<2000;i++){
        for (j=0;j<2000;j++){
            Arr[j][i]=0;
        }
    }
    mid-end = clock();
    
    for (i=0;i<2000;i++){
        for (j=0;j<2000;j++){
            Arr[i][j]=1;
        }
    }
    final = clock();
    fprintf(out,"1st method: %f.2\n", (float)(mid-end - start));
    fprintf(out,"2nd method: %f.2\n", (float)(final - mid-end));
    return 0;
}
