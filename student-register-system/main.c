#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define int(x) *((int *) x)

void ekle();
void bul();
void sirala();
int dosyaKontrol();
void telnobul();
void ogrencinobul();
void mailbul();
int satirbul();
void isimsirala();
void ogrencinosirala();


//strekle, strcmp, strcpy fonksiyonların kullanımına izin vermiyormuşsunuz galiba hocam
//bu yüzden aşağıdaki fonksiyonları o komutları replike edebilmek için yazdım çünkü öbür
//türlü kodu çalıştıramam. 

char *kopyala(char *target, const char *base){
    char *saved = target;
    while(*base){
        *target++ = *base++;
    }
    *target = 0;
    return saved;
}

char *strekle(char *ilk, char *son){
    int i, j;
    for(i=0; ilk[i]!='\0'; ++i);

    for(j=0; son[j]!='\0'; ++j, ++i)
   {
      ilk[i]=son[j];
   }
   ilk[i] = "\0";
   return ilk;
}

int karsilastir (const char *p1, const char *p2)
{
  const unsigned char *s1 = (const unsigned char *) p1;
  const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;
  do
    {
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
        return c1 - c2;
    }
  while (c1 == c2);
  return c1 - c2;
}

//----------------------------------

int main(){
    int secim;
    puts("1 -> kullanici ekle\n2 -> kullanici bul\n3 -> kullanici sirala\n4 -> cikis\n\nLutfen secim yapiniz: ");
    scanf("%d", &secim);
    while(secim > 4 || secim < 1){
        system("CLS");
        puts("yanlis secim yaptiniz. Lutfen tekrar seciniz.\n");
        puts("1 -> kullanici ekle\n2 -> kullanici bul\n3 -> kullanici sirala\n4 -> cikis\n\nLutfen secim yapiniz: ");
        scanf("%d", &secim);
    };
    system("CLS");
    while(secim != 4){
        switch(secim){
            case 1:
                ekle();
                system("CLS");
                break;
            case 2:
                bul();
                system("CLS");
                break;
            case 3:
                sirala();
                system("CLS");
                break;
        }
        puts("1 -> kullanici ekle\n2 -> kullanici bul\n3 -> kullanici sirala\n4 -> cikis\n\nLutfen secim yapiniz: ");
        scanf("%d", &secim);
        while(secim > 4 || secim < 1){
            system("CLS");
            puts("yanlis secim yaptiniz. Lutfen tekrar seciniz.\n");
            puts("1 -> kullanici ekle\n2 -> kullanici bul\n3 -> kullanici sirala\n4 -> cikis\n\nLutfen secim yapiniz: ");
            scanf("%d", &secim);
        }
    }
    puts("cikis yapiliyor...");
    return 0;
}


int dosyaKontrol(){
    FILE *mydoc;
    if(mydoc = fopen("ogrenciler.txt", "r")){
        fclose(mydoc);
        return 1;
    }
    return 0;
}


void ekle(){
    struct ogrenci{
        char isim[20];
        char soyisim[20];
        int ogrencino;
        int telefonno;
        char mail[50];
    };
    struct ogrenci ogrenci1;
    printf("Ogrencinin ismini giriniz: ");
    scanf("%s",ogrenci1.isim);
    printf("\nOgrencinin soy ismini giriniz: ");
    scanf("%s",ogrenci1.soyisim);
    printf("\nOgrencinin ogrenci numarasini giriniz: ");
    scanf("%d", &ogrenci1.ogrencino);
    printf("\nOgrencinin telefon numarasini giriniz: ");
    scanf("%d", &ogrenci1.telefonno);
    printf("\nOgrencinin mail adresini giriniz: ");
    scanf("%s", ogrenci1.mail);
    FILE *dosya;

    if(dosyaKontrol()){
        dosya = fopen("ogrenciler.txt", "a");
        fprintf(dosya, "%s", ogrenci1.isim);
        fprintf(dosya," ");
        fprintf(dosya, "%s", ogrenci1.soyisim);
        fprintf(dosya," ");
        fprintf(dosya, "%d", ogrenci1.ogrencino);
        fprintf(dosya," ");
        fprintf(dosya, "%d", ogrenci1.telefonno);
        fprintf(dosya," ");
        fprintf(dosya, "%s", ogrenci1.mail);
        fprintf(dosya, "\n");
        fclose(dosya);
    } else{
        dosya = fopen("ogrenciler.txt", "w");
        fprintf(dosya, "%s", ogrenci1.isim);
        fprintf(dosya," ");
        fprintf(dosya, "%s", ogrenci1.soyisim);
        fprintf(dosya," ");
        fprintf(dosya, "%d", ogrenci1.ogrencino);
        fprintf(dosya," ");
        fprintf(dosya, "%d", ogrenci1.telefonno);
        fprintf(dosya," ");
        fprintf(dosya, "%s", ogrenci1.mail);
        fprintf(dosya, "\n");
        fclose(dosya);
    }
}


