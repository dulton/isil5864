#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/mutex.h>
#include <linux/seq_file.h>

#include <isil5864/isil_common.h>

#define MODULE_ENTRY "isil"

static struct proc_dir_entry *s_dir_entry = NULL, *message_entry;

#ifdef MESSAGE_LOG
struct message_privte *message_log = NULL;
int message_level = ISIL_DBG_CUR_LEVEL;

static void show_proc_entry_info(void *context)
{
    struct proc_dir_entry *entry = (struct proc_dir_entry *)context;

    if(entry && (entry->subdir == NULL)) {
        printk ("%s,", entry->name);
    }
}

static void touch_each_proc_entry(struct proc_dir_entry *root, void (*fn)(void *))
{
    if(root) {
        if(fn) {
            fn(root);
        }
        touch_each_proc_entry(root->subdir, fn);
        touch_each_proc_entry(root->next, fn);
    }
}

static int msg_open(struct inode * inode, struct file * file)
{
    file->private_data = message_log;

    return 0;
}

static int msg_release(struct inode * inode, struct file * file)
{
    return 0;
}

static ssize_t msg_write(struct file *file, const char __user *buf,
        size_t count, loff_t *ppos)
{
    char level;
    char temp[64];

    if(copy_from_user(&level, buf, 1)){
        printk("%s, %d: copy_from_user failed\n", __FUNCTION__, __LINE__);
    }
    if(count < 64) {
        if(copy_from_user(temp, buf, count)){
            printk("%s, %d: copy_from_user failed\n", __FUNCTION__, __LINE__);
        }
        temp[63] = '\0';
        printk("%s\n", temp);
    }

    if((level >= '0') && (level <= '9')) {
        level -= '0';
    }else{
        printk("unknown log level %x\n", level);
        return -EINVAL;
    }

    message_level = level;

    return count;
}
static ssize_t msg_read(struct file *file, char __user *buf,
        size_t count, loff_t *ppos)
{
    u32 i = 0;
    char c;
    int error = 0;
    struct message_privte *p;

    p = (struct message_privte *)file->private_data;

    if ((file->f_flags & O_NONBLOCK) && !(p->end - p->start))
        return -EAGAIN;

    error = wait_event_interruptible(p->wait, (p->start - p->end));
    if(error) {
        goto msg_out;
    }
    i = 0;
    spin_lock_irq(&p->lock);
    while (!error && (p->start != p->end) && i < count) {
        if((p->end < p->start) && (p->start == (MESSAGE_LEN - (MESSAGE_LEN>>8)))) {
            p->start = 0;
        }
        c = p->buf[p->start&(MESSAGE_LEN - 1)];
        p->start++;
        spin_unlock_irq(&p->lock);
        error = __put_user(c,buf);
        buf++;
        i++;
        cond_resched();
        spin_lock_irq(&p->lock);
    }
    spin_unlock_irq(&p->lock);
    if (!error)
        error = i;
msg_out:
    return error;
}

static unsigned int msg_poll(struct file *file, poll_table *wait)
{
    struct message_privte *p;

    p = (struct message_privte *)file->private_data;

    poll_wait(file, &p->wait, wait);
    if (p->end != p->start)
        return POLLIN | POLLRDNORM;

    return 0;
}


static const struct file_operations proc_messages_operations = {
    .read		= msg_read,
    .poll		= msg_poll,
    .open		= msg_open,
    .write      = msg_write,
    .release	= msg_release,
};
#else
static void touch_each_proc_entry(struct proc_dir_entry *root, void (*fn)(void *)){
}
static void show_proc_entry_info(void *context){
}
#endif

void *isil_seq_get_private(struct seq_file *seq)
{
    if(seq) {
        return seq->private;
    }

    return NULL;
}

void *isil_file_get_seq_private(struct file *file)
{
    if(file) {
        struct seq_file *seq = (struct seq_file *)file->private_data;
        if(seq) {
            return seq->private;
        }
    }

    return NULL;
}

static int isil_seq_open_fs(struct inode *inode, struct file *file)
{
    struct proc_dir_entry *pde;

    pde = PDE(inode);

    return single_open(file, (void *)pde->read_proc, pde->data);
}





