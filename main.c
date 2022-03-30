#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <contact.h>
#include <contactlist.h>
#include <utils.h>

int search(struct Contact contact, const char *needle)
{
    char *match = strstr(contact.firstname, needle);
    if (match != NULL)
    {
        return 1;
    }
    match = strstr(contact.lastname, needle);
    if (match != NULL)
    {
        return 1;
    }
    match = strstr(contact.phone, needle);
    if (match != NULL)
    {
        return 1;
    }
    match = strstr(contact.email, needle);
    if (match != NULL)
    {
        return 1;
    }
    return 0;
}

void print_matching(struct ContactList *list, const char *needle)
{
    int count = 0;
    struct ContactListNode *curr = list->head;
    while (curr != NULL)
    {
        if (search(curr->value, needle))
        {
            printf("Rezultatas: %s %s %s %s\n", curr->value.firstname, curr->value.lastname, curr->value.phone, curr->value.email);
            count++;
        }
        curr = curr->next;
    }
    printf("Rastą %i rezultatų.\n\n", count);
}

struct Contact input_contact()
{
    size_t buff_len = MAX_FIRSTNAME_LEN;
    printf("Iveskite varda: ");
    char *firstname = NULL;
    int firsname_len = getline(&firstname, &buff_len, stdin);
    printf("Iveskite pavarde: ");
    buff_len = MAX_LASTNAME_LEN;
    char *lastname = NULL;
    int lastname_len = getline(&lastname, &buff_len, stdin);
    printf("Iveskite telefona: ");
    buff_len = MAX_PHONE_LEN;
    char *phone = NULL;
    int phone_len = getline(&phone, &buff_len, stdin);
    printf("Iveskite el pasta: ");
    buff_len = MAX_EMAIL_LEN;
    char *email = NULL;
    int email_len = getline(&email, &buff_len, stdin);

    firsname_len--;
    lastname_len--;
    phone_len--;
    email_len--;
    firstname[firsname_len] = 0;
    lastname[lastname_len] = 0;
    phone[phone_len] = 0;
    email[email_len] = 0;
    struct Contact contact = make_contact(firstname, lastname, phone, email);
    free(firstname);
    free(lastname);
    free(phone);
    free(email);

    return contact;
}

void print_menu()
{
    printf("\n\
    [p] Spausdinti sarašą\n\
    [a] Pridėti gale\n\
    [i] Įterpti\n\
    [r] Ištrnti elementą\n\
    [c] Ištrinti viską\n\
    [g] Rasti pagal eilės numerį\n\
    [s] Surasti pagal vardą, pavardę, el. paštą arba telefono numerį\n\
    \n\
    [q] Išeiti\n\n");
}

void handle_input(char selection, struct ContactList *list)
{
    switch (selection)
    {
    case 'p':
        ContactList_print_all(list);
        break;
    case 'q':
        exit(0);
        break;
    case 'a':
        ContactList_append(list, input_contact());
        break;
    case 'i':
    {
        struct Contact contact = input_contact();
        size_t buffSize = 16;
        char *number = NULL;
        printf("Įvekite pozicija, kur įterpti: ");
        getline(&number, &buffSize, stdin);
        int num = atoi(number);
        free(number);
        ContactList_insert(list, contact, num);
        break;
    }
    case 'r':
    {
        size_t buffSize = 16;
        char *number = NULL;
        printf("Įvekite pozicija, kurią ištrinti: ");
        getline(&number, &buffSize, stdin);
        int num = atoi(number);
        free(number);
        ContactList_remove(list, num);
        break;
    }
    case 'c':
        ContactList_clear(list);
        break;
    case 'g':
    {
        size_t buffSize = 16;
        char *number = NULL;
        printf("Įvekite pozicija, kurios įrašas domina: ");
        getline(&number, &buffSize, stdin);
        int num = atoi(number);
        free(number);
        struct Contact *contact = ContactList_get(list, num);
        if (contact == NULL)
        {
            printf("Netinkamas indeksas.");
            return;
        }
        printf("Vardas: %s\nPavardė: %s\nTelefono numeris: %s\nEl. paštas: %s\n", contact->firstname, contact->lastname, contact->phone, contact->email);
        break;
    }
    case 's':
    {
        size_t buffSize = 16;
        char *needle = NULL;
        printf("Įvekite pozicija, kurios įrašas domina: ");
        int needle_len = getline(&needle, &buffSize, stdin);
        needle_len--;
        needle[needle_len] = 0;
        print_matching(list, needle);
        free(needle);
        break;
    }
    case '\n':
        print_menu();
        break;
    default:
        break;
    }
}

int main()
{
    struct ContactList list;
    init_list(&list);
    print_menu();
    while (1)
    {
        char *selectionLine = NULL;
        size_t bufferSize = 16;
        size_t selectionLength = getline(&selectionLine, &bufferSize, stdin);
        for (size_t i = 0; i < selectionLength; i++)
        {
            handle_input(selectionLine[i], &list);
        }
    }
    return 0;
}