void bul(){
    if(!dosyaKontrol()){
        puts("dosya bulunamadi. lutfen once dosyaya bilgi ekleyin.");
        puts("\nbir ust menuye donmek icin bir tusa tiklayin.");
        getch();
    }else{
        int secim;
        puts("1-> Telefon numarasina gore bul\n2-> ogrenci numarasina gore bul\n3-> mail adresine gore bul\n4-> bir ust menuye don\n\nLutfen secim yapiniz: ");
        scanf("%d", &secim);
        while(secim>4 || secim<1){
            system("CLS");
            puts("yanlis secim yaptiniz. tekrar secim  yapiniz.");
            puts("1-> Telefon numarasina gore bul\n2-> ogrenci numarasina gore bul\n3-> mail adresine gore bul\n4-> bir ust menuye don\n\nLutfen secim yapiniz: ");
            scanf("%d", &secim);
        }
        while(secim != 4){
            switch(secim){
                case 1:
                    telnobul();
                    system("CLS");
                    break;
                case 2:
                    ogrencinobul();
                    system("CLS");
                    break;
                case 3:
                    mailbul();
                    system("CLS");
                    break;
            }
            puts("1-> Telefon numarasina gore bul\n2-> ogrenci numarasina gore bul\n3-> mail adresine gore bul\n4-> bir ust menuye don\n\nLutfen secim yapiniz: ");
            scanf("%d", &secim);
            while(secim>4 || secim<1){
                system("CLS");
                puts("yanlis secim yaptiniz. tekrar secim  yapiniz.");
                puts("1-> Telefon numarasina gore bul\n2-> ogrenci numarasina gore bul\n3-> mail adresine gore bul\n4-> bir ust menuye don\n\nLutfen secim yapiniz: ");
                scanf("%d", &secim);
            }
        }
    }
}


void sirala(){
    if(!dosyaKontrol()){
        puts("dosya bulunamadi. lutfen once dosyaya bilgi ekleyin.");
        puts("\nbir ust menuye donmek icin bir tusa tiklayin.");
        getch();
    }else{
        int secim;
        puts("1-> isme gore sirala\n2-> ogrenci numarasina gore sirala\n3-> bir ust menuye don\n\nLutfen secim yapiniz: ");
        scanf("%d", &secim);
        while(secim>3 || secim<1){
            system("CLS");
            puts("yanlis secim yaptiniz. tekrar secim  yapiniz.");
            puts("1-> isme gore sirala\n2-> ogrenci numarasina gore sirala\n3-> bir ust menuye don\n\nLutfen secim yapiniz: ");
            scanf("%d", &secim);
        }
        while(secim != 3){
            switch(secim){
                case 1:
                    isimsirala();
                    system("CLS");
                    break;
                case 2:
                    ogrencinosirala();
                    system("CLS");
                    break;
            }
            puts("1-> isme gore sirala\n2-> ogrenci numarasina gore sirala\n3-> bir ust menuye don\n\nLutfen secim yapiniz: ");
            scanf("%d", &secim);
            while(secim>3 || secim<1){
                system("CLS");
                puts("yanlis secim yaptiniz. tekrar secim  yapiniz.");
                puts("1-> isme gore sirala\n2-> ogrenci numarasina gore sirala\n3-> bir ust menuye don\n\nLutfen secim yapiniz: ");
                scanf("%d", &secim);
            }
        }
    }
}

