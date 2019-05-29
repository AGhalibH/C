#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

//Motor=1;
//Mobil=2;
//Truk =3;

int tipe_kendaraan, tempat_parkir_motor = 100, tempat_parkir_mobil = 50, tempat_parkir_truk = 25;
int tarif_motor_1jam_pertama = 2000, tarif_mobil_1jam_pertama = 3000, tarif_truk_1jam_pertama = 4000;
int tarif_motor_1jam_berikut = 1000, tarif_mobil_1jam_berikut = 2000, tarif_truk_1jam_berikut = 3000;
int total_1jam_pertama = 1, total_jam_berikutnya, biaya_parkir;
int jam_masuk, menit_masuk, hari_masuk;
int jam_keluar, menit_keluar, hari_keluar;
int total_jam, total_menit, total_hari, temp_total_jam1, temp_total_jam2, temp_total_jam3;
int body(), biaya_parkir_motor(), biaya_parkir_mobil(), biaya_parkir_truk();
int display_motor(), display_mobil(), display_truk();
int masuk(), keluar(), o_masuk(), o_keluar(), k;
int tipe_kendaraan0(), tipe_kendaraan1(), tipe_kendaraan2(), tipe_kendaraan3(), tipe_kendaraan4();
int error_menu3();
int time();

int main (){
fullscreen();
remove_scrollbar();
system("COLOR 9F");
printf("................................................................................................................................................................................................................................................\n");

printf("..............................................................................................................:*#@@@######@@@#*:................................................................................................................\n");

printf(".........................................................................................................:#@#+-................-*#@=-...........................................................................................................\n");

printf("......................................................................................................+@#:...:*#@=....##:@=...+*-...+##+........................................................................................................\n");

printf("...................................................................................................-##:......+@*:@*...@#@=...-@=....+..+@=-.....................................................................................................\n");

printf(".................................................................................................:@=...=*.....=@@@=..-@@@=...#@-..:@@+::.-##-...................................................................................................\n");

printf("................................................................................................##-...:@#@#-..-@=-@#.:@**@:.+@+..=@#*=@:...-@=..................................................................................................\n");

printf("..............................................................................................:@+......-@=:@@+.*@++=:-+--**-@#.-@#*#@#.......*@-................................................................................................\n");

printf("................................................................................:#############@-.:@@#+..-#@#:#*...:+**==**+:...++:@@+...*@@@=.:@#############-..................................................................................\n");

printf("................................................................................+@-:::::::::*@-.*@#::@#...##-.-*==============*:..*-.+@@=--#@-.:@*::::::::::@-..................................................................................\n");

printf("................................................................................+@-=========@-....:#@@+.....:====================+..#@::@@--....:@========*:@-..................................................................................\n");

printf("................................................................................+@-========@+........:#@#.-*======*********========-.+@#:........=#=======*:@-..................................................................................\n");

printf("................................................................................+@-=======##.............-========:...---....-======:............-@=======*:@-..................................................................................\n");

printf("................................................................................+@-=======#*...------....*========:..:=====:..-======-....----....=#======*:@-..................................................................................\n");

printf("................................................................................+@-=======@:.*+......*:.:=========:..:=====:..-======:.+-......+-.*#======*:@-..................................................................................\n");

printf("................................................................................+@-=======@::WWWWWWWWWW-:=========:..-+++:-...*======+:@#WWWWW@##.+@======*:@-..................................................................................\n");

printf("................................................................................+@-=======@:+##W####W##::=========:..----::+=========+:==@===*@=*-*#======*:@-..................................................................................\n");

printf("................................................................................+@-=======#*.@+...-..*@..*========:..:===============-.@+......=#.=#======*:@-..................................................................................\n");

printf("................................................................................+@-=======##.............-========:..:==============:............-@=======*:@-..................................................................................\n");

printf("................................................................................+@-========@+.............-=======++++=============:.............*#=======*:@-..................................................................................\n");

printf("................................................................................+@-=========@-.........:*:..+====================*.-=*-.........:@========*:@-..................................................................................\n");

printf("................................................................................+@-=========##.......+@=:@+...:*===============:...##----......-@=========*:@-..................................................................................\n");

printf("................................................................................+@+++++++++++#@-..:@-=@+.-.#=....-:**=====*:-...=@=.+@@@#@#-..:@=++++++++++*@-..................................................................................\n");

printf("..............................................................................................+@:.#@#@=...=#=@*-**-.......-+:=@@:##@-..:@#@:.*@:................................................................................................\n");

printf("...............................................................................................-##.......+@#:.-@**@.@@@@.#@*:.*@#=#*@:.....-#=..................................................................................................\n");

printf(".................................................................................................:@=....=@:...-@@:...##..+@#@-.:@*#@:@*..-##-...................................................................................................\n");

printf("...................................................................................................:##-.:....:*-@#...##...@=....-@=+*..:@#-.....................................................................................................\n");

printf("......................................................................................................*@#:...+@@@:...#=...*@@@:.....:#@+........................................................................................................\n");

printf(".........................................................................................................+#@=+-......++....-...-+#@=:...........................................................................................................\n");

printf(".............................................................................................................-+=#@@@#===##@@@#*:................................................................................................................\n");

printf("................................................................................................................................................................................................................................................\n\n");


printf("\t\t\t\t\t\t\t\t\t\t\t\t\t      MALL PARKING SYSTEM\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t    Oleh :\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\tIdham Ramadito\t\t NPM : 1806200293\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t\tAditya Ghalib Hendryan\t NPM : 1806148630\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
system("pause");
system("cls");
	menu:			//Menu 1
	body();
	switch(tipe_kendaraan)
	{
		case 0 :
			exit (0);
			break;
		case 1:
			tipe_kendaraan1();
			break;
		case 2:
			tipe_kendaraan2();
			break;
		case 3:
			tipe_kendaraan3();
			break;
		case 4:
			system("cls");
			printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t HELP");
			printf("\n\n\t\t 1. Pilih menu sesuai dengan tipe kendaraan anda");
			printf("\n\n\t\t 2. Anda akan mendapatkan nomor parkir");
			printf("\n\n\t\t 3. Masukkan nomor parkir dan anda akan mendapatkan lokasi parkir kendaraan anda");
			printf("\n\n\t\t 4. Saat ingin keluar input waktu masuk dan keluar dengan menginput jam masuk kemudian menitnya, dan jam keluar kemudian menitnya");
			printf("\n\n\t\t 5. Input waktu masuk dan keluar dengan menginput jam masuk kemudian menitnya, dan jam keluar kemudian menitnya");
			printf("\n\n\t\t 6. Input waktu dengan format 00:00 sampai 24:00");
			printf("\n\n\t\t 7. Anda tidak dapat menginput waktu masuk dan keluar pada jam yang sama, jika anda parkir kurang dari satu jam biaya parkir dihitung satu jam");
			printf("\n\n\t\t 8. Contoh input waktu bila parkir kurang dari satu jam : input masuk 03.00 input waktu keluar menjadi 04.00 walaupun parkir kurang dari satu jam");
			printf("\n\n\t\t 9. TIDAK DIPERBOLEHKAN MENGINAPKAN KENDARAAN ANDA\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
			system("pause");
			system("cls");
			return body();
			break;
		default:
			system("cls");
			printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  TIDAK ADA MENU PILIHAN TERSEBUT\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
			system ("pause");
			system ("cls");
			getchar ();
			return body();
			break;
	}
}

//Main Body
int body()
{
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t      MALL PARKING SYSTEM\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 1. Motor ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 2. Mobil ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 3. Truk ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 4. Help ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t 0. Exit ");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t Pilih menu : ");
	
	scanf("%d", &tipe_kendaraan);
}

//Menu Motor
int tipe_kendaraan1()
{
	system("cls");
	display_motor();	//Menu 2
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	menu3_motor:		//Menu 3
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| KENDARAAN MOTOR                  |");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	/*Jam Masuk*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Masuk Motor : ");
	masuk();
	
	/*Jam Keluar*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Keluar Motor : ");
	keluar();
	
	/*Error Menu 3*/
	error_menu3();
	
	temp_total_jam1=jam_keluar-jam_masuk;	
	if(temp_total_jam1<=0 || temp_total_jam1>=24)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t PEMASUKKAN JAM MASUK ATAU KELUAR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu3_motor;
	} else if(k==0)
	{
		system("cls");
		goto menu3_motor;
	} else
	{
		/*Overview Total Waktu*/
		//Masuk
		o_masuk();
	
		//Keluar
		o_keluar();
		/*Biaya Parkir Motor*/
		biaya_parkir_motor();
		system("pause");
		system("cls");
		return main();
	}
}

