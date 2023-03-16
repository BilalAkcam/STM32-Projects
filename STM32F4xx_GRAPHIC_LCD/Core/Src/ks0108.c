#include "ks0108.h"
#include "font.h"
#include "delay.h"

volatile unsigned char x_ks0108, y_ks0108;	 // Global Degiskenler

//Fonksiyonlar

void draw_ks0108( char bitmap[2048]){		//Gorsel Cizdirmek Icin Kullanilan Fonksiyon
	int x,y,i,j;
	for(i=0;	i<2;	i++)
	{
		j=0;
		HAL_Delay(100);
		for(y=0;	y<8;	y++)
		{
			for(x=0; x<128; x++)
			{
				if(i==0)
					ks0108_int_8Bit (x, y, bitmap[j++]);

			}
		}
		HAL_Delay(100);
	}
}



void ks0108_int_write (int sec, int Veri)	//sec = 0 ise cs1 (GLCD'nin sol tarafi) aktif, sec = 1 ise cs2 (GLCD'nin sag tarafi) aktiftir.
{
	if (sec != 0)							// GLCD'nin kullanilacak kismi secilir
		KS0108_R();							//sec 0'dan farkliysa sol, sifirsa sag taraf GLCD'de aktif edilir.
	else
		KS0108_L();

	KS0108_RW	= 0;						// Yazma modu aktif
	KS0108_EN	= 1;						// GLCD enable edildi
	KS0108_LDATA(Veri);						// datayı GLCD'ye yukle
	delay_us(1);
	KS0108_EN	= 0;
	KS0108_L();								//cs1 aktif
	KS0108_R();								//cs2 aktif
}



void ks0108_int_8Bit (int xx, int yy, int Veri_Bayt)
{


	int sec = 0;							// GLCD'nin kullanilacak kismini secilir
	if (xx >= 64)
	{
		if (xx>127)
			xx=0;
		else
		{
			xx-=64;
			sec = 1;
		}
	}

	KS0108_DI	= 0;	// veri modu
	xx|=0x40;
	ks0108_int_write (sec, xx);
	ks0108_int_write (sec, (yy & 0xBF) | 0xB8);

											// Komut moduna geç ve koordinati belirli noktayi isaretle
	KS0108_DI	= 0;						// Komut modu
	ks0108_int_write (sec, xx);				// Yatay adresi kur
											// Yatay (x) adresi belirlenen noktaya fonksiyondan gonderilen degeri yaz
	KS0108_DI	= 1;						// Veri modu
	ks0108_int_write (sec, Veri_Bayt);  	// Veri_Bayt degerini piksele yaz

}

void strobe_ks0108(void){
	delay_us(1);							// 1 us bekle
	KS0108_EN	= 1;						//Eneble pinini set yap
	delay_us(1);
	KS0108_EN	= 0;
	delay_us(1);
}

void wait_busy_ks0108(void){
	KS0108_PORT_DIR(KS0108_PORT_INPUT);		//Portu giris yap
	KS0108_DI	= 0;						// Komut Modu
	KS0108_RW	= 1;						// Okuma Modu
	strobe_ks0108();						// LCD flas
	KS0108_RW	= 0;						// Yazma Modu
	KS0108_PORT_DIR(KS0108_PORT_OUTPUT); 	// Port yonunu degistir.
}

void putcmd_ks0108(char ins){				//Gelen adres bilgilerine gore veriyi KS0108_LDATA()'ya gonderen fonksiyon
	wait_busy_ks0108();
	KS0108_DI	= 0;						// Komut Modu
	KS0108_LDATA(ins);						// Ogrenileni porta gonder
	strobe_ks0108();						// LCD flas
}

unsigned char getd_ks0108(void){
	char data;
	KS0108_PORT_DIR(KS0108_PORT_INPUT);		// Portu giris yap
	KS0108_DI	= 1;						// Veri Modu
	KS0108_RW	= 1;						// Okuma Modu
	strobe_ks0108();						// LCD flas
	data = KS0108_DATA;						// LCD'den data oku
	KS0108_RW	= 0;						// Yazma modu
	KS0108_PORT_DIR(KS0108_PORT_OUTPUT);	// Portu cikis yap
	return data;
}