void telnobul(){
    int size;
    size = satirbul();
    void *arr[50][5];
    FILE *myfile;
    int myint;
    myfile = fopen("ogrenciler.txt", "r");
    for(int i = 0; i < size; i++){
        char *isim;
        isim =malloc(sizeof(char)*50);
        fscanf(myfile, "%s", isim);
        arr[i][0] = malloc(strlen(isim)*sizeof(char));
        arr[i][0] = isim;

        char *soyisim;
        soyisim = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", soyisim);
        arr[i][1] = malloc(strlen(soyisim)*sizeof(char));
        arr[i][1] = soyisim;

        fscanf(myfile, "%d", &myint);
        arr[i][2] = malloc(sizeof(int));
        int(arr[i][2]) = myint;

        fscanf(myfile, "%d", &myint);
        arr[i][3] = malloc(sizeof(int));
        int(arr[i][3]) = myint;

        char *mail;
        mail = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", mail);
        arr[i][4] = malloc(strlen(mail)*sizeof(char));
        arr[i][4] = mail;
    }
    fclose(myfile);
    int control = 0;
    int search;
    puts("lutfen aramak istediginiz telefon numarasini girin: ");
    scanf("%d", &search);
    for(int row = 0; row < size; row++){
        if(int(arr[row][3]) == search){
            system("CLS");
            puts("aradiginiz kisinin bilgileri: ");
            puts("");
            printf("%20s\t%20s\t%20s\t%20s\t%20s\t", "isim", "soyisim", "ogrenci no", "tel no", "email");
            puts("");
            puts("");
            for(int i = 0; i < 5; i++){
                if(i == 0 || i == 1 || i == 4){
                    printf("%20s\t", arr[row][i]);
                }else{
                    printf("%20d\t", int(arr[row][i]));
                }
            }
            control = 1;
            break;
        }
    }
    if(control == 0){
        system("CLS");
        puts("\ngirdiginiz telefon numarasina sahip bir ogrenci bulunamadi.");
    }
    puts("\n\nonceki menuye donmek icin bir tusa basiniz...");
    getch();
}

void mailbul(){
    int size;
    size = satirbul();
    void *arr[50][5];
    FILE *myfile;
    int myint;
    myfile = fopen("ogrenciler.txt", "r");
    for(int i = 0; i < size; i++){
        char *isim;
        isim =malloc(sizeof(char)*50);
        fscanf(myfile, "%s", isim);
        arr[i][0] = malloc(strlen(isim)*sizeof(char));
        arr[i][0] = isim;

        char *soyisim;
        soyisim = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", soyisim);
        arr[i][1] = malloc(strlen(soyisim)*sizeof(char));
        arr[i][1] = soyisim;

        fscanf(myfile, "%d", &myint);
        arr[i][2] = malloc(sizeof(int));
        int(arr[i][2]) = myint;

        fscanf(myfile, "%d", &myint);
        arr[i][3] = malloc(sizeof(int));
        int(arr[i][3]) = myint;

        char *mail;
        mail = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", mail);
        arr[i][4] = malloc(strlen(mail)*sizeof(char));
        arr[i][4] = mail;
    }
    fclose(myfile);
    int control = 0;
    char *asd;
    printf("lutfen aramak istediginiz mail adresini girin: ");
    asd = malloc(sizeof(char)*50);
    scanf("%s", asd);
    for(int row = 0; row < size; row++){
        if(karsilastir(asd, arr[row][4]) == 0){
            system("CLS");
            puts("aradiginiz kisinin bilgileri: ");
            puts("");
            printf("%20s\t%20s\t%20s\t%20s\t%20s\t", "isim", "soyisim", "ogrenci no", "tel no", "email");
            puts("");
            puts("");
            for(int i = 0; i < 5; i++){
                if(i == 0 || i == 1 || i == 4){
                    printf("%20s\t", arr[row][i]);
                }else{
                    printf("%20d\t", int(arr[row][i]));
                }
            }
            control = 1;
            break;
        }
    }
    if(control == 0){
        system("CLS");
        puts("\ngirdiginiz mail adresine sahip bir ogrenci bulunamadi.");
    }
    puts("\n\nonceki menuye donmek icin bir tusa basiniz...");
    getch();
}

