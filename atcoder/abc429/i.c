//2553211 AI°Î ½ªºÆÓî
#include<stdio.h>
#include<math.h>//ÔÚÍøÉÏËÑµÄfloor£¨£©º¯Êı£¬µ«ºÃÏñºÍ£¨int£©Ğ§¹ûÒ»Ñù£¿

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");
	double a, b, c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12;
	scanf("%lf", &a);

	//Ô½ÏòÖĞ¼ä¼ÆËãÔ½¸´ÔÓ£¬¹Ê²ÉÈ¡´ÓÁ½±ß·Ö±ğÏòÖĞ¼ä¼ÆËã£¬ÏÈËã¸ßÎ»
	c12 = floor(a / 1000000000);
	c11 = floor(a / 100000000) - c12 * 10;
	c10 = floor(a / 10000000) - c12 * 100 - c11 * 10;
	c9 = floor(a / 1000000) - c12 * 1000 - c11 * 100 - c10 * 10;
	c8 = floor(a / 100000) - c12 * 10000 - c11 * 1000 - c10 * 100 - c9 * 10;
	c7 = floor(a / 10000) - c12 * 100000 - c11 * 10000 - c10 * 1000 - c9 * 100 - c8 * 10;
	c6 = floor(a / 1000) - c12 * 1000000 - c11 * 100000 - c10 * 10000 - c9 * 1000 - c8 * 100 - c7 * 10;

	b = a * 1000;
	c0 = b - floor(b / 10) * 10;//c0µÄ´æÔÚ¿ÉÒÔ±£Ö¤c1µ½c5ÊÇÍêÈ«×¼È·µÄ£¬Ïû³ıÎó²î
	c1 = (b - c0) / 10 - floor((b - c0) / 100) * 10;
	c2 = (b - c0 - c1 * 10) / 100 - floor((b - c0 - c1 * 10) / 1000) * 10;
	c3 = (b - c0 - c1 * 10 - c2 * 100) / 1000 - floor((b - c0 - c1 * 10 - c2 * 100) / 10000) * 10;
	c4 = (b - c0 - c1 * 10 - c2 * 100 - c3 * 1000) / 10000         //ÕâÀïÒ»¾ä¹ı³¤£¬¹Ê²ğÎªÁ½ĞĞ
		- floor((b - c0 - c1 * 10 - c2 * 100 - c3 * 1000) / 100000) * 10;
	c5 = (b - c0 - c1 * 10 - c2 * 100 - c3 * 1000 - c4 * 10000) / 100000
		- floor((b - c0 - c1 * 10 - c2 * 100 - c3 * 1000 - c4 * 10000) / 1000000) * 10;

	printf("´óĞ´½á¹ûÊÇ:\n");

	switch ((int)c12) {
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
	}
	switch ((int)c11) {
		case 1:
			printf("Ò¼ÒÚ");
			break;
		case 2:
			printf("·¡ÒÚ");
			break;
		case 3:
			printf("ÈşÒÚ");
			break;
		case 4:
			printf("ËÁÒÚ");
			break;
		case 5:
			printf("ÎéÒÚ");
			break;
		case 6:
			printf("Â½ÒÚ");
			break;
		case 7:
			printf("ÆâÒÚ");
			break;
		case 8:
			printf("°ÆÒÚ");
			break;
		case 9:
			printf("¾ÁÒÚ");           //ÒÚÎ»
			break;
	}



	switch ((int)c10) {
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		default:
			if (c12 + c11)
				printf("Áã");
				break;
	}
	switch ((int)c9) {
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		default:
			if (c10&&(c8||c7))

				printf("Áã");
			break;
	}
	switch ((int)c8) {
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		default:
			if (c9&&c7)
				printf("Áã");
			break;
	}
	switch ((int)c7) {
		case 1:
			printf("Ò¼Íò");
			break;
		case 2:
			printf("·¡Íò");
			break;
		case 3:
			printf("ÈşÍò");
			break;
		case 4:
			printf("ËÁÍò");
			break;
		case 5:
			printf("ÎéÍò");
			break;
		case 6:
			printf("Â½Íò");
			break;
		case 7:
			printf("ÆâÍò");
			break;
		case 8:
			printf("°ÆÍò");
			break;
		case 9:
			printf("¾ÁÍò");
			break;
		default:
			if(c12 + c11 + c10 + c9 + c8)
				printf("Íò");                    //ÍòÎ»
			break;
	}



	switch ((int)c6) {
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		default:
			if (c12 + c11 + c10 + c9 + c8 + c7)
				printf("Áã");
			break;
	}
	switch ((int)c5) {
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		default:
			if (c6 && (c4 || c3))

				printf("Áã");
			break;
	}
	switch ((int)c4) {
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		default:
			if (c5 && c3)
				printf("Áã");
			break;
	}
	switch ((int)c3) {
		case 1:
			printf("Ò¼Ô²");
			break;
		case 2:
			printf("·¡Ô²");
			break;
		case 3:
			printf("ÈşÔ²");
			break;
		case 4:
			printf("ËÁÔ²");
			break;
		case 5:
			printf("ÎéÔ²");
			break;
		case 6:
			printf("Â½Ô²");
			break;
		case 7:
			printf("ÆâÔ²");
			break;
		case 8:
			printf("°ÆÔ²");
			break;
		case 9:
			printf("¾ÁÔ²");
			break;
		default:
			if (a == 0)
				printf("ÁãÔ²Õû");
			else
				printf("Ô²");             //¸öÎ»
			break;
	}
	
	

	if (c2 + c1) {
		switch ((int)c2) {
			case 1:
				printf("Ò¼½Ç");
				break;
			case 2:
				printf("·¡½Ç");
				break;
			case 3:
				printf("Èş½Ç");
				break;
			case 4:
				printf("ËÁ½Ç");
				break;
			case 5:
				printf("Îé½Ç");
				break;
			case 6:
				printf("Â½½Ç");
				break;
			case 7:
				printf("Æâ½Ç");
				break;
			case 8:
				printf("°Æ½Ç");
				break;
			case 9:
				printf("¾Á½Ç");
				break;
			default:
				if (c12 + c11 + c10 + c9 + c8 + c7 + c6 + c5 + c4 + c3)
					printf("Áã");
				break;
		}
		switch ((int)c1) {
			case 1:
				printf("Ò¼·Ö\n");
				break;
			case 2:
				printf("·¡·Ö\n");
				break;
			case 3:
				printf("Èş·Ö\n");
				break;
			case 4:
				printf("ËÁ·Ö\n");
				break;
			case 5:
				printf("Îé·Ö\n");
				break;
			case 6:
				printf("Â½·Ö\n");
				break;
			case 7:
				printf("Æâ·Ö\n");
				break;
			case 8:
				printf("°Æ·Ö\n");
				break;
			case 9:
				printf("¾Á·Ö\n");
				break;
			default:
				printf("Õû\n");
				break;
		}

	}
	else if(a)
		printf("Õû\n");              //·Ö¡¢½Ç

	return 0;
}