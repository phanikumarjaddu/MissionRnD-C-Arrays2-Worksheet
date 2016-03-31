/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmptransaction(char *Adate, char *Bdate)
{
	int k;
	for (k = 6; k <= 9; k++)
	{
		if (Adate[k] > Bdate[k])
			return 1;
		else if (Adate[k] < Bdate[k])
			return 0;
	}

	for (k = 3; k <= 4; k++)
	{
		if (Adate[k] > Bdate[k])
			return 1;
		else if (Adate[k] < Bdate[k])
			return 0;
	}

	for (k = 0; k <= 1; k++)
	{
		if (Adate[k] > Bdate[k])
			return 1;
		else if (Adate[k] < Bdate[k])
			return 0;
	}
	return 2;
}


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, p = 0, k, r;
	struct transaction *sub;
	if (A == NULL || ALen < 0)
		return NULL;
	if (B == NULL || BLen < 0)
		return NULL;
	sub = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i<ALen && j < BLen)
	{
		r = cmptransaction(A[i].date, B[j].date);
		if (r == 1)
		{
			*(sub + p) = B[j];
			j++;
		}
		else if (r == 0)
		{
			*(sub + p) = A[i];
			i++;
		}
		else
		{
			*(sub + p) = A[i];
			i++;
			p++;
			*(sub + p) = B[j];
			j++;
		}
		p++;
	}
	for (k = j; k<BLen; k++)
	{
		*(sub + p) = B[k];
		p++;
	}
	for (k = i; k < ALen; k++)
	{
		*(sub + p) = A[k];
		p++;
	}
	return sub;
}