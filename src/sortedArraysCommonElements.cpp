/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int sametransaction(struct transaction *A, struct transaction *B, int i, int Len)
{
	int k, year_equal = 0, month_equal = 0, day_equal = 0;
	for (int j = 0; j < Len; j++)
	{
		for (k = 6; k <= 9; k++)
		{
			if ((A[j].date[k] - B[j].date[k]) == 0)
				year_equal++;
		}

		for (k = 3; k <= 4 && year_equal == 4; k++)
		{
			if ((A[j].date[k] - B[j].date[k]) == 0)
				month_equal++;
		}

		for (k = 0; k <= 1 && month_equal == 2; k++)
		{
			if ((A[j].date[k] - B[j].date[k]) == 0)
				day_equal++;
		}
		if (day_equal == 2)
			return 1;
	}
	return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	int p = 0, i;
	struct transaction *sub;
	if (ALen <= 0 || BLen <= 0)
		return NULL;
	else if (A ==NULL || B == NULL)
		return NULL;
	else
	{
		sub = (struct transaction *)malloc(sizeof(struct transaction));
		if (ALen >= BLen)
		{
			for (i = 0; i < ALen; i++)
			{
				if (sametransaction(A, B, i, BLen))
				{
					*(sub + p) = A[i];
					p++;
				}
			}
			if (p == 0)
				return NULL;
			else
				return sub;
		}
		else
		{
			for (i = 0; i < ALen; i++)
			{
				if (sametransaction(A, B, i, BLen))
				{
					*(sub + p) = A[i];
					p++;
				}
			}
			if (p == 0)
				return NULL;
			else
				return sub;
		}
	}
	return NULL;
}