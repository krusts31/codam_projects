FROM debian:buster
RUN apt update
RUN apt upgrade -y 
RUN apt-get -y install sendmail
#install vim
RUN apt install vim -y
#innstall git
WORKDIR /home
RUN apt install git -y
#cloning some srcs
RUN git clone https://github.com/krusts31/ft_server_srcs srcs
#install wget
RUN apt install wget -y
#install nginx
RUN apt install nginx -y
RUN cp /home/srcs/local.conf /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/local.conf /etc/nginx/sites-enabled/
## Install MariaDB
RUN apt install -y mariadb-server
## Install PHP 7.3
RUN apt install php php-json php-cgi php-mysqli php-pear php-mbstring php-gettext php-common php-phpseclib php-mysql -y
RUN apt install php7.3 php7.3-fpm php7.3-common php7.3-mbstring php7.3-gettext php7.3-xmlrpc php7.3-soap php7.3-gd php7.3-xml php7.3-intl php7.3-mysql php7.3-cli php7.3-ldap php7.3-zip php7.3-curl php7.3-cgi -y
#ssl certificate
RUN openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096
RUN openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key
RUN rm ca.pass.key
RUN openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1"
RUN mv ca.key /etc/ssl
RUN mv ca.pem /etc/ssl
#donwloading phpmyadmin
RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz 
#installing phpmyadmin
RUN mkdir /var/www/html/phpmyadmin
RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
#configuring phpmyadmin
RUN cp /home/srcs/config.inc.php /var/www/html/phpmyadmin
#generate blow_fish
RUN bash /home/srcs/gen_blowfish.sh
#creating a a database and giving rights to alkrusts
RUN service mysql start && \
	echo "CREATE DATABASE wordpress;" | mysql -u root && \
	echo "GRANT ALL PRIVILEGES ON *.* TO 'alkrusts'@'localhost' IDENTIFIED BY 'password';" | mysql -u root && \
	echo "FLUSH PRIVILEGES" | mysql -u root
#install wordpress
WORKDIR /var/www/html/wordpress
RUN service mysql start && \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	wp core download --allow-root && \
	wp config create --dbname=wordpress --dbuser=alkrusts --dbpass=password --allow-root && \
	wp core install --allow-root --url="/"  --title="hello world" --admin_user="alkrusts" --admin_password="password" --admin_email="alkrusts@student.codam.nl" && \
	wp plugin install "WP Mail SMTP" --allow-root && \
	wp plugin activate "wp-mail-smtp" --allow-root && \
	mysql -e "USE wordpress;UPDATE wp_options SET option_value='https://localhost/wordpress' WHERE option_name='siteurl' OR option_name='home';"
RUN cp /home/srcs/wp-config.php /var/www/html/wordpress
RUN mkdir menu
RUN cp /home/srcs/index.html /var/www/html/wordpress/menu
#edditing max upload size
RUN sed -i 's/upload_max_filesize = 2M/upload_max_filesize = 19M/g' /etc/php/7.3/fpm/php.ini && \
	sed -i 's/post_max_size = 8M/post_max_size = 19M/g' /etc/php/7.3/fpm/php.ini
#taking away root privilages from the websers
RUN chmod -R 755 /var/www/html* && \
	chown -R www-data:www-data /var/www/html*
EXPOSE 80 443 110 465
CMD /home/srcs/install.sh && bash
