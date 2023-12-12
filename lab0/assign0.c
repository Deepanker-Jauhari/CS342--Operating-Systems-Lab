#include <stdio.h>


int strcomp2(char* x, char*y){
	while(*x){
		if(*x!=*y){
			break;
		}
		x++;
		y++;
	}
	
	return *(char*)x-*(char*)y;
}

int strrlen(char *x){
	int lenx=0;
	while(*x){
	lenx++;
	x++;
	}
	
	return lenx;
}

int strcomp(char* x, char* y, int lenx, int leny){
	int flag = strcomp2(x,y);
	
	if(flag>0){
	return 1;
	}
	else if(flag<0){
	return -1;
	}
	
	return 0;
}


void strsort(char a[][20], char **b, int n){
	for(int i=n;i<50;i++){
		b[i]=NULL;
	}
	for(int i=0;i<n;i++){
		b[i] = a[i];
	}
	for(int i=1;i<n;i++){
		char* key = b[i];
		int j = i-1;
		while(j>=0 && strcomp2(b[j],key) > 0){
			b[j+1] = b[j];
			j--;
		}
		b[j+1] = key;
	}
}

int main(){
	int n;
	printf("Write n: ");
	scanf("%d", &n);
	char a[50][20]; 
	char* b[50];   
	for (int i=0; i<n; i++){
		printf("Write a[%d]: ", i);
		scanf("%s", a[i]);
	}
	strsort(a, b, n);
	printf("\n Sorted strings are:\n");
	for (int i = 0; i < n; i++){
		printf("%s\n", b[i]);
	}
	
	return 0;
}

