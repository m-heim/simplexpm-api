typedef enum task_type {
    epic,
    feature,
    task,
    issue
} task_type;

typedef enum task_priority {
    urgent,
    high,
    medium,
    low
} task_priority;

typedef struct task_entry task_entry;
typedef struct task_entry {
    char *name;
    char *description;
    int priority;
    task_type type;
    task_entry **children;
    task_entry *parent;
} task_entry;

task_entry *te_make();

int te_change_name(task_entry *entry, char *name);
int te_change_description(task_entry *entry, char *description);
int te_change_priority(task_entry *entry, task_priority priority);
int te_change_task_type(task_entry *entry, task_type type);
int te_add_child(task_entry *entry, task_entry *child);
int te_remove_child(task_entry *entry, task_entry *child);
int te_change_parent(task_entry *entry, task_entry *parent);
int te_clean_tree(task_entry *entry);