echo 'rc_provide="loopback net"' >> /etc/rc.conf
rc-service mariadb restart
rc-service php-fpm82 restart
rc-service nginx restart
/bin/sh
