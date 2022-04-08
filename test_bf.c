#include <stdio.h>
#include <string.h>
#include "blowfish.h"

int main(void)
{
    // This text should be devided by 8. In real life, 
    // add more characters if needed.
    char plaintext[] = 
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
    "Aliquam eget blandit augue. Vestibulum lobortis erat ligula, "
    "non rhoncus orci consectetur vitae. Aenean a risus purus. "
    "Maecenas ullamcorper et purus quis tempor. "
    "Pellentesque gravida scelerisque leo quis ultrices. "
    "Ut in interdum mi. Curabitur eget eros non magna facilisis "
    "pellentesque. Vivamus nec lacus nulla. Maecenas sed dui a "
    "nibh pretium malesuada. Quisque convallis lorem scelerisque "
    "consequat pulvinar. Suspendisse varius ligula in lorem molestie.";

    printf("Text length: %d\n\n", (int)strlen(plaintext));

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
    
    printf("plaintext:\n%.*s\n", (int)strlen(plaintext), plaintext);
    printf("---------------------------------------------------\n");
    printf("encrypted:\n%.*s\n", (int)strlen(plaintext), encrypted);
    printf("---------------------------------------------------\n");
    printf("decrypted:\n%.*s\n", (int)strlen(plaintext), decrypted);
    printf("\n\n\n");
}