//Menu Mobil
int tipe_kendaraan2()
{
	system("cls");
	display_mobil();	//Menu 2
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	menu3_mobil:		//Menu 3
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| KENDARAAN MOBIL                  |");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	
	/*Jam Masuk*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Masuk Mobil :");
	masuk();
	
	/*Jam Keluar*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Keluar Mobil :");
	keluar();
	
	/*Error Menu 3*/
	error_menu3();
	
	temp_total_jam2=jam_keluar-jam_masuk;
	if(temp_total_jam2<=0 || temp_total_jam2>=24)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t PEMASUKKAN JAM MASUK ATAU KELUAR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu3_mobil;
	} else if(k==0)
	{
		system("cls");
		goto menu3_mobil;
	} else
	{
		/*Overview Total Waktu*/
		//Masuk
		o_masuk();
	
		//Keluar
		o_keluar();
		
		/*Biaya Parkir Mobil*/
		biaya_parkir_mobil();
		system("pause");
		system("cls");
		return main();
	}
}

//Menu Truk
int tipe_kendaraan3()
{
	system("cls");
	display_truk();		//Menu 2
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	menu3_truk:			//Menu 3
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| KENDARAAN TRUK                  |");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==================================+");
	
	/*Jam Masuk*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Masuk Truk :");
	masuk();
	
	/*Jam Keluar*/
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tJam Keluar Truk :");
	keluar();
	
	/*Error Menu 3*/
	error_menu3();
	
	temp_total_jam3=jam_keluar-jam_masuk;
	if(temp_total_jam3<=0 || temp_total_jam3>=24)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t PEMASUKKAN JAM MASUK ATAU KELUAR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu3_truk;
	} else if(k==0)
	{
		system("cls");
		goto menu3_truk;
	} else
	{
		/*Overview Total Waktu*/
		//Masuk
		o_masuk();
		
		//Keluar
		o_keluar();
		
		/*Biaya Parkir Truk*/
		biaya_parkir_truk();
		system("pause");
		system("cls");
		return main();
	}	
}

