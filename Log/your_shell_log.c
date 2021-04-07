#include <unistd.h>
#include <fcntl.h>

/**
 * log_cmd - appends cmd to logfile
 * @logfile: path for logfile to use
 * @cmd: command text
 * @cmd_len: length of command text
 *
 * Return: 1 for success, else -1
*/
int your_log_cmd(const char *logfile, char *cmd, size_t cmd_len)
{
	int fd;
	ssize_t writelen;

	if (logfile == NULL)
		return (-1);
	fd = open(logfile, O_RDWR | O_CREAT | O_APPEND, 0600);
	if (fd < 0)
		return (-1);
	if (cmd)
	{
		writelen = write(fd, cmd, cmd_len);
		if (writelen == -1)
			return (-1);
	}
	close(fd);

	return (1);
}
