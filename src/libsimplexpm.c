#include "../include/libsimplexpm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sp_internal_error(char *error, int status) {
  printf("[INTERN] %s, please report to author", error);
  exit(status);
  return;
}

struct sp_task_entry *sp_te_make() {
  struct sp_task_entry *entry = calloc(1, sizeof(struct sp_task_entry));
  entry->name = NULL;
  entry->description = NULL;
  entry->children =
      calloc(SP_ARRAY_DEFAULT_SIZE, sizeof(struct sp_task_entry *));
  entry->children_size = SP_ARRAY_DEFAULT_SIZE;
  entry->children_used = 0;
  entry->assignees_size = SP_ARRAY_DEFAULT_SIZE;
  entry->assignees_used = 0;
  entry->assignees = calloc(SP_ARRAY_DEFAULT_SIZE, sizeof(struct sp_user *));
  entry->parent = NULL;
  entry->type = UNKNOWN_TYPE;
  entry->priority = UNKNOWN_PRIORITY;
  return entry;
}

int sp_te_change_name(struct sp_task_entry *entry, char *name) {
  if (entry == NULL) {
    sp_internal_error("couldn't change name", 1);
  }
  int len = strlen(name);
  entry->name = realloc(entry->name, (len + 1) * sizeof(char));
  strcpy(entry->name, name);
  (entry->name)[len] = '\0';
  return 0;
}
int sp_te_change_description(struct sp_task_entry *entry, char *description) {
  if (entry == NULL) {
    sp_internal_error("couldn't change description", 1);
  }
  int len = strlen(description);
  entry->description = realloc(entry->description, (len + 1) * sizeof(char));
  strcpy(entry->description, description);
  (entry->description)[len] = '\0';
  return 0;
}
int sp_te_change_priority(struct sp_task_entry *entry,
                          enum sp_task_priority priority) {
  if (priority < URGENT_PRIORITY || priority > UNKNOWN_PRIORITY) {
    sp_internal_error("couldn't change priority", 1);
  }
  entry->priority = priority;
  return 0;
}
int sp_te_change_task_type(struct sp_task_entry *entry,
                           enum sp_task_type type) {
  if (type < PROJECT_TYPE || type > UNKNOWN_TYPE) {
    sp_internal_error("couldn't change type", 1);
    return;
  }
  entry->type = type;
  return 0;
}
int sp_te_add_child(struct sp_task_entry *entry, struct sp_task_entry *child) {}
int sp_te_remove_child(struct sp_task_entry *entry,
                       struct sp_task_entry *child) {
}
int sp_te_change_parent(struct sp_task_entry *entry,
                        struct sp_task_entry *parent) {
  if (entry == NULL) {
    sp_internal_error("couldn't change parent", 1);
  }
  entry->parent = parent;
  return 0;
}
int sp_te_clean_tree(struct sp_task_entry *entry);
