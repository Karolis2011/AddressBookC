#pragma once

#include <contact.h>

struct ContactListNode
{
    struct Contact value;
    struct ContactListNode *next;
    struct ContactListNode *prev;
};

struct ContactList
{
    struct ContactListNode *head;
    struct ContactListNode *tail;
};

void ContactList_append(struct ContactList *list, struct Contact value);
void ContactList_insert(struct ContactList *list, struct Contact value, int pos);
void ContactList_remove(struct ContactList *list, int pos);
void ContactList_print_all(struct ContactList *list);
void ContactList_clear(struct ContactList *list);
struct Contact *ContactList_get(struct ContactList *list, int pos);