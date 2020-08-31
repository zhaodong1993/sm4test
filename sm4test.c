#include<stdio.h>
#include"sm4.h"
#define DATALEN 100
#define INPUT_FILE "./plain.txt" 
#define OUTPUT_FILE "./plain_new.txt"

int main ()
{
	FILE *fp=fopen(INPUT_FILE,"r") ;
	if(fp==NULL)
	{
	printf("open file failed!\n") ;
	return -1 ;
	}
	unsigned char key[16]={0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01} ;
	unsigned char iv[16] ={0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01} ;
	
	unsigned char input[DATALEN] ;
	unsigned char output[DATALEN] ;
	sm4_context ctx ;
	
	int i=0 ;
	
	for(i;i<DATALEN;i++)
	{
		if(fscanf(fp,"%x ",&input[i])==EOF)
			break ;
	}
	
	
	int datalen=i ;
	
	printf("input:\n") ;
	for(i=0;i<datalen;i++)
	printf("%02x ",input[i]) ;
	printf("\n") ;
	

	//encrypt
	sm4_setkey_dec(&ctx,key) ;
	sm4_crypt_cbc(&ctx,0,datalen,iv,input,output) ;
	printf("output:\n") ;
	for(i=0;i<datalen;i++)
        printf("%02x ",output[i]) ;

	FILE *fp_new ;

	if((fp_new=fopen(OUTPUT_FILE,"w"))==NULL)
	{
		printf("creat plain_new.txt filed!\n") ;
	}
	printf("\n") ;

	for(i=0;i<datalen;i++)
	{
		fprintf(fp_new,"%02x ",output[i]) ;
	}

	
	fclose(fp) ;
	fclose(fp_new) ;
	return 0 ;
}
