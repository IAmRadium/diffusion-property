//Author: Md Rasid Ali, 
//Reference paper:https://eprint.iacr.org/2015/873.pdf

#include<stdio.h>
#define sbox_len 4
#define input_len 4
#define output_len 4

char f[]={0xc,0x5,0x6,0xb,0x9,0x0,0xa,0xd,0x3,0xe,0xf,0x8,0x4,0x7,0x1,0x2};

//char f[]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};

int check(char e_i,char i,char j){
	char count=0; 	
	for(char x=0;x<sbox_len*sbox_len;x++){
		if((((f[x]^f[x^e_i])&e_i)>>i)==1)
			count+=1;
	}
	return count;
}

int main(){
	char values[sbox_len][sbox_len],e_i;
	for(char i=0;i<input_len;i++){
		e_i=1<<i;
		for(char j=0;j<output_len;j++){
			values[i][j]=check(e_i,i,j);
		}
	}
	printf("Printing the count matrix:\n\n");
	int sum=0;	
	for(int i=0;i<input_len;i++){
		for(int j=0;j<output_len;j++){
			printf("%d ",values[i][j]);
			if(values[i][j]==0) sum++;
		}
		printf("\n");
	}
	float D_c=1-(double)sum/(input_len*output_len);
	printf("\nRequired D_c= %f\n",D_c);
	
	return 0;
}
