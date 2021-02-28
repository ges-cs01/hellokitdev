#include "functions.h"

static void hellokit_exit(void) {
    printk(KERN_INFO "HELLOKIT_DEBUG: CIAO! \n");
}

module_exit(hellokit_exit);
