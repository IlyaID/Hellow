#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    int len_first, len_second, tmp=0; 
    char c, first[1000], second[1000], third[1000];
  
    scanf("%s",first);
    len_first=strlen(first);
    
    scanf("%s",second);
    len_second=strlen(second);
    
    if (len_first<len_second){
        for(int i = 0; i < 1 + len_second; i++){
            third[i]=first[i];
            first[i]=second[i];
            second[i]=third[i];
        }
    }

    len_first = strlen(first);
    len_second = strlen(second);

    int n = len_first - 1;
    int p = len_second - 1;
    int z = n - p;
    
    for(int i = n; i > z -1; --i){
        if (tmp==0){
            if ((first[i]=='0')&&(second[i-z]=='0')) third[i]='0';
            else if ((first[i]=='1')&&(second[i-z]=='0')) third[i]='1';
            else if ((first[i]=='0')&&(second[i-z]=='1')) third[i]='1';
            else if ((first[i]=='1')&&(second[i-z]=='1')) {third[i]='$';tmp=1;}
            else if ((first[i]=='0')&&(second[i-z]=='$')) third[i]='$';
            else if ((first[i]=='$')&&(second[i-z]=='0')) third[i]='$';
            else if ((first[i]=='$')&&(second[i-z]=='1')) third[i]='0';
            else if ((first[i]=='1')&&(second[i-z]=='$')) third[i]='0';
            else if ((first[i]=='$')&&(second[i-z]=='$')) {third[i]='1';tmp=2;};
    
        }
        else if (tmp==1){
            if ((first[i]=='0')&&(second[i-z]=='0')) {third[i]='1';tmp=0;}
            else if ((first[i]=='1')&&(second[i-z]=='0')) {third[i]='$';tmp=1;}
            else if ((first[i]=='0')&&(second[i-z]=='1')) {third[i]='$';tmp=1;}
            else if ((first[i]=='1')&&(second[i-z]=='1')) {third[i]='1';tmp=0;}
            else if ((first[i]=='0')&&(second[i-z]=='$')) {third[i]='0';tmp=0;}
            else if ((first[i]=='$')&&(second[i-z]=='0')) {third[i]='0';tmp=0;}
            else if ((first[i]=='$')&&(second[i-z]=='1')) {third[i]='1';tmp=1;}
            else if ((first[i]=='1')&&(second[i-z]=='$')) {third[i]='1';tmp=1;}
            else if ((first[i]=='$')&&(second[i-z]=='$')) {third[i]='$';tmp=0;};
        }
        else if (tmp == 2){
            if ((first[i]=='0')&&(second[i-z]=='0')) {third[i]='$';tmp=0;}
            else if ((first[i]=='1')&&(second[i-z]=='0')) {third[i]='0';tmp=0;}
            else if ((first[i]=='0')&&(second[i-z]=='1')) {third[i]='0';tmp=0;}
            else if ((first[i]=='1')&&(second[i-z]=='1')) {third[i]='1';tmp=0;}
            else if ((first[i]=='0')&&(second[i-z]=='$')) {third[i]='1';tmp=2;}
            else if ((first[i]=='$')&&(second[i-z]=='0')) {third[i]='1';tmp=2;}
            else if ((first[i]=='$')&&(second[i-z]=='1')) {third[i]='$';tmp=0;}
            else if ((first[i]=='1')&&(second[i-z]=='$')) {third[i]='$';tmp=0;}
            else if ((first[i]=='$')&&(second[i-z]=='$')) {third[i]='0';tmp=2;};
        }
    }
    
    for(int i = z - 1;i > -1; --i){
        if ((first[i]=='0')&&(tmp==0)) third[i]='0';
        else if ((first[i]=='1')&&(tmp==0)) third[i]='1';
        else if ((first[i]=='$')&&(tmp==0)) third[i]='$';
        else if ((first[i]=='0')&&(tmp==1)) {third[i]='1';tmp=0;}
        else if ((first[i]=='$')&&(tmp==1)) {third[i]='0';tmp=0;}
        else if ((first[i]=='0')&&(tmp==2)) {third[i]='$';tmp=0;}
        else if ((first[i]=='1')&&(tmp==2)) {third[i]='0';tmp=0;}
        else if ((first[i]=='$')&&(tmp==2)) {third[i]='1';tmp=2;}
        else if ((first[i]=='0')&&(tmp==1)) {third[i]='1';tmp=0;}
        else if ((first[i]=='$')&&(tmp==1)) {third[i]='0';tmp=0;}
        else if ((first[i]=='1')&&(tmp==1)) {third[i]='$';tmp=1;};
    }
    
    if (tmp==1) printf("%c",'1');
    if (tmp==2) printf("%c",'$');

    z=0;

    for (int i = 0; i <= n; ++i){
        if ((third[i]!='0')) z = 1;
        if ((z==1) || (tmp==1) ||(tmp==2)) printf("%c",third[i]);    
    }

    if ((z==0)&&((tmp!=1)||(tmp!=2)))  printf("0");
    
    return 0;
}