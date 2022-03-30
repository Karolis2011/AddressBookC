#pragma once

#include <contact.h>
#include <contactlist.h>

struct Contact make_contact(const char *firstname, const char *lastname, const char *phone, const char *email);
void init_list(struct ContactList *list);
