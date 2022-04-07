This is a copy of Kocher implementation back in 1997. I added a very simple test file that use Kocher's code to encrypt and decrypt a text line.

### How the implementation works

Please see the Wikipedia page for how the algorithm works internally.
For developer, we need to understand a few important features:

-  Blowfish is a symmetric-key block cipher.
-  The algorithm works with 8 bytes block-based.
-  The caller needs to split that 8 bytes block into 2 part, Left and Right.


### Run the code

`blowfish_test.c`, `blowfish.c`, `blowfish.h` were written by Paul Kocher. Run it with:

```bash
gcc -Wall blowfish_test.c blowfish.c -o b; ./b
# 272A5DF333FD2 33A2830A71BB4
# Test encryption failed.
# Test decryption OK
```

To run my simple test:

```bash
gcc -Wall test_bf.c blowfish.c -o test_bf; ./test_bf
# length: 24
# plaintext:  This is a random message
# encrypted:  l+����*u�&��2�K�[�C�,\�
# decrypted:  This is a random message
```
