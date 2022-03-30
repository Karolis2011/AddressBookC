#include <stdlib.h>
#include <stdio.h>
#include <contactlist.h>

struct ContactListNode *i_ContactList_alloc_node(struct Contact value)
{
    struct ContactListNode *newNode = (struct ContactListNode *)malloc(sizeof(struct ContactListNode));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct ContactListNode *i_ContactList_recall_node(struct ContactList *list, int pos)
{
    if (pos == 0)
    {
        return list->head;
    }
    struct ContactListNode *node = list->head;
    int i = 0;
    while (node != NULL && i < pos)
    {
        i++;
        node = node->next;
    }
    return node;
}

void ContactList_append(struct ContactList *list, struct Contact value)
{
    struct ContactListNode *newNode = i_ContactList_alloc_node(value);
    if (list->head == NULL || list->tail == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        struct ContactListNode *oldTail = list->tail;
        list->tail = newNode;
        newNode->prev = oldTail;
        oldTail->next = newNode;
    }
}

void ContactList_insert(struct ContactList *list, struct Contact value, int pos)
{
    if (list->head == NULL)
    {
        ContactList_append(list, value);
        return;
    }
    struct ContactListNode *newNode = i_ContactList_alloc_node(value);
    struct ContactListNode *nodeAfter = i_ContactList_recall_node(list, pos);
    newNode->prev = nodeAfter->prev;
    nodeAfter->prev = newNode;
    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
    }
    newNode->next = nodeAfter;
    if (nodeAfter == list->head)
    {
        list->head = newNode;
    }
}

void ContactList_remove(struct ContactList *list, int pos)
{
    if (list->head == NULL)
    {
        return;
    }
    struct ContactListNode *node = i_ContactList_recall_node(list, pos);
    if (node == NULL)
    {
        printf("Netinkamas indeksas.");
        return;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    if (list->head == node)
    {
        list->head = node->next;
    }
    if (list->tail == node)
    {
        list->tail = node->prev;
    }
    free(node);
}

void ContactList_print_all(struct ContactList *list)
{
    struct ContactListNode *curr = list->head;
    int pos = 0;
    while (curr != NULL)
    {
        printf("%i: %s %s %s %s\n", pos, curr->value.firstname, curr->value.lastname, curr->value.phone, curr->value.email);
        curr = curr->next;
        pos++;
    }
}

void ContactList_clear(struct ContactList *list)
{
    struct ContactListNode *curr = list->head;
    while (curr != NULL)
    {
        struct ContactListNode *next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

struct Contact *ContactList_get(struct ContactList *list, int pos)
{
    struct ContactListNode *node = i_ContactList_recall_node(list, pos);
    if (node == NULL)
    {
        return NULL;
    }
    return &node->value;
}