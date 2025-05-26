# Nesneye Yönelik Programlama


### Programlama Yaklaşımları

Prosedürel Yaklaşım

Aslında programlamaya ilk başladığımızda yaptığımız prosedürel yaklaşımdır. Program alt programlara bölünerek sırasıyla çalıştırılır.
Adım adım komut temelli yaklaşım.

```cpp
int a =10;
int b =20;
std::cout<< a+b;
```
Fonksiyonel Yaklaşım

Bir uygulamanın verilerini ve durumunu değiştirmeden her türlü işlemi fonksiyonlarla yapmasıdır.

```cpp
int a =10;
int b = 20;
std::cout<<topla(a,b);
```

Nesneye Yönelik Programlama (OOP)

Nesneye yönelik programlama, gerçek dünya varlıklarını sınıf ve nesne kavramları ile modelleyen bir yaklaşımdır. 

```cpp
class Araba {
public:
    void calistir() {
        cout << "Araba çalışıyor." << endl;
    }
};

int main() {
    Araba benimArabam;
    benimArabam.calistir();

    return 0;
}
```

Erişim Belirteçleri


| Belirteç    | Anlamı                                                     |
| ----------- | ---------------------------------------------------------- |
| `public`    | Her yerden erişilebilir.                                   |
| `private`   | Sadece sınıfın içinden erişilebilir.                       |
| `protected` | Sadece sınıfın içinden ve kalıtım yoluyla alt sınıflardan. |


 ## Yapıcı ve Yıkıcı metodlar

**Yapıcı Metot (Constructor)**

* Sınıftan bir nesne oluşturulduğunda otomatik çalışır.

* Nesneye ilk değer atamak için kullanılır.

* İsmi, sınıf ismiyle aynıdır ve geri dönüş tipi yoktur.

* Yazmak zorunda değilsiniz,yazmazsanız derleyici otomatik olarak oluşturur.

```cpp

#include <iostream>
using namespace std;
class KrediKarti {
public:
	KrediKarti() {
		cout << "Kredi Kartı oluşturuldu";
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	KrediKarti ziraat;
} 
```

Burada nesne oluşturulduğunda direkt olarak KrediKarti adli metod çalışıp ekrana Kredi kartı oluşturuldu yazacak.
```cpp
#include <iostream>
using namespace std;
class KrediKarti {
public:
	KrediKarti(int a) {
		cout << "Kredi Kartı oluşturuldu";
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	KrediKarti ziraat(12);
}
```
 Bu şekilde parametre vererekte yapıcı metod oluşturulabilir.

```cpp
 #include <iostream>
using namespace std;
class KrediKarti {
public:
	KrediKarti(int a) {
		cout << "Kredi Kartı oluşturuldu";
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	KrediKarti ziraat;

}
```
Bu şekilde kod kullanımı yanlıştır. Yapıcı metod eklemek gerekiyor.

```cpp
#include <iostream>
using namespace std;
class KrediKarti {
public:
	KrediKarti(int a) {
		cout << "Kredi Kartı oluşturuldu";
	}
	KrediKarti() {

	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	KrediKarti ziraat;
}
```
Bu seferde ekrana birşey yazmaz yapıcı metodda birşey yazmıyor.


Bir kodda birden fazla yapıcı metod olabilir. Aşırı yüklemeye benzer bir durum gibi düşünüyorum.


Yıkıcı Metot (Destructor)

* Nesne yaşamını bitirdiğinde otomatik olarak çalışır.

* Genellikle hafıza temizleme, dosya kapatma gibi işlemler için kullanılır.

* ~ işareti ile tanımlanır ve parametre almaz.
* Kendiniz çağıramazsınız.

```
#include <iostream>
using namespace std;
class SanalKrediKarti {
public:
	SanalKrediKarti( ) {
		cout << "Kredi Kartı oluşturuldu"<<endl;
	}
	void KrediKarti() {
		cout << "Sanal kartla işlem yapıldı" << endl;
	}
	~SanalKrediKarti() {
		cout << "Kart Silindi";
	}
};
int main()
{
	setlocale(LC_ALL, "Turkish");

	SanalKrediKarti ziraat;
	ziraat.KrediKarti();

}
```
çıktısı:

Kredi Kartı oluşturuldu

Sanal kartla işlem yapıldı

Kart Silindi

New anahtar kelimesi kullanılmıyorsa bu stackte oluşturuluyordur.
Stackte oluşturulan nesneler de parantezler bittiği anda kaldırılır.


### Inheritance/Kalıtım/Miras

C++’ta bir sınıfın başka bir sınıfın özelliklerini ve davranışlarını miras almasını sağlar.

Ana bir sınıfınız vardır. Base class 
Bu sınıftaki özellikleri spesifik olarak alt bir sınıfta(Derived Class) kullanmak istiyorsanız bu sınıftan miras almanız gerekiyor. Böylelikle kod tekrarıda azalır. Bir nesne ürettiğiniz zaman o nesnenin sınıfı ne kadar sınıftan miras alırsa hepsinden birer nesne oluşturur. Protected ile base classta erişim verirseniz bu türetilmiş sınıflardada kullanılabilir.


```cpp


#include <iostream>
using namespace std;
class SanalKrediKarti {
public:

	SanalKrediKarti( ) {
		cout << "Kredi Kartı oluşturuldu"<<endl;
	}
	void KrediKarti() {
		cout << "Sanal kartla işlem yapıldı" << endl;
	}
	~SanalKrediKarti() {
		cout << "Kart Silindi";
	}
public:
	int sifre;
	int pukkey;
};

class ziraatsanal :public SanalKrediKarti {
	void SanalKrediKarti(){
	pukkey = 123; }

protected:
	int ziraatkod;

};
int main()
{
	setlocale(LC_ALL, "Turkish");

	SanalKrediKarti  ziraat;
	ziraat.KrediKarti();

	ziraatsanal ziraatkart;
	ziraat.sifre = 123;

}
```

ziraatsanal SanalKrediKartı classından miras almıştır.


### Pointerlarla Beraber Nesneler kullanılması


```cpp
SanalKrediKarti  ziraat;
ziraat.KrediKarti();

ziraatsanal ziraatkart;
ziraat.sifre = 123;


ziraatsanal *ziraatptr = &ziraatkart;
ziraatptr->sifre;
```

### Kalıtım ve yapıcı yıkıcı metodlar

```cpp
#include <iostream>
using namespace std;

// Üst sınıf
class Hayvan {
public:
    Hayvan() {
        cout << "Hayvan yapıcı çalıştı." << endl;
    }

    ~Hayvan() {
        cout << "Hayvan yıkıcı çalıştı." << endl;
    }

    void sesCikar() {
        cout << "Hayvan ses çıkarıyor." << endl;
    }
};

// Alt sınıf (Hayvan sınıfından türeyen)
class Kopek : public Hayvan {
public:
    Kopek() {
        cout << "Köpek yapıcı çalıştı." << endl;
    }

    ~Kopek() {
        cout << "Köpek yıkıcı çalıştı." << endl;
    }

    void havla() {
        cout << "Hav hav!" << endl;
    }
};

int main() {
    cout << "Program başladı." << endl;
    Kopek benimKopek;  // Nesne oluşturuluyor
    benimKopek.sesCikar();  // Üst sınıf metodu
    benimKopek.havla();     // Alt sınıf metodu
    cout << "Program bitiyor." << endl;
    return 0;
}
```
