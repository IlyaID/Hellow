#define N 100
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct _Decimal {
    char a[N];   // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;       // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0}; // представление 0 в виде структуры

Decimal add (Decimal a, Decimal b);

Decimal add (Decimal a, Decimal b){
    Decimal result;
    int tmp = 0;
        if(a.n >= b.n){
            result.n = a.n;
            for(int i = 0; i <= result.n; i++){
                
                if(i <= b.n){
                    if(a.a[i] + b.a[i] + tmp >= 10){
                        result.a[i] = (a.a[i] + b.a[i] + tmp)%10;
                        tmp = 1;
                    }
                    else{
                        result.a[i] = a.a[i] + b.a[i] + tmp;
                        tmp = 0;
                    } 
                }
                else{
                    //result.a[i] = a.a[i] + tmp;
                    if(a.a[i] + tmp >= 10){
                        result.a[i] = (a.a[i] + tmp)%10;
                        tmp = 1;
                    }
                    else{
                        result.a[i] = a.a[i]  + tmp;
                        tmp = 0;
                    } 
                }
            }
        }

        else{
            result.n = b.n;
            for(int i = 0; i <= result.n; i++){
                
                if(i <= a.n){
                    if(a.a[i] + b.a[i] + tmp >= 10){
                        result.a[i] = (a.a[i] + b.a[i] + tmp)%10;
                        tmp = 1;
                    }
                    else{
                        result.a[i] = a.a[i] + b.a[i] + tmp;
                        tmp = 0;
                    } 
                }
                else{
                    //result.a[i] = b.a[i] + tmp;
                    if(b.a[i] + tmp >= 10){
                        result.a[i] = (b.a[i] + tmp)%10;
                        tmp = 1;
                    }
                    else{
                        result.a[i] = b.a[i]  + tmp;
                        tmp = 0;
                    } 
                }
            }
        }
    if(tmp != 0){
        result.a[++result.n] = 1;
    }
    return result;
}





void print_decimal(Decimal put){
    for(int i = 0; i <= put.n; i++){
        printf("%d * 10^%d + ", put.a[i], i);
    }
    
} 


int main(){
    Decimal a = {{7, 4, 9}, 2};  // set number 147
    Decimal b = {{3, 6, 9}, 2};     // set number 13
    Decimal res;
    
    res = add(a, b);  
              // res = a+b = 147+13 = 160
    print_decimal(res);                    // print 160
    
    
    return 0;
}
