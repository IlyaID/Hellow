#include <unistd.h>

int main(int argc, char* argv[]){
    char str[] = "Liberté, égalité, fraternité!\n";
    write(1, str, sizeof(str) - 1);
    exit(0);
}