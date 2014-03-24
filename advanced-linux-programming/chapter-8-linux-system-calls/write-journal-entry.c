#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char* journal_filename = "journal.log";

void write_journal_entry(char* entry)
{
    int fd = open(journal_filename, O_WRONLY | O_CREAT | O_APPEND, 0660);
    write(fd, entry, strlen(entry));
    fsync(fd);

    close(fd);
}
        
int main(int argc, char* argv[])
{
    write_journal_entry("Hello fsync!\n");

    return 0;
}
