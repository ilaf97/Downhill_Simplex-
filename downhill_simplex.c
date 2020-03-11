#include <stdio.h>
#include <math.h>  //Required for use of 'pow' function

double F(double x0, double x1) {  //Defines the function F(x0, x1)

  return (100.*(x1-(x0*x0))*(x1-(x0*x0)))+((1.-x0)*(1.-x0));
  //Defines output of this function
}

double iteration(double e, double f, double g, double h) {
//Defines Equation 8 in task script to give iteration condition

  return sqrt((((e - h)*(e - h))/2.) + (((f - h)*(f - h))/2.) + (((g - h)*(g - h))/2.));
  //Defines output of this function
}


int main() {

  double a[2] = {0., 0.};  //Defines initial minimum vertex		
  double b[2] = {2., 0.};  //Defines initial maximum vertex
  double c[2] = {0., 2.};  //Defines initial middle-valued vertex
  
  int N, i; //Defines loop counters for main program and p_bar loop
  double y0, y1, y2, y_star, y_2star, y_bar, yl, ym, yh;
  double p_bar[2], p_star[2], p_2star[2], p0[2], p1[2], p2[2];
  double pl[2], pm[2], ph[2];
  //Declaration of variable types. Note that the largest y value is represented by 
  //yh, the middle value by ym and the smallest value by yl. The vertices which
  //correspond to these y values are represented by arrays labeled ph, pm and pl.
  //p0, p1 and p2 are the names of the vertices before they have been ordered from
  //largest to smallest. 
  
  for (N = 0; N <= 1000; N++) {  //Definition of FOR loop conditions for main program
  
    y0 = F(a[0], a[1]); 
    y1 = F(b[0], b[1]);
    y2 = F(c[0], c[1]);
    //Passes arguments to function to find values. These change for each loop and are
    //ordered from largest to smallest by the following IF/ELSE IF conditions.

    p0[0] = a[0]; p0[1] = a[1];
    p1[0] = b[0]; p1[1] = b[1];
    p2[0] = c[0]; p2[1] = c[1];
    //Sets values for vertices using all values in a, b and c arrays. This is reset for
    //each loop using output from flowchart.
  
  
    /* Following conditions determine yl, ym, yh and pl, pm, ph */ 
  
    if (y0 > y2 && y2 > y1) {
    //IF condition where y0 is largest and y1 is smallest
      yh = y0; 
      yl = y1;
      ym = y2;
      //Defines values for yl, ym and yh
      
      ph[0] = p0[0]; ph[1] = p0[1];
      pm[0] = p2[0]; pm[1] = p2[1];
      pl[0] = p1[0]; pl[1] = p1[1];
      //Defines values for pl, pm and ph arrays
    }
  
    else if (y0 > y1 && y1 > y2) {
    //ELSE IF condition where y0 is largest and y2 is smallest
      yh = y0; 
      yl = y2;
      ym = y1;
      //Defines values for yl, ym and yh
      
      ph[0] = p0[0]; ph[1] = p0[1];
      pm[0] = p1[0]; pm[1] = p1[1];
      pl[0] = p2[0]; pl[1] = p2[1];
      //Defines values for pl, pm and ph arrays
    }
       
    else if (y0 < y1 && y1 < y2) {
    //ELSE IF condition where y2 is largest and y0 is smallest
      yh = y2; 
      yl = y0;
      ym = y1;
      //Defines values for yl, ym and yh
      
      ph[0] = p2[0]; ph[1] = p2[1];
      pm[0] = p1[0]; pm[1] = p1[1];
      pl[0] = p0[0]; pl[1] = p0[1];
      //Defines values for pl, pm and ph arrays
    }
      
    else if (y0 < y2 && y2 < y1) {
    //ELSE IF condition where y1 is largest and y0 is smallest
      yh = y1; 
      yl = y0;
      ym = y2;
      //Defines values for yl, ym and yh
      
      ph[0] = p1[0]; ph[1] = p1[1];
      pm[0] = p2[0]; pm[1] = p2[1];
      pl[0] = p0[0]; pl[1] = p0[1];
      //Defines values for pl, pm and ph arrays
    }
        
    else if (y1 > y0 && y0 > y2) {
    //ELSE IF condition where y1 is largest and y2 is smallest
      yh = y1; 
      yl = y2;
      ym = y0;
      //Defines values for yl, ym and yh
      
      ph[0] = p1[0]; ph[1] = p1[1];
      pm[0] = p0[0]; pm[1] = p0[1];
      pl[0] = p2[0]; pl[1] = p2[1];
      //Defines values for pl, pm and ph arrays
    }
      
    else {
    //ELSE condition where y2 is largest and y1 is smallest
      yh = y2; 
      yl = y1;
      ym = y0;
      //Defines values for yl, ym and yh
      
      ph[0] = p2[0]; ph[1] = p2[1];
      pm[0] = p0[0]; pm[1] = p0[1];
      pl[0] = p1[0]; pl[1] = p1[1];
      //Defines values for pl, pm and ph arrays
    }
    
    /* yl, ym, yh and pl, pm, ph have now been determined. The following code
    preceding the IF ELSE tree - which considers the different flowchart conditions
    - sets all the values for the p_bar, p_star, y_bar and y_star quantities. */
    
    /* This following FOR loop considers all the different cases for pm and pl array 
    values to find the correct values for the p_bar array values */
    
    for (i = 0; i < 2; i++) {  //Defines a loop to run through array values
      
      if (pm[i] == 0.) {
        p_bar[i] = pl[i]/2.;  //Defines p_bar array values when pm[i]= 0
      }
      
      else if (pl[i] == 0.) {
        p_bar[i] = pm[i]/2.;  //Defines p_bar array for when pl[i] = 0
      }
    
      else if (pm[i] != pl[i]) {
        p_bar[i] = (pl[i] + pm[i])/2.;
        //Defines p_bar array values for when pl and pm are not equal
      }

      else { 
        p_bar[i] = pm[i];  //Defines p_bar arrays for when pm[i] = pl[i]
      }
    }    

    p_star[0] = (2. * p_bar[0]) - ph[0];
    p_star[1] = (2. * p_bar[1]) - ph[1];
    //Defines p_star array values
      
    y_bar = F(p_bar[0], p_bar[1]);
    y_star = F(p_star[0], p_star[1]);
    //Defines values for y_star and y_bar by passing p_bar and p_star array values
    //to F(x0, x1) function.
      
  
    /* Following IF ELSE tree represents flowchart. The 'NO ->' or 'YES ->'
    comments represent movement along flowchart decision tree branches to indicate
    which flowchart conditions are being considered in each IF ELSE statement. */
      
    if (y_star < yl) {  //YES
      p_2star[0] = (2. * p_star[0]) - p_bar[0]; 
      p_2star[1] = (2. * p_star[1]) - p_bar[1];
      //Sets p_2star array values
        
      y_2star = F(p_2star[0], p_2star[1]); 
      //Finds value of y_2star by passing p_2star array values to F(x0, x1) function
         
      if (y_2star < yl) {  //YES -> YES
        ph[0] = p_2star[0];
        ph[1] = p_2star[1];
        //Changes ph array values to p_2star array values
      }
       
      else {  //YES -> NO
        ph[0] = p_star[0];
        ph[1] = p_star[1];
        //Changes ph array values to p_star array values
      }
    }
          
    else {  //NO

      if (y_star > ym) {  //NO -> YES
      //Implies that y_star is also greater than yl
 
        if (y_star > yh) {  //NO -> YES -> YES
          p_2star[0] = (ph[0] + p_bar[0])/2.;
          p_2star[1] = (ph[1] + p_bar[1])/2.;
          //Sets p_2star array values
            
          y_2star = F(p_2star[0], p_2star[1]);
          //Finds value of y_2star by passing p_2star array values to F(x0, x1) function
            
          if (y_2star > yh ) {  //NO -> YES -> YES -> YES
            pm[0] = (pm[0] + pl[0])/2.;
            pm[1] = (pm[1] + pl[1])/2.;
            //Changes pm array values 
              
            ph[0] = (ph[0] + pl[0])/2.;
            ph[1] = (ph[1] + pl[1])/2.;
            //Changes ph array values

            /* Note that although flowchart demands that all pi's are changed using
            the above formula, (pl[0 or 1] + pl[0 or 1])/2. = initial pl[0 or 1]
            so pl does not need to be changed. */
          }
                      
          else {  //NO -> YES -> YES -> NO
            ph[0] = p_2star[0];
            ph[1] = p_2star[1];
            //Changes ph array values to p_2star array values
          }
        }
                
        else {  //NO -> YES -> NO
          ph[0] = p_star[0];
          ph[1] = p_star[1];
          //Changes ph array values to p_star array values

          p_2star[0] = (ph[0] + p_bar[0])/2.;
          p_2star[1] = (ph[1] + p_bar[1])/2.;
          //Sets p_2star array values
            
          y_2star = F(p_2star[0], p_2star[1]);
          //Finds value of y_2star by passing p_2star array values to F(x0, x1) function
                      
          if (y_2star > yh ) {  //NO -> YES -> NO -> YES
            pm[0] = (pm[0] + pl[0])/2.;
            pm[1] = (pm[1] + pl[1])/2.;
            //Changes pm array values
              
            ph[0] = (ph[0] + pl[0])/2.;
            ph[1] = (ph[1] + pl[1])/2.;
            //Changes ph array values
          }
                      
          else {  //NO -> YES -> NO -> NO
            ph[0] = p_2star[0];
            ph[1] = p_2star[1];
            //Changes ph array values to p_2star array values
          }
        }
      }
       
      else {  //NO -> NO
        ph[0] = p_star[0];
        ph[1] = p_star[1];
        //Changes ph array values to p_star array values
      }
    }
  
  /* End of flowchart */ 
   
    
  yh = F(ph[0], ph[1]); 
  ym = F(pm[0], pm[1]);
  yl = F(pl[0], pl[1]);
  //Re-calculates yh, ym and yl ready to be evaluated by iteration fucntion

  a[0] = ph[0]; a[1] = ph[1];
  b[0] = pm[0]; b[1] = pm[1];
  c[0] = pl[0]; c[1] = pl[1];
  //Sets the values of the a, b and c arrays to the new ph, pm and pl array values

  /*These following IF ELSE statements decide whether a minimum has been found or not,
  and what to output if the program is unsuccessful in finding a minimum */

    if (iteration(yl, ym, yh, y_bar) < pow(10.0, -8.0)) {
    //Condition for if program successful in locating minimum. This occurs when iteration
    //function < 10^-8
      printf("Minimum located within triangular plot formed by following vertices:\n");
      printf("P0 = (%lf, %lf)\n", a[0], a[1]);
      printf("P1 = (%lf, %lf)\n", b[0], b[1]);
      printf("P2 = (%lf, %lf)\n", c[0], c[1]);
      printf("yl = %lf, ym = %lf, yh = %lf\n", yl, ym, yh);
      printf("Number of iterations = %d\n", (N+1));
      N = 1000; //Sets N = 1000 to immediately end the FOR loop
    }  
    
    
    else if (N == 1000 && iteration(yl, ym, yh, y_bar) >= pow(10.0, -8.0)) {
    //Condition only satisfied if program fails to find minimum. Prints message to user
      printf("*** Minimum not found ***\n");
    }
    
    
    else {
      printf("Iteration no.: %d\n", (N+1)); 
      //Prints iteration no. to make output easier to interpret
      printf("P0 = (%lf, %lf), P1 = (%lf, %lf), P2 = (%lf, %lf)\n", a[0], a[1], b[0], b[1], c[0], c[1]);
      //Prints vertices for each iteration
      printf("\n");  
      //Prints vertex values and tarts new line to make output easier to read
    }
  }
}