static size_t regs_dump(isil_chip_t *chip, char *buf, size_t size)
{
	size_t count = 0;

	u32 reg_addr;
	u32 value;

	for (reg_addr = 0x0000; (count < size) && (reg_addr <= 0x2FFC); reg_addr += 4) {
		value = chip->io_op->chip_read32(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"[0x%05x] = 0x%08x\n", reg_addr, value);
	}

	for (reg_addr = 0x4000; (count < size) && (reg_addr <= 0x4FFC); reg_addr += 4) {
		value = chip->io_op->chip_read32(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"[0x%05x] = 0x%08x\n", reg_addr, value);
	}

	for (reg_addr = 0x8000; (count < size) && (reg_addr <= 0x180DC); reg_addr += 4) {
		value = chip->io_op->chip_read32(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"[0x%05x] = 0x%08x\n", reg_addr, value);
	}

	for (reg_addr = 0x18100; (count < size) && (reg_addr <= 0x1817C); reg_addr += 4) {
		value = chip->io_op->chip_read32(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"[0x%05x] = 0x%08x\n", reg_addr, value);
	}

	for (reg_addr = 0x80000; (count < size) && (reg_addr <= 0x87FFF); reg_addr += 4) {
		value = chip->io_op->chip_read32(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"[0x%05x] = 0x%08x\n", reg_addr, value);
	}

	for (reg_addr = 0x0; (count < size) && (reg_addr <= 0xEFE); reg_addr += 1) {
		value = mpb_read(chip, reg_addr);
		count += scnprintf(buf + count, size - count,
				"indir[0x%03x] = 0x%02x\n", reg_addr, value);
	}

	return count;
}


#define DEBUGFS_BUF_SIZE	1024 * 1024

struct debugfs_buffer {
	size_t count;
	char data[DEBUGFS_BUF_SIZE];
};

static int debugfs_regs_dump_open(struct inode *inode, struct file *file)
{
    struct proc_dir_entry *pde;

    pde = PDE(inode);

    //return single_open(file, (void *)pde->read_proc, pde->data);

	isil_chip_t *chip = pde->data; //inode->i_private;
	struct debugfs_buffer *buf;

	buf = kmalloc(sizeof(*buf), GFP_KERNEL);
	if (buf == NULL)
		return -ENOMEM;

	buf->count = regs_dump(chip, buf->data, sizeof(buf->data));

	file->private_data = buf;
	return 0;
}

static ssize_t debugfs_regs_dump_read(struct file *file, char __user *user_buf,
				      size_t nbytes, loff_t *ppos)
{
	struct debugfs_buffer *buf = file->private_data;

	return simple_read_from_buffer(user_buf, nbytes, ppos, buf->data,
				       buf->count);
}

static int debugfs_regs_dump_release(struct inode *inode, struct file *file)
{
	kfree(file->private_data);
	file->private_data = NULL;

	return 0;
}

static const struct file_operations regs_dump_fops = {
	.owner = THIS_MODULE,
	.open = debugfs_regs_dump_open,
	.llseek = no_llseek,
	.read = debugfs_regs_dump_read,
	.release = debugfs_regs_dump_release,
};





int isil_module_register(isil_chip_t *chip, isil_proc_register_s *reg)
{
	static struct proc_dir_entry *regs_dump_entry;
    if(!chip || !reg)
    {
        return -EINVAL;
    }

    if(!chip->proc_entry){
        ISIL_DBG(ISIL_DBG_INFO, "create proc entry /proc/%s/%s\n", MODULE_ENTRY, chip->name);
        chip->proc_entry = proc_mkdir(chip->name, s_dir_entry);      


				regs_dump_entry = create_proc_entry("regs_dump", 0444, chip->proc_entry);
				regs_dump_entry->proc_fops = &regs_dump_fops;
				regs_dump_entry->data = chip;


    }
    if(reg->entry || (atomic_read(&reg->ref_count) > 0)){
        atomic_inc(&reg->ref_count);
        return ISIL_OK;
    }else{
        atomic_set(&reg->ref_count, 1);
    }

    if(reg) {
        struct file_operations *ops;

        ops = (struct file_operations *)kmalloc(sizeof(struct file_operations), GFP_KERNEL);
        ops->owner = THIS_MODULE;
        ops->open = isil_seq_open_fs;
        ops->read = seq_read;
        ops->write = reg->write;
        ops->llseek = seq_lseek;
        ops->release = single_release;
        reg->entry = create_proc_entry(reg->name, S_IRUGO, chip->proc_entry);
        if(reg->entry){
            reg->entry->read_proc = (void *)reg->read;
            reg->entry->proc_fops = ops;
            reg->entry->data = reg->private;
        }
    }
    if(!reg->entry){
        ISIL_DBG(ISIL_DBG_ERR, "create /proc/%s/%s/%s failed\n", MODULE_ENTRY, chip->name, reg->name);
        return -EPERM;
    }
    ISIL_DBG(ISIL_DBG_INFO, "create proc entry /proc/%s/%s/%s\n", MODULE_ENTRY, chip->name, reg->name);

    return ISIL_OK;
}

