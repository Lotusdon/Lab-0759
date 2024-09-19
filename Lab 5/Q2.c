
#include <stdio.h>

int main() {
    char day,vac;
    int sleep;
    

    printf("enter the day of the week\n 'M' for monday \n'T' for tuesday \n'W'for wednesday\n'H' for thursday\n'F' for friday\n'S'for saturday\n'U' for sunday\n");
    scanf(" %c",&day);
    printf("enter if on a vaction ('O') or if not on a vacation ('N')\n");
    scanf(" %c",&vac);
   
    
    if ( day = 'M' || 'T' || 'W' || 'H' || 'F')
     
    {  
        switch(vac) 
        {
          case 'O':
          sleep = 1;
          break;
          
          case 'N':
          sleep=0 ;
          break;
          
          default: printf("wrong vacation type entered\n"); 
            
        };
    
    }
    
    else if ('S' || 'U') 
    {
     
         switch(vac) 
         {
         case 'O': sleep = 1 ;
         break;
         
         case 'N': sleep = 0 ;
         break;
         
         default : printf("wrong vacation type entered\n"); 
             
         };
    }
    
   else { printf("wrong day entered");}
   
    if ( sleep = 0 ) {
    printf("you can not sleep in" ) ; }
    else {
    printf("you can sleep in " ) ;}
    return 0;
    
}


   
