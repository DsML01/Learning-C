#include <math.h>
#include <stdio.h>
int rounds(int v1, int v2, int d1, int d2) {
  // v1 clodes upa atk
  // v2 bezaliel so bate
  if (v1 > 0) {
    if (ceil((double)v1 / d2) < ceil((double)v2 / d1)) {
      d1 = d1 + 50;
    } 
    else {
      v2 = v2 - d1;
    }
  }
  if (v2 > 0) {
    v1 = v1 - d2;
  }
  if (v1 > 0 && v2 > 0) {
    return rounds(v1, v2, d1, d2);
  }
  else {
    if (v1 > v2) {
      printf("Clodes\n");
    }
    else if (v2 > v1) {
      printf("Bezaliel\n");
    }
    return 0;
  }
  return 0;
}

void battles(n2) {
  int v1, v2, d1, d2;
  if (n2 > 0) {
    // v1 clodes
    // v2 bezaliel
    scanf("%d%d%d%d", &v1, &v2, &d1, &d2);
    rounds(v1,v2,d1,d2);
    battles(n2-1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  battles(n);

  return 0;
}