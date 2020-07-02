currentNum=0
while true; do
while read -r INPUT </dev/ttyUSB0 ; do
#	echo "currentNum = " 
#	echo $currentNum
INPUT="${INPUT//[$'\t\r\n ']}"
if [ ! -z "$INPUT" ]; then
	if [ "$currentNum" -ne "$INPUT" ] ; then
		#clear
#		echo "$INPUT"
		amixer -q sset Master $INPUT"%"
		#sleep 0.1
		currentNum=$INPUT
		
	fi
fi
done
done
