# minishell

minishell is a mini bash or zsh. It can handle complex pipelines. It uses an AST. It can handle
redirections, pipes, env, and signals like ctrl+ c, cltr + d, ctrl + \. It has some builtins. It has a 
command history. 

##### To use minishell

```sh
apt-get install libreadline-dev
git clone
make
./minishell
```

##### Example
```sh
ls -la
ls -la | cat -n
cat << EOF
echo "hi" > test.text
echo "hihi" >> test.text
echo $USER
env
export X=123
cd /
```

##### my jurney:
1. Learned about the `fork`, `execv`, `waitpid`, signal.
2. Learned how a shell works.
3. Learned how to make a fork bomb. ;)
4. Learned to feel comfortable in a linux shell. :D
5. Learned how to make a complex piple line to do my biding.
6. Learned how to work with a team m8.
7. Learned how to work with git in a team.
