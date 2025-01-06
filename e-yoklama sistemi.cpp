#include <stdio.h>



struct Ogrenci {
    int numara;
    char isim[50];
    int yoklama;
};

struct Ogrenci ogrenciler[100];
int ogrenci_sayisi = 0;

// Fonksiyon prototipleri
void ogrenci_ekle();
void yoklama_al();
void yoklama_raporu();

int main() {
    int secim;

    do {
        printf("\n--- Ogrenci Yoklama Sistemi ---\n");
        printf("1. Ogrenci Ekle\n");
        printf("2. Yoklama Al\n");
        printf("3. Yoklama Raporu\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                ogrenci_ekle();
                break;
            case 2:
                yoklama_al();
                break;
            case 3:
                yoklama_raporu();
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    } while (secim != 4);

    return 0;
}

void ogrenci_ekle() {
    if (ogrenci_sayisi >= 100) {
        printf("Maksimum ogrenci sayisina ulasildi!\n");
        return;
    }

    printf("\nYeni ogrenci bilgilerini girin:\n");
    printf("Ogrenci numarasi: ");
    scanf("%d", &ogrenciler[ogrenci_sayisi].numara);
    printf("Ogrenci ismi: ");
    scanf(" %s", &ogrenciler[ogrenci_sayisi].isim);

    ogrenciler[ogrenci_sayisi].yoklama = 0; 
     ogrenci_sayisi++;

    printf("Ogrenci basariyla eklendi!\n");
}

void yoklama_al() {
    int numara, bulundu = 0;

    printf("\nYoklama almak icin ogrenci numarasini girin: ");
    scanf("%d", &numara);

    for (int i = 0; i < ogrenci_sayisi; i++) {
        if (ogrenciler[i].numara == numara) {
            bulundu = 1;
            printf("%s isimli ogrenci mevcut mu? (1: Evet, 0: Hayir): ", ogrenciler[i].isim);
            scanf("%d", &ogrenciler[i].yoklama);
            printf("Yoklama kaydedildi.\n");
            break;
        }
    }

    if (!bulundu) {
        printf("Bu numaraya sahip bir ogrenci bulunamadi.\n");
    }
}

void yoklama_raporu() {
    printf("\n--- Yoklama Raporu ---\n");

    for (int i = 0; i < ogrenci_sayisi; i++) {
        printf("Numara: %d, Isim: %s, Durum: %s\n", 
               ogrenciler[i].numara, 
               ogrenciler[i].isim, 
               ogrenciler[i].yoklama ? "Mevcut" : "Yok");
    }
}
