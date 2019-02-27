/* 
 * File:   main.c
 * Author: jcunha
 *
 * Created on 26 de Fevereiro de 2019
 * 
 *       Worksheet08
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

/*
 * -------------   Example 1   ----------------------
 */

int add(int p, int q);    //function declaration
 
void example1(void){
  int a, b, result;
  printf("Enter two numbers:");
  scanf("%d%d",&a,&b);
  result=add(a,b);
  printf("Sum of %d and %d is %d\n",a,b,result);
}
int add(int p,int q){  //function definition
  return p+q;          //Body of the function
}

/*
 * -------------   Example 2   ----------------------
 */

int max(int num1, int num2); /* function declaration */ 

void example2(void){
   int a = 100, b = 200, ret; /*local variable definition */
   ret = max(a, b); /* calling a function to get max value */
   printf("Max value is : %d\n", ret);
} 
 
/* function definition returning the max between two numbers */ 
int max(int num1, int num2) {
   int result; 		/* local variable declaration */ 
   if (num1 > num2){
      result = num1;
   }else{
      result = num2;}
   return result; 
}


/*
 * -------------   Example 3   ----------------------
 *
 *   Static local variable
 */

int max_count(int num1, int num2); 
 
void example3(void) {
   int a = 100, b = 200, ret; //automatic local var
   ret = max_count(a, b); 
   printf("Max value is : %d\n", ret);
   max_count(3, 2);
} 
 
int max_count(int num1, int num2) {
   int result; 		// automatic local variable
   static int count=0;	//static local variable
   if (num1 > num2){
      result = num1;
   }else{
      result = num2;
   }
   printf("Call number %d.\n",++count);
   return result; 
}


/*
 * -------------   Example 4   ----------------------
 * 
 *    Standard C Library Functions.
 */
 
/*
 * these includes are necessary for this example, and 
 * were placed at the top of this file
 * 
 * #include <stdlib.h>
 * #include <stdio.h>
 * #include <math.h>
 * #include <time.h>
 */

void delay (void);
 
void example4(void){
  int x;
  double a, cos_x;
  time_t start, end;
 
  x=abs(-7);//x is 7
  printf("abs(-7) is %d\n",x);
 
  a=ceil(5.1);//a is 6
  printf("ceil(5.1) is %lf\n",a);
 
  cos_x = cos(1.6543);
  printf("cos(1.6543) is %lf\n", cos_x);
 
  start = time(NULL);
  delay();
  end = time(NULL);
  printf("Difference in seconds:%f \n", difftime(end, start));
}
 
void delay (void) {
  int i,j; //automatic variables –visible only
           //within delay()
  for (i=0; i<100000; i++){ //outer loop
    for (j=0; j<20000; j++){ //inner loop
    } //do nothing 
  }
}


/*
 * -------------   Example 5   ----------------------
 * 
 *    Standard C Library Functions.
 */
 
/*
 * these includes are necessary for this example, and 
 * were placed at the top of this file
 * 
 * #include <stdlib.h>
 * #include <ctype.h>
 */

void example5(void){
   int c;
 
   printf("Give a leter to see if it is a number, a control or char:");
   c=getchar();
   if(isalpha(c)){
      printf("%c is a character\n",c);
   }
   if (isascii(c)){
      printf("%c is an ascii\n",c);
   }
   if(iscntrl(c)){
      printf("%c is  a control char\n",c);
   }
   if(isdigit(c)){
      printf("%c is a digit\n" ,c);
   }
   if(islower(c)){
      printf("%c is a lower case letter\n",c);
   }
   if(ispunct(c)){
      printf("%c is punctuation mark\n", c);
   }
   if(isspace(c)){
      printf("%c is a space\n",c);
   }
   if(isupper(c)){
      printf("%c is a capital letter\n",c);
   }
}


/*
 * -------------   Example 6   ----------------------
 * 
 *    Standard C Library Functions.
 */
 
/*
 * these includes are necessary for this example, and 
 * were placed at the top of this file
 * 
 * #include <stdlib.h>
 * #include <stdio.h>
 * #include <math.h>
 * #include <time.h>
 * #include <ctype.h>
 */

 
void example6(void){
   double x,y,z;
   int i;
   char c;
   float fp;
   x=10;
   y=log(x);
   printf("log(10) is %lf\n", y);
   x=2.0;
   y=4.0;
   z=pow(x,y); //z is 16
   printf("%lf ^ %lf  is %lf\n", x, y, z);
 
   printf("product of %f and %f is %f\n",x, y, x*y);
 
   putchar('B');
   putchar('\n');
 
   //see 10 random //numbers
   for(i=0;i<10;i++){
      printf("%d\t",rand());
   }
   printf("\n");
 
   srand(1234);  //How to initialize the random generator with a different value in every run?
 
   printf("Give me an integer, a floating point number, and a char:");
   scanf("%d %f %c", &i, &fp, &c);
   printf("Read:%d %f %c\n",i, fp, c);
 
   x=0.52;
   printf("x =%f radians\n", x);
   y=sin(x);
   printf("the sine of x =%f \n",y);
   printf("%f \n",sqrt(25.0)); //shows 5
 
   long timestamp;
   timestamp=time(NULL);
   printf("Number of seconds since 1/1/1970:%ld\n", timestamp);
   c=tolower('S');
   printf("c is  %c\n", c);
   c=toupper('s');
   printf("c is  %c\n", c);
 
}


/*
 * -------------   Exercise1   ----------------------
 */

/*
 * Funtion: iseven
 * 
 * tests is a given number is even
 * 
 * IN:   number - number to test
 * OUT:  1 if even, 0 if odd
 */
int iseven(int number) {

}



/*
 * -------------   Main   ----------------------
 */

/*
 *  To run the examples or exercises add the corresponding a function call 
 *  to main()
 */
int main(int argc, char** argv) {

    //call example
    example1();
    
    return (EXIT_SUCCESS);
}

