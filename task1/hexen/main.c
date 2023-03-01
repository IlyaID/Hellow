#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HexToBin(char* hexen, char* binary)
{
    long int i = 0, j = 0;
 
    while (hexen[j]) {
 
        switch (hexen[j]) {
        case '0':
            binary[i] = '0';
            binary[++i] = '0';
            binary[++i] = '0';
            binary[++i] = '0';
            i++;
            break;
        case '1':
            binary[i] = '0';
            binary[++i] = '0';
            binary[++i] = '0';
            binary[++i] = '1';
            i++;
            break;
        case '2':
            binary[i] = '0';
            binary[++i] = '0';
            binary[++i] = '1';
            binary[++i] = '0';
            i++;
            break;
        case '3':
            binary[i] = '0';
            binary[++i] = '0';
            binary[++i] = '1';
            binary[++i] = '1';
            i++;
            break;
        case '4':
            binary[i] = '0';
            binary[++i] = '1';
            binary[++i] = '0';
            binary[++i] = '0';
            i++;
            break;
        case '5':
            binary[i] = '0';
            binary[++i] = '1';
            binary[++i] = '0';
            binary[++i] = '1';
            i++;
            break;
        case '6':
            binary[i] = '0';
            binary[++i] = '1';
            binary[++i] = '1';
            binary[++i] = '0';
            i++;
            break;
        case '7':
            binary[i] = '0';
            binary[++i] = '1';
            binary[++i] = '1';
            binary[++i] = '1';
            
            break;
        case '8':
            binary[i] = '1';
            binary[++i] = '0';
            binary[++i] = '0';
            binary[++i] = '0';
            i++;
            break;
        case '9':
            binary[i] = '1';
            binary[++i] = '0';
            binary[++i] = '0';
            binary[++i] = '1';
            i++;
            break;
        case 'A':
        case 'a':
            binary[i] = '1';
            binary[++i] = '0';
            binary[++i] = '1';
            binary[++i] = '0';
            i++;
            break;
        case 'B':
        case 'b':
            binary[i] = '1';
            binary[++i] = '0';
            binary[++i] = '1';
            binary[++i] = '1';
            i++;
            break;
        case 'C':
        case 'c':
            binary[i] = '1';
            binary[++i] = '1';
            binary[++i] = '0';
            binary[++i] = '0';
            i++;
            break;
        case 'D':
        case 'd':
            binary[i] = '1';
            binary[++i] = '1';
            binary[++i] = '0';
            binary[++i] = '1';
            i++;
            break;
        case 'E':
        case 'e':
            binary[i] = '1';
            binary[++i] = '1';
            binary[++i] = '1';
            binary[++i] = '0';
            i++;
            break;
        case 'F':
        case 'f':
            binary[i] = '1';
            binary[++i] = '1';
            binary[++i] = '1';
            binary[++i] = '1';
            i++;
            break;
        default:
            return 0;
        }
        j++;
    }
}



int main()
{
    char hex[1000000];
    char bin[4000000];
    
    scanf("%s", &hex);
    
    HexToBin(hex, bin);

    long long len_bin = strlen(bin); 

    int i = 0;
    
    while(bin[i] == '0'){
        
        i++;
    }
    
    for(i;i < len_bin; i++){
        printf("%c", bin[i] + 0);
    }
    
    return 0;
}