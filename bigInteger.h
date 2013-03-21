/*
* Prototype of bigIntegers functions
* By Isaac Chiboub - isaac.chiboub@utbm.fr
* And Thibault Miclo - thibault.miclo@utbm.fr
*
* Last edit : 23/12/11
*/

typedef struct {
	Boolean sign;
	Dlist absvalue;
} nb; /* bigInteger Structure */

typedef nb* bigInteger; /* Define a bigInteger */

/*
* newBigInteger - make a bigInteger with user input
* Arguments
* - char nb[] - An array of char, inputed by the user
*
* Return : bigInteger, a pointer on the newly created bigInteger
*
*/
bigInteger newBigInteger(char nb[]);

/*
* inputToValidNb - Replace wrong caracters by 0
* Arguments :
* - int a - A char
*
* Return : Ascii value of 0 is the char is wrong
* else return a
*
*/
int inputToValidNb(int a);

/*
* sumBigInt - computes the sum between a bigInteger A and a bigInteger B
* Arguments
* - bigInteger A - One of the bigIntegers
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the sum
*
*/
bigInteger sumBigInt(bigInteger a, bigInteger b);


/*
* diffBigInt - computes the diff between a bigInteger A and a bigInteger B
* Arguments
* - bigInteger A - One of the bigIntegers
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the diff
*
*/
bigInteger diffBigInt(bigInteger a, bigInteger b);


/*
* sumBigInt - computes the multiplication between a bigInteger A and a bigInteger B
* Arguments
* - bigInteger A - One of the bigIntegers
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the multiplication
*
*/
bigInteger mulBigInt(bigInteger a, bigInteger b);


/*
* sumBigInt - computes the quotient of bigInteger A / bigInteger B
* Arguments
* - bigInteger A - The divided bigInteger
* - bigInteger B - The divisor bigInteger
*
* Return : bigInteger, a pointer on the result bigInteger, the quotient
*
*/
bigInteger quotientBigInt(bigInteger a, bigInteger b);


/*
* getNumberN - useful for quotientBigInt, to go down the number N at each step
* Arguments
* - bigInteger A - bigInteger where we seek the number
* - int n - position of the number in the bigInteger
*
* Return : Return the n-number of bigInteger A
*
*/
int getNumberN(bigInteger a,int n);


/*
* restBigInt - compute the rest of the division : bigInteger A / bigInteger B
* Arguments
* - bigInteger A - The divided bigInteger
* - bigInteger B - The divisor bigInteger
*
* Return : bigInteger, a pointer on the result bigInteger, the rest
*
*/
bigInteger restBigInt(bigInteger a, bigInteger b);

/*
* restBigInt - compute the greatest commom divisior of two bigIntegers A and B : gcd(A,B)
* Arguments
* - bigInteger A - The first bigInteger
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the gcd
*
*/
bigInteger gcdBigInt(bigInteger a, bigInteger b);

/*
* restBigInt - compute the lowest common multiple of two bigIntegers A and B : lcm(A,B)
* Arguments
* - bigInteger A - The first bigInteger
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the rest
*
*/
bigInteger lcmBigInt(bigInteger a, bigInteger b);

/*
* restBigInt - compute the factorial of a number
* Arguments
* - unsigned long a - An integer, unsigned
*
* Return : bigInteger, a pointer on the result bigInteger, the factorial
*
*/
bigInteger factorial(unsigned long a);

/*
* cnpBigInt - compute the combinatorial of two integers n and p
* Arguments
* - bigInteger A - The first bigInteger
* - bigInteger B - The second one
*
* Return : bigInteger, a pointer on the result bigInteger, the rest
*
*/
bigInteger cnp(unsigned long n, unsigned long p);

/*
* printBigInteger - print on the screen a bigInteger
* Arguments
* - bigInteger nombre - The bigInteger you want to print
* 
* Return : void
*
*/
void printBigInteger (bigInteger nombre);

/*
* isNull - test if a bigInteger is null or not
* Arguments
* - bigInteger nombre - The bigInteger you want to test
* 
* Return
* - true if it's null
* - false otherwise
*
*/
Boolean isNull (bigInteger nombre);

/*
* compareBigInt - compare two bigIntegers
* Arguments
* - bigInteger nombre1 - The first bigInteger
* - biginteger nombre2 - The second 
*
* Return :
* - 0 if equal
* - 1 if nombre1 > nombre2
* - (-1) if nombre1 < nombre 2
*
*/
int compareBigInt (bigInteger nombre1, bigInteger nombre2);

/*
* signBigInt - return the sign of the bigInteger
* Arguments
* - bigInteger a - The tested bigInteger
* 
* Return :
* - 0 if null
* - 1 if a > 0
* - (-1) if a < 0
*
*/
int signBigInt(bigInteger a);

/*
* equalsBigInt - test the equality between two bigIntegers
* Arguments
* - bigInteger a - The first bigInteger
* - biginteger b - The second 
*
* Return :
* - true if equal
* - false otherwise
*
*/
Boolean equalsBigInt(bigInteger a, bigInteger b);
