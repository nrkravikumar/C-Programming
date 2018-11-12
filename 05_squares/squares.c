#include <stdio.h>
#include <stdlib.h>

int maximum(int x,int y)
{
  if(x>y)
    {
      return x;
    }
  else
    {
      return y;
    }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  int w = maximum(size1,x_offset+size2);
  int h = maximum(size1,y_offset+size2);
  for(int y=0;y<h;y++)
    {
    for(int x=0;x<w;x++)
	{
	  if(((x >= x_offset && x < x_offset+size2) && (y == y_offset || y == y_offset+size2-1))||((y >= y_offset && y < y_offset+size2) && (x == x_offset ||x == x_offset+size2-1)))
	    {
	      printf("*");
	    }
	  else
	    {
	      if((x < size1 && (y==0 || y==size1-1)) || (y < size1 && (x==0 || x==size1-1)))
		{
		  printf("#");
		}
	      else
		{
		  printf(" ");
		}
	    }
	}
    printf("\n");

    }
}
