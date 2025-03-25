#include "LinkedList.h"


// Membuat node baru
void Create_Node(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    }
}

// Menghapus node
void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

// Mengecek apakah list kosong
bool isEmpty(List L) {
    return L == NULL;
}


// *** OPERASI PENYISIPAN ***
void InsVFirst(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        P->next = *L;
        *L = P;
    }
}

void InsVLast(List *L, infotype X) {
    address P, Last;
    Create_Node(&P, X);
    if (P != NULL) {
        if (isEmpty(*L)) {
            *L = P;
        } else {
            Last = *L;
            while (Last->next != NULL) {
                Last = Last->next;
            }
            Last->next = P;
        }
    }
}

void InsertFirst(List *L, address P) {
    P->next = *L;
    *L = P;
}

void InsertAfter(List *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void InsertLast(List *L, address P) {
    address Last;
    if (isEmpty(*L)) {
        *L = P;
    } else {
        Last = *L;
        while (Last->next != NULL) {
            Last = Last->next;
        }
        Last->next = P;
    }
}

// *** OPERASI PENGHAPUSAN ***
void DelVFirst(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        P = *L;
        *X = P->info;
        *L = P->next;
        DeAlokasi(&P);
    }
}

void DelVLast(List *L, infotype *X) {
    address P, Prec = NULL;
    if (!isEmpty(*L)) {
        P = *L;
        while (P->next != NULL) {
            Prec = P;
            P = P->next;
        }
        *X = P->info;
        if (Prec == NULL) {
            *L = NULL;
        } else {
            Prec->next = NULL;
        }
        DeAlokasi(&P);
    }
}

void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*P)->next;
        DeAlokasi(P);
    }
}

void DelLast(List *L, address *P) {
    address Prec = NULL;
    if (!isEmpty(*L)) {
        *P = *L;
        while ((*P)->next != NULL) {
            Prec = *P;
            *P = (*P)->next;
        }
        if (Prec == NULL) {
            *L = NULL;
        } else {
            Prec->next = NULL;
        }
        DeAlokasi(P);
    }
}

void DelP(List *L, infotype X) {
    address P = *L, Prec = NULL;
    while (P != NULL && P->info != X) {
        Prec = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Prec == NULL) {
            *L = P->next;
        } else {
            Prec->next = P->next;
        }
        DeAlokasi(&P);
    }
}

// *** OPERASI PENCARIAN ***
address Search(List L, infotype X) {
    address P = L;
    while (P != NULL && P->info != X) {
        P = P->next;
    }
    return P;
}

// Mengurutkan List secara Ascending 
void Ascending(List *L) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    List i, j;
    infotype temp;
    for (i = *L; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Mengurutkan List secara Descending 
void Descending(List *L) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    List i, j;
    float temp;
    for (i = *L; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info < j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

// Menghitung jumlah elemen dalam list
int HitungElement(List L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

// Menyalin data mahasiswa dengan nilai >= 70 ke list baru


// Menghapus seluruh list
void DeleteList(List *L) {
    address P;
    while (!isEmpty(*L)) {
        P = *L;
        *L = P->next;
        DeAlokasi(&P);
    }
}
