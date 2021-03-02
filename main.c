#include "functions.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("print3mps");
MODULE_SUPPORTED_DEVICE("testdevice");

int Major;
static int Device_open = 0;
static char msg[BUFF_LEN];
static char *msg_ptr;

static struct file_operations fops = {
    .read    = device_read,
    .write   = device_write,
    .open    = device_open,
    .release = device_release
};

int init_module(void) {
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "failed to load.\n");
        return Major;
    }

    printk(KERN_ALERT "major number assigned, %d.", Major);
    printk(KERN_ALERT "please create device with name \n mknod /dev/%s c %d 0.", DEVICE_NAME, Major);
    return 0;
}
