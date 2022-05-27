error=0
echo "Q" | openssl s_client -connect alkrusts.42.fr:443 -tls1_3 &> /dev/null
if [[ $? == 0 ]]
then
	echo -e "\e[32mTLS SERT 1_3 PRESENT\e[0m"
else
	echo -e "\e[31mTLS SERT 1_3 NOT PRESENT\e[0m"
	error=1
fi
echo "Q" | openssl s_client -connect alkrusts.42.fr:443 -tls1_2 &> /dev/null
if [[ $? == 0 ]]
then
	echo -e "\e[32mTLS SERT 1_2 PRESENT\e[0m"
else
	echo -e "\e[31mTLS SERT 1_2 NOT PRESENT\e[0m"
	error=1
fi
echo "Q" | openssl s_client -connect alkrusts.42.fr:443 -tls1_1 &> /dev/null
if [[ $? == 1 ]]
then
	echo -e "\e[32mTLS SERT 1_1 NOT PRESENT\e[0m"
	error=1
else
	echo -e "\e[31mTLS SERT 1_1 PRESENT\e[0m"
fi
echo "Q" | openssl s_client -connect alkrusts.42.fr:443 -tls &> /dev/null
if [[ $? == 1 ]]
then
	echo -e "\e[32mTLS SERT 1 NOT PRESENT\e[0m"
	error=1
else
	echo -e "\e[31mTLS SERT 1 PRESENT\e[0m"
fi

if [[ $error == 0 ]]
then
	echo ""
	echo -e "SERT TEST \e[31m[KO]\e[0m"
else
	echo ""
	echo -e "SERT TEST \e[32m[OK]\e[0m"
fi
echo ""
