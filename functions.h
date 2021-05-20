#include <linux/module.h>
#include <linux/kernel.h> // debug messages.
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

int init_module(void);
int device_open(struct inode *inode, struct file *file);
int device_release(struct inode *inode, struct file *file);
ssize_t device_read(struct file *file, char *buffer, size_t length, loff_t *offset);
ssize_t device_write(struct file *file, const char *buffer, size_t length, loff_t *offset);

#define SUCCESS 0
#define DEVICE_NAME "kitty"
#define BUFF_LEN 80

extern int Major;
