#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1024

char* my_strdup(const char* s) {
    char *p = malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

typedef struct node {
    char* line;
    struct node* next;
} Node;

typedef struct list_t {
    Node* head;
    int size;
} List;


void list_init(List* list_p){
    list_p->head = NULL;
    list_p->size = 0;
}

int list_ins_first(List* list_p, char* line){
    Node* node = malloc(sizeof(Node));
    if (node == NULL){
        fprintf(stderr, "Problem with memory allocation.");
        return 1;
    }
    node->line = line;
    node->next = list_p->head;
    list_p->size++;
    list_p->head = node;
    return 0;
}

void list_print(List* list_p){
    Node* current = list_p->head;
    printf("Reversed input:\n\n");
    while(current){
        printf("%s", current->line);
        current = current->next;
    }
}

int list_size(List* list_p){
    return list_p->size;
}

int main(int argc, char* argv[]){

    List lines;
    char line[MAX_LINE_LEN];
    int line_ct = 0;
    int limit = -1;
    FILE* input = stdin;
    list_init(&lines);

    // parse arguments
    for(int i = 1; i < argc; i++){
        if(strncmp(argv[i], "-l", 2) == 0){
            limit = atoi(argv[i+1]); // set limit for affected lines
            i++;
        }
        else {
            input = fopen(argv[i], "r"); // if file is given, read from it
            if(input == NULL){
                fprintf(stderr, "Error opening file %s", argv[i]);
                return 1;
            }
        }
    }

    while (line_ct != limit && fgets(line, sizeof(line), input)) {
        int check = list_ins_first(&lines, my_strdup(line));
        if(check == 1){
            return 1;
        }
        line_ct++;
    }

    list_print(&lines);

    return 0;
}