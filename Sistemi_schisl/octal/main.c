#include <stdio.h>
#include <stdlib.h>

int main(){

    //FILE *fin, *fout; 
    
        //fin = fopen("input.txt", "r");
       //fout = fopen("output.txt", "w");
    unsigned long long int n = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld",&n);
    printf("%llo", n);
        //fscanf(fin,"%lld",&n);
        //fprintf(fout,"%o", n);
        //fclose(fin);
       // fclose(fout);
        return 0;
    
}