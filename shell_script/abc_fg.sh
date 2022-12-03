while true
do
	echo -n "abc_fg > "
	read Input
	case $Input in
		"") exec bg
			;;
		"hello") echo "Hello, ForeGround!" 
			;;
		"exit") return
			;;
		"") break
			;;
	esac
done
