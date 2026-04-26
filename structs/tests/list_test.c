#include "list.h"
#include <stdio.h>

int
main(void) {
    List l = list_init();
    
    char cmd;
    int val;
    while (scanf("%c", &cmd) == 1) {
        switch (cmd) {
            case 'b':    
                scanf("%d", &val);
                list_push_back(&l, val);
                break;
            case 'e':
                scanf("%d", &val);
                Node *to_erase = list_find(&l, val);
                list_erase(&l, to_erase);
                break;
            default:
                printf("No such command\n");
                exit(1);
        }
    }
    
    list_destroy(&l);
    return 0;
}
