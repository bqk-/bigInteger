/*
* Body of bigIntegers functions
* By Isaac Chiboub - isaac.chiboub@utbm.fr
* And Thibault Miclo - thibault.miclo@utbm.fr
*
* Last edit : 23/12/11
*/

#include <DlinkedList.h>
#include <bigInteger.h>
#include <stdio.h>
#include <stdlib.h>

bigInteger newBigInteger(char nb[])
{
	/* Declarations */
	int i, val;
	bigInteger temp=NULL;
	temp=malloc(sizeof(nb));

	/* Test : is it 0 or -0 ? */
	if((nb[0]=='0'&&nb[1]=='\0')||(nb[0]==45&&nb[1]=='0'&&nb[2]=='\0'))
	{
		temp=NULL;
	}
	else
	{
		/* Negative ? */
		if(nb[0]==45)
		{
			temp->sign=TRUE;
		}
		else
		{
			temp->sign=FALSE;
		}
		/* Check validity of the number inputed, replace wrong characters by 0 */
		for(i=temp->sign;nb[i]!='\0';i++)
		{
			nb[i]=inputToValidNb(nb[i]);
		}
		/* make 4 figures' package, until the end of the input */
		for(i=i-1;i>=temp->sign;i=i-4)
		{
			val=0;
			if(i>=temp->sign)
			{
				val+=nb[i]-'0';
			}
			if(i-1>=temp->sign)
			{
				val+=(nb[i-1]-'0')*10;
			}
			if(i-2>=temp->sign)
			{
				val+=(nb[i-2]-'0')*100;
			}
			if(i-3>=temp->sign)
			{
				val+=(nb[i-3]-'0')*1000;
			}
			/* Insert the package in a DlinkedList, as an element */
			temp->absvalue=insertTail(temp->absvalue,val);
		}
	}
	
	return temp;
}
int inputToValidNb(int a)
{
	/* If it is a figure, don't touch it */
	if(a>='0' || a <='9')
	{
		return a;
	} /* Else, return the 0 char */
	else
	{
		return '0';
	}
}
bigInteger sumBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	int ta,tb,r=0,sum;
	bigInteger result=NULL;
	Element* l1=malloc(sizeof(Element));	
	Element* l2=malloc(sizeof(Element));
	result=malloc(sizeof(nb));
	/* If one or the two is/are null */
	if(a==NULL || b==NULL)
	{
		if(a==b)
		{
			l1=insertTail(l1,0);
			removeHead(l1);
			result->absvalue=l1;
			return result;
		}		
		else if(a==NULL)
		{
			return b;
		}
		else if(b==NULL)
		{
			return a;
		}
	}	
	/* Easier to work with DlinkedList instead of bigInteger */ 
	l1=a->absvalue;
	l2=b->absvalue;
	/* Same sign ? */
	if(a->sign==b->sign)
	{
		/* While the two aren't null */
		while(l1!=NULL || l2!=NULL)
		{
			sum=0;
			/* Make sure to work with a valid value for l1 */
			if(l1==NULL)
			{
				ta=0;
			}
			else
			{
				ta=l1->value;
				l1=l1->next;
			}
			/* Make sure to work with a valid value for l2 */
			if(l2==NULL)
			{
				tb=0;
			}
			else
			{
				tb=l2->value;
				l2=l2->next;
			}
			/* Simple sum */
			sum=ta+tb+r;
			/* Rest or not ? */
			if(sum>9999)
			{
				r=1;
				sum-=10000;
			}
			else
			{
				r=0;
			}
			/* Insert the package in a DlinkedList, as an element */
			result->absvalue=insertTail(result->absvalue,sum);
		}
		/* Don't forget the final rest ! */
		if(r>0)
		{
			result->absvalue=insertTail(result->absvalue,1);
		}
		/* Put the right sign to the result */
		result->sign=a->sign;
	}
	else
	{
		/* Contrary signs, so that's a soustraction, let's call diffBigInt with some order and signs changes */
		if(a->sign==TRUE)
		{
			a->sign=FALSE;
			result=diffBigInt(b,a);
			a->sign=TRUE;
		}
		else
		{
			b->sign=FALSE;
			result=diffBigInt(a,b);
			b->sign=TRUE;
		}
	}
	
	return result;
}

