.... export PS1=%
....

%echo "Shell Variables 101"
Shell Variables 101
%busybox ash


BusyBox v1.27.2 (Ubuntu 1:1.27.2-2ubuntu3.4) built-in shell (ash)
Enter 'help' for a list of built-in commands.

%echo "Watchout! Do not test on your $SHLVL-1 = 1"
Watchout! Do not test on your 3-1 = 1
Watchout! Do not test on your (3-1) = 2, we are in busybox bash-like
%echo "Watchout! Do not test on your ($SHLVL-1) = 2, we are in busybox bash-like
"
Watchout! Do not test on your (3-1) = 2, we are in busybox bash-like
%echo $foo

%foo=bar
%echo $foo
bar
%env | grep foo
%export foo=bar
%env | grep foo
foo=bar
_=foo=bar
%foo=hidden
%echo $foo
hidden
%env | grep foo
foo=hidden
%unset foo
%env | grep foo
_=foo
%foo=hidden
%env | grep foo
_=foo
%echo $foo
hidden
%unset foo
%echo $foo

%env | grep foo
%strace foo=bar
strace: Can't stat 'foo=bar': No such file or directory
%strace -e foo=bar
strace: invalid system call 'foo=bar'
%strace -e foo=bar
strace: invalid system call 'foo=bar'
%echo $?
1


