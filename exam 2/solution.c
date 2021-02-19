#include <stdio.h>
#include <stdlib.h>
#define ARR_LEN 30

//Functions to be implemented:
void readbinary(char arr[], int *len, int *reps);
int sum1rec(char arr[], int len);
int existSubseq(char arr[], int len, int reps);

int main() {
	char arr[ARR_LEN];
	int len,reps, i;
	
	//Read and print the array:
	readbinary(arr, &len, &reps);
	printf("Array:\n");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	//Computes how many 1 ' s are occurring (RECURSIVE)
	printf("Totale occorrenze di 1: %d\n", sum1rec(arr, len));
	
	//Computes  if  a  subsequence  of  exactly  nreps  1 ' s  exists  in  the array
	if(existSubseq(arr,len,reps))
		printf("Condizione per %d uno contigui: VERA\n",reps);
	else
		printf("Condizione per %d uno contigui: FALSA\n", reps);
	return 0;
}

void readbinary(char arr[], int *len, int *reps){
	int i=0;
	int n=0;
	int elemento;
	scanf("%d", &elemento);
	while(i<30 && elemento==1 || elemento==0){
		arr[i]=elemento;
		n=n+1;
		scanf("%d", &elemento);
		i++;
		}
	*reps=elemento;
	*len=n;
	}

int sum1rec(char arr[], int len){
	if(len>=0){	
		if(arr[len-1]==1) return 1+sum1rec(arr, len-1);
		else return sum1rec(arr, len-1);
		}
	else return 0;
}


int existSubseq(char arr[], int len, int reps){
	int i=0;
	int trovato=0;
	int n=0;
	while(i<len && !trovato){
		if(arr[i]==1) {n=n+1; if(n==reps && arr[i+1]!=1) trovato=1; else i++;}
		else {n=0; i++;}
		}
	return trovato;
}















