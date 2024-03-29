![philos](https://user-images.githubusercontent.com/73430903/175942780-45cb88c3-840a-42dd-95b0-a54515ffc317.png)


I never thought philosophy would be so deadly (the basics of threading a process.
How to create threads and use mutexes.)

Overview

Here are the things you need to know if you want to succeed this assignment:

• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying!

Correctness properties it needs to satisfy are :

    Mutual Exclusion Principle –
    No two Philosophers can have the two forks simultaneously.
    Free from Deadlock –
    Each philosopher can get the chance to eat in a certain finite time.
    Free from Starvation –When few Philosophers are waiting then one gets a chance to eat in a while.
    No strict Alternation.
    Proper utilization of time.

validated with 100 points without bonuses