EXPORT_SYMBOL_GPL(isil_module_register);

int isil_module_unregister(isil_chip_t *chip, isil_proc_register_s *reg)
{
    struct file_operations *ops;

    if(!chip || !reg)
    {
        return -EINVAL;
    }

    if(!reg->entry || (atomic_read(&reg->ref_count) <= 0))
    {
        return -EPERM;
    }else{
        atomic_dec(&reg->ref_count);
    }
    if(atomic_read(&reg->ref_count) > 0) {
        return ISIL_OK;
    }

    ops = (void *)reg->entry->proc_fops;
    remove_proc_entry(reg->name, chip->proc_entry);
    ISIL_DBG(ISIL_DBG_INFO, "remove proc entry /proc/%s/%s/%s\n", MODULE_ENTRY, chip->name, reg->name);
    reg->entry = NULL;
    if(ops) {
        kfree(ops);
    }
    if(!chip->proc_entry->subdir){
        ISIL_DBG(ISIL_DBG_INFO, "remove proc entry /proc/%s/%s\n", MODULE_ENTRY, chip->name);
        remove_proc_entry(chip->name, s_dir_entry);
    }

    return ISIL_OK;
}
EXPORT_SYMBOL_GPL(isil_module_unregister);


int proc_module_init(void)
{
#ifdef MESSAGE_LOG
    struct message_privte *p;
#endif

    s_dir_entry = proc_mkdir(MODULE_ENTRY, NULL);
    if(!s_dir_entry)
    {
        return -EINVAL;
    }

    //s_dir_entry->owner = THIS_MODULE;
#ifdef MESSAGE_LOG
    p  = (struct message_privte *)kmalloc(sizeof(struct message_privte), GFP_KERNEL);
    if(p) {
        p->buf      = (char *)kmalloc(MESSAGE_LEN, GFP_KERNEL);
        if(p->buf) {
            p->buf_len  = MESSAGE_LEN;
            p->start    = 0;
            p->end      = 0;
            spin_lock_init(&p->lock);
            init_waitqueue_head(&p->wait);
            message_entry    = create_proc_entry("messages", 0644, s_dir_entry);
            message_entry->proc_fops = &proc_messages_operations;
            message_entry->data = p;
            message_log = p;
        }else{
            message_log = NULL;
        }
    }else{
        message_log = NULL;
    }
#endif

    return 0;
}

void proc_module_release(void)
{

#ifdef MESSAGE_LOG
    struct message_privte *p;
#endif

    if(s_dir_entry) {
        if(s_dir_entry->subdir) {
            printk("unrelease mode:");
            touch_each_proc_entry(s_dir_entry->subdir, show_proc_entry_info);
            printk("\n");
        }
#ifdef MESSAGE_LOG
        if(message_entry) {
            p = message_entry->data;
            if(p) {
                if(p->buf) {
                    free_pages((unsigned long)p->buf, get_order(MESSAGE_LEN));
                    remove_proc_entry("messages", s_dir_entry);
                    message_log = NULL;
                }
                kfree(p);
            }
            message_entry = NULL;
        }
#endif
        s_dir_entry = NULL;
        remove_proc_entry(MODULE_ENTRY, NULL);
    }

    return ;
}

struct file *isil_kernel_file_open(char *name)
{
    struct file *fp_file;

    fp_file = filp_open(name, O_CREAT | O_RDWR | O_SYNC, 0655);
    if(IS_ERR(fp_file))
    {
        printk("open file \"%s\" faild, %d\n", name, (int )fp_file);
        return NULL;
    }

    return fp_file;
}

void isil_kernel_file_close(struct file *fp_file)
{
    if(fp_file)
    {
        filp_close(fp_file, NULL);
    }
}

unsigned int atoi(char *str)
{
    char *p; 
    unsigned int val = 0, unknown = 0;

    if(!str){
        return 0;
    }
    /*dec*/
    p = str;
    while(*p){
        val *= 10;
        switch(*p){
            case '0' ... '9':
                val += *p - '0';
                break;
            default:
                unknown = 1;
                break;
        }
        p++;
    }
    if(unknown){
        /*hex*/
        p = str;
        val = 0;
        while(*p){
            val <<= 4;
            switch(*p){
                case '0' ... '9':
                    val |= *p - '0';
                    break;
                case 'A' ... 'F':
                    val |= *p - 'A';
                    break;
                case 'a' ... 'f':
                    val |= *p - 'a' + 0xa;
                    break;
                default:;
            }
            p++;
        }   
    }

    return val;
}


