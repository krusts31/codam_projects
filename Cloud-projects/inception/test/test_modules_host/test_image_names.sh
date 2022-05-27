#gets the last arg from docker ps wich are all the running container names
runing_services=$(docker ps --format '{{.Names}}')
#removes the first line since it is not needed
echo -e "\e[36mEXPECTED IMAGE NAMES:\e[0m $runing_services"
#loop over all the $runing_services word by word
error=0
for service_name in $runing_services
do
	#looks for service_name in docker images
	docker image ls | grep -w "$service_name" > /dev/null
	ret=$?
	if [[ $ret == 0 ]]
	then
		echo -e "\e[32mSERVICE\e[0m \e[35m$service_name\e[0m \e[32mHAS THE A IMAGE WITH THE SAME NAME\e[0m"
	else
		echo -e "\e[31mSERVICE\e[0m \e[35m$service_name\e[0m \e[31mDOES NOT HAVE A IMAGE WITH THE SAME NAME\e[0m"
		error=1
	fi
done
if [[ $error == 0 ]]
then
	echo ""
	echo -e "IMAGE NAME TEST: \e[32m[OK]\e[0m"
else
	echo ""
	echo -e "IMAGE NAME TEST: \e[31m[KO]\e[0m"
fi
echo ""
