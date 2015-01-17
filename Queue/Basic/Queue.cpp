//程序中加入了一些windows下控制颜色的代码，已注释掉。

#include <iostream>
#pragma once

#include <windows.h>
#include <cstdio>
#include <cstdlib>

/*#define fg_blue FOREGROUND_BLUE
#define fg_red FOREGROUND_RED
#define fg_green FOREGROUND_GREEN
#define fg_intensity FOREGROUND_INTENSITY


void set_std_color(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
	SetConsoleTextAttribute(hConsole, color);
}
void set_std_color_light(int color) {
	set_std_color(color | FOREGROUND_INTENSITY);
}

#define printfc(color,m,...); \
	set_std_color_light(color); \
	printf(m, __VA_ARGS__); \
	set_std_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
*/
using namespace std;

enum Error_Code {
    success,
    overflow,
    underflow
};
const int maxQueue = 100;
typedef int Queue_entry;
class Queue {
public:
    Queue() {
        count = 0;
        front = 0;
        rear = maxQueue - 1;
    }
    bool empty() const {
    // Post return true if the Queue is empty, otherwise return false.
        return count == 0;
    }
    Error_Code append(const Queue_entry &item) {
        if(count >= maxQueue) return overflow;
        count++;
        rear = (rear + 1 == maxQueue) ? 0 : (rear + 1);
        entry[rear] = item;
        return success;
    }
    Error_Code serve() {
        if(count <= 0) return underflow;
        count--;
        front = (front + 1 == maxQueue) ? 0 : (front + 1);
        return success;
    }
    Error_Code retrieve(Queue_entry &item) {
        if(count <= 0) return underflow;
        item = entry[front];
        return success;
    }
    int size() const{
        return count;
    }
private:
    int front;
    int rear;
    int count;
    Queue_entry entry[maxQueue];
};

void help();
bool do_command(char c, Queue &test_queue);
char get_command();
void introduction();

int main() {
    Queue test_queue;
    introduction();
    while (do_command(get_command(), test_queue));
    return 0;
}

void help() {
    //printfc(fg_red, "This is the Help Screen!\n", NULL);
    cout << "Program Name:Queue Demonstration" << endl
         << "This program allows user to enter one command" << endl
         << "(but only one) on each input line." << endl
         << "For example, if the command is 'S', then" << endl
         << "the program will serve the front of the Queue." << endl
         << endl
         << "The valid commands are:" << endl
         << "    A -- Append an item to the Queue" << endl
         << "    S -- Serve the front item" << endl
         << "    R -- Retrieve and print the front item" << endl
         << "    # -- Size of the current Queue" << endl
         << "    C -- Clear the Queue" << endl
         << "    P -- Print the Queue" << endl
         << "    H -- This help screen" << endl
         << "    Q -- Quit the program" << endl

         << "Press <Enter> to continue." << endl;
         cout << endl << endl;
    char c;
    do {
        cin.get(c);
    } while (c != '\n');
}

bool do_command(char c, Queue &test_queue) {
    bool continue_input = true;
    Queue_entry x;
    switch(c) {
    case 'R':
        if (test_queue.retrieve(x) == underflow) {
            cout << "Queue is empty." << endl;
        } else {
            cout << endl
                 << "The first entry is " << x << endl;
        }
        break;
    case 'Q':
        cout << "Queue demonstration  finished." << endl;
        continue_input = false;
        break;
    case 'A':
        cout << "Please input the entry to be appended." << endl;
        cin >> x;
        if (test_queue.append(x) == overflow) {
            cout << "Queue is full." << endl;
        } else {
            cout << "Append Success!" << endl;
        }
        break;
    case 'S':
        if (test_queue.serve() == underflow) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Serve success!" << endl;
        }
        break;
    case '#':
        cout << "The size of current Queue is: "
             << test_queue.size() << endl;
        break;
    case 'H':
        help();
        break;
    default:
        break;
    }
    return continue_input;
}

char get_command() {
    char c;
    bool check = false;
    cout << "Please input a character as a command." << endl;
    do {
        cin >> c;
        if (c == 'A' || c == 'S' || c == 'R' || c == '#' ||
            c == 'C' || c == 'P' || c == 'H' || c == 'Q') {
            cout << "Command is legal." << endl;
            check = true;
        } else {
            cout << "Command undefined!" << endl
                 << "Please Input again!" << endl;
            check = false;
        }
    } while (!check);
    return c;
}

void introduction() {
    help();
}
