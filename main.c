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

int device_open(struct inode *inode, struct file *file) {
    static int counter = 0;
    if(Device_open) {
        return -EBUSY;
    }
    
    sprintf(msg, "Good morning %d times", counter++);
    msg_ptr = msg;
    try_module_get(THIS_MODULE);
    return 0;
}

int device_release(struct inode *inode, struct file *file) {
    Device_open--;

    module_put(THIS_MODULE);
    return 0;
}

ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    
    if(*msg_ptr == 0) {
        return 0;
    }

    while(length && *msg_ptr) {
        put_user(*(msg_ptr), buffer++);
        length--;
        bytes_read++;
    }

    return bytes_read;
}

ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset) {
    printk(KERN_ALERT "hey hey kernel alert\n");
    return 0;
}
