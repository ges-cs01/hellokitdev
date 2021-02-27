#include <linux/module.h>
#include <linux/kernel.h> // debug messages.
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

static void hellokit_exit(void) {
    printk(KERN_INFO "HELLOKIT_DEBUG: CIAO! \n");
}

module_exit(hellokit_exit);
