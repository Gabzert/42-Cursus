#!/bin/sh

if [ ! -f "/etc/vsftpd.conf.bak" ]; then

    mkdir -p /var/www/html

    cp /etc/vsftpd.conf /etc/vsftpd.conf.bak


    # mv /etc/vsftpd.conf /etc/vsftpd/vsftpd.conf
    # cp /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.bak

    # Add the FTP_USER, change his password and declare him as the owner of wordpress folder and all subfolders
    adduser $FTP_USER --disabled-password
    echo "$FTP_USER:$FTP_PASSWORD" | /usr/sbin/chpasswd &> /dev/null
    chown -R $FTP_USER:$FTP_USER /var/www/html

	#chmod +x /etc/vsftpd/vsftpd.conf
    echo $FTP_USER | tee -a /etc/vsftpd.userlist &> /dev/null

fi

/usr/sbin/vsftpd /etc/vsftpd.conf