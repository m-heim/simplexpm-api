#include "../include/libsimplexpm.h"
#include <stdlib.h>
#include <string.h>

task_entry *te_make() {
    task_entry *entry = calloc(1, sizeof(task_entry));
    entry->name = NULL;
    entry->description = NULL;
    entry->children = NULL;
    entry->parent = NULL;
    entry->type = epic;
    entry->priority = low;
    return entry;
}

int te_change_name(task_entry *entry, char *name) {
    if (entry == NULL || name == NULL) {
        return 1;
    }
    int len = strlen(name);
    entry->name = realloc(entry->name, (len + 1) * sizeof(char));
    strcpy(entry->name, name);
    (entry->name)[len] = '\0';
    return 0;
}
int te_change_description(task_entry *entry, char *description) {
    if (entry == NULL || description == NULL) {
        return 1;
    }
    int len = strlen(description);
    entry->description = realloc(entry->description, (len + 1) * sizeof(char));
    strcpy(entry->description, description);
    (entry->description)[len] = '\0';
    return 0;
}
int te_change_priority(task_entry *entry, task_priority priority) {
    entry->priority = priority;
    return 0;
}
int te_change_task_type(task_entry *entry, task_type type);
int te_add_child(task_entry *entry, task_entry *child);
int te_remove_child(task_entry *entry, task_entry *child);
int te_change_parent(task_entry *entry, task_entry *parent);
int te_clean_tree(task_entry *entry);