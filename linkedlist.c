#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct node {
	int data;
	struct node* next;
};

struct node* new (int data)
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->data = data;
temp->next = NULL;
return temp;
}

struct node* travel(struct node* head)
{
	struct node* curr = head;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}


bool searching (struct node* head, int key)
{
	while (head != NULL)
	{
		if (head->data == key)
			return true;
		head = head->next;
	}
	return false;
}

void search(struct node* head, int key) {
	if (searching(head, key)) {
		printf("Aranan deðer bulundu: %d\n", key);
	}
	else {
		printf("Aranan deðer bulunamadý: %d\n", key);
	}
}


int findLength(struct node* head)
{
	int sayac = 0;
	while (head != NULL)
	{
		sayac++;
		head = head->next;
	}
	printf("Bagli listenin uzunlugu: %d\n", sayac);
	return sayac;
}

struct node* insertToBegin(struct node* head,int data)
{
	struct node* temp = new(data);
	temp->next = head; // Yeni düðümün next iþaretçisini eski head'e baðla
	head = temp;       // Head'i yeni düðüme güncelle
	return head;       // Yeni head'i döndür
}

struct node* insertToPoz(struct node* head, int poz, int data)
{
	struct node* temp2 = new(data);
	if (poz < 1)
	{
		printf("%s", "Hata !");
		return NULL;
	}
	if (poz == 1)
	{
		struct node* temp1 = new(data);
		temp1->next = head;
		head = temp1;
		return head;
	}
	struct node* temp = head;
	int count = 1;
	while (count < poz - 1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	if (temp == NULL)
	{
		printf("%s", "Hata");
		return NULL;
	}

	struct node* veri = new(data);


	veri->next = temp->next;
	temp->next = veri;


	return head;
}
struct node* insertToEnd(struct node* head, int data)
{
	struct node* temp = new(data);
	if (head == NULL)
	{
		return temp;
	}
	struct node* curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = temp;
	temp->next = NULL;
	return head;
}

struct node* cleaningOfEnd(struct node* head) {
	if (head == NULL)
	{
		printf("Liste boþ");
		return NULL;
	}
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	struct node* curr = head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	free(curr->next); 
	curr->next = NULL; 
	return head; 
}

struct node* cleaninfOfPoz(struct node* head, int poz) {
	if (poz < 1) {
		printf("Hatalý pozisyon...\n");
		return head; 
	}

	// Eðer silinecek pozisyon baþta ise
	if (poz == 1) {
		struct node* temp = head;
		head = head->next; 
		free(temp); 
		return head;
	}

	int i = 1;
	struct node* curr = head;

	// Pozisyona kadar ilerle
	while (curr != NULL && i < poz - 1) {
		curr = curr->next;
		i++;
	}

	
	if (curr == NULL || curr->next == NULL) {
		printf("Pozisyonda silinecek düðüm yok.\n");
		return NULL; 
	}

	struct node* temp = curr->next; 
	curr->next = curr->next->next; 
	free(temp); 

	return head; 
}

struct node* cleaningOfHead(struct node* head)
{
	if (head == NULL)
	{
		printf("Liste zaten boþ.\n");
		return NULL;
	}
	struct node* temp = head;
	head = head->next;  // head'i güncelle
	free(temp);  // eski baþ düðümü sil
	return head;  // güncellenmiþ head'i döndür
}

