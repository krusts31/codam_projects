#!/bin/sh

if [ ! -f "/etc/vsftpd/vsftpd.conf.bak" ]; then

    mkdir -p /var/www/html

    cp /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.bak
    mv /tmp/vsftpd.conf /etc/vsftpd/vsftpd.conf

    adduser $VSFPTD_USER --disabled-password

    echo "$VSFPTD_USER:$VSFPTD_PASSWORD" | /usr/sbin/chpasswd &> /dev/null

    chown -R $VSFPTD_USER:$VSFPTD_USER /var/www/html

    echo $VSFPTD_USER | tee -a /etc/vsftpd.userlist &> /dev/null

fi

echo "VSFTPD started on :21"

exec /usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
