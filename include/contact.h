#pragma once

#define MAX_FIRSTNAME_LEN 64
#define MAX_LASTNAME_LEN 64
#define MAX_PHONE_LEN 16
#define MAX_EMAIL_LEN 128

struct Contact
{
    char firstname[MAX_FIRSTNAME_LEN];
    char lastname[MAX_LASTNAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
};