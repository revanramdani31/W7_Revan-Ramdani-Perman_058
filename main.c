#include "STACK.H"
#include "LinkedList.h"
#include "STACK.c"
#include "LinkedList.c"

int main() {
    int decimal;
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &decimal);
    
    if (decimal < 0) {
        printf("Bilangan harus positif.\n");
    } else if (decimal == 0) {
        printf("Hasil konversi biner: 0\n");
    } else {
        ConvertToBinary(decimal);
    }
    
    return 0;
}
