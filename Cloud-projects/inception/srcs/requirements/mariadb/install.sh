#!/bin/sh

if [ ! -d /run/mysqld ]
then
	echo "setting up maraidb"
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
	chown -R mysql:mysql /var/lib/mysql

	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm

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
fi

echo "mariadb started"

exec /usr/bin/mariadbd --user=mysql --console
