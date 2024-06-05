#include <cs50.h>
#include <stdio.h>

int main(void){
    //declareing the variable
    int myheight;
    do
    {
        //assigning the variable
        myheight = get_int("How tall is your pyramid? ");
    }
    //checking the variable for a positive integer
    while(myheight < 1);

    const int n = myheight;
    for(int i=0; i < n; i++)
    {
         printf("%d\n", i);
    }
}