//Modular Display Motor
int display_motor()
{
	int motor[100]={0}, counter1, kolom1, baris=0, nomor_parkir1, kode_kolom1, temp_kolom1, temp_baris1, motor_acak, input_nomor_parkir1;
	time_t t;
	char huruf[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, kode_baris1;
	//Nomor Parkir Acak
	menu2_motor:
	srand((unsigned) time(&t));
	nomor_parkir1=(rand()%100)+1;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+===============================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| Nomor Parkir Motor Anda = %d  |", nomor_parkir1);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+===============================+\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Masukkan Nomor Parkir = ");
	scanf("%d", &input_nomor_parkir1);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	if(input_nomor_parkir1!=nomor_parkir1)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     PEMASUKKAN NOMOR PARKIR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu2_motor;
	}
	//Penempatan Motor Secara Acak Dengan Terdapat Motor Lainnya
	for (motor_acak=0; motor_acak<=100; motor_acak++)
	{
		motor[motor_acak]=(rand()%2);
	}
	motor[nomor_parkir1-1]=1;
	//Kode Tempat Parkir
	kode_kolom1=nomor_parkir1%10;
	temp_baris1=nomor_parkir1/10;
	temp_kolom1=nomor_parkir1/10;
	if(kode_kolom1==0)
	{
		kode_kolom1=nomor_parkir1/temp_kolom1;
	}
	if(temp_baris1==10 || temp_baris1==20 || temp_baris1==30 || temp_baris1==40 || temp_baris1==50 || temp_baris1==60 || temp_baris1==70 || temp_baris1==90 || temp_baris1==100)
	{
		kode_baris1=huruf[temp_baris1-1];
	} else if(temp_baris1!=10 || temp_baris1!=20 || temp_baris1!=30 || temp_baris1!=40 || temp_baris1!=50 || temp_baris1!=60 || temp_baris1!=70 || temp_baris1!=90 || temp_baris1!=100)
	{
		kode_baris1=huruf[temp_baris1];
	} 
	else if(temp_baris1<1)
	{
		kode_baris1=huruf[0];
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Kode Tempat Parkir   = %c%d", kode_baris1, kode_kolom1);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
	//Kolom
	for(kolom1=1; kolom1<=10; kolom1++)
	{
		printf("|_%d_", kolom1);
		if(kolom1==10)
		{
			printf("|___", kolom1);
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
	//Tempat Parkir
	for(counter1=0; counter1<100; counter1++)
	{
		if(counter1==nomor_parkir1-1)
		{
			printf("|[%d]", motor[nomor_parkir1-1]);
		} else 
		{
			printf("| %d ", motor[counter1]);
		}
		if(counter1==9 || counter1==19 || counter1==29 || counter1==39 || counter1==49 || counter1==59 || counter1==69 || counter1==79 || counter1==89 || counter1==99)
		{
			printf(" | %c", baris[huruf]);
			baris+=1;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
		}
	}
}

//Modular Display mobil
int display_mobil()
{
	int mobil[50]={0}, counter2, kolom2, baris2=0, nomor_parkir2, kode_kolom2, temp_kolom2, temp_baris2, mobil_acak, input_nomor_parkir2;
	time_t t;
	char huruf[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, kode_baris2;
	//Nomor Parkir Acak
	menu2_mobil:
	srand((unsigned) time(&t));
	nomor_parkir2=(rand()%50)+1;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+===============================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| Nomor Parkir Mobil Anda = %d  |", nomor_parkir2);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+===============================+\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Masukkan Nomor Parkir = ");
	scanf("%d", &input_nomor_parkir2);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	if(input_nomor_parkir2!=nomor_parkir2)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     PEMASUKKAN NOMOR PARKIR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu2_mobil;
	}
	//Penempatan Mobil Secara Acak Dengan Terdapat Mobil Lainnya
	for (mobil_acak=0; mobil_acak<=50; mobil_acak++)
	{
		mobil[mobil_acak]=(rand()%2);
	}
	mobil[nomor_parkir2-1]=1;
	//Kode Tempat Parkir
	kode_kolom2=nomor_parkir2%10;
	temp_kolom2=nomor_parkir2/10;
	if(kode_kolom2==0)
	{
		kode_kolom2=nomor_parkir2/temp_kolom2;
	}
	if(input_nomor_parkir2>=1 && input_nomor_parkir2<=10)
	{
		kode_baris2=huruf[0];
	} else if(input_nomor_parkir2>=11 && input_nomor_parkir2<=20)
	{
		kode_baris2=huruf[1];
	} else if(input_nomor_parkir2>=21 && input_nomor_parkir2<=30)
	{
		kode_baris2=huruf[2];
	} else if(input_nomor_parkir2>=31 && input_nomor_parkir2<=40)
	{
		kode_baris2=huruf[3];
	} else if(input_nomor_parkir2>=41 && input_nomor_parkir2<=50)
	{
		kode_baris2=huruf[4];
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Kode Tempat Parkir   = %c%d", kode_baris2, kode_kolom2);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t");
	//Kolom
	for(kolom2=1; kolom2<=10; kolom2++)
	{
		printf("|_%d_", kolom2);
		if(kolom2==10)
		{
			printf("|___", kolom2);
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
	//Tempat Parkir
	for(counter2=0; counter2<50; counter2++)
	{
		if(counter2==nomor_parkir2-1)
		{
			printf("|[%d]", mobil[nomor_parkir2-1]);
		} else 
		{
			printf("| %d ", mobil[counter2]);
		}
		if(counter2==9 || counter2==19 || counter2==29 || counter2==39 || counter2==49)
		{
			printf(" | %c", baris2[huruf]);
			baris2+=1;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t\t");
		}
	}
}

//Modular Display truk
int display_truk()
{
	int truk[25]={0}, counter3, kolom3, baris3=0, nomor_parkir3, kode_kolom3, temp_kolom3, temp_baris3, truk_acak, temp_nomor_parkir3, input_nomor_parkir3;
	time_t t;
	char huruf[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}, kode_baris3;
	//Nomor Parkir Acak
	menu2_truk:
	srand((unsigned) time(&t));
	nomor_parkir3=(rand()%25)+1;
	temp_nomor_parkir3=nomor_parkir3;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==============================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t| Nomor Parkir Truk Anda = %d  |", nomor_parkir3);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t+==============================+\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t");
	system("pause");
	system("cls");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Masukkan Nomor Parkir = ");
	scanf("%d", &input_nomor_parkir3);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	if(input_nomor_parkir3!=nomor_parkir3)
	{
		system("cls");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tERROR!");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     PEMASUKKAN NOMOR PARKIR SALAH\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t     ");
		system("pause");
		system("cls");
		goto menu2_truk;
	}
	//Penempatan Truk Secara Acak Dengan Terdapat Truk Lainnya
	for (truk_acak=0; truk_acak<=25; truk_acak++)
	{
		truk[truk_acak]=(rand()%2);
	}
	truk[temp_nomor_parkir3-1]=1;
	//Kode Tempat Parkir
	kode_kolom3=nomor_parkir3%10;
	if(kode_kolom3==0)
	{
		kode_kolom3+=5;
	} else if(kode_kolom3>5)
	{
		kode_kolom3-=5;
	}
	if (nomor_parkir3>=1 && nomor_parkir3<=5)
	{
		kode_baris3=huruf[0];
	} else if (nomor_parkir3>=6 && nomor_parkir3<=10)
	{
		kode_baris3=huruf[1];
	} else if (nomor_parkir3>=11 && nomor_parkir3<=15)
	{
		kode_baris3=huruf[2];
	} else if (nomor_parkir3>=16 && nomor_parkir3<=20)
	{
		kode_baris3=huruf[3];
	} else if (nomor_parkir3>=21 && nomor_parkir3<=25)
	{
		kode_baris3=huruf[4];
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t           Kode Tempat Parkir   = %c%d", kode_baris3, kode_kolom3);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t+==============================================+");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
	//Print Tabel Kolom
	for(kolom3=1; kolom3<=5; kolom3++)
	{
		printf("|_%d_", kolom3);
		if(kolom3==5)
		{
			printf("|___", kolom3);
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
	//Tempat Parkir
	for(counter3=0; counter3<25; counter3++)
	{
		if(counter3==nomor_parkir3-1)
		{
			printf("|[%d]", truk[nomor_parkir3-1]);
		} else 
		{
			printf("| %d ", truk[counter3]);
		}
		if(counter3==4 || counter3==9 || counter3==14 || counter3==19 || counter3==24)
		{
			printf("| %c", baris3[huruf]); //Tabel Baris
			baris3+=1;
			printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t  ");
		}
	}
}

//Jam Masuk
int masuk()
{
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tMasukkan Jam Masuk    (0 - 23)  = ");
	scanf("%d", &jam_masuk);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tMasukkan Menit Masuk  (0 - 59)  = ");
	scanf("%d", &menit_masuk);
}

//Jam Keluar
int keluar()
{
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tMasukkan Jam Keluar   (0 - 23)  = ");
	scanf("%d", &jam_keluar);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tMasukkan Menit Keluar (0 - 59)  = ");
	scanf("%d", &menit_keluar);
}

//Overview Masuk
int o_masuk()
{
	if(jam_masuk>=0 && jam_masuk<=9)
	{
		if(menit_masuk>=0 && menit_masuk<=9)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Masuk  = 0%d:0%d ", jam_masuk, menit_masuk);
		} else if(menit_masuk>=10 && menit_masuk<=59)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Masuk  = 0%d:%d ", jam_masuk, menit_masuk);
		}
	} else if(jam_masuk>=10 && jam_masuk<=23)
	{
		if(menit_masuk>=0 && menit_masuk<=9)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Masuk  = %d:0%d ", jam_masuk, menit_masuk);
		} else if(menit_masuk>=10 && menit_masuk<=59)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Masuk  = %d:%d ", jam_masuk, menit_masuk);
		}
	}
	
}

