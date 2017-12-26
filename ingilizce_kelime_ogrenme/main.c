#include<stdio.h>
#include"fonk.h"

int main() 
{
	logo_yaz("logo.txt");
	char **tr, **ing;
	satir_sayisi = satir_ogren("kelimeler.txt");
	tr = dizi_yap(tr, satir_sayisi);
	ing = dizi_yap(ing, satir_sayisi);	
	dizileri_doldur("kelimeler.txt", ing, tr);
    while(1) {
        menu_ac();
        printf("\nseçiminizi yazınız :");
        int cas, kont=0;
        kont = scanf("%d", &cas);
		if (!kont) {
			kirmizi_yaz("sadece 1-5 arası seçim yapınız\n");
			break;
		}
        switch (cas) {
            case 1:
                mavi_yaz("- çıkmak için q'ya bas\n- devam için entera bas\n");
                char as;
                do{                    
                    as = rasgele_yaz(ing, tr);                  
                }while(as != 'q');
                break;
			case 2:
				do{                    
                    as = rasgele_yaz(tr, ing);                  
                }while(as != 'q');
				break;
            case 3:
                dizi_komple_yaz(ing);
                break;
            case 4:
                dizi_komple_yaz(tr);
                break;
            case 5:
                goto exit;
            default:
				kirmizi_yaz("sadece 1-5 arası seçim yapınız\n");
                break;
        }
    }
exit:
	kirmizi_yaz("Program Sonlandırılıyor....\n");
	mavi_yaz("GULE GULE :)\n");
	return 0;
}
