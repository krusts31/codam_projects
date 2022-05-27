domain_name=$USER.42.fr
wp_username=alkrusts_wordpress_user
wp_password=alkrusts_password
wp_admin=alkrusts_wordpress_rick
wp_admin_password=alkrusts_wordpress_rick_password

if [ -z "$domain_name" ]
then
	echo "enter your domain name: user.42.fr"
	read domain_name
fi

if [ -z "$wp_username" ]
then
	echo "enter your wordpress username"
	read wp_username
fi

if [ -z "$wp_password" ]
then
	echo "enter your wordpress password"
	read wp_password
fi

if [ -z "$wp_admin" ]
then
	echo "enter your wordpress admin username"
	read wp_admin
fi

if [ -z "$wp_admin_password" ]
then
	echo "enter your wordpress admin password"
	read wp_admin_password
fi

LOGIN_URL="https://$domain_name/wp-login.php?redirect_to=https%3A%2F%2F$domain_name%2Fwp-admin%2F&reauth=1"

error=0
curl -k -b cookies -c cookies "https://$domain_name/wp-login.php" > /dev/null
curl -k -L -b cookies -c cookies -d "log=$wp_username&pwd=$wp_password&wp-submit=%E7%99%BB%E5%BD%95&redirect_to=https%3A%2F%2F$domain_name%2Fwp-admin%2F&testcookie=1" "https://$domain_name/wp-login.php" | grep "login_error"
if [[ $? == 1 ]]
then
	echo ""
	echo -e "\e[32mPOSSIBLE TO LOG IN AS $wp_username $wp_password\e[0m"
else
	echo ""
	echo -e "\e[31mNOT POSSIBLE TO LOG IN AS $wp_username $wp_password\e[0m"
	error=1
fi
echo ""
rm -rf cookies
curl -k -b cookies -c cookies "https://$domain_name/wp-login.php" > /dev/null
curl -k -L -b cookies -c cookies -d "log=$wp_admin&pwd=$wp_admin_password&wp-submit=%E7%99%BB%E5%BD%95&redirect_to=https%3A%2F%2F$domain_name%2Fwp-admin%2F&testcookie=1" "https://$domain_name/wp-login.php" | grep "login_error"
if [[ $? == 1 ]]
then
	echo ""
	echo -e "\e[32mPOSSIBLE TO LOG IN AS $wp_admin $wp_admin_password\e[0m"
else
	echo ""
	echo -e "\e[31mNOT POSSIBLE TO LOG IN AS $wp_admin $wp_admin_password\e[0m"
	error=1
fi
rm -rf cookies
echo ""

if [[ $error == 0 ]]
then
	echo ""
	echo -e "LOGGIN IN TO WORDPRESS \e[32m[OK]\e[0m"
else
	echo ""
	echo -e "LOGGIN IN TO WORDPRESS \e[31m[KO]\e[0m"
fi
echo ""



docker cp  test/test_modules_host/internal_tests/wordpress_post_test.sh wordpress:/var/www/html/wordpress_post_test.sh
echo
echo "Making 100 wp posts"

docker exec wordpress /bin/sh wordpress_post_test.sh

curl -k https://$domain_name/?p=24 | grep "404"
ret=$?
error=0
if [ $ret == 1 ]
then
	echo
	echo -e "\e[32mSuccseeded to make a post\e[0m"
else
	echo
	echo -e "\e[31mSFailed to make a post\e[0m"
	error=1
fi
echo

if [ $error == 1 ]
then
	echo
	echo -e "POST creation \e[31m[KO]\e[0m"
else
	echo
	echo -e "POST creation \e[32m[OK]\e[0m"
fi
echo
