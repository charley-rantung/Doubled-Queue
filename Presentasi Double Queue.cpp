#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct node
{
	int nilai;
	struct node *next, *prev;
};
struct node *NB;
struct node *temp;
struct node *head, *tail = NULL;
int count=0;

void Enqueue()
{
	NB=(struct node*)malloc(sizeof(struct node));
	printf("Masukkan Nilai : ");
	scanf("%d", &NB->nilai);
	NB->next=NULL;
	if(head==NULL)
	{
		head=NB;
		head->prev=NULL;
	}
	else
	{
		tail=head;
		while(tail->next!=NULL)
		{
			tail=tail->next;
		}
		tail->next=NB;
		NB->prev=tail;
		tail=NB;
	}
	count++;
}

void Dequeue()
{
	
	if(count==0)
	{
		printf("Antrian lagi kosong, isi dulu bro baru se kaluar\n");
	}
	else
	{	
	
	/*
		if(count==0)
		printf("Queue Kosong");
		else
		{
			printf("Antrian data : \n");
			temp=head;
			head=head->link;
			printf("Nilai yang akan dikeluarkan adalah %d", temp->nilai);
			free(temp);
			count--;
		
	} */
		temp=head;
		printf("Data yang dikeluarkan adalah : %d\n",temp->nilai);
		head=head->next;
		free(temp);
		count--;
	}

}


void Display()
{
	temp=head;
	if(count==0)
	printf("Masih kosong bro, Co se maso di menu no. 1\n");
	else
	{
		for(int i=0;i<count;i++)
		{
			printf("Nilai Antrian ke-%d adalah : %d\n", i+1, temp->nilai);
			temp=temp->next;
		}
	}
}

int main()
{
	int pil;
	
	do
	{
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Masukkan pilihan anda : ");
		scanf("%d", &pil);
		
		switch(pil)
		{
			case 1	:	Enqueue();
						break;
			case 2	:	Dequeue();
						break;
			case 3	:	Display();
						break;
		}
	}while(pil!=4);
	
	getche();
	return 0;
}	
