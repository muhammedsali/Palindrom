#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dugum {
    int veri;
    struct dugum *ileri;
};

// Verilen tek baðlý listenin palindrom olup olmadýðýný kontrol eden fonksiyon
bool palindromMu(struct dugum *baslangic) {
	
	
    // Özel durum: Liste boþ veya tek elemanlýysa palindromdur.
    if (baslangic == NULL || baslangic->ileri == NULL) {
        return true;
    }
    
    
    // Yavaþ ve hýzlý iþaretçiler oluþturuluyor.
    struct dugum *yavas = baslangic;
    struct dugum *hizli = baslangic;
    
    
    // Orta elemaný bulmak için hýzlý iþaretçi ilerletiliyor.
    while (hizli != NULL && hizli->ileri != NULL) {
        yavas = yavas->ileri;
        hizli = hizli->ileri->ileri;
    }
    
    
    // Ortadaki elemandan sonrasý ters çevriliyor.
    struct dugum *onceki = NULL;
    struct dugum *simdiki = yavas;
    struct dugum *sonraki;
    
    while (simdiki != NULL) {
        sonraki = simdiki->ileri;
        simdiki->ileri = onceki;
        onceki = simdiki;
        simdiki = sonraki;
    }
    
    
    // Ýki iþaretçi, baþtan ve sondan ilerleyerek kontrol ediliyor.
    struct dugum *p1 = baslangic;
    struct dugum *p2 = onceki;
    
    while (p2 != NULL) {
        if (p1->veri != p2->veri) {
            return false;
        }
        p1 = p1->ileri;
        p2 = p2->ileri;
    }
    
    return true;
}


int main() {
    // Örnek bir liste oluþturuluyor.
    struct dugum *baslangic = NULL;
    baslangic = (struct dugum*) malloc(sizeof(struct dugum));
    baslangic->veri = 1;
    baslangic->ileri = (struct dugum*) malloc(sizeof(struct dugum));
    baslangic->ileri->veri = 2;
    baslangic->ileri->ileri = (struct dugum*) malloc(sizeof(struct dugum));
    baslangic->ileri->ileri->veri = 3;
    baslangic->ileri->ileri->ileri = (struct dugum*) malloc(sizeof(struct dugum));
    baslangic->ileri->ileri->ileri->veri = 2;
    baslangic->ileri->ileri->ileri->ileri = (struct dugum*) malloc(sizeof(struct dugum));
    baslangic->ileri->ileri->ileri->ileri->veri = 1;
    baslangic->ileri->ileri->ileri->ileri->ileri = NULL;
    
    
    // Liste palindrom mu diye kontrol ediliyor.
    if (palindromMu(baslangic)) {
        printf("Verilen liste palindromdur.\n");
 } else {
        printf("Verilen liste palindrom deðildir.\n");
    }
    
    return 0;
}
