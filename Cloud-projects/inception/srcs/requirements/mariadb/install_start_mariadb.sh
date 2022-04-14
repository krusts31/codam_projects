#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

#https://www.man7.org/linux/man-pages/man1/mysql_install_db.1.html

#mysqld is just a process
#		--basedir=The path to the MariaDB installation directory.
#		--datadir=The path to the MariaDB data directory.

mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm 

#this the first 5 lines does the same as mysql_sercure_installation
#the 4 rest creats a mariadb user that has all the accsess to
#wordpress database


cat << EOF > init.sql

USE mysql;
FLUSH PRIVILEGES;

DELETE FROM mysql.user WHERE User='';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db='test';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

ALTER USER 'root'@'localhost' IDENTIFIED BY '$MARIADB_ROOT_PASSWORD';

CREATE DATABASE $WORDPRESS_DATABASE_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$MARIADB_USER'@'%' IDENTIFIED by '$MARIADB_USER_PASSWORD';
GRANT ALL PRIVILEGES ON $WORDPRESS_DATABASE_NAME.* TO '$MARIADB_USER'@'%';
FLUSH PRIVILEGES;

EOF

/usr/bin/mariadbd --user=mysql --bootstrap < init.sql

sed 's/#bind-address=0.0.0.0/bind-address=0.0.0.0/' -i /etc/my.cnf.d/mariadb-server.cnf
sed 's/skip-networking//' -i /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mariadbd --user=mysql --console
