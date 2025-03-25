/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanaggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "Linked_list.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty(Stack S) {
    return (S.First == NULL);  // Stack kosong jika first bernilai NULL
}


/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList)); // Pastikan malloc digunakan
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil){
	free (P);
	 }
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algorit
	 ma */
	 P = First(L);
	 while ((P != Nil) && (!found)){
		if (Info(P) == X){	
			found = true; 	
		}
		else{	
			P = Next(P);	
		}
	 }	
	 P = Nil;
	
	 return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found)){
		if (PSearch == P){	
			found = true; 	
		}
		else{	
			PSearch = Next(PSearch);	
		}
	 }	
	 PSearch = Nil; 
	 
	 return (found);
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = First(L);
	while ((P != Nil) && (!found)){
		 if (Info(P) == X){	
			found = true;	
		}else{
			Prec = P;
			P = Next(P);
		}
	}     
	P = Nil;
	
	if (found){	
		return (Prec);		
	}else{
		return (Nil);		
	}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (Stack * L, infotype *X){
	 /* Kamus Lokal */
	 address P = Alokasi(X);
	 /* Algoritma */
    if (!IsEmpty(*L)) { // Pastikan stack tidak kosong
        P = First(*L);
        *X = P->info; // Simpan nilai sebelum dealokasi
        First(*L) = P->next;
        free(P); // Bebaskan memori
    }
}

void InsertFirst (Stack * L, address P){
    if (!IsEmpty(*L)) { // Pastikan stack tidak kosong
        P = First(*L);
        First(*L) = P->next;
        free(P); // Bebaskan memori
    }
}

void InsVLast (List * L, infotype X){
	 /* Kamus Lokal */
	address P;
	address Q;
	 /* Algoritma */
	P = Alokasi(X);
    if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            Q = First(*L);
            while (Next(Q) != Nil) {
                Q = Next(Q);
            }
            Next(Q) = P;
        }
    }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan Elemen ****/
void DelVFirst (Stack * L, infotype * X){
	address P;
	 /* Algoritma */
    DelFirst(L, &P);
    }
void DelFirst (Stack * L, address * P){
	//Buatkan algoritma sesuai spesifikasi modul ini
	if (!ListEmpty(*L)) {
        *P = First(*L);
        First(*L) = Next(*P);
        DeAlokasi(*P);
    }
}


void DelVLast (List * L, infotype * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	address Q;
	 /* Algoritma */

	 if (!ListEmpty(*L)) {
        PDel = First(*L); 
		Q = Nil;
        while (Next(PDel) != Nil) {
            Q = PDel;
            PDel = Next(PDel);
        }
        *X = Info(PDel);
        if (Q == Nil) {
            First(*L) = Nil;
        } else {
            Next(Q) = Nil;
        }
        DeAlokasi(PDel);
    }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}


void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	//Buatkan algoritma sesuai spesifikasi modul ini
	if (P != Nil && Prec != Nil) {
        Next(P) = Next(Prec);
        Next(Prec) = P;
	}
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
	 if (P != Nil) {
        if (ListEmpty(*L)) {
            First(*L) = P;
        } else {
            Last = First(*L);
            while (Next(Last) != Nil) {
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}


void DelP(List *L, infotype X) {
    /* Kamus Lokal */
    address P, Prec;

    /* Algoritma */
    if (ListEmpty(*L)) { // Cek apakah list kosong
        printf("Underflow: List kosong, tidak bisa menghapus elemen.\n");
        return;
    }

    P = First(*L);
    Prec = Nil;

    // Cari elemen dengan nama dan nilai yang cocok
    while (P != Nil && Info(P) != X) { 
        Prec = P;
        P = Next(P);
    }

    // Jika ditemukan
    if (P != Nil) {
        if (Prec == Nil) { // Jika elemen yang dihapus adalah elemen pertama
            First(*L) = Next(P);
        } else { // Jika elemen di tengah/akhir
            Next(Prec) = Next(P);
        }
        printf("Menghapus: %s dengan nilai %d\n", Info(P));
        DeAlokasi(P); // Dealokasi elemen
    } else {
        printf("Elemen dengan nama '%s' dan nilai %d tidak ditemukan dalam list.\n", X);
    }
}


void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	 if (!ListEmpty(*L)) {
        Prec = Nil;
        *P = First(*L);

        while (Next(*P) != Nil) {
            Prec = *P;
            *P = Next(*P);
        }

        if (Prec == Nil) {
            First(*L) = Nil;
        } else {
            Next(Prec) = Nil;
        }

        DeAlokasi(*P);
    }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	 //Buatkan algoritma sesuai spesifikasi modul ini
	 if (Prec != Nil && Next(Prec) != Nil) {
        *Pdel = Next(Prec);
        Next(Prec) = Next(*Pdel);
        DeAlokasi(*Pdel);
    }
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	 if (ListEmpty(L)) {
        printf("List Kosong\n");
    } else {
        P = First(L);
        while (P != Nil) {
            printf("%d ", Info(P));
            P = Next(P);
        }
        printf("\n");
    }
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	 while (!ListEmpty(*L)) {
        DelFirst(L, &PDel);
        DeAlokasi(PDel);
    }
	 //Buatkan algoritma sesuai sPDelesifikasi modul ini
}
/*menghapus bilangan ganjil*/
void DelOdd(List *L) {
    address P = First(*L);
    address Prec = Nil;
    address PDel;

    while (P != Nil) {
        if (Info(P) % 2 != 0) { // Jika nilai ganjil
            if (Prec == Nil) { // Jika P adalah elemen pertama
                First(*L) = Next(P);
                PDel = P;
                P = Next(P);
                DeAlokasi(PDel);
            } else { // Jika P bukan elemen pertama
                Next(Prec) = Next(P);
                PDel = P;
                P = Next(P);
                DeAlokasi(PDel);
            }
        } else {
            Prec = P;
            P = Next(P);
        }
    }
}




