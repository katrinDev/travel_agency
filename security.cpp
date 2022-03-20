#include "myLib.h"

void encryption(string& password, int num) {
    string alf = "abcdefghijklmnopqrstuvwxyz";
    string enc = "adventurbcfghijklmopqswxyz";
    char ch;

    for (size_t j = 0; j <= password.length(); j++) {
        ch = password[j];
        if (num == 1) {
            if (isalpha(ch)) {
                for (size_t i = 0; i <= alf.length(); i++) {
                    if (alf[i] == ch) {
                        ch = enc[i];
                        break;
                    }
                    if (isupper(ch)) {
                        if (ch == toupper(alf[i])) {
                            ch = (char)toupper(enc[i]);
                            break;
                        }
                    }
                }
            }
            if (isdigit(ch)) {
                ch++;
            }
        }
        if (num == 2) {
            if (isalpha(ch)) {
                for (size_t i = 0; i <= enc.length(); i++) {
                    if (enc[i] == ch) {
                        ch = alf[i];
                        break;
                    }
                    if (isupper(ch)) {
                        if (ch == toupper(enc[i])) {
                            ch = (char)toupper(alf[i]);
                            break;
                        }
                    }
                }
            }
            if (isdigit(ch)) {
                ch--;
            }
        }
        password[j] = ch;
    }
}

bool password_check(string name) {
    bool n = true;
    string k;
    for (int i = 0; name[i] != '\0'; i++) {
        char c = name[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || isdigit(c))) {
            n = false;
            break;
        }
    }
    if (!n) {
        printf("\tВы можете использовать только латинские буквы, числа или символ '_'!\n");

    }
    return n;
}