bigInteger diffBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	int ta,tb,r=0,diff;
	bigInteger result=NULL;
	Element* temp=malloc(sizeof(Element));	
	Element* l1=malloc(sizeof(Element));	
	Element* l2=malloc(sizeof(Element));
	result=malloc(sizeof(nb));
	/* No null bigInteger ? */
	if(a!=NULL && b!= NULL)
	{
		/* Easier to work with DlinkedList instead of bigInteger */ 
		l1=a->absvalue;
		l2=b->absvalue;
	}
	else
	{
		if(a==b)
		{
			l1=insertTail(l1,0);
			removeHead(l1);
			result->absvalue=l1;
			return result;
		}
		else if(a==NULL)
		{
			return b;
		}
		else
		{
			return a;
		}
	}
	/* Is it really a soustraction ? Let's check that */
	if(a->sign==TRUE&&b->sign==FALSE)
	{
		a->sign=FALSE;
		result=sumBigInt(a,b);
		result->sign=TRUE;
		a->sign=TRUE;
	}
	else if(a->sign==TRUE&&b->sign==TRUE)
	{
		a->sign=FALSE;
		b->sign=FALSE;
		result=diffBigInt(b,a);
		a->sign=TRUE;
		b->sign=TRUE;
	}
	else if(a->sign==FALSE&&b->sign==TRUE)
	{
		b->sign=FALSE;
		result=sumBigInt(a,b);
		b->sign=TRUE;
	}
	else
	{
		/* If b>a, do b-a and put a '-' before the result */
		if(compareBigInt(a,b)==-1)
		{
			temp=l1;
			l1=l2;
			l2=temp;
			result->sign=TRUE;
		} /* Equal ? so no need to compute anything */
		else if(compareBigInt(a,b)==0)
		{
			result->absvalue=insertTail(result->absvalue,0);
			result->sign=FALSE;
			return result;		
		}
		/* While the two aren't null */
		while(l1!=NULL || l2!=NULL)
		{
			/* Make sure to work with a valid value for l1 */
			if(l1==NULL)
			{
				ta=0;
			}
			else
			{
				ta=l1->value-r;
				l1=l1->next;
			}
			/* Make sure to work with a valid value for l2 */
			if(l2==NULL)
			{
				tb=0;
			}
			else
			{
				tb=l2->value;
				l2=l2->next;
			}
			/* Do the soustraction 4 by 4 */
			if(ta>tb)
			{
				diff=ta-tb;
				r=0;
			}
			else if(tb>ta)
			{
				diff=(10000+ta)-tb;
				r=1;
			}
			else
			{
				diff=0;
				r=0;
			}
			/* Insert the 4 figures' package in a DlinkedList, as an element */
			result->absvalue=insertTail(result->absvalue,diff);			
		}
		temp=result->absvalue;
		/* Remove useless 0 */
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp->value==0 && temp->prev!=NULL)
		{
			temp=temp->prev;
			removeTail(temp);
		}

	}
	return result;
}
bigInteger mulBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	int ta=0,tb=0,r=0,group=0,ins=0;
	long i=1,j=0;
	bigInteger result=NULL;
	bigInteger temp=NULL;
	Element* l1=malloc(sizeof(Element));
	Element* l2=malloc(sizeof(Element));
	result=malloc(sizeof(nb));
	/* No null bigInteger ? */
	if(a!=NULL && b!= NULL)
	{
		/* Easier to work with DlinkedList instead of bigInteger */ 
		l1=a->absvalue;
		l2=b->absvalue;
	}
	else if(a==NULL || b==NULL)
	{
		l1=insertTail(l1,0);
		l1=removeHead(l1);
		result->absvalue=l1;
		return result;
	}
	else
	{
		l1=insertTail(l1,0);
		l1=removeHead(l1);
		result->absvalue=l1;
		return result;
	}


	temp=malloc(sizeof(nb));
	/* If a list is null */
	if(l1==NULL || l2==NULL)
	{
		return NULL;
	}
	/* Make sur to be at the begining of the list */ 
	while(l1->prev != NULL)
	{
		l1=l1->prev;
	}
	while(l2->prev != NULL)
	{
		l2=l2->prev;
	}
	/* We need to compute or simple multiplication for each package of b->absvalue */ 
	while(l2 != NULL)
	{
		/* Temporary variable */
		temp->absvalue=NULL;
		r=0;
		/* Put as many 0 as necessary */
		for(i=0;i<j;i++)
		{
			temp->absvalue=insertTail(temp->absvalue,0);
		}
		/* Do the multiplication for each package of a */
		while(l1 != NULL)
		{	
			/* Do the basic multiplication then check for the rest */
			ta=l1->value;
			tb=l2->value;

			group=0;
			ins=0;

			group=group + (ta*tb)+r;
	
			l1=l1->next;

			if(group>9999)
			{
				ins=group%10000;
				r=(group-ins)/10000;
				/* Insert the 4 figures' package in a DlinkedList, as an element */
				temp->absvalue=insertTail(temp->absvalue,ins);
			}
			else
			{
				r=0;
				/* Insert the 4 figures' package in a DlinkedList, as an element */
				temp->absvalue=insertTail(temp->absvalue,group);
			}

		}
		/* Don't forget the final rest */
		if(r>0)
		{
			temp->absvalue=insertTail(temp->absvalue,r);
		}

		l1=a->absvalue;
		result=sumBigInt(temp,result);
		
		l2=l2->next;
	
		j++;
	}
	/* Remove useless 0 */
	l1=result->absvalue;
	while(l1->next!=NULL)
	{
		l1=l1->next;
	}
	while(l1->value==0 && l1->prev!=NULL)
	{
		l1=l1->prev;
		removeTail(l1);
	}

	/* Put the right sign to the result */
	if(a->sign==b->sign)
	{
		result->sign=FALSE;
	}
	else
	{
		result->sign=TRUE;
	}
	return result;	
}
bigInteger quotientBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	Dlist l=malloc(sizeof(Element));
	Dlist m=malloc(sizeof(Element));
	Dlist tmp=malloc(sizeof(Element));
	bigInteger plop=malloc(sizeof(nb));
	bigInteger temp=malloc(sizeof(nb));
	bigInteger result=malloc(sizeof(nb));
	int i=0,j=0, depart=0,k=0,compare,X=-1,n;
	int bsign=FALSE;
	int asign=FALSE;
	char* string=NULL;
	char* qr=NULL;
	/* No null bigInteger ? */
	if(a!=NULL && b!= NULL)
	{
		l=a->absvalue;
		m=b->absvalue;
	}
	else
	{
		result=sumBigInt(result,0);
		return result;
	}
	/* No null bigInteger ? (bis) */
	if(m->value == 0 && m->next==NULL)
	{
		tmp=insertTail(tmp,0);
		removeHead(tmp);
		result->absvalue=tmp;
		result->sign=FALSE;
		return result;
	}
	/* Store the signs of a and b, and remove them to the bigInteger to avoid issues with the other fonctions used into quotientBigInt */
	asign=a->sign;
	a->sign=FALSE;
	bsign=b->sign;
	b->sign=FALSE;

	/* If b > a, result will be < 1, not a bigInteger in fact, so 0 */
	if(compareBigInt(a,b) == -1 || isNull(b))
	{
		a->sign=asign;
		if(!isNull(b))
		{
			b->sign=bsign;
		}
		tmp=insertTail(tmp,0);
		removeHead(tmp);
		result->absvalue=tmp;
		result->sign=FALSE;
		return result;
	}


	/* Basic division ? */
	if(l->value<=9999 && l->next==NULL)
	{
		if(asign==bsign)
		{
			result->sign=FALSE;
		}
		else
		{
			result->sign=TRUE;
		}
		a->sign=asign;
		b->sign=bsign;
		tmp=insertTail(tmp,l->value/m->value);
		tmp=removeHead(tmp);
		result->absvalue=tmp;
		return result;
	}

	/* Count the number of characters in a and b and store it into i and j */
	while(m->next!=NULL)
	{
		i+=4;
		m=m->next;
	}
	if(m->value>999)
	{
		i+=4;
	}
	else if(m->value>99)
	{
		i+=3;
	}
	else if(m->value>9)
	{
		i+=2;
	}
	else
	{
		i+=1;
	}
	/* Dynamic allocation for the first number divided by b, we don't need more than the number of characters +1 in b */
	string=malloc((i+1)*sizeof(char));
	

	while(l->next!=NULL)
	{
		j+=4;
		l=l->next;
	}
	if(l->value>999)
	{
		j+=4;
	}
	else if(l->value>99)
	{
		j+=3;
	}
	else if(l->value>9)
	{
		j+=2;
	}
	else
	{
		j+=1;
	}
	/* Dynamic allocation for the quotient, can't be larger than a */
	qr=malloc(j*sizeof(char));

	/* i is the number of characters of b
	* We take the i first characters of a 
	* Then we make an bigInteger with that */
	l=a->absvalue;
	while(l->next!=NULL)
	{
		l=l->next;
	}
	/* First 4 figures's package */
	depart=j%4;
	if(depart==3)
	{
		k+=3;
		string[2]=l->value%10+'0';
		string[1]=(l->value%100-l->value%10)/10+'0';
		string[0]=(l->value%1000-l->value%100)/100+'0';
		l=l->prev;
	}
	else if(depart==2)
	{
		k+=2;
		string[1]=l->value%10+'0';
		string[0]=(l->value%100-l->value%10)/10+'0';
		l=l->prev;
	}
	else if(depart==1)
	{
		k+=1;
		string[0]=l->value%10+'0';
		l=l->prev;
	}
	depart=i;

	/* All the others 4 figures' packages, except the last one */
	while(depart-k>=0)
	{
		string[k+3]=l->value%10+'0';
		string[k+2]=(l->value%100-l->value%10)/10+'0';
		string[k+1]=(l->value%1000-l->value%100)/100+'0';
		string[k]=(l->value-l->value%1000)/1000+'0';
		k+=4;
		if(l->prev!=NULL)
		{
			l=l->prev;
		}	
	}

	/* The last one */
	if(k-i==3)
	{
		string[k]=l->value%10+'0';
	}
	else if(k-i==2)
	{
		string[k+1]=l->value%10+'0';
		string[k]=(l->value%100-l->value%10)/10+'0';
	}
	else if(k-i==1)
	{
		string[k+2]=l->value%10+'0';
		string[k+1]=(l->value%100-l->value%10)/10+'0';
		string[k]=(l->value%1000-l->value%100)/100+'0';
	}

	/* Don't forget to close the string */
	string[i]='\0';
	plop=newBigInteger(string);			
	/* Our bigInteger is ready */

	/* If our new biginteger is < b, we need to take one more figure from a */
	if(compareBigInt(plop,b)==-1)
	{
		tmp=NULL;
		tmp=insertTail(tmp,10);
		temp->absvalue=tmp;
		plop=mulBigInt(plop,temp);

		X=getNumberN(a,j-i);
		tmp=NULL;
		tmp=insertTail(tmp,X);
		temp->absvalue=tmp;
		plop=sumBigInt(plop,temp);
		i++;
	}
	
	i--;
	n=0;
	/* Compute the soustraction, like in primary school */
	while(j-i>0)
	{
		i++;
		k=0;	
		compare=0;
		/* How many times can I put the quotient ? */
		while(compare>=0 && k<10)
		{
			k++;
			tmp=NULL;
			tmp=insertTail(tmp,k);
			temp->absvalue=tmp;
			temp=mulBigInt(b,temp);

			compare=compareBigInt(plop,temp);
		}
		k--;

		/* Store the figures of the quotient into an array of char */
		tmp=NULL;
		tmp=insertTail(tmp,k);
		temp->absvalue=tmp;
		temp=mulBigInt(b,temp);

		qr[n]=k+'0';
		n++;
		plop=diffBigInt(plop,temp);

		tmp=NULL;
		tmp=insertTail(tmp,10);
		temp->absvalue=tmp;
		plop=mulBigInt(plop,temp);
		
		/* Go down the next number */
		if(j-i>0)
		{
			X=getNumberN(a,j-i);
		}
		tmp=NULL;
		tmp=insertTail(tmp,X);
		temp->absvalue=tmp;
		plop=sumBigInt(plop,temp);
	}
	/* Close the string */
	qr[n]='\0';
	/* Build the result bigInteger */
	result=newBigInteger(qr);
	
	a->sign=asign;
	b->sign=bsign;

	/* Put the right sign */
	if(a->sign==b->sign)
	{
		result->sign=FALSE;
	}
	else
	{
		result->sign=TRUE;
	}

	return result;

}

