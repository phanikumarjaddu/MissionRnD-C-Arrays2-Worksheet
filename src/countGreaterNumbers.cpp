/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(struct transaction *Arr, char *date,int i)
{
	int j;
	for (j = 6; j <= 9; j++)
	{
		if (Arr[i].date[j] - date[j] > 0)
			return 1;
		else if (Arr[i].date[j] - date[j] < 0)
			return 0;
	}
	for (j = 3; j <= 4; j++)
	{
		if (Arr[i].date[j] - date[j] > 0)
			return 1;
		else if (Arr[i].date[j] - date[j] < 0)
			return 0;
	}
	for (j = 0; j <= 1; j++)
	{
		if (Arr[i].date[j] - date[j] > 0)
			return 1;
		else if (Arr[i].date[j] - date[j] < 0)
			return 0;
	}
	return 0;
}


int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		if (compare(Arr, date, i))
			return len - i;
	}
	return 0;
}


