#include <gmp.h>
#include <gmpxx.h>
#include <stdio.h>
#include <assert.h>
#include<cstdlib>
#include<ctime>

int main(){

  //define the inputs to be used
  char inputStr[1024]; // char string for input
  mpz_t n;
  int flag,time_out=60;

  printf ("Enter your number: ");
  scanf("%1023s" , inputStr); //take input value

  //Initialize the number n
  mpz_init(n);
  mpz_set_ui(n,0);

  //Parse the input string as a base 10 number
  flag = mpz_set_str(n,inputStr, 10);
  assert (flag == 0); // If flag is not 0 then the operation failed


  printf ("Pollard's Rho Algorithm: ");
  printf("\n");

  mpz_class w (n);
  mpz_class q (n);
  mpz_class n_val (n);

  next_factor:
  mpz_class l (w);
  mpz_class c (1);
  mpz_class x (2);
  mpz_class x_1(2);

  //check for input correctness
 //Do not accept negative numbers or zero

if (w<1)
     {
   printf ("Enter a positive number. ");
   return 0;
    }

 //Start the Pollard's Rho algorithm

 clock_t t; //Define and start timer
  t=clock();

  x_1=x_1*x_1+3;//Our function : f(x)= x^2+3
 mpz_class p;
 mpz_class x_x_1;
 x_x_1=abs(x_1-x);//x'=x'-1
 mpz_gcd (p.get_mpz_t(), x_x_1.get_mpz_t(), w.get_mpz_t());//get gcd( (x'-x),n)


while(p==1)//check if gcd is 1 then iteratively compute f(x) on x and twice on x'
{
    x=x*x+3;
    mpz_powm (x.get_mpz_t(), x.get_mpz_t(), c.get_mpz_t(), w.get_mpz_t());
    x_1=x_1*x_1+3;
    mpz_powm (x_1.get_mpz_t(), x_1.get_mpz_t(), c.get_mpz_t(),w.get_mpz_t());
    x_1=x_1*x_1+3;
    mpz_powm (x_1.get_mpz_t(), x_1.get_mpz_t(), c.get_mpz_t(), w.get_mpz_t());
    x_x_1=abs(x_1-x);
    mpz_gcd (p.get_mpz_t(), x_x_1.get_mpz_t(), w.get_mpz_t());
    if(time_out<(clock()-t)/CLOCKS_PER_SEC)
        goto triv_div;
}
printf("\n");
printf("Factor: ");

if(p>1&&p<w) // for gcd greater than 1, p is a factor
{

    w=w/p; //
    mpz_out_str(stdout,10,p.get_mpz_t());
    goto next_factor;
}

else if (p==w) //Then test has failed
{
     mpz_out_str(stdout,10,l.get_mpz_t());
     printf("\n");
     printf("Test has failed after the above factor/factors!");
     printf("\n");

}
triv_div:
 t=clock()-t;
 printf("\n");
 printf("Time taken: %f seconds",((float)t)/CLOCKS_PER_SEC);
 printf("\n");
 printf("\n");
 printf("Trial Division:");
 printf("\n");

//trivial division

  mpz_class fact(1);
  mpz_class sqrt_n(q);
  mpz_sqrt(sqrt_n.get_mpz_t(),sqrt_n.get_mpz_t());

 clock_t y;
 y=clock();

   int fact_count=0;
    mpz_class last_fact;


for(fact=2;fact<=sqrt_n;fact++)
{

if (q%fact==0)
{   fact_count++;
    printf("\n");
    printf("Factor: ");
    mpz_out_str(stdout,10,fact.get_mpz_t());
    printf(" ");
    q=q/fact;
    last_fact=q;
    mpz_class sqrt_q(q);
    mpz_sqrt(sqrt_q.get_mpz_t(),sqrt_q.get_mpz_t());
    sqrt_n=sqrt_q;
    if(q%fact==0)//check for repeated factors
        {
        fact--;
        }
}
}




 if(fact_count==0 ){//This section prints n as a factor if it is prime
    printf("\n");
    printf("Factor: ");
    mpz_out_str(stdout,10,n_val.get_mpz_t());
 }

 if(fact==sqrt_n&&fact_count>=1){//This section prints n as a factor if it is prime
    printf("\n");
    printf("Factor:");
    mpz_out_str(stdout,10,q.get_mpz_t());


 }
else {
  printf("\n");
    printf("Factor: ");
    mpz_out_str(stdout,10,last_fact.get_mpz_t());

}

  y=clock()-y;
  printf("\n");
 printf("Time taken: %f seconds",((float)y)/CLOCKS_PER_SEC);
 printf("\n");
  mpz_clear(n);

  printf("\n");
  return 0;

}
