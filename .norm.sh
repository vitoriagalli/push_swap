function pass()
{
	echo ""
	echo "        _..._"
	echo "      .'     '.      _"
	echo "     /    .-\"\"-\   _/ \\"
	echo "   .-|   /:.   |  |   |"
	echo "   |  \  |:.   /.-'-./"
	echo "   | .-'-;:__.'    =/"
	echo "   .'=  *=|42SP _.='"
	echo "  /   _.  |    ;"
	echo -e " ;-.-'|    \   |           \033[1mNORM OK\033[0m"
	echo "/   | \    _\  _\\    you are good to go"
	echo "\__/'._;.  ==' ==\\"
	echo "         \    \   |"
	echo "         /    /   /"
	echo "         /-._/-._/"
	echo "         \   \`\  \\"
	echo "          \`-._/._/"
	echo ""
}

function fail()
{
	echo ""
	echo "▄██████████████▄▐█▄▄▄▄█▌"
	echo "██████▌▄▌▄▐▐▌███▌▀▀██▀▀"
	echo "████▄█▌▄▌▄▐▐▌▀███▄▄█▌"
	echo "▄▄▄▄▄██████████████▀"
	echo ""
}

if [ "$1" == "0" ]
then
	pass
else
	fail
fi
