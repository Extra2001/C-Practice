//
//  main.c
//  杜王町的奇妙抗疫
//
//  Created by Li Riqian on 2020/2/15.
//  Copyright © 2020 Li Riqian. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int x, front = 0, rear = 0;
char q[1007][37], s[37];

int isFull() {
    
    return front == (rear + 1) % x;
}

int isEmpty() {
    
    return front == rear;
}

void outQueue() {
    
    front = (front + 1) % x;
}

void inQueue() {
    
    if (isFull())
        outQueue();
    strcpy(q[rear], s);
    rear = (rear + 1) % x;
}

int main(int argc, const char * argv[]) {
    
    scanf("%d", &x);
    x++;
    while (~scanf("%s", s))
        inQueue();
    printf("%s\n", q[front]);
    
    return 0;
}
