#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>

struct elem {
	int degree;
	int kof;
	struct elem* next;
};


int equality(struct elem* FirstP, struct elem* FirstQ) {

	int result = 1;
	struct elem* currP = FirstP->next;
	struct elem* currQ = FirstQ->next;

	while ((currP->kof == currQ->kof) &&
		(currP->degree == currQ->degree) &&
		(currP->next != NULL) &&
		(currQ->next != NULL))
	{
		currP = currP->next;
		currQ = currQ->next;
	}
	if ((currP->kof != currQ->kof) ||
		(currP->degree!=currQ->degree) ||
		(currP->next != NULL) ||
		(currQ->next != NULL)) result = 0;
	return result;
}

int meaning(struct elem *firstP, int x)
{
int result = 0;
struct elem *currP = firstP;

	while (currP->next!=NULL)
	{
		currP = currP->next;
	result+=(int) ((currP->kof) * round(pow(x, currP->degree)));
    }

	return result;
}


struct elem* getPos(struct elem* first, int degree)
{
	struct elem* result = NULL;
	struct elem* curr = (struct elem*)malloc(sizeof(struct elem));
	curr = first;

	while ((curr->next != NULL) && (curr->degree != degree))
		curr = curr->next;

	if (curr->degree == degree) result = curr;

	return result;
}

struct elem* add(struct elem* firstP, struct elem* firstQ) {

	struct elem* firstR = (struct elem*)malloc(sizeof(struct elem));
	struct elem* currR = firstR;
	currR->next = NULL;

	int maxDegree;
	if (firstP->next->degree > firstQ->next->degree)
		maxDegree = firstP->next->degree;
	else maxDegree = firstQ->next->degree;

	int degree = maxDegree;

	while (degree != -1) {
		struct elem* posP = getPos(firstP, degree);
		struct elem* posQ = getPos(firstQ, degree);

		if ((posP != NULL) || (posQ != NULL))
		{
			currR->next = (struct elem*)malloc(sizeof(struct elem));
			currR = currR->next;
			currR->next = NULL;
			currR->degree = degree;
			currR->kof = 0;

			if (posP != NULL)  currR->kof += posP->kof;
			if (posQ != NULL)  currR->kof += posQ->kof;
		}

		degree--;
	}
	return firstR;
}

void write (struct elem *first) {
	struct elem *curr = first;
	while (curr->next != NULL) 
	{
		curr = curr->next;
		if (curr->kof != 0)
		{
			if (curr->kof == -1) printf("-"); else
				if (curr->kof != 1)
					printf("%d", curr->kof);
			printf("x^%d ", curr->degree);
			if (curr->next != NULL)
			{
				if (curr->next->kof > 0) printf("+");
			}
			else
				printf("\n");
		}
	}
}



void main()
{
	int exit = 0;
	do
	{
	printf("(1) compare   (2) calculate   (3) add   (4) exit\n");
	int number;
	scanf("%d", &number);
	
		switch (number)
		{
		case 1:
		{
			//////////////////////////////////////////////// сравнить многочлены
			struct elem* firstP = (struct elem*)malloc(sizeof(struct elem));
			firstP->next = NULL;
			struct elem* curr = firstP;

			int degree;
			int currKof;
			printf("Enter degree ");
			scanf("%d", &degree);
			for (int i = degree; i >= 0; i--)
			{
				printf("Enter kof x^%d ", i);
				scanf("%d", &currKof);
				if (currKof != 0)
				{
					curr->next = (struct elem*)malloc(sizeof(struct elem));
					curr = curr->next;
					curr->degree = i;
					curr->kof = currKof;
					curr->next = NULL;
				}
			}


			struct elem* firstQ = (struct elem*)malloc(sizeof(struct elem));
			firstQ->next = NULL;
			curr = firstQ;

			printf("Enter degree ");
			scanf("%d", &degree);
			for (int i = degree; i >= 0; i--)
			{
				printf("Enter kof x^%d ", i);
				scanf("%d", &currKof);
				if (currKof != 0)
				{
					curr->next = (struct elem*)malloc(sizeof(struct elem));
					curr = curr->next;
					curr->degree = i;
					curr->kof = currKof;
					curr->next = NULL;
				}
			}

			printf("P(x) = ");
			write(firstP);
			printf("Q(x) = ");
			write(firstQ);

			int similar = equality(firstP, firstQ);
			if (!similar) printf("different\n"); else
				printf("equals\n");
			//////////////////////////////////////////////// сравнить многочлены
		}
			break;

		case 2:
		{
			//////////////////////////////////////////////// вычислить значение
			struct elem* first = (struct elem*)malloc(sizeof(struct elem));
			first->next = NULL;
			struct elem* curr = first;
			int degree;
			int currKof;

			printf("Enter degree ");
			scanf("%d", &degree);
			for (int i = degree; i >= 0; i--)
			{
				printf("Enter kof x^%d ", i);
				scanf("%d", &currKof);
				if (currKof != 0)
				{
					curr->next = (struct elem*)malloc(sizeof(struct elem));
					curr = curr->next;
					curr->degree = i;
					curr->kof = currKof;
					curr->next = NULL;
				}
			}

			printf("P(x) = ");
			write(first);

			printf("Enter x ");
			int x;
			scanf("%d", &x);
			int value = meaning(first, x);
			printf("P(%d) = %d\n", x, value);
			//////////////////////////////////////////////// вычислить значение
		}
			break;


		case 3:
		{
			//////////////////////////////////////////////// сравнить многочлены
			struct elem* firstP = (struct elem*)malloc(sizeof(struct elem));
			firstP->next = NULL;
			struct elem* curr = firstP;

			int degree;
			int currKof;
			printf("Enter degree ");
			scanf("%d", &degree);
			for (int i = degree; i >= 0; i--)
			{
				printf("Enter kof x^%d ", i);
				scanf("%d", &currKof);
				if (currKof != 0)
				{
					curr->next = (struct elem*)malloc(sizeof(struct elem));
					curr = curr->next;
					curr->degree = i;
					curr->kof = currKof;
					curr->next = NULL;
				}
			}


			struct elem* firstQ = (struct elem*)malloc(sizeof(struct elem));
			firstQ->next = NULL;
			curr = firstQ;

			printf("Enter degree ");
			scanf("%d", &degree);
			for (int i = degree; i >= 0; i--)
			{
				printf("Enter kof x^%d ", i);
				scanf("%d", &currKof);
				if (currKof != 0)
				{
					curr->next = (struct elem*)malloc(sizeof(struct elem));
					curr = curr->next;
					curr->degree = i;
					curr->kof = currKof;
					curr->next = NULL;
				}
			}

			struct elem* sum = (struct elem*)malloc(sizeof(struct elem));
			printf("P(x) = ");
			write(firstP);
			printf("Q(x) = ");
			write(firstQ);
			sum = add(firstP, firstQ);
			printf("Q(x) + P(x) = ");
			write(sum);
			printf("\n");
			//////////////////////////////////////////////// сравнить многочлены
		}
			break;


		case 4: exit = 1;
			break; 

		default:
			printf("Enter 1, 2 or 3\n");
		}
	} while (exit == 0);
}