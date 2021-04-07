# Creating Logs for input to shell

## To add a log for the original shell to verify output:
- Pull test_shell_log.c
- Compile with gcc test_shell_log.c

## To add a test file for your shell:
#### Add to your main:

- size_t cmdBufferLen;
- char *cmdBuffer = NULL;
- cmdBufferLen = getline(&cmdBuffer, &cmdBufferLen, stdin);
- log_cmd("your_log.txt", cmdBuffer, cmdBufferLen);

#### Then:
- Pull your_shell_log.c
- Compile with gcc *.c (as long as test_shell_log.c isn't in the directory)

Created by Adam Brimer.
README written by Rachel Lewis. Slack me if you have questions