void putd_ks0108(char data){
	if(x_ks0108==0){						// 64' luk hucre dolmazsa sol Chip (CS1) Seciliyor
		KS0108_L();							// cs1 aktif
		putcmd_ks0108(KS0108_Y_ADRESS|(y_ks0108&0x7));
		putcmd_ks0108(KS0108_X_ADRESS);
	}else if(x_ks0108==64){					// 64 luk hucre doldu Sag chip (cs2) Seciliyor
		KS0108_R();							// cs2 aktif
		putcmd_ks0108(KS0108_Y_ADRESS|(y_ks0108&0x7));
		putcmd_ks0108(KS0108_X_ADRESS);
	}
	wait_busy_ks0108();
	KS0108_DI	= 1;
	KS0108_LDATA(data);
	strobe_ks0108();
	x_ks0108++;
	if(x_ks0108>127){

	x_ks0108=0;
	y_ks0108++;
	}

	if(y_ks0108>7){
	y_ks0108=0;
	}

}

void cls_ks0108(void){
	unsigned int i;
	x_ks0108 = 0;
	y_ks0108 = 0;
	for(i=0;i<1024;i++)putd_ks0108(0x00);
	x_ks0108 = 0;
	y_ks0108 = 0;
}

void init_ks0108(void){						// KS init ayarlari

	KS0108_RST_DIR(KS0108_PIN_OUTPUT);
	KS0108_RW_DIR(KS0108_PIN_OUTPUT);
	KS0108_DI_DIR(KS0108_PIN_OUTPUT);
	KS0108_EN_DIR(KS0108_PIN_OUTPUT);
	KS0108_CS1_DIR(KS0108_PIN_OUTPUT);
	KS0108_CS2_DIR(KS0108_PIN_OUTPUT);
	KS0108_PORT_DIR(KS0108_PORT_OUTPUT);

	KS0108_DI	= 0;						// Komut Modu
	KS0108_RW	= 0;						// Yazma Mode
	KS0108_N();								// Chip Secilmesin
	KS0108_LDATA(0x00);						// Datayi Porta Yukle
	KS0108_EN	= 0;

	KS0108_RST	= 0;
	delay_ms(2);
	KS0108_RST	= 1;
	delay_ms(1);

	KS0108_L();								// cs1 aktif
	putcmd_ks0108(KS0108_DISPLAY_OFF);
	putcmd_ks0108(KS0108_START_LINE);
	putcmd_ks0108(KS0108_X_ADRESS);
	putcmd_ks0108(KS0108_Y_ADRESS);
	putcmd_ks0108(KS0108_DISPLAY_ON);

	KS0108_R();								// cs2 aktif
	putcmd_ks0108(KS0108_DISPLAY_OFF);
	putcmd_ks0108(KS0108_START_LINE);
	putcmd_ks0108(KS0108_X_ADRESS);
	putcmd_ks0108(KS0108_Y_ADRESS);
	putcmd_ks0108(KS0108_DISPLAY_ON);

	cls_ks0108();
}

void gotoxy_ks0108(unsigned char x, unsigned char y){ 	//Adres bigilerini alan fonksiyon
	x_ks0108 = x;
	y_ks0108 = y;
	if(x_ks0108<64){
		KS0108_L();										// cs1 aktif
		putcmd_ks0108(KS0108_Y_ADRESS|(y_ks0108&0x7));
		putcmd_ks0108(KS0108_X_ADRESS|x_ks0108);
	}else{
		KS0108_R();										// cs2 aktif
		putcmd_ks0108(KS0108_Y_ADRESS|(y_ks0108&0x7));
		putcmd_ks0108(KS0108_X_ADRESS|(x_ks0108-64));
	}
}

void putc_ks0108(char c){								// Kullanicidan alinan karakteri font dizisinde bulan fonksiyon
	int i;

	switch(c){
		case '\f':cls_ks0108();break;
		case '\n':gotoxy_ks0108(0,y_ks0108++);break;
		case '\r':gotoxy_ks0108(0,y_ks0108);break;
		default:if(x_ks0108>122)gotoxy_ks0108(0,++y_ks0108);
		for(i = 0; i < 5; i++)putd_ks0108(Font[(((c-0x20)*5) + i)]);
		putd_ks0108(0x00);
		break;

/* Asci Tablosunda space karakteri hex olarak 0x20 den baslar. Bizim font dizisindeki space ise ilk karakterimizdir
   bu yuzden  c-0x20 ile asci tablosunda kaydirma yaparak space ilk karakter haline gelmis olur.
*/
	}
}




void puts_ks0108(char *s){		//Ekrana karakter yazdiran fonksiyon.
	do{
		putc_ks0108(*s);
	}while(*++s);
}

// Yazdirilacak olan char karakterin adresini *s pointerinda tutar ve putc_ks0108 fonksiyonundaki c ye atar.

