wp_username=alkrusts_wordpress_user
wp_password=alkrusts_password

wp_admin=alkrusts_wordpress_rick
wp_admin_password=alkrusts_wordpress_rick_password

mariadb_user=alkrusts_mariadb
mariadb_user_password=alkrusts_mariadb_password
mariadb_root=rootPasswordThisIs

/usr/bin/mariadb -hmariadb -uroot --password=$mariadb_root &> /dev/null

ret=$?
error=0
if [ $ret == 1 ]
then
	echo 
	echo -e "\e[32m CAN NOT CONECT AS ROOT REMOTE\e[0m"
else
	echo 
	echo -e "\e[31m CAN CONECT AS ROOT REMOTE\e[0m"
	error=1
fi
echo 


/usr/bin/mariadb -hmariadb -u$mariadb_user --password=$mariadb_user_password &> /dev/null

ret=$?

if [ $ret == 1 ]
then
	echo 
	echo -e "\e[31m CAN NOT CONECT AS USER REMOTE\e[0m"
	error=1
else
	echo 
	echo -e "\e[32m CAN CONECT AS USER REMOTE\e[0m"
fi
echo 

if [ $error == 1 ]
then
	echo
	echo -e "LOG IN MARIADB TEST \e[31m[KO]\e[0m"
else
	echo 
	echo -e "LOG IN MARIADB TEST \e[32m[OK]\e[0m"
fi
echo 

echo "USE wordpress; SELECT * FROM wp_users;" | mariadb -hmariadb -ualkrusts_mariadb -palkrusts_mariadb_password | grep -w $wp_username &> /dev/null
ret=$?
if [ $ret == 1 ]
then
	echo 
	echo -e "\e[31mwordpress user not found!\e[0m"
	error=1
else
	echo 
	echo -e "\e[32mwordpress user found!\e[0m"
fi

echo "USE wordpress; SELECT * FROM wp_users;" | mariadb -hmariadb -ualkrusts_mariadb -palkrusts_mariadb_password | grep -w $wp_admin  &> /dev/null
ret=$?
if [ $ret == 1 ]
then
	echo 
	echo -e "\e[31m admin user not found!\e[0m"
	error=1
else
	echo 
	echo -e "\e[32mwordpress admin found!\e[0m"
fi

if [ $error == 1 ]
then
	echo
	echo -e "WP DATA TEST \e[31m[KO]\e[0m"
else
	echo 
	echo -e "WP DATA TEST \e[32m[OK]\e[0m"
fi
echo 