int getNumberN(bigInteger a,int n)
{
	/* Declarations */
	Element* temp=malloc(sizeof(Element));	
	temp=a->absvalue;

	/* Foreach the bigInteger until we reach the package where is our figure */
	while(n/4>1 && temp->next!=NULL)
	{
		temp=temp->next;
		n-=4;
	}
	/* Return the good one */
	if(n==1)
	{
		return temp->value%10;
	}
	else if(n==2)
	{
		return (temp->value%100-temp->value%10)/10;
	}
	else if(n==3)
	{
		return (temp->value%1000-temp->value%100)/100;
	}
	else if(n==4)
	{
		return (temp->value-temp->value%1000)/1000;
	}
	else
	{
		return 0;
	}
}

bigInteger restBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	bigInteger result=NULL;
	bigInteger quo=NULL;
	bigInteger mul=NULL;
	result=malloc(sizeof(nb));
	quo=malloc(sizeof(nb));
	mul=malloc(sizeof(nb));
	
	/* a / b = q * b + r so r = a - (b * q) */
	quo=quotientBigInt(a,b);
	mul=mulBigInt(b,quo);
	result=diffBigInt(a,mul);
	
	
	return result;
}

bigInteger gcdBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	bigInteger result=NULL;
	Element* temp=malloc(sizeof(Element));	
	temp=a->absvalue;
	result=malloc(sizeof(nb));

	/* We use the rest of the euclidian division algorithm */
	result=restBigInt(a,b);
	temp=result->absvalue;
	
	/* While we don't reach 0 */
	while( temp->value != 0)
	{
		a=b;
		b=result;
		result=restBigInt(a,b);
		temp=result->absvalue;
	}
	
	/* Last one was the gcd */
	result=b;
	result->sign=FALSE;

	return result;
}

