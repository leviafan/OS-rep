#include <stdio.h>
#include <stdlib.h>

int show_mess(char *mess){
    return printf("%s",mess);
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}


int main(int argc, char *argv[]){
    FILE *r_file;
    int i, check, *tmp_heap, *heap_with_numbers=NULL, error_code=0, unit=0, unit_number=0, file_cntr=1, argum=argc;
    char dummy, str[50];
    if (argc<2){
        if (show_mess("\nToo few arguments. I need one file at least")>0) error_code=1;
        return error_code;
    }
    do{
        r_file = fopen(argv[file_cntr],"r");
        if (!r_file){
            strcpy (str,"\nCan't open for read file: ");
            if (!show_mess(strcat(str,argv[file_cntr]))) error_code=1;
            return error_code;
        }
        while (!feof(r_file)){
            if (fscanf (r_file,"%i ",&unit)==1){
                strcpy (str,"\nIncorrect data in file: ");
                if (show_mess(strcat(str,argv[file_cntr]))>0) error_code=1;
                while (fscanf (r_file,"%i ",&unit)==1){fscanf (r_file,"%s",&dummy);}
            }
            tmp_heap = (int*) realloc (heap_with_numbers, (unit_number+1)*sizeof(int));
  			if (tmp_heap){
                heap_with_numbers=tmp_heap;
                heap_with_numbers[unit_number]=unit;
            }
            else{
                free (heap_with_numbers);
                fclose(r_file);
                if (show_mess("\nCan't realloc memory. ")>0) error_code=1;
                return error_code;
            }
            unit_number++;
        }
        fclose(r_file);
        file_cntr++;
    } while (file_cntr<argc-1);

    qsort(heap_with_numbers, unit_number, sizeof(int), cmp);
    r_file=fopen(argv[argc-1],"w");
    if (!r_file){
        strcpy (str,"\nCan't open for write file: ");
        if (show_mess(strcat(str,argv[argc-1]))>0) error_code=1;
        free(heap_with_numbers);
        return error_code; 
    }
    for(i=0;i<unit_number;i++){
        
        if (!fprintf (r_file,"%i ",heap_with_numbers[i])){
            fclose(r_file);
            strcpy (str,"\nCan't write data into file: ");
            if (show_mess(strcat(str,argv[argc-1]))>0) error_code=1;
        }
    }
    fclose(r_file);
    free(heap_with_numbers);
    return error_code;
}
