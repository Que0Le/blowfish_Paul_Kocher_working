#include <stdio.h>
#include <string.h>
#include "blowfish.h"

int main(void)
{
    // This text should be devided by 8. In real life, 
    // add more characters if needed.
    char plaintext[] = "This is a random message";
    printf("Text length: %d\n", (int)strlen(plaintext));

    char encrypted[strlen(plaintext)];
    memset(encrypted, '\0', (int)strlen(plaintext));
    char decrypted[strlen(plaintext)];
    memset(decrypted, '\0', (int)strlen(plaintext));
  
  
    BLOWFISH_CTX ctx;
    char salt[] = "TESTKEY";

    Blowfish_Init(&ctx, (unsigned char *)salt, strlen(salt));

    int i;
    unsigned long L, R = 2;
    for (i = 0; i < strlen(plaintext); i+=8)
    {
        // Copy L and R
        memcpy(&L, &plaintext[i], 4);
        memcpy(&R, &plaintext[i+4], 4);
        // Encrypt the parts
        Blowfish_Encrypt(&ctx, &L, &R);
        // Store the output
        memcpy(&encrypted[i], &L,  4);
        memcpy(&encrypted[i+4], &R, 4);
        // Decrypt 
        Blowfish_Decrypt(&ctx, &L, &R);
        // Store result
        memcpy(&decrypted[i], &L, 4);
        memcpy(&decrypted[i+4], &R, 4);
    }
    printf("plaintext:  %.*s\n", (int)strlen(plaintext), plaintext);
    printf("encrypted:  %.*s\n", (int)strlen(plaintext), encrypted);
    printf("decrypted:  %.*s\n", (int)strlen(plaintext), decrypted);
    printf("\n\n\n");
}
