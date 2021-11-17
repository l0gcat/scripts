#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {

	if ( argc != 4 ) {
		printf("\n[!] not enough arguments\n");
		printf("usage : %s from to len\n", argv[0]);
		printf("        %s 0 10 3", argv[0]);
		return 1;
	
	} else {
		int from = atoi(argv[1]);
		int to = atoi(argv[2]);
		int len = atoi(argv[3]);
		char istr[12];

		for( int i = from; i < to+1; i++) {
			
			sprintf(istr, "%d", i);
			
			if ( strlen(istr) != len ) {
				
				switch ( len - strlen(istr) ) {
					case 1:
						printf("%s%s\n", "0", istr);
						break;
					case 2:
						printf("%s%s\n", "00", istr);
						break;
					case 3:
						printf("%s%s\n", "000", istr);
						break;
					case 4:
						printf("%s%s\n", "0000", istr);
						break;
					case 5:
						printf("%s%s\n", "00000", istr);
						break;
					case 6:
						printf("%s%s\n", "000000", istr);
						break;
					case 7:
						printf("%s%s\n", "0000000", istr);
						break;
					case 8:
						printf("%s%s\n", "00000000", istr);
						break;
					case 9:
						printf("%s%s\n", "000000000", istr);
						break;
					case 10:
						printf("%s%s\n", "0000000000", istr);
						break;
					case 11:
						printf("%s%s\n", "00000000000", istr);
						break;
					case 12:
						printf("%s%s\n", "000000000000", istr);
						break;
				}
			} else {
				printf("%d\n", i);
			}
		}
		return 0;
	}
}
