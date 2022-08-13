#ifndef LIBSIMPLEXPM_H
#define LIBSIMPLEXPM_H
#include <time.h>
#define SP_ARRAY_DEFAULT_SIZE 10
enum sp_task_type {
    PROJECT_TYPE,
    EPIC_TYPE,
    FEATURE_TYPE,
    TASK_TYPE,
    ISSUE_TYPE,
    UNKNOWN_TYPE,
};

enum sp_task_priority {
    URGENT_PRIORITY,
    HIGH_PRIORITY,
    MEDIUM_PRIORITY,
    LOW_PRIORITY,
    UNKNOWN_PRIORITY
};

struct sp_task_entry {
    char *name;
    char *description;
    int priority;
    enum sp_task_type type;
    struct sp_user **assignees;
    size_t assignees_used;
    size_t assignees_size;
    struct sp_task_entry **children;
    size_t children_used;
    size_t children_size;
    struct sp_task_entry *parent;
    time_t creation;
    time_t due;
};

struct sp_user {
    char *name;
};

struct sp_task_entry *sp_te_make();

int sp_te_change_name(struct sp_task_entry *entry, char *name);
int sp_te_change_description(struct sp_task_entry *entry, char *description);
int sp_te_change_priority(struct sp_task_entry *entry, enum sp_task_priority priority);
int sp_te_change_task_type(struct sp_task_entry *entry, enum sp_task_type type);
int sp_te_add_child(struct sp_task_entry *entry, struct sp_task_entry *child);
int sp_te_remove_child(struct sp_task_entry *entry, struct sp_task_entry *child);
int sp_te_change_parent(struct sp_task_entry *entry, struct sp_task_entry *parent);
int sp_te_clean_tree(struct sp_task_entry *entry);

void sp_internal_error(char *error, int status);

#endif