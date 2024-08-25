#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <global.h>
#include <rsaref.h>


int n(int nLen)
{
	if(nLen < 16) return 2;
	else if(nLen < 24) return 3;
	else return 4;
}


int main()
{
	unsigned char szName[101] = {0};
	unsigned char szCipher[101] = {0};
	unsigned char iv[48] = {0};
	unsigned char szResult[101] = {0};
	unsigned char szKey[] = "FBHtfaKFukbeSfDCCMhuslTASPODHNarnkcufhaolmeopDVYUsvF";
	unsigned char szAppend[] = "RBJKDgvjjnlASSXIOLMSBAFVTHOLASRaumftbsagmlpfbnyJJ7W";
	unsigned char szConvert[] = "hvSRvVennVkOQfaQiDFCplnHLlnmIjsAYHNCIFlYVaGcGtSDS3VWGFGGRSVGKmGoP";
	register int i, nLen, x;
	DES_CBC_CTX des_Context;

	printf("Accurate Burn v1.16 Keygen\n\n");
	printf("Enter your name : ");
	gets(szName);
	nLen = strlen(szName);
	if(nLen > 0 && nLen <= 31)
	{
		for(i = 0; i < nLen; i++)
			szAppend[i] = szName[i];
		if(nLen < 9)
			for(i = 9; i < 9+nLen; i++)
				szAppend[i] = szName[i-9];
		x = n(nLen);
		for(i = 0; i < x; i++)
		{
			DES_CBCInit(&des_Context, szKey+i*8, iv, 1); 
			DES_CBCUpdate(&des_Context, szCipher+i*8, szAppend+i*8, 8);
		}
		x *= 8;
		for(i = 0; i < x; i++)
			szResult[i] = szConvert[szCipher[i]%62];
		memset(&des_Context, 0, sizeof(des_Context));
		printf("\nYour registration code is : %s", szResult);
	}
	else printf("Please enter between 1 and 31 chars.");
	printf("\nPress enter to exit");
	getch();
	return 0;

}