bigInteger lcmBigInt(bigInteger a, bigInteger b)
{
	/* Declarations */
	bigInteger result=NULL;
	result=malloc(sizeof(nb));
	
	/* lcm(a,b) = (a * b) / gcd(a,b) */ 
	result=quotientBigInt(mulBigInt(a,b),gcdBigInt(a,b));
	result->sign=FALSE;


	return result;
}
bigInteger factorial(unsigned long a)
{
	/* Declarations */
	Dlist tmp=malloc(sizeof(Element));
	bigInteger result=malloc(sizeof(nb));
	bigInteger temp=malloc(sizeof(nb));
	unsigned long i,j;
	char string[11];
	char stringr[11];

	/* Need to be a unsigned long int */
	if(a<0)
	{
		return NULL;
	} /* 0! = 1 */
	else if(a==0)
	{
		tmp=insertTail(tmp,1);
		tmp=removeHead(tmp);
		result->absvalue=tmp;
		return result;
	}
	else
	{
		i=1;
		j=0;
		/* Make an array of chars with a */
		while(a>=i)
		{
			string[j]=(a%(i*10)-a%i)/i+'0';
			i*=10;
			j++;		
		}
		/* Make a bgiInteger with that array */
		for(i=0;i<j;i++)
		{
			stringr[i]=string[j-i-1];
		}
		stringr[i]='\0';
		result=newBigInteger(stringr);
		/* For k from 1 to a-i, do r=r*k */
		for(i=a-1;i>0;i--)
		{
			tmp=NULL;
			tmp=insertTail(tmp,a-i);
			temp->absvalue=tmp;
			result=mulBigInt(result,temp);
		}
		return result;	
	}
}
bigInteger cnp(unsigned long n, unsigned long p)
{
	/* Factorial need unsigned long int */
	if(n>p)
	{
		/* Just the definition of cnp */
		return quotientBigInt(factorial(n),mulBigInt(factorial(p),factorial(n-p)));
	} /* Or no result */
	else
	{
		return NULL;
	}
}