void ogrencinobul(){
    int size;
    size = satirbul();
    void *arr[50][5];
    FILE *myfile;
    int myint;
    myfile = fopen("ogrenciler.txt", "r");
    for(int i = 0; i < size; i++){
        char *isim;
        isim =malloc(sizeof(char)*50);
        fscanf(myfile, "%s", isim);
        arr[i][0] = malloc(strlen(isim)*sizeof(char));
        arr[i][0] = isim;

        char *soyisim;
        soyisim = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", soyisim);
        arr[i][1] = malloc(strlen(soyisim)*sizeof(char));
        arr[i][1] = soyisim;

        fscanf(myfile, "%d", &myint);
        arr[i][2] = malloc(sizeof(int));
        int(arr[i][2]) = myint;

        fscanf(myfile, "%d", &myint);
        arr[i][3] = malloc(sizeof(int));
        int(arr[i][3]) = myint;

        char *mail;
        mail = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", mail);
        arr[i][4] = malloc(strlen(mail)*sizeof(char));
        arr[i][4] = mail;
    }
    fclose(myfile);
    int control = 0;
    int search;
    puts("lutfen aramak istediginiz ogrenci numarasini girin: ");
    scanf("%d", &search);
    for(int row = 0; row < size; row++){
        if(int(arr[row][2]) == search){
            system("CLS");
            puts("aradiginiz kisinin bilgileri: ");
            puts("");
            printf("%20s\t%20s\t%20s\t%20s\t%20s\t", "isim", "soyisim", "ogrenci no", "tel no", "email");
            puts("");
            puts("");
            for(int i = 0; i < 5; i++){
                if(i == 0 || i == 1 || i == 4){
                    printf("%20s\t", arr[row][i]);
                }else{
                    printf("%20d\t", int(arr[row][i]));
                }
            }
            control = 1;
            break;
        }
    }
    if(control == 0){
        system("CLS");
        puts("\ngirdiginiz ogrenci numarasina sahip bir ogrenci bulunamadi.");
    }
    puts("\n\nonceki menuye donmek icin bir tusa basiniz...");
    getch();
}

int satirbul(){
    FILE *fp = fopen("ogrenciler.txt","r");
    int ch=0;
    int lines=0;

    if (fp == NULL){
    return 0;
    }
    while(!feof(fp)){
        ch = fgetc(fp);
        if(ch == '\n'){
            lines++;
        }
    }
    fclose(fp);
    return lines;
}

void isimsirala(){
    int size;
    size = satirbul();
    void *arr[50][6];
    FILE *myfile;
    int myint;
    myfile = fopen("ogrenciler.txt", "r");
    for(int i = 0; i < size; i++){
        char *isim;
        isim =malloc(sizeof(char)*50);
        fscanf(myfile, "%s", isim);
        arr[i][0] = malloc(strlen(isim)*sizeof(char));
        arr[i][0] = isim;

        char *soyisim;
        soyisim = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", soyisim);
        arr[i][1] = malloc(strlen(soyisim)*sizeof(char));
        arr[i][1] = soyisim;

        fscanf(myfile, "%d", &myint);
        arr[i][2] = malloc(sizeof(int));
        int(arr[i][2]) = myint;

        fscanf(myfile, "%d", &myint);
        arr[i][3] = malloc(sizeof(int));
        int(arr[i][3]) = myint;

        char *mail;
        mail = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", mail);
        arr[i][4] = malloc(strlen(mail)*sizeof(char));
        arr[i][4] = mail;
    }

    void *constarr[50][5];
    for(int i = 0; i < size; i++){
        char *name;
        name =malloc(sizeof(char)*50);
        kopyala(name, arr[i][0]);
        constarr[i][0] = malloc(strlen(name)*sizeof(char));
        constarr[i][0] = name;

        char *surname;
        surname = malloc(sizeof(char)*50);
        kopyala(surname, arr[i][1]);
        constarr[i][1] = malloc(strlen(surname)*sizeof(char));
        constarr[i][1] = surname;


        constarr[i][2] = malloc(sizeof(int));
        int(constarr[i][2]) = int(arr[i][2]);

        constarr[i][3] = malloc(sizeof(int));
        int(constarr[i][3]) = int(arr[i][3]);

        char *mail1;
        mail1 = malloc(sizeof(char)*50);
        kopyala(mail1, arr[i][4]);
        constarr[i][4] = malloc(strlen(mail1)*sizeof(char));
        constarr[i][4] = mail1;
    }

    fclose(myfile);
    for(int i = 0; i < size; i++){
        char *connected;
        connected = malloc(sizeof(char)*100);
        connected = arr[i][0];
        strekle(connected, arr[i][1]);
        arr[i][5] = connected;
    }

    char str[50][100], temp[100];
    for(int i = 0; i < size; i++){
        kopyala(str[i], arr[i][5]);
    }
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(karsilastir(str[i], str[j]) > 0){
                kopyala(temp, str[i]);
                kopyala(str[i], str[j]);
                kopyala(str[j], temp);
            }
        }
    }
    puts("Alfabetik siralanmis liste: ");
    puts("");
    printf("%20s\t%20s\t%20s\t%20s\t%20s\t", "isim", "soyisim", "ogrenci no", "tel no", "email");
    puts("");
    puts("");
    for(int i = 0; i < size; i++){
        for(int row = 0; row < size; row++){
            if(karsilastir(str[i], arr[row][5]) == 0){
                for(int j = 0; j < 5; j++){
                    if(j == 0 || j == 1 || j == 4){
                        printf("%20s\t", constarr[row][j]);
                    }else{
                        printf("%20d\t", int(constarr[row][j]));
                    }
                }
            }
        }
        puts("");
    }

    getch();
}

