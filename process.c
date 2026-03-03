#include <stdio.h>
#include "kernel.h"
#include "process.h"

PCB process_table[MAX_PROCESSES];
int process_count = 0;
int current_process = -1;

void create_process() {
    if (process_count >= MAX_PROCESSES) {
        printf("Process limit reached\n");
        return;
    }

    process_table[process_count].pid = process_count + 1;
    process_table[process_count].state = READY;
    process_table[process_count].pc = 0;

    printf("Process %d created\n", process_table[process_count].pid);
    process_count++;
}

void scheduler() {
    if (process_count == 0) {
        printf("No processes to schedule\n");
        return;
    }

    current_process = (current_process + 1) % process_count;

    if (process_table[current_process].state != TERMINATED) {
        process_table[current_process].state = RUNNING;
        printf("Running process %d\n", process_table[current_process].pid);
        process_table[current_process].pc++;

        process_table[current_process].state = READY;
    }
}

void terminate_process(int pid) {
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].pid == pid) {
            process_table[i].state = TERMINATED;
            printf("Process %d terminated\n", pid);
        }
    }
}

void list_processes() {
    for (int i = 0; i < process_count; i++) {
        printf("PID: %d | State: %d | PC: %d\n",
               process_table[i].pid,
               process_table[i].state,
               process_table[i].pc);
    }
}