# Planner
Task from "Algorithms and data structures" subject.

OPEN BY RAW OPTION

The content of the task:
One of the tasks of the operating system is to allocate processor time to each process. Write a simple planner program.
CPU time should be allocated according to the following rules:

- Each process can have a high, normal or low priority,
- Lower priority processes will not receive the processor if there are processes with higher priority,
- Processes of the same priority are executed alternately, in order of their creation,
- Processes can be created, deleted and prioritized,
- If there is no process in the system, a special process called 'idle' is performed.

Each process is uniquely identified by its number (positive integer, not greater than (2^31)-1)

If there are 3 normal priority processes (1, 2, 3), they will be executed 
in order of 1, 2, 3, 1, 2, 3, .... 
If we add process 4 with high priority at this point, then the following processes will be: 4, 4, 4, ....

The solution using dynamic data structures (list, cyclical list) will be definitely higher (max 100%) than the task using arrays (max 30%).


Input and Output

At the entrance will be a string of commands:
n - Allocating processor time to the next process; 
    the output should contain the number of tasks, which is to receive processor or idle if there are no tasks in the system,
c id p - Creating a process with id number and priority p, 1 is a high priority, 0 is a normal priority, and -1 is a low priority; 
         The newly created task should be at the end of the priority queue if 0: 2 3 1 executes c 4 0 and the result should be 0: 2 3 1 4,
t id - Means completing task with id number,
p id p - Change task priority with this id number to p (equally delete task id and add it to new priority),
l - (Small letter L) list of tasks; List all tasks in the format:
    1:
    0:
    -1:
    
For example, if there are 1, 2, 3, 4, 5 tasks in the system, 1, 2, 3 have normal priority 
and 4 and 5 is high, 4 will be earlier than 5, 
and tasks 1, 2, 3 will be executed in Of such order (eg after removal of tasks 4 and 5), the output should appear:

1: 4 5
0: 1 2 3
-1:



Examples:

Input:
c 1 0
c 2 0
c 3 0
n
n
n
n
c 4 1
n
n
n
t 4
n
n
n
c 5 -1
t 1
t 2
n
n
t 3
n
n
c 6 -1
n
n
n
Output:
1
2
3
1
4
4
4
2
3
1
3
3
5
5
5
6
5

Input:
c 1 0
c 2 0
c 3 0
c 4 1
c 5 1
c 6 -1
c 7 -1
c 8 -1
l

Output:
1: 4 5
0: 1 2 3
-1: 6 7 8

Input:
c 1 0
c 2 0
c 3 0
c 4 -1
n
n
n
n
p 4 1
n
n
p 1 1
n
n
n
t 1
t 2
t 3
t 4
n
n

Output:
1
2
3
1
4
4
4
1
4
idle
idle