void printBigInteger (bigInteger nombre)
{
	/* Declaration */
	Element* temp=malloc(sizeof(Element));	
	
	/* Nombre is null, just print NULL so */
	if(nombre==NULL)
	{
		printf("NULL");
	}
	else
	{
		/* Easier to work with a list */
		temp=nombre->absvalue;
	
		/* List is null, just print NULL so */
		if(temp==NULL)
		{
			printf("NULL");
		} 
		else
		{
			/* Go to the begining of the bigInteger */
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			/* Print the sign if needed */
			if(nombre->sign == TRUE)
			{
				printf("-");
			}
		
			/* Foreach the bigInteger and print the 4 figures' packages at each step */
			while(temp != NULL)
			{
				if(temp->next == NULL)
				{
					printf("%d", temp->value);
				}
				else
				{	
					/* Don't forget to print the 0 if needed as we don't store them in the bigInteger */
					if(temp->value < 10)
					{
						printf("000");
						printf("%d", temp->value);
					}
					else if(temp->value < 100)
					{
						printf("00");
						printf("%d", temp->value);
					}
					else if(temp->value < 1000)
					{
						printf("0");
						printf("%d", temp->value);
					}
					else
					{
						printf("%d", temp->value);
					}
				}
				temp = temp->prev;
			}
		}
	}

	printf("\n\n");	
}

