#!/bin/sh

while [[ ! -f /var/www/html/wp_done ]]
do
	echo "Waiting for wordpress to install"
	sleep 3
done

if [ ! -f "/etc/vsftpd/vsftpd.conf.bak" ]; then

    mkdir -p /var/www/html

    cp /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.bak
    mv /tmp/vsftpd.conf /etc/vsftpd/vsftpd.conf

    adduser $(echo -n $VSFPTD_USER | base64 -d) --disabled-password

    echo "$(echo -n $VSFPTD_USER | base64 -d):$(echo -n $VSFPTD_PASSWORD | base64 -d)" | /usr/sbin/chpasswd &> /dev/null

    chown -R $(echo -n $VSFPTD_USER | base64 -d):$(echo -n $VSFPTD_USER | base64 -d)  /var/www/html

    echo $(echo -n $VSFPTD_USER | base64 -d) | tee -a /etc/vsftpd.userlist &> /dev/null

fi

echo "VSFTPD started on :21"

exec /usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf
