# HSH Tester
### A little c app to simplify comparing results between your hsh shell and /bin/sh

### Setup
To use hsh_tester, compile with `gcc hsh_tester.c -o hsh_tester`
You can either move the compiled hsh_tester executable to your project directory with your hsh executable or add the directory where you compiled hsh_tester to your $PATH to call `hsh_tester {your test command}`
* NOTE: current version of hsh_tester is hard-coded to use `./hsh` as the name for your compiled shell. To use a different filename for your shell, change the value of `hsh_path` variable on line 19 and recompile.

### Testable commands
- Currently working:
  - `ls`
  - `env`
  - `pwd`
- Needs fixing:
  - `echo`
  - `cat`
  - `which`
- Not supported:
  - `touch`
  - `rm`
  - `cp`
  - `mv`
  - `cd`
