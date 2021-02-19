#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//List structure:
struct El {
    int  info;
    struct  El *next;
};

typedef struct El  ElementoLista;


// Functions/Procedure  to be implemented:

void readList(ElementoLista **lista, int dis);
int maxDistance(ElementoLista *lista);
void CancellaMax(ElementoLista **lista, int maxdis);


//Function to print all the elements of the list:
void printList(ElementoLista *list) {
    printf("(");
    while (list != NULL) {
        printf("%d ", list->info);
        list = list->next;
    }
    printf(")\n");
}

int main() {
	ElementoLista *list=NULL;
    int  boundis, maxdis;
    
    //Read the  bounded distance
    scanf("%d", &boundis);
    
    //Read and print the list
    readList(&list, boundis);
    printf("La lista bounded-%d e':\n", boundis);
    printList(list);
    
    //Compute and print the maxdistance of the  list
    maxdis=maxDistance(list);
    printf("La distanza massima e':\n%d\n", maxdis);
    
    //Removes the elements at distance maxdistance
    CancellaMax(&list,maxdis);
    printf("La lista modificata e':\n");
    printList(list);
    
    return 0;
}

void readList(ElementoLista **lista, int dis){
	int n;
	scanf("%d", &n);
	ElementoLista* new=malloc(sizeof(ElementoLista));
	new->info=n;
	new->next=NULL;
	*lista=new;
	scanf("%d", &n);
	while(abs(n-new->info)<=dis){
		ElementoLista* succ=malloc(sizeof(ElementoLista));	
		succ->info=n;
		succ->next=NULL;
		new->next=succ;
		new=succ;
		scanf("%d", &n);}
}

int maxDistance(ElementoLista *lista){
	ElementoLista* corr=lista->next;
	ElementoLista* prec=lista;
	int max=0;
	while(corr!=NULL){
		if(abs(prec->info-corr->info)>max) max=abs(prec->info-corr->info);
		else {prec=prec->next; corr=corr->next;}}
	return max;}

void CancellaMax(ElementoLista **lista, int maxdis){
	ElementoLista* prec=*lista;
	ElementoLista* corr=(*lista)->next;
	ElementoLista* succ=corr->next;
	while(succ!=NULL){
		if(abs((*lista)->info-corr->info)==maxdis){
			ElementoLista* aux=*lista;
			prec=corr;
			*lista=corr;
			corr=succ;
			succ=succ->next;
			free(aux);}
		else if(abs(corr->info-succ->info)==maxdis) {
			ElementoLista* aux=corr;
			corr=succ;
			succ=succ->next;
			prec->next=corr;
			free(aux);}
		else {prec=corr; corr=succ; succ=succ->next;}}
	if(succ==NULL && abs(prec->info-corr->info)==maxdis){
		ElementoLista* aux=prec;
		prec=corr;
		*lista=corr;
		free(aux);}
}
			






