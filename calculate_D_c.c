//Author: Md Rasid Ali, 
//Reference paper:https://eprint.iacr.org/2015/873.pdf

#include<stdio.h>
#include<math.h>
#define input_len 6
#define output_len 8

//PRESENT input_len 4, output_len 4
//char f[]={0xc,0x5,0x6,0xb,0x9,0x0,0xa,0xd,0x3,0xe,0xf,0x8,0x4,0x7,0x1,0x2};

//DES
//char input_len 6 output_len 4 f[]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};

//TWIS   input_len 6, output_len 8
//char f[]={0x90,0x49,0xd1,0xc6,0x2f,0x33,0x74,0xfb,0x95,0x6d,0x82,0xea,0x0e,0xb0,0xa8,0x1c,0x28,0xd0,0x4b,0x92,0x5c,0xee,0x85,0xb1,0xc4,0x0a,0x76,0x3d,0x63,0xf9,0x17,0xaf,0xbf,0xbf,0x19,0x65,0xf7,0x7a,0x32,0x20,0x16,0xce,0xe4,0x83,0x9d,0x5b,0x4c,0xd8,0xee,0x99,0x2e,0xf8,0xd4,0x9b,0x0f,0x13,0x29,0x89,0x67,0xcd,0x71,0xdd,0xb6,0xf4};

//

int check(char func_val[(int)pow(2,input_len)][output_len], char e_i,char j){
	char count=0; 	
	for(char x=0;x<pow(2,input_len);x++){
		if((func_val[x][j]^func_val[x^e_i][j])==0x01){
			count+=1;
		}
	}
	return count;
}

int main(){
	char values[input_len][output_len],e_i,bit_val,temp,func_val[(int)pow(2,input_len)][output_len];
	//The below block represents the sbox as a collection of m functions f_1,...,f_m   
	for(int i=0;i<pow(2,input_len);i++){
		temp=f[i];
		for(int j=0;j<output_len;j++){
			bit_val=temp&0x01;
			func_val[i][j]=bit_val;
			temp=temp>>1;
		}
	}

	//testing the functions f_1,...,f_m
	for(int i=0;i<pow(2,input_len);i++){
		for(int j=0;j<output_len;j++){
			printf("%d ",func_val[i][j]);
		}
		printf("\n");
	}

	for(char i=0;i<input_len;i++){
		e_i=1<<i;
		printf("%d\n",e_i);
		for(char j=0;j<output_len;j++){
			values[i][j]=check(func_val,e_i,j);
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
