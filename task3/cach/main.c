#include <stdio.h>

int NOD(int x, int y)
{
    if(x != y)
    {
        if(x > y)NOD(x - y, y);
        else NOD(x, y - x);
    }
    else 
        return x;
}


int main()
{
    int n, f;
    scanf("%d%d", &n, &f);
    int A[1024][1024];
    int B[1024][1024];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            A[i][j] = NOD(i + 1, j + 1);
            B[i][j] = NOD(n - i + 1, n - j + 1);
        }
    }

    int schet = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int sum = 0;
            for(int g = 0; g < n; g++)
            {
                sum += A[i][g] *  B[j][g];
            }
            //printf("%d\n", sum);
            if(sum % f == 0)schet++;
        }
    }
   // printf("\n");
    printf("%d", schet);
    return 0;
}