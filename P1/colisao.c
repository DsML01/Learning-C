#include <stdio.h>

int main ()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int ny = n, nx = m;

  int mapa[ny][nx];

  for(int iy = 0; iy < ny; iy++)
  {
    for(int ix = 0; ix < nx; ix++)
    {
      scanf("%d", &mapa[iy][ix]);
    }
  }

  int c;
  scanf("%d", &c);

  char movimentos[c];

  //descobrir como que eu posso ler essa string

  for(int ic = 0; ic < c; ic++)
  {
    scanf(" %c", &movimentos[ic]);
  }

  int x,y;
  scanf("%d%d", &x,&y);

  for(int ic = 0; ic < c; ic++)
  {
    //printf("%c", movimentos[ic]);
  }

  //printf("\n(%d,%d)\n", x,y);

  for(int ic = 0; ic < c; ic++)
  {
    //printf("%c", movimentos[ic]);
    if(movimentos[ic] == 'C' && y-1 < 0) y += 0;
    else if(movimentos[ic] == 'E' && x-1 < 0) y += 0;
    else if(movimentos[ic] == 'D' && x+1 >= nx) x += 0;
    else if(movimentos[ic] == 'B' && y+1 >= ny) y += 0;
    else if(movimentos[ic] == 'C' && mapa[y-1][x] == 1) y--;    
    else if(movimentos[ic] == 'E' && mapa[y][x-1] == 1) x --;
    else if(movimentos[ic] == 'D' && mapa[y][x+1] == 1) x ++;
    else if(movimentos[ic] == 'B' && mapa[y+1][x] == 1) y ++;
  }

  printf("(%d,%d)\n", y,x);

  return 0;
}