#ifndef PROCESS_H
#define PROCESS_H

typedef enum {
    READY,
    RUNNING,
    TERMINATED
} ProcessState;

typedef struct {
    int pid;
    ProcessState state;
    int pc;   // program counter simulation
} PCB;

void create_process();
void scheduler();
void terminate_process(int pid);
void list_processes();

#endif