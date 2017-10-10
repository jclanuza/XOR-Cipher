/* A very simple and little example of a XOR Cipher 
	Juan Carlos Lanuza L. - MGA - 2016
*/
#include <stdio.h>
#include <string.h>

unsigned xorcipher(char *xor_string,unsigned key);

int main(int argc, char** argv)
{
	unsigned key;
	char c_string[64];
	
	printf("String:");
	gets(c_string);
	fprintf(stdout,"XOR Key (0 - 255):");
	scanf("%d",&key);		
	xorcipher(c_string,key);
	return 0;
}

unsigned xorcipher(char *c_string,unsigned key)
{
	char xor_string[64];
	for(int i = 0;i <= strlen(c_string);i++)
	{
		xor_string[i] = (char)((int)c_string[i] ^ key);	
	}	
	fprintf(stdout,
			"\n------------------------------------\n"
			"Current String: %s\n"
			"XOR Key: %d\n"
			"Ciphered String: %s\n"
			"Ciphered String HEX: %X\n"
			"------------------------------------\n"
			,c_string,key,xor_string,xor_string
			);
	return 0;	
}
