/*
* Main file to test bigInteger functions
* By Isaac Chiboub - isaac.chiboub@utbm.fr
* And Thibault Miclo - thibault.miclo@utbm.fr
*
* Last edit : 23/12/11
*/

#include <DlinkedList.h>
#include <bigInteger.h>
#include <stdio.h>
#include <stdlib.h>

void menu();

int main(int argc, char* argv[]) 
{
	menu();	/* Body of the program */		
	
	return EXIT_SUCCESS;
}

void menu()
{
	/* Declarations */
	int set=0;
	char input1[10000]="";
	char input2[10000]="";
	char again[1]="n";
	unsigned long l1,l2;
	bigInteger n1=NULL;
	bigInteger n2=NULL;
	bigInteger result=NULL;
	printf("						**********************************************************\n");
	printf("						*		       LO27 Project			 *\n");
	printf("						*     		Miclo Thibault & Chiboub Isaac           *\n");
	printf("						* Welcome in the test program for the BigInteger library *\n");
	printf("						**********************************************************\n\n\n");
	printf("	This library contains all the features below. \n\n\n"); 
	
	printf("-----------\n");
	printf(" 1. isNull \n 2. signBigInt \n 3. equalsBigInt \n 4. compareBigInt \n 5. sumBigInt \n 6. diffBigInt \n 7. mulBigInt \n 8. quotientBigint \n 9. restBigInt \n10. gcdBigInt \n11. lcmBigInt \n12. factorial \n13. cnp \n");
	printf("-----------\n\n\n");
	printf("Please chose the fonction you want to test by typing the corresponding number : \n");
	
	
	scanf("%d",&set);
	/* Loop to ensure a good choice of function */
	while( set < 1 || set > 13)
	{
		printf(" Wrong choice of fonctions, try another one \n");
		scanf("%d",&set);
	}
	
	if(set == 1 || set == 2 ) /* signBigInt or isNull */
	{
		printf("\nEnter a big integer :  \n");
		scanf("%s",input1);
	}
	else if (set != 12 && set != 13) /* All except 1, 2, 12 and 13 */
	{
		printf("\nEnter a the first big integer :  \n");
		scanf("%s",input1);
		printf("Enter b the second : \n");
		scanf("%s",input2);	
	}
	else if ( set == 12) /* Factorial */
	{
		printf("\nEnter an unsigned long int a : \n");
		scanf("%lu",&l1);
	}
	else /* Combinatorial */
	{
		printf("\nEnter an unsigned long int n : \n");
		scanf("%lu",&l1);
		printf("\nEnter p (n>p) : \n");
		scanf("%lu",&l2);
	}

	n1=newBigInteger(input1);
	n2=newBigInteger(input2);
	
	switch(set) /* Switch to display the result of the operation asked */
	{
		case 1:
		printf("\nIsNull(a) = %d\n",isNull(n1));
		break;
		case 2:
		printf(" signBigInt(a) = %d\n", signBigInt(n1));
		break;
		case 3:
		printf("equalsBigInt(a,b)=%d\n",equalsBigInt(n1,n2));
		break;
		case 4:
		printf(" compareBigInt(a,b) = %d\n", compareBigInt(n1,n2));
		break;
		case 5:
		result=sumBigInt(n1,n2);
		printf("\na + b = ");
		printBigInteger(result);
		break;
		case 6:
		result=diffBigInt(n1,n2);
		printf("\na - b = ");
		printBigInteger(result);
		break;
		case 7:
		result=mulBigInt(n1,n2);
		printf("\na * b = ");
		printBigInteger(result);
		break;
		case 8:
		result=quotientBigInt(n1,n2);
		printf("\na / b = ");
		printBigInteger(result);
		break;
		case 9:
		result=restBigInt(n1,n2);
		printf("\nrest(a,b) = ");
		printBigInteger(result);
		break;
		case 10:
		result=gcdBigInt(n1,n2);
		printf("\ngcd(a,b) = ");
		printBigInteger(result);
		break;
		case 11:
		result=lcmBigInt(n1,n2);
		printf("\nlcm(a,b) = ");
		printBigInteger(result);
		break;
		case 12:
		result=factorial(l1);
		printf("\nfactorial(%lu) = ",l1);
		printBigInteger(result);
		break;
		case 13:
		result=cnp(l1,l2);
		printf("\ncnp(%lu,%lu) = ",l1,l2);
		printBigInteger(result);
		break;
	}
	
	/* Try another function ? */
	printf("\nWould like to try another fonction ? (Y/N)\n");
	scanf("%s",again);
	if(again[0]=='Y'||again[0]=='y')
	{
		/* Call menu again */
		menu();
	}
}
