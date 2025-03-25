#include <stdio.h>
#include "stack.h"
#include "Linked_list.h"
#include "STACK.cpp"
#include "Body.c"

void KonversiDesimalKeBiner(int desimal) {
    Stack S;
    CreateEmpty(&S);  // Inisialisasi stack kosong

    // Jika input 0, langsung print
    if (desimal == 0) {
        printf("Biner: 0\n");
        return;
    }

    // Push sisa hasil bagi ke stack
    while (desimal > 0) {
        Push(&S, desimal % 2);
        desimal /= 2;
    }

    // Pop dan cetak hasil konversi dalam urutan yang benar
    printf("Biner: ");
    int bit;
    while (!IsEmpty(S)) {
        Pop(&S, &bit);
        printf("%d", bit);
    }
    printf("\n");
}


int main() {
    Stack S;
    infotype X;

    int desimal;
    
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &desimal);

    // Panggil fungsi konversi
    KonversiDesimalKeBiner(desimal);

    return 0;
}
