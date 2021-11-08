# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init_container.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 13:33:46 by iderighe          #+#    #+#              #
#    Updated: 2021/05/20 12:47:33 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# switch Autoindex
if [ $AUTOINDEX = "off" ]
then
	sed -i 's/autoindex on/autoindex off/g' /etc/nginx/sites-available/localhost
fi

# SSL
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=FR/ST=75/L=Paris/O=42/OU=iderighe/CN=localhost' -keyout /etc/ssl/certs/localhost.key -out /etc/ssl/certs/localhost.crt

# Config MYSQL-MariaDB
service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "CREATE USER 'Isabelle'@'localhost' IDENTIFIED BY 'password';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'Isabelle'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

# start services
service php7.3-fpm start
service nginx start

bash
