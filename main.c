#include "functions.h"
static char* my_string = "";

module_param(my_string, charp, 0000);
MODULE_PARM_DESC(my_string, "A character string");


static int hellokit_init(void) {
    printk(KERN_INFO "HELLOKIT_DEBUG: %s \n", my_string);
    return 0; 
}

module_init(hellokit_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("print3mps");
MODULE_SUPPORTED_DEVICE("testdevice");
