/*


#kn1ght - Alphanumeric Shellcode Encoder
#Coded By. roissy
#Concat: roissy@protonmail.com

     ,.
,----------.
|    I     |
| FUCKING  |
|   SUCK   |
|    IT    |
`----------'               ,--------.
     ||  |)___(|          |  ME TOO  |
     ||  /_   _\          |  FUCKNUT |
     || //_\_/_\\          )---------'
     || |\/~"~\/|    _.--.
    .-| /\\   //\   /  ,,, ,/
    |_/~ ,-~~~-. \( >c;^<  /`/
     \  .       . \~~>--'_//~
      `-|       / | / `\~_/
       |_.     : / //> // \`-._
       /  \___.~~\ \\ (/\. \._ ~`-._
       \   `_=    )|\)  / . \ ~`-.,-'
        \_`"  `--~  \__/   `,`-.
                            ~~~


The MIT License (MIT)

Copyright (c) 2016 roissy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <stdio.h>
#include <string.h>

#define SIZE 1024

const char *hexdb[]= {

    "20", /*   */     "21", /* ! */     "22", /* " */    "23", /* # */
    "24", /* $ */     "25", /* % */     "26", /* & */    "27", /* ' */
    "28", /* ( */     "29", /* ) */     "2a", /* * */    "2b", /* + */
    "2c", /* , */     "2d", /* - */     "2e", /* . */    "2f", /* / */
    "30", /* 0 */     "31", /* 1 */     "32", /* 2 */    "33", /* 3 */
    "34", /* 4 */     "35", /* 5 */     "36", /* 6 */    "37", /* 7 */
    "38", /* 8 */     "39", /* 9 */     "3a", /* : */    "3b", /* ; */
    "3c", /* < */     "3d", /* = */     "3e", /* > */    "3f", /* ? */
    "40", /* @ */     "41", /* A */     "42", /* B */    "43", /* C */
    "44", /* D */     "45", /* E */     "46", /* F */    "47", /* G */
    "48", /* H */     "49", /* I */     "4a", /* J */    "4b", /* K */
    "4c", /* L */     "4d", /* M */     "4e", /* N */    "4f", /* O */
    "50", /* P */     "51", /* Q */     "52", /* R */    "53", /* S */
    "54", /* T */     "55", /* U */     "56", /* V */    "57", /* W */
    "58", /* X */     "59", /* Y */     "5a", /* Z */    "5b", /* [ */
    "5c", /* \ */     "5d", /* ] */     "5e", /* ^ */    "5f", /* _ */
    "60", /* ` */     "61", /* a */     "62", /* b */    "63", /* c */
    "64", /* d */     "65", /* e */     "66", /* f */    "67", /* g */
    "68", /* h */     "69", /* i */     "6a", /* j */    "6b", /* k */
    "6c", /* l */     "6d", /* m */     "6e", /* n */    "6f", /* o */
    "70", /* p */     "71", /* q */     "72", /* r */    "73", /* s */
    "74", /* t */     "75", /*", */     "76", /* v */    "77", /* w */
    "78", /* x */     "79", /* y */     "7a", /* z */    "7b", /* { */
    "7c", /* | */     "7d", /* } */     "7e"  /* ~ */  };


char asciidb[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

void plaintext(char *);
void plaintextreverse(char *);

int main(int argc, char* argv[]){

    printf("kn1ght - Alphanumeric Shellcode Encoder, Coded By. roissy - MIT Licence\n\n");

    char input[SIZE];

    printf("Enter String:");
    fgets(input,SIZE,stdin);

    // Encode
    printf("\nHex:\n\n");

    plaintext(input);
    printf("\n");
    //plaintextreverse(input);
    printf("\n");

    return 0;

}

void plaintext(char *arg){

    int i,x;
    for(i=0;i<strlen(arg);i++){
        for(x=0;x<95;x++){
            if(arg[i] == asciidb[x]){
                printf("\\x%s", hexdb[x]);
            }
        }
    }

}

void plaintextreverse(char *arg){

    int i,x;
    for(i=strlen(arg);i>=0;i--){
        for(x=0;x<95;x++){
            if(arg[i] == asciidb[x]){
                printf("\\x%s", hexdb[x]);
            }
        }
    }

}
