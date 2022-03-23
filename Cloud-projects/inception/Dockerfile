FROM debian:buster
RUN apt update -y
RUN apt upgrade -y
#sendmail allows for meai sending from wordpress
#install nginx and some utils
RUN apt-get -y install sendmail \
	vim \
	wget \
	nginx
#PHP stuff
RUN apt install apt-transport-https lsb-release ca-certificates wget -y; \
	wget -O /etc/apt/trusted.gpg.d/php.gpg https://packages.sury.org/php/apt.gpg; \
	sh -c 'echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/php.list'
RUN apt update -y
RUN apt upgrade -y
RUN apt install -y php8.1 php8.1-cgi php8.1-mysqli php8.1-mbstring php8.1-gettext php8.1-common php8.1-mysql php8.1-fpm php8.1-common php8.1-mbstring php8.1-gettext php8.1-xmlrpc php8.1-soap php8.1-gd php8.1-xml php8.1-intl php8.1-cli php8.1-ldap php8.1-zip php8.1-curl php8.1-cgi

#PhpMyAdmin Stuff
WORKDIR /home
RUN ln -s /etc/nginx/sites-available/local.conf /etc/nginx/sites-enabled/
RUN mkdir /var/www/html/phpmyadmin
RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz
RUN tar xvf phpMyAdmin-latest-all-languages.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin

#if the mariadb-server is instaled before php then it will not work

RUN apt-get install -y mariadb-server

RUN service mysql start && \
	echo "CREATE DATABASE wordpress;" | mysql -u root && \
	echo "GRANT ALL PRIVILEGES ON *.* TO 'alkrusts'@'localhost' IDENTIFIED BY 'Uberparole1!';" | mysql -u root && \
	echo "FLUSH PRIVILEGES" | mysql -u root

RUN service mysql start

#wordpress struff
WORKDIR /var/www/html/wordpress

RUN service mysql start && \
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp && \
	wp core download --allow-root && \
	wp config create --dbname=wordpress --dbuser=alkrusts --dbpass=Uberparole1! --allow-root && \
	wp core install --allow-root --url="/"  --title="hello world" --admin_user="alkrusts" --admin_password="Uberparole1!" --admin_email="alkrusts@student.codam.nl" && \
	wp plugin install "WP Mail SMTP" --allow-root && \
	wp plugin activate "wp-mail-smtp" --allow-root && \
	mysql -e "USE wordpress;UPDATE wp_options SET option_value='https://localhost/wordpress' WHERE option_name='siteurl' OR option_name='home';"
RUN mkdir menu
#edditing max upload size
RUN sed -i 's/upload_max_filesize = 2M/upload_max_filesize = 19M/g' /etc/php/8.1/fpm/php.ini && \
	sed -i 's/post_max_size = 8M/post_max_size = 19M/g' /etc/php/8.1/fpm/php.ini

COPY srcs /home/srcs

RUN openssl genrsa -aes256 -passout pass:xxxx -out ca.pass.key 4096
RUN openssl rsa -passin pass:xxxx -in ca.pass.key -out ca.key
RUN rm ca.pass.key
RUN openssl req -new -x509 -days 3650 -key ca.key -out ca.pem -subj "/C=NL/ST=Holland/L=Amsterdam/O=ft_server_srcs inc/OU=IT/CN=127.0.0.1"
RUN mv ca.key /etc/ssl
RUN mv ca.pem /etc/ssl/ca.pam

RUN cp /home/srcs/local.conf /etc/nginx/sites-available
RUN cp /home/srcs/config.inc.php /var/www/html/phpmyadmin
RUN cp /home/srcs/wp-config.php /var/www/html/wordpress
RUN bash /home/srcs/gen_blowfish.sh

CMD /home/srcs/install.sh && bash

#taking away root privilages from the websers

#RUN chmod -R 755 /var/www/html* && \
#	chown -R www-data:www-data /var/www/html*

RUN apt-get install vsftpd -y

EXPOSE 80 443 110 465 20 21