#include <iostream>

// Toplama fonksiyonu (callback adayı)
int toplama(int a, int b) {
    return a + b;
}

// Çarpma fonksiyonu (callback adayı)
int carpma(int a, int b) {
    return a * b;
}

// İşlem fonksiyonu (callback fonksiyon alıyor)
void islemYap(int x, int y, int (*islem)(int, int)) {
    int sonuc = islem(x, y);
    std::cout << "Sonuç: " << sonuc << std::endl;
}

int main() {
    // Toplama işlemi için callback
    islemYap(10, 5, toplama);   // Çıktı: Sonuç: 15

    // Çarpma işlemi için callback
    islemYap(10, 5, carpma);    // Çıktı: Sonuç: 50

    return 0;
}



-----------------------------------------------------------------


#include <iostream>
#include <vector>

// Callback tipi: bir sayıyı alır, true/false döner
bool ciftMi(int sayi) {
    return sayi % 2 == 0;
}

bool bestenBuyukMu(int sayi) {
    return sayi > 5;
}

// Filtreleme fonksiyonu
std::vector<int> filtrele(const std::vector<int>& liste, bool (*kosul)(int)) {
    std::vector<int> sonuc;
    for (int eleman : liste) {
        if (kosul(eleman)) {
            sonuc.push_back(eleman);
        }
    }
    return sonuc;
}

int main() {
    std::vector<int> sayilar = {1, 2, 3, 4, 5, 6, 7, 8};

    std::vector<int> ciftler = filtrele(sayilar, ciftMi);
    std::vector<int> buyukler = filtrele(sayilar, bestenBuyukMu);

    std::cout << "Çift sayılar: ";
    for (int s : ciftler) std::cout << s << " ";
    std::cout << std::endl;

    std::cout << "5'ten büyük sayılar: ";
    for (int s : buyukler) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
-------------------------------------------------------------------


#include <iostream>

// Fonksiyon işaretçisi tipi tanımlıyoruz (2 int alır, int döner)
using IslemFonksiyonu = int(*)(int, int);

// Toplama
int toplama(int a, int b) {
    return a + b;
}

// Çıkarma
int cikarma(int a, int b) {
    return a - b;
}

// Callback alan fonksiyon
void hesapla(int x, int y, IslemFonksiyonu islem) {
    int sonuc = islem(x, y);
    std::cout << "Sonuç: " << sonuc << std::endl;
}

int main() {
    hesapla(10, 5, toplama);  // Sonuç: 15
    hesapla(10, 5, cikarma);  // Sonuç: 5
    return 0;
}
