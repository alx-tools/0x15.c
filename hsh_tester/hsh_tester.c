#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int _puts(char *str);

int main(int argc, char **argv)
{
	int i;
	unsigned int hsh_outlen = 0, sh_outlen = 0, outlen = 0;
	char *cmd, *sh_cmd, *hsh_cmd, *hsh_path, *sh_out, *hsh_out;
	FILE *sh_fp, *hsh_fp;
	char buf[1024], res[1024];
	/* reads HSH_PATH from env or uses ./hsh as default */
	/* hsh_path = getenv("HSH_PATH") == NULL ? "./hsh" : getenv("HSH_PATH");*/
	hsh_path = "./hsh";
	/* malloc for concatenated command from argv */
	cmd = malloc(sizeof(char) * 2 * argc);
	/* malloc command + 19 chars for "echo "{command}" | /bin/sh" */
    	if (argc < 2)
        	_puts("Use: test with a shell command!\n"), exit(-1);
	/* concat argv's to cmd string */
    	for(i = 1; i < argc; i++) {
        	strcat(cmd, argv[i]);
        	strcat(cmd, " ");
	}
	_puts(cmd);
	_puts("\n");
	/* malloc command + 19 chars for "echo "{command}" | /bin/sh" */
        sh_cmd = malloc(sizeof(char) * (strlen(cmd) + 19));
	/* malloc command + hsh_path + 11 chars for "echo "{command}" | {hsh_path}" */
        hsh_cmd = malloc(sizeof(char) * (strlen(cmd)));
	/* format commands to sh_cmd and hsh_cmd */
	sprintf(sh_cmd, "echo \"%s\" | /bin/sh", cmd);
	sprintf(hsh_cmd, "echo \"%s\" | %s", cmd, hsh_path);
	/* Get file pointer to output from commands */
	sh_fp = popen(sh_cmd, "r");
	hsh_fp = popen(hsh_cmd, "r");
	if (sh_fp == NULL)
		_puts("ERROR: Failed to open command with sh\n");
	if (hsh_fp == NULL)
		_puts("ERROR: Failed to open command with hsh\n");
	/* Read the output a line at a time - output it. */
	_puts("sh output:\n");
	while (fgets(buf, sizeof(buf), sh_fp) != NULL) {
		sh_outlen += write(STDOUT_FILENO, buf, strlen(buf));
	}
	_puts("\nhsh output:\n");
	while (fgets(buf, sizeof(buf), hsh_fp) != NULL) {
		hsh_outlen += write(STDOUT_FILENO, buf, strlen(buf));
	}
	_puts("\n");
	sprintf(res, "Total lengths: sh-%d	hsh-%d\n", sh_outlen, hsh_outlen);
	_puts(res);
	pclose(sh_fp);
	pclose(hsh_fp);
	return (0);
}

int _puts(char *str)
{
	return write(STDOUT_FILENO, str, strlen(str));
}
