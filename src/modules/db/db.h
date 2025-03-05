#ifndef DB_H
#define DB_H

#define DB_MAX_SIZE 100

extern Task db[DB_MAX_SIZE];
extern int dbSize;

void readTasks(void);
void writeTasks(void);

#endif
