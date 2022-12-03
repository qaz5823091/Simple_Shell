makeBackgroundProcess() {
	sh ./abc_bg.sh &
	ps -ef | grep "sh ./abc_bg.sh" | grep -v grep | awk -F ' ' '{print $2}' > pid.txt
}

killBackgroundProcess() {
	if [ -f "pid.txt" ];
	then
		kill -9 `cat pid.txt`
		rm pid.txt
	fi
	exit
}

while true
do
	echo -n "my_shell > "
	read Input
	case "$Input" in
		"abc_fg") exec ./abc_fg.sh ;;
		"abc_bg") makeBackgroundProcess ;;
		"hello") echo "Hello, MyShell!" ;;
		"exit") killBackgroundProcess
	esac
done
