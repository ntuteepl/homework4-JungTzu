
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main(){
  
  int n;
  scanf("%d", &n);
  assert(1 <= n && n <= 50);
  int a[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++){
    bool prime = true;
    for (int j = 2 ; ((j*j)<=a[i]) && prime ; j++)
      if (a[i]%j == 0)
        prime = false;

    if (prime == true)
      printf("YES\n");
    if (prime == false)
      printf("NO\n");
  }
}