void ogrencinosirala(){
    int size;
    size = satirbul();
    void *arr[50][5];
    FILE *myfile;
    int myint;
    myfile = fopen("ogrenciler.txt", "r");
    for(int i = 0; i < size; i++){
        char *isim;
        isim =malloc(sizeof(char)*50);
        fscanf(myfile, "%s", isim);
        arr[i][0] = malloc(strlen(isim)*sizeof(char));
        arr[i][0] = isim;

        char *soyisim;
        soyisim = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", soyisim);
        arr[i][1] = malloc(strlen(soyisim)*sizeof(char));
        arr[i][1] = soyisim;

        fscanf(myfile, "%d", &myint);
        arr[i][2] = malloc(sizeof(int));
        int(arr[i][2]) = myint;

        fscanf(myfile, "%d", &myint);
        arr[i][3] = malloc(sizeof(int));
        int(arr[i][3]) = myint;

        char *mail;
        mail = malloc(sizeof(char)*50);
        fscanf(myfile, "%s", mail);
        arr[i][4] = malloc(strlen(mail)*sizeof(char));
        arr[i][4] = mail;
    }
    fclose(myfile);

    int sorted[50],temp;
    for(int i = 0; i < size; i++){
        sorted[i] = int(arr[i][2]);
    }
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(sorted[i]>sorted[j]){
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    void *constarr[50][5];
    for(int i = 0; i < size; i++){
        char *name;
        name =malloc(sizeof(char)*50);
        kopyala(name, arr[i][0]);
        constarr[i][0] = malloc(strlen(name)*sizeof(char));
        constarr[i][0] = name;

        char *surname;
        surname = malloc(sizeof(char)*50);
        kopyala(surname, arr[i][1]);
        constarr[i][1] = malloc(strlen(surname)*sizeof(char));
        constarr[i][1] = surname;


        constarr[i][2] = malloc(sizeof(int));
        int(constarr[i][2]) = int(arr[i][2]);

        constarr[i][3] = malloc(sizeof(int));
        int(constarr[i][3]) = int(arr[i][3]);

        char *mail1;
        mail1 = malloc(sizeof(char)*50);
        kopyala(mail1, arr[i][4]);
        constarr[i][4] = malloc(strlen(mail1)*sizeof(char));
        constarr[i][4] = mail1;
    }

    puts("ogrenci numarasina gore siralanmis liste: ");
    puts("");
    printf("%20s\t%20s\t%20s\t%20s\t%20s\t", "isim", "soyisim", "ogrenci no", "tel no", "email");
    puts("");
    puts("");
    for(int i = 0; i < size; i++){
        for(int row = 0; row < size; row++){
            if(int(arr[row][2]) == sorted[i]){
                for(int j = 0; j < 5; j++){
                    if(j == 0 || j == 1 || j == 4){
                        printf("%20s\t", constarr[row][j]);
                    }else{
                        printf("%20d\t", int(constarr[row][j]));
                    }
                }
            }
        }
        puts("");
    }

    
    getch();
}