//Overview Keluar
int o_keluar()
{
	if(jam_keluar>=0 && jam_keluar<=9)
	{
		if(menit_keluar>=0 && menit_keluar<=9)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Keluar = 0%d:0%d ", jam_keluar, menit_keluar);
		} else if(menit_keluar>=10 && menit_keluar<=59)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Keluar = 0%d:%d ", jam_keluar, menit_keluar);
		}
	} else if(jam_keluar>=10 && jam_keluar<=23)
	{
		if(menit_keluar>=0 && menit_keluar<=9)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Keluar = %d:0%d ", jam_keluar, menit_keluar);
		} else if(menit_keluar>=10 && menit_keluar<=59)
		{
			printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tWaktu Keluar = %d:%d ", jam_keluar, menit_keluar);
		}
	}
}

//Biaya Parkir Motor
int biaya_parkir_motor()
{
	total_jam = jam_keluar-jam_masuk;
	total_menit = menit_keluar-menit_masuk;
	if(total_menit<0)
	{
		total_jam-=1;
	}
	total_jam_berikutnya = total_jam - total_1jam_pertama;
	
	if (total_hari==0)
	{
		biaya_parkir = (total_1jam_pertama * tarif_motor_1jam_pertama) + (total_jam_berikutnya * tarif_motor_1jam_berikut);
	} else
	{
		biaya_parkir = (total_1jam_pertama * tarif_motor_1jam_pertama) + (total_jam_berikutnya * tarif_motor_1jam_berikut);
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBiaya Parkir = %d + %d = %d\n", (total_1jam_pertama * tarif_motor_1jam_pertama), (total_jam_berikutnya * tarif_motor_1jam_berikut), biaya_parkir);
}

//Biaya Parkir Mobil
int biaya_parkir_mobil()
{
	total_jam = jam_keluar-jam_masuk;
	total_menit = menit_keluar-menit_masuk;
	if(total_menit<0)
	{
		total_jam-=1;
	}
	total_jam_berikutnya = total_jam - total_1jam_pertama;
	
	if (total_hari==0)
	{
		biaya_parkir = (total_1jam_pertama * tarif_mobil_1jam_pertama) + (total_jam_berikutnya * tarif_mobil_1jam_berikut);
	} else
	{
		biaya_parkir = (total_1jam_pertama * tarif_mobil_1jam_pertama) + (total_jam_berikutnya * tarif_mobil_1jam_berikut);
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBiaya Parkir = %d + %d = %d\n", (total_1jam_pertama * tarif_mobil_1jam_pertama), (total_jam_berikutnya * tarif_mobil_1jam_berikut), biaya_parkir);
}

//Biaya Parkir Truk
int biaya_parkir_truk()
{
	total_jam = jam_keluar-jam_masuk;
	total_menit = menit_keluar-menit_masuk;
	if(total_menit<0)
	{
		total_jam-=1;
	}
	total_jam_berikutnya = total_jam - total_1jam_pertama;
	
	if (total_hari==0)
	{
		biaya_parkir = (total_1jam_pertama * tarif_truk_1jam_pertama) + (total_jam_berikutnya * tarif_truk_1jam_berikut);
	} else
	{
		biaya_parkir = (total_1jam_pertama * tarif_truk_1jam_pertama) + (total_jam_berikutnya * tarif_truk_1jam_berikut);
	}
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tBiaya Parkir = %d + %d = %d\n", (total_1jam_pertama * tarif_truk_1jam_pertama), (total_jam_berikutnya * tarif_truk_1jam_berikut), biaya_parkir);
}

//Error Menu 3
int error_menu3()
{
	if(jam_masuk<0 || jam_masuk>23)
		{
			k=0;
		} else if(menit_masuk<0 || menit_masuk>59)
		{
			k=0;
		} else if(jam_keluar<0 || jam_keluar>23)
		{
			k=0;
		} else if(menit_keluar<0 || menit_keluar>59)
		{
			k=0;
		} else
		{
			k=1;
		}
}
//End of Program

