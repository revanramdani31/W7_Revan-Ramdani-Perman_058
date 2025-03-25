/* File        : stack.cpp */
/* Deskripsi   : Body ADT stack yang diimplementasikan dgn linked list */
/* Dibuat oleh : Ade Chandra Nugraha*/

#include "STACK.h"
#include "LinkedList.h"


/**** Perubahan nilai komponen struktur ****/
void SetTop (Stack *S, Stack NewTop )
/* Memberi Nilai TOP yang baru dengan NewTop */
{
	*S = NewTop;
}

/*    PROTO TYPE    */
/**** Konstruktor/Kreator ****/
void CreateEmpty (Stack *S)
/* IS : S sembarang */
/* FS : Membuat sebuah stack S yang kosong */
/* Ciri stack kosong : TOP bernilai NULL */
{
	*S = NULL;
}

/**** Predikat untuk test keadaan KOLEKSI ****/
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack Kosong */
{
	return (isEmpty(S));
}

/**** Menambahkan sebuah elemen ke Stack ****/
void Push (Stack *S, infotype X)
/* Menambahkan X sebagai elemen stack S */
/* IS : S mungkin kosong */
/* FS : X menjadi TOP yang baru */
{
	InsVFirst(&(*S),X);  // nama modul disesuaikan dengan pseudocode linked list pribadi
}

/**** Menghapus sebuah elemen Stack ****/
void Pop (Stack *S, infotype *X)
/* Menghapus X dari Stack S */
/* IS : S tidak mungkin kosong */
/* FS : X adalah nilai elemen TOP yang lama */
{
	DelVFirst(&(*S), &(*X)); // nama modul disesuaikan dengan pseudocode linked list pribadi
}

void ConvertToBinary(int decimal) {
    Stack S;
    CreateEmpty(&S);
    
    // Konversi ke biner menggunakan stack
    while (decimal > 0) {
        Push(&S, decimal % 2);
        decimal /= 2;
    }
    
    // Cetak hasil biner dengan pop dari stack
    printf("Hasil konversi biner: ");
    while (!IsEmpty(S)) {
        int bit;
        Pop(&S, (infotype*)&bit);
        printf("%d", bit);
    }
    printf("\n");
}