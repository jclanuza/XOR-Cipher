#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

/* Error codes */
#define ERR_PWD -1
#define	ERRF_SF -2
#define ERRF_DF -3

FILE *scr_file, *dst_file;
char sfile[100],dfile[100];
static int32_t unencrypted,encrypted;
static int32_t k[16] = {0xFF};	

static void encryptdecrypt(void);
static void report(int32_t source_file_bytes, int32_t output_file_bytes, float data_loss);

unsigned int main(void)
{
	fprintf(stdout,"Archivo a Cifrar o Decifrar: "); 
	gets(sfile);
	fprintf(stdout,"Archivo de Salida: "); 
	gets(dfile);
	encryptdecrypt();
	system("pause");
	exit(EXIT_SUCCESS);
}

static void encryptdecrypt(void)
{
	if(k == '\0') 
	{ 
		fprintf(stderr,"Es necesaria una clave\n"); 
		exit(ERR_PWD); 
	}
	else
	if((scr_file = fopen(sfile, "rb")) == NULL ) 
	{
		fprintf(stderr,"\n\n%s : Archivo Inexistente o fallo su apertura\n\a",sfile);
		exit(ERRF_SF);
	}
	else
	if((dst_file = fopen(dfile, "wb")) == NULL)
	{
		fprintf(stderr,"\n\n%s : Archivo Inexistente o fallo su apertura\n\a",dfile);
		exit(ERRF_DF);		
	}
	while ((unencrypted = getc(scr_file)) != EOF) 
	{
		encrypted = (unencrypted ^ k[0]);
		encrypted &= k[0];
		putc(encrypted,dst_file);
	}
	/* Determina el tamaño del Archivo */
	fseek(scr_file, 0L, SEEK_END);
  	fseek(dst_file, 0L, SEEK_END);
  	report(ftell(scr_file),ftell(dst_file),(((float)ftell(dst_file) / (float)ftell(scr_file)) * 100));
	
	fclose(dst_file);
	fclose(scr_file);
}

static void report(int32_t sc_fbytes, int32_t dst_fbytes, float d_loss)
{
	fprintf(stdout,"\n\nArchivo Original: %s | Size: %.2f KB\n"
				   "Archivo Cifrado: %s | Size: %.2f KB\n"
				   "Perdida durante Cifrado: %.2f %c\n"
				   "Mecanismo de Cifrado: XOR\n"
				   "Clave Utilizada: %X\n\n"
	,sfile,((float)sc_fbytes / 1024),dfile,((float)dst_fbytes / 1024),(d_loss - 100),(char)37,k[0]);
}
