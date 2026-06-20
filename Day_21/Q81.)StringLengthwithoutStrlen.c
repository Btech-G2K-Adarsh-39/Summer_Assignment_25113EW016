#include <stdio.h>

int findLen(char* s) {
  	int l = 0;
    
  	// Count each character from start to end
    while (s[l]) l++;
  
  	return l;
}

int main() {
    char s[] = "Geeks";
    
    printf("%d", findLen(s));
    return 0;
}