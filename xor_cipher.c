/* A very simple and little example of a XOR Cipher 

	Juan Carlos Lanuza L. - MGA - 2016
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i,key;
	char c_string[64],xor_string[64];
	printf("String:");
		gets(c_string);
	while(strlen(c_string) > 64 )
	{
		puts("Sorry, the max value is 64 characteres, try again with a more short string");
		printf("String: ");
			scanf("%s",c_string);
	}
	printf("XOR Key (0 - 255):");
		scanf("%d",&key);
	while(key < 0 || key > 255)
	{
		puts("The Max values for the key in this case of implementation is (0 - 255)\n");
		printf("XOR Key: ");	
		scanf("%d",key);	
	}			
	for(i = 0; i <= strlen(c_string); i++)
	{
		xor_string[i] = (char)((int)c_string[i] ^ key);	
	}	
	puts("");
	puts("");
	puts("------------------------------------");
	printf("Current String: %s\n\n",c_string);
	printf("Ciphered String: %s\n\n",xor_string);
	printf("Ciphered String HEX: %X\n\n",xor_string);
	puts("------------------------------------");
exit(EXIT_SUCCESS); /* only for OS, no valid for Microcontrolers or Microprocessors*/
}
