#include <stdio.h>

double F(double x, double c) {  //Defines the function F(x)

  return (100*(c-(x*x))*(c-(x*x)))+((1-x)*(1-x));
  // Defines output of function
  
}

void write_file (char *filename, double y0, double y1) {

  int i;  //Defines i to use as a loop counter
  double x, z2, c;   //z2 = User input for x1
  FILE *p_file;  //Points to file location in memory
  
  /* FOLLOWING CODE ALLOWS USER INPUT FOR x1 RANGE*/
  
  FILE *fp; //Points to file location in memory
  printf("Input value for x1: \n"); //User input prompt
  scanf("%lf", &z2); //Scans for user input
  fp = fopen("data.txt", "w");  //Opens data.txt for writing
  fprintf(fp, "%lf\n", z2);  //Prints user inputted value into file
  fclose(fp);  //Closes file
  fp = fopen("data.txt", "r");  //Opens file for reading
  fscanf(fp, "%lf", &c);  //Scans file for user input
  printf("User inputted x1 = %lf\n", c);  //User input feedback
  fclose(fp);  //Closes file
  
  
  p_file = fopen(filename, "w");  //Opens file for writing

  for (i = 0; i<=100; i++ ) { //Defines conditions for loop
    
    x = y0 + i*(y1-y0)/100.;  
    //Determines value for x within interval between y0 and y1 values (yet to
    //be specified). Division by 100 allows the loop condition to produce 100 values.
    
    fprintf(p_file, "%lf, %lf\n", x, F(x, c));
    // Prints values of x and F(x) to the file (name yet to be defined)
    
  }
}

int main () {

/* See file ex2_a2 for non-user input file */

  FILE *fp;
  double z0, z1, a, b;
  //z0 = User input for x0_min
  //z1 = User input for x0_max
  
  /* FOLLOWING CODE ALLOWS USER INPUT TO DEFINE x0 VALUE RANGE*/
  
  printf("Input value for lower limit of x0: \n"); //User input prompt
  
  scanf("%lf", &z0); //Scans for user input value
  fp = fopen("data.txt", "w"); //Opens file for writing
  fprintf(fp, "%lf\n", z0); //Prints value inputted into file
  fclose(fp); //Closes file
  fp = fopen("data.txt", "r"); //Opens file for reading
  fscanf(fp, "%lf", &a); //Scans file for value of z0
  printf("User inputted x0_min = %lf\n", a); //Prints user input value
  fclose(fp); //Closes file
  
  printf("Input value for upper limit of x0: \n"); //User input prompt
  
  scanf("%lf", &z1); 
  fp = fopen("data.txt", "w"); 
  fprintf(fp, "%lf\n", z1);
  fclose(fp);
  fp = fopen("data.txt", "r"); 
  fscanf(fp, "%lf", &b);
  printf("User inputted x0_max = %lf\n", b);
  fclose(fp);
  
  
  write_file("values.txt", a, b);
   //Names the file being written to, as well as the values of y0 and y1 (the 
  //arguments. This runs the write file function and hence writes the file 
  //values.txt with the values from the function F(x). 
  
  printf("Enter 'cat values.txt' to see written data file\n");
  //Makes the user interface more pleasant
  
}