Boolean isNull (bigInteger nombre)
{
	/* Declaration */
	Element* temp=malloc(sizeof(Element));	
	
	/* Easier to work with a list */
	if(nombre!=NULL)
	{
		temp=nombre->absvalue;
	}
	else
	{
		return TRUE;
	}

	/* Just check if the list is null or not */
	if(temp!=NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}

int compareBigInt (bigInteger nombre1, bigInteger nombre2)
{
	/* Declarations */
	int i=1,j=1;
	Element* temp=malloc(sizeof(Element));	
	Element* tem=malloc(sizeof(Element));

	/* Both aren't null */
	if(nombre1!=NULL && nombre2!= NULL)
	{
		/* Easier to work with list */
		temp=nombre1->absvalue;
		tem=nombre2->absvalue;
	} 
	else /* Else it's a bit easier */
	{
		if(nombre1==nombre2)
		{
			return 0;
		}
		else if(nombre1==NULL)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}	

	/* No null list ? */
	if(temp!=NULL && tem!=NULL)
	{
		/* Maybe signs facilite our work ? */
		if(nombre1->sign==TRUE && nombre2->sign==FALSE)
		{
			return -1;
		}
		else if(nombre1->sign==FALSE && nombre2->sign==TRUE)
		{
			return 1;
		}
		else
		{
			/* Count the number of 4 figures' packages in nombre 1 */
			while(temp->next != NULL)
			{	
				i++;
				temp=temp->next;
			}
	
			/* Count the number of 4 figures' packages in nombre2 */
			while(tem->next != NULL)
			{	
				j++;
				tem=tem->next;			
			}
		
			/* Different number of package ? That's over so */
			if(i > j)
			{
				if(nombre1->sign==TRUE)
				{
					return -1;
				}
				else
				{	
					return 1;
				}
			}
			else if(i < j)
			{
				if(nombre1->sign==TRUE)
				{
					return 1;
				}
				else
				{	
					return -1;
				}
			}
			else	/* Same number */
			{
				/* Just compare the values */
				if(temp->value > tem->value)
				{	
					 if(nombre1->sign==TRUE)
					{
						return -1;
					}
					else
					{	
						return 1;
					}
				}
				else if(temp->value < tem->value)
				{
					if(nombre1->sign==TRUE)
					{
						return 1;
					}
					else
					{	
						return -1;
					}
				}
				else
				{
					while(temp->prev!=NULL)
					{
						temp=temp->prev;
						tem=tem->prev;
						if(temp->value > tem->value)
						{	
							 if(nombre1->sign==TRUE)
							{
								return -1;
							}
							else
							{	
								return 1;
							}
						}
						else if(temp->value < tem->value)
						{
							if(nombre1->sign==TRUE)
							{
								return 1;
							}
							else
							{	
								return -1;
							}
						}
					}
				}	
			}
		}
		/* Strictly equals numbers */
		return 0;
	}
	else /* One list at least is null */
	{
		if(tem==NULL)
		{
			return 1;
		}
		else if(temp==NULL)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}	
}

int signBigInt(bigInteger a)
{
	/* a is null */
	if(isNull(a))
	{
		return 0;
	} /* a is 0 */
	else if(a->absvalue->value == 0)
	{
		return 0;
	} /* a < 0 */
	else if(a->sign == TRUE)
	{
		return -1;
	}
	else /* a > 0 */
	{
		return 1;
	}
}

Boolean equalsBigInt(bigInteger a, bigInteger b)
{
	/* compareBigInt(a,b)==0 when a=b */
	if(compareBigInt(a,b)==0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
