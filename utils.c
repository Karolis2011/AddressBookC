#include <contactlist.h>
#include <stdlib.h>
#include <string.h>

struct Contact make_contact(const char *firstname, const char *lastname, const char *phone, const char *email)
{
    struct Contact value;
    strncpy(value.firstname, firstname, MAX_FIRSTNAME_LEN);
    strncpy(value.lastname, lastname, MAX_LASTNAME_LEN);
    strncpy(value.phone, phone, MAX_PHONE_LEN);
    strncpy(value.email, email, MAX_EMAIL_LEN);
    value.firstname[MAX_FIRSTNAME_LEN - 1] = 0;
    value.lastname[MAX_LASTNAME_LEN - 1] = 0;
    value.phone[MAX_PHONE_LEN - 1] = 0;
    value.email[MAX_EMAIL_LEN - 1] = 0;
    return value;
}

void init_list(struct ContactList *list)
{
    list->head = NULL;
    list->tail = NULL;
    ContactList_append(list, make_contact("Karolis", "Kundrotas", "841200551", "kundrotaskarolis3@gmail.com"));
    ContactList_append(list, make_contact("Marija", "Bagdonaite", "861522458", "marijabag@gmail.com"));
    ContactList_append(list, make_contact("Evelina", "Kriciunaite", "865448445", "evelinakris@gmail.com"));
    ContactList_append(list, make_contact("Tadas", "Kumplinas", "8525456485", "tadux@gmail.com"));
    ContactList_append(list, make_contact("Justas", "Nablinskas", "865548231", "pranauskis@gmail.com"));

    ContactList_append(list, make_contact("Laura", "Lekinskytė", "864903493", "larux@gmail.com"));
    ContactList_append(list, make_contact("Emijila", "Galvynytė", "865587555", "larux@gmail.com"));
    ContactList_append(list, make_contact("Antanas", "Langauskas", "869110549", "antakas@gmail.com"));
    ContactList_append(list, make_contact("Valda", "Pociūtė", "868141017", "valdte@gmail.com"));
    ContactList_append(list, make_contact("Tautvydė", "Zagorskytė", "867699466", "tautte@gmail.com"));
}