	void printList(struct node* head)
	{
		if (head == NULL) {
			printf("Liste boþ.\n");
			return;
		}

		struct node* curr = head;
		for(curr;curr!=NULL;curr=curr->next){
		//while (curr != NULL)
		//{
			printf("%d\n", curr->data);
			//curr = curr->next;
		}
	}

int main()
{
	printf("%s", "Programa Hos Geldiniz !\n");
	printf("%s", "Islemler:\n ");
	char islemler[] = "\t1-Gezinme\n"
		"\t2-Arama\n"
		"\t3-Uzunluk Bulma\n"
		"\t4-Silme\n"
		"\t5-Ekleme\n"
		"\tCikis icin q'ya basiniz.\n";


	struct node* one = new(1);
	struct node* two = new(2);
	struct node* three = new(3);
	struct node* four = new(4);
	struct node* five = new(5);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = NULL;
	
	while (1) {
		printf(islemler);
		char secim[30];
		printf("%s", "Yapmak istediginiz islemi giriniz :");
		//scanf("%s", &secim);
		fgets(secim, sizeof(secim), stdin);
		secim[strcspn(secim, "\n")] = 0;
		if (strcmp(secim, "q") == 0)
		{
			printf("%s", "Programdan cikiliyor.");
			break;
		}
		else if (strcmp(secim, "1") == 0)
		{
			printf("%s", "Gezinme baslatiliyor...\n");
			travel(one);
		}
		else if (strcmp(secim, "2") == 0)
		{
			int sayi;
			printf("%s", "Aradiginiz sayiyi giriniz: ");
			scanf("%d", &sayi);
			getchar();
			search(one, sayi);
		}
		else if (strcmp(secim, "3") == 0)
		{
			printf("%s", "Uzunluk bulunuyor...");
			findLength(one);
		}
		else if (strcmp(secim, "4") == 0)
		{
			char silim[40];
			printf("%s",
				"a-Basi silme\n"
				"b-Belirli bir pozisyonu silme \n"
				"c-Sonu silme");
			printf("%s", "Hangi silme islemi :");
			fgets(silim, sizeof(silim), stdin);
			silim[strcspn(silim, "\n")] = 0; // Yeni satýr karakterini kaldýr
			if (strcmp(silim, "a") == 0)
			{
				printf("%s", "Silme baslatiliyor...");
				cleaningOfHead(one);
				one = cleaningOfHead(one);
				printList(one);
			}
			else if (strcmp(silim, "b") == 0)
			{
				printf("%s", "Silmek istediginiz poziyonu seciniz :");
				int sayi1;
				scanf("%d", &sayi1);
				getchar();
				printf("%s", "Silme baslatiliyor...");
				cleaninfOfPoz(one, sayi1);
				printList(one);
			}
			else if (strcmp(silim, "c") == 0)
			{
				printf("%s", "Silme baslatiliyor...");
				cleaningOfEnd(one);
				printList(one);

			}
			else {
				printf("%s", "Lutfen gecerli secim yapiniz..");
			}
		
		
		}
		else if (strcmp(secim, "5") == 0)
		{
			char secmece[40];
			printf("%s",
				"a-Basa ekleme\n"
				"b-Belirli bir pozisyona ekleme\n"
				"c-Sona ekleme\n");
			printf("%s", "Hangi ekleme islemi :");
			fgets(secmece, sizeof(secmece), stdin);
			secmece[strcspn(secmece, "\n")] = 0; // Yeni satýr karakterini kaldýr


			if (strcmp(secmece, "a") == 0)
			{
				printf("%s", "Eklemek istediginiz sayiyi giriniz: ");
				int num;
				scanf("%d", &num);
				getchar();
				printf("%s", "Ekleme baslatiliyor...");
				insertToBegin(one, num);
				printList(one);
			}
			else if (strcmp(secmece, "b") == 0)
			{
				printf("%s", "Eklemek istediginiz sayiyi giriniz: ");
				int num1;
				scanf("%d", &num1);
				getchar();
				printf("%s", "Eklemek istediginiz poziyonu giriniz: ");
				int poz;
				scanf("%d", &poz);
				getchar();
				printf("%s", "Ekleme baslatiliyor...");
				insertToPoz(one, poz, num1);
				printList(one);

			}
			else if (strcmp(secmece, "c") == 0)
			{
				printf("%s", "Eklemek istediginiz sayiyi giriniz: ");
				int num2;
				scanf("%d", &num2);
				getchar();
				printf("%s", "Ekleme baslatiliyor...");
				insertToEnd(one, num2);
				printList(one);
			}
			else {
				printf("%s", "Lutfen gecerli secim yapiniz..");
			}
		}

		else {
			printf("%s", "Lutfen gecerli secim yapiniz..");
		}
	}
}