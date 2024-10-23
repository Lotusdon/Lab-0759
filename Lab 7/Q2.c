#include <stdio.h>

int main() {
    char x;
    int ac = 0, ec = 0, ic = 0, oc = 0, uc = 0;  
    char arr[100];

  
    printf("Enter string: ");
    scanf("%s", arr);

    for (int i = 0; arr[i] != '\0'; i++) {
        x = arr[i];
        switch (x) {
            case 'a': ac++; break;
            case 'e': ec++; break;
            case 'i': ic++; break;
            case 'o': oc++; break;
            case 'u': uc++; break;
            default: break;
        }
    }

   
    printf("Vowel counts:\n");
    printf("a: %d\n", ac);
    printf("e: %d\n", ec);
    printf("i: %d\n", ic);
    printf("o: %d\n", oc);
    printf("u: %d\n", uc);

    return 0;
}
