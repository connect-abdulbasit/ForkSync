#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/init.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

struct semaphore mutex;
struct semaphore S[N];
struct task_struct *thread_id[N];

void test(int phnum);
void take_fork(int phnum);
void put_fork(int phnum);
int philosopher(void *num);

void test(int phnum)
{
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[phnum] = EATING;
        printk(KERN_INFO "Philosopher %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
        printk(KERN_INFO "Philosopher %d is Eating\n", phnum + 1);
        up(&S[phnum]);
    }
}

void take_fork(int phnum)
{
    down(&mutex);
    state[phnum] = HUNGRY;
    printk(KERN_INFO "Philosopher %d is Hungry\n", phnum + 1);
    test(phnum);
    up(&mutex);
    down(&S[phnum]);
}

void put_fork(int phnum)
{
    down(&mutex);
    state[phnum] = THINKING;
    printk(KERN_INFO "Philosopher %d putting fork %d and %d down\n", phnum + 1, LEFT + 1, phnum + 1);
    printk(KERN_INFO "Philosopher %d is thinking\n", phnum + 1);
    test(LEFT);
    test(RIGHT);
    up(&mutex);
}

int philosopher(void *num)
{
    int *i = (int *)num;
    while (!kthread_should_stop())
    {
        msleep(1000);
        take_fork(*i);
        msleep(1000);
        put_fork(*i);
    }
    return 0;
}

static int __init dpp_init(void)
{
    int i;
    sema_init(&mutex, 1);
    for (i = 0; i < N; i++)
    {
        sema_init(&S[i], 0);
    }

    for (i = 0; i < N; i++)
    {
        thread_id[i] = kthread_run(philosopher, &phil[i], "Philosopher_%d", i);
        printk(KERN_INFO "Philosopher %d is thinking\n", i + 1);
    }

    return 0;
}

static void __exit dpp_exit(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (thread_id[i])
            kthread_stop(thread_id[i]);
    }
    printk(KERN_INFO "Dining Philosophers Module Removed\n");
}

module_init(dpp_init);
module_exit(dpp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdul Basit");
MODULE_DESCRIPTION("Dining Philosophers Kernel